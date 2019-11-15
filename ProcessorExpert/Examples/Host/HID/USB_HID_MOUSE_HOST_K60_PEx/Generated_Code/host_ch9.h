/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : host_ch9.h
**     Project   : ProcessorExpert
**     Processor : MK60N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:23, # CodeGen: 54
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __host_ch9_h__
#define __host_ch9_h__

#include "psptypes.h"
#include "host_common.h"

/*----------------------------------------------------------------**
** Chapter 9.4 Standard Device Requests -- all devices            **
** See Table 9-3 p. 250 of USB 2.0 spec for combinations          **
**   of request type bitfields with requests, WVALUE, WINDEX etc. **
**----------------------------------------------------------------*/
#define  REQ_TYPE_DEVICE    0x00
#define  REQ_TYPE_INTERFACE 0x01
#define  REQ_TYPE_ENDPOINT  0x02

/* Combine one of the 3 above with one of the following 2 */
#define  REQ_TYPE_IN        0x80
#define  REQ_TYPE_OUT       0x00

/* Also for class requests set the following bit */
#define  REQ_TYPE_CLASS     0x20

/* Standard USB requests, see Chapter 9 */
#define  REQ_GET_STATUS          0
#define  REQ_CLEAR_FEATURE       1
#define  REQ_SET_FEATURE         3
#define  REQ_SET_ADDRESS         5
#define  REQ_GET_DESCRIPTOR      6
#define  REQ_SET_DESCRIPTOR      7
#define  REQ_GET_CONFIGURATION   8
#define  REQ_SET_CONFIGURATION   9
#define  REQ_GET_INTERFACE       10
#define  REQ_SET_INTERFACE       11
#define  REQ_SYNCH_FRAME         12

/*******************************************************************
**
** Values specific to CLEAR FEATURE commands (must go to common.h later)
*/

#define  ENDPOINT_HALT        0
#define  DEVICE_REMOTE_WAKEUP 1
#define  TEST_MODE            2

/* States of device instances on the device list */

/* initial device state */
#define  DEVSTATE_INITIAL        0x00

/* device descriptor [0..7]*/
#define  DEVSTATE_DEVDESC8       0x01

/* address set */
#define  DEVSTATE_ADDR_SET       0x02

/* full device descriptor */
#define  DEVSTATE_DEV_DESC       0x03

/* config descriptor [0..7] */
#define  DEVSTATE_GET_CFG9       0x04

/* config set */
#define  DEVSTATE_SET_CFG        0x05

/* full config desc. read in */
#define  DEVSTATE_CFG_READ       0x06

/* application callbacks */
#define  DEVSTATE_APP_CALL       0x07

/* Select interface done */
#define  DEVSTATE_SET_INTF       0x08

#define  DEVSTATE_ENUM_OK        0x09
#define  DEVSTATE_SET_HNP        0x0B

/* Event codes for attach/detach etc. callback */
#define  USB_ATTACH_EVENT        1   /* device attach */
#define  USB_DETACH_EVENT        2   /* device detach */
#define  USB_CONFIG_EVENT        3   /* device reconfigured */
#define  USB_INTF_EVENT          4   /* device interface selected */

/* Alphabetical list of Function Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

    extern USB_STATUS  _usb_host_register_ch9_callback(_usb_device_instance_handle,
    tr_callback, pointer);
    extern USB_STATUS _usb_host_ch9_clear_feature(_usb_device_instance_handle,
    uint_8, uint_8, uint_16);
    extern USB_STATUS _usb_host_ch9_get_configuration(_usb_device_instance_handle,
    uchar_ptr);
    extern USB_STATUS _usb_host_ch9_get_descriptor(_usb_device_instance_handle,
    uint_16, uint_16, uint_16, uchar_ptr);
    extern USB_STATUS _usb_host_ch9_get_interface(_usb_device_instance_handle,
    uint_8, uchar_ptr);
    extern USB_STATUS _usb_host_ch9_get_status(_usb_device_instance_handle,
    uint_8, uint_8, uchar_ptr);
    extern USB_STATUS _usb_host_ch9_set_address(_usb_device_instance_handle);
    extern USB_STATUS _usb_host_ch9_set_configuration(_usb_device_instance_handle,
    uint_16);
    extern USB_STATUS _usb_host_ch9_set_descriptor(_usb_device_instance_handle,
    uint_16, uint_16, uint_16, uchar_ptr);
    extern USB_STATUS _usb_host_ch9_set_feature(_usb_device_instance_handle,
    uint_8, uint_8, uint_16);
    extern USB_STATUS _usb_host_ch9_set_interface(_usb_device_instance_handle,
    uint_8, uint_8);
    extern USB_STATUS _usb_host_ch9_synch_frame(_usb_device_instance_handle,
    uint_8, uchar_ptr);
    extern USB_STATUS _usb_hostdev_cntrl_request(_usb_device_instance_handle,
    USB_SETUP_PTR, uchar_ptr, tr_callback, pointer);

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
