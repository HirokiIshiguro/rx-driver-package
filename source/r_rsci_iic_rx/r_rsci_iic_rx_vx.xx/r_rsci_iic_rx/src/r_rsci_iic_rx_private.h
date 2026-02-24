/***********************************************************************************************************************
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : r_rsci_iic_private.h
 * Description  : Functions for using RSCI_IIC on RX devices. 
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 30.10.2025 1.00     First Release

 **********************************************************************************************************************/
/* Guards against multiple inclusion */
#ifndef RSCI_IIC_PRIVATE_H
    #define RSCI_IIC_PRIVATE_H
/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
/* Fixed width integer support. */
    #include <stdint.h>
/* bool support */
    #include <stdbool.h>

    #include "r_rsci_iic_rx_if.h"
    #include "r_rsci_iic_rx_pin_config.h"
    #include "r_rsci_iic_rx_config.h"

/***********************************************************************************************************************
 Macro definitions
 **********************************************************************************************************************/

#if ((BSP_MCU_RX26T == 1) && ((BSP_CFG_MCU_PART_MEMORY_SIZE == 0x8) || (BSP_CFG_MCU_PART_MEMORY_SIZE == 0xA)))
    #error  "ERROR - RX26T Product with 48 Kbytes RAM not support RSCI_IIC module!"
#endif

/*----------------------------------------------------------------------------*/
/*   Define return values and values of channel state flag.                   */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_NO_INIT         ((rsci_iic_ch_dev_status_t)(0)) /* No initial state*/
    #define RSCI_IIC_IDLE            ((rsci_iic_ch_dev_status_t)(1)) /* Idle state*/
    #define RSCI_IIC_FINISH          ((rsci_iic_ch_dev_status_t)(2)) /* Finish state*/
    #define RSCI_IIC_NACK            ((rsci_iic_ch_dev_status_t)(3)) /* Nack state*/
    #define RSCI_IIC_COMMUNICATION   ((rsci_iic_ch_dev_status_t)(4)) /* Communication state*/
    #define RSCI_IIC_ERROR           ((rsci_iic_ch_dev_status_t)(5)) /* Error state*/

/*----------------------------------------------------------------------------*/
/*   Defines the argument of the R_RSCI_IIC_Control function.                  */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_GEN_ERR_CON        ((rsci_iic_ctrl_ptn_t)(0x00))   /* Err output */
    #define RSCI_IIC_GEN_START_CON      ((rsci_iic_ctrl_ptn_t)(0x01))   /* Generate Start Condition */
    #define RSCI_IIC_GEN_STOP_CON       ((rsci_iic_ctrl_ptn_t)(0x02))   /* Generate Stop Condition  */
    #define RSCI_IIC_GEN_RESTART_CON    ((rsci_iic_ctrl_ptn_t)(0x04))   /* Generate Restart Condition*/
    #define RSCI_IIC_GEN_SSDA_HI_Z      ((rsci_iic_ctrl_ptn_t)(0x08))   /* Nack reception */
    #define RSCI_IIC_GEN_SSCL_ONESHOT   ((rsci_iic_ctrl_ptn_t)(0x10))   /* Output one shot of SSCL clock */
    #define RSCI_IIC_GEN_RESET          ((rsci_iic_ctrl_ptn_t)(0x20))   /* Reset RSCI_IIC module */

/*============================================================================*/
/*  Parameter check of Pin Configuration Options                              */
/*============================================================================*/
/* RSCI_IIC port (ascii to number) */
/* RSCI0 */
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT))
        #define RSCI_IIC_CH0_SSCL_GP (R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT))
        #define RSCI_IIC_CH0_SSCL_GP (R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT))
        #define RSCI_IIC_CH0_SSCL_GP (R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT)
        #define RSCI_IIC_CH0_SSCL_GP (R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI0_SSCL000_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI0_SSCL000_BIT))
        #define RSCI_IIC_CH0_SSCL_PIN    (R_RSCI_IIC_CFG_RSCI0_SSCL000_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI0_SSCL000_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

    #if ((('0') <= R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT))
        #define RSCI_IIC_CH0_SSDA_GP (R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT))
        #define RSCI_IIC_CH0_SSDA_GP (R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT))
        #define RSCI_IIC_CH0_SSDA_GP (R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT)
        #define RSCI_IIC_CH0_SSDA_GP (R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI0_SSDA000_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI0_SSDA000_BIT))
        #define RSCI_IIC_CH0_SSDA_PIN    (R_RSCI_IIC_CFG_RSCI0_SSDA000_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI0_SSDA000_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

