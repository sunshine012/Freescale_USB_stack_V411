#ifndef __PE_ProjectInfo_H
#define __PE_ProjectInfo_H

/*lint -save -e621 */

/* Selected target CPU */
#define PE_CPUtype "MCF51JF128_64"
#define PE_CPUtype_MCF51JF128_64
#define PE_CPUfamily "ColdFirePlus"
#define PE_CPUfamily_ColdFirePlus
#define PE_CPUsubFamily "MCF51JF"
#define PE_CPUsubFamily_MCF51JF

/* Active PE configuration */
#define PEcfg_Configuration "51JF128VLH_INTERNAL_FLASH"
#ifndef PEcfg_51JF128VLH_INTERNAL_FLASH
#define PEcfg_51JF128VLH_INTERNAL_FLASH 1U
#endif

/* BEAN METHODS IN PROJECT */
#define  _UART_Init
#define  _UART_Deinit
#define  _UART_SendBlock
#define  _UART_ReceiveBlock
#define  _UART_GetSentDataNum
#define  _UART_GetReceivedDataNum
#define  _UART_GetTxCompleteStatus
#define  _UART_Main
#define  _usb_cdc_usb_class_cdc_init_ipipe
#define  _usb_cdc_usb_class_cdc_install_driver
#define  _usb_cdc__io_cdc_serial_open
#define  _usb_cdc__io_cdc_serial_read
#define  _usb_cdc__io_cdc_serial_write
#define  _usb_cdc_usb_class_cdc_get_ctrl_interface
#define  _usb_cdc_usb_class_cdc_get_acm_descriptors
#define  _usb_cdc_usb_class_cdc_set_acm_descriptors
#define  _usb_cdc_usb_class_cdc_get_ctrl_descriptor
#define  _usb_cdc_usb_class_cdc_bind_data_interfaces
#define  _usb_cdc_usb_class_cdc_unbind_data_interfaces
#define  _usb_cdc_usb_class_cdc_bind_acm_interface
#define  _usb_cdc_usb_class_cdc_unbind_acm_interface
#define  _usb_cdc_usb_class_cdc_get_data_interface
#define  _usb_host_usb_class_hub_init
#define  _usb_host_usb_class_hub_cntrl_callback
#define  _usb_host_usb_class_hub_cntrl_common
#define  _usb_host_usb_class_hub_get_descriptor
#define  _usb_host_usb_class_hub_set_port_feature
#define  _usb_host_usb_class_hub_clear_port_feature
#define  _usb_host_usb_class_hub_get_port_status
#define  _usb_host_usb_host_hub_device_event
#define  _usb_host__usb_khci_task
#define  _usb_host__usb_event_init
#define  _usb_host__usb_event_clear
#define  _usb_host__usb_event_wait_ticks
#define  _usb_host__usb_host_register_ch9_callback
#define  _usb_host__usb_host_ch9_clear_feature
#define  _usb_host__usb_host_ch9_get_configuration
#define  _usb_host__usb_host_ch9_get_descriptor
#define  _usb_host__usb_host_ch9_get_interface
#define  _usb_host__usb_host_ch9_get_status
#define  _usb_host__usb_host_ch9_set_address
#define  _usb_host__usb_host_ch9_set_descriptor
#define  _usb_host__usb_host_ch9_set_interface
#define  _usb_host__usb_host_ch9_synch_frame
#define  _usb_host__usb_hostdev_cntrl_request
#define  _usb_host__usb_host_close_pipe
#define  _usb_host__usb_host_close_all_pipes
#define  _usb_host__usb_host_cancel_transfer
#define  _usb_host_usb_hostdev_validate
#define  _usb_host__usb_hostdev_get_buffer
#define  _usb_host__usb_hostdev_get_descriptor
#define  _usb_host__usb_hostdev_find_pipe_handle
#define  _usb_host_usb_hostdev_get_pipe_handle
#define  _usb_host_usb_host_class_intf_init
#define  _usb_host_usb_host_class_intf_validate
#define  _usb_host__usb_host_driver_info_register
#define  _usb_host__usb_hostdev_select_config
#define  _usb_host__usb_hostdev_select_interface
#define  _usb_host_usb_dev_list_attach_device
#define  _usb_host_usb_hostdev_tr_init
#define  _usb_host__usb_host_init
#define  _usb_host__usb_host_register_service
#define  _usb_host__usb_host_unregister_service
#define  _usb_host__usb_host_open_pipe
#define  _usb_host__usb_host_send_setup
#define  _usb_host__usb_host_get_transfer_status
#define  _usb_host__usb_host_recv_data
#define  _usb_host__usb_host_shutdown
#define  _usb_host__usb_host_get_frame_number
#define  _usb_host__usb_host_get_micro_frame_number
#define  _usb_host__usb_host_send_data

/* BEAN EVENTS IN PROJECT */

