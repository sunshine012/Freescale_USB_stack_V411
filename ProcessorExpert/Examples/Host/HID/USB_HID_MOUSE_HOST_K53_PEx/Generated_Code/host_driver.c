/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_driver.c
**     Project   : ProcessorExpert
**     Processor : MK53N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:30, # CodeGen: 22
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "usb.h"
#include "hostapi.h"
#include "usbprv_host.h"
#include "khci.h"

#include "host_driver.h"
/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_host_driver_install
*  Returned Value : None
*  Comments       :
*        Installs the device
*END*-----------------------------------------------------------------*/
uint_8 _usb_host_driver_install
(
/* [IN] device number */
uint_32  device_number,

/* [IN] address if the callback functions structure */
pointer  callback_struct_ptr
)
{ /* Body */
    pointer callback_struct_table_ptr;

    callback_struct_table_ptr =
    (USB_HOST_CALLBACK_FUNCTIONS_STRUCT_PTR)malloc(USBCFG_MAX_DRIVERS*
    sizeof(USB_HOST_CALLBACK_FUNCTIONS_STRUCT));

    if (!callback_struct_table_ptr) {
        return USBERR_DRIVER_INSTALL_FAILED;
    } /* Endif */

    *((USB_HOST_CALLBACK_FUNCTIONS_STRUCT_PTR)\
    (((USB_HOST_CALLBACK_FUNCTIONS_STRUCT_PTR)callback_struct_table_ptr) +
    device_number)) =
    *((USB_HOST_CALLBACK_FUNCTIONS_STRUCT_PTR)callback_struct_ptr);

    return USB_OK;

} /* EndBody */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/