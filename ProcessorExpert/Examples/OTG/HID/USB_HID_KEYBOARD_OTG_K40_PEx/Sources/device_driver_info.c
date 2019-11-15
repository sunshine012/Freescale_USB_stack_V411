/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : device_driver_info.c
**     Project   : ProcessorExpert
**     Processor : MK40N512MD100
**     Component : USB_HID_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.003
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-04-17, 15:38, # CodeGen: 23
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
/* Begin of code block <0>  auto generated code, DO NOT MODIFY LINES BELOW */
#include "device_driver_info.h"
#include "usb_host_hub_sm.h"
/* End code block <0>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write your own includes here ... */
#include "hidkeyboard.h"
/* Begin of code block <1>  auto generated code, DO NOT MODIFY LINES BELOW */
/* Table of driver capabilities this application wants to use */
const USB_HOST_DRIVER_INFO DriverInfoTable[] =
{
    {
        {0x00,0x00},                   /* Vendor ID per USB-IF             */
        {0x00,0x00},                   /* Product ID per manufacturer      */
        0x03,                          /* Class code                       */
        0x01,                          /* Sub-Class code                   */
        0x01,                          /* Protocol                         */
        0,                             /* Reserved                         */
        usb_host_hid_keyboard_event    /* Application call back function   */
   },
    {
        {0x00,0x00},                   /* Vendor ID per USB-IF             */
        {0x00,0x00},                   /* Product ID per manufacturer      */
        USB_CLASS_HUB,                 /* Class code                       */
        USB_SUBCLASS_HUB_NONE,         /* Sub-Class code                   */
        USB_PROTOCOL_HUB_LS,           /* Protocol                         */
        0,                             /* Reserved                         */
        usb_host_hub_device_event      /* Application call back function   */
    },
    {
        {0x00,0x00},                   /* All-zero entry terminates        */
        {0x00,0x00},                   /* driver info list.                */
        0,
        0,
        0,
        0,
        NULL
    }
};

/* End code block <1>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write code here ... */


/* Application call back function   */
void usb_host_hid_keyboard_event
(
    /* [IN] pointer to device instance */
    _usb_device_instance_handle      dev_handle,
    /* [IN] pointer to interface descriptor */
    _usb_interface_descriptor_handle intf_handle,
    /* [IN] code number for event causing callback */
    uint_32                          event_code
)
{
/* End code block <2>, DO NOT MODIFY LINES ABOVE */
/* Write your own code of usb_host_hid_keyboard_event function below */
   usb_host_hid_keyboard_app_event(dev_handle,intf_handle,event_code);
/* End of code block <3>, DO NOT MODIFY THE LINE BELOW */
} /* End of usb_host_audio_hid_event function */
/* DO NOT MODIFY LINES ABOVE */

/*EOF*/

