/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_class.c
**     Project   : ProcessorExpert
**     Processor : MK60N512LQ100
**     Component : USB_DEVICE_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-20, 13:47, # CodeGen: 1
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

/* FILE usb_class.c */
#include "usb_class.h"      /* USB class Header File */
#include "usb_devapi.h"     /* USB device Header file */
#include "usb_framework.h"  /* USB framework module header file */
#include "usb_device.h"

/****************************************************************************
 * Global Variables
 ****************************************************************************/
 /* Class callback pointer */
static USB_CLASS_CALLBACK g_class_callback = NULL;
/* save the device state before device goes to suspend state */
static uint_16 g_device_state_before_suspend;
/* Internal method prototypes */
static void USB_Device_Init_Params(void);
static void USB_Control_Service(PTR_USB_DEV_EVENT_STRUCT event);
static void USB_Control_Service_Handler(uint_8 controller_ID, uint_8 status, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Get_Status(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Feature(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Set_Address(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Get_Config(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Set_Config(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Get_Interface(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Set_Interface(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Sync_Frame(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static uint_8 USB_Strd_Req_Get_Descriptor(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
static void USB_DCI_CallBack(LDD_TDeviceData *TDevDataPtr, LDD_USB_Device_TTD *pTD);
static void USB_DCI_SetAddressCallback(LDD_TDeviceData *USBDevDataPtr, LDD_USB_Device_TTD *pTD);
static uint_8 USB_DCI_Get_BDT_Index(uint_8 ep_num, uint_8 direction, bool odd);
static uint_8 USB_DCI_Validate_Param(uint_8 ep_num, uint_8 direction, bool odd);

/*
** ===================================================================
**     Method      :  USB_Suspend_Service (component USB_DEVICE_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Suspend_Service(PTR_USB_DEV_EVENT_STRUCT event)
{
    /* Get the status of the device before suspend, so that on resume we
       can get back to the same state */
    (void)_usb_device_get_status(&(event->controller_ID),
        USB_STATUS_DEVICE_STATE, &g_device_state_before_suspend);
    /* Set the device state in the Device Layer to SUSPEND */
    (void)_usb_device_set_status(&(event->controller_ID), USB_STATUS_DEVICE_STATE,
        USB_STATE_SUSPEND);

    return;
}

/*
** ===================================================================
**     Method      :  USB_Resume_Service (component USB_DEVICE_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Resume_Service(PTR_USB_DEV_EVENT_STRUCT event)
{
    uint_16 device_state;
    (void)_usb_device_get_status(&(event->controller_ID), USB_STATUS_DEVICE_STATE,
        &device_state);
    if(device_state == USB_STATE_SUSPEND)
    {
        /*
           Set the device state in the Device Layer to the state
           before suspend
        */
        (void)_usb_device_set_status(&(event->controller_ID),
            USB_STATUS_DEVICE_STATE, g_device_state_before_suspend);
    }
    return;
}

/*
** ===================================================================
**     Method      :  USB_Stall_Service (component USB_DEVICE_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Stall_Service(PTR_USB_DEV_EVENT_STRUCT event)
{
    if(event->ep_num == CONTROL_ENDPOINT)
    {
        /* Update the Endpoint Status in the Device Layer to Idle */
        (void)_usb_device_set_status(&(event->controller_ID),
            (uint_8)(USB_STATUS_ENDPOINT | CONTROL_ENDPOINT |
            (event->direction << USB_COMPONENT_DIRECTION_SHIFT)),
            (uint_16)USB_STATUS_IDLE);
    }
    return;
}

/*
** ===================================================================
**     Method      :  USB_Sof_Service (component USB_DEVICE_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Sof_Service(PTR_USB_DEV_EVENT_STRUCT event)
{
    uint_16 sof_count;

    /* update SOF */
    sof_count = event->buffer_ptr[0];
    sof_count <<= SOF_HIGH_BYTE_SHIFT;
    sof_count |= event->buffer_ptr[1];

    /* write SOF to status */
    (void)_usb_device_set_status(&(event->controller_ID), USB_STATUS_SOF_COUNT,
        sof_count);
    return;
}

/*
** ===================================================================
**     Method      :  USB_Reset_Service (component USB_DEVICE_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Reset_Service(PTR_USB_DEV_EVENT_STRUCT event)
{
    USB_EP_STRUCT ep_struct;
    uint_8 err;

    /* Initialize the endpoint 0 in both directions */
    ep_struct.direction = USB_SEND;
    ep_struct.ep_num = CONTROL_ENDPOINT;
    ep_struct.size = CONTROL_MAX_PACKET_SIZE;
    ep_struct.type = USB_CONTROL_PIPE;

    /* Deinit Endpoint in case its already initialized */
    err = _usb_device_deinit_endpoint(&(event->controller_ID),
            ep_struct.ep_num, ep_struct.direction);
    /* now initialize the endpoint */
    err = _usb_device_init_endpoint(&(event->controller_ID),
                    ep_struct.ep_num, (uint_16)ep_struct.size, ep_struct.direction, ep_struct.type, TRUE);

    ep_struct.direction = USB_RECV;
    /* Deinit Endpoint in case its already initialized */
    (void)_usb_device_deinit_endpoint(&(event->controller_ID),
            ep_struct.ep_num, ep_struct.direction);
    /* now initialize the endpoint */
    (void)_usb_device_init_endpoint(&(event->controller_ID),
                    ep_struct.ep_num, (uint_16)ep_struct.size, ep_struct.direction, ep_struct.type, TRUE);

    /* set the default device state */
    (void)_usb_device_set_status(&(event->controller_ID), USB_STATUS_DEVICE_STATE,
        USB_STATE_DEFAULT);

    /* set the default device state */
    (void)_usb_device_set_status(&(event->controller_ID), USB_STATUS_DEVICE,
        SELF_POWERED >> SELF_POWER_BIT_SHIFT);

    /* set the EndPoint Status as Idle in the device layer */
    (void)_usb_device_set_status(&(event->controller_ID),
        (uint_8)(USB_STATUS_ENDPOINT | CONTROL_ENDPOINT |
        (USB_SEND << USB_COMPONENT_DIRECTION_SHIFT)),
        USB_STATUS_IDLE);
    /* let the application know that bus reset has taken place */
    g_class_callback(event->controller_ID, USB_APP_BUS_RESET, NULL);

        UNUSED(err);
    return;
}


/*
** ===================================================================
**     Method      :  USB_Error_Service (component USB_DEVICE_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Error_Service(PTR_USB_DEV_EVENT_STRUCT event)
{
    /* notify the application of the error */
    g_class_callback(event->controller_ID, USB_APP_ERROR,
        (uint_8*)(&(event->errors)));
    return;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_Class_Init (component USB_DEVICE_STACK)
**
**     Description :
**         The function initializes the Class Module
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         class_callback  - [IN] Class Callback
**         other_req_callback - [IN] Other
**                           Requests Callback
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Class_Init(uint_8 controller_ID, USB_CLASS_CALLBACK class_callback, USB_REQ_FUNC other_req_callback)
{
   uint_8 status = USB_Framework_Init(controller_ID,class_callback,
        other_req_callback);

    /* save callback address */
    g_class_callback = class_callback;

    if(status == USB_OK)
    {
        /* Register all the services here */
        status |= _usb_device_register_service(controller_ID,
            USB_SERVICE_BUS_RESET, USB_Reset_Service);
        status |= _usb_device_register_service(controller_ID,
            USB_SERVICE_SOF,USB_Sof_Service);
        status |= _usb_device_register_service(controller_ID,
            USB_SERVICE_SLEEP,USB_Suspend_Service);
        status |= _usb_device_register_service(controller_ID,
            USB_SERVICE_RESUME,USB_Resume_Service);
        status |= _usb_device_register_service(controller_ID,
            USB_SERVICE_STALL,USB_Stall_Service);
        status |= _usb_device_register_service(controller_ID,
            USB_SERVICE_ERROR,USB_Error_Service);

        /* set the device state as powered */
        (void)_usb_device_set_status(&controller_ID,
            USB_STATUS_DEVICE_STATE,USB_STATE_POWERED);
        g_device_state_before_suspend = USB_STATE_POWERED;
    }

    return status;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_Class_DeInit (component USB_DEVICE_STACK)
**
**     Description :
**         This function De-initializes the Class Module
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Class_DeInit(uint_8 controller_ID)
{
    uint_8 status = USB_OK;
    /* Free class_callback */
    g_class_callback = NULL;

    /* Unegister all the services here */
    status |= _usb_device_unregister_service(&controller_ID,USB_SERVICE_BUS_RESET);
    status |= _usb_device_unregister_service(&controller_ID,USB_SERVICE_SOF);
    status |= _usb_device_unregister_service(&controller_ID,USB_SERVICE_SLEEP);
    status |= _usb_device_unregister_service(&controller_ID,USB_SERVICE_RESUME);
    status |= _usb_device_unregister_service(&controller_ID,USB_SERVICE_STALL);
    status |= _usb_device_unregister_service(&controller_ID,USB_SERVICE_ERROR);

    if(status == USB_OK)
        /* Call Framework deinit function */
        status = USB_Framework_DeInit(controller_ID);

    return status;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_Class_Send_Data (component USB_DEVICE_STACK)
**
**     Description :
**         This function calls the device to send data upon receiving
**         an IN token
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         ep_num          - [IN] Endpoint number
**         buff_ptr        - [IN] Buffer to send
**         size            - [IN] Length of the transfer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Class_Send_Data(uint_8 controller_ID, uint_8 ep_num, uint_8_ptr buff_ptr, USB_PACKET_SIZE size)
{
    uint_8 status = USB_OK;
    uint_16 device_state, state;

    (void)_usb_device_get_status(&controller_ID, USB_STATUS_DEVICE_STATE,
        &device_state);
    (void)_usb_device_get_status(&controller_ID, USB_STATUS_DEVICE, &state);
    if((device_state == USB_STATE_SUSPEND) &&
        (state & REMOTE_WAKEUP_STATUS_MASK ) &&
        (USB_Frame_Remote_Wakeup(controller_ID) == TRUE))
    {
        USB_lock;
        /* Resume the bus */
                _usb_device_assert_resume(&controller_ID);

        device_state = USB_STATE_CONFIG;
        /* Set the device state in the Device Layer to DEFAULT */
        (void)_usb_device_set_status(&controller_ID, USB_STATUS_DEVICE_STATE,
            USB_STATE_CONFIG);
        USB_unlock;
    }

    if(device_state != USB_STATE_SUSPEND)
    {    /* if not suspended */
         status = _usb_device_send_data(&controller_ID, ep_num, buff_ptr, size);
    }

    return status;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_Class_Periodic_Task (component USB_DEVICE_STACK)
**
**     Description :
**         This funtion calls for periodic tasks
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void USB_Class_Periodic_Task(void)
{
}

/* END usb_class.c */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/