/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : types.h
**     Project   : ProcessorExpert
**     Processor : MK40N512LQ100
**     Component : USB_DEVICE_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-20, 22:45, # CodeGen: 1
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __TYPES_H
#define __TYPES_H
#include <stddef.h>

/******************************************************************************
 * Macro's
 *****************************************************************************/
#define LSB(a)      ((a)._byte.byte0)
#define MSB(a)      ((a)._byte.byte1)

#define LOWER_LSB(a)    ((a)._byte.byte0)
#define LOWER_MSB(a)    ((a)._byte.byte1)
#define UPPER_LSB(a)    ((a)._byte.byte2)
#define UPPER_MSB(a)    ((a)._byte.byte3)

#define _PTR_ *
#define _CODE_PTR_ *

#ifndef TRUE
#define FALSE 0
#define TRUE 1
#endif
#define USB_PACKET_SIZE  uint_32
#define BYTESWAP16(x)        (uint_16)((((x) & 0xFF00) >> 0x8) | (((x) & 0xFF) << 0x8))
#define BYTESWAP32(val)        (uint_32)((BYTESWAP16((uint_32)(val) & (uint_32)0xFFFF) << 0x10) |  \
                                        (BYTESWAP16((uint_32)((val) >> 0x10))))

#define ieee_htons(x)                BYTESWAP16(x)
#define ieee_htonl(x)                BYTESWAP32(x)
#define ieee_ntohs(x)                BYTESWAP16(x)
#define ieee_ntohl(x)                BYTESWAP32(x)

#define UNUSED(x)   (void)x;
#include "psptypes.h"
#endif

