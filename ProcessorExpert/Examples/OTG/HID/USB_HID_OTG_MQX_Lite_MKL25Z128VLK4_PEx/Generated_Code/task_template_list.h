/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : task_template_list.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Component 01.083, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-05, 15:46, # CodeGen: 10
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/


#ifndef __task_template_list_h__
#define __task_template_list_h__

/* MQX Lite task IDs */
#define DEVICE_APP_TASK_TASK 1U
#define HOST_APP_TASK_TASK   2U
#define OTG_APP_TASK_TASK    3U

/* MQX Lite task stack sizes */
#define DEVICE_APP_TASK_TASK_STACK_SIZE (sizeof(TD_STRUCT) + 20 + PSP_STACK_ALIGNMENT + 1)
#define HOST_APP_TASK_TASK_STACK_SIZE (sizeof(TD_STRUCT) + 1024 + PSP_STACK_ALIGNMENT + 1)
#define OTG_APP_TASK_TASK_STACK_SIZE (sizeof(TD_STRUCT) + 800 + PSP_STACK_ALIGNMENT + 1)


#endif /* __task_template_list_h__ */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
