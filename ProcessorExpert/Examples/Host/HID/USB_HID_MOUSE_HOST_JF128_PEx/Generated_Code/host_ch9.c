/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_ch9.c
**     Project   : ProcessorExpert
**     Processor : MCF51JF128_64
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:26, # CodeGen: 27
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "hostapi.h"
#include "usbprv.h"
#include "host_dev_list.h"
#include "host_common.h"
#include "host_ch9.h"
#include "usbprv_host.h"

/* Prototype, copy to stack frames for each use instance */

static const USB_SETUP req_prototype =
{
    0,          /* request type */
    0,          /* request */
    {0,0},      /* WVALUE  */
    {0,0},      /* WINDEX  */
    {0,0}       /* WLENGTH  */
};

/* Unpublished functions, not intended for application use */
static void  usb_host_cntrl_transaction_done(_usb_pipe_handle,
pointer, uchar_ptr, uint_32, uint_32);

static USB_STATUS  usb_host_ch9_dev_req(_usb_device_instance_handle,
USB_SETUP_PTR, uchar_ptr);

/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : usb_host_cntrl_transaction_done
* Returned Value : none
* Comments       :
*     Callback function to process transaction-done events
*     State machine for enumeration/subsequent transactions
*     Between states, the 8-byte buffer in device_instance
*        is used to save the first part of the configuration.
*     Pointer desc in various flavors (uchar_ptr, cfig_ptr)
*        is used to parse this buffer in various ways.
*
*END*--------------------------------------------------------------------*/
static void  usb_host_cntrl_transaction_done
(
/* [IN] the pipe handle */
_usb_pipe_handle  handle,

/* [IN] The user parameter */
pointer           user_parm,

/* [IN] the buffer */
uchar_ptr         buffer,

/* [IN] The length of the transfer */
uint_32           length,

/* [IN] status of the transfer */
uint_32           status
)
{ /* Body */
    USB_HOST_STATE_STRUCT_PTR  usb_host_ptr;
    PIPE_DESCRIPTOR_STRUCT_PTR pipe_ptr =
    (PIPE_DESCRIPTOR_STRUCT_PTR)handle;
    DEV_INSTANCE_PTR           dev_inst_ptr =
    (DEV_INSTANCE_PTR)pipe_ptr->DEV_INSTANCE;
    DESCRIPTOR_UNION           desc;
    uint_32                    config_size;

    usb_host_ptr = (USB_HOST_STATE_STRUCT_PTR)dev_inst_ptr->host;

/*----------------------------------------------------**
** Enumeration state machine -- cases are named after **
** the just-completed transactions.                   **
**----------------------------------------------------*/

    switch (dev_inst_ptr->state) {
    case DEVSTATE_INITIAL:      /* initial device state */
        break;
    case DEVSTATE_DEVDESC8:     /* device descriptor [0..7]*/
        /* We must have received the first 8 bytes in
        ** dev_inst_ptr->dev_descriptor which contains the
        ** max packet size for this control endpoint
        */
        pipe_ptr->MAX_PACKET_SIZE =
        dev_inst_ptr->dev_descriptor.bMaxPacketSize;

        /* Notify device driver of MaxPacketSize0 for this device */
        status = _usb_host_update_max_packet_size_call_interface (usb_host_ptr, pipe_ptr);

        if (status != USB_OK)
        {
            dev_inst_ptr->state = DEVSTATE_INITIAL;
            break;
        }
        else
        {
            dev_inst_ptr->state = DEVSTATE_ADDR_SET;
        }

        /* Now set the address that we assigned when we initialized
        ** the device instance struct for this device
        */
        status = _usb_host_ch9_set_address((pointer)dev_inst_ptr);

        if (status != USB_STATUS_TRANSFER_QUEUED)
        {
            dev_inst_ptr->state = DEVSTATE_INITIAL;
            break;
        }

        break;
    case DEVSTATE_ADDR_SET:     /* address set */
        pipe_ptr->DEVICE_ADDRESS = dev_inst_ptr->address;

        /* Notify device driver of USB device's new address */
        status = _usb_host_update_device_address_call_interface (usb_host_ptr, pipe_ptr);

        if (status != USB_OK)
        {
            dev_inst_ptr->state = DEVSTATE_INITIAL;
            break;
        }

        dev_inst_ptr->state = DEVSTATE_DEV_DESC;

        /* Now get the full descriptor */
        status = _usb_host_ch9_get_descriptor((pointer)dev_inst_ptr,
        USB_DESC_TYPE_DEV << 8,
        0,
        USB_DESC_LEN_DEV,
        (uchar_ptr)&dev_inst_ptr->dev_descriptor);

        if (status != USB_STATUS_TRANSFER_QUEUED)
        {
            dev_inst_ptr->state = DEVSTATE_INITIAL;
            break;
        }

        break;
    case DEVSTATE_DEV_DESC:     /* full device descriptor received */
        /* Now lets get the first 9 bytes of the configuration
        ** descriptor
        */
        desc.pntr = &dev_inst_ptr->buffer;
        dev_inst_ptr->state = DEVSTATE_GET_CFG9;
        status = _usb_host_ch9_get_descriptor((pointer)dev_inst_ptr,
        USB_DESC_TYPE_CFG << 8,
        0,
        sizeof(dev_inst_ptr->buffer),
        desc.bufr);

        if (status != USB_STATUS_TRANSFER_QUEUED)
        {
            dev_inst_ptr->state = DEVSTATE_INITIAL;
            break;
        }

        break;
    case DEVSTATE_GET_CFG9:     /* Read 9 bytes of config descriptor */
        dev_inst_ptr->state = DEVSTATE_SET_CFG;
        /* Now select the configuration as specified in the
        ** descriptor
        */
        desc.cfig = (CONFIGURATION_DESCRIPTOR_PTR)dev_inst_ptr->buffer;
        config_size = utoh16(desc.cfig->wTotalLength);

        desc.pntr = &dev_inst_ptr->buffer;
        if (USB_OK != usb_dev_list_get_memory(dev_inst_ptr,
                    config_size,
                    USB_MEMTYPE_CONFIG,
                    (pointer _PTR_)&desc))
        {
            return;
        }
        desc.word += MEM_HEADER_LEN; /* step past header */
        dev_inst_ptr->state = DEVSTATE_SET_CFG;
        /* We can only read one config descriptor at a time */
        status = _usb_host_ch9_get_descriptor((pointer)dev_inst_ptr,
        USB_DESC_TYPE_CFG << 8,
        0,
        (uint_16)config_size,
        desc.bufr);

        if (status != USB_STATUS_TRANSFER_QUEUED)
        {
            dev_inst_ptr->state = DEVSTATE_INITIAL;
            break;
        }

        break;
    case DEVSTATE_SET_CFG:     /* config descriptor [0..8] */

        /* Point to the memory owned by this device */
        desc.pntr = &dev_inst_ptr->memlist->payload;
        dev_inst_ptr->state = DEVSTATE_CFG_READ;
        status = _usb_host_ch9_set_configuration(dev_inst_ptr,
        desc.cfig->bConfigurationValue);

        if (status != USB_STATUS_TRANSFER_QUEUED)
        {
            dev_inst_ptr->state = DEVSTATE_INITIAL;
            break;
        }

        break;
    case DEVSTATE_CFG_READ:     /* full config desc. read in */
        dev_inst_ptr->state = DEVSTATE_APP_CALL;

        /* Scan the configuration descriptor to find out the total
        ** number of interfaces available. This will be the upper
        ** bound for searching through the interface descriptors'
        ** array
        */
        dev_inst_ptr->num_of_interfaces = 0;

        /* Point to the memory owned by this device */
        desc.pntr = &dev_inst_ptr->memlist->payload;
        /* We will always start with config desc so update the search pointer */
        config_size = utoh16(desc.cfig->wTotalLength);
        config_size -= desc.cfig->bLength;
        desc.word += desc.cfig->bLength;

        while (config_size) {
            if (desc.intf->bDescriptorType == USB_DESC_TYPE_IF) {
                /* Found an interface */
                dev_inst_ptr->num_of_interfaces++;
            } /* Endif */
            /* EAI - if desc.intf->bLength this while loop never exits!!!! */
            if (desc.intf->bLength) {
                config_size -= desc.intf->bLength;
                desc.word += desc.intf->bLength;
            } else {
                /* Not sure what proper error recovery is yet. */
                break;
            }
        }

        /* Don't select an interface here. The device driver will
        ** select the interface
        */

    case DEVSTATE_APP_CALL:     /* full config desc. read in */
        dev_inst_ptr->state = DEVSTATE_SET_INTF;
        if (dev_inst_ptr->new_config != 0) {
            /* We have just read a new configuration descriptor */
            dev_inst_ptr->new_config = 0;
            usb_hostdev_attach_detach(dev_inst_ptr, USB_CONFIG_EVENT);
        } else {
            usb_hostdev_attach_detach(dev_inst_ptr, USB_ATTACH_EVENT);
        }
        break;

    case DEVSTATE_SET_INTF:    /* Select interface done */
        dev_inst_ptr->state = DEVSTATE_ENUM_OK;
        usb_hostdev_attach_detach(dev_inst_ptr, USB_INTF_EVENT);
        break;
    default:
        dev_inst_ptr->state = DEVSTATE_ENUM_OK;
    case DEVSTATE_ENUM_OK:   /* enumeration complete */
        if ((dev_inst_ptr->control_callback != NULL))
        dev_inst_ptr->control_callback
        (handle,
        user_parm,
        buffer,
        length,
        status);
        break;
    }

}
/*
** ===================================================================
**     Method      :  _usb_host_register_ch9_callback (component USB_HOST_STACK)
**     Description :
**         This function registers a callback function that will be
**         called  to notify the user of a ch9 command completion. This
**         should be used  only after enumeration is completed
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         callback        - Callback upon completion
**       * callback_param  - User provided
**                           callback param
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_register_ch9_callback(_usb_device_instance_handle dev_handle, tr_callback callback, void* callback_param)
{
    /* Body */
    DEV_INSTANCE_PTR           dev_inst_ptr;
    USB_STATUS                 error;

    /* Verify that device handle is valid */
    USB_lock();
    error = usb_hostdev_validate(dev_handle);

    if (error != USB_OK) {
        USB_unlock();
        return USBERR_DEVICE_NOT_FOUND;
    } /* Endif */

    dev_inst_ptr = (DEV_INSTANCE_PTR)dev_handle;

    /* This will be called if the device is already enumerated */
    dev_inst_ptr->control_callback = callback;
    dev_inst_ptr->control_callback_param = callback_param;

    USB_unlock();
    return USB_OK;
}


