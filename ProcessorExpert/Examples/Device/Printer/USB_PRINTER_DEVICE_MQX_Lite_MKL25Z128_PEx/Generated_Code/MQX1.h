/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MQX1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Component 01.050, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-10-19, 13:15, # CodeGen: 10
**     Abstract    :
**         MQX Lite RTOS Adapter component.
**     Settings    :
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
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


/* MQX Lite version number and path to source files */
#define MQX_LITE_VERSION               "1.0.0"
#define MQX_LITE_VERSION_NUMBER        0x01000000
#define MQX_PATH                       "C:/Freescale/CW MCU v10.3.140812/MCU/ProcessorExpert/lib/mqxlite/mqx_1_0/"

void      SystemTimer1_OnCounterRestart(LDD_TUserData *UserDataPtr);
uint32_t  SystemTimer1_GetTicsPerSecond(LDD_TDeviceData *DeviceDataPtr);

extern const MQXLITE_INITIALIZATION_STRUCT MQX_init_struct;

/* MQX Lite entrypoint */
void __boot(void);

/* SVC handler - called after SVC instruction */
void _svc_handler(void);

/* PendSV handler - task switch functionality */
void _pend_svc(void);




/* MQX Lite adapter system timer functions */
#define MQXLITE_RTOS_ADAPTER_SYSTEM_TIMER_INIT(param)   \
            SystemTimer1_Init(param)
#define MQXLITE_RTOS_ADAPTER_SYSTEM_TIMER_START(param)  \
            SystemTimer1_Enable(param)
#define MQXLITE_RTOS_ADAPTER_SYSTEM_TIMER_GET_INPUT_FREQUENCY(param)        \
            SystemTimer1_GetInputFrequency(param)
#define MQXLITE_RTOS_ADAPTER_SYSTEM_TIMER_GET_PERIOD_TICKS(param, value)    \
            SystemTimer1_GetPeriodTicks(param, value)
#define MQXLITE_RTOS_ADAPTER_SYSTEM_TIMER_SET_PERIOD_TICKS(param, value)    \
            SystemTimer1_SetPeriodTicks(param, value)
#define MQXLITE_RTOS_ADAPTER_SYSTEM_TIMER_GET_COUNTER_VALUE(param)          \
            SystemTimer1_GetCounterValue(param)
#define MQXLITE_RTOS_ADAPTER_SYSTEM_TIMER_GET_TICS_PER_SECOND(param)        \
            SystemTimer1_GetTicsPerSecond(param)



/* MQX Lite initialization function */
#define PEX_RTOS_INIT()  (_mqxlite_init((MQXLITE_INITIALIZATION_STRUCT_PTR) &MQX_init_struct))

/* MQX Lite start function */
#define PEX_RTOS_START() (_mqxlite())

/* Stacks */
extern uint8_t interrupt_stack[];
extern uint8_t sys_td_stack[];

/* Idle task stack setting */
#define MQX_IDLE_TASK_STACK_SIZE       1024
extern uint8_t idle_task_stack[MQX_IDLE_TASK_STACK_SIZE];


extern INTERRUPT_TABLE_STRUCT          mqx_static_isr_table[];
#define MQX_STATIC_ISR_TABLE_PTR       mqx_static_isr_table


/* Task stacks declarations */
extern uint8_t Task1_task_stack[TASK1_TASK_STACK_SIZE];

/* MQX Lite template list and init structure */
extern const TASK_TEMPLATE_STRUCT      MQX_template_list[];
extern const MQXLITE_INITIALIZATION_STRUCT MQX_init_struct;

/* The first interrupt allocated by Processor Expert */
#define FIRST_INTERRUPT_VECTOR_USED    (INT_SysTick)
/* The last interrupt allocated by Processor Expert */
#define LAST_INTERRUPT_VECTOR_USED     (INT_USB0)

#define MQX_INTERRUPT_TABLE_ITEMS      (LAST_INTERRUPT_VECTOR_USED - FIRST_INTERRUPT_VECTOR_USED + 1)

extern int __VECTOR_TABLE_START[];     /* defined in linker command file */
#define INTERRUPT_VECTOR_TABLE         (_mqx_max_type)(__VECTOR_TABLE_START)

extern const uint8_t * task_stack_pointers[];

/* END MQX1. */

#endif
/* ifndef __MQX1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.02]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
