
/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : psptypes.h
**     Project   : ProcessorExpert
**     Processor : MK53N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-29, 16:18, # CodeGen: 1
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __usb_psptypes_h__
#define __usb_psptypes_h__


/*--------------------------------------------------------------------------*/
/*
**                            STANDARD TYPES
*/

/*
**  The following typedefs allow us to minimize portability problems
**  due to the various C compilers (even for the same processor) not
**  agreeing on the sizes of "int"s and "short int"s and "longs".
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef  NULL
#undef  NULL
#endif
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((pointer)0)
#endif

#ifndef TRUE
#define FALSE 0
#define TRUE 1
#endif

#define LSB(a)      ((a)._byte.byte0)
#define MSB(a)      ((a)._byte.byte1)

#define LOWER_LSB(a)    ((a)._byte.byte0)
#define LOWER_MSB(a)    ((a)._byte.byte1)
#define UPPER_LSB(a)    ((a)._byte.byte2)
#define UPPER_MSB(a)    ((a)._byte.byte3)

#define _PTR_      *
#define _CODE_PTR_      *

#define BYTESWAP16(x)        (uint_16)((((x) & 0xFF00) >> 0x8) | (((x) & 0xFF) << 0x8))
#define BYTESWAP32(val)        (uint_32)((BYTESWAP16((uint_32)(val) & (uint_32)0xFFFF) << 0x10) |  \
    (BYTESWAP16((uint_32)((val) >> 0x10))))
#define ieee_htons(x)                BYTESWAP16(x)
#define ieee_htonl(x)                BYTESWAP32(x)
#define ieee_ntohs(x)                BYTESWAP16(x)
#define ieee_ntohl(x)                BYTESWAP32(x)

#define UNUSED(x)   (void)x;
#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
