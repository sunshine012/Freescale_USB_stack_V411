/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : UART.c
**     Project     : ProcessorExpert
**     Processor   : MCF51JF128VLH
**     Component   : Serial_LDD
**     Version     : Component 01.165, Driver 01.10, CPU db: 3.00.000
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2012-11-19, 12:54, # CodeGen: 19
**     Abstract    :
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
**     Settings    :
**          Component name                                 : UART
**          Device                                         : UART0
**          Interrupt service/event                        : Disabled
**          Settings                                       : 
**            Data width                                   : 8 bits
**            Parity                                       : None
**            Stop bits                                    : 1
**            Loop mode                                    : Normal
**            Baud rate                                    : 115200 baud
**            Wakeup condition                             : Idle line wakeup
**            Stop in wait mode                            : no
**            Idle line mode                               : Starts after start bit
**            Transmitter output                           : Not inverted
**            Receiver input                               : Not inverted
**            Break generation length                      : 10/11 bits
**            Receiver                                     : Enabled
**              RxD                                        : ADC0_SE14/TSI0_CH6/PTD6/UART0_RX/RGPIO14/FBa_D4
**              RxD pin signal                             : 
**            Transmitter                                  : Enabled
**              TxD                                        : ADC0_SE13/TSI0_CH5/PTA7/UART0_TX/FTM0_QD_PHA/FBa_D5
**              TxD pin signal                             : 
**            Flow control                                 : None
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnBlockSent                                : Disabled
**              OnBlockReceived                            : Disabled
**              OnTxComplete                               : Disabled
**              OnError                                    : Disabled
**              OnBreak                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                - LDD_TDeviceData* UART_Init(LDD_TUserData *UserDataPtr);
**         Deinit              - void UART_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SendBlock           - LDD_TError UART_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock        - LDD_TError UART_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetSentDataNum      - uint16_t UART_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetReceivedDataNum  - uint16_t UART_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetTxCompleteStatus - bool UART_GetTxCompleteStatus(LDD_TDeviceData *DeviceDataPtr);
**         Main                - void UART_Main(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE UART. */
/*lint -save  -e926 -e927 -e928 -e929 -e572 Disable MISRA rule (11.4,12.8) checking. */

/* {Default RTOS Adapter} No RTOS includes */
#include "UART.h"
#include "UART_PDD.h"

#define AVAILABLE_EVENTS_MASK 0x00U

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static UART_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

/*
** ===================================================================
**     Method      :  UART_Init (component Serial_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Device data structure pointer.
** ===================================================================
*/
LDD_TDeviceData* UART_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  UART_TDeviceDataPtr DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  /* Clear the receive counters and pointer */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Clear the counter of received characters */
  DeviceDataPrv->InpDataNumReq = 0x00U; /* Clear the counter of characters to receive by ReceiveBlock() */
  DeviceDataPrv->InpDataPtr = NULL;    /* Clear the buffer pointer for received characters */
  /* Clear the transmit counters and pointer */
  DeviceDataPrv->OutSentDataNum = 0x00U; /* Clear the counter of sent characters */
  DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
  DeviceDataPrv->OutDataPtr = NULL;    /* Clear the buffer pointer for data to be transmitted */
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* SIM_SCGC1: UART0=1 */
  SIM_SCGC1 |= (uint8_t)0x01U;                            
  /* MXC_PTDPF1: D6=2 */
  MXC_PTDPF1 = (uint8_t)((MXC_PTDPF1 & (uint8_t)~(uint8_t)0x0DU) | (uint8_t)0x02U);
  /* MXC_PTAPF1: A7=2 */
  MXC_PTAPF1 = (uint8_t)((MXC_PTAPF1 & (uint8_t)~(uint8_t)0xD0U) | (uint8_t)0x20U);
  UART_PDD_EnableTransmitter(UART0_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
  UART_PDD_EnableReceiver(UART0_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  DeviceDataPrv->SerFlag = 0x00U;      /* Reset flags */
  /* UART0_C1: LOOPS=0,UARTSWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART0_C1 = (uint8_t)0x00U;           /*  Set the C1 register */
  /* UART0_C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART0_C3 = (uint8_t)0x00U;           /*  Set the C3 register */
  /* UART0_S2: LBKDIF=0,RXEDGIF=0,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART0_S2 = (uint8_t)0x00U;           /*  Set the S2 register */
  /* UART0_MODEM: ??=0,??=0,??=0,??=0,RXRTSE=0,TXRTSPOL=0,TXRTSE=0,TXCTSE=0 */
  UART0_MODEM = (uint8_t)0x00U;        /*  Set the MODEM register */
  UART_PDD_SetBaudRateFineAdjust(UART0_BASE_PTR, 0u); /* Set baud rate fine adjust */
  UART_PDD_SetBaudRate(UART0_BASE_PTR, 13U); /* Set the baud rate register. */
  UART_PDD_EnableFifo(UART0_BASE_PTR, (UART_PDD_TX_FIFO_ENABLE | UART_PDD_RX_FIFO_ENABLE)); /* Enable RX and TX FIFO */
  UART_PDD_FlushFifo(UART0_BASE_PTR, (UART_PDD_TX_FIFO_FLUSH | UART_PDD_RX_FIFO_FLUSH)); /* Flush RX and TX FIFO */
  UART_PDD_EnableTransmitter(UART0_BASE_PTR, PDD_ENABLE); /* Enable transmitter */
  UART_PDD_EnableReceiver(UART0_BASE_PTR, PDD_ENABLE); /* Enable receiver */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_UART_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  UART_Deinit (component Serial_LDD)
**
**     Description :
**          Deinitializes the device. Switches off the device, frees
**         the device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/
void UART_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  UART_TDeviceDataPtr DeviceDataPrv = (UART_TDeviceDataPtr)DeviceDataPtr;

  (void)DeviceDataPrv;
  UART_PDD_EnableTransmitter(UART0_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
  UART_PDD_EnableReceiver(UART0_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  /* Disable clock gate */
  /* SIM_SCGC1: UART0=0 */
  SIM_SCGC1 &= (uint8_t)~(uint8_t)0x01U;                           
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  UART_ReceiveBlock (component Serial_LDD)
**
**     Description :
**         Specifies the number of data to receive. The method returns
**         ERR_BUSY until the specified number of characters is
**         received. Method <CancelBlockReception> can be used to
**         cancel a running receive operation.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**         Size            - Number of characters to receive
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous receive request is
**                           pending.
** ===================================================================
*/
LDD_TError UART_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  UART_TDeviceDataPtr DeviceDataPrv = (UART_TDeviceDataPtr)DeviceDataPtr;

  if (Size == 0U) {                    /* Is the parameter Size within an expected range? */
    return ERR_PARAM_SIZE;             /* If no then error */
  }
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the previous receive operation pending? */
    return ERR_BUSY;                   /* If yes then error */
  }
  DeviceDataPrv->InpDataPtr = BufferPtr; /* Store a pointer to the input data. */
  DeviceDataPrv->InpDataNumReq = Size; /* Store a number of characters to be received. */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Set number of received characters to zero. */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  UART_SendBlock (component Serial_LDD)
**
**     Description :
**         Sends a block of characters. The method returns ERR_BUSY
**         when the previous block transmission is not completed.
**         Method <CancelBlockTransmission> can be used to cancel a
**         transmit operation. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to a buffer from where
**                           data will be sent.
**         Size            - Number of characters in the buffer.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous transmit request is
**                           pending.
** ===================================================================
*/
LDD_TError UART_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  UART_TDeviceDataPtr DeviceDataPrv = (UART_TDeviceDataPtr)DeviceDataPtr;

  if (Size == 0U) {                    /* Is the parameter Size within an expected range? */
    return ERR_PARAM_SIZE;             /* If no then error */
  }
  if (DeviceDataPrv->OutDataNumReq != 0x00U) { /* Is the previous transmit operation pending? */
    return ERR_BUSY;                   /* If yes then error */
  }
  DeviceDataPrv->OutDataPtr = BufferPtr; /* Set a pointer to the output data. */
  DeviceDataPrv->OutDataNumReq = Size; /* Set the counter of characters to be sent. */
  DeviceDataPrv->OutSentDataNum = 0x00U; /* Clear the counter of sent characters. */
  DeviceDataPrv->SerFlag |= ENABLED_TX_INT; /* Set the flag ENABLED_TX_INT */
  DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)TX_COMPLETED); /* Clear the TX_COMPLETED flag */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  UART_GetReceivedDataNum (component Serial_LDD)
**
**     Description :
**         Returns the number of received characters in the receive
**         buffer. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Number of received characters in the
**                           receive buffer.
** ===================================================================
*/
uint16_t UART_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr)
{
  UART_TDeviceDataPtr DeviceDataPrv = (UART_TDeviceDataPtr)DeviceDataPtr;

  return (DeviceDataPrv->InpRecvDataNum); /* Return the number of received characters. */
}

/*
** ===================================================================
**     Method      :  UART_GetSentDataNum (component Serial_LDD)
**
**     Description :
**         Returns the number of sent characters.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - The number of sent characters.
** ===================================================================
*/
uint16_t UART_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr)
{
  UART_TDeviceDataPtr DeviceDataPrv = (UART_TDeviceDataPtr)DeviceDataPtr;

  return (DeviceDataPrv->OutSentDataNum); /* Return the number of sent characters. */
}

