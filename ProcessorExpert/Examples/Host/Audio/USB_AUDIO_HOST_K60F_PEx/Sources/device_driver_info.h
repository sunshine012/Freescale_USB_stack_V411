/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : device_driver_info.h
**     Project   : ProcessorExpert
**     Processor : MK60FN1M0LQ15
**     Component : USB_AUDIO_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

/* Begin of code block <0>  auto generated code, DO NOT MODIFY LINES BELOW */
#ifndef __device_driver_info_h__
#define __device_driver_info_h__
#include "host_common.h"
/*************************************************************************
* Macro's
/*************************************************************************/
#define USE_HUB
/* End code block <0>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write your own includes here ... */

/* Begin of code block <1>  auto generated code, DO NOT MODIFY LINES BELOW */
/* Alphabetical list of Function Prototypes */
#ifdef __cplusplus
extern "C" {
#endif
    extern const USB_HOST_DRIVER_INFO DriverInfoTable[];
    /* Application call back function   */
    void usb_host_audio_control_event
    (
    _usb_device_instance_handle,
    _usb_interface_descriptor_handle,
    uint_32
    );
/*
** ===================================================================
**     Method      :  usb_host_audio_usb_host_audio_control_event (component USB_AUDIO_CLASS)
**
**     Description :
**         The funtion initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - [IN] pointer to device instance
**         intf_handle     - [IN] pointer to interface descriptor
**         event_code      - [IN] code number for event causing callback
**     Returns     :
** ===================================================================
*/
    void usb_host_audio_stream_event
    (
    _usb_device_instance_handle,
    _usb_interface_descriptor_handle,
    uint_32
    );
/*
** ===================================================================
**     Method      :  usb_host_audio_usb_host_audio_stream_event (component USB_AUDIO_CLASS)
**
**     Description :
**         The funtion initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - [IN] pointer to device instance
**         intf_handle     - [IN] pointer to interface descriptor
**         event_code      - [IN] code number for event causing callback
**     Returns     :
** ===================================================================
*/
#ifdef __cplusplus
}
#endif
#endif
/* End code block <1>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write code here ... */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
/* EOF */

