/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MQX1.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVLQ10
**     Version     : Component 01.083, Driver 01.00, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-26, 09:26, # CodeGen: 22
**     Abstract    :
**         MQX Lite RTOS Adapter component.
**     Settings    :
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE MQX1. */

#include "MQX1.h"
#include "mqx_tasks.h"



/* Task stacks definition */
uint8_t App_Task_task_stack[APP_TASK_TASK_STACK_SIZE];
uint8_t Khci_Task_task_stack[KHCI_TASK_TASK_STACK_SIZE];

/* Task stacks array of pointers */
const uint8_t * mqx_task_stack_pointers[] = {
/* "App_Task" task                     */  App_Task_task_stack,
/* "Khci_Task" task                    */  Khci_Task_task_stack,
/* Stack array end                     */  NULL
};

/* Kernel Data */
volatile KERNEL_DATA_STRUCT            mqx_kernel_data;
#define __KERNEL_DATA_START            (pointer)(&mqx_kernel_data)
#define __KERNEL_DATA_END              (pointer)((uchar_ptr)&mqx_kernel_data + sizeof(mqx_kernel_data))

/* Task ready queue */
READY_Q_STRUCT                         mqx_static_ready_queue[MQX_READY_QUEUE_ITEMS];

/* Table of 'C' handlers for interrupts. */
INTERRUPT_TABLE_STRUCT                 mqx_static_isr_table[MQX_INTERRUPT_TABLE_ITEMS];


/* Interrupt stack */
uint8_t mqx_interrupt_stack[MQX_INTERRUPT_STACK_SIZE + PSP_STACK_ALIGNMENT + 1];
/* Idle task stack */
uint8_t mqx_idle_task_stack[sizeof(TD_STRUCT) + PSP_IDLE_STACK_SIZE + PSP_STACK_ALIGNMENT + 1];
/* System stack */
uint8_t mqx_system_stack[PSP_MINSTACKSIZE + PSP_STACK_ALIGNMENT + 1];

/* MQX Lite initialization structure */
const MQXLITE_INITIALIZATION_STRUCT  MQX_init_struct =
{
/* PROCESSOR NUMBER                 */  1,
/* START OF KERNEL MEMORY           */  __KERNEL_DATA_START,
/* END OF KERNEL MEMORY             */  __KERNEL_DATA_END,
/* MQX_HARDWARE_INTERRUPT_LEVEL_MAX */  2,
/* INTERRUPT STACK SIZE             */  sizeof(mqx_interrupt_stack),
/* INTERRUPT STACK LOCATION         */  mqx_interrupt_stack,
/* IDLE_TASK STACK SIZE             */  sizeof(mqx_idle_task_stack),
/* IDLE_TASK STACK_LOCATION         */  mqx_idle_task_stack,
/* TASK TEMPLATE LIST               */  (TASK_TEMPLATE_STRUCT_PTR)&MQX_template_list[0]
};

/*
** ===================================================================
**     Method      :  MQX1_OnCounterRestart (component MQXLite)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void SystemTimer1_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
    _time_notify_kernel();
}


/* Function returns number of ticks per second for system timer */
uint32_t  SystemTimer1_GetTicsPerSecond(LDD_TDeviceData *DeviceDataPtr)
{
    uint32_t input_frequency;
    uint32_t period_ticks;

    /* Parameter DeviceDataPtr is not used, suppress unused argument warning */
    (void)DeviceDataPtr;
    input_frequency = SystemTimer1_GetInputFrequency(NULL);
    SystemTimer1_GetPeriodTicks(NULL, &period_ticks);
    return input_frequency / (period_ticks);
}



/* END MQX1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
