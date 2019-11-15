/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PE_Types.h
**     Project     : ProcessorExpert
**     Processor   : MCF51JF128VLH
**     Component   : PE_Types
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2012-11-19, 11:05, # CodeGen: 12
**     Abstract    :
**         PE_Types.h - contains definitions of basic types,
**         register access macros and hardware specific macros
**         which can be used in user application.
**     Settings    :
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __PE_Types_H
#define __PE_Types_H

/* Standard ANSI C types */
#include <stdint.h>

#ifndef FALSE
  #define  FALSE  0x00u                /* Boolean value FALSE. FALSE is defined always as a zero value. */
#endif
#ifndef TRUE
  #define  TRUE   0x01u                /* Boolean value TRUE. TRUE is defined always as a non zero value. */
#endif

#ifndef NULL
  #define  NULL   0x00u
#endif

/* PE types definition */
#ifndef __cplusplus
typedef unsigned char           bool;
#endif
typedef unsigned char           byte;
typedef unsigned short          word;
typedef unsigned long           dword;
typedef unsigned long long      dlong;
typedef unsigned char           TPE_ErrCode;
#ifndef TPE_Float
typedef float                   TPE_Float;
#endif

/* Other basic data types */
typedef signed char             int8;
typedef signed short int        int16;
typedef signed long int         int32;

typedef unsigned char           uint8;
typedef unsigned short int      uint16;
typedef unsigned long int       uint32;


/**********************************************************/
/* Uniform multiplatform 8-bits peripheral access macros */
/**********************************************************/

/* Enable maskable interrupts */
/*lint -save  -esym(961,19.13) Disable MISRA rule (19.13) checking. */
#define __EI()\
 do {\
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */\
   asm(move.w SR,D0); \
   asm(andi.l #0xF8FF,D0); \
   asm(move.w D0,SR); \
  /*lint -restore Enable MISRA rule (1.1) checking. */\
 } while(0)
/*lint -restore  +esym(961,19.13) Enable MISRA rule (19.13) checking. */

/* Disable maskable interrupts */
/*lint -save  -esym(961,19.13) Disable MISRA rule (19.13) checking. */
#define __DI() \
 do {\
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */\
   asm(move.w SR,D0); \
   asm(ori.l #0x0700,D0); \
   asm(move.w D0,SR); \
  /*lint -restore Enable MISRA rule (1.1) checking. */\
 } while(0)
/*lint -restore  +esym(961,19.13) Enable MISRA rule (19.13) checking. */


/* Save status register and disable interrupts */
/*lint -save  -esym(961,19.13) Disable MISRA rule (19.13) checking. */
#define EnterCritical() \
 do {\
   if (++SR_lock == 1u) {\
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */\
     asm(move.w SR,D0); \
     asm(move.w D0,SR_reg); \
     asm(ori.l #1792,D0); \
     asm(move.w D0,SR); \
  /*lint -restore Enable MISRA rule (1.1) checking. */\
   }\
 } while(0)
/*lint -restore  +esym(961,19.13) Enable MISRA rule (19.13) checking. */

/* Restore status register  */
#define ExitCritical() \
 do {\
   if (--SR_lock == 0u) { \
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */\
     asm(move.w SR_reg,D0); \
     asm(move.w D0,SR); \
  /*lint -restore Enable MISRA rule (1.1) checking. */\
   }\
 } while(0)


#define PE_DEBUGHALT() \
  /*lint -save  -e586 -e950 Disable MISRA rule (2.1,1.1) checking. */\
    asm (HALT) \
  /*lint -restore Enable MISRA rule (2.1,1.1) checking. */

#define PE_NOP() \
  /*lint -save  -e586 -e950 Disable MISRA rule (2.1,1.1) checking. */\
    asm (NOP) \
  /*lint -restore Enable MISRA rule (2.1,1.1) checking. */


/*lint -save  -esym(961,19.13) Disable MISRA rule (19.13) checking. */
#define PE_STOP() \
  /*lint -save  -e586 -e950 Disable MISRA rule (2.1,1.1) checking. */\
  asm(stop #0x2000) \
  /*lint -restore Enable MISRA rule (2.1,1.1) checking. */
/*lint -restore  +esym(961,19.13) Enable MISRA rule (19.13) checking. */


/* Interrupt definition template */
#if !defined(PE_ISR)
  #define PE_ISR(ISR_name) __interrupt void ISR_name(void)
#endif

#endif /* __PE_Types_H */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
