/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_driver.c
**     Project   : ProcessorExpert
**     Processor : MK60N512LQ100
**     Component : USB_DEVICE_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-20, 14:23, # CodeGen: 1
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#include "usb_devapi.h" /* USB Device Layer API Header File */
#include "usb_dciapi.h" /* USB Controller API Header File */

/****************************************************************************
 * Global Variables
 ****************************************************************************/
/* Array of USB Service pointers */
static USB_SERVICE_CALLBACK g_usb_CB[USB_SERVICE_MAX];
/* Array of USB Component Status */
/* Test mode is the last service */
static uint_16 g_usb_component_status[USB_STATUS_TEST_MODE];
/* Array of USB Endpoint Status */
static uint_16 g_usb_ep_status[MAX_SUPPORTED_ENDPOINTS];
/* Current un-initialized non CONTROL Endpoint */
static uint_8 g_EPn=0;
/* Maximum number of Non CONTROL Endpoint required by upper layer */
static uint_8 g_EPn_max=0;

/*****************************************************************************
 * Local Types - None
 *****************************************************************************/
/*****************************************************************************
 * Local Functions Prototypes - None
 *****************************************************************************/
/* Internal method prototypes */
static void USB_Device_Init_Params(void);

/*
** ===================================================================
**     Method      :  USB_Device_Init_Params (component USB_DEVICE_STACK)
**
**     Description :
**         The funtion initializes the Device Layer Structures
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_Device_Init_Params(void)
{
    uint_8 loop_index=0;

    g_EPn= g_EPn_max; /* 1 control endpoint */

    /*
       Initialize USB_STATUS_DEVICE_STATE, USB_STATUS_INTERFACE,
       USB_STATUS_ADDRESS, USB_STATUS_CURRENT_CONFIG, USB_STATUS_SOF_COUNT
       and USB_STATUS_DEVICE to USB_STATUS_UNKNOWN
    */
    for(loop_index = 0; loop_index < USB_STATUS_TEST_MODE; loop_index++)
    {
         {
          g_usb_component_status[loop_index] = USB_STATUS_UNKNOWN;
         }
    }

    /* Initialize status of All Endpoints to USB_STATUS_DISABLED */
    for(loop_index = 0; loop_index < MAX_SUPPORTED_ENDPOINTS; loop_index++)
    {
        g_usb_ep_status[loop_index] = USB_STATUS_DISABLED;
    }
}

/*
** ===================================================================
**     Method      :  usb_device__usb_device_init (component USB_DEVICE_STACK)
**
**     Description :
**         This function initializes the Device layer and the
**         Controller layer of the S08 USB stack. It initialised the
**         variables used for this layer and then calls the controller
**         layer initialize function
**     Parameters  :
**         NAME            - DESCRIPTION
**         device_number   - [IN] USB Device
**                           controller to initialize
**       * handle          - [IN] Pointer to USB Device handle
**         number_of_endpoints - [IN]
**                           Number of endpoints to initialize
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8  _usb_device_init(uint_8 device_number, _usb_device_handle _PTR_ handle, uint_8 number_of_endpoints)
{
    UNUSED(handle);

    /* validate endpoints param */
    if((number_of_endpoints > MAX_SUPPORTED_ENDPOINTS) ||
       (number_of_endpoints < MIN_SUPPORTED_ENDPOINTS))
    {
        return USBERR_INVALID_NUM_OF_ENDPOINTS;
    }

    /*init variables */
    g_EPn_max = (uint_8)(number_of_endpoints - 1);

    USB_Device_Init_Params();

    /* Initialize all services to null value */
    Clear_Mem((uint_8_ptr)g_usb_CB,
        (sizeof(USB_SERVICE_CALLBACK) * USB_SERVICE_MAX), (uint_8)NULL);
    /* Call controller layer initialization function */
    return USB_DCI_Init(device_number);
}

/*
** ===================================================================
**     Method      :  usb_device__usb_device_deinit (component USB_DEVICE_STACK)
**
**     Description :
**         This function de-initializes the Device layer and the
**         Controller layer
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 _usb_device_deinit(void)
{
    g_EPn_max = 0;
    /* Call controller layer de-initialization function */
    return USB_DCI_DeInit();
}

