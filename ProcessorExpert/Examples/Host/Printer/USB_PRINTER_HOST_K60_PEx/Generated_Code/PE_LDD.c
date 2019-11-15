/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PE_LDD.c.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVLQ10
**     Version     : Component 01.000, Driver 01.04, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-27, 10:02, # CodeGen: 23
**     Abstract    :
**
**     Settings    :
**
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE PE_LDD */

/* {Default RTOS Adapter} No RTOS includes */
/* {Default RTOS Adapter} No RTOS driver includes */

#include "PE_LDD.h"
#include "Cpu.h"

/*lint -esym(765,PE_PeripheralUsed,LDD_SetClockConfiguration,PE_CpuClockConfigurations,PE_FillMemory) Disable MISRA rule (8.10) checking for symbols (PE_PeripheralUsed,LDD_SetClockConfiguration,PE_CpuClockConfigurations,PE_FillMemory). */

/*
** ===========================================================================
** Array of initialized device structures of LDD components.
** ===========================================================================
*/
LDD_TDeviceData *PE_LDD_DeviceDataList[2] = {
    NULL,
    NULL
  };

/*
** ===========================================================================
** The array of clock frequencies in configured clock configurations.
** ===========================================================================
*/
const TCpuClockConfiguration PE_CpuClockConfigurations[CPU_CLOCK_CONFIG_NUMBER] = {
  /* Clock configuration 0 */
  {
    CPU_CORE_CLK_HZ_CONFIG_0,          /* Core clock frequency in clock configuration 0 */
    CPU_BUS_CLK_HZ_CONFIG_0,           /* Bus clock frequency in clock configuration 0 */
    CPU_FLEXBUS_CLK_HZ_CONFIG_0,       /* Flexbus clock frequency in clock configuration 0 */
    CPU_FLASH_CLK_HZ_CONFIG_0,         /* FLASH clock frequency in clock configuration 0 */
    CPU_USB_CLK_HZ_CONFIG_0,           /* USB clock frequency in clock configuration 0 */
    CPU_PLL_FLL_CLK_HZ_CONFIG_0,       /* PLL/FLL clock frequency in clock configuration 0 */
    CPU_MCGIR_CLK_HZ_CONFIG_0,         /* MCG internal reference clock frequency in clock configuration 0 */
    CPU_OSCER_CLK_HZ_CONFIG_0,         /* System OSC external reference clock frequency in clock configuration 0 */
    CPU_ERCLK32K_CLK_HZ_CONFIG_0,      /* External reference clock 32k frequency in clock configuration 0 */
    CPU_MCGFF_CLK_HZ_CONFIG_0          /* MCG fixed frequency clock */
  }
};

/*
** ===================================================================
**     Method      :  PE_FillMemory (component MK60N512LQ100)
**
**     Description :
**         Fill the memory area by specified value.
** ===================================================================
*/
void PE_FillMemory(register void* SourceAddressPtr, register uint8_t c, register uint32_t len)
{
  register uint8_t *ptr = (uint8_t*)SourceAddressPtr;

  if (len > 0U) {
    while (len--) {
      *ptr++ = c;
    }
  }
}

/*
** ===================================================================
**     Method      :  PE_PeripheralUsed (component MK60N512LQ100)
**
**     Description :
**         Returns the information whether a peripheral is allocated by 
**         PE or not.
** ===================================================================
*/
bool PE_PeripheralUsed(uint32_t PrphBaseAddress)
{
  bool result = FALSE;

  switch (PrphBaseAddress) {
    /* Base address allocated by peripheral(s) UART3 */
    case 0x4006D000UL:
    /* Base address allocated by peripheral(s) USB0 */
    case 0x40072000UL:
      result = TRUE;
      break;
    default:
      break;
  }
  return result;
}

/*
** ===================================================================
**     Method      :  LDD_SetClockConfiguration (component MK60N512LQ100)
**
**     Description :
**         This method changes the clock configuration of all LDD 
**         components in the project.
** ===================================================================
*/
void LDD_SetClockConfiguration(LDD_TClockConfiguration ClockConfiguration)
{
  (void)ClockConfiguration;            /* Parameter is not used, suppress unused argument warning */
  /* Just one clock configuration defined in CPU component. */
}

/* END PE_LDD */
