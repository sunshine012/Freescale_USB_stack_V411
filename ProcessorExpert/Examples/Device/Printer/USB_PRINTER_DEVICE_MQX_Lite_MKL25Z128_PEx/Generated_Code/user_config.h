/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : user_config.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Component 01.050, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-09-15, 14:04, # CodeGen: 8
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/


#ifndef __user_config_h__
#define __user_config_h__


/* Macros generated by the MQXLite component */
#define MQX_CPU     PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KL2X, 0x0F)

#define MQX_MQXLITE                    1

#define CORTEX_M0_CORE                 1

/* Synchronization object settings */
#define MQX_USE_SEMAPHORES             1

#define MQX_USE_MUTEXES                0

#define MQX_USE_LWEVENTS               0

/* 
 * Idle task settings 
 * Kinetis  : MQX_USE_IDLE_TASK must be set to 1 
 */
#define MQX_USE_IDLE_TASK              1

/* Interrupt settings */
#define MQX_ROM_VECTORS                1



/*****************************************************************************
 * Build options (instead of build options in project settings)
 */
/* ARM GNUC compiler */


#endif /* __user_config_h__ */


/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.02]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/