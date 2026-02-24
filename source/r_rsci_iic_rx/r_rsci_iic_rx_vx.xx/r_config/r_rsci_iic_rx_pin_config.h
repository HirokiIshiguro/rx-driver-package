/***********************************************************************************************************************
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : r_rsci_iic_rx_pin_config.h
 * Description  : Pin configures the RSCI IIC drivers
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 30.10.2025 1.00     First Release
 **********************************************************************************************************************/
/* Guards against multiple inclusion */
#ifndef RSCI_IIC_PIN_CONFIG_H
    #define RSCI_IIC_PIN_CONFIG_H
/***********************************************************************************************************************
 Configuration Options
 **********************************************************************************************************************/
/*------------------------------------------------------------------------------*/
/*   Set using port as rsci iic port                                             */
/*------------------------------------------------------------------------------*/
/* Select the port group and pin used by setting
 "R_RSCI_IIC_CFG_RSCIx_SSCLx_PORT (select from port group 0 to K)"
 and "R_RSCI_IIC_CFG_RSCIx_SSCLx_BIT (select from pin number 0 to 7)"
 and "R_RSCI_IIC_CFG_RSCIx_SSDAx_PORT (select from port group 0 to K)"
 and "R_RSCI_IIC_CFG_RSCIx_SSDAx_BIT (select from pin number 0 to 7)",
 respectively. */

/* Select the ports (SSCL000 and SSDA000) to use in RSCI0 */
    #define R_RSCI_IIC_CFG_RSCI0_SSCL000_PORT     '2'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI0_SSCL000_BIT      '1'        /* Bit Number  */

    #define R_RSCI_IIC_CFG_RSCI0_SSDA000_PORT     '2'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI0_SSDA000_BIT      '0'        /* Bit Number  */

/* Select the ports (SSCL008 and SSDA008) to use in RSCI8 */
    #define R_RSCI_IIC_CFG_RSCI8_SSCL008_PORT     'C'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI8_SSCL008_BIT      '6'        /* Bit Number  */

    #define R_RSCI_IIC_CFG_RSCI8_SSDA008_PORT     'C'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI8_SSDA008_BIT      '7'        /* Bit Number  */

/* Select the ports (SSCL009 and SSDA009) to use in RSCI9 */
    #define R_RSCI_IIC_CFG_RSCI9_SSCL009_PORT     'B'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI9_SSCL009_BIT      '6'        /* Bit Number  */

    #define R_RSCI_IIC_CFG_RSCI9_SSDA009_PORT     'B'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI9_SSDA009_BIT      '7'        /* Bit Number  */

/* Select the ports (SSCL010 and SSDA010) to use in RSCI10 */
    #define R_RSCI_IIC_CFG_RSCI10_SSCL010_PORT    '8'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI10_SSCL010_BIT     '1'        /* Bit Number  */

    #define R_RSCI_IIC_CFG_RSCI10_SSDA010_PORT    '8'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI10_SSDA010_BIT     '2'        /* Bit Number  */

/* Select the ports (SSCL011 and SSDA011) to use in RSCI11 */
    #define R_RSCI_IIC_CFG_RSCI11_SSCL011_PORT    '7'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI11_SSCL011_BIT     '6'        /* Bit Number  */

    #define R_RSCI_IIC_CFG_RSCI11_SSDA011_PORT    '7'        /* Port Number */
    #define R_RSCI_IIC_CFG_RSCI11_SSDA011_BIT     '7'        /* Bit Number  */

#endif /* RSCI_IIC_PIN_CONFIG_H */

