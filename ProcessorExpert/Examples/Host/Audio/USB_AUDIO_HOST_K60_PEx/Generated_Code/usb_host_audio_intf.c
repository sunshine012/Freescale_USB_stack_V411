/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_host_audio_intf.c
**     Project   : ProcessorExpert
**     Processor : MK60N512LQ100
**     Component : USB_AUDIO_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#include "hostapi.h"
#include "usb_host_audio.h"

static pointer                         audio_control_anchor;
static pointer                         audio_stream_anchor;
/*
** ===================================================================
**     Method      :  usb_host_audio_usb_class_audio_control_init (component USB_AUDIO_CLASS)
**
**     Description :
**         This function is called by common class to initialize the
**         class driver for audio control interface. It is called in
**         response to a select interface call by application.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pbs_ptr         - [IN]  structure with USB pipe
**                           information on the interface
**         ccs_ptr         -  [IN] audio call struct pointer
**     Returns     : Nothing
** ===================================================================
*/
void usb_class_audio_control_init(PIPE_BUNDLE_STRUCT_PTR pbs_ptr, CLASS_CALL_STRUCT_PTR ccs_ptr)
{
    /* Body */
    AUDIO_CONTROL_INTERFACE_STRUCT_PTR if_ptr = ccs_ptr->class_intf_handle;
    USB_STATUS                    status;

    /* Make sure the device is still attached */
    USB_lock();
    status = usb_host_class_intf_init(pbs_ptr, if_ptr, &audio_control_anchor);
    if (status == USB_OK)
    {
        /*
        ** We generate a code_key based on the attached device. This is used to
        ** verify that the device has not been detached and replaced with another.
        */
        ccs_ptr->code_key = 0;
        ccs_ptr->code_key = usb_host_class_intf_validate(ccs_ptr);

        if_ptr->AUDIO_G.IFNUM = ((INTERFACE_DESCRIPTOR_PTR)if_ptr->AUDIO_G.G.intf_handle)->bInterfaceNumber;
        if_ptr->interrupt_pipe = usb_hostdev_get_pipe_handle(pbs_ptr, USB_INTERRUPT_PIPE, 0);

        if (USB_OK != (status = _usb_event_init(&if_ptr->control_event)))
        {
            status = USBERR_INIT_FAILED;
        }
        else
        {
            /* pre-set events */
            _usb_event_set(&if_ptr->control_event, USB_AUDIO_CTRL_PIPE_FREE | USB_AUDIO_CTRL_INT_PIPE_FREE);
        }
    } /* Endif */

    /* Signal that an error has occured by setting the "code_key" */
    if (status) {
        ccs_ptr->code_key = 0;
    } /* Endif */
    USB_unlock();
}

/*
** ===================================================================
**     Method      :  usb_host_audio_usb_class_audio_stream_init (component USB_AUDIO_CLASS)
**
**     Description :
**         This function is called by common class to initialize the
**         class driver for audio stream interface. It is called in
**         response to a select interface call by application.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pbs_ptr         - [IN]  structure with USB pipe
**                           information on the interface
**         ccs_ptr         - [IN] stream call struct pointer
**     Returns     : Nothing
** ===================================================================
*/
void usb_class_audio_stream_init(PIPE_BUNDLE_STRUCT_PTR pbs_ptr, CLASS_CALL_STRUCT_PTR ccs_ptr)
{
    /* Body */
    AUDIO_STREAM_INTERFACE_STRUCT_PTR if_ptr = ccs_ptr->class_intf_handle;
    USB_STATUS                     status;

    /* Make sure the device is still attached */
    USB_lock();
    status = usb_host_class_intf_init(pbs_ptr, if_ptr, &audio_stream_anchor);
    if (status == USB_OK)
    {

        /* Check the audio stream interface alternating 1 */
        if (0 != (((INTERFACE_DESCRIPTOR_PTR)if_ptr->AUDIO_G.G.intf_handle)->bNumEndpoints))
        {
            /*
            ** We generate a code_key based on the attached device. This is used to
            ** verify that the device has not been detached and replaced with another.
            */
            ccs_ptr->code_key = 0;
            ccs_ptr->code_key = usb_host_class_intf_validate(ccs_ptr);

            if_ptr->AUDIO_G.IFNUM = ((INTERFACE_DESCRIPTOR_PTR)if_ptr->AUDIO_G.G.intf_handle)->bInterfaceNumber;

            if_ptr->iso_in_pipe = usb_hostdev_get_pipe_handle(pbs_ptr, USB_ISOCHRONOUS_PIPE, USB_RECV);
            if_ptr->iso_out_pipe = usb_hostdev_get_pipe_handle(pbs_ptr, USB_ISOCHRONOUS_PIPE, USB_SEND);

            if ((if_ptr->iso_in_pipe == NULL) && (if_ptr->iso_out_pipe == NULL))
            status = USBERR_OPEN_PIPE_FAILED;

            else if (USB_OK != (status = _usb_event_init(&if_ptr->stream_event)))
            status = USBERR_INIT_FAILED;
            else
            {
                /* pre-set events */
                _usb_event_set(&if_ptr->stream_event, USB_DATA_READ_PIPE_FREE | USB_DATA_SEND_PIPE_FREE);
            }
        }
        else
        {
            status = USBERR_INIT_FAILED;
        }
    } /* Endif */

    /* Signal that an error has occured by setting the "code_key" */
    if (status)
    {
        ccs_ptr->code_key = 0;
    } /* Endif */
    USB_unlock();
}

