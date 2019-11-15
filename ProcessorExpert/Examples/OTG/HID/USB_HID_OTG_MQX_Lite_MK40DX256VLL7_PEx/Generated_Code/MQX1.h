/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MQX1.h
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Version     : Component 01.083, Driver 01.00, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-28, 10:27, # CodeGen: 13
**     Abstract    :
**         MQX Lite RTOS Adapter component.
**     Settings    :
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __MQX1_H
#define __MQX1_H

/* MODULE MQX1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */
#include "SystemTimer1.h"
#include "task_template_list.h"
/* MQX Lite include files */
#include "mqxlite.h"
#include "mqxlite_prv.h"


/* Path to MQX Lite source files */
#define MQX_PATH   "D:/Freescale/CW MCU v10.3/MCU/ProcessorExpert/lib/mqxlite/V1.0.1/"

void      SystemTimer1_OnCounterRestart(LDD_TUserData *UserDataPtr);
uint32_t  SystemTimer1_GetTicsPerSecond(LDD_TDeviceData *DeviceDataPtr);


/* MQX Lite entrypoint */
void __boot(void);
/* SVC handler - called after SVC instruction */
void _svc_handler(void);
/* PendSV handler - task switch functionality */
void _pend_svc(void);

/* MQX Lite adapter system timer functions */
#define MQXLITE_SYSTEM_TIMER_INIT(param)   \
            SystemTimer1_Init(param)
#define MQXLITE_SYSTEM_TIMER_START(param)  \
            SystemTimer1_Enable(param)
#define MQXLITE_SYSTEM_TIMER_GET_INPUT_FREQUENCY(param)        \
            SystemTimer1_GetInputFrequency(param)
#define MQXLITE_SYSTEM_TIMER_GET_PERIOD_TICKS(param, value)    \
            SystemTimer1_GetPeriodTicks(param, value)
#define MQXLITE_SYSTEM_TIMER_SET_PERIOD_TICKS(param, value)    \
            SystemTimer1_SetPeriodTicks(param, value)
#define MQXLITE_SYSTEM_TIMER_GET_COUNTER_VALUE(param)          \
            SystemTimer1_GetCounterValue(param)
#define MQXLITE_SYSTEM_TIMER_GET_TICS_PER_SECOND(param)        \
            SystemTimer1_GetTicsPerSecond(param)



/* Task stacks declarations */
extern uint8_t Device_App_Task_task_stack[DEVICE_APP_TASK_TASK_STACK_SIZE];
extern uint8_t Host_App_Task_task_stack[HOST_APP_TASK_TASK_STACK_SIZE];
extern uint8_t OTG_App_Task_task_stack[OTG_APP_TASK_TASK_STACK_SIZE];

/* MQX Lite init structure and task template list */
extern const MQXLITE_INITIALIZATION_STRUCT       MQX_init_struct;
extern const TASK_TEMPLATE_STRUCT                MQX_template_list[];


/* MQX Lite initialization function */
#define PEX_RTOS_INIT()  (_mqxlite_init((MQXLITE_INITIALIZATION_STRUCT_PTR) &MQX_init_struct))
/* MQX Lite start function */
#define PEX_RTOS_START() (_mqxlite())


/* The first interrupt vector that the application wants to have a 'C' ISR for.    */
#define FIRST_INTERRUPT_VECTOR_USED    (INT_SysTick)
/* The last interrupt vector that the application wants to handle. */
#define LAST_INTERRUPT_VECTOR_USED     (INT_PORTC)
#define MQX_INTERRUPT_TABLE_ITEMS      (LAST_INTERRUPT_VECTOR_USED - FIRST_INTERRUPT_VECTOR_USED + 1)
/* The table of 'C' handlers for interrupts. */
extern INTERRUPT_TABLE_STRUCT          mqx_static_isr_table[MQX_INTERRUPT_TABLE_ITEMS];

/* MQX system stack */
extern uint8_t mqx_system_stack[];

/* Task ready queue */
#define MQX_IDLE_TASK_PRIORITY         (13)
#define MQX_READY_QUEUE_ITEMS          (MQX_IDLE_TASK_PRIORITY + 1)
extern READY_Q_STRUCT                  mqx_static_ready_queue[MQX_READY_QUEUE_ITEMS];

/* Task stacks array of pointers */
extern const uint8_t * mqx_task_stack_pointers[];



/* END MQX1. */

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
