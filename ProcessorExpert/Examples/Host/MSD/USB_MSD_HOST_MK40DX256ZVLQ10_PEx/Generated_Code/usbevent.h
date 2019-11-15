/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usbevent.h
**     Project   : ProcessorExpert
**     Processor : MK40N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-29, 14:17, # CodeGen: 1
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __usb_event_h__
#define __usb_event_h__

#include "psptypes.h"
/*--------------------------------------------------------------------------*/
/*
**                            MACRO DEFINITIONS
*/

#define USB_EVENT_OK                       0x00
#define USB_EVENT_ERROR                    0x01
#define USB_EVENT_SET                      0x02
#define USB_EVENT_NOT_SET                  0x03
#define USB_EVENT_VALID                    0x04
#define USB_EVENT_INVALID                  0x05

/*--------------------------------------------------------------------------*/
/*
**                            DATATYPE DECLARATIONS
*/
typedef struct usb_event
{
    boolean VALID;
    uint_32 VALUE;
} USB_EVENT_STRUCT, _PTR_ USB_EVENT_STRUCT_PTR;
/*---------------------------------------------------------------------
**
**
*/

/*--------------------------------------------------------------------------*/
/*
** FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

    extern uint_16 _usb_event_init(USB_EVENT_STRUCT_PTR);
    extern uint_16 _usb_event_clear(USB_EVENT_STRUCT_PTR, uint_32);
    extern uint_16 _usb_event_set(USB_EVENT_STRUCT_PTR, uint_32);
    extern uint_16 _usb_event_wait_ticks(USB_EVENT_STRUCT_PTR, uint_32, uint_8, uint_16);

#ifdef __cplusplus
}
#endif

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
