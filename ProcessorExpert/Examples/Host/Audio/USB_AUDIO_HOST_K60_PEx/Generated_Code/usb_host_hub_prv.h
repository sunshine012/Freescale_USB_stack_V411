/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_host_hub_prv.h
**     Project   : ProcessorExpert
**     Processor : MK60N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 11:52, # CodeGen: 191
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __usb_host_hub_prv_h__
#define __usb_host_hub_prv_h__

/* System Include files */
#include "usb.h"
#include "hostapi.h"
#include "host_ch9.h"
#include "host_dev_list.h"
#include "host_common.h"
#include "usbprv.h"

#define  C_HUB_LOCAL_POWER          (0)
#define  C_HUB_OVER_CURRENT         (1)
#define  PORT_CONNECTION            (0)
#define  PORT_ENABLE                (1)
#define  PORT_SUSPEND               (2)
#define  PORT_OVER_CURRENT          (3)
#define  PORT_RESET                 (4)
#define  PORT_POWER                 (8)
#define  PORT_LOW_SPEED             (9)
#define  PORT_HIGH_SPEED            (10)
#define  C_PORT_CONNECTION          (16)
#define  C_PORT_ENABLE              (17)
#define  C_PORT_SUSPEND             (18)
#define  C_PORT_OVER_CURRENT        (19)
#define  C_PORT_RESET               (20)
#define  C_PORT_POWER               (24)
#define  PORT_TEST                  (21)
#define  PORT_INDICATOR             (22)

/* structure for HUB class descriptor */
typedef struct _HUB_DESCRIPTOR_STRUCT {
    uint_8     BLENGTH;
    uint_8     BDESCRIPTORTYPE;
    uint_8     BNRPORTS;
    uint_8     WHUBCHARACTERISTICS[2];
    uint_8     BPWRON2PWRGOOD;
    uint_8     BHUBCONTRCURRENT;
    uint_8     DEVICEREMOVABLE[];
    /* not used: */
    /*    uint_8     PORTPOWERCTRLMASK; */
} HUB_DESCRIPTOR_STRUCT, _PTR_ HUB_DESCRIPTOR_STRUCT_PTR;

typedef struct {
    CLASS_CALL_STRUCT_PTR   CLASS_PTR;
    tr_callback             CALLBACK_FN;
    pointer                 CALLBACK_PARAM;
} HUB_COMMAND, _PTR_ HUB_COMMAND_PTR;

/* Class specific functions exported by hub class driver */
#ifdef __cplusplus
extern "C" {
#endif

extern USB_STATUS usb_class_hub_cntrl_common(HUB_COMMAND_PTR, uint_8, uint_8, uint_16, uint_16, uint_16, uchar_ptr);
extern void usb_class_hub_cntrl_callback(pointer, pointer, uchar_ptr, uint_32, USB_STATUS);
extern USB_STATUS usb_class_hub_get_descriptor(HUB_COMMAND_PTR, uchar_ptr, uchar);
extern USB_STATUS usb_class_hub_set_port_feature(HUB_COMMAND_PTR, uint_8, uint_8);
extern USB_STATUS usb_class_hub_clear_port_feature(HUB_COMMAND_PTR, uint_8, uint_8);
extern USB_STATUS usb_class_hub_get_port_status(HUB_COMMAND_PTR, uint_8, uchar_ptr, uchar);

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