/*
** ===================================================================
**     Method      :  usb_device__usb_device_init_endpoint (component USB_DEVICE_STACK)
**
**     Description :
**         This function initializes an endpoint the Device layer and
**         the Controller layer in the S08 USB stack. It validate
**         whether all endpoints have already been initialized or not
**         and then calls the controller layer endpoint initialize
**         function
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number
**         max_packet_size - [IN] Maximum
**                           packet size (in bytes) for the endpoint
**         direction       - [IN] Direction of transfer
**         endpoint_type   - [IN] Type of endpoint
**         flag            - [IN] Zero termination flag
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 _usb_device_init_endpoint(_usb_device_handle handle, uint_8 endpoint_number, uint_16 max_packet_size, uint_8 direction, uint_8 endpoint_type, uint_8 flag)
{
    USB_EP_STRUCT ep_str;

    uint_8 status=USB_OK;

    /* check if all endpoint have already been initialised */
    if((g_EPn == 0) && (endpoint_number != CONTROL_ENDPOINT))
    {
        return USBERR_EP_INIT_FAILED;
    }

    ep_str.direction    = direction;
    ep_str.ep_num       = endpoint_number;
    ep_str.size         = max_packet_size;
    ep_str.type         = endpoint_type;

    /* call controller layer for initiazation */
    status = USB_DCI_Init_EndPoint(*((uint_8*)handle), &ep_str, flag);

    /* if endpoint successfully initialised update counter */
    if ((ep_str.ep_num != CONTROL_ENDPOINT) && (status == USB_OK))
    {
        g_EPn--;
    }

    return status;
}

/*
** ===================================================================
**     Method      :  usb_device__usb_device_deinit_endpoint (component USB_DEVICE_STACK)
**
**     Description :
**         This function deinitializes an endpoint the Device layer and
**         the Controller layer in the S08 USB stack. It validate
**         whether all endpoints have already been deinitialized or not
**         and then calls the controller layer endpoint deinitialize
**         function
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number
**         direction       - [IN] Direction of transfer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 _usb_device_deinit_endpoint(_usb_device_handle handle, uint_8 endpoint_number, uint_8 direction)
{
    uint_8 status=USB_OK;

    /* check if all endpoint have already been initialised */
    if((g_EPn == g_EPn_max) && (endpoint_number != CONTROL_ENDPOINT))
    {
        return USBERR_EP_DEINIT_FAILED;
    }

    /* call controller layer for initiazation */
    status = USB_DCI_Deinit_EndPoint(*((uint_8*)handle), endpoint_number, direction);

    /* if endpoint successfully deinitialised update counter */
    if ((endpoint_number != CONTROL_ENDPOINT) && (status == USB_OK))
    {
        g_EPn++;
    }

    return status;
}

/*
** ===================================================================
**     Method      :  usb_device__usb_device_get_status (component USB_DEVICE_STACK)
**
**     Description :
**         This function retrieves the endpoint as well USB component
**         status which is stored by calling USB_Device_Set_Status.
**         This function can be called by Application as well as the
**         DCI layer.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         component       - [IN] USB Component status to
**                           get
**         status          - [OUT] Pointer to 16 bit return value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 _usb_device_get_status(_usb_device_handle handle, uint_8 component, uint_16_ptr status)
{
    /* get the endpoint number from component input variable */
    uint_8 ep_num = (uint_8)(component & USB_STATUS_ENDPOINT_NUMBER_MASK);
    UNUSED (handle)

    if((component <= USB_STATUS_TEST_MODE) &&
       (component >= USB_STATUS_DEVICE_STATE))
    {
        /* Get the corresponding component status
           -1 as components start from 1 */
        *status = g_usb_component_status[component-1];
    }
    else if ((component & USB_STATUS_ENDPOINT) &&
        (ep_num < MAX_SUPPORTED_ENDPOINTS))
    {
        /* Get the corresponding endpoint status */
        *status = g_usb_ep_status[ep_num];
    }
    else
    {
        return USBERR_BAD_STATUS;
    }

    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_device__usb_device_set_status (component USB_DEVICE_STACK)
