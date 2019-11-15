/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_shut.c
**     Project   : ProcessorExpert
**     Processor : MK40N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-25, 09:45, # CodeGen: 5
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "hostapi.h"
#include "usbprv_host.h"
#include "host_shut.h"
/*
** ===================================================================
**     Method      :  _usb_host_shutdown (component USB_HOST_STACK)
**     Description :
**         Shutdown an initialized USB Host
**     Parameters  :
**         NAME            - DESCRIPTION
**         hci_handle      - [IN] the USB_host handle 
**     Returns     : Nothing
** ===================================================================
*/
void _usb_host_shutdown(_usb_host_handle hci_handle)
{
    /* Body */
    /* De-initialize and disconnect the host hardware from the bus */
    _usb_host_shutdown_call_interface (hci_handle);
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_host_bus_control
*  Returned Value : None
*  Comments       :
* _usb_host_bus_control controls the bus operations such as asserting and
* deasserting the bus reset, asserting and deasserting resume,
* suspending and resuming the SOF generation
*
*END*-----------------------------------------------------------------*/

void _usb_host_bus_control
(
/* [IN] the USB Host state structure */
_usb_host_handle           hci_handle,

/* The operation to be performed on the bus */
uint_8                     bus_control
)
{ /* Body */
    _usb_host_bus_control_data_call_interface (hci_handle, bus_control);
} /* Endbody */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
