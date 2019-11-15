/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Vectors.c
**     Project     : ProcessorExpert
**     Processor   : MCF51JF128VLH
**     Version     : Component 01.004, Driver 01.02, CPU db: 3.00.000
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2012-11-19, 13:47, # CodeGen: 62
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
  #include "AS1.h"
  #include "usb_hid.h"
  #include "usb_otg.h"
  #include "USB_LDD.h"
  #include "OTG_MAX3353_INT_PIN.h"
  #include "OTG_MAX3353.h"
  #include "Events.h"


  /* ISR prototype */
  typedef void (*const tIsrFunc)(void);
  typedef struct {
    uint32_t * __ptr;
    tIsrFunc __fun[0x72];
  } tVectorTable;
  
  extern uint32_t __SP_INIT[];
  extern void _startup( void );
  
  /* Pragma to place the interrupt vector table on correct location defined in linker file. */
  #pragma define_section vectortable ".vectortable" far_absolute R
  
  /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. Need to explicitly cast pointers to the general ISR for Interrupt vector table */
  
  static __declspec(vectortable) tVectorTable __vector_table = { /* Interrupt vector table */
    /* ISR name                             No. Address      Pri Name             Description */
    __SP_INIT,                         /* 0x00  0x00000000   -   ivINITSP         used by PE */
    {
    (tIsrFunc)_startup,                /* 0x01  0x00000004   -   ivINITPC         used by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x02  0x00000008   -   ivVaccerr        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x03  0x0000000C   -   ivVadderr        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x04  0x00000010   -   ivViinstr        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x05  0x00000014   -   ivVdiv_by_zero   unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x06  0x00000018   -   ivVReserved6     unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x07  0x0000001C   -   ivVReserved7     unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x08  0x00000020   -   ivVprviol        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x09  0x00000024   -   ivVtrace         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0A  0x00000028   -   ivVunilaop       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0B  0x0000002C   -   ivVunilfop       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0C  0x00000030   -   ivVdbgi          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0D  0x00000034   -   ivVReserved13    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0E  0x00000038   -   ivVferror        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x0F  0x0000003C   -   ivVReserved15    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x10  0x00000040   -   ivVReserved16    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x11  0x00000044   -   ivVReserved17    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x12  0x00000048   -   ivVReserved18    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x13  0x0000004C   -   ivVReserved19    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x14  0x00000050   -   ivVReserved20    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x15  0x00000054   -   ivVReserved21    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x16  0x00000058   -   ivVReserved22    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x17  0x0000005C   -   ivVReserved23    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x18  0x00000060   -   ivVspuri         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x19  0x00000064   -   ivVReserved25    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x1A  0x00000068   -   ivVReserved26    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x1B  0x0000006C   -   ivVReserved27    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x1C  0x00000070   -   ivVReserved28    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x1D  0x00000074   -   ivVReserved29    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x1E  0x00000078   -   ivVReserved30    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x1F  0x0000007C   -   ivVReserved31    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x20  0x00000080   -   ivVtrap0         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x21  0x00000084   -   ivVtrap1         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x22  0x00000088   -   ivVtrap2         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x23  0x0000008C   -   ivVtrap3         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x24  0x00000090   -   ivVtrap4         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x25  0x00000094   -   ivVtrap5         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x26  0x00000098   -   ivVtrap6         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x27  0x0000009C   -   ivVtrap7         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x28  0x000000A0   -   ivVtrap8         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x29  0x000000A4   -   ivVtrap9         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x2A  0x000000A8   -   ivVtrap10        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x2B  0x000000AC   -   ivVtrap11        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x2C  0x000000B0   -   ivVtrap12        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x2D  0x000000B4   -   ivVtrap13        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x2E  0x000000B8   -   ivVtrap14        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x2F  0x000000BC   -   ivVtrap15        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x30  0x000000C0   -   ivVReserved48    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x31  0x000000C4   -   ivVReserved49    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x32  0x000000C8   -   ivVReserved50    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x33  0x000000CC   -   ivVReserved51    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x34  0x000000D0   -   ivVReserved52    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x35  0x000000D4   -   ivVReserved53    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x36  0x000000D8   -   ivVReserved54    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x37  0x000000DC   -   ivVReserved55    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x38  0x000000E0   -   ivVReserved56    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x39  0x000000E4   -   ivVReserved57    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x3A  0x000000E8   -   ivVReserved58    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x3B  0x000000EC   -   ivVReserved59    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x3C  0x000000F0   -   ivVReserved60    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x3D  0x000000F4   -   ivVunsinstr      unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x3E  0x000000F8   -   ivVReserved62    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x3F  0x000000FC   -   ivVReserved63    unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x40  0x00000100   -   ivVirq           unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x41  0x00000104   -   ivVlvd           unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x42  0x00000108   -   ivVllwu          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x43  0x0000010C   -   ivVlol           unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x44  0x00000110   -   ivVflash         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x45  0x00000114   -   ivVdmach0        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x46  0x00000118   -   ivVdmach1        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x47  0x0000011C   -   ivVdmach2        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x48  0x00000120   -   ivVdmach3        unused by PE */
    (tIsrFunc)&USB_LDD_USB_Interrupt,  /* 0x49  0x00000124   570   ivVusb0          used by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x4A  0x00000128   -   ivVrngb          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x4B  0x0000012C   -   ivVftm1fault_ovf unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x4C  0x00000130   -   ivVftm1ch0       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x4D  0x00000134   -   ivVftm1ch1       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x4E  0x00000138   -   ivVftm1ch2       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x4F  0x0000013C   -   ivVftm1ch3       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x50  0x00000140   -   ivVftm1ch4       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x51  0x00000144   -   ivVftm1ch5       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x52  0x00000148   -   ivVcmp0          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x53  0x0000014C   -   ivVftm0fault_ovf unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x54  0x00000150   -   ivVftm0ch0       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x55  0x00000154   -   ivVftm0ch1       unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x56  0x00000158   -   ivVspi0          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x57  0x0000015C   -   ivVsci0          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x58  0x00000160   -   ivVsai_rx        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x59  0x00000164   -   ivVsai_tx        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x5A  0x00000168   -   ivViic0          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x5B  0x0000016C   -   ivViic2          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x5C  0x00000170   -   ivVspi1          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x5D  0x00000174   -   ivVsci1          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x5E  0x00000178   -   ivViic1          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x5F  0x0000017C   -   ivViic3          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x60  0x00000180   -   ivVadc0          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x61  0x00000184   -   ivVtsi0          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x62  0x00000188   -   ivVdac0          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x63  0x0000018C   -   ivVcmt           unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x64  0x00000190   -   ivVpdb0          unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x65  0x00000194   -   ivVlptmr0        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x66  0x00000198   -   ivVlptmr1        unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x67  0x0000019C   -   ivVL7swi         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x68  0x000001A0   -   ivVL6swi         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x69  0x000001A4   -   ivVL5swi         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x6A  0x000001A8   -   ivVL4swi         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x6B  0x000001AC   -   ivVL3swi         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x6C  0x000001B0   -   ivVL2swi         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x6D  0x000001B4   -   ivVL1swi         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x6E  0x000001B8   -   ivVmtim0         unused by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x6F  0x000001BC   -   ivVusbdcd        unused by PE */
    (tIsrFunc)&OTG_MAX3353_INT_PIN_Interrupt, /* 0x70  0x000001C0   130   ivVportab        used by PE */
    (tIsrFunc)&Cpu_Interrupt,          /* 0x71  0x000001C4   -   ivVportdc        unused by PE */
    (tIsrFunc)&Cpu_Interrupt           /* 0x72  0x000001C8   -   ivVportfe        unused by PE */
    }
  };
  /*lint -restore Enable MISRA rule (11.4) checking. */
  

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