/*
** ===================================================================
**     Method      :  UART_GetTxCompleteStatus (component Serial_LDD)
**
**     Description :
**         Returns whether the transmitter has transmitted all
**         characters and there are no other characters in the
**         transmitter's HW FIFO or the shift register. This method is
**         available only if a peripheral supports this feature.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Possible values:
**                           <true> - Data block is completely
**                           transmitted.
**                           <false> - Data block isn't completely
**                           transmitted.
** ===================================================================
*/
bool UART_GetTxCompleteStatus(LDD_TDeviceData *DeviceDataPtr)
{
  UART_TDeviceDataPtr DeviceDataPrv = (UART_TDeviceDataPtr)DeviceDataPtr;

  if ((DeviceDataPrv->SerFlag & TX_COMPLETED) != 0U) { /* Is a transmission completed? */
    DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)TX_COMPLETED); /* If yes then clear the flag and return the result */
    return TRUE;
  }
  return FALSE;
}

/*
** ===================================================================
**     Method      :  InterruptRx (component Serial_LDD)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void InterruptRx(UART_TDeviceDataPtr DeviceDataPrv)
{
  register uint16_t Data;              /* Temporary variable for data */

  Data = (uint16_t)UART_PDD_GetChar8(UART0_BASE_PTR); /* Read an 8-bit character from the receiver */
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the receive block operation pending? */
    *(DeviceDataPrv->InpDataPtr++) = (uint8_t)Data; /* Put an 8-bit character to the receive buffer */
    DeviceDataPrv->InpRecvDataNum++;   /* Increment received char. counter */
    if (DeviceDataPrv->InpRecvDataNum == DeviceDataPrv->InpDataNumReq) { /* Is the requested number of characters received? */
      DeviceDataPrv->InpDataNumReq = 0x00U; /* If yes then clear number of requested characters to be received. */
    }
  }
}

