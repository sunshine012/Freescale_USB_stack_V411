/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CsIO1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ConsoleIO
**     Version     : Component 01.001, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-28, 11:17, # CodeGen: 8
**     Abstract    :
**         This component generates low-level methods for redirecting console I/O to the selected UART.
**         These methods are typically used by printf()/scanf() methods.
**     Settings    :
**          Component name                                 : CsIO1
**          Serial_LDD_Link                                : ConsoleIO_Serial_LDD
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE CsIO1. */

#include "IO_Map.h"
#include "stdio.h"
#include <stdarg.h>
#include "UART0_PDD.h"
/*
** ===================================================================
**     Method      :  CsIO1___read_console (component ConsoleIO)
**
**     Description :
**         __read_console
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
int __read_console(__file_handle handle, unsigned char* buffer, size_t * count)
{
  size_t i;

  (void)handle;                        /* Parameter is not used, suppress unused argument warning */
  for (i = 0; i < *count; i++) {
    /* wait until new char is received */
    while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_RDRF_MASK) == 0) {};

    /* Save a character of the UARTx device into the receive buffer */
    buffer[i] = (unsigned char)UART0_PDD_GetChar8(UART0_BASE_PTR);
  }
  return (__no_io_error);
}

/*
** ===================================================================
**     Method      :  CsIO1___write_console (component ConsoleIO)
**
**     Description :
**         __write_console
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
int __write_console(__file_handle handle, unsigned char* buffer, size_t* count)
{
size_t i;

  (void)handle;                        /* Parameter is not used, suppress unused argument warning */
  for (i = 0; i < *count; i++) {
    /* Send '\r' before each '\n'. */
    if (buffer[i] == '\n') {
      /* Wait until UART is ready to write a next character into output buffer */
      while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_TDRE_MASK) == 0) {};
      /* Save a character into the transmit buffer of the UART0 device */
      UART0_PDD_PutChar8(UART0_BASE_PTR, '\r');
    }
    /* Save a character into the transmit buffer of the UART0 device */
    while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_TDRE_MASK) == 0) {};
    /* Wait until UART is ready for saving a next character into the transmit buffer */
    UART0_PDD_PutChar8(UART0_BASE_PTR, (unsigned char)buffer[i]);
  }
  /* Wait until last character is sent */
  while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_TDRE_MASK) == 0) {};
  return(__no_io_error);
}

/*
** ===================================================================
**     Method      :  CsIO1___close_console (component ConsoleIO)
**
**     Description :
**         __close_console
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
int __close_console(__file_handle handle)
{
  (void)handle;                        /* Parameter is not used, suppress unused argument warning */
  return(__no_io_error);
}

/* END CsIO1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
