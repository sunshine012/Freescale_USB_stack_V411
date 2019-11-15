/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_cnl.c
**     Project   : ProcessorExpert
**     Processor : MCF51JF128_64
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:54, # CodeGen: 19
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "hostapi.h"
#include "usbprv_host.h"
#include "host_cnl.h"

/*
** ===================================================================
**     Method      :  _usb_host_cancel_transfer (component USB_HOST_STACK)
**     Description :
**         _usb_host_cancel_transfer is a non-blocking routine that
**         causes a transfer to be terminated.
**     Parameters  :
**         NAME            - DESCRIPTION
**         hci_handle      - [IN] USB Host controller
**                           handle
**         pipe_handle     - [IN] Pipe handle
**         transfer_number - [IN] Specific
**                           transfer to cancel
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_cancel_transfer(_usb_host_handle hci_handle, _usb_pipe_handle pipe_handle, uint_32 transfer_number)
{
    USB_STATUS error;
    uint_32  bRet;
    PIPE_DESCRIPTOR_STRUCT_PTR pipe_descr_ptr;
    PIPE_TR_STRUCT_PTR         pipe_tr_ptr;
    USB_HOST_STATE_STRUCT_PTR usb_host_ptr;

    usb_host_ptr = (USB_HOST_STATE_STRUCT_PTR)hci_handle;

    pipe_descr_ptr = (PIPE_DESCRIPTOR_STRUCT_PTR)pipe_handle;

    USB_lock();

    /* Check if valid pipe id */

    if (pipe_descr_ptr->PIPE_ID > USBCFG_MAX_PIPES) {
        USB_unlock();
        return USBERR_INVALID_PIPE_HANDLE;
    }

    pipe_tr_ptr = pipe_descr_ptr->tr_list_ptr;
    while (pipe_tr_ptr->TR_INDEX != transfer_number)  {
        /* If unused TR found, or end of list, exit with bad status */
        if ((pipe_tr_ptr->TR_INDEX == 0) ||
                (pipe_tr_ptr->next == pipe_descr_ptr->tr_list_ptr))
        {
            USB_unlock();
            return USBERR_INVALID_PIPE_HANDLE;
        }
        pipe_tr_ptr = pipe_tr_ptr->next;
    }

    /* Get the current status */
    bRet = pipe_tr_ptr->status;

    /* Cancel the transfer at low-level */
    error = _usb_host_cancel_call_interface (hci_handle, pipe_descr_ptr, pipe_tr_ptr);

    if (error != USB_OK)
    {
        USB_unlock();
        return error;
    }

    /* Indicate that the pipe is idle */
    pipe_tr_ptr->status = USB_STATUS_IDLE;

    if (pipe_tr_ptr->CALLBACK != NULL) {
        pipe_tr_ptr->CALLBACK((pointer)pipe_descr_ptr,
        pipe_tr_ptr->CALLBACK_PARAM,
        NULL,
        0,
        USBERR_SHUTDOWN);
    }

    USB_unlock();
    /* Return the status prior to the transfer cancellation */
    return bRet;
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