/* RSCI8 */
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT))
        #define RSCI_IIC_CH8_SSCL_GP (R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT))
        #define RSCI_IIC_CH8_SSCL_GP (R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT))
        #define RSCI_IIC_CH8_SSCL_GP (R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT)
        #define RSCI_IIC_CH8_SSCL_GP (R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI8_SSCL008_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI8_SSCL008_BIT))
        #define RSCI_IIC_CH8_SSCL_PIN    (R_RSCI_IIC_CFG_RSCI8_SSCL008_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI8_SSCL008_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

    #if ((('0') <= R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT))
        #define RSCI_IIC_CH8_SSDA_GP (R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT))
        #define RSCI_IIC_CH8_SSDA_GP (R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT))
        #define RSCI_IIC_CH8_SSDA_GP (R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT)
        #define RSCI_IIC_CH8_SSDA_GP (R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI8_SSDA008_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI8_SSDA008_BIT))
        #define RSCI_IIC_CH8_SSDA_PIN    (R_RSCI_IIC_CFG_RSCI8_SSDA008_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI8_SSDA008_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

/* RSCI9 */
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT))
        #define RSCI_IIC_CH9_SSCL_GP (R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT))
        #define RSCI_IIC_CH9_SSCL_GP (R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT))
        #define RSCI_IIC_CH9_SSCL_GP (R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT)
        #define RSCI_IIC_CH9_SSCL_GP (R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI9_SSCL009_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI9_SSCL009_BIT))
        #define RSCI_IIC_CH9_SSCL_PIN    (R_RSCI_IIC_CFG_RSCI9_SSCL009_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI9_SSCL009_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

    #if ((('0') <= R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT))
        #define RSCI_IIC_CH9_SSDA_GP (R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT))
        #define RSCI_IIC_CH9_SSDA_GP (R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT))
        #define RSCI_IIC_CH9_SSDA_GP (R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT)
        #define RSCI_IIC_CH9_SSDA_GP (R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI9_SSDA009_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI9_SSDA009_BIT))
        #define RSCI_IIC_CH9_SSDA_PIN    (R_RSCI_IIC_CFG_RSCI9_SSDA009_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI9_SSDA009_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

/* RSCI10 */
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT))
        #define RSCI_IIC_CH10_SSCL_GP (R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT))
        #define RSCI_IIC_CH10_SSCL_GP (R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT))
        #define RSCI_IIC_CH10_SSCL_GP (R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT)
        #define RSCI_IIC_CH10_SSCL_GP (R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI10_SSCL010_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI10_SSCL010_BIT))
        #define RSCI_IIC_CH10_SSCL_PIN    (R_RSCI_IIC_CFG_RSCI10_SSCL010_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI10_SSCL010_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

    #if ((('0') <= R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT))
        #define RSCI_IIC_CH10_SSDA_GP (R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT))
        #define RSCI_IIC_CH10_SSDA_GP (R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT))
        #define RSCI_IIC_CH10_SSDA_GP (R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT)
        #define RSCI_IIC_CH10_SSDA_GP (R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI10_SSDA010_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI10_SSDA010_BIT))
        #define RSCI_IIC_CH10_SSDA_PIN    (R_RSCI_IIC_CFG_RSCI10_SSDA010_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI10_SSDA010_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