**
**     Description :
**         This function sets the endpoint as well USB component status
**         which can be retrieved by calling _usb_device_get_status.
**         This function can be called by Application as well as the
**         DCI layer.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         component       - [IN] USB Component status to
**                           set
**         setting         - [IN] Status to set
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 _usb_device_set_status(_usb_device_handle handle, uint_8 component, uint_16 setting)
{
    /* get the endpoint number from component input variable */
    uint_8 ep_num = (uint_8)(component & USB_STATUS_ENDPOINT_NUMBER_MASK);
    UNUSED (handle)

    if((component <= USB_STATUS_TEST_MODE) &&
       (component >= USB_STATUS_DEVICE_STATE))
    {
        /*
           Set the corresponding component setting
           -1 as components start from 1
        */
        g_usb_component_status[component-1] = setting;
    }
    else if ((component & USB_STATUS_ENDPOINT) &&
        (ep_num < MAX_SUPPORTED_ENDPOINTS))
    {
        uint_8 direction =
            (uint_8)((component >> USB_COMPONENT_DIRECTION_SHIFT) &
            USB_COMPONENT_DIRECTION_MASK);
        /* HALT Endpoint */
        if(setting == USB_STATUS_STALLED)
        {
            _usb_device_stall_endpoint(handle, ep_num, direction);
        }
        else if((setting == USB_STATUS_IDLE) &&
            (g_usb_ep_status[ep_num] == USB_STATUS_STALLED))
        {
            _usb_device_unstall_endpoint(handle, ep_num, direction);

            if(ep_num == CONTROL_ENDPOINT)
            {
                direction = (uint_8)((direction == USB_SEND)?
                    (USB_RECV):(USB_SEND));
                _usb_device_unstall_endpoint(handle, ep_num, direction);
            }
        }
        /* Set the corresponding endpoint setting */
        g_usb_ep_status[ep_num] = setting;
    }
    else
    {
        return USBERR_BAD_STATUS;
    }
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_device__usb_device_register_service (component USB_DEVICE_STACK)
**
**     Description :
**         This function registers a callback function from the
**         application if it is called not already registered so that
**         the regitered callback function can be if the event of that
**         type occurs
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         type            - [IN] type of event or endpoint number to
**                           service 
**         service         - [IN] pointer to callback function
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 _usb_device_register_service(uint_8 controller_ID, uint_8 type, USB_SERVICE_CALLBACK service)
{
    UNUSED (controller_ID)
    /* check if the type is valid and callback for the type
       is not already registered */
    if(((type  <= USB_SERVICE_MAX_EP) ||
        ((type < USB_SERVICE_MAX) && (type >= USB_SERVICE_BUS_RESET))) &&
       (g_usb_CB[type] == NULL))
    {
        /* register the callback function */
        g_usb_CB[type] = service;
        return USB_OK;
    }
    else
    {
        return USBERR_ALLOC_SERVICE;
    }
}

/*
** ===================================================================
**     Method      :  usb_device__usb_device_unregister_service (component USB_DEVICE_STACK)
**
**     Description :
**         This function un registers a callback function which has
**         been previously registered by the application layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         event_endpoint  - [IN] Endpoint (0
**                           through 15) or event to service
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 _usb_device_unregister_service(_usb_device_handle handle, uint_8 event_endpoint)
{
    UNUSED (handle)
    /* check if the type is valid and callback for the type
       is already registered */
    if(((event_endpoint  <= USB_SERVICE_MAX_EP) ||
        ((event_endpoint < USB_SERVICE_MAX) && (event_endpoint >= USB_SERVICE_BUS_RESET))) &&
       (g_usb_CB[event_endpoint] != NULL))
    {
        /* unregister the callback */
        g_usb_CB[event_endpoint] = NULL;
        return USB_OK;
    }
    else
    {
        return USBERR_UNKNOWN_ERROR;
    }
}

/*
** ===================================================================
**     Method      :  usb_device_USB_Device_Call_Service (component USB_DEVICE_STACK)
**
**     Description :
**         This function calls the registered service callback function
**         of the application layer based on the type of event received.
**         This function is called from the DCI layer.
**     Parameters  :
**         NAME            - DESCRIPTION
**         type            - [IN] Type of service or endpoint
**         event           - [IN] Pointer to event structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8  USB_Device_Call_Service(uint_8 type,PTR_USB_DEV_EVENT_STRUCT  event)
{
    if(type == USB_SERVICE_BUS_RESET)
    {    /* if it is an reset interrupt then reset all status structures */
       USB_Device_Init_Params();
    }

    /* check if the callback is registered or not */
    if(g_usb_CB[type] != NULL)
    {
        /* call the callback function */
        g_usb_CB[type](event);
    }

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