/*
** ===================================================================
**     Method      :  InterruptTx (component Serial_LDD)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void InterruptTx(UART_TDeviceDataPtr DeviceDataPrv)
{

  if (DeviceDataPrv->OutSentDataNum < DeviceDataPrv->OutDataNumReq) { /* Is number of sent characters less than the number of requested incoming characters? */
    UART_PDD_PutChar8(UART0_BASE_PTR, *(DeviceDataPrv->OutDataPtr++)); /* Put a 8-bit character to the transmit register */
    DeviceDataPrv->OutSentDataNum++;   /* Increment the counter of sent characters. */
    if (DeviceDataPrv->OutSentDataNum == DeviceDataPrv->OutDataNumReq) {
      DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
    }
  } else {
    DeviceDataPrv->SerFlag |= ENABLE_TX_COMPLETE; /* Enable TX complete detection */
    DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)ENABLED_TX_INT); /* Clear the flag ENABLED_TX_INT */
  }
}

/*
** ===================================================================
**     Method      :  UART_Main (component Serial_LDD)
**
**     Description :
**         This method is available only in the polling mode (Interrupt
**         service/event = 'no'). If interrupt service is disabled this
**         method replaces the interrupt handler. This method should be
**         called if Receive/SendBlock was invoked before in order to
**         run the reception/transmission. The end of the
**         receiving/transmitting is indicated by OnBlockSent or
**         OnBlockReceived event. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/
void UART_Main(LDD_TDeviceData *DeviceDataPtr)
{
  UART_TDeviceDataPtr DeviceDataPrv = (UART_TDeviceDataPtr)DeviceDataPtr;
  register uint16_t StatReg = UART_PDD_ReadInterruptStatusReg(UART0_BASE_PTR); /* Read status register */

  if (StatReg & (UART_S1_NF_MASK | UART_S1_OR_MASK | UART_S1_FE_MASK | UART_S1_PF_MASK)) { /* Is any error flag set? */
    (void)UART_PDD_GetChar8(UART0_BASE_PTR); /* Dummy read 8-bit character from receiver */
    StatReg &= (uint16_t)(~(uint16_t)UART_S1_RDRF_MASK); /* Clear the receive data flag to discard the errorneous data */
  }
  if (StatReg & UART_S1_RDRF_MASK) {   /* Is the receiver's interrupt flag set? */
    InterruptRx(DeviceDataPrv);        /* If yes, then invoke the internal service routine. This routine is inlined. */
  }
  if (DeviceDataPrv->SerFlag & ENABLED_TX_INT) { /* Is the transmitter interrupt enabled? */
    if (StatReg & UART_S1_TDRE_MASK) { /* Is the transmitter empty? */
      InterruptTx(DeviceDataPrv);      /* If yes, then invoke the internal service routine. This routine is inlined. */
    }
  }
  if (((DeviceDataPrv->SerFlag & ENABLE_TX_COMPLETE) != 0U)  && (StatReg & UART_S1_TC_MASK)) { /* Is a transmission completed? */
    DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)ENABLE_TX_COMPLETE); /* Clear the flag ENABLE_TX_COMPLETE */
    DeviceDataPrv->SerFlag |= TX_COMPLETED; /* Set the flag */
  }
}

/*lint -restore Enable MISRA rule (11.4,12.8) checking. */
/* END UART. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
