/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_snd.c
**     Project   : ProcessorExpert
**     Processor : MK60FN1M0LQ15
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 11:55, # CodeGen: 25
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "hostapi.h"
#include "usbprv_host.h"
#include "host_snd.h"
#include "khci.h"
/*
** ===================================================================
**     Method      :  _usb_host_get_frame_number (component USB_HOST_STACK)
**     Description :
**         This function can be used to inquire the current frame
**         number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         hci_handle      - [IN] the USB Host state
**                           structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_32 _usb_host_get_frame_number(_usb_host_handle hci_handle)
{
    /* Body */
    USB_HOST_STATE_STRUCT_PTR usb_host_ptr;
    usb_host_ptr = (USB_HOST_STATE_STRUCT_PTR)hci_handle;

    /* Call the low-level send routine */
    return((USB_HOST_CALLBACK_FUNCTIONS_STRUCT_PTR)usb_host_ptr->CALLBACK_STRUCT_PTR)->HOST_EHCI_GET_FRAME_NUM(hci_handle);
}
/*
** ===================================================================
**     Method      :  _usb_host_get_micro_frame_number (component USB_HOST_STACK)
**     Description :
**         This function can be used to inquire the current micro frame
**         number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         hci_handle      - [IN] USB Host controller
**                           handle
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_32 _usb_host_get_micro_frame_number(_usb_host_handle hci_handle)
{
    /* Body */
    USB_HOST_STATE_STRUCT_PTR usb_host_ptr;
    usb_host_ptr = (USB_HOST_STATE_STRUCT_PTR)hci_handle;

    /* Call the low-level send routine */
    return((USB_HOST_CALLBACK_FUNCTIONS_STRUCT_PTR)usb_host_ptr->CALLBACK_STRUCT_PTR)->HOST_EHCI_GET_MICRO_FRAME_NUM(hci_handle);
}

/*
** ===================================================================
**     Method      :  _usb_host_send_data (component USB_HOST_STACK)
**     Description :
**         The Send Data routine is non-blocking routine that causes a
**         block of data to be made available for transmission to the
**         USB host.
**     Parameters  :
**         NAME            - DESCRIPTION
**         hci_handle      - [IN] the USB Host state
**                           structure
**         pipe_handle     - [IN] the pipe handle
**         tr_params_ptr   - [IN] transfer
**                           parameters
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_32 _usb_host_send_data(_usb_host_handle hci_handle, _usb_pipe_handle pipe_handle, TR_INIT_PARAM_STRUCT_PTR tr_params_ptr)
{
    /* Body */
    PIPE_DESCRIPTOR_STRUCT_PTR pipe_descr_ptr;
    USB_HOST_STATE_STRUCT_PTR  usb_host_ptr;
    uint_32  return_code;

    PIPE_TR_STRUCT_PTR         pipe_tr_ptr;

    USB_lock();
    return_code = _usb_host_set_up_TR(pipe_handle, tr_params_ptr, &pipe_tr_ptr);
    if (return_code != USB_STATUS_TRANSFER_QUEUED) {
        USB_unlock();
        return return_code;
    } /* Endif */

    usb_host_ptr = (USB_HOST_STATE_STRUCT_PTR)hci_handle;
    pipe_descr_ptr = (PIPE_DESCRIPTOR_STRUCT_PTR)pipe_handle;

    /*Must Flush and Invalidate the buffer before sending
/receiving the data in it */
    USB_dcache_flush_mlines((void *)pipe_tr_ptr->TX_BUFFER, pipe_tr_ptr->TX_LENGTH);

    /* We have obtained the current TR on the Pipe's TR list
** from _usb_host_set_up_TR
*/
    /* Call the low-level send routine */
    return_code = _usb_host_send_call_interface (hci_handle, pipe_descr_ptr, pipe_tr_ptr);

    USB_unlock();

    if(return_code == USB_OK)
    {
        return USB_STATUS_TRANSFER_QUEUED;
    }
    else
    {
        return return_code;
    }
}
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
