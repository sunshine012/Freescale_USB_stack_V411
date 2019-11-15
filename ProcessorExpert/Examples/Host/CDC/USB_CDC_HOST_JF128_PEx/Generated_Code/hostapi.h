/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : hostapi.h
**     Project   : ProcessorExpert
**     Processor : MCF51JF128_64
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:04, # CodeGen: 17
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __hostapi_h__
#define __hostapi_h__ 1

#include "psptypes.h"
#include "usb.h"

#include "host_ch9.h"
#include "host_close.h"
#include "host_cnl.h"

#include "host_common.h"
#include "host_dev_list.h"
#include "host_main.h"
#include "host_rcv.h"
#include "host_shut.h"
#include "host_snd.h"

#define  USB_INTERFACE_DESCRIPTOR_TYPE       (0x04)

/* Available service types */
#define  USB_SERVICE_HOST_RESUME             (0x01)
#define  USB_SERVICE_SYSTEM_ERROR            (0x02)
#define  USB_SERVICE_SPEED                   (0x03)
#define  USB_SERVICE_ATTACH                  (0x04)
#define  USB_SERVICE_DETACH                  (0x05)
#define  USB_SERVICE_STALL_PACKET            (0x06)
#define  USB_SERVICE_ENUMERATION_DONE        (0x07)
#define  USB_SERVICE_1MS_TIMER               (0x08)

/* Used to manage services and service callbacks */
typedef struct host_service_struct
{
    struct host_service_struct _PTR_ NEXT;
    uint_32                          TYPE;
    void                 (_CODE_PTR_ SERVICE)(pointer, uint_32);
} USB_SERVICE_STRUCT, _PTR_ USB_SERVICE_STRUCT_PTR;

/* Prototypes */

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