/* BEAN UART PROPERTIES CONFIGURATION */
#define  _UART_BeanTypeName_Serial_LDD
#define  _UART_BeanTypeName_STR "Serial_LDD"
#define  _UART_DeviceName_UART
#define  _UART_DeviceName_STR "UART"
#define  _UART_Device_UART0
#define  _UART_Device_STR "UART0"
#define  _UART_ReentrantMethods FALSE
#define  _UART_ReentrantMethods_no
#define  _UART_IntService FALSE
#define  _UART_IntService_Disabled
#define  _UART_DataWidth_8
#define  _UART_DataWidth_STR "8"
#define  _UART_Parity_None
#define  _UART_Parity_STR "None"
#define  _UART_StopBits_1
#define  _UART_StopBits_STR "1"
#define  _UART_LoopMode_Normal
#define  _UART_LoopMode_STR "Normal"
#define  _UART_BdRate_value 115200.0F  /* This is timing required by the user - may not match with the set value */
#define  _UART_BdRate_unit baud        /* This is timing required by the user - may not match with the set value */
#define  _UART_BdRate_unit_baud        /* This is timing required by the user - may not match with the set value */
#define  _UART_BdRate_valueSet 115318.15384615386F /* Value set by PE timing model in units: us/Hz/baud/ticks/bit_s - according to requirements */
#define  _UART_BdRate_unitSet baud     /* Value set by PE timing model in units: us/Hz/baud/ticks/bit_s - according to requirements */
#define  _UART_BdRate_unitSet_baud     /* Value set by PE timing model in units: us/Hz/baud/ticks/bit_s - according to requirements */
#define  _UART_BdRate_NumTimingItems 1
#define  _UART_WakeupCond_IdleLine
#define  _UART_WakeupCond_STR "IdleLine"
#define  _UART_StopInWait FALSE
#define  _UART_StopInWait_no
#define  _UART_IdleMode_AfterStartBit
#define  _UART_IdleMode_STR "AfterStartBit"
#define  _UART_SCIOutMode_0
#define  _UART_SCIOutMode_STR "0"
#define  _UART_TxPolarity_NotInverted
#define  _UART_TxPolarity_STR "NotInverted"
#define  _UART_RxPolarity_NotInverted
#define  _UART_RxPolarity_STR "NotInverted"
#define  _UART_BreakLength_10_11
#define  _UART_BreakLength_STR "10_11"
#define  _UART_Receiver TRUE
#define  _UART_Receiver_Enabled
#define  _UART_Inp_ADC0_SE14_TSI0_CH6_PTD6_UART0_RX_RGPIO14_FBa_D4
#define  _UART_Inp_STR "ADC0_SE14_TSI0_CH6_PTD6_UART0_RX_RGPIO14_FBa_D4"
#define  _UART_Inp_BITNUM 6
#define  _UART_RxDpinSignal_
#define  _UART_Transmitter TRUE
#define  _UART_Transmitter_Enabled
#define  _UART_Out_ADC0_SE13_TSI0_CH5_PTA7_UART0_TX_FTM0_QD_PHA_FBa_D5
#define  _UART_Out_STR "ADC0_SE13_TSI0_CH5_PTA7_UART0_TX_FTM0_QD_PHA_FBa_D5"
#define  _UART_Out_BITNUM 7
#define  _UART_TxDpinSignal_
#define  _UART_FlowControlGrp_None
#define  _UART_FlowControlGrp_STR "None"
#define  _UART_InitEnable TRUE
#define  _UART_InitEnable_yes
#define  _UART_AutoInitializationGrp_1
#define  _UART_AutoInitializationGrp_STR "1"
#define  _UART_AutoInitialization TRUE
#define  _UART_AutoInitialization_yes
#define  _UART_OnBlockSentInitState FALSE
#define  _UART_OnBlockSentInitState_Disabled
#define  _UART_OnBlockReceivedInitState FALSE
#define  _UART_OnBlockReceivedInitState_Disabled
#define  _UART_OnTxCompleteInitState FALSE
#define  _UART_OnTxCompleteInitState_Disabled
#define  _UART_OnErrorInitState FALSE
#define  _UART_OnErrorInitState_Disabled
#define  _UART_OnBreakInitState FALSE
#define  _UART_OnBreakInitState_Disabled
#define  _UART_ClockConfigGrp_1
#define  _UART_ClockConfigGrp_STR "1"
#define  _UART_SpeedMode0_0
#define  _UART_SpeedMode0_STR "0"
#define  _UART_SpeedMode1_1
#define  _UART_SpeedMode1_STR "1"
#define  _UART_SpeedMode2_1
#define  _UART_SpeedMode2_STR "1"
#define  _UART_SpeedMode3_1
#define  _UART_SpeedMode3_STR "1"
#define  _UART_SpeedMode4_1
#define  _UART_SpeedMode4_STR "1"
#define  _UART_SpeedMode5_1
#define  _UART_SpeedMode5_STR "1"
#define  _UART_SpeedMode6_1
#define  _UART_SpeedMode6_STR "1"
#define  _UART_SpeedMode7_1
#define  _UART_SpeedMode7_STR "1"
/* BEAN usb_cdc PROPERTIES CONFIGURATION */
#define  _usb_cdc_BeanTypeName_USB_CDC_CLASS
#define  _usb_cdc_BeanTypeName_STR "USB_CDC_CLASS"
#define  _usb_cdc_DeviceName_usb_cdc
#define  _usb_cdc_DeviceName_STR "usb_cdc"
#define  _usb_cdc_CDC_Mode_HOST
#define  _usb_cdc_CDC_Mode_STR "HOST"
#define  _usb_cdc_Usb_Host_Usb_Host
#define  _usb_cdc_Usb_Host_STR "Usb_Host"
#define  _usb_cdc_Use_Poll TRUE
#define  _usb_cdc_Use_Poll_yes
#define  _usb_cdc_Use_Hub TRUE
#define  _usb_cdc_Use_Hub_yes
#define  _usb_cdc_Cdc_class_list_1
#define  _usb_cdc_Cdc_class_list_STR "1"
#define  _usb_cdc_Cdc_class_list_NUMITEMS 1
#define  _usb_cdc_Cdc_class_code0_02
#define  _usb_cdc_Cdc_class_code0_STR "02"
#define  _usb_cdc_Cdc_sub_class_code0_2
#define  _usb_cdc_Cdc_sub_class_code0_STR "2"
#define  _usb_cdc_Cdc_protocol_code0_00
#define  _usb_cdc_Cdc_protocol_code0_STR "00"
#define  _usb_cdc_Cdc_class_code_mask0 255
#define  _usb_cdc_Cdc_sub_class_code_mask0 255
#define  _usb_cdc_Cdc_protocol_code_mask0 254
#define  _usb_cdc_Data_class_code_0A
#define  _usb_cdc_Data_class_code_STR "0A"
#define  _usb_cdc_Data_sub_class_code_00
#define  _usb_cdc_Data_sub_class_code_STR "00"
#define  _usb_cdc_Data_protocol_code_00
#define  _usb_cdc_Data_protocol_code_STR "00"
#define  _usb_cdc_Data_class_code_mask 255
#define  _usb_cdc_Data_sub_class_code_mask 0
#define  _usb_cdc_Data_protocol_code_mask 0
/* BEAN usb_host PROPERTIES CONFIGURATION */
#define  _usb_host_BeanTypeName_USB_HOST_STACK
#define  _usb_host_BeanTypeName_STR "USB_HOST_STACK"
#define  _usb_host_DeviceName_usb_host
#define  _usb_host_DeviceName_STR "usb_host"
#define  _usb_host_LDD_Component_USB_LDD
#define  _usb_host_LDD_Component_STR "USB_LDD"
#define  _usb_host_Common_Class FALSE
#define  _usb_host_Common_Class_no
#define  _usb_host_Use_Poll TRUE
#define  _usb_host_Use_Poll_yes
#define  _usb_host_Use_Hub TRUE
#define  _usb_host_Use_Hub_yes
#define  _usb_host_Class_List_2
#define  _usb_host_Class_List_STR "2"
#define  _usb_host_Class_List_NUMITEMS 2
#define  _usb_host_Class_Name0_acm
#define  _usb_host_Class_Name0_STR "acm"
#define  _usb_host_Class_Code0 2
#define  _usb_host_SubClass_Code0 2
#define  _usb_host_Protocol_Code0 0
#define  _usb_host_Class_Code_Mask0 255
#define  _usb_host_SubClass_Code_Mask0 255
#define  _usb_host_Protocol_Code_Mask0 254
#define  _usb_host_Class_Name1_data
#define  _usb_host_Class_Name1_STR "data"
#define  _usb_host_Class_Code1 10
#define  _usb_host_SubClass_Code1 0
#define  _usb_host_Protocol_Code1 0
#define  _usb_host_Class_Code_Mask1 255
#define  _usb_host_SubClass_Code_Mask1 0
#define  _usb_host_Protocol_Code_Mask1 0
/* BEAN Cpu PROPERTIES CONFIGURATION */
#define  _Cpu_BeanTypeName_MCF51JF128_64
#define  _Cpu_BeanTypeName_STR "MCF51JF128_64"
#define  _Cpu_DeviceName_Cpu
#define  _Cpu_DeviceName_STR "Cpu"
#define  _Cpu_CPU_MCF51JF128VLH
#define  _Cpu_CPU_STR "MCF51JF128VLH"
#define  _Cpu_SharedInternalProperties_1
#define  _Cpu_SharedInternalProperties_STR "1"
#define  _Cpu_CPU_peripheral_CPU
#define  _Cpu_CPU_peripheral_STR "CPU"
#define  _Cpu_MemModelDev_MemModel_FlexMem
#define  _Cpu_MemModelDev_STR "MemModel_FlexMem"
#define  _Cpu_Shared_ClockSettings_1
#define  _Cpu_Shared_ClockSettings_STR "1"
#define  _Cpu_IntOsc 32.768F
#define  _Cpu_IntOsc_STR "32.768"
#define  _Cpu_InitializeSlowTRIM TRUE
#define  _Cpu_InitializeSlowTRIM_yes
#define  _Cpu_SlowTRIMvalueAddress 1023
#define  _Cpu_SlowFTRIMvalueAddress 1022
#define  _Cpu_IntOscFast 4.0F
#define  _Cpu_IntOscFast_STR "4.0"
#define  _Cpu_InitializeFastTRIM FALSE
#define  _Cpu_InitializeFastTRIM_no
#define  _Cpu_OSC1Grp FALSE
#define  _Cpu_OSC1Grp_Disabled
#define  _Cpu_OSC2Grp FALSE
#define  _Cpu_OSC2Grp_Disabled
#define  _Cpu_CLKModeList_1
#define  _Cpu_CLKModeList_STR "1"
#define  _Cpu_CLKModeList_NUMITEMS 1
#define  _Cpu_IRCLKENCLKMode0 TRUE
#define  _Cpu_IRCLKENCLKMode0_Enabled
#define  _Cpu_IREFSTENCLKMode0 FALSE
#define  _Cpu_IREFSTENCLKMode0_Disabled
#define  _Cpu_IRCLKSelectCLKMode0_0
#define  _Cpu_IRCLKSelectCLKMode0_STR "0"
#define  _Cpu_IRCLKClkCLKMode0 0.032768F
#define  _Cpu_IRCLKClkCLKMode0_STR "0.032768"
#define  _Cpu_ERCLKEN2CLKMode0 TRUE
#define  _Cpu_ERCLKEN2CLKMode0_Enabled
#define  _Cpu_EREFSTEN2CLKMode0 FALSE
#define  _Cpu_EREFSTEN2CLKMode0_Disabled
#define  _Cpu_ERCLK2ClkCLKMode0 0.0F
#define  _Cpu_ERCLK2ClkCLKMode0_STR "0.0"
#define  _Cpu_ERCLK2LowClkCLKMode0 0.0F
#define  _Cpu_ERCLK2LowClkCLKMode0_STR "0.0"
#define  _Cpu_ERCLKEN1CLKMode0 TRUE
#define  _Cpu_ERCLKEN1CLKMode0_Enabled
#define  _Cpu_EREFSTEN1CLKMode0 FALSE
#define  _Cpu_EREFSTEN1CLKMode0_Disabled
#define  _Cpu_ERCLK1ClkCLKMode0 0.0F
#define  _Cpu_ERCLK1ClkCLKMode0_STR "0.0"
#define  _Cpu_ERCLK1LowClkCLKMode0 0.0F
#define  _Cpu_ERCLK1LowClkCLKMode0_STR "0.0"
#define  _Cpu_MCGModeSelCLKMode0_0
#define  _Cpu_MCGModeSelCLKMode0_STR "0"
#define  _Cpu_MCGOUTSelectCLKMode0_FLLOUT
#define  _Cpu_MCGOUTSelectCLKMode0_STR "FLLOUT"
#define  _Cpu_MCGModeCLKMode0_
#define  _Cpu_MCGOutputCLKMode0 47.972352F
#define  _Cpu_MCGOutputCLKMode0_STR "47.972352"
#define  _Cpu_MCG_ERCLKClkCLKMode0 0.0F
#define  _Cpu_MCG_ERCLKClkCLKMode0_STR "0.0"
#define  _Cpu_MCGCMECLKMode0 FALSE
#define  _Cpu_MCGCMECLKMode0_Disabled
#define  _Cpu_FLLEnblCLKMode0 TRUE
#define  _Cpu_FLLEnblCLKMode0_Enabled
#define  _Cpu_FLLOutputCLKMode0 47.972352F
#define  _Cpu_FLLOutputCLKMode0_STR "47.972352"
#define  _Cpu_FLLFixedClkCLKMode0 16.384F
#define  _Cpu_FLLFixedClkCLKMode0_STR "16.384"
#define  _Cpu_FLL_RefClkSrcCLKMode0_1
#define  _Cpu_FLL_RefClkSrcCLKMode0_STR "1"
#define  _Cpu_FLLRefClkCLKMode0 32.768F
#define  _Cpu_FLLRefClkCLKMode0_STR "32.768"
#define  _Cpu_MCG_FLL_MFactor_CLKMode0_Auto_select
#define  _Cpu_MCG_FLL_MFactor_CLKMode0_STR "Auto_select"
#define  _Cpu_PLLEnblCLKMode0 FALSE
#define  _Cpu_PLLEnblCLKMode0_Disabled
#define  _Cpu_PLLSTENCLKMode0 FALSE
#define  _Cpu_PLLSTENCLKMode0_Disabled
#define  _Cpu_PLLOutputCLKMode0 0.0F
#define  _Cpu_PLLOutputCLKMode0_STR "0.0"
#define  _Cpu_MCG_PRDIV_CLKMode0_Auto_select
#define  _Cpu_MCG_PRDIV_CLKMode0_STR "Auto_select"
#define  _Cpu_PLLRefClkCLKMode0 1.0F
#define  _Cpu_PLLRefClkCLKMode0_STR "1.0"
#define  _Cpu_MCG_VDIV_CLKMode0_Auto_select
#define  _Cpu_MCG_VDIV_CLKMode0_STR "Auto_select"
#define  _Cpu_PLL_LOLIECLKMode0 FALSE
#define  _Cpu_PLL_LOLIECLKMode0_Disabled
#define  _Cpu_InitPriority_0
#define  _Cpu_InitPriority_STR "0"
#define  _Cpu_WDOGDis TRUE
#define  _Cpu_WDOGDis_yes
#define  _Cpu_SharedADC0_1
#define  _Cpu_SharedADC0_STR "1"
#define  _Cpu_ADCCondGrp_
#define  _Cpu_ADC0CondGrp_
#define  _Cpu_ADC0AsynchroClock_Auto_selected_prescaler
#define  _Cpu_ADC0AsynchroClock_STR "Auto_selected_prescaler"
#define  _Cpu_ADC1CondGrp_
#define  _Cpu_ADC2CondGrp_
#define  _Cpu_ADC3CondGrp_
#define  _Cpu_ADC4CondGrp_
#define  _Cpu_SharedNMI0_1
#define  _Cpu_SharedNMI0_STR "1"
#define  _Cpu_RCMGrp TRUE
#define  _Cpu_RCMGrp_Enabled
#define  _Cpu_PeriphDeviceRCM_RCM
#define  _Cpu_PeriphDeviceRCM_STR "RCM"
#define  _Cpu_RCMResetPin_RESET_b_PTC1
#define  _Cpu_RCMResetPin_STR "RESET_b_PTC1"
#define  _Cpu_RCMResetPin_BITNUM 1
#define  _Cpu_RCMResetPinSignal_
#define  _Cpu_RCMFilterInStop_disabled
#define  _Cpu_RCMFilterInStop_STR "disabled"
#define  _Cpu_RCMFilterInRunWait_disabled
#define  _Cpu_RCMFilterInRunWait_STR "disabled"
#define  _Cpu_RCMFilterWidth 1
#define  _Cpu_RCMIsInitialized TRUE
#define  _Cpu_RCMIsInitialized_yes
#define  _Cpu_SharedNMI1_1
#define  _Cpu_SharedNMI1_STR "1"
#define  _Cpu_BDMPinEnable TRUE
#define  _Cpu_BDMPinEnable_Enabled
#define  _Cpu_BDMPin_BKGD_MS_PTB4
#define  _Cpu_BDMPin_STR "BKGD_MS_PTB4"
#define  _Cpu_BDMPin_BITNUM 4
#define  _Cpu_BDMPinSignal_
#define  _Cpu_SharedFlashOrganization_1
#define  _Cpu_SharedFlashOrganization_STR "1"
#define  _Cpu_SharedFLASHGrp_1
#define  _Cpu_SharedFLASHGrp_STR "1"
#define  _Cpu_EEEfeatureGrp_
#define  _Cpu_FlexNVMSize_32_KB
#define  _Cpu_FlexNVMSize_STR "32_KB"
#define  _Cpu_Dpart_32
#define  _Cpu_Dpart_STR "32"
#define  _Cpu_Dpart__0
#define  _Cpu_Dpart__STR "0"
#define  _Cpu_DataFlashAvailable FALSE
#define  _Cpu_DataFlashAvailable_no
#define  _Cpu_EEPROMAvailable FALSE
#define  _Cpu_EEPROMAvailable_no
#define  _Cpu_EEPROMPartitionStart 2129920
#define  _Cpu_EEPROMPartitionSize 0
#define  _Cpu_EEEpart_0
#define  _Cpu_EEEpart_STR "0"
#define  _Cpu_EEEpart__0
#define  _Cpu_EEEpart__STR "0"
#define  _Cpu_FlexRAM FALSE
#define  _Cpu_FlexRAM_Disabled
#define  _Cpu_EEEFeatureIsInitialized TRUE
#define  _Cpu_EEEFeatureIsInitialized_yes
#define  _Cpu_FlashOrgDscrBlockList_2
#define  _Cpu_FlashOrgDscrBlockList_STR "2"
#define  _Cpu_FlashOrgDscrBlockList_NUMITEMS 2
#define  _Cpu_FlashOrgDscrBlockAddress0 0
#define  _Cpu_FlashOrgDscrBlockSize0 131072
#define  _Cpu_FlashOrgDscrBlockWUnitSize0 4
#define  _Cpu_FlashOrgDscrBlockEUnitSize0 1024
#define  _Cpu_FlashOrgDscrBlockPUnitSize0 4096
#define  _Cpu_FlashOrgDscrBlockAddress1 2097152
#define  _Cpu_FlashOrgDscrBlockSize1 32768
#define  _Cpu_FlashOrgDscrBlockWUnitSize1 4
#define  _Cpu_FlashOrgDscrBlockEUnitSize1 1024
#define  _Cpu_FlashOrgDscrBlockPUnitSize1 4096
#define  _Cpu_ShrdFLASHCfgGrp_1
#define  _Cpu_ShrdFLASHCfgGrp_STR "1"
#define  _Cpu_FTFL_FlashConfigGrp FALSE
#define  _Cpu_FTFL_FlashConfigGrp_Disabled
#define  _Cpu_SharedCPUConfigGrp_1
#define  _Cpu_SharedCPUConfigGrp_STR "1"
#define  _Cpu_CPUCR_IME FALSE
#define  _Cpu_CPUCR_IME_Disabled
#define  _Cpu_CPUCR_IAE FALSE
#define  _Cpu_CPUCR_IAE_Disabled
#define  _Cpu_CPUCR_BWD TRUE
#define  _Cpu_CPUCR_BWD_Enabled
#define  _Cpu_CPUCR_HAE TRUE
#define  _Cpu_CPUCR_HAE_Enabled
#define  _Cpu_CPUCR_CBRR FALSE
#define  _Cpu_CPUCR_CBRR_Disabled
#define  _Cpu_CPUCR_FHP FALSE
#define  _Cpu_CPUCR_FHP_Disabled
#define  _Cpu_CPUCR_FSD TRUE
#define  _Cpu_CPUCR_FSD_Enabled
#define  _Cpu_CPUCR_FCDIS TRUE
#define  _Cpu_CPUCR_FCDIS_Enabled
#define  _Cpu_CPUCR_FDCEN FALSE
#define  _Cpu_CPUCR_FDCEN_Disabled
#define  _Cpu_CPUCR_FICDIS TRUE
#define  _Cpu_CPUCR_FICDIS_Enabled
#define  _Cpu_ShrdSCBGrp1_1
#define  _Cpu_ShrdSCBGrp1_STR "1"
#define  _Cpu_PeriphDeviceSIM_SIM
#define  _Cpu_PeriphDeviceSIM_STR "SIM"
#define  _Cpu_SIMCLKOUTGrp_disabled
#define  _Cpu_SIMCLKOUTGrp_STR "disabled"
#define  _Cpu_SIMSCGCGrp FALSE
#define  _Cpu_SIMSCGCGrp_Disabled
#define  _Cpu_SIMIsInitialized TRUE
#define  _Cpu_SIMIsInitialized_yes
#define  _Cpu_ShrdPMCGrp_1
#define  _Cpu_ShrdPMCGrp_STR "1"
#define  _Cpu_PeriphDevicePMC_PMC
#define  _Cpu_PeriphDevicePMC_STR "PMC"
#define  _Cpu_PMCLVDreset_enabled
#define  _Cpu_PMCLVDreset_STR "enabled"
#define  _Cpu_PMCLVDvoltageSelect_low
#define  _Cpu_PMCLVDvoltageSelect_STR "low"
#define  _Cpu_PMCLVWvoltageSelect_low
#define  _Cpu_PMCLVWvoltageSelect_STR "low"
#define  _Cpu_PMCBangapBuffer_disabled
#define  _Cpu_PMCBangapBuffer_STR "disabled"
#define  _Cpu_PMCBangapVLPBuffer_disabled
#define  _Cpu_PMCBangapVLPBuffer_STR "disabled"
#define  _Cpu_PMCLVDIntName_Vlvd
#define  _Cpu_PMCLVDIntName_STR "Vlvd"
#define  _Cpu_PMCLVDIntNameRequestFeatureGroup_Only_if_property_present
#define  _Cpu_PMCLVDIntNameRequestFeatureGroup_STR "Only_if_property_present"
#define  _Cpu_PMCLVDIntNameRequest_enabled
#define  _Cpu_PMCLVDIntNameRequest_STR "enabled"
#define  _Cpu_DevInit_PMCISRnameLVDGrp_
#define  _Cpu_PMCLVDinterrupt_disabled
#define  _Cpu_PMCLVDinterrupt_STR "disabled"
#define  _Cpu_PMCLVWinterrupt_disabled
#define  _Cpu_PMCLVWinterrupt_STR "disabled"
#define  _Cpu_PMCIsInitialized TRUE
#define  _Cpu_PMCIsInitialized_yes
#define  _Cpu_ShrdFBusGrp_1
#define  _Cpu_ShrdFBusGrp_STR "1"
#define  _Cpu_ExternalBusGrp FALSE
#define  _Cpu_ExternalBusGrp_Disabled
#define  _Cpu_Shared_CPUInterrupts_1
#define  _Cpu_Shared_CPUInterrupts_STR "1"
#define  _Cpu_DevInit_Default_ISRGrp_
#define  _Cpu_MCU_Reset_Vector_Grp_
#define  _Cpu_InstrRelatedReset TRUE
#define  _Cpu_InstrRelatedReset_Enabled
#define  _Cpu_IntIllegalInstructionGrp FALSE
#define  _Cpu_IntIllegalInstructionGrp_Disabled
#define  _Cpu_IntUnimplementedLineAGrp FALSE
#define  _Cpu_IntUnimplementedLineAGrp_Disabled
#define  _Cpu_IntUnimplementedLineFGrp FALSE
#define  _Cpu_IntUnimplementedLineFGrp_Disabled
#define  _Cpu_IntPrivilegeViolationGrp FALSE
#define  _Cpu_IntPrivilegeViolationGrp_Disabled
#define  _Cpu_AddrRelatedReset TRUE
#define  _Cpu_AddrRelatedReset_Enabled
#define  _Cpu_IntAccessErrorGrp FALSE
#define  _Cpu_IntAccessErrorGrp_Disabled
#define  _Cpu_IntAddressErrorGrp FALSE
#define  _Cpu_IntAddressErrorGrp_Disabled
#define  _Cpu_IntFormatErrorGrp FALSE
#define  _Cpu_IntFormatErrorGrp_Disabled
#define  _Cpu_IntDivideByZeroGrp FALSE
#define  _Cpu_IntDivideByZeroGrp_Disabled
#define  _Cpu_IntUnsupportedInstrGrp FALSE
#define  _Cpu_IntUnsupportedInstrGrp_Disabled
#define  _Cpu_TrapExceptionsGrp_16
#define  _Cpu_TrapExceptionsGrp_STR "16"
#define  _Cpu_TrapExceptionsGrp_NUMITEMS 16
#define  _Cpu_IntTrapGrp0 FALSE
#define  _Cpu_IntTrapGrp0_Disabled
#define  _Cpu_IntTrapGrp1 FALSE
#define  _Cpu_IntTrapGrp1_Disabled
#define  _Cpu_IntTrapGrp2 FALSE
#define  _Cpu_IntTrapGrp2_Disabled
#define  _Cpu_IntTrapGrp3 FALSE
#define  _Cpu_IntTrapGrp3_Disabled
#define  _Cpu_IntTrapGrp4 FALSE
#define  _Cpu_IntTrapGrp4_Disabled
#define  _Cpu_IntTrapGrp5 FALSE
#define  _Cpu_IntTrapGrp5_Disabled
#define  _Cpu_IntTrapGrp6 FALSE
#define  _Cpu_IntTrapGrp6_Disabled
#define  _Cpu_IntTrapGrp7 FALSE
#define  _Cpu_IntTrapGrp7_Disabled
#define  _Cpu_IntTrapGrp8 FALSE
#define  _Cpu_IntTrapGrp8_Disabled
#define  _Cpu_IntTrapGrp9 FALSE
#define  _Cpu_IntTrapGrp9_Disabled
#define  _Cpu_IntTrapGrp10 FALSE
#define  _Cpu_IntTrapGrp10_Disabled
#define  _Cpu_IntTrapGrp11 FALSE
#define  _Cpu_IntTrapGrp11_Disabled
#define  _Cpu_IntTrapGrp12 FALSE
#define  _Cpu_IntTrapGrp12_Disabled
#define  _Cpu_IntTrapGrp13 FALSE
#define  _Cpu_IntTrapGrp13_Disabled
#define  _Cpu_IntTrapGrp14 FALSE
#define  _Cpu_IntTrapGrp14_Disabled
#define  _Cpu_IntTrapGrp15 FALSE
#define  _Cpu_IntTrapGrp15_Disabled
#define  _Cpu_SWInterruptsGrp_7
#define  _Cpu_SWInterruptsGrp_STR "7"
#define  _Cpu_SWInterruptsGrp_NUMITEMS 7
#define  _Cpu_IntSwiGrp0 FALSE
#define  _Cpu_IntSwiGrp0_Disabled
#define  _Cpu_IntSwiGrp1 FALSE
#define  _Cpu_IntSwiGrp1_Disabled
#define  _Cpu_IntSwiGrp2 FALSE
#define  _Cpu_IntSwiGrp2_Disabled
#define  _Cpu_IntSwiGrp3 FALSE
#define  _Cpu_IntSwiGrp3_Disabled
#define  _Cpu_IntSwiGrp4 FALSE
#define  _Cpu_IntSwiGrp4_Disabled
#define  _Cpu_IntSwiGrp5 FALSE
#define  _Cpu_IntSwiGrp5_Disabled
#define  _Cpu_IntSwiGrp6 FALSE
#define  _Cpu_IntSwiGrp6_Disabled
#define  _Cpu_IntLossOfLockGrp FALSE
#define  _Cpu_IntLossOfLockGrp_Disabled
#define  _Cpu_Shared_CPULowPowerGrp_1
#define  _Cpu_Shared_CPULowPowerGrp_STR "1"
#define  _Cpu_MC_AVLP TRUE
#define  _Cpu_MC_AVLP_0
#define  _Cpu_MC_ALLS TRUE
#define  _Cpu_MC_ALLS_0
#define  _Cpu_MC_AVLLS TRUE
#define  _Cpu_MC_AVLLS_0
#define  _Cpu_Shared_CPULowPowerGrp1_1
#define  _Cpu_Shared_CPULowPowerGrp1_STR "1"
#define  _Cpu_WakeUpCntrlGrp TRUE
#define  _Cpu_WakeUpCntrlGrp_Enabled
#define  _Cpu_WakeUpIntLvl_0
#define  _Cpu_WakeUpIntLvl_STR "0"
#define  _Cpu_ShrdLLWUGrp_1
#define  _Cpu_ShrdLLWUGrp_STR "1"
#define  _Cpu_LLWUGrp FALSE
#define  _Cpu_LLWUGrp_Disabled
#define  _Cpu_Shared_CPULowPowerGrp0_1
#define  _Cpu_Shared_CPULowPowerGrp0_STR "1"
#define  _Cpu_SetLowPowerModeGrp_
#define  _Cpu_SetOperationMode_WAIT_Sel_WAIT_WLPW
#define  _Cpu_SetOperationMode_WAIT_Sel_STR "WAIT_WLPW"
#define  _Cpu_SetOperationMode_SLEEP_Sel_STOP_VLPS
#define  _Cpu_SetOperationMode_SLEEP_Sel_STR "STOP_VLPS"
#define  _Cpu_SetOperationMode_STOP FALSE
#define  _Cpu_SetOperationMode_STOP_Disabled
#define  _Cpu_SpeedModeList_1
#define  _Cpu_SpeedModeList_STR "1"
#define  _Cpu_SpeedModeList_NUMITEMS 1
#define  _Cpu_IRC_32kHzSpeedMode0 0.032768F
#define  _Cpu_IRC_32kHzSpeedMode0_STR "0.032768"
#define  _Cpu_IRC_4MHzSpeedMode0 4.0F
#define  _Cpu_IRC_4MHzSpeedMode0_STR "4.0"
#define  _Cpu_OSC2SpeedMode0 4.0F
#define  _Cpu_OSC2SpeedMode0_STR "4.0"
#define  _Cpu_OSC1SpeedMode0 0.032768F
#define  _Cpu_OSC1SpeedMode0_STR "0.032768"
#define  _Cpu_IRCLKSelSpeedMode0_IRC_32kHz
#define  _Cpu_IRCLKSelSpeedMode0_STR "IRC_32kHz"
#define  _Cpu_MCG_FLL_RCLKSelSpeedMode0_IRC_32kHz
#define  _Cpu_MCG_FLL_RCLKSelSpeedMode0_STR "IRC_32kHz"
#define  _Cpu_MCG_FRDIVSpeedMode0_Auto_selected_prescaler
#define  _Cpu_MCG_FRDIVSpeedMode0_STR "Auto_selected_prescaler"
#define  _Cpu_MCG_FLL_MFactorSpeedMode0_1464
#define  _Cpu_MCG_FLL_MFactorSpeedMode0_STR "1464"
#define  _Cpu_MCG_PRDIVSpeedMode0_Auto_selected_prescaler
#define  _Cpu_MCG_PRDIVSpeedMode0_STR "Auto_selected_prescaler"
#define  _Cpu_MCG_VDIVSpeedMode0_Auto_selected_prescaler
#define  _Cpu_MCG_VDIVSpeedMode0_STR "Auto_selected_prescaler"
#define  _Cpu_MCGOUTSelSpeedMode0_MCGFLLCLK
#define  _Cpu_MCGOUTSelSpeedMode0_STR "MCGFLLCLK"
#define  _Cpu_VLPRSpeedMode0 FALSE
#define  _Cpu_VLPRSpeedMode0_Disabled
#define  _Cpu_CLKModeSpeedMode0_0
#define  _Cpu_CLKModeSpeedMode0_STR "0"
#define  _Cpu_MCGModeSelSpeedMode0_0
#define  _Cpu_MCGModeSelSpeedMode0_STR "0"
#define  _Cpu_MCGOutputSpeedMode0 47.972352F
#define  _Cpu_MCGOutputSpeedMode0_STR "47.972352"
#define  _Cpu_IRCLKClkSpeedMode0_0_032768
#define  _Cpu_IRCLKClkSpeedMode0_STR "0_032768"
#define  _Cpu_ERCLK2ClkSpeedMode0_0
#define  _Cpu_ERCLK2ClkSpeedMode0_STR "0"
#define  _Cpu_ERCLK1ClkSpeedMode0_0
#define  _Cpu_ERCLK1ClkSpeedMode0_STR "0"
#define  _Cpu_FLLFixedClkSpeedMode0_16_384
#define  _Cpu_FLLFixedClkSpeedMode0_STR "16_384"
#define  _Cpu_PLL0ClockSpeedMode0_48
#define  _Cpu_PLL0ClockSpeedMode0_STR "48"
#define  _Cpu_FLL0ClockSpeedMode0_48
#define  _Cpu_FLL0ClockSpeedMode0_STR "48"
#define  _Cpu_OUTDIVSpeedMode0_2
#define  _Cpu_OUTDIVSpeedMode0_STR "2"
#define  _Cpu_OUTDIV_SpeedMode0_Auto_selected_prescaler
#define  _Cpu_OUTDIV_SpeedMode0_STR "Auto_selected_prescaler"
#define  _Cpu_CoreClockSpeedMode0 23.986176F
#define  _Cpu_CoreClockSpeedMode0_STR "23.986176"
#define  _Cpu_BusClockSpeedMode0 11.993088F
#define  _Cpu_BusClockSpeedMode0_STR "11.993088"
#define  _Cpu_USBClockCondGrp0_
#define  _Cpu_USB0_CLKINSpeedMode0 0.0F
#define  _Cpu_USB0_CLKINSpeedMode0_STR "0.0"
#define  _Cpu_USBPLLFLLCLkSelSpeedMode0_0
#define  _Cpu_USBPLLFLLCLkSelSpeedMode0_STR "0"
#define  _Cpu_USBPLLFLLClockSpeedMode0 47.972352F
#define  _Cpu_USBPLLFLLClockSpeedMode0_STR "47.972352"
#define  _Cpu_USBDIVSpeedMode0__1
#define  _Cpu_USBDIVSpeedMode0_STR "_1"
#define  _Cpu_USBFRACSpeedMode0__1
#define  _Cpu_USBFRACSpeedMode0_STR "_1"
#define  _Cpu_USBClockSpeedMode0 47.972352F
#define  _Cpu_USBClockSpeedMode0_STR "47.972352"
#define  _Cpu_I2SClockCondGrp0_
#define  _Cpu_I2S0_CLKINSpeedMode0 0.0F
#define  _Cpu_I2S0_CLKINSpeedMode0_STR "0.0"
#define  _Cpu_I2S0_MclkPinSourceSpeedMode0_Auto_selected_prescaler
#define  _Cpu_I2S0_MclkPinSourceSpeedMode0_STR "Auto_selected_prescaler"
#define  _Cpu_I2S0_TxClkModeSpeedMode0_Auto_selected_prescaler
#define  _Cpu_I2S0_TxClkModeSpeedMode0_STR "Auto_selected_prescaler"
#define  _Cpu_I2S0_RxClkModeSpeedMode0_Auto_selected_prescaler
#define  _Cpu_I2S0_RxClkModeSpeedMode0_STR "Auto_selected_prescaler"
#define  CPU_TICKS_REFERENCE_CLOCK_HZ 4000000.0F

/*lint -restore */

#endif /* __PE_ProjectInfo_H */
