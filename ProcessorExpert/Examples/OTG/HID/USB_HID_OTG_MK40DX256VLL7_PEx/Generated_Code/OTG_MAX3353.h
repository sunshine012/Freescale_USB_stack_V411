/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : OTG_MAX3353.h
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Component   : I2C_LDD
**     Version     : Component 01.011, Driver 01.06, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-27, 15:42, # CodeGen: 4
**     Abstract    :
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
**     Settings    :
**          Component name                                 : OTG_MAX3353
**          I2C channel                                    : I2C1
**          Interrupt service                              : Disabled
**          Settings                                       : 
**            Mode selection                               : MASTER
**            MASTER mode                                  : Enabled
**              Initialization                             : 
**                Address mode                             : 7-bit addressing
**                Target slave address init                : 2C
**            SLAVE mode                                   : Disabled
**            Pins                                         : 
**              SDA pin                                    : 
**                SDA pin                                  : PTC11/I2C1_SDA/I2S0_RXD/LCD_P31/ADC1_SE7b
**                SDA pin signal                           : 
**              SCL pin                                    : 
**                SCL pin                                  : PTC10/I2C1_SCL/I2S0_RX_FS/LCD_P30/ADC1_SE6b/CMP0_IN4
**                SCL pin signal                           : 
**              High drive select                          : Disabled
**              Input Glitch filter                        : 0
**            Internal frequency (multiplier factor)       : 12 MHz
**            Bits 0-2 of Frequency divider register       : 101
**            Bits 3-5 of Frequency divider register       : 000
**            SCL frequency                                : 400 kHz
**            SDA Hold                                     : 0.75 us
**            SCL start Hold                               : 0.917 us
**            SCL stop Hold                                : 1.333 us
**            Control acknowledge bit                      : Disabled
**            Low timeout                                  : Disabled
**          Initialization                                 : 
**            Enabled in init code                         : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnMasterBlockSent                          : Enabled
**              OnMasterBlockReceived                      : Enabled
**              OnMasterByteReceived                       : Disabled
**              OnSlaveBlockSent                           : Disabled
**              OnSlaveBlockReceived                       : Disabled
**              OnSlaveByteReceived                        : Disabled
**              OnSlaveRxRequest                           : Disabled
**              OnSlaveTxRequest                           : Disabled
**              OnSlaveGeneralCallAddr                     : Disabled
**              OnSlaveSmBusCallAddr                       : Disabled
**              OnSlaveSmBusAlertResponse                  : Disabled
**              OnError                                    : Enabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component enabled
**            Clock configuration 2                        : This component enabled
**            Clock configuration 3                        : This component enabled
**            Clock configuration 4                        : This component enabled
**            Clock configuration 5                        : This component enabled
**            Clock configuration 6                        : This component enabled
**            Clock configuration 7                        : This component enabled
**     Contents    :
**         Init                         - LDD_TDeviceData* OTG_MAX3353_Init(LDD_TUserData *UserDataPtr);
**         Deinit                       - void OTG_MAX3353_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         MasterSendBlock              - LDD_TError OTG_MAX3353_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr,...
**         MasterGetBlockSentStatus     - bool OTG_MAX3353_MasterGetBlockSentStatus(LDD_TDeviceData *DeviceDataPtr);
**         MasterReceiveBlock           - LDD_TError OTG_MAX3353_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr,...
**         MasterGetBlockReceivedStatus - bool OTG_MAX3353_MasterGetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);
**         SelectSlaveDevice            - LDD_TError OTG_MAX3353_SelectSlaveDevice(LDD_TDeviceData *DeviceDataPtr,...
**         GetError                     - LDD_TError OTG_MAX3353_GetError(LDD_TDeviceData *DeviceDataPtr,...
**         CheckBus                     - LDD_TError OTG_MAX3353_CheckBus(LDD_TDeviceData *DeviceDataPtr,...
**         Main                         - void OTG_MAX3353_Main(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __OTG_MAX3353_H
#define __OTG_MAX3353_H

/* MODULE OTG_MAX3353. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */
#include "PE_LDD.h"

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define OTG_MAX3353_PRPH_BASE_ADDRESS  0x40067000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define OTG_MAX3353_Init_METHOD_ENABLED
#define OTG_MAX3353_Deinit_METHOD_ENABLED
#define OTG_MAX3353_MasterSendBlock_METHOD_ENABLED
#define OTG_MAX3353_MasterGetBlockSentStatus_METHOD_ENABLED
#define OTG_MAX3353_MasterReceiveBlock_METHOD_ENABLED
#define OTG_MAX3353_MasterGetBlockReceivedStatus_METHOD_ENABLED
#define OTG_MAX3353_SelectSlaveDevice_METHOD_ENABLED
#define OTG_MAX3353_GetError_METHOD_ENABLED
#define OTG_MAX3353_CheckBus_METHOD_ENABLED
#define OTG_MAX3353_Main_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define OTG_MAX3353_OnMasterBlockSent_EVENT_ENABLED
#define OTG_MAX3353_OnMasterBlockReceived_EVENT_ENABLED
#define OTG_MAX3353_OnError_EVENT_ENABLED



LDD_TDeviceData* OTG_MAX3353_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_Init (component I2C_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the device data structure. 
** ===================================================================
*/

void OTG_MAX3353_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_Deinit (component I2C_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError OTG_MAX3353_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_MasterSendBlock (component I2C_LDD)
**
**     Description :
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 0 to
**         the I2C bus and then writes the block of characters to the
**         bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that transmission was
**         successful. The state of transmission is detectable by means
**         of events (OnMasterSendComplete or OnError). Data to be sent
**         are not copied to an internal buffer and remains in the
**         original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockSent"can be used to detect the end of
**         the transmission. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to the block of data
**                           to send.
**         Size            - Size of the data block.
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The I2C device is now running
** ===================================================================
*/

bool OTG_MAX3353_MasterGetBlockSentStatus(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_MasterGetBlockSentStatus (component I2C_LDD)
**
**     Description :
**         This method returns current state of MasterSendBlock method.
**         This method is available only for the MASTER mode and if
**         method MasterSendBlock is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Return value:
**                           <true> - data block is completely
**                           transmitted.
**                           <false> - data block isn't completely
**                           transmitted.
** ===================================================================
*/

LDD_TError OTG_MAX3353_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_MasterReceiveBlock (component I2C_LDD)
**
**     Description :
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 1 to
**         the I2C bus and then receives the block of characters from
**         the bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that reception was
**         successful. The state of reception is detectable by means of
**         events (OnMasterSendComplete  or OnError). Data to be
**         received are not copied to an internal buffer and remains in
**         the original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockReceived"can be used to detect the end
**         of the reception. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**         Size            - The size of the block.
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The master device is busy
**                           ERR_NOTAVAIL - It is not possible to
**                           receive data if general call address is set.
**                           ERR_PARAM_MODE -  Stop condition isn't
**                           possible generated on end transmission.
** ===================================================================
*/

bool OTG_MAX3353_MasterGetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_MasterGetBlockReceivedStatus (component I2C_LDD)
**
**     Description :
**         This method returns current state of MasterReceiveBlock
**         method. This method is available only for the MASTER mode
**         and if method MasterReceiveBlock is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Return value:
**                           <true> - data block is completely received.
**                           <false> - data block isn't completely
**                           received.
** ===================================================================
*/

LDD_TError OTG_MAX3353_SelectSlaveDevice(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TAddrType AddrType, LDD_I2C_TAddr Addr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_SelectSlaveDevice (component I2C_LDD)
**
**     Description :
**         This method selects a new slave for communication by its
**         7-bit slave, 10-bit address or general call value. Any send
**         or receive method directs to or from selected device, until
**         a new slave device is selected by this method. This method
**         is available for the MASTER mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         AddrType        - Specify type of slave address
**                           (7bit, 10bit or general call address), e.g.
**                           LDD_I2C_ADDRTYPE_7BITS.
**         Addr            - 7bit or 10bit slave address value.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_BUSY - The device is busy, wait until
**                           the current operation is finished.
**                           ERR_DISABLED -  The device is disabled.
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_ADDRESS_TYPE -  Invalid address
**                           type.
**                           ERR_PARAM_ADDRESS -  Invalid address value.
** ===================================================================
*/

LDD_TError OTG_MAX3353_GetError(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TErrorMask *ErrorMaskPtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_GetError (component I2C_LDD)
**
**     Description :
**         Returns value of error mask, e.g. LDD_I2C_ARBIT_LOST.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * ErrorMaskPtr    - Pointer to a variable
**                           where errors value mask will be stored.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError OTG_MAX3353_CheckBus(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TBusState *BusStatePtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_CheckBus (component I2C_LDD)
**
**     Description :
**         This method returns the status of the bus. If the START
**         condition has been detected, the method returns LDD_I2C_BUSY.
**         If the STOP condition has been detected, the method returns
**         LDD_I2C_IDLE.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BusStatePtr     - Pointer to a variable,
**                           where value of status is stored.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
** ===================================================================
*/

void OTG_MAX3353_Main(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_Main (component I2C_LDD)
**
**     Description :
**         This method is available only for polling mode. If interrupt
**         service is disabled this method replaces the I2C interrupt
**         handler. This method should be called if Receive/SendBlock
**         was invoked before in order to run the reception/transmition.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

/* END OTG_MAX3353. */

#endif
/* ifndef __OTG_MAX3353_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/