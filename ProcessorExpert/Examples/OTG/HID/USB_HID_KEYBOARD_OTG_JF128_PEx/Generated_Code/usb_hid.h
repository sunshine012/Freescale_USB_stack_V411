/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : usb_hid.h
**     Project     : ProcessorExpert
**     Processor   : MCF51JF128VLH
**     Component   : USB_HID_CLASS
**     Version     : Component 01.027, Driver 01.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2012-11-19, 13:47, # CodeGen: 62
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         USB_Class_HID_Init              - uint_8 usb_hid_USB_Class_HID_Init(uint_8 controller_ID, USB_CLASS_CALLBACK...
**         USB_Class_HID_DeInit            - uint_8 usb_hid_USB_Class_HID_DeInit(uint_8 controller_ID);
**         USB_Class_HID_Send_Data         - uint_8 usb_hid_USB_Class_HID_Send_Data(uint_8 controller_ID, uint_8 ep_num,...
**         usb_class_host_hid_init         - void usb_hid_usb_class_host_hid_init(PIPE_BUNDLE_STRUCT_PTR *pbs_ptr,...
**         usb_class_host_hid_get_report   - USB_STATUS usb_hid_usb_class_host_hid_get_report(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_set_report   - USB_STATUS usb_hid_usb_class_host_hid_set_report(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_get_idle     - USB_STATUS usb_hid_usb_class_host_hid_get_idle(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_set_idle     - USB_STATUS usb_hid_usb_class_host_hid_set_idle(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_get_protocol - USB_STATUS usb_hid_usb_class_host_hid_get_protocol(HID_COMMAND_PTR *com_ptr,...
**         usb_class_host_hid_set_protocol - USB_STATUS usb_hid_usb_class_host_hid_set_protocol(HID_COMMAND_PTR *com_ptr,...
**
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef _USB_HID_H
#define _USB_HID_H 1
/******************************************************************************
 * Includes
 *****************************************************************************/
#include "types.h"
#include "usb_descriptor.h"
#include "usb_class.h"



/******************************************************************************
 * Macro's
 *****************************************************************************/
#define MAX_QUEUE_ELEMS                     (4)

 /* class specific requests */
#define USB_HID_GET_REPORT_REQUEST          (0x01)
#define USB_HID_GET_IDLE_REQUEST            (0x02)
#define USB_HID_GET_PROTOCOL_REQUEST        (0x03)
#define USB_HID_SET_REPORT_REQUEST          (0x09)
#define USB_HID_SET_IDLE_REQUEST            (0x0A)
#define USB_HID_SET_PROTOCOL_REQUEST        (0x0B)

/* for class specific requests */
#define HIGH_BYTE_SHIFT                     (8)
#define MSB_MASK                            (0xFF00)
#define USB_HID_REQUEST_DIR_MASK            (0x08)
#define USB_HID_REQUEST_TYPE_MASK           (0x01)
#define REPORT_SIZE                         (4)
#define CLASS_REQ_DATA_SIZE                 (0x01)

/******************************************************************************
 * Types
 *****************************************************************************/
/* structure to hold a request in the endpoint queue */
typedef struct _usb_class_hid_queue
{
    uint_8 controller_ID;   /* Controller ID*/
    uint_8 channel;         /* Endpoint number */
    uint_8_ptr app_buff;    /* Buffer to send */
    USB_PACKET_SIZE size;   /* Size of the transfer */
}USB_CLASS_HID_QUEUE, *PTR_USB_CLASS_HID_QUEUE;

/* USB class hid endpoint data */
typedef struct _usb_class_hid_endpoint
{
    uint_8 endpoint;        /* Endpoint number */
    uint_8 type;            /* Type of endpoint (interrupt,
                               bulk or isochronous) */
    uint_8 bin_consumer;    /* Num of queued elements */
    uint_8 bin_producer;    /* Num of de-queued elements */
    USB_CLASS_HID_QUEUE queue[MAX_QUEUE_ELEMS]; /* Queue data */
}USB_CLASS_HID_ENDPOINT;

/* contains the endpoint data for non control endpoints */
typedef struct _usb_class_hid_endpoint_data
{
    /* Num of non control endpoints */
    uint_8 count;
    /* contains the endpoint info */
    USB_CLASS_HID_ENDPOINT ep[HID_DESC_ENDPOINT_COUNT];
}USB_CLASS_HID_ENDPOINT_DATA, *PTR_USB_CLASS_HID_ENDPOINT_DATA;

/******************************************************************************
 * Global Functions
 *****************************************************************************/
uint_8 USB_Class_HID_Init(
    uint_8 controller_ID,
    USB_CLASS_CALLBACK hid_class_callback,
    USB_REQ_FUNC vendor_req_callback,
    USB_CLASS_SPECIFIC_HANDLER_FUNC param_callback
);
/*
** ===================================================================
**     Method      :  usb_hid_USB_Class_HID_Init (component USB_HID_CLASS)
**
**     Description :
**         The funtion initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To Identify the
**                           controller
**         hid_class_callback - HID Class
**                           Callback
**         vendor_req_callback - vendor
**                           specific class request callback 
**         param_callback  - HID Class requests
**                           Callback
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_HID_DeInit(
    uint_8 controller_ID
);
/*
** ===================================================================
**     Method      :  usb_hid_USB_Class_HID_DeInit (component USB_HID_CLASS)
**
**     Description :
**         The funtion de-initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - Controller ID 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_HID_Send_Data(
    uint_8 controller_ID,
    uint_8 ep_num,
    uint_8_ptr app_buff,
    USB_PACKET_SIZE size
);
/*
** ===================================================================
**     Method      :  usb_hid_USB_Class_HID_Send_Data (component USB_HID_CLASS)
**
**     Description :
**         This fucntion is used by Application to send data through
**         HID class
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         ep_num          - endpoint num 
**         app_buff        - buffer to send
**         size            - length of the transfer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define USB_Class_HID_Periodic_Task USB_Class_Periodic_Task
#endif
/* EOF */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/