/* RSCI11 */
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT))
        #define RSCI_IIC_CH11_SSCL_GP (R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT))
        #define RSCI_IIC_CH11_SSCL_GP (R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT))
        #define RSCI_IIC_CH11_SSCL_GP (R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT)
        #define RSCI_IIC_CH11_SSCL_GP (R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI11_SSCL011_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI11_SSCL011_BIT))
        #define RSCI_IIC_CH11_SSCL_PIN    (R_RSCI_IIC_CFG_RSCI11_SSCL011_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI11_SSCL011_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

    #if ((('0') <= R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT) && (('9') >= R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT))
        #define RSCI_IIC_CH11_SSDA_GP (R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT - 0x30)
    #elif ((('A') <= R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT) && (('H') >= R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT))
        #define RSCI_IIC_CH11_SSDA_GP (R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT - 0x37)
    #elif ((('J') <= R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT) && (('N') >= R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT))
        #define RSCI_IIC_CH11_SSDA_GP (R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT - 0x38)
    #elif (('Q') == R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT)
        #define RSCI_IIC_CH11_SSDA_GP (R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT - 0x3A)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT in r_rsci_iic_rx_pin_config.h"
    #endif
    #if ((('0') <= R_RSCI_IIC_CFG_RSCI11_SSDA011_BIT) && (('7') >= R_RSCI_IIC_CFG_RSCI11_SSDA011_BIT))
        #define RSCI_IIC_CH11_SSDA_PIN    (R_RSCI_IIC_CFG_RSCI11_SSDA011_BIT - 0x30)
    #else
        #error "Error! Invalid setting for R_RSCI_IIC_CFG_RSCI11_SSDA011_BIT in r_rsci_iic_rx_pin_config.h"
    #endif

/*============================================================================*/
/*  Parameter check of Configuration Options                                  */
/*============================================================================*/

/* Channel select not changed. */
    #if ((0 == RSCI_IIC_CFG_CH0_INCLUDED) && (0 == RSCI_IIC_CFG_CH8_INCLUDED) && (0 == RSCI_IIC_CFG_CH9_INCLUDED) \
        && (0 == RSCI_IIC_CFG_CH10_INCLUDED) && (0 == RSCI_IIC_CFG_CH11_INCLUDED) )
        #error "ERROR - RSCI_IIC_CFG_CHx_INCLUDED (x is 0, 8 to 11) is all 0.- Parameter error in r_rsci_iic_rx_config.h."
    #endif

/*----------------------------------------------------------------------------*/
/*   Definitions for ports group.                                             */
/*----------------------------------------------------------------------------*/
    #define PORT0_GR    (0)
    #define PORT1_GR    (1)
    #define PORT2_GR    (2)
    #define PORT3_GR    (3)
    #define PORT4_GR    (4)
    #define PORT5_GR    (5)
    #define PORT6_GR    (6)
    #define PORT7_GR    (7)
    #define PORT8_GR    (8)
    #define PORT9_GR    (9)
    #define PORTA_GR    (0xA)
    #define PORTB_GR    (0xB)
    #define PORTC_GR    (0xC)
    #define PORTD_GR    (0xD)
    #define PORTE_GR    (0xE)
    #define PORTF_GR    (0xF)
    #define PORTG_GR    (0x10)
    #define PORTH_GR    (0x11)
    #define PORTI_GR    (0x11)
    #define PORTJ_GR    (0x12)
    #define PORTK_GR    (0x13)
    #define PORTL_GR    (0x14)
    #define PORTM_GR    (0x15)
    #define PORTN_GR    (0x16)
    #define PORTO_GR    (0x16)
    #define PORTP_GR    (0x16)
    #define PORTQ_GR    (0x17)
    #define PORT_GR_MAX (0x18)

