/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usbevent.c
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

#include "usbevent.h"
#include "usb.h"
/*
** ===================================================================
**     Method      :  _usb_event_init (component USB_HOST_STACK)
**     Description :
**         Allocate event pointer, clear value and set event in valid
**         state.
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_16 _usb_event_init(USB_EVENT_STRUCT_PTR event)
{
    event->VALID = USB_EVENT_VALID;
    event->VALUE = 0;
    return  USB_OK;
}
/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _usb_event_set
* Returned Value   :
* Comments         : Set value of event pointer.
*
*
*END*----------------------------------------------------------------------*/
uint_16 _usb_event_set(USB_EVENT_STRUCT_PTR event, uint_32 value)
{
    if(event->VALID == USB_EVENT_VALID) {
        event->VALUE |= value;
        return USB_EVENT_VALID;
    }
    return USB_EVENT_INVALID;
}

/*
** ===================================================================
**     Method      :  _usb_event_clear (component USB_HOST_STACK)
**     Description :
**         Clear value of event pointer
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - 
**         bitmask         - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_16 _usb_event_clear(USB_EVENT_STRUCT_PTR event, uint_32 bitmask)
{
    if(event->VALID == USB_EVENT_VALID) {
        event->VALUE &= ~bitmask;
        return USB_EVENT_VALID;
    }
    return USB_EVENT_INVALID;
}

/*
** ===================================================================
**     Method      :  _usb_event_wait_ticks (component USB_HOST_STACK)
**     Description :
**         This function returns the value USB_EVENT_SET when an event
**         occurs, but timeout not support
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - 
**         bitmask         - 
**         all             - 
**         ticks           - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_16 _usb_event_wait_ticks(USB_EVENT_STRUCT_PTR event, uint_32 bitmask, uint_8 all, uint_16 ticks)
{

    UNUSED(all)
    UNUSED(ticks)

    if(event->VALID == USB_EVENT_VALID) {
        if(0x00 != (event->VALUE & bitmask)){
            return USB_EVENT_SET;
        } else {
            return USB_EVENT_NOT_SET;
        }
    }
    return USB_EVENT_INVALID;
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
