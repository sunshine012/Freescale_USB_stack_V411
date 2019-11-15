/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PTE26.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVMD10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.003
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 13:36, # CodeGen: 85
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : PTE26
**          Port                                           : PTE
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 4000000
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTE
**            Interrupt priority                           : maximal priority
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : key
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTE26/UART4_CTS_b/ENET_1588_CLKIN/RTC_CLKOUT/USB_CLKIN
**                  Pin signal                             : 
**                  Initial pin direction                  : Input
**                  Initial pin event                      : Rising edge
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Enabled
**     Contents    :
**         Init         - LDD_TDeviceData* PTE26_Init(LDD_TUserData *UserDataPtr);
**         SetPortValue - void PTE26_SetPortValue(LDD_TDeviceData *DeviceDataPtr, PTE26_TPortValue Value);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __PTE26_H
#define __PTE26_H

/* MODULE PTE26. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "IO_Map.h"
#include "GPIO_PDD.h"
#include "PORT_PDD.h"
#include "PE_LDD.h"

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define PTE26_PRPH_BASE_ADDRESS  0x400FF100U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define PTE26_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_PTE26_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define PTE26_Init_METHOD_ENABLED
#define PTE26_SetPortValue_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define PTE26_OnPortEvent_EVENT_ENABLED

/* Definition of bit field constants */
#define key ((LDD_GPIO_TBitField)0)

/* Definition of implementation constants */
#define PTE26_ALLOCATED_PINS_MASK 0x04000000U /* Mask of all allocated pins from the port */
#define PTE26_MODULE_BASE_ADDRESS PTE_BASE_PTR /* Name of macro used as the base address */
#define PTE26_PORTCONTROL_BASE_ADDRESS PORTE_BASE_PTR /* Name of macro used as the base address */
#define PTE26_AVAILABLE_EVENTS_MASK LDD_GPIO_ON_PORT_EVENT /* Mask of all available events */
#define PTE26_FIELD_0_PIN_0 LDD_GPIO_PIN_26 /* Constant for the pin in the field used in the method ConnectPin */
#define PTE26_key_START_BIT 26u        /* Index of the starting bit of the bit field (0 represents LSB) */
#define PTE26_key_MASK 0x04000000u     /* Mask of the bits allocated by the bit field (within the port) */
/* Representation of unaligned data value of the port.
   Unsigned integer of proper width depending on the size of the GPIO port allocated.
   Typically the value of n-th bit represents the data for the n-th pin within the port.
   Such value is not abstracted from the physical position of the bits within the port. */
typedef uint32_t PTE26_TPortValue;

/* Representation of right-aligned data value of the bit field.
   Typically the value of n-th bit represents the data of the n-th bit within the bit field (not within the port).
   There are used only so many lowest bits, as it is denoted by the width of the bit field.
   Such value is abstracted from the physical position of the bit field pins within the port.
   Equals to the type <compId>_TPortValue. */
typedef PTE26_TPortValue PTE26_TFieldValue;



LDD_TDeviceData* PTE26_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  PTE26_Init (component GPIO_LDD)
**
**     Description :
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/

void PTE26_SetPortValue(LDD_TDeviceData *DeviceDataPtr, PTE26_TPortValue Value);
/*
** ===================================================================
**     Method      :  PTE26_SetPortValue (component GPIO_LDD)
**
**     Description :
**         This method writes the output data value to the port. Only
**         configured pins (through all of bit fields in this component)
**         are affected.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Value           - Unaligned data value to write to the
**                           port. The bit 0 corresponds with the pin
**                           which has index 0 within the port, the bit
**                           1 corresponds with the pin which has index
**                           1 within the port, etc. Only configured
**                           pins (through all of bit fields in this
**                           component) are affected.
**     Returns     : Nothing
** ===================================================================
*/

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(PTE26_Interrupt);
/*
** ===================================================================
**     Method      :  PTE26_Interrupt (component GPIO_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END PTE26. */

#endif
/* ifndef __PTE26_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
