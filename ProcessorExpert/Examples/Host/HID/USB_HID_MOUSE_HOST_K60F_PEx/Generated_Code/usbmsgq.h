/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usbmsgq.h
**     Project   : ProcessorExpert
**     Processor : MK60FN1M0LQ15
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:32, # CodeGen: 26
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __usb_msq_h__
#define __usb_msq_h__

#include "psptypes.h"
#include "khci.h"

/*--------------------------------------------------------------------------*/
/*
**                            MACRO DEFINITIONS
*/

/* control bits for lwmsgq_send */

/* Error messages */
#define USB_MSGQ_OK                           0x00
#define USB_MSGQ_SEND_ERROR                   0x01
#define USB_MSGQ_RECEIVE_ERROR                0x02
#define USB_MSGQ_INIT_ERROR                   0x03

/* QUEUE status */
#define USB_MSGQ_VALID                        0x00
#define USB_MSGQ_FULL                         0x01
#define USB_MSGQ_EMPTY                        0x02
#define USB_MSGQ_TIMEOUT                      0x03

/*--------------------------------------------------------------------------*/
/*
**                            DATATYPE DECLARATIONS
*/

/*---------------------------------------------------------------------
**
** LWMSGQ STRUCTURE
**
** This structure used to store a circular long word queue.
** The structure must be the LAST if it is included into another
** data structure, as the queue falls off of the end of
** this structure.
*/

typedef struct usb_msgq_element
{
    TR_MSG_STRUCT        MESSAGE_DATA;
    struct usb_msgq_element * NEXT;
    struct usb_msgq_element * PREV;
}USB_MSGQ_ELEMENT, _PTR_ USB_MSGQ_ELEMENT_PTR;
typedef struct usb_msgq_struct
{
    /* A Queue of task descriptors waiting to write */
    USB_MSGQ_ELEMENT_PTR    HEAD;

    /* A Queue of task descriptors waiting to read */
    USB_MSGQ_ELEMENT_PTR    TAIL;

    /* The validity check field */
    uint_32    QUEUE_STATUS;

    /* The size of the message chunk in the queue in _mqx_max_type's */
    uint_32    SIZE;

    /* The maximum number of msgs for the queue, as specified in
    * initialization of the queue.
    */
    uint_32     MAX_SIZE;

    /* The current number of messages in the queue. */
    uint_32    CURRENT_SIZE;

} USBMSGQ_STRUCT, _PTR_ USBMSGQ_STRUCT_PTR;

/*--------------------------------------------------------------------------*/
/*
** FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

    uint_32 _usb_msgq_init(uint_32, uint_32);
    uint_32 _usb_msgq_send(int*);
    uint_32 _usb_msgq_receive(int*);

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
