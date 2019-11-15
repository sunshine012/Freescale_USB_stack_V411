/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PTC5.h
**     Project     : ProcessorExpert
**     Processor   : MK40DN512ZVMD10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.003
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 11:49, # CodeGen: 12
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : PTC5
**          Port                                           : PTC
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 20
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTC
**            Interrupt priority                           : medium priority
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : PLAY
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTC5/SPI0_SCK/LPT0_ALT2/CMP0_OUT/LCD_P25
**                  Pin signal                             : 
**                  Initial pin direction                  : Input
**                  Initial pin event                      : Rising edge
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Enabled
**     Contents    :
**         Init - LDD_TDeviceData* PTC5_Init(LDD_TUserData *UserDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __PTC5_H
#define __PTC5_H

/* MODULE PTC5. */

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
#define PTC5_PRPH_BASE_ADDRESS  0x400FF080U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define PTC5_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_PTC5_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define PTC5_Init_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define PTC5_OnPortEvent_EVENT_ENABLED

/* Definition of bit field constants */
#define PLAY ((LDD_GPIO_TBitField)0)

/* Definition of implementation constants */
#define PTC5_ALLOCATED_PINS_MASK 0x20U /* Mask of all allocated pins from the port */
#define PTC5_MODULE_BASE_ADDRESS PTC_BASE_PTR /* Name of macro used as the base address */
#define PTC5_PORTCONTROL_BASE_ADDRESS PORTC_BASE_PTR /* Name of macro used as the base address */
#define PTC5_AVAILABLE_EVENTS_MASK LDD_GPIO_ON_PORT_EVENT /* Mask of all available events */
#define PTC5_FIELD_0_PIN_0 LDD_GPIO_PIN_5 /* Constant for the pin in the field used in the method ConnectPin */
#define PTC5_PLAY_START_BIT 5u         /* Index of the starting bit of the bit field (0 represents LSB) */
#define PTC5_PLAY_MASK 0x20u           /* Mask of the bits allocated by the bit field (within the port) */
/* Representation of unaligned data value of the port.
   Unsigned integer of proper width depending on the size of the GPIO port allocated.
   Typically the value of n-th bit represents the data for the n-th pin within the port.
   Such value is not abstracted from the physical position of the bits within the port. */
typedef uint32_t PTC5_TPortValue;

/* Representation of right-aligned data value of the bit field.
   Typically the value of n-th bit represents the data of the n-th bit within the bit field (not within the port).
   There are used only so many lowest bits, as it is denoted by the width of the bit field.
   Such value is abstracted from the physical position of the bit field pins within the port.
   Equals to the type <compId>_TPortValue. */
typedef PTC5_TPortValue PTC5_TFieldValue;



LDD_TDeviceData* PTC5_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  PTC5_Init (component GPIO_LDD)
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

/* {Default RTOS Adapter} ISR function prototype */
void PTC5_Interrupt(void);
/*
** ===================================================================
**     Method      :  PTC5_Interrupt (component GPIO_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END PTC5. */

#endif
/* ifndef __PTC5_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
