/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_cnfg.h
**     Project   : ProcessorExpert
**     Processor : MKL25Z128LK4
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
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

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
