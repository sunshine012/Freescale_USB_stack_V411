/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_classes.c
**     Project   : ProcessorExpert
**     Processor : MK53N512MD100
**     Component : USB_AUDIO_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#include "hostapi.h"
#include "host_ch9.h"
#include "host_common.h"

/* get application-specific configuration */
#include "usb_classes.h"
#include "usb_host_hub.h"
#include "usb_host_audio.h"
/* here hub is considered as device from host point of view */
#include "usb_host_hub.h"
CLASS_MAP class_interface_map[] =
{
    {
        usb_class_audio_control_init,
        sizeof(AUDIO_CONTROL_INTERFACE_STRUCT),
        0x01,
        0x01,
        0x00,
        0xFF,0xFF,0x00,
    },
    {
        usb_class_audio_stream_init,
        sizeof(AUDIO_STREAM_INTERFACE_STRUCT),
        0x01,
        0x02,
        0x00,
        0xFF,0xFF,0x00,
    },
    {
        usb_class_hub_init,
        sizeof(USB_HUB_CLASS_INTF_STRUCT),
        USB_CLASS_HUB,
        USB_SUBCLASS_HUB_NONE,
        USB_PROTOCOL_HUB_FS,
        0xFF, 0x00, 0x00
    },
    {
        NULL,
        0,
        0, 0, 0,
        0, 0, 0
    }
};
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
/* EOF */
