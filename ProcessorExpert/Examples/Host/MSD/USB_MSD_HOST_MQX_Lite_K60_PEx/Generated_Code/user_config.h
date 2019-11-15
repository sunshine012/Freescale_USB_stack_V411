/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : user_config.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVLQ10
**     Version     : Component 01.083, Driver 01.00, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-26, 09:26, # CodeGen: 22
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __user_config_h__
#define __user_config_h__

/* MQX Lite version number */
#define MQX_LITE_VERSION               "V1.0.1"
#define MQX_LITE_VERSION_NUMBER        0x01000001

/* Selected MQX CPU type */
#define MQX_CPU              PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M4, \
                                         PSP_CPU_GROUP_KINETIS_K6X, \
                                         0x0F)

/* Component settings */
#define MQX_USE_SEMAPHORES             1
#define MQX_USE_LWEVENTS               1
#define MQX_USE_MUTEXES                0
#define MQX_USE_LWMSGQ                 1
#define MQX_USE_LWTIMER                0
#define MQX_KERNEL_LOGGING             0

/* Idle task settings */
#define MQX_USE_IDLE_TASK              1
#define MQX_ENABLE_LOW_POWER           0


/* Interrupt settings */
#define MQX_ROM_VECTORS                1
#define MQX_INTERRUPT_STACK_SIZE       256

/* PSP Settings */
#define PSP_HAS_FPU                    0


/* Additional settings can be defined in the property User Definitions > Definitions of the MQXLite RTOS component */

#endif /* __user_config_h__ */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
