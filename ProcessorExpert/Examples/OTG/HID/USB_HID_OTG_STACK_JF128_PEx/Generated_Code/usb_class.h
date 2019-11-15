/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_class.h
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

#ifndef _USB_CLASS_H
#define _USB_CLASS_H

/* FILE usb_class.h */
#include "psptypes.h"
#include "usb_devapi.h"

/******************************************************************************
* Macro's
*****************************************************************************/
#define SOF_HIGH_BYTE_SHIFT                 (8)
#define GET_STATUS_DEVICE_MASK              (0x0003)
#define GET_STATUS_OTG_MASK                 (0x0001)
#define REMOTE_WAKEUP_STATUS_MASK           (0x0002)
#define BUS_POWERED                         (0x80)
#define SELF_POWERED                        (0x40)
#define SELF_POWER_BIT_SHIFT                (6)

/* Events to the Application */
#define USB_APP_BUS_RESET                   (0)
#define USB_APP_CONFIG_CHANGED              (1)
#define USB_APP_ENUM_COMPLETE               (2)
#define USB_APP_SEND_COMPLETE               (3)
#define USB_APP_DATA_RECEIVED               (4)
#define USB_APP_ERROR                       (5)
#define USB_APP_GET_DATA_BUFF               (6)
#define USB_APP_EP_STALLED                  (7)
#define USB_APP_EP_UNSTALLED                (8)
#define USB_APP_GET_TRANSFER_SIZE           (9)

/* max packet size for the control endpoint */
#define CONTROL_MAX_PACKET_SIZE             (32) /* max supported value is 64*/

/* identification values and masks to identify request types  */
#define USB_REQUEST_CLASS_MASK              (0x60)
#define USB_REQUEST_CLASS_STRD              (0x00)
#define USB_REQUEST_CLASS_CLASS             (0x20)
#define USB_REQUEST_CLASS_VENDOR            (0x40)

/******************************************************************************
* Types
*****************************************************************************/
/* eight byte usb setup packet structure */
typedef struct _USB_SETUP_STRUCT {
    uint_8      request_type;    /* Bmrequest type */
    uint_8      request;         /* Request code */
    uint_16     value;           /* Wvalue */
    uint_16     index;           /* Windex */
    uint_16     length;          /* Length of the data */
} USB_SETUP_STRUCT;

/* callback function pointer structure for Application to handle events */
typedef void(_CODE_PTR_ USB_CLASS_CALLBACK)(uint_8, uint_8, void*);

/* callback function pointer structure to handle USB framework request */
typedef uint_8 (_CODE_PTR_ USB_REQ_FUNC)(uint_8, USB_SETUP_STRUCT *,uint_8_ptr*,USB_PACKET_SIZE*);

/*callback function pointer structure for application to provide class params*/
typedef uint_8 (_CODE_PTR_ USB_CLASS_SPECIFIC_HANDLER_FUNC)(uint_8,uint_16,uint_8_ptr*,USB_PACKET_SIZE*);

uint_8 USB_Class_Init(
uint_8 controller_ID,
USB_CLASS_CALLBACK class_callback,
USB_REQ_FUNC other_req_callback
);
/*
** ===================================================================
**     Method      :  USB_Class_Init (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         class_callback  - [IN] Class Callback
**         other_req_callback - [IN] Other
**                           Requests Callback
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Class_Send_Data(
uint_8 controller_ID,
uint_8 ep_num,
uint_8_ptr buff_ptr,
USB_PACKET_SIZE size
);
/*
** ===================================================================
**     Method      :  USB_Class_Send_Data (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         ep_num          - [IN] Endpoint number
**         buff_ptr        - [IN] Buffer to send
**         size            - [IN] Length of the transfer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_Class_DeInit(
uint_8 controller_ID
);
/*
** ===================================================================
**     Method      :  USB_Class_DeInit (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
void USB_Class_Periodic_Task(void);
/*
    ** ===================================================================
    **     Method      :  USB_Class_Periodic_Task (component USB_OTG_STACK)
    **     Description :
    **
**     Parameters  : None
**     Returns     : Nothing
    ** ===================================================================
    */
/* END usb_class.h */
#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
