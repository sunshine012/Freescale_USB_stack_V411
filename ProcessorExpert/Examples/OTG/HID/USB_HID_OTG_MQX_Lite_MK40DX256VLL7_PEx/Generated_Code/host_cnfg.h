/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_cnfg.h
**     Project   : ProcessorExpert
**     Processor : MK40N512LQ100
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef __usb_cnfg_h__
#define __usb_cnfg_h__

/* maximum pipes */
#define USBCFG_MAX_PIPES                              (24)

/* maximum number of usb interfaces */
#define USBCFG_MAX_INTERFACE                          (1)

#define USBCFG_HOST_NUM_ISO_PACKET_DESCRIPTORS        (0)

#define USBCFG_MAX_DRIVERS                            (1)

#define USBCFG_DEFAULT_MAX_NAK_COUNT                  (15)

#define USBCFG_MFS_OPEN_READ_CAPACITY_RETRY_DELAY     (_time_get_ticks_per_sec() * 1)

#define USBCFG_MFS_LWSEM_TIMEOUT                      (_time_get_ticks_per_sec() * 20)

#define USBCFG_MFS_MAX_RETRIES                        (2)
#define USBCFG_KHCI_TASK_PRIORITY                     (7)
/* maximum number of usb device list */
#define MAX_DEV_LIST                                  (5)
/* maximum usb device list buffer size*/
#define MAX_DEV_LIST_BUFF_SIZE                        (140)
/* maximum number of usb device attach */
#define MAX_DEV_ATTACH                                (1)
/* maximum number of usb device descriptor */
#define MAX_NUM_DESCS                                 (1)
/* maximum number of usb transaction element */
#define MAX_TR_ELEMENT                                (4)
/* max host register service */
#define MAX_HOST_REGISTER_SERVICE                     (1)
/* maximum number of Hub */

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
