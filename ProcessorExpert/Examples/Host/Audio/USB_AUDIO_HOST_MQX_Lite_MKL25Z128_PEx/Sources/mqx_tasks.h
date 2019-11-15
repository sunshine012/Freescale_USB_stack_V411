/** ###################################################################
**     Filename    : mqx_tasks.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-21, 11:29, # CodeGen: 59
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         App_Task  - void App_Task(void* task_init_data);
**         Khci_Task - void Khci_Task(void* task_init_data);
**
**     Copyright Freescale Semiconductor, Inc. All Rights Reserved.
** ###################################################################*/

#ifndef __mqx_tasks_H
#define __mqx_tasks_H
/* MODULE mqx_tasks */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "UART.h"
#include "IO1.h"
#include "usb_host.h"
#include "USB_LDD.h"
#include "MQX1.h"
#include "SystemTimer1.h"
#include "PWM.h"
#include "PIT0.h"
#include "PTA4.h"
#include "PE_LDD.h"



void App_Task(uint32_t task_init_data);
/*
** ===================================================================
**     Event       :  App_Task (module mqx_tasks)
**
**     Component   :  Task1 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/



void Khci_Task(uint32_t task_init_data);
/*
** ===================================================================
**     Event       :  Khci_Task (module mqx_tasks)
**
**     Component   :  Task2 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/


/* END mqx_tasks */
#endif /* __mqx_tasks_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/