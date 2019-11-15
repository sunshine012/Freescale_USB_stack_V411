/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : task_template_list.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Component 01.083, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-11-20, 10:55, # CodeGen: 16
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#include "task_template_list.h"
#include "mqx_tasks.h"

#define TASK_TEMPLATE_LIST_END         {0, 0, 0, 0, 0, 0, 0}

/* MQX task template list */
const TASK_TEMPLATE_STRUCT MQX_template_list[] =
{
  /* Task: Task1 */
  {
  /* Task number                      */  TASK1_TASK,
  /* Entry point                      */  (TASK_FPTR)Task1_task,
  /* Stack size                       */  TASK1_TASK_STACK_SIZE,
  /* Task priority                    */  9U,
  /* Task name                        */  "task1",
  /* Task attributes                  */  (MQX_AUTO_START_TASK),
  /* Task parameter                   */  (uint32_t)(0)
  },
  TASK_TEMPLATE_LIST_END
};

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