/*----------------------------------------------------------------------------*/
/*  Bit position masks                                                        */
/*----------------------------------------------------------------------------*/
    #define BIT0_MASK   (0x01U)
    #define BIT1_MASK   (0x02U)
    #define BIT2_MASK   (0x04U)
    #define BIT3_MASK   (0x08U)
    #define BIT4_MASK   (0x10U)
    #define BIT5_MASK   (0x20U)
    #define BIT6_MASK   (0x40U)
    #define BIT7_MASK   (0x80U)
    #define BIT8_MASK   (0x0100U)
    #define BIT9_MASK   (0x0200U)
    #define BIT10_MASK  (0x0400U)
    #define BIT11_MASK  (0x0800U)
    #define BIT12_MASK  (0x1000U)
    #define BIT13_MASK  (0x2000U)
    #define BIT14_MASK  (0x4000U)
    #define BIT15_MASK  (0x8000U)
    #define BIT16_MASK  (0x010000U)
    #define BIT17_MASK  (0x020000U)
    #define BIT18_MASK  (0x040000U)
    #define BIT19_MASK  (0x080000U)
    #define BIT20_MASK  (0x100000U)
    #define BIT21_MASK  (0x200000U)
    #define BIT22_MASK  (0x400000U)
    #define BIT23_MASK  (0x800000U)
    #define BIT24_MASK  (0x01000000U)
    #define BIT25_MASK  (0x02000000U)
    #define BIT26_MASK  (0x04000000U)
    #define BIT27_MASK  (0x08000000U)
    #define BIT28_MASK  (0x10000000U)
    #define BIT29_MASK  (0x20000000U)
    #define BIT30_MASK  (0x40000000U)
    #define BIT31_MASK  (0x80000000U)

/*----------------------------------------------------------------------------*/
/*  Define counter.                                                           */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_STOP_COND_WAIT      ((uint16_t)(1000))  /* Counter of waiting stop condition generation */

/*----------------------------------------------------------------------------*/
/*  Define R/W code for slave address.                                        */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_W_CODE              ((uint8_t)(0xFE))   /* Write code for slave address */
    #define RSCI_IIC_R_CODE              ((uint8_t)(0x01))   /* Read code for slave address */

/*----------------------------------------------------------------------------*/
/*  Define of port control.                                                   */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_HI                  ((uint8_t)(0x01))   /* Port "H" */
    #define RSCI_IIC_LOW                 ((uint8_t)(0x00))   /* Port "L" */
    #define RSCI_IIC_OUT                 ((uint8_t)(0x01))   /* Port Output */
    #define RSCI_IIC_IN                  ((uint8_t)(0x00))   /* Port Input */
    #define RSCI_IIC_BUSY                ((uint8_t)(0x01))   /* Port use as I/O port for peripheral functions. */
    #define RSCI_IIC_NOT_BUSY            ((uint8_t)(0x00))   /* Port Use as general I/O port. */

/*----------------------------------------------------------------------------*/
/*  Define bool type.                                                         */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_FALSE               ((bool)(0x00))      /* False */
    #define RSCI_IIC_TRUE                ((bool)(0x01))      /* True */

/*----------------------------------------------------------------------------*/
/*  Define digital filter enable bit.                                         */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_DF_ENABLE           ((uint8_t)(1))      /* Enable */
    #define RSCI_IIC_DF_DISABLE          ((uint8_t)(0))      /* Disable */

/*----------------------------------------------------------------------------*/
/*  Condition bit.                                                            */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_STAREQ              ((uint8_t)(1)) /* A start condition is generated */
    #define RSCI_IIC_RSTAREQ             ((uint8_t)(2)) /* A restart condition is generated */
    #define RSCI_IIC_STPREQ              ((uint8_t)(4)) /* A stop condition is generated */

/*----------------------------------------------------------------------------*/
/*  I2C Interrupt Mode Select (IICINTM bit).                                  */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_RCV_TRS_INTERRUPT   (1)      /* Synchronization with the clock signal */

/*----------------------------------------------------------------------------*/
/*  Clock Synchronization (IICCSC bit).                                       */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_NO_SYNCHRO          ((uint8_t)(0))      /* No synchronization with the clock signal */
    #define RSCI_IIC_SYNCHRO             ((uint8_t)(1))      /* Synchronization with the clock signal */

/*----------------------------------------------------------------------------*/
/*  ACK Transmission Data bit (IICACKT bit).                                  */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_ACK_TRANS           ((uint8_t)(0)) /* ACK Transmission */
    #define RSCI_IIC_NACK_TRANS          ((uint8_t)(1)) /* NACK transmission and reception of ACK/NACK */

