/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_host_hub_sm.h
**     Project   : ProcessorExpert
**     Processor : MCF51JF128_64
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef __usb_host_hub_sm_h__
#define __usb_host_hub_sm_h__
/* System Include files */
#include "usb.h"
#include "hostapi.h"
#include "host_ch9.h"
#include "host_dev_list.h"
#include "host_common.h"
#include "usbprv.h"

/*
** Following structs contain all states and pointers
** used by the application to control/operate devices.
*/

#define APP_STATUS_ATTACHED               (0x01) /* flag informs that application started attach process */

typedef struct hub_device_port_struct {
    uint_8                           REMOVABLE;  /* is it the port used for removable USB devices? */
    uint_16                          STATUS;
    uint_8                           APP_STATUS; /* application stores flags here */
} HUB_PORT_STRUCT, _PTR_ HUB_PORT_STRUCT_PTR;

typedef struct hub_device_struct {
    CLASS_CALL_STRUCT                CLASS_INTF;
    _usb_device_instance_handle      DEV_HANDLE;
    _usb_interface_descriptor_handle INTF_HANDLE;
    /* below the hub specific data */
    enum {
        HUB_IDLE,
        HUB_GET_DESCRIPTOR_TINY_PROCESS,
        HUB_GET_DESCRIPTOR_PROCESS,
        HUB_SET_PORT_FEATURE_PROCESS,
        HUB_CLEAR_PORT_FEATURE_PROCESS,
        HUB_GET_PORT_STATUS_PROCESS,
        HUB_GET_PORT_STATUS_ASYNC,
        HUB_RESET_DEVICE_PORT_PROCESS,
        HUB_ADDRESS_DEVICE_PORT_PROCESS,
        HUB_DETACH_DEVICE_PORT_PROCESS,
        HUB_NONE
    }                                STATE;
    uchar                            HUB_PORT_NR;
    uint_16                          port_iterator;
    pointer                          interrupt_buffer;
    pointer                          control_buffer;
    HUB_PORT_STRUCT_PTR              HUB_PORTS;
} HUB_DEVICE_STRUCT,  _PTR_ HUB_DEVICE_STRUCT_PTR;

/* List of Function Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

    void usb_host_hub_device_event(_usb_device_instance_handle, _usb_interface_descriptor_handle, uint_32);

#ifdef __cplusplus
}
#endif

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
