/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_dci.h
**     Project   : ProcessorExpert
**     Processor : MK60FN1M0LQ15
**     Component : USB_DEVICE_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 11:41, # CodeGen: 6
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef _USB_DCI_H
#define _USB_DCI_H
/* Customs includes */
#include "types.h"
#include "PE_LDD.h"


/******************************************************************************
 * Macro's
 *****************************************************************************/
#define NO_ERRORS                     (0)   /* Init value for error */
#define STD_SET_ADDRESS               0x0500
#define STD_GET_DESCRIPTOR            0x0680
#define STD_SET_DESCRIPTOR            0x0700
#define STD_GET_CONFIGURATION         0x0880
#define STD_SET_CONFIGURATION         0x0900
#define STD_GET_INTERFACE             0x0A81
#define STD_SET_INTERFACE             0x0B01
#define STD_SYNCH_FRAME               0x0C82

/* Maximum BDT Indexes */
#define MAX_BDT_INDEX  (64)

#define INVALID_BDT_INDEX             (0xff)/* invalid bdt index */
#define USB_RAM_EVEN_BUFFER           (0)
#define USB_RAM_ODD_BUFFER            (1)
#define TRANSFER_INDEX(x)                            (x>>1)

#define USB_DCI_SET_REQUEST_ITF       (0x21)
#define USB_DCI_SET_REQUEST_EP        (0x22)

/******************************************************************************
 * Types
 *****************************************************************************/
typedef struct  _BDT_ELEM
{
        uint_16            len;             /* endpoint max buffer len */
    uint_8_ptr         app_buffer;      /* application buffer pointer */
} BDT_ELEM, *P_BDT_ELEM;

/*****************************************************************************
* Global Functions Prototypes
*****************************************************************************/
extern void USB_DCI_Bus_Reset_Handler(void);
extern void USB_DCI_OnDeviceSpeedDetect(LDD_TUserData *UserDataPtr, LDD_USB_TBusSpeed CurrentSpeed);
extern void USB_DCI_OnDeviceSuspend(LDD_TUserData *UserDataPtr);
extern void USB_DCI_OnDeviceResume(LDD_TUserData *UserDataPtr);
extern void USB_DCI_OnDeviceSetupPacket(LDD_TUserData *UserDataPtr, uint8_t EpNum);
extern void USB_DCI_OnDeviceError(LDD_TUserData *UserDataPtr, uint8_t ErrorSource, uint8_t ErrorCode);

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

