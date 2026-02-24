/* Generated configuration header file - do not edit */
/***********************************************************************************************************************
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : r_rsci_iic_rx_config.h
 * Description  : Configures the RSCI IIC drivers
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 30.10.2025 1.00     First Release
 **********************************************************************************************************************/
/* Guards against multiple inclusion */
#ifndef RSCI_IIC_CONFIG_H
    #define RSCI_IIC_CONFIG_H
/***********************************************************************************************************************
 Configuration Options
 **********************************************************************************************************************/
/* SPECIFY WHETHER TO INCLUDE CODE FOR API PARAMETER CHECKING */
/* Setting to BSP_CFG_PARAM_CHECKING_ENABLE utilizes the system default setting */
/* Setting to 1 includes parameter checking */
/*            0 compiles out parameter checking */
    #define RSCI_IIC_CFG_PARAM_CHECKING_ENABLE   (1)

/* SPECIFY CHANNELS TO INCLUDE SOFTWARE SUPPORT FOR 1=included, 0=not */
/* mcu supported channels */

/*  RX260    : ch0,    ,    ,    ,    ,    ,    ,    , ch8, ch9,     ,     ,     */
/*  RX261    : ch0,    ,    ,    ,    ,    ,    ,    , ch8, ch9,     ,     ,     */
/*  RX26T    :    ,    ,    ,    ,    ,    ,    ,    , ch8, ch9,     , ch11,     */
/*  RX660    :    ,    ,    ,    ,    ,    ,    ,    ,    ,    , ch10, ch11,     */
/*  RX671    :    ,    ,    ,    ,    ,    ,    ,    ,    ,    , ch10, ch11,     */
/* Please change the definition value of channel to be used to '1'. */
    #define RSCI_IIC_CFG_CH0_INCLUDED    (0)
    #define RSCI_IIC_CFG_CH8_INCLUDED    (0)
    #define RSCI_IIC_CFG_CH9_INCLUDED    (0)
    #define RSCI_IIC_CFG_CH10_INCLUDED   (0)
    #define RSCI_IIC_CFG_CH11_INCLUDED   (0)

/* Set RSCI IIC bps */
/* 1K = 1000, 100K= 100000, Max:384k = 384000 */
    #define RSCI_IIC_CFG_CH0_BITRATE_BPS   (384000)
    #define RSCI_IIC_CFG_CH8_BITRATE_BPS   (384000)
    #define RSCI_IIC_CFG_CH9_BITRATE_BPS   (384000)
    #define RSCI_IIC_CFG_CH10_BITRATE_BPS  (384000)
    #define RSCI_IIC_CFG_CH11_BITRATE_BPS  (384000)

/*
 This definition set for TXI and so on for RSCI interrupt priority level for RSCI IIC.
 */
/* 1 lowest, 15 highest */
    #define RSCI_IIC_CFG_CH0_INT_PRIORITY  (2)
    #define RSCI_IIC_CFG_CH8_INT_PRIORITY  (2)
    #define RSCI_IIC_CFG_CH9_INT_PRIORITY  (2)
    #define RSCI_IIC_CFG_CH10_INT_PRIORITY (2)
    #define RSCI_IIC_CFG_CH11_INT_PRIORITY (2)

/* Digital noise filter (NFEN bit).
 0 =  Noise cancellation function for the SSCLn and SSDAn input signals is disabled.
 1 =  Noise cancellation function for the SSCLn and SSDAn input signals is enable.
 */
    #define RSCI_IIC_CFG_CH0_DIGITAL_FILTER  (1)
    #define RSCI_IIC_CFG_CH8_DIGITAL_FILTER  (1)
    #define RSCI_IIC_CFG_CH9_DIGITAL_FILTER  (1)
    #define RSCI_IIC_CFG_CH10_DIGITAL_FILTER (1)
    #define RSCI_IIC_CFG_CH11_DIGITAL_FILTER (1)

/* Noise Filter Clock (NFCS bit).
 001  =  1       =   The clock signal divided by 1 is used with the noise filter.
 010  =  2       =   The clock signal divided by 2 is used with the noise filter.
 011  =  3       =   The clock signal divided by 4 is used with the noise filter.
 100  =  4       =   The clock signal divided by 8 is used with the noise filter.
 In simple I2C Mode, Setting 000b is prohibited.
 */
    #define RSCI_IIC_CFG_CH0_FILTER_CLOCK    (1)
    #define RSCI_IIC_CFG_CH8_FILTER_CLOCK    (1)
    #define RSCI_IIC_CFG_CH9_FILTER_CLOCK    (1)
    #define RSCI_IIC_CFG_CH10_FILTER_CLOCK   (1)
    #define RSCI_IIC_CFG_CH11_FILTER_CLOCK   (1)

/* I2C Mode Register (IICDL bit).
 00001  =  1       =   0 to 1 cycle
 00010  =  2       =   1 to 2 cycles
 00011  =  3       =   2 to 3 cycles
 00100  =  4       =   3 to 4 cycles
 00101  =  5       =   4 to 5 cycles
 |
 11110  = 30       =  29 to 30 cycles
 11111  = 31       =  30 to 31 cycles
 */
    #define RSCI_IIC_CFG_CH0_SSDA_DELAY_SELECT   (18)
    #define RSCI_IIC_CFG_CH8_SSDA_DELAY_SELECT   (18)
    #define RSCI_IIC_CFG_CH9_SSDA_DELAY_SELECT   (18)
    #define RSCI_IIC_CFG_CH10_SSDA_DELAY_SELECT  (18)
    #define RSCI_IIC_CFG_CH11_SSDA_DELAY_SELECT  (18)

/* Define software bus busy check counter. */
    #define RSCI_IIC_CFG_BUS_CHECK_COUNTER   (1000)

/* Setting to port.
 1 =  includes rsci (simple iic) port setting processing
 0 =  compiles out rsci (simple iic) port setting processing
 */
    #define RSCI_IIC_CFG_PORT_SETTING_PROCESSING   (1)

#endif /* RSCI_IIC_CONFIG_H */


