/** ###################################################################
**     THIS USER MODULE IS GENERATED BY THE TOOL. MODIFY IT FOLLOW COMMENTS BELOW.
**     Filename  : usb_classes.h
**     Project   : ProcessorExpert
**     Processor : MK60N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-12-26, 09:26, # CodeGen: 22
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef __usb_classes_h__
#define __usb_classes_h__
/* End of header definition, DO NOT MODIFY LINES ABOVE */
/* Write your own includes here ...*/
#define QUEUE_SIZE               4
/* Define the representation of a circular queue */
typedef struct _MASS_QUEUE_STRUCT
{
   pointer     ELEMENTS[QUEUE_SIZE]; /* storage for the queue*/
   uint_32     COUNT;
   uint_8      FIRST;         /* index of the first element in the queue*/
   uint_8      LAST;          /* index of the last element in the queue*/
} MASS_QUEUE_STRUCT, _PTR_ MASS_QUEUE_STRUCT_PTR;

/* DO NOT MODIFY LINES BELOW */
typedef struct {
    GENERAL_CLASS                             G;
/* End <struct_begin_1>, DO NOT MODIFY LINES ABOVE */
/* Write your own fields of struct 1 below */
    _usb_pipe_handle                      CONTROL_PIPE;      /* control pipe handle*/
      _usb_pipe_handle                    BULK_IN_PIPE;      /* Bulk in pipe handle*/
      _usb_pipe_handle                    BULK_OUT_PIPE;     /* Bulk out pipe handle*/
      MASS_QUEUE_STRUCT                   QUEUE;             /* structure that queues requests*/
      uint_8                              INTERFACE_NUM;     /* interface number*/
      uint_8                              ALTERNATE_SETTING; /* Alternate setting*/
/* Begin of <struct_end_1>, DO NOT MODIFY LINES BELOW */
} USB_CLASS_MSD_HOST_INTF_STRUCT, _PTR_ USB_CLASS_MSD_HOST_INTF_STRUCT_PTR;
/* DO NOT MODIFY LINES ABOVE*/

/* Begin of <fuction_prototype>, DO NOT MODIFY LINES BELOW */
extern void usb_class_MSD_Host_init(PIPE_BUNDLE_STRUCT_PTR, CLASS_CALL_STRUCT_PTR);
/* End <fuction_prototype>, DO NOT MODIFY LINES ABOVE */

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

