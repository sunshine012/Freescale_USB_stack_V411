/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_classes.c
**     Project   : ProcessorExpert
**     Processor : MCF51JF128_64
**     Component : USB_HID_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 13:47, # CodeGen: 62
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#include "usb_host_hid.h"
#include "hostapi.h"
#include "host_ch9.h"
#include "host_common.h"

/* get application-specific configuration */
#include "usb_classes.h"
#include "usb_host_hub.h"
CLASS_MAP class_interface_map[] =
{
   {
      usb_class_host_hid_init,
      sizeof(USB_HID_CLASS_INTF_STRUCT),
      0x03,
      0x01,
      0x01,
      0xFF,0x00,0x00,
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
/* EOF */
