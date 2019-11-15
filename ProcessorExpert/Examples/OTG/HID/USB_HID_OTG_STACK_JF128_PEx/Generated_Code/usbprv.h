/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usbprv.h
**     Project   : ProcessorExpert
**     Processor : MCF51JF128_64
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef __usbprv_h__
#define __usbprv_h__ 1

#define USB_lock()                           asm { move.w SR,D0; ori.l #0x0700,D0; move.w D0,SR;  }
#define USB_unlock()                         asm { move.w SR,D0; andi.l #0xF8FF,D0; move.w D0,SR;  }

#define USB_dcache_invalidate()
#define USB_dcache_invalidate_line(p)
/* Based on the targets it should be modified, for coldfire it is MBYTES */
#define USB_dcache_invalidate_mlines(p,n)
#define USB_dcache_flush_line(p)
/* Based on the targets it should be modified, for coldfire it is MBYTES */
#define USB_dcache_flush_mlines(p,n)

#define USB_mem_alloc_uncached(n)             malloc(n)
#define USB_mem_alloc_uncached_zero(n)        USB_mem_alloc_zero(n);

#define USB_mem_alloc_zero(n)                 malloc(n)
#define USB_mem_free(ptr)                     free(ptr)
#define USB_mem_zero(ptr,n)                   memset((ptr),(0),(n))
#define USB_mem_copy(src,dst,n)               memcpy((dst),(src),(n))

#define USB_uncached                              volatile

#endif

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
