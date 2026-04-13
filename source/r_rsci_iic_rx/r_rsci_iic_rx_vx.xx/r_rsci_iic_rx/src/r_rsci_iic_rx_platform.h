/***********************************************************************************************************************
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : r_rsci_iic_rx_platform.h
 * Description  : Functions for using RSCI_IIC on RX devices. 
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 30.10.2025 1.00     First Release

 **********************************************************************************************************************/
/* Guards against multiple inclusion */
#ifndef RSCI_IIC_PLATFORM_H
    #define RSCI_IIC_PLATFORM_H
/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
/* Include specifics for chosen MCU.  */
    #if defined(BSP_MCU_RX26T)
        #include "./targets/rx26t/r_rsci_iic_rx26t_private.h"
    #elif defined(BSP_MCU_RX260)
        #include "./targets/rx260/r_rsci_iic_rx260_private.h"
    #elif defined(BSP_MCU_RX261)
        #include "./targets/rx261/r_rsci_iic_rx261_private.h"
    #elif defined(BSP_MCU_RX660)
        #include "./targets/rx660/r_rsci_iic_rx660_private.h"
    #elif defined(BSP_MCU_RX671)
        #include "./targets/rx671/r_rsci_iic_rx671_private.h"
    #else
        #error "This MCU is not supported by the current r_rsci_iic_rx module."
    #endif

#endif /* RSCI_IIC_PLATFORM_H */