/*----------------------------------------------------------------------------*/
/*  ACK Reception Data Flag (IICACKR bit).                                    */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_ACK_RCV             ((uint8_t)(1))

/*----------------------------------------------------------------------------*/
/*  I2C Status Clear Register (IICSTIFC bit).                                 */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_STIF_CLEAR             ((uint8_t)(1))

/*----------------------------------------------------------------------------*/
/*  RSCI Status Clear Register                                                */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_SSCR_CLEAR             ((uint32_t)(0xFFFFFFB))

/*----------------------------------------------------------------------------*/
/*  SSDA/SSCL Output Select (IICSDAS bit/ IICSCLS bit).                       */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_CLOCK_OUTPUT        ((uint8_t)(0)) /* Serial data/clock output */
    #define RSCI_IIC_CON_OUTPUT          ((uint8_t)(1)) /* Generate a start, restart, or stop condition */
    #define RSCI_IIC_LOW_OUTPUT          ((uint8_t)(2)) /* Output the low level on the SSDA/SSCL pin */
    #define RSCI_IIC_HI_Z_OUTPUT         ((uint8_t)(3)) /* Place the SSDA/SSCL pin in the high-impedance state */

/*----------------------------------------------------------------------------*/
/*  Transimitted/Received Data Transfer Direction bit (DDIR bit).             */
/*----------------------------------------------------------------------------*/
    #define RSCI_IIC_LSB_FIRST           ((uint8_t)(1)) /* Transfer with LSB first */

    #define RSCI_IIC_MSB_FIRST           ((uint8_t)(0)) /* Transfer with MSB first */

/*----------------------------------------------------------------------------*/
/*  Define register setting.                                                  */
/*----------------------------------------------------------------------------*/
/* Common registers setting */

    #define RSCI_IIC_ONESHOT_WAIT        ((uint8_t)(40)) /* OneShot wait */

/* Base register of PCR used to calculate all PCR register addresses. This is constant for all supported MCUs. */
    #define RSCI_IIC_PRV_PCR_BASE_REG ((uint8_t volatile *)(&MPC.PWPR.BYTE-95))
/* Base register of PDR used to calculate all PDR register addresses. This is constant for all supported MCUs. */
    #define RSCI_IIC_PRV_PDR_BASE_REG ((uint8_t volatile *)(&MPC.PWPR.BYTE-287))
/* Base register of PMR used to calculate all PMR register addresses. This is constant for all supported MCUs. */
    #define RSCI_IIC_PRV_PMR_BASE_REG ((uint8_t volatile *)(&MPC.PWPR.BYTE-191))
/* Base register of ODR0 used to calculate all ODR0 register addresses. This is constant for all supported MCUs. */
    #define RSCI_IIC_PRV_ODR0_BASE_REG ((uint8_t volatile *)(&MPC.PWPR.BYTE-159))
/* Base register of ODR1 used to calculate all ODR1 register addresses. This is constant for all supported MCUs. */
    #define RSCI_IIC_PRV_ODR1_BASE_REG ((uint8_t volatile *)(&MPC.PWPR.BYTE-158))
/* Base register of PFS used to calculate all PFS register addresses. This is constant for all supported MCUs. */
    #define RSCI_IIC_PRV_PFS_BASE_REG ((uint8_t volatile *)(&MPC.PWPR.BYTE+33))
/* Base register of PIDR used to calculate all PIDR register addresses. This is constant for all supported MCUs. */
    #define RSCI_IIC_PRV_PIDR_BASE_REG ((uint8_t volatile *)(&MPC.PWPR.BYTE-223))

/*----------------------------------------------------------------------------*/
/*  Define int zero.                                                          */
/*----------------------------------------------------------------------------*/
    #define INT_ZERO (0)

/***********************************************************************************************************************
 Typedef definitions
 **********************************************************************************************************************/