/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : usb_host_ch9_dev_req
* Returned Value : USB_OK, or error status
* Comments       :
*     Function to process standard device requests in Chapter 9.
*        See Table 9-3 p. 250 of USB 2.0 specification.
*     This code does minimal error checking, on the assumption
*        that it is called only from wrappers in this file.
*     It is presumed that this function is called with USB interrupts disabled
*
*END*--------------------------------------------------------------------*/
static USB_STATUS  usb_host_ch9_dev_req
(
/* usb device */
_usb_device_instance_handle   dev_handle,

/* Device Request to send */
USB_SETUP_PTR                 devreq_ptr,

/* buffer to send/receive */
uchar_ptr                     buff_ptr
)
{

    DEV_INSTANCE_PTR           dev_ptr;
    _usb_pipe_handle           pipe_handle;
    TR_INIT_PARAM_STRUCT       tr;
    USB_STATUS                 error;


    /* Verify that device handle is valid */
    error = usb_hostdev_validate(dev_handle);

    if (error != USB_OK)
    {

        return USBERR_DEVICE_NOT_FOUND;
    } /* Endif */

    dev_ptr = (DEV_INSTANCE_PTR)dev_handle;
    pipe_handle = dev_ptr->control_pipe;

    /* Initialize the TR with TR index and default control callback
** function if there is one registered
*/
    usb_hostdev_tr_init(&tr, dev_ptr->control_callback,
    dev_ptr->control_callback_param);

    /* Set buffer length if required */
    switch (devreq_ptr->BREQUEST) {
    case REQ_SET_DESCRIPTOR:
        tr.TX_BUFFER = buff_ptr;
        tr.TX_LENGTH = utoh16(devreq_ptr->WLENGTH);
        break;
    case REQ_GET_CONFIGURATION:
    case REQ_GET_DESCRIPTOR:
    case REQ_GET_INTERFACE:
    case REQ_GET_STATUS:
    case REQ_SYNCH_FRAME:
        tr.RX_BUFFER = buff_ptr;
        tr.RX_LENGTH = utoh16(devreq_ptr->WLENGTH);
        break;
    }

    tr.DEV_REQ_PTR = (uchar_ptr)(devreq_ptr);

    if ((dev_ptr->state < DEVSTATE_ENUM_OK) ||
            (tr.CALLBACK == NULL))
    {
        tr.CALLBACK = usb_host_cntrl_transaction_done;
        tr.CALLBACK_PARAM = NULL;
    }
    error = _usb_host_send_setup(dev_ptr->host, pipe_handle, &tr);

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_clear_feature (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         req_type        - request type
**                           device/interface/endpoint
**         intf_endpt      - device = 0, or
**                           interface/endpoint
**         feature         - feature selection
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_clear_feature(_usb_device_instance_handle dev_handle, uint_8 req_type, uint_8 intf_endpt, uint_16 feature)
{
    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();

    switch (req_type) {
    case REQ_TYPE_DEVICE:
        break;
    case REQ_TYPE_INTERFACE:
    case REQ_TYPE_ENDPOINT:
        htou16(request.WINDEX, intf_endpt);
        break;
    default:
        USB_unlock();
        return USBERR_INVALID_BMREQ_TYPE;
    }

    request.BMREQUESTTYPE = (uchar)(req_type | REQ_TYPE_OUT);
    request.BREQUEST = REQ_CLEAR_FEATURE;
    htou16(request.WVALUE, feature);

    error = usb_host_ch9_dev_req(dev_handle, &request, NULL);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_get_configuration (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - [IN] usb device
**         buffer          - [OUT] configuration value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_get_configuration(_usb_device_instance_handle dev_handle, uchar_ptr buffer)
{
    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();

    request.BMREQUESTTYPE = REQ_TYPE_DEVICE | REQ_TYPE_IN;
    request.BREQUEST = REQ_GET_CONFIGURATION;
    htou16(request.WLENGTH, 1);

    error = usb_host_ch9_dev_req(dev_handle, &request, buffer);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_get_descriptor (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         type_index      - descriptor type & index
**         lang_id         - Language ID or 0
**         buflen          - buffer length
**         buffer          - descriptor buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_get_descriptor(_usb_device_instance_handle dev_handle, uint_16 type_index, uint_16 lang_id, uint_16 buflen, uchar_ptr buffer)
{

    USB_SETUP  request;
    USB_STATUS error = USB_OK;

    USB_lock();

    request.BMREQUESTTYPE = REQ_TYPE_DEVICE | REQ_TYPE_IN;
    request.BREQUEST = REQ_GET_DESCRIPTOR;
    htou16(request.WVALUE, type_index);
    htou16(request.WINDEX, lang_id);
    htou16(request.WLENGTH, buflen);

    error = usb_host_ch9_dev_req(dev_handle, &request, buffer);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_get_interface (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         interface       - interface index
**         buffer          - alternate setting buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_get_interface(_usb_device_instance_handle dev_handle, uint_8 interface, uchar_ptr buffer)
{

    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();

    request.BMREQUESTTYPE = REQ_TYPE_INTERFACE | REQ_TYPE_IN;
    request.BREQUEST = REQ_GET_INTERFACE;
    htou16(request.WINDEX, interface);
    htou16(request.WLENGTH, 1);

    error = usb_host_ch9_dev_req(dev_handle, &request, buffer);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_get_status (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         req_type        - request type
**                           device/interface/endpoint
**         intf_endpt      - device = 0, or
**                           interface/endpoint
**         buffer          - returned status
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_get_status(_usb_device_instance_handle dev_handle, uint_8 req_type, uint_8 intf_endpt, uchar_ptr buffer)
{
    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();

    switch (req_type) {
    case REQ_TYPE_DEVICE:
    case REQ_TYPE_INTERFACE:
    case REQ_TYPE_ENDPOINT:
        break;
    default:
        USB_unlock();
        return USBERR_INVALID_BMREQ_TYPE;
    } /* EndSwitch */

    request.BMREQUESTTYPE = (uchar)(req_type | REQ_TYPE_IN);
    request.BREQUEST = REQ_GET_STATUS;
    htou16(request.WINDEX, intf_endpt);
    htou16(request.WLENGTH, 2);

    error = usb_host_ch9_dev_req(dev_handle, &request, buffer);
    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_set_address (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_set_address(_usb_device_instance_handle dev_handle)
{
    DEV_INSTANCE_PTR  dev_ptr = (DEV_INSTANCE_PTR)dev_handle;
    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();

    request.BMREQUESTTYPE = REQ_TYPE_DEVICE | REQ_TYPE_OUT;
    request.BREQUEST = REQ_SET_ADDRESS;
    htou16(request.WVALUE, dev_ptr->address);

    error = usb_host_ch9_dev_req(dev_handle, &request, NULL);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  usb_host__usb_host_ch9_set_configuration (component USB_HOST_STACK)
**
**     Description :
**         Function to process standard device request in Chapter 9. See 
**         Table 9-3 p. 250 of USB 2.0 specification.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
USB_STATUS _usb_host_ch9_set_configuration(_usb_device_instance_handle dev_handle, uint_16 config)
{
    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();

    request.BMREQUESTTYPE = REQ_TYPE_DEVICE | REQ_TYPE_OUT;
    request.BREQUEST = REQ_SET_CONFIGURATION;
    htou16(request.WVALUE, config);

    error = usb_host_ch9_dev_req(dev_handle, &request, NULL);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_set_descriptor (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         type_index      - descriptor type & index
**         lang_id         - Language ID or 0
**         buflen          - buffer length
**         buffer          - descriptor buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_set_descriptor(_usb_device_instance_handle dev_handle, uint_16 type_index, uint_16 lang_id, uint_16 buflen, uchar_ptr buffer)
{
    USB_SETUP  request;
    USB_STATUS error = USB_OK;

    USB_lock();

    request.BMREQUESTTYPE = REQ_TYPE_DEVICE | REQ_TYPE_OUT;
    request.BREQUEST = REQ_SET_DESCRIPTOR;
    htou16(request.WVALUE, type_index);
    htou16(request.WINDEX, lang_id);
    htou16(request.WLENGTH, buflen);

    error = usb_host_ch9_dev_req(dev_handle, &request, buffer);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  usb_host__usb_host_ch9_set_feature (component USB_HOST_STACK)
**
**     Description :
**         Function to process standard device request in Chapter 9. See 
**         Table 9-3 p. 250 of USB 2.0 specification.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
USB_STATUS _usb_host_ch9_set_feature(_usb_device_instance_handle dev_handle, uint_8 req_type, uint_8 intf_endpt, uint_16 feature)
{
    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();
    switch (req_type) {
    case REQ_TYPE_DEVICE:
        break;
    case REQ_TYPE_INTERFACE:
    case REQ_TYPE_ENDPOINT:
        htou16(request.WINDEX, intf_endpt);
        break;
    default:
        USB_unlock();
        return USBERR_INVALID_BMREQ_TYPE;
    }

    request.BMREQUESTTYPE = (uchar)(req_type | REQ_TYPE_OUT);
    request.BREQUEST = REQ_SET_FEATURE;
    htou16(request.WVALUE, feature);

    error = usb_host_ch9_dev_req(dev_handle, &request, NULL);

    USB_unlock();
    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_set_interface (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         alternate       - alternate setting
**         intf            - interface
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_set_interface(_usb_device_instance_handle dev_handle, uint_8 alternate, uint_8 intf)
{
    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();

    request.BMREQUESTTYPE = REQ_TYPE_INTERFACE | REQ_TYPE_OUT;
    request.BREQUEST = REQ_SET_INTERFACE;
    htou16(request.WVALUE, alternate);
    htou16(request.WINDEX, intf);

    error = usb_host_ch9_dev_req(dev_handle, &request, NULL);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_host_ch9_synch_frame (component USB_HOST_STACK)
**     Description :
**         Function to process standard device request in Chapter 9.
**         See Table 9-3 p. 250 of USB 2.0 specification.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         intf            - interface index
**         buffer          - configuration buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_ch9_synch_frame(_usb_device_instance_handle dev_handle, uint_8 intf, uchar_ptr buffer)
{
    USB_SETUP  request = req_prototype;
    USB_STATUS error = USB_OK;

    USB_lock();

    request.BMREQUESTTYPE = REQ_TYPE_ENDPOINT | REQ_TYPE_IN;
    request.BREQUEST = REQ_SYNCH_FRAME;
    htou16(request.WINDEX, intf);
    htou16(request.WLENGTH, 2);

    error = usb_host_ch9_dev_req(dev_handle, &request, buffer);

    USB_unlock();

    return error;
}

/*
** ===================================================================
**     Method      :  _usb_hostdev_cntrl_request (component USB_HOST_STACK)
**     Description :
**         Function to process class- or vendor-specific control pipe
**         device requests.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - usb device
**         devreq          - Device Request to send
**         buff_ptr        - buffer to send/receive
**         callback        - callback upon completion
**       * callback_param  - [IN] the parameter
**                           to pass back to the callback function
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_hostdev_cntrl_request(_usb_device_instance_handle dev_handle, USB_SETUP_PTR devreq, uchar_ptr buff_ptr, tr_callback callback, void* callback_param)
{
    /* Body */

    DEV_INSTANCE_PTR           dev_ptr;
    _usb_pipe_handle           pipe_handle;
    TR_INIT_PARAM_STRUCT       tr;
    USB_STATUS                 error = USB_OK;

    /* Verify that device handle is valid */
    USB_lock();
    error = usb_hostdev_validate(dev_handle);

    if (error != USB_OK) {
        USB_unlock();
        return USBERR_DEVICE_NOT_FOUND;
    } /* Endif */


    dev_ptr = (DEV_INSTANCE_PTR)dev_handle;
    if (dev_ptr->state < DEVSTATE_ENUM_OK) {
        USB_unlock();
        return USBERR_DEVICE_NOT_FOUND;
    } /* Endif */

    pipe_handle = dev_ptr->control_pipe;

    usb_hostdev_tr_init(&tr, callback, callback_param);

    /* Set TR buffer length as required */
    if ((REQ_TYPE_IN & devreq->BMREQUESTTYPE) != 0) {
        tr.RX_BUFFER = buff_ptr;
        tr.RX_LENGTH = utoh16(devreq->WLENGTH);
    } else {
        tr.TX_BUFFER = buff_ptr;
        tr.TX_LENGTH = utoh16(devreq->WLENGTH);
    } /* EndIf */

    tr.DEV_REQ_PTR = (uchar_ptr)devreq;
    error = _usb_host_send_setup(dev_ptr->host, pipe_handle, &tr);

    USB_unlock();

    return error;
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
