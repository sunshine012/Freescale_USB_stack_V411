/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Vectors.c
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCLQ10
**     Version     : Component 01.000, Driver 01.04, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-23, 14:59, # CodeGen: 7
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

  #include "Cpu.h"
  #include "MQX1.h"
  #include "SystemTimer1.h"
  #include "usb_device.h"
  #include "USB_LDD.h"
  #include "Events.h"
  #include "mqx_tasks.h"


  /* ISR prototype */
  extern uint32_t __SP_INIT;
  extern void __thumb_startup( void );
  
  
  /*lint -esym(765,__vect_table) Disable MISRA rule (8.10) checking for symbols (__vect_table). Definition of the interrupt vector table placed by linker on a predefined location. */
  /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. Need to explicitly cast pointers to the general ISR for Interrupt vector table */
  
  __attribute__ ((section (".vectortable"))) const tVectorTable __vect_table = { /* Interrupt vector table */
  
    /* ISR name                             No. Address      Pri Name                          Description */
    &__SP_INIT,                        /* 0x00  0x00000000   -   ivINT_Initial_Stack_Pointer   used by PE */
    {
    (tIsrFunc)&__boot,                 /* 0x01  0x00000004   -   ivINT_Initial_Program_Counter used by PE */
    (tIsrFunc)&Cpu_INT_NMIInterrupt,   /* 0x02  0x00000008   -2   ivINT_NMI                     used by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x03  0x0000000C   -1   ivINT_Hard_Fault              unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x04  0x00000010   -   ivINT_Mem_Manage_Fault        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x05  0x00000014   -   ivINT_Bus_Fault               unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x06  0x00000018   -   ivINT_Usage_Fault             unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x07  0x0000001C   -   ivINT_Reserved7               unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x08  0x00000020   -   ivINT_Reserved8               unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x09  0x00000024   -   ivINT_Reserved9               unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0A  0x00000028   -   ivINT_Reserved10              unused by PE */
    (tIsrFunc)&_svc_handler,           /* 0x0B  0x0000002C   -   ivINT_SVCall                  used by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0C  0x00000030   -   ivINT_DebugMonitor            unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0D  0x00000034   -   ivINT_Reserved13              unused by PE */
    (tIsrFunc)&_pend_svc,              /* 0x0E  0x00000038   -   ivINT_PendableSrvReq          used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x0F  0x0000003C   8   ivINT_SysTick                 used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x10  0x00000040   -   ivINT_DMA0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x11  0x00000044   -   ivINT_DMA1                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x12  0x00000048   -   ivINT_DMA2                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x13  0x0000004C   -   ivINT_DMA3                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x14  0x00000050   -   ivINT_DMA4                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x15  0x00000054   -   ivINT_DMA5                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x16  0x00000058   -   ivINT_DMA6                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x17  0x0000005C   -   ivINT_DMA7                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x18  0x00000060   -   ivINT_DMA8                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x19  0x00000064   -   ivINT_DMA9                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x1A  0x00000068   -   ivINT_DMA10                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x1B  0x0000006C   -   ivINT_DMA11                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x1C  0x00000070   -   ivINT_DMA12                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x1D  0x00000074   -   ivINT_DMA13                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x1E  0x00000078   -   ivINT_DMA14                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x1F  0x0000007C   -   ivINT_DMA15                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x20  0x00000080   -   ivINT_DMA_Error               used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x21  0x00000084   -   ivINT_MCM                     used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x22  0x00000088   -   ivINT_FTFL                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x23  0x0000008C   -   ivINT_Read_Collision          used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x24  0x00000090   -   ivINT_LVD_LVW                 used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x25  0x00000094   -   ivINT_LLW                     used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x26  0x00000098   -   ivINT_Watchdog                used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x27  0x0000009C   -   ivINT_RNG                     used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x28  0x000000A0   -   ivINT_I2C0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x29  0x000000A4   -   ivINT_I2C1                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x2A  0x000000A8   -   ivINT_SPI0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x2B  0x000000AC   -   ivINT_SPI1                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x2C  0x000000B0   -   ivINT_SPI2                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x2D  0x000000B4   -   ivINT_Reserved45              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x2E  0x000000B8   -   ivINT_Reserved46              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x2F  0x000000BC   -   ivINT_Reserved47              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x30  0x000000C0   -   ivINT_Reserved48              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x31  0x000000C4   -   ivINT_Reserved49              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x32  0x000000C8   -   ivINT_Reserved50              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x33  0x000000CC   -   ivINT_Reserved51              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x34  0x000000D0   -   ivINT_Reserved52              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x35  0x000000D4   -   ivINT_Reserved53              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x36  0x000000D8   -   ivINT_Reserved54              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x37  0x000000DC   -   ivINT_Reserved55              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x38  0x000000E0   -   ivINT_Reserved56              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x39  0x000000E4   -   ivINT_Reserved57              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x3A  0x000000E8   -   ivINT_Reserved58              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x3B  0x000000EC   -   ivINT_Reserved59              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x3C  0x000000F0   -   ivINT_Reserved60              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x3D  0x000000F4   -   ivINT_UART0_RX_TX             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x3E  0x000000F8   -   ivINT_UART0_ERR               used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x3F  0x000000FC   -   ivINT_UART1_RX_TX             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x40  0x00000100   -   ivINT_UART1_ERR               used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x41  0x00000104   -   ivINT_UART2_RX_TX             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x42  0x00000108   -   ivINT_UART2_ERR               used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x43  0x0000010C   -   ivINT_UART3_RX_TX             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x44  0x00000110   -   ivINT_UART3_ERR               used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x45  0x00000114   -   ivINT_UART4_RX_TX             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x46  0x00000118   -   ivINT_UART4_ERR               used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x47  0x0000011C   -   ivINT_UART5_RX_TX             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x48  0x00000120   -   ivINT_UART5_ERR               used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x49  0x00000124   -   ivINT_ADC0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x4A  0x00000128   -   ivINT_ADC1                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x4B  0x0000012C   -   ivINT_CMP0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x4C  0x00000130   -   ivINT_CMP1                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x4D  0x00000134   -   ivINT_CMP2                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x4E  0x00000138   -   ivINT_FTM0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x4F  0x0000013C   -   ivINT_FTM1                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x50  0x00000140   -   ivINT_FTM2                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x51  0x00000144   -   ivINT_CMT                     used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x52  0x00000148   -   ivINT_RTC                     used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x53  0x0000014C   -   ivINT_Reserved83              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x54  0x00000150   -   ivINT_PIT0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x55  0x00000154   -   ivINT_PIT1                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x56  0x00000158   -   ivINT_PIT2                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x57  0x0000015C   -   ivINT_PIT3                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x58  0x00000160   -   ivINT_PDB0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x59  0x00000164   8   ivINT_USB0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x5A  0x00000168   -   ivINT_USBDCD                  used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x5B  0x0000016C   -   ivINT_ENET_1588_Timer         used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x5C  0x00000170   -   ivINT_ENET_Transmit           used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x5D  0x00000174   -   ivINT_ENET_Receive            used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x5E  0x00000178   -   ivINT_ENET_Error              used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x5F  0x0000017C   -   ivINT_I2S0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x60  0x00000180   -   ivINT_SDHC                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x61  0x00000184   -   ivINT_DAC0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x62  0x00000188   -   ivINT_DAC1                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x63  0x0000018C   -   ivINT_TSI0                    used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x64  0x00000190   -   ivINT_MCG                     used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x65  0x00000194   -   ivINT_LPTimer                 used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x66  0x00000198   -   ivINT_LCD                     used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x67  0x0000019C   -   ivINT_PORTA                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x68  0x000001A0   -   ivINT_PORTB                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x69  0x000001A4   -   ivINT_PORTC                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x6A  0x000001A8   -   ivINT_PORTD                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x6B  0x000001AC   -   ivINT_PORTE                   used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x6C  0x000001B0   -   ivINT_Reserved108             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x6D  0x000001B4   -   ivINT_Reserved109             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x6E  0x000001B8   -   ivINT_Reserved110             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x6F  0x000001BC   -   ivINT_Reserved111             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x70  0x000001C0   -   ivINT_Reserved112             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x71  0x000001C4   -   ivINT_Reserved113             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x72  0x000001C8   -   ivINT_Reserved114             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x73  0x000001CC   -   ivINT_Reserved115             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x74  0x000001D0   -   ivINT_Reserved116             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x75  0x000001D4   -   ivINT_Reserved117             used by PE */
    (tIsrFunc)&_int_kernel_isr,        /* 0x76  0x000001D8   -   ivINT_Reserved118             used by PE */
    (tIsrFunc)&_int_kernel_isr         /* 0x77  0x000001DC   -   ivINT_Reserved119             used by PE */
    }
  };
  /*lint -restore Enable MISRA rule (11.4) checking. */
  

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
