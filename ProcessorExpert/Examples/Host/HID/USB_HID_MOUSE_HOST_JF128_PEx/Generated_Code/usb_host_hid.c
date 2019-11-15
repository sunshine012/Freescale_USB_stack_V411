/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : usb_host_hid.c
**     Project     : ProcessorExpert
**     Processor   : MCF51JF128VLH
**     Component   : USB_HID_CLASS
**     Version     : Component 01.027, Driver 01.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2012-11-19, 12:26, # CodeGen: 27
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         usb_class_host_hid_init         - void usb_host_hid_usb_class_host_hid_init(PIPE_BUNDLE_STRUCT_PTR *pbs_ptr,...
**         usb_class_host_hid_get_report   - USB_STATUS usb_host_hid_usb_class_host_hid_get_report(HID_COMMAND_PTR...
**         usb_class_host_hid_set_report   - USB_STATUS usb_host_hid_usb_class_host_hid_set_report(HID_COMMAND_PTR...
**         usb_class_host_hid_get_idle     - USB_STATUS usb_host_hid_usb_class_host_hid_get_idle(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_set_idle     - USB_STATUS usb_host_hid_usb_class_host_hid_set_idle(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_get_protocol - USB_STATUS usb_host_hid_usb_class_host_hid_get_protocol(HID_COMMAND_PTR...
**         usb_class_host_hid_set_protocol - USB_STATUS usb_host_hid_usb_class_host_hid_set_protocol(HID_COMMAND_PTR...
**
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#include "usb_host_hid.h"

/****************************************************************************
 * Global Variables
 ****************************************************************************/
/****************************************************************************
 * Local Variables
 ****************************************************************************/
static USB_HID_CLASS_INTF_STRUCT_PTR hid_anchor = NULL;

/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_init (component USB_HID_CLASS)
**
**     Description :
**         This function is called by common class to initialize the
**         class driver. It is called in response to a select interface
**         call by application
**     Parameters  :
**         NAME            - DESCRIPTION
**       * pbs_ptr         - Pointer to [IN]  structure with
**                           USB pipe information on the interface
**       * ccs_ptr         - Pointer to [IN] printer call
**                           struct pointer
**     Returns     : Nothing
** ===================================================================
*/
void usb_class_host_hid_init(
    /* [IN]  structure with USB pipe information on the interface */
    PIPE_BUNDLE_STRUCT_PTR pbs_ptr,

    /* [IN] printer call struct pointer */
    CLASS_CALL_STRUCT_PTR ccs_ptr
)
{
   USB_HID_CLASS_INTF_STRUCT_PTR if_ptr = ccs_ptr->class_intf_handle;
   USB_STATUS                    status;

   /* Make sure the device is still attached */
   USB_lock();
   status = usb_host_class_intf_init(pbs_ptr, if_ptr, &hid_anchor);
   if (status == USB_OK) {
      /*
      ** We generate a code_key based on the attached device. This is used to
      ** verify that the device has not been detached and replaced with another.
      */
      ccs_ptr->code_key = 0;
      ccs_ptr->code_key = usb_host_class_intf_validate(ccs_ptr);
   }
   USB_unlock();
}

/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_cntrl_callback (component USB_HID_CLASS)
**
**     Description :
**         This is the callback used when HID information is sent or 
**         received
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void usb_class_host_hid_cntrl_callback(
    /* [IN] Unused */
    pointer pipe,
    /* [IN] Pointer to the class interface instance */
    pointer param,
    /* [IN] Data buffer */
    uchar_ptr buffer,
    /* [IN] Length of buffer */
    uint_32 len,
    /* [IN] Error code (if any) */
    USB_STATUS status
)
{
   USB_HID_CLASS_INTF_STRUCT_PTR      if_ptr;

   /*
   ** There is need for USB_lock in the callback function, and there is also no
   ** need to check if the device is still attached (otherwise this callback
   ** would never have been called!
   */
   /* Get class interface handle, reset IN_SETUP and call callback */
   if_ptr = (USB_HID_CLASS_INTF_STRUCT_PTR)param;

   if_ptr->IN_SETUP = FALSE;

   if (if_ptr->USER_CALLBACK) {
      if_ptr->USER_CALLBACK(pipe, if_ptr->USER_PARAM, buffer, len, status);
   } /* Endif */
}
/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_cntrl_common (component USB_HID_CLASS)
**
**     Description :
**         This function is used to send a control request
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
USB_STATUS usb_class_host_hid_cntrl_common(
    /* [IN] The communication device common command structure */
    HID_COMMAND_PTR com_ptr,
    /* [IN] Bitmask of the request type */
    uint_8 bmrequesttype,
    /* [IN] Request code */
    uint_8 brequest,
    /* [IN] Value to copy into WVALUE field of the REQUEST */
    uint_16 wvalue,
    /* [IN] Length of the data associated with REQUEST */
    uint_16 wlength,
    /* [IN] Pointer to data buffer used to send/recv */
    uchar_ptr data
)
{
   USB_HID_CLASS_INTF_STRUCT_PTR    if_ptr;
   USB_SETUP                        req;
   USB_STATUS                       status = USBERR_NO_INTERFACE;

   USB_lock();
   /* Validity checking */
   if (usb_host_class_intf_validate(com_ptr->CLASS_PTR)) {
      if_ptr =
         (USB_HID_CLASS_INTF_STRUCT_PTR)com_ptr->CLASS_PTR->class_intf_handle;
      status = usb_hostdev_validate(if_ptr->G.dev_handle);
   } /* Endif */

   if (!status && if_ptr->IN_SETUP) {
      status = USBERR_TRANSFER_IN_PROGRESS;
   } /* Endif */

   if (!status) {
      /* Save the higher level callback and ID */
      if_ptr->USER_CALLBACK = com_ptr->CALLBACK_FN;
      if_ptr->USER_PARAM = com_ptr->CALLBACK_PARAM;

      /* Setup the request */
      req.BMREQUESTTYPE = bmrequesttype;
      req.BREQUEST = brequest;
      htou16(req.WVALUE, wvalue);
      htou16(req.WINDEX, ((INTERFACE_DESCRIPTOR_PTR)if_ptr->G.intf_handle)->bInterfaceNumber);
      htou16(req.WLENGTH, wlength);
      status = _usb_hostdev_cntrl_request(if_ptr->G.dev_handle, &req, data,
         usb_class_host_hid_cntrl_callback, if_ptr);
      if (status == USB_STATUS_TRANSFER_QUEUED) {
         if_ptr->IN_SETUP = TRUE;
      } /* Endif */
   } /* Endif */
   USB_unlock();
   return status;
}

/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_get_report (component USB_HID_CLASS)
**
**     Description :
**         This function is called by the application to get a report
**         from the HID device
**     Parameters  :
**         NAME            - DESCRIPTION
**       * com_ptr         - Pointer to [IN] Class Interface
**                           structure pointer
**         rid             - [IN] Report ID (see HID specification)
**         rtype           - [IN] Report type (see HID
**                           specification)
**       * buf             - Pointer to [IN] Buffer to receive report
**                           data
**         blen            - [IN] length of the Buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_host_hid_get_report(
    /* [IN] Class Interface structure pointer */
    HID_COMMAND_PTR com_ptr,
    /* [IN] Report ID (see HID specification) */
    uint_8 rid,
    /* [IN] Report type (see HID specification) */
    uint_8 rtype,
    /* [IN] Buffer to receive report data */
    pointer buf,
    /* [IN] length of the Buffer */
    uint_16 blen
)
{
   return usb_class_host_hid_cntrl_common(com_ptr,
      REQ_TYPE_IN | REQ_TYPE_CLASS | REQ_TYPE_INTERFACE,
      GET_REPORT, (uint_16)((rtype << 8) | rid), blen, buf);
}

/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_set_report (component USB_HID_CLASS)
**
**     Description :
**         This function is called by the application to send a report
**         to the HID device
**     Parameters  :
**         NAME            - DESCRIPTION
**       * com_ptr         - [IN] Class Interface structure
**                           pointer
**         rid             - [IN] Report ID (see HID specification)
**         rtype           - [IN] Report type (see HID
**                           specification)
**       * buf             - Pointer to [IN] Buffer to receive report
**                           data
**         blen            - [IN] length of the Buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_host_hid_set_report(
    /* [IN] Class Interface structure pointer */
    HID_COMMAND_PTR com_ptr,
    /* [IN] Report ID (see HID specification) */
    uint_8 rid,
    /* [IN] Report type (see HID specification) */
    uint_8 rtype,
    /* [IN] Buffer to receive report data */
    pointer buf,
    /* [IN] length of the Buffer */
    uint_16 blen
)
{
   return usb_class_host_hid_cntrl_common(com_ptr,
      REQ_TYPE_OUT | REQ_TYPE_CLASS | REQ_TYPE_INTERFACE,
      SET_REPORT, (uint_16)((rtype << 8) | rid), blen, buf);
}

/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_get_idle (component USB_HID_CLASS)
**
**     Description :
**         This function is called by the application to read the idle
**         rate of a particular HID device report
**     Parameters  :
**         NAME            - DESCRIPTION
**       * com_ptr         - [IN] Class Interface structure
**                           pointer
**         rid             - [IN] Report ID (see HID specification)
**       * idle_rate       - Pointer to [OUT] idle rate of
**                           this report
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_host_hid_get_idle(
    /* [IN] Class Interface structure pointer */
    HID_COMMAND_PTR com_ptr,
    /* [IN] Report ID (see HID specification) */
    uint_8 rid,
    /* [OUT] idle rate of this report */
    uint_8_ptr idle_rate
)
{
   return usb_class_host_hid_cntrl_common(com_ptr,
      REQ_TYPE_IN | REQ_TYPE_CLASS | REQ_TYPE_INTERFACE,
      GET_IDLE, rid, 1, idle_rate);
}

/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_set_idle (component USB_HID_CLASS)
**
**     Description :
**         This function is called by the application to silence a
**         particular report on interrupt In pipe until a new event
**         occurs or specified  time elapses
**     Parameters  :
**         NAME            - DESCRIPTION
**       * com_ptr         - [IN] Class Interface structure
**                           pointer
**         rid             - [IN] Report ID (see HID specification)
**         duration        - [IN] Idle rate
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_host_hid_set_idle(
    /* [IN] Class Interface structure pointer */
    HID_COMMAND_PTR com_ptr,
    /* [IN] Report ID (see HID specification) */
    uint_8 rid,
    /* [IN] Idle rate */
    uint_8 duration
)
{
    return usb_class_host_hid_cntrl_common(com_ptr,
      REQ_TYPE_OUT | REQ_TYPE_CLASS | REQ_TYPE_INTERFACE,
      SET_IDLE, (uint_16)((duration << 8) | rid), 0, NULL);
}

/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_get_protocol (component USB_HID_CLASS)
**
**     Description :
**         Reads the active protocol (boot protocol or report protocol)
**     Parameters  :
**         NAME            - DESCRIPTION
**       * com_ptr         - [IN] Class Interface structure
**                           pointer
**       * protocol        - Pointer to [IN] Protocol (1 byte,
**                           0 = Boot Protocol or 1 = Report Protocol
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_host_hid_get_protocol(
    /* [IN] Class Interface structure pointer */
    HID_COMMAND_PTR com_ptr,
    /* [IN] Protocol (1 byte, 0 = Boot Protocol or 1 = Report Protocol */
    uint_8_ptr protocol
)
{
   return usb_class_host_hid_cntrl_common(com_ptr,
      REQ_TYPE_IN | REQ_TYPE_CLASS | REQ_TYPE_INTERFACE,
      GET_PROTOCOL, 0, 1, protocol);
}

/*
** ===================================================================
**     Method      :  usb_host_hid_usb_class_host_hid_set_protocol (component USB_HID_CLASS)
**
**     Description :
**         Switches between the boot protocol and the report protocol
**         (or vice versa)
**     Parameters  :
**         NAME            - DESCRIPTION
**       * com_ptr         - [IN] Class Interface structure
**                           pointer
**         protocol        - [IN] Protocol (1 byte, 0 = Boot
**                           Protocol or 1 = Report Protocol
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS usb_class_host_hid_set_protocol(
    /* [IN] Class Interface structure pointer */
    HID_COMMAND_PTR com_ptr,
    /* [IN] The protocol (0 = Boot, 1 = Report) */
    uint_8 protocol
)
{
   return usb_class_host_hid_cntrl_common(com_ptr,
      REQ_TYPE_OUT | REQ_TYPE_CLASS | REQ_TYPE_INTERFACE,
      SET_PROTOCOL, protocol, 0, NULL);
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
