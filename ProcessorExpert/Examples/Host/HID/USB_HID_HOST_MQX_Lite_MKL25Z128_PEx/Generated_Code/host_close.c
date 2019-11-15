/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_close.c
**     Project   : ProcessorExpert
**     Processor : MKL25Z128LK4
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-02, 13:43, # CodeGen: 119
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "hostapi.h"
#include "usbprv_host.h"
#include "host_close.h"

/*
** ===================================================================
**     Method      :  _usb_host_close_pipe (component USB_HOST_STACK)
**     Description :
**         _usb_host_close_pipe routine removes the pipe from the open
**         pipe list
**     Parameters  :
**         NAME            - DESCRIPTION
**         hci_handle      - [IN] the USB Host state
**                           structure
**         pipe_handle     - [IN] the pipe (handle) to
**                           close
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
USB_STATUS _usb_host_close_pipe(_usb_host_handle hci_handle, _usb_pipe_handle pipe_handle)
{
    USB_STATUS error;
    PIPE_DESCRIPTOR_STRUCT_PTR pipe_descr_ptr;
    pipe_descr_ptr = (PIPE_DESCRIPTOR_STRUCT_PTR)pipe_handle;

    if (pipe_descr_ptr->PIPE_ID > USBCFG_MAX_PIPES) {
        return USBERR_INVALID_PIPE_HANDLE;
    }

    USB_lock();

    /* Call the low-level routine to free the controller specific resources */
    error = _usb_host_close_pipe_call_interface (hci_handle, pipe_descr_ptr);

    if (error != USB_OK)
    {
        USB_unlock();

        return error;
    }

    /* de-initialise the pipe descriptor */
    memset(pipe_descr_ptr, 0, sizeof(PIPE_DESCRIPTOR_STRUCT));

    USB_unlock();

    return USB_OK;
}

/*
** ===================================================================
**     Method      :  _usb_host_close_all_pipes (component USB_HOST_STACK)
**     Description :
**         _usb_host_close_all_pipes routine removes the pipe from the
**         open pipe list
**     Parameters  :
**         NAME            - DESCRIPTION
**         hci_handle      - [IN] the USB Host state
**                           structure
**     Returns     : Nothing
** ===================================================================
*/
void _usb_host_close_all_pipes(_usb_host_handle hci_handle)
{
    int_16 i;
    USB_HOST_STATE_STRUCT_PTR usb_host_ptr;

    usb_host_ptr = (USB_HOST_STATE_STRUCT_PTR)hci_handle;

    USB_lock();

    for (i=0; i < USBCFG_MAX_PIPES; i++) {
        if (!(usb_host_ptr->PIPE_DESCRIPTOR_BASE_PTR[i].OPEN)) {
            break;
        } else {
            /* Call the low-level routine to free the controller specific
        ** resources for this pipe
        */
            _usb_host_close_pipe_call_interface (hci_handle,
            &usb_host_ptr->PIPE_DESCRIPTOR_BASE_PTR[i]);

            /* de-initialise the pipe descriptor */
            memset(&usb_host_ptr->PIPE_DESCRIPTOR_BASE_PTR[i],0,
            sizeof(PIPE_DESCRIPTOR_STRUCT));
        }
    }

    USB_unlock();
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
