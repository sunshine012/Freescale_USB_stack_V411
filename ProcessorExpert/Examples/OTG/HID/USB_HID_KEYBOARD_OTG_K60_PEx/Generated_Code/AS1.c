/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : AS1.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVMD10
**     Component   : Serial_LDD
**     Version     : Component 01.165, Driver 01.10, CPU db: 3.00.003
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 13:36, # CodeGen: 85
**     Abstract    :
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
**     Settings    :
**          Component name                                 : AS1
**          Device                                         : UART3
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
**              RxD                                        : PTC16/CAN1_RX/UART3_RX/ENET0_1588_TMR0/FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b
**              RxD pin signal                             : 
**            Transmitter                                  : Enabled
**              TxD                                        : PTC17/CAN1_TX/UART3_TX/ENET0_1588_TMR1/FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b
**              TxD pin signal                             : 
**            Flow control                                 : None
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Enabled
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
**         Init               - LDD_TDeviceData* AS1_Init(LDD_TUserData *UserDataPtr);
**         Deinit             - void AS1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SendBlock          - LDD_TError AS1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock       - LDD_TError AS1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetSentDataNum     - uint16_t AS1_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetReceivedDataNum - uint16_t AS1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         Main               - void AS1_Main(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE AS1. */
/*lint -save  -e926 -e927 -e928 -e929 -e572 Disable MISRA rule (11.4,12.8) checking. */

/* {Default RTOS Adapter} No RTOS includes */
#include "AS1.h"
#include "Events.h"
#include "UART_PDD.h"

#define AVAILABLE_EVENTS_MASK (LDD_SERIAL_ON_BLOCK_RECEIVED | LDD_SERIAL_ON_BLOCK_SENT)

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static AS1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

/*
** ===================================================================
**     Method      :  AS1_Init (component Serial_LDD)
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
LDD_TDeviceData* AS1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  AS1_TDeviceDataPtr DeviceDataPrv;
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
  /* SIM_SCGC4: UART3=1 */
  SIM_SCGC4 |= SIM_SCGC4_UART3_MASK;                                                   
  /* PORTC_PCR16: ISF=0,MUX=3 */
  PORTC_PCR16 = (uint32_t)((PORTC_PCR16 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x04)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x03)
                ));                                                  
  /* PORTC_PCR17: ISF=0,MUX=3 */
  PORTC_PCR17 = (uint32_t)((PORTC_PCR17 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x04)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x03)
                ));                                                  
  UART_PDD_EnableTransmitter(UART3_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
  UART_PDD_EnableReceiver(UART3_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  DeviceDataPrv->SerFlag = 0x00U;      /* Reset flags */
  /* UART3_C1: LOOPS=0,UARTSWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART3_C1 = 0x00U;                    /*  Set the C1 register */
  /* UART3_C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART3_C3 = 0x00U;                    /*  Set the C3 register */
  /* UART3_S2: LBKDIF=0,RXEDGIF=0,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART3_S2 = 0x00U;                    /*  Set the S2 register */
  /* UART3_MODEM: ??=0,??=0,??=0,??=0,RXRTSE=0,TXRTSPOL=0,TXRTSE=0,TXCTSE=0 */
  UART3_MODEM = 0x00U;                 /*  Set the MODEM register */
  UART_PDD_SetBaudRateFineAdjust(UART3_BASE_PTR, 1u); /* Set baud rate fine adjust */
  UART_PDD_SetBaudRate(UART3_BASE_PTR, 26U); /* Set the baud rate register. */
  UART_PDD_EnableFifo(UART3_BASE_PTR, (UART_PDD_TX_FIFO_ENABLE | UART_PDD_RX_FIFO_ENABLE)); /* Enable RX and TX FIFO */
  UART_PDD_FlushFifo(UART3_BASE_PTR, (UART_PDD_TX_FIFO_FLUSH | UART_PDD_RX_FIFO_FLUSH)); /* Flush RX and TX FIFO */
  UART_PDD_EnableTransmitter(UART3_BASE_PTR, PDD_ENABLE); /* Enable transmitter */
  UART_PDD_EnableReceiver(UART3_BASE_PTR, PDD_ENABLE); /* Enable receiver */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_AS1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  AS1_Deinit (component Serial_LDD)
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
void AS1_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  AS1_TDeviceDataPtr DeviceDataPrv = (AS1_TDeviceDataPtr)DeviceDataPtr;

  (void)DeviceDataPrv;
  UART_PDD_EnableTransmitter(UART3_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
  UART_PDD_EnableReceiver(UART3_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  /* Disable clock gate */
  /* SIM_SCGC4: UART3=0 */
  SIM_SCGC4 &= (uint32_t)~(uint32_t)(SIM_SCGC4_UART3_MASK);                                                   
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  AS1_ReceiveBlock (component Serial_LDD)
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
LDD_TError AS1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  AS1_TDeviceDataPtr DeviceDataPrv = (AS1_TDeviceDataPtr)DeviceDataPtr;

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
**     Method      :  AS1_SendBlock (component Serial_LDD)
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
LDD_TError AS1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  AS1_TDeviceDataPtr DeviceDataPrv = (AS1_TDeviceDataPtr)DeviceDataPtr;

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
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AS1_GetReceivedDataNum (component Serial_LDD)
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
uint16_t AS1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr)
{
  AS1_TDeviceDataPtr DeviceDataPrv = (AS1_TDeviceDataPtr)DeviceDataPtr;

  return (DeviceDataPrv->InpRecvDataNum); /* Return the number of received characters. */
}

/*
** ===================================================================
**     Method      :  AS1_GetSentDataNum (component Serial_LDD)
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
uint16_t AS1_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr)
{
  AS1_TDeviceDataPtr DeviceDataPrv = (AS1_TDeviceDataPtr)DeviceDataPtr;

  return (DeviceDataPrv->OutSentDataNum); /* Return the number of sent characters. */
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
static void InterruptRx(AS1_TDeviceDataPtr DeviceDataPrv)
{
  register uint16_t Data;              /* Temporary variable for data */

  Data = (uint16_t)UART_PDD_GetChar8(UART3_BASE_PTR); /* Read an 8-bit character from the receiver */
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the receive block operation pending? */
    *(DeviceDataPrv->InpDataPtr++) = (uint8_t)Data; /* Put an 8-bit character to the receive buffer */
    DeviceDataPrv->InpRecvDataNum++;   /* Increment received char. counter */
    if (DeviceDataPrv->InpRecvDataNum == DeviceDataPrv->InpDataNumReq) { /* Is the requested number of characters received? */
      DeviceDataPrv->InpDataNumReq = 0x00U; /* If yes then clear number of requested characters to be received. */
      AS1_OnBlockReceived(DeviceDataPrv->UserDataPtr);
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
static void InterruptTx(AS1_TDeviceDataPtr DeviceDataPrv)
{

  if (DeviceDataPrv->OutSentDataNum < DeviceDataPrv->OutDataNumReq) { /* Is number of sent characters less than the number of requested incoming characters? */
    UART_PDD_PutChar8(UART3_BASE_PTR, *(DeviceDataPrv->OutDataPtr++)); /* Put a 8-bit character to the transmit register */
    DeviceDataPrv->OutSentDataNum++;   /* Increment the counter of sent characters. */
    if (DeviceDataPrv->OutSentDataNum == DeviceDataPrv->OutDataNumReq) {
      DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
      AS1_OnBlockSent(DeviceDataPrv->UserDataPtr);
    }
  } else {
    DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)ENABLED_TX_INT); /* Clear the flag ENABLED_TX_INT */
  }
}

/*
** ===================================================================
**     Method      :  AS1_Main (component Serial_LDD)
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
void AS1_Main(LDD_TDeviceData *DeviceDataPtr)
{
  AS1_TDeviceDataPtr DeviceDataPrv = (AS1_TDeviceDataPtr)DeviceDataPtr;
  register uint16_t StatReg = UART_PDD_ReadInterruptStatusReg(UART3_BASE_PTR); /* Read status register */

  if (StatReg & (UART_S1_NF_MASK | UART_S1_OR_MASK | UART_S1_FE_MASK | UART_S1_PF_MASK)) { /* Is any error flag set? */
    (void)UART_PDD_GetChar8(UART3_BASE_PTR); /* Dummy read 8-bit character from receiver */
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
}

/*lint -restore Enable MISRA rule (11.4,12.8) checking. */
/* END AS1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
