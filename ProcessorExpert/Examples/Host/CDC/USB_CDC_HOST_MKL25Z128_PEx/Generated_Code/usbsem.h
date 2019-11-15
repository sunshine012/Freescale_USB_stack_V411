/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usbsem.h
**     Project   : ProcessorExpert
**     Processor : MKL25Z128LK4
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 14:45, # CodeGen: 15
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef __usb_sem_h__
#define __usb_sem_h__
#include "psptypes.h"
#include "khci.h"
/*--------------------------------------------------------------------------*/
/*
**                            MACRO DEFINITIONS
*/

#define USB_SEM_OK                       0x00
#define USB_SEM_ERROR                    0x01
#define USB_SEM_FREE                     0x02
#define USB_SEM_VALID                    0x04
#define USB_SEM_INVALID                  0x05

/*--------------------------------------------------------------------------*/
/*
**                            DATATYPE DECLARATIONS
*/

typedef struct usb_sem
{
    boolean VALID;
    uint_32 VALUE;
} USB_SEM_STRUCT, _PTR_ USB_SEM_STRUCT_PTR;
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

    extern uint_16 _usb_sem_create(USB_SEM_STRUCT_PTR, int_32);
    extern uint_16 _usb_sem_post(USB_SEM_STRUCT_PTR);
    extern uint_16 _usb_sem_wait(USB_SEM_STRUCT_PTR);
    extern uint_16 _usb_sem_wait_ticks(USB_SEM_STRUCT_PTR, uint_32);
    extern uint_16 _usb_sem_destroy(USB_SEM_STRUCT_PTR);

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