/*
** ===================================================================
**     Method      :  usb_host_audio_usb_class_audio_get_ctrl_interface (component USB_AUDIO_CLASS)
**
**     Description :
**         This function is used to find registered control interface
**         in the chain. It must be run with interrupts disabled to
**         have interfaces validated.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * intf_handle     - [IN] pointer to interface
**                           handle
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
CLASS_CALL_STRUCT_PTR usb_class_audio_get_ctrl_interface(void* intf_handle)
{

    CLASS_CALL_STRUCT_PTR   control_parser;

    /* find this control interface in the list with interface descriptor */
    for (control_parser = audio_control_anchor; control_parser != NULL; control_parser = control_parser->next)
    if (usb_host_class_intf_validate(control_parser))
    if (((AUDIO_CONTROL_INTERFACE_STRUCT_PTR) control_parser->class_intf_handle)->AUDIO_G.G.intf_handle == intf_handle)
    break;

    return control_parser;
}

/*
** ===================================================================
**     Method      :  usb_host_audio_usb_class_audio_control_get_descriptors (component USB_AUDIO_CLASS)
**
**     Description :
**         This function is hunting for descriptors in the device
**         configuration and fills back fields if the descriptor was
**         found. Must be run in locked state and validated USB device
**         or directly from attach event.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - [IN] pointer to device
**                           instance
**         intf_handle     - [IN] pointer to interface
**                           descriptor
**       * header_desc     -  [OUT] pointer to header
**                           descriptor
**       * it_desc         - [OUT] pointer to input terminal
**                           descriptor
**       * ot_desc         - [OUT] pointer to output terminal
**                           descriptor
**       * fu_desc         - [OUT] pointer to feature unit
**                           descriptor
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_audio_control_get_descriptors(_usb_device_instance_handle dev_handle, _usb_interface_descriptor_handle intf_handle, USB_AUDIO_CTRL_DESC_HEADER_PTR *header_desc, USB_AUDIO_CTRL_DESC_IT_PTR *it_desc, USB_AUDIO_CTRL_DESC_OT_PTR *ot_desc, USB_AUDIO_CTRL_DESC_FU_PTR *fu_desc)
{

    INTERFACE_DESCRIPTOR_PTR   intf_ptr = (INTERFACE_DESCRIPTOR_PTR)intf_handle;
    USB_STATUS                 status;
    int_32 i;
    USB_AUDIO_CTRL_FUNC_DESC_PTR      fd;

    status = USB_OK;
    /* collect all interface functional descriptors */
    for (i = 0; ; i++)
    {
        if (USB_OK != _usb_hostdev_get_descriptor(
                    dev_handle,
                    intf_handle,
                    USB_DESC_TYPE_CS_INTERFACE,  /* Functional descriptor for interface */
                    (uint_8)i,                           /* Index of descriptor */
                    intf_ptr->bAlternateSetting, /* Index of interface alternate */
                    (pointer _PTR_) &fd))
        {
            /* Here we can check capabilities from functional descriptors */
            /* But for now, nothing is checked */
            if (fu_desc == NULL)
            status = USBERR_INIT_FAILED;
            break;
        }
        /* Check if this union descriptor describes master for this interface */
        switch (fd->header.bDescriptorSubtype)
        {
        case USB_DESC_SUBTYPE_CS_HEADER:
            *header_desc = &fd->header;
            if (utoh16(((*header_desc)->bcdCDC)) > 0x0110)
            status = USBERR_INIT_FAILED;
            break;
        case USB_DESC_SUBTYPE_CS_IT:
            *it_desc = &fd->it;
            break;
        case USB_DESC_SUBTYPE_CS_OT:
            *ot_desc = &fd->ot;
            break;
        case USB_DESC_SUBTYPE_CS_FU:
            *fu_desc = &fd->fu;
            break;
        }
        if (status != USB_OK)
        break;
    }

    return status;
}

