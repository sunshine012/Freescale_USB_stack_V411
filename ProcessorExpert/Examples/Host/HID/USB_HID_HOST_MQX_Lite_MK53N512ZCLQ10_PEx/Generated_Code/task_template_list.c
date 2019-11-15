/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : task_template_list.c
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCLQ10
**     Version     : Component 01.083, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-14, 17:12, # CodeGen: 2
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
  /* Task: App_Task */
  {
  /* Task number                      */  APP_TASK_TASK,
  /* Entry point                      */  (TASK_FPTR)App_Task,
  /* Stack size                       */  APP_TASK_TASK_STACK_SIZE,
  /* Task priority                    */  9U,
  /* Task name                        */  "app_task",
  /* Task attributes                  */  (MQX_AUTO_START_TASK),
  /* Task parameter                   */  (uint32_t)(0)
  },
  /* Task: Khci_Task */
  {
  /* Task number                      */  KHCI_TASK_TASK,
  /* Entry point                      */  (TASK_FPTR)Khci_Task,
  /* Stack size                       */  KHCI_TASK_TASK_STACK_SIZE,
  /* Task priority                    */  8U,
  /* Task name                        */  "khci_task",
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