/*----------------------------------------------------------------------------*/
/*  Define internal rsci_iic information structure type.                       */
/*----------------------------------------------------------------------------*/
/* Set number of RSCI_IIC channel */
typedef enum
{
    RSCI_IIC_NUM_CH0 = 0U,
    RSCI_IIC_NUM_CH8 = 8U,
    RSCI_IIC_NUM_CH9,
    RSCI_IIC_NUM_CH10,
    RSCI_IIC_NUM_CH11,
    RSCI_IIC_NUM_CH_MAX = 13U
} rsci_iic_num_ch_t;

/* Internal Mode. */
typedef enum
{
    RSCI_IIC_MODE_NONE = 0U, /* Non-communication mode */
    RSCI_IIC_MODE_OPEN, /* Open mode */
    RSCI_IIC_MODE_SEND, /* Single master transmission mode */
    RSCI_IIC_MODE_RECEIVE, /* Single master reception mode */
    RSCI_IIC_MODE_SEND_RECEIVE, /* Single master transmission reception mode */
    RSCI_IIC_MODE_GETSTATUS, /* Get status mode */
    RSCI_IIC_MODE_CONTROL, /* Control mode */
    RSCI_IIC_MODE_CLOSE, /* Close mode */
} rsci_iic_api_mode_t;

/* Internal Status. */
typedef enum
{
    RSCI_IIC_STS_NO_INIT = 0U, /* None initialization state */
    RSCI_IIC_STS_IDLE, /* Idle state */
    RSCI_IIC_STS_ST_COND_WAIT, /* Start condition generation completion wait state */
    RSCI_IIC_STS_SEND_SLVADR_W_WAIT, /* Slave address [Write] transmission completion wait state */
    RSCI_IIC_STS_SEND_SLVADR_R_WAIT, /* Slave address [Read] transmission completion wait state */
    RSCI_IIC_STS_SEND_DATA_WAIT, /* Data transmission completion wait state */
    RSCI_IIC_STS_RECEIVE_DATA_WAIT, /* Data reception completion wait state */
    RSCI_IIC_STS_SP_COND_WAIT, /* Stop condition generation completion wait state */
    RSCI_IIC_STS_MAX /* Prohibition of setup above here */
} rsci_iic_api_status_t;

/* Internal Event. */
typedef enum
{
    RSCI_IIC_EV_INIT = 0U, /* Called function of Initializes IIC driver */
    RSCI_IIC_EV_GEN_START_COND, /* Called function of Start condition generation */
    RSCI_IIC_EV_INT_START, /* Interrupted start condition generation */
    RSCI_IIC_EV_INT_ADD, /* Interrupted address sending */
    RSCI_IIC_EV_INT_SEND, /* Interrupted data sending */
    RSCI_IIC_EV_INT_STOP, /* Interrupted Stop condition generation */
    RSCI_IIC_EV_INT_NACK, /* Interrupted No Acknowledge */
    RSCI_IIC_EV_MAX /* Prohibition of setup above here */
} rsci_iic_api_event_t;

/*----- Structure type -----*/
/* Internal state transition structure */
typedef struct
{
    rsci_iic_api_event_t event_type; /* Event */
    rsci_iic_return_t   (* proc)(rsci_iic_info_t *); /* handler */
} rsci_iic_mtx_t;

/***********************************************************************************************************************
 Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
/*----------------------------------------------------------------------------*/
/*  external function                                                         */
/*----------------------------------------------------------------------------*/
extern rsci_iic_return_t r_rsci_iic_advance (rsci_iic_info_t * p_rsci_iic_info);
extern rsci_iic_return_t r_rsci_iic_check_arguments (rsci_iic_info_t * p_rsci_iic_info, rsci_iic_api_mode_t called_api);

/*----------------------------------------------------------------------------*/
/*  Interrupt Function                                                        */
/*----------------------------------------------------------------------------*/
extern void r_rsci_iic_txi_isr_processing (uint8_t ch_no);
extern void r_rsci_iic_tei_isr_processing (uint8_t ch_no);

#endif /* RSCI_IIC_PRIVATE_H */