/*
** ===================================================================
**     Method      :  usb_host_audio_usb_class_audio_stream_get_descriptors (component USB_AUDIO_CLASS)
**
**     Description :
**         This function is hunting for descriptors in the device
**         configuration and fills back fields if the descriptor was
**         found. Must be run in locked state and validated USB device
**         or directly from attach event.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - [IN] pointer to device
**                           instance
**         intf_handle     - [IN] pointer to interface
**                           descriptor
**       * as_itf_desc     - [OUT] pointer to specific
**                           audio stream interface descriptor
**       * frm_type_desc   - [OUT] pointer to
**                           format type descriptor
**       * iso_endp_spec_desc - [OUT]
**                           pointer to specific isochronous endpoint
**                           descriptor
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_audio_stream_get_descriptors(_usb_device_instance_handle dev_handle, _usb_interface_descriptor_handle intf_handle, USB_AUDIO_STREAM_DESC_SPEPIFIC_AS_IF_PTR *as_itf_desc, USB_AUDIO_STREAM_DESC_FORMAT_TYPE_PTR *frm_type_desc, USB_AUDIO_STREAM_DESC_SPECIFIC_ISO_ENDP_PTR *iso_endp_spec_desc)
{

    INTERFACE_DESCRIPTOR_PTR   intf_ptr =
    (INTERFACE_DESCRIPTOR_PTR)intf_handle;
    USB_STATUS                 status;
    int_32 i;
    USB_AUDIO_STREAM_FUNC_DESC_PTR      fd;

    status = USB_OK;
    /* collect all interface functional descriptors */
    for (i = 0; ; i++)
    {
        if (USB_OK != _usb_hostdev_get_descriptor(
                    dev_handle,
                    intf_handle,
                    USB_DESC_TYPE_CS_INTERFACE,  /* Functional descriptor for interface */
                    (uint_8)i,                           /* Index of descriptor */
                    intf_ptr->bAlternateSetting, /* Index of interface alternate */
                    (pointer _PTR_) &fd))
        {
            /* Here we can check capabilities from functional descriptors */
            /* But for now, nothing is checked */
            if (as_itf_desc == NULL)
            status = USBERR_INIT_FAILED;
            break;
        }
        /* Check if this union descriptor describes master for this interface */
        switch (fd->as_general.bDescriptorSubtype)
        {
        case USB_DESC_SUBTYPE_AS_CS_GENERAL:
            *as_itf_desc = &fd->as_general;
            break;
        case USB_DESC_SUBTYPE_AS_CS_FORMAT_TYPE:
            *frm_type_desc = &fd->frm_type;
            break;
        }
        if (status != USB_OK)
        break;
    }

    /* collect all interface functional descriptors */
    for (i = 0; ; i++) {
        if (USB_OK != _usb_hostdev_get_descriptor(
                    dev_handle,
                    intf_handle,
                    USB_DESC_TYPE_CS_ENDPOINT,  /* Functional descriptor for interface */
                    (uint_8)i,                           /* Index of descriptor */
                    intf_ptr->bAlternateSetting, /* Index of interface alternate */
                    (pointer _PTR_) &fd))
        {
            /* Here we can check capabilities from functional descriptors */
            /* But for now, nothing is checked */
            if (as_itf_desc == NULL)
            status = USBERR_INIT_FAILED;
            break;
        }
        /* Check if this union descriptor describes master for this interface */
        switch (fd->as_general.bDescriptorSubtype)
        {
        case USB_DESC_CLASS_ENDPOINT_GENERAL:
            *iso_endp_spec_desc = &fd->iso_endp_specific;
            break;
        default:
            break;
        }
        if (status != USB_OK)
        break;
    }

    return status;
}

