/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : usb_hid.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVMD10
**     Component   : USB_HID_CLASS
**     Version     : Component 01.027, Driver 01.00, CPU db: 3.00.003
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 13:36, # CodeGen: 85
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         USB_Class_HID_Init              - uint_8 usb_hid_USB_Class_HID_Init(uint_8 controller_ID, USB_CLASS_CALLBACK...
**         USB_Class_HID_DeInit            - uint_8 usb_hid_USB_Class_HID_DeInit(uint_8 controller_ID);
**         USB_Class_HID_Send_Data         - uint_8 usb_hid_USB_Class_HID_Send_Data(uint_8 controller_ID, uint_8 ep_num,...
**         usb_class_host_hid_init         - void usb_hid_usb_class_host_hid_init(PIPE_BUNDLE_STRUCT_PTR *pbs_ptr,...
**         usb_class_host_hid_get_report   - USB_STATUS usb_hid_usb_class_host_hid_get_report(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_set_report   - USB_STATUS usb_hid_usb_class_host_hid_set_report(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_get_idle     - USB_STATUS usb_hid_usb_class_host_hid_get_idle(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_set_idle     - USB_STATUS usb_hid_usb_class_host_hid_set_idle(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_get_protocol - USB_STATUS usb_hid_usb_class_host_hid_get_protocol(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_set_protocol - USB_STATUS usb_hid_usb_class_host_hid_set_protocol(HID_COMMAND_PTR *com_ptr,...
**
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#include "usb_hid.h"
#include "usb_devapi.h" /* USB device Header File */
/****************************************************************************
 * Global Variables
 ****************************************************************************/
uint_8 g_class_request_params[2]; /* for get/set idle and protocol requests*/

/****************************************************************************
 * Local Variables
 ****************************************************************************/
/* HID endpoint info array */
static USB_CLASS_HID_ENDPOINT_DATA g_hid_endpoint_data;
/* HID Class Callback Function Pointer */
static USB_CLASS_CALLBACK g_hid_class_callback=NULL;
/* HID Class Vendor Callback Function Pointer */
static USB_REQ_FUNC       g_vendor_req_callback=NULL;
/* HID Class requests Callback Function Pointer */
static USB_CLASS_SPECIFIC_HANDLER_FUNC g_param_callback = NULL;

/* Internal method prototypes */
static uint_8 USB_Map_Ep_To_Struct_Index(uint_8 controller_ID, uint_8 ep_num);
static void USB_Service_Hid(PTR_USB_DEV_EVENT_STRUCT event);
static void USB_Class_Hid_Event(uint_8 controller_ID, uint_8 event, void* val);
static uint_8 USB_Other_Requests(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);

/*
** ===================================================================
**     Method      :  USB_Map_Ep_To_Struct_Index (component USB_HID_CLASS)
**
**     Description :
**         The funtion maps the endpoint number to the index of the 
**         endpoint data struct
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Map_Ep_To_Struct_Index(
    uint_8 controller_ID,              /* [IN] Controller ID */
    uint_8 ep_num                      /* Endpoint Number */
)
{
    uint_8 index = 0;

    USB_ENDPOINTS *ep_desc_data = (USB_ENDPOINTS *)USB_Desc_Get_Endpoints(controller_ID);

    /* map the endpoint num to the index of the endpoint structure */
    for(index = 0; index < ep_desc_data->count; index++)
    {
        if(ep_desc_data->ep[index].ep_num == ep_num)
        {
            break;
        }
    }
    return index;
}

/*
** ===================================================================
**     Method      :  USB_Service_Hid (component USB_HID_CLASS)
**
**     Description :
**         The funtion is a callback function of HID endpoint
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Service_Hid(
    PTR_USB_DEV_EVENT_STRUCT event     /* [IN] Pointer to USB Event Structure */
)
{
    uint_8 index;
    uint_8 producer, consumer;

     /* map the endpoint num to the index of the endpoint structure */
    index = USB_Map_Ep_To_Struct_Index(event->controller_ID, event->ep_num);

    producer = g_hid_endpoint_data.ep[index].bin_producer;

    /* if there are no errors de-queue the queue and decrement the no. of
       transfers left, else send the same data again */
    if(event->errors == 0)
    {
        /* de-queue if the send is complete without an error */
        g_hid_endpoint_data.ep[index].bin_consumer++;
    }
    else
    {
        /* notify the application of the error */
        g_hid_class_callback(event->controller_ID, USB_APP_ERROR,
            (uint_8*)(&(event->errors)));
    }
    consumer = g_hid_endpoint_data.ep[index].bin_consumer;

    if(consumer != producer)
    {
        /*if bin is not empty */
        USB_CLASS_HID_QUEUE queue;
        /* send the next packet in queue */
        queue = g_hid_endpoint_data.ep[index].
            queue[consumer % MAX_QUEUE_ELEMS];

        (void)USB_Class_Send_Data(queue.controller_ID, queue.channel,
            queue.app_buff, queue.size);
    }

    /* notify the app of the send complete */
    g_hid_class_callback(event->controller_ID, USB_APP_SEND_COMPLETE, 0);
}

/*
** ===================================================================
**     Method      :  USB_Class_Hid_Event (component USB_HID_CLASS)
**
**     Description :
**         The funtion initializes HID endpoint
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Class_Hid_Event(
    uint_8 controller_ID,              /* [IN] Controller ID */
    uint_8 event,                      /* [IN] Event Type */
    void* val                          /* [IN] Pointer to configuration Value */
)
{
    uint_8 index;

    if(event == USB_APP_ENUM_COMPLETE)
    {
        uint_8 count;
        /* get the endpoints from the descriptor module */
        USB_ENDPOINTS *ep_desc_data = (USB_ENDPOINTS *)USB_Desc_Get_Endpoints(controller_ID);

        count = ep_desc_data->count;
        /* deinitialize all endpoints in case they were initialized */
        while(count > 0)
        {
            USB_EP_STRUCT_PTR ep_struct_ptr= (USB_EP_STRUCT_PTR) (&ep_desc_data->ep[count - 1]);
            (void)_usb_device_deinit_endpoint(&controller_ID,
                ep_struct_ptr->ep_num, ep_struct_ptr->direction);
            count--;
        }

        /* intialize all non control endpoints */
        while(count < ep_desc_data->count)
        {
            USB_EP_STRUCT_PTR ep_struct=
                (USB_EP_STRUCT_PTR)&ep_desc_data->ep[count];

            (void)_usb_device_init_endpoint(&controller_ID, ep_struct->ep_num,
                ep_struct->size, ep_struct->direction, ep_struct->type,TRUE);

            /* register callback service for the endpoint */
            (void)_usb_device_register_service(controller_ID,
                (uint_8)(USB_SERVICE_EP0+ep_struct->ep_num),USB_Service_Hid);

            /* set the EndPoint Status as Idle in the device layer */
            (void)_usb_device_set_status(&controller_ID,
                (uint_8)(USB_STATUS_ENDPOINT | HID_ENDPOINT |
                (ep_struct->direction << USB_COMPONENT_DIRECTION_SHIFT)),
                USB_STATUS_IDLE);

            count++;
        }
    }
    else if((event == USB_APP_BUS_RESET) || (event == USB_APP_CONFIG_CHANGED))
    {
        /* clear producer and consumer on reset */
        for(index = 0; index < g_hid_endpoint_data.count; index++)
        {
            g_hid_endpoint_data.ep[index].bin_consumer = 0x00;
            g_hid_endpoint_data.ep[index].bin_producer = 0x00;
        }
    }

    if(g_hid_class_callback != NULL)
    {
        /* notify the application of the event */
        g_hid_class_callback(controller_ID, event, val);
    }
}

/*
** ===================================================================
**     Method      :  USB_Other_Requests (component USB_HID_CLASS)
**
**     Description :
**         The funtion provides flexibilty to add class and vendor 
**         specific requests
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Other_Requests(
    uint_8 controller_ID,              /* [IN] Controller ID */
    USB_SETUP_STRUCT *setup_packet,    /*[IN] Setup packet received */
    uint_8_ptr *data,                  /* [OUT] Data to be send back */
    USB_PACKET_SIZE *size              /* [OUT] Size to be returned*/
)
{
    uint_8 index;
    uint_8 status = USBERR_INVALID_REQ_TYPE;
    uint_8 rpt_buf[REPORT_SIZE];/* buffer to send in case of get report req */
    *((uint_32_ptr)rpt_buf) = 0;

    if((setup_packet->request_type & USB_REQUEST_CLASS_MASK) ==
        USB_REQUEST_CLASS_CLASS)
    {
        /* class request so handle it here */
        /* index == 0 for get/set idle, index == 1 for get/set protocol */
        index = (uint_8)((setup_packet->request - 2) &
            USB_HID_REQUEST_TYPE_MASK);

        status = USB_OK;
        /* point to the data which comes after the setup packet */
        *data = ((uint_8*)setup_packet) + USB_SETUP_PKT_SIZE;
        *size = 0;
        /* handle the class request */
        switch(setup_packet->request)
        {
            case USB_HID_GET_REPORT_REQUEST :
                /*set the data pointer to the buffer to send */
                *data = &rpt_buf[0];
                if(*size > REPORT_SIZE) *size = REPORT_SIZE;
                break;

            case USB_HID_SET_REPORT_REQUEST :
                for(index = 0; index < REPORT_SIZE; index++)
                {   /* copy the data sent by host in the buffer */
                  rpt_buf[index] = *(*data + index);
                }
                break;

            case USB_HID_GET_IDLE_REQUEST :
                /* point to the current idle rate */
                *data = &g_class_request_params[index];
                *size = CLASS_REQ_DATA_SIZE;
                break;

            case USB_HID_SET_IDLE_REQUEST :
                /* set the idle rate sent by the host */
                g_class_request_params[index] =(uint_8)((setup_packet->value
                    & MSB_MASK) >> HIGH_BYTE_SHIFT);
                break;

            case USB_HID_GET_PROTOCOL_REQUEST :
                /* point to the current protocol code
                            0 = Boot Protocol
                            1 = Report Protocol*/
                *data = &g_class_request_params[index];
                *size = CLASS_REQ_DATA_SIZE;
                break;

            case USB_HID_SET_PROTOCOL_REQUEST :
                /* set the protocol sent by the host
                             0 = Boot Protocol
                             1 = Report Protocol*/
                g_class_request_params[index] = (uint_8)(setup_packet->value);
                break;
            default :
                break;
        }

        if(g_param_callback != NULL)
        {
            /*
               handle callback if the application has supplied it
               set the size of the transfer from the setup packet
            */
            *size = (USB_PACKET_SIZE)setup_packet->length;

            /* notify the application of the class request.
               give control to the application */
            status = g_param_callback(setup_packet->request,/* request type */
                setup_packet->value,
                data,/* pointer to the data */
                size);/* size of the transfer */
        }
    }
    else if((setup_packet->request_type & USB_REQUEST_CLASS_MASK) ==
        USB_REQUEST_CLASS_VENDOR)
    {
        /* vendor specific request  */
        if(g_vendor_req_callback != NULL)
        {
            status = g_vendor_req_callback(controller_ID, setup_packet,data,
                size);
        }
    }
    return status;
}

/*
** ===================================================================
**     Method      :  usb_hid_USB_Class_HID_Init (component USB_HID_CLASS)
**
**     Description :
**         The funtion initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To Identify the
**                           controller
**         hid_class_callback - HID Class
**                           Callback
**         vendor_req_callback - vendor
**                           specific class request callback 
**         param_callback  - HID Class requests
**                           Callback
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Class_HID_Init(
   uint_8 controller_ID,                           /* [IN] Controller ID */
   USB_CLASS_CALLBACK hid_class_callback,          /* [IN] HID Class Callback */
   USB_REQ_FUNC vendor_req_callback,               /* [IN] Vendor Request Callback */
   USB_CLASS_SPECIFIC_HANDLER_FUNC param_callback  /* [ IN] HID Class requests Callback */
)
{
    uint_8 index;
    USB_ENDPOINTS *ep_desc_data = (USB_ENDPOINTS *)
        USB_Desc_Get_Endpoints(controller_ID);

    /* Initialize the device layer*/
    uint_8 status = _usb_device_init(controller_ID, NULL,
        (uint_8)(ep_desc_data->count+1));
    if(status == USB_OK)
    {
        /* Initialize the generic class functions */
        status = USB_Class_Init(controller_ID,USB_Class_Hid_Event,
            USB_Other_Requests);

        if(status == USB_OK)
        {
            g_hid_endpoint_data.count = ep_desc_data->count;

            for(index = 0; index < ep_desc_data->count; index++)
            {
                g_hid_endpoint_data.ep[index].endpoint =
                    ep_desc_data->ep[index].ep_num;
                g_hid_endpoint_data.ep[index].type =
                    ep_desc_data->ep[index].type;
                g_hid_endpoint_data.ep[index].bin_consumer = 0x00;
                g_hid_endpoint_data.ep[index].bin_producer = 0x00;
            }

            /* save the HID class callback pointer */
            g_hid_class_callback = hid_class_callback;

            /* save the vendor request callback pointer */
            g_vendor_req_callback = vendor_req_callback;

            /* Save the callback to ask application for class specific params*/
            g_param_callback = param_callback;
        }
    }
    return status;
}
/*
** ===================================================================
**     Method      :  usb_hid_USB_Class_HID_DeInit (component USB_HID_CLASS)
**
**     Description :
**         The funtion de-initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - Controller ID 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Class_HID_DeInit(
    uint_8 controller_ID               /* [IN] Controller ID */
)
{
    uint_8 status;

    /* free the HID class callback pointer */
    g_hid_class_callback = NULL;

    /* free the vendor request callback pointer */
    g_vendor_req_callback = NULL;

    /* free the callback to ask application for class specific params*/
    g_param_callback = NULL;

    /* Call common class deinit function */
    status = USB_Class_DeInit(controller_ID);

    if(status == USB_OK)
    /* Call device deinit function */
    status = _usb_device_deinit();

    return status;
}

/*
** ===================================================================
**     Method      :  usb_hid_USB_Class_HID_Send_Data (component USB_HID_CLASS)
**
**     Description :
**         This fucntion is used by Application to send data through
**         HID class
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         ep_num          - endpoint num 
**         app_buff        - buffer to send
**         size            - length of the transfer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Class_HID_Send_Data(
    uint_8 controller_ID,              /* [IN] Controller ID */
    uint_8 ep_num,                     /* [IN] Endpoint Number */
    uint_8_ptr app_buff,               /* [IN] Buffer to Send */
    USB_PACKET_SIZE size               /* [IN] Length of the Transfer */
)
{
    uint_8 index;
    volatile uint_8 producer, consumer;
    uint_8 status = USB_OK;

     /* map the endpoint num to the index of the endpoint structure */
    index = USB_Map_Ep_To_Struct_Index(controller_ID, ep_num);

    producer = g_hid_endpoint_data.ep[index].bin_producer;
    consumer = g_hid_endpoint_data.ep[index].bin_consumer;

    if((uint_8)(producer - consumer) != (uint_8)(MAX_QUEUE_ELEMS))
    {
        /* the bin is not full*/
        uint_8 queue_num = (uint_8)(producer % MAX_QUEUE_ELEMS);

        /* queue the send request */
        /* put all send request parameters in the endpoint data structure */
        g_hid_endpoint_data.ep[index].queue[queue_num].controller_ID =
            controller_ID;
        g_hid_endpoint_data.ep[index].queue[queue_num].channel = ep_num;
        g_hid_endpoint_data.ep[index].queue[queue_num].app_buff = app_buff;
        g_hid_endpoint_data.ep[index].queue[queue_num].size = size;

        /* increment producer bin by 1*/
        g_hid_endpoint_data.ep[index].bin_producer++;
        producer++;

        if((uint_8)(producer - consumer) == (uint_8)1)
        {
            /* send the IO if there is only one element in the queue */
            status = USB_Class_Send_Data(controller_ID, ep_num, app_buff,size);
        }
    }
    else /* bin is full */
    {
        status = USBERR_DEVICE_BUSY;
    }
    return status;
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
