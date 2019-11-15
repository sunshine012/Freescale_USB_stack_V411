
/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_framework.c
**     Project   : ProcessorExpert
**     Processor : MK40N512MD100
**     Component : USB_DEVICE_STACK
**     Version   : Driver 01.00, CPU db: 3.00.003
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 11:32, # CodeGen: 25
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#include "types.h"          /* Contains User Defined Data Types */
#include "usb_class.h"      /* USB class Header File */
#include "usb_framework.h"  /* USB Framework Header File */
#include "usb_descriptor.h" /* USB descriptor Header File */
#include <string.h>

/*****************************************************************************
 * Constant and Macro's
 *****************************************************************************/
/****************************************************************************
 * Global Variables
 ****************************************************************************/
static USB_SETUP_STRUCT g_setup_pkt;
/*is used to store the value of data which needs to be sent to the USB
host in response to the standard requests.*/
static uint_16 g_std_framework_data;
/*used to store the address received in Set Address in the standard request.*/
static uint_8  g_assigned_address;
/* Framework module callback pointer */
static USB_CLASS_CALLBACK g_framework_callback=NULL;
/* Other Requests Callback pointer */
static USB_REQ_FUNC g_other_req_callback=NULL;

boolean const g_validate_request[MAX_STRD_REQ][3] =
{
  TRUE,TRUE,FALSE, /*USB_Strd_Req_Get_Status*/
         /* configured state: valid for existing interfaces/endpoints
            address state   : valid only for interface or endpoint 0
            default state   : not specified
         */
  TRUE,TRUE,FALSE, /* Clear Feature */
         /* configured state: valid only for device in configured state
            address state   : valid only for device (in address state),
                              interface and endpoint 0
            default state   : not specified
         */
  FALSE,FALSE,FALSE, /*reserved for future use*/
         /* configured state: request not supported
            address state   : request not supported
            default state   : request not supported
         */
  TRUE,TRUE,FALSE, /* Set Feature */
        /*  configured state: valid only for device in configured state
            address state   : valid only for interface or endpoint 0
            default state   : not specified
        */

  FALSE,FALSE,FALSE,/*reserved for future use*/
        /*  configured state: request not supported
            address state   : request not supported
            default state   : request not supported
         */
  FALSE,TRUE,TRUE, /*USB_Strd_Req_Set_Address*/
        /*  configured state: not specified
            address state   : changes to default state if specified addr == 0,
                              but uses newly specified address
            default state   : changes to address state if specified addr != 0
         */
  TRUE,TRUE,TRUE, /*USB_Strd_Req_Get_Descriptor*/
         /* configured state: valid request
            address state   : valid request
            default state   : valid request
         */
  FALSE,FALSE,FALSE, /*Set Descriptor*/
         /* configured state: request not supported
            address state   : request not supported
            default state   : request not supported
         */
  TRUE,TRUE,FALSE, /*USB_Strd_Req_Get_Config*/
         /* configured state: bConfiguration Value of current config returned
            address state   : value zero must be returned
            default state   : not specified
         */
  TRUE,TRUE,FALSE, /*USB_Strd_Req_Set_Config*/
         /* configured state: If the specified configuration value is zero,
                              then the device enters the Address state.If the
                              specified configuration value matches the
                              configuration value from a config descriptor,
                              then that config is selected and the device
                              remains in the Configured state. Otherwise, the
                              device responds with a Request Error.

            address state   : If the specified configuration value is zero,
                              then the device remains in the Address state. If
                              the specified configuration value matches the
                              configuration value from a configuration
                              descriptor, then that configuration is selected
                              and the device enters the Configured state.
                              Otherwise,response is Request Error.
            default state   : not specified
         */
  TRUE,FALSE,FALSE, /*USB_Strd_Req_Get_Interface*/
         /* configured state: valid request
            address state   : request error
            default state   : not specified
         */
  TRUE,FALSE,FALSE, /*USB_Strd_Req_Set_Interface*/
         /* configured state: valid request
            address state   : request error
            default state   : not specified
         */
  TRUE,FALSE,FALSE /*USB_Strd_Req_Sync_Frame*/
         /* configured state: valid request
            address state   : request error
            default state   : not specified
         */
};
/*****************************************************************************
 * Global Functions Prototypes - None
 *****************************************************************************/
/*****************************************************************************
 * Local Types - None
 *****************************************************************************/