/*
** ===================================================================
**     Method      :  usb_host_audio_usb_class_audio_control_set_descriptors (component USB_AUDIO_CLASS)
**
**     Description :
**         This function is used to set descriptors for control
**         interface.  Descriptors can be used afterwards by
**         application or by driver
**     Parameters  :
**         NAME            - DESCRIPTION
**         ccs_ptr         - [IN] class call struct pointer 
**         header_desc     - [IN] header descriptor
**                           pointer
**         it_desc         - [IN] input terminal descriptor
**                           pointer
**         ot_desc         - [IN] output terminal descriptor
**                           pointer
**         fu_desc         - [IN] feature unit descriptor
**                           pointer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_audio_control_set_descriptors(CLASS_CALL_STRUCT_PTR ccs_ptr, USB_AUDIO_CTRL_DESC_HEADER_PTR header_desc, USB_AUDIO_CTRL_DESC_IT_PTR it_desc, USB_AUDIO_CTRL_DESC_OT_PTR ot_desc, USB_AUDIO_CTRL_DESC_FU_PTR fu_desc)
{
    /* Body */
    AUDIO_CONTROL_INTERFACE_STRUCT_PTR if_ptr;
    USB_STATUS                    status = USBERR_NO_INTERFACE;

    /* Make sure the device is still attached */
    USB_lock();

    /* Validity checking */
    if (usb_host_class_intf_validate(ccs_ptr))
    {
        if_ptr = (AUDIO_CONTROL_INTERFACE_STRUCT_PTR)ccs_ptr->class_intf_handle;
        if_ptr->header_desc = header_desc;
        if_ptr->it_desc = it_desc;
        if_ptr->ot_desc = ot_desc;
        if_ptr->fu_desc = fu_desc;
    } /* Endif */
    USB_unlock();

    return status;
}

/*
** ===================================================================
**     Method      :  usb_host_audio_usb_class_audio_stream_set_descriptors (component USB_AUDIO_CLASS)
**
**     Description :
**         This function is used to set descriptors for stream
**         interface Descriptors can be used afterwards by application
**         or by driver
**     Parameters  :
**         NAME            - DESCRIPTION
**         ccs_ptr         - [IN] class call struct pointer
**         as_itf_desc     - [IN] audio stream
**                           interface descriptor pointer
**         frm_type_desc   - [IN] format type
**                           descriptor pointer
**         iso_endp_spec_desc - [IN]
**                           isochonous endpoint specific descriptor
**                           pointer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_audio_stream_set_descriptors(CLASS_CALL_STRUCT_PTR ccs_ptr, USB_AUDIO_STREAM_DESC_SPEPIFIC_AS_IF_PTR as_itf_desc, USB_AUDIO_STREAM_DESC_FORMAT_TYPE_PTR frm_type_desc, USB_AUDIO_STREAM_DESC_SPECIFIC_ISO_ENDP_PTR iso_endp_spec_desc)
{
    /* Body */
    AUDIO_STREAM_INTERFACE_STRUCT_PTR if_ptr;
    USB_STATUS                    status = USBERR_NO_INTERFACE;

    /* Make sure the device is still attached */
    USB_lock();

    /* Validity checking */
    if (usb_host_class_intf_validate(ccs_ptr))
    {
        if_ptr = (AUDIO_STREAM_INTERFACE_STRUCT_PTR)ccs_ptr->class_intf_handle;

        if_ptr->as_itf_desc                 = as_itf_desc;
        if_ptr->frm_type_desc                 = frm_type_desc;
        if_ptr->iso_endp_spec_desc         = iso_endp_spec_desc;
    } /* Endif */
    USB_unlock();

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
