/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usbsem.c
**     Project   : ProcessorExpert
**     Processor : MK40N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:52, # CodeGen: 19
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "usbsem.h"
#include "usb.h"

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _usb_sem_create
* Returned Value   :
* Comments         : Create a semaphore pointer, set VALID field to USB_SEM_VALID and VAULE to initial_number
*
*
*END*----------------------------------------------------------------------*/
uint_16 _usb_sem_create
(
USB_SEM_STRUCT_PTR sem_ptr,
int_32               initial_number
)
{
    sem_ptr->VALID = USB_SEM_VALID;
    sem_ptr->VALUE = (uint_32)initial_number;
    return  USB_OK;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _usb_sem_post
* Returned Value   :
* Comments         : Increate VALUE field of semaphore pointer.
*
*
*END*----------------------------------------------------------------------*/
uint_16 _usb_sem_post
(
USB_SEM_STRUCT_PTR sem_ptr
)
{
    if(sem_ptr->VALID == USB_SEM_VALID) {
        sem_ptr->VALUE++;
        return USB_OK;
    }
    return USB_SEM_INVALID;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _usb_sem_wait
* Returned Value   :
* Comments         : Wait for a lightweight semaphore.
*
*
*END*----------------------------------------------------------------------*/
uint_16 _usb_sem_wait
(
USB_SEM_STRUCT_PTR sem_ptr
)
{
    if(sem_ptr->VALID == USB_SEM_VALID) {
        sem_ptr->VALUE--;
        return USB_OK;
    }
    return USB_SEM_INVALID;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _usb_sem_wait_ticks
* Returned Value   :
* Comments         :
*
*
*END*----------------------------------------------------------------------*/
uint_16 _usb_sem_wait_ticks
(
USB_SEM_STRUCT_PTR sem_ptr,
uint_32 ticks
)
{
    UNUSED(ticks)

    if(sem_ptr->VALID == USB_SEM_VALID) {
        if(sem_ptr->VALUE <= 0)
        return USB_SEM_FREE;
        else {
            sem_ptr->VALUE--;
            return USB_OK;
        }
    }
    return USB_SEM_INVALID;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _usb_sem_wait_ticks
* Returned Value   :
* Comments         : Set VALID field of semaphore pointer to USB_SEM_INVALID
*
*
*END*----------------------------------------------------------------------*/
uint_16 _usb_sem_destroy
(
USB_SEM_STRUCT_PTR sem_ptr
)
{
    if(sem_ptr->VALID == USB_SEM_VALID) {
        sem_ptr->VALUE--;
        return USB_OK;
    }
    return USB_SEM_INVALID;
}
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