/* Internal method prototypes */
static void USB_Control_Service(PTR_USB_DEV_EVENT_STRUCT event);
static void USB_Control_Service_Handler(uint_8 controller_ID, uint_8 status, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Get_Status(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Feature(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Set_Address(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Assign_Address(uint_8 controller_ID);
static uint_8 USB_Strd_Req_Get_Config(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Set_Config(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Get_Interface(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Set_Interface(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Sync_Frame(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Get_Descriptor(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
/*****************************************************************************
 * Local Variables
 *****************************************************************************/
static uint_8 ext_req_to_host[32];/* used for extended OUT transactions on
                                     CONTROL ENDPOINT*/
/*****************************************************************************
 * Global Variables
 *****************************************************************************/
USB_REQ_FUNC const g_standard_request[MAX_STRD_REQ] =
{
    USB_Strd_Req_Get_Status,
    USB_Strd_Req_Feature,
    NULL,
    USB_Strd_Req_Feature,
    NULL,
    USB_Strd_Req_Set_Address,
    USB_Strd_Req_Get_Descriptor,
    NULL,
    USB_Strd_Req_Get_Config,
    USB_Strd_Req_Set_Config,
    USB_Strd_Req_Get_Interface,
    USB_Strd_Req_Set_Interface,
    USB_Strd_Req_Sync_Frame
};

/*
** ===================================================================
**     Method      :  usb_device_USB_Framework_Init (component USB_DEVICE_STACK)
**
**     Description :
**         This fuction registers the service on the control endpoint
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         class_callback  - Class Callback
**         other_req_callback - Other
**                           Request Callback
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Framework_Init(uint_8 controller_ID, USB_CLASS_CALLBACK class_callback, USB_REQ_FUNC other_req_callback)
{
    uint_8 error=USB_OK;

    /* save input parameters */
    g_framework_callback = class_callback;
    g_other_req_callback = other_req_callback;

    /* Register CONTROL service */
    error = _usb_device_register_service(controller_ID, USB_SERVICE_EP0,

        USB_Control_Service
        );
    return error;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_Framework_DeInit (component USB_DEVICE_STACK)
**
**     Description :
**         The funtion De-initializes the Class Module
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Framework_DeInit(uint_8 controller_ID)
{
    uint_8 error;
    /* Free framwork_callback */
    g_framework_callback = NULL;

    /* Free other_req_callback */
    g_other_req_callback = NULL;

    /* Unregister CONTROL service */
    error = _usb_device_unregister_service(&controller_ID, USB_SERVICE_EP0);

    /* Return error */
    return error;
}


/*
** ===================================================================
**     Method      :  usb_device_USB_Framework_Reset (component USB_DEVICE_STACK)
**
**     Description :
**         This function is used to reset the framework module
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Framework_Reset(uint_8 controller_ID)
{
    UNUSED (controller_ID)
    return USB_OK;
}


/*
** ===================================================================
**     Method      :  USB_Control_Service (component USB_DEVICE_STACK)
**
**     Description :
**         This function handles the data sent or received on the control 
**         endpoint
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Control_Service(PTR_USB_DEV_EVENT_STRUCT event)
{
    uint_16    device_state  = 0;
    uint_8     status        = USBERR_INVALID_REQ_TYPE;
    uint_8_ptr data          = NULL;
    USB_PACKET_SIZE size;
    /* get the device state  */
    (void)_usb_device_get_status(&(event->controller_ID), USB_STATUS_DEVICE_STATE,
        &device_state);

    if (event->setup == TRUE)
    {
        /* get the setup packet */
        (void)memcpy(&g_setup_pkt, event->buffer_ptr, USB_SETUP_PKT_SIZE);

        /* take care of endianess  of the 16 bt fields correctly */
        /* if the request is standard request */
        if ((g_setup_pkt.request_type & USB_REQUEST_CLASS_MASK) ==
            USB_REQUEST_CLASS_STRD)
        {
            /* if callback is not NULL */
            if (g_standard_request[g_setup_pkt.request] != NULL)
            {
                /* if the request is valid in this device state */
                if((device_state < USB_STATE_POWERED) &&
                    (g_validate_request[g_setup_pkt.request][device_state]
                    ==TRUE))
                {
                    /* Standard Request function pointers */
                    status = g_standard_request[g_setup_pkt.request]
                        (event->controller_ID, &g_setup_pkt, &data,
                        (USB_PACKET_SIZE *)&size);
                }
            }
        }
        else /* for Class/Vendor requests */
        {
            /*get the length from the setup_request*/
            size = (USB_PACKET_SIZE)g_setup_pkt.length;

            if( (size != 0) &&
                ((g_setup_pkt.request_type & USB_DATA_DIREC_MASK) ==
                USB_DATA_TO_DEVICE) )
            {
                (void)memcpy(ext_req_to_host, &g_setup_pkt, USB_SETUP_PKT_SIZE);

                /* expecting host to send data (OUT TRANSACTION)*/
                (void)_usb_device_recv_data(&(event->controller_ID),
                    CONTROL_ENDPOINT, ext_req_to_host+USB_SETUP_PKT_SIZE,
                    (USB_PACKET_SIZE)(size));
                return;
            }
            else if(g_other_req_callback != NULL)/*call class/vendor request*/
            {
                status = g_other_req_callback(event->controller_ID,
                    &g_setup_pkt, &data, (USB_PACKET_SIZE*)&size);
            }
        }

        USB_Control_Service_Handler(event->controller_ID,
            status, &g_setup_pkt, &data, (USB_PACKET_SIZE*)&size);
    }
    /* if its not a setup request */
    else if(device_state == USB_STATE_PENDING_ADDRESS)
    {
        /* Device state is PENDING_ADDRESS */
        /* Assign the new adddress to the Device */
        (void)USB_Strd_Req_Assign_Address(event->controller_ID);
        return;
    }
    else if( ((g_setup_pkt.request_type &
            USB_DATA_DIREC_MASK) == USB_DATA_TO_DEVICE) &&
            (event->direction == USB_RECV) )
    {
        /* execution enters Control Service because of
           OUT transaction on CONTROL_ENDPOINT*/
        if(g_other_req_callback != NULL)
        {   /* class or vendor request */
            size = (USB_PACKET_SIZE)(event->len + USB_SETUP_PKT_SIZE);
            status = g_other_req_callback(event->controller_ID,
                (USB_SETUP_STRUCT*)(ext_req_to_host), &data,
                (USB_PACKET_SIZE*)&size);
        }

        USB_Control_Service_Handler(event->controller_ID,
            status, &g_setup_pkt, &data,
            (USB_PACKET_SIZE*)&size);
    }
    return;
}

/*
** ===================================================================
**     Method      :  USB_Control_Service_Handler (component USB_DEVICE_STACK)
**
**     Description :
**         This function sends a response to the data received on the 
**         control endpoint. The request is decoded in the control service
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Control_Service_Handler(uint_8 controller_ID, uint_8 status, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    if(status == USBERR_INVALID_REQ_TYPE)
    {
        /* incase of error Stall endpoint */
        (void)_usb_device_set_status(&controller_ID,
            (uint_8)(USB_STATUS_ENDPOINT | CONTROL_ENDPOINT |
            (USB_SEND << USB_COMPONENT_DIRECTION_SHIFT)),
            USB_STATUS_STALLED);
    }
    else /* Need to send Data to the USB Host */
    {
        /* send the data prepared by the handlers.*/
        if(*size > setup_packet->length)
        {
            *size = (USB_PACKET_SIZE)setup_packet->length;
        }

         /* send the data to the host */
        (void)USB_Class_Send_Data(controller_ID,
            CONTROL_ENDPOINT, *data, *size);
        if((setup_packet->request_type & USB_DATA_DIREC_MASK) ==
            USB_DATA_TO_HOST)
        {   /* Request was to Get Data from device */
            /* setup rcv to get status from host */
            (void)_usb_device_recv_data(&controller_ID,
                CONTROL_ENDPOINT,NULL,0);
        }

    }
    return;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Get_Status (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called in response to Get Status request. 
**         This is a request and is called by the host to know the status 
**         of the device, the interface and the endpoint
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Get_Status(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    uint_8 interface, endpoint;
    uint_8 status;

    if((setup_packet->request_type & USB_REQUEST_SRC_MASK) ==
        USB_REQUEST_SRC_DEVICE)
    {
        {
         /* request for Device */
         status = _usb_device_get_status(&controller_ID,
             USB_STATUS_DEVICE,&g_std_framework_data);
         g_std_framework_data    &= GET_STATUS_DEVICE_MASK;
         g_std_framework_data     = BYTE_SWAP16(g_std_framework_data);
         *size                    = DEVICE_STATUS_SIZE;
        }
    }
    else if ((setup_packet->request_type & USB_REQUEST_SRC_MASK) ==
        USB_REQUEST_SRC_INTERFACE)
    {
        /* request for Interface */
        interface                 = (uint_8) setup_packet->index;
        status                    =  USB_Desc_Get_Interface(controller_ID,interface,
                                  (uint_8_ptr)&g_std_framework_data);
        *size                     = INTERFACE_STATUS_SIZE;
    }
    else if ((setup_packet->request_type & USB_REQUEST_SRC_MASK) ==
        USB_REQUEST_SRC_ENDPOINT)
    {
        /* request for Endpoint */
        endpoint                  = (uint_8)(((uint_8) setup_packet->index) |
                                  USB_STATUS_ENDPOINT);
        status                    =  _usb_device_get_status(&controller_ID,
                                  endpoint,
                                  &g_std_framework_data);
        g_std_framework_data      = BYTE_SWAP16(g_std_framework_data);
        *size                     = ENDP_STATUS_SIZE;
    }

    *data = (uint_8_ptr)&g_std_framework_data;
    return status;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Feature (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called in response to Clear or Set Feature 
**         request. This is a ch9 request, used to set/clear a feature on 
**         the device (device_remote_wakeup and test_mode) or on the 
**         endpoint(ep halt)
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Feature(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    uint_16 device_status;
    uint_8  set_request;
    uint_8  status = USBERR_INVALID_REQ_TYPE;
    uint_8  epinfo;
    uint_8  event;

    UNUSED (data)

    *size=0;
    /* find whether its a clear feature request or a set feature request */
    set_request = (uint_8)
        ((setup_packet->request & USB_SET_REQUEST_MASK) >> 1 );

    if((setup_packet->request_type & USB_REQUEST_SRC_MASK) ==
        USB_REQUEST_SRC_DEVICE)
    {


        if(set_request == TRUE)
        {
           uint_16 device_set_feature_bitfield = DEVICE_SET_FEATURE_MASK;

           if(((uint_16)(1 << (uint_8)setup_packet->value)) & device_set_feature_bitfield)
           {
              status = USB_OK;
              if(setup_packet->value == DEVICE_FEATURE_REMOTE_WAKEUP)
                {
                status = _usb_device_get_status(&controller_ID,
                USB_STATUS_DEVICE, &device_status);
              /* add the request to be cleared from device_status */
                device_status |= (uint_16)(1 << (uint_8)setup_packet->value);

                              /* set the status on the device */
                status = _usb_device_set_status(&controller_ID,
                USB_STATUS_DEVICE, device_status);

                }

           }
           else
           {
              status = USBERR_INVALID_REQ_TYPE;
           }
        }
        else
        {
           if(((uint_16)(1 << (uint_8)setup_packet->value)) & DEVICE_CLEAR_FEATURE_MASK)
           {
              status = USB_OK;
              if(setup_packet->value == DEVICE_FEATURE_REMOTE_WAKEUP)
                {
                status = _usb_device_get_status(&controller_ID,
                USB_STATUS_DEVICE, &device_status);
                /* remove the request to be cleared from device_status */
                device_status &= (uint_16)~(1 << (uint_8)setup_packet->value);
                status = _usb_device_set_status(&controller_ID,
                USB_STATUS_DEVICE, device_status);
                }
           }
           else
           {
              status = USBERR_INVALID_REQ_TYPE;
           }
        }
    }
    else if ((setup_packet->request_type & USB_REQUEST_SRC_MASK) ==
        USB_REQUEST_SRC_ENDPOINT)
    {
        /* request for Endpoint */
        epinfo = (uint_8)(setup_packet->index & 0x00FF);
          status = _usb_device_set_status(&controller_ID,
              (uint_8)(epinfo|USB_STATUS_ENDPOINT), set_request);

        if((set_request == 0)&&(epinfo == 0x03))
        {
            asm("nop");
        }

        event = (uint_8)(set_request ?
            USB_APP_EP_STALLED : USB_APP_EP_UNSTALLED);
        /* inform the upper layers of stall/unstall */
        g_framework_callback(controller_ID,event,(void*)&epinfo);
    }
    return status;
}


/*
** ===================================================================
**     Method      :  USB_Strd_Req_Assign_Address (component USB_DEVICE_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Assign_Address(uint_8 controller_ID)
{
    /* Set Device Address */
    (void)_usb_device_set_address(&controller_ID, g_assigned_address);

    /* Set Device state */
    (void)_usb_device_set_status(&controller_ID,
        USB_STATUS_DEVICE_STATE, USB_STATE_ADDRESS);
    /* Set Device state */
    (void)_usb_device_set_status(&controller_ID, USB_STATUS_ADDRESS,
        g_assigned_address);

    return USB_OK;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Get_Config (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called in response to Get Config request. 
**         This is a ch9 request and is used to know the currently used 
**         configuration
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Get_Config(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    UNUSED (setup_packet)
    *size = CONFIG_SIZE;
    (void)_usb_device_get_status(&controller_ID,
        USB_STATUS_CURRENT_CONFIG, &g_std_framework_data);
    g_std_framework_data = BYTE_SWAP16(g_std_framework_data);
    *data = (uint_8_ptr)(&g_std_framework_data);

    return USB_OK;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Set_Config (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called in response to Set Config request. 
**         This is a ch9 request and is used by the host to set the new 
**         configuration
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Set_Config(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    uint_8 status = USBERR_INVALID_REQ_TYPE;
    uint_16 config_val;

    UNUSED (data)
    *size          = 0;
    status         = USB_STATUS_ERROR;
    config_val     = setup_packet->value;

    if (USB_Desc_Valid_Configation(controller_ID, config_val))
    /*if valid configuration (fn returns boolean value)*/
    {
        uint_16 device_state = USB_STATE_CONFIG;

        /* if config_val is 0 */
        if (!config_val)
        {
            device_state = USB_STATE_ADDRESS ;
        }

        status = _usb_device_set_status(&controller_ID, USB_STATUS_DEVICE_STATE,
            device_state);
        status = _usb_device_set_status(&controller_ID,
            USB_STATUS_CURRENT_CONFIG, config_val);
        /*
           Callback to the app. to let the application know about the new
           Configuration
        */
        g_framework_callback(controller_ID,USB_APP_CONFIG_CHANGED,
            (void *)&config_val);
        g_framework_callback(controller_ID,USB_APP_ENUM_COMPLETE, NULL);
    }

    return status;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Get_Interface (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called in response to Get Interface request. 
**         This is a ch9 request and is used to know the current interface
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Get_Interface(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    uint_8 status;

    *size     = INTERFACE_STATUS_SIZE;
    status    = USB_Desc_Get_Interface(controller_ID,(uint_8)setup_packet->index,
        (uint_8_ptr)&g_std_framework_data);
    *data     = (uint_8_ptr)&g_std_framework_data;

    return status;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Set_Interface (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called in response to Set Interface request. 
**         This is a ch9 request and is used by the  host to set the 
**         interface
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Set_Interface(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    uint_8 status;

    UNUSED (data);
    *size = 0;

    /* Request type not for interface */
    if ((setup_packet->request_type & 0x03) != 0x01)
    {
        return USB_STATUS_ERROR;
    }

    /* Get Interface and alternate interface from setup_packet */
    status = USB_Desc_Set_Interface(controller_ID,(uint_8)setup_packet->index,
        (uint_8)setup_packet->value);

    UNUSED (status);

    return USB_OK;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Sync_Frame (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called in response to Sync Frame request. 
**         This req is used to set and then report an ep's 
**         synchronization frame
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Sync_Frame(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    uint_8 status;

    UNUSED (setup_packet)
    *size = FRAME_SIZE;

    /* Get the frame number */
    status = _usb_device_get_status(&controller_ID, USB_STATUS_SOF_COUNT,
        &g_std_framework_data);
    *data = (uint_8_ptr)&g_std_framework_data;

    return status;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Get_Descriptor (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called in response to Get Descriptor request. 
**         This is a ch9 request and is used to send the descriptor 
**         requested by the host
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Get_Descriptor(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    uint_8 type    = USB_uint_16_high(setup_packet->value);
    uint_16 index  = (uint_8)UNINITIALISED_VAL;
    uint_8 str_num = (uint_8)UNINITIALISED_VAL;
    uint_8 status;

    if (type == STRING_DESCRIPTOR_TYPE)
    {
        /* for string descriptor set the language and string number */
        index      = setup_packet->index;
        /*g_setup_pkt.lValue*/
        str_num    = USB_uint_16_low(setup_packet->value);
    }

    /* Call descriptor class to get descriptor */
    status = USB_Desc_Get_Descriptor(controller_ID,
                                     type,str_num,index,data,size);
    return status;
}

/*
** ===================================================================
**     Method      :  USB_Strd_Req_Set_Address (component USB_DEVICE_STACK)
**
**     Description :
**         This is a ch9 request, saves the new address in a global 
**         variable. This address is assigned to the device after this 
**         transaction completes
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_Strd_Req_Set_Address(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size)
{
    UNUSED (data)
    *size=0;
    /* update device status */
    (void)_usb_device_set_status(&controller_ID,
        USB_STATUS_DEVICE_STATE, USB_STATE_PENDING_ADDRESS);

    /*store the address from setup_packet into assigned_address*/
    g_assigned_address = (uint_8)setup_packet->value;

    return USB_OK;
}


/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

