/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usbprv.h
**     Project   : ProcessorExpert
**     Processor : MKL25Z128LK4
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 14:45, # CodeGen: 15
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __usbprv_h__
#define __usbprv_h__ 1

#define USB_lock()                           asm(" CPSID i");
#define USB_unlock()                         asm(" CPSIE i");

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
#endif
#define USB_mem_free(ptr)                     free(ptr)
#define USB_mem_zero(ptr,n)                   memset((ptr),(0),(n))
#define USB_mem_copy(src,dst,n)               memcpy((dst),(src),(n))

#define USB_uncached                              volatile

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
