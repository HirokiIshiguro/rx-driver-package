/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_lpt_rx_config.h
* Version      : 1.0
* Description  : Functions for using even link controller
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*         : 01.03.2016 1.00    First Release
***********************************************************************************************************************/
#ifndef LPT_CONFIG_H
#define LPT_CONFIG_H

/*******************************************************************************
  Configuration Options
*******************************************************************************/

/* SPECIFY WHETHER TO INCLUDE CODE FOR API PARAMETER CHECKING */
/* Setting to BSP_CFG_PARAM_CHECKING_ENABLE utilizes the system default setting */
/* Setting to 1 includes parameter checking; 0 compiles out parameter checking */
#define LPT_CFG_PARAM_CHECKING      (1)

/* LPT (Low Power Timer) Clock source select (LPTCR1.LPCNTCKSEL)
   0 = Sub-clock oscillator
   1 = IWDT-dedicated on-chip oscillator
*/ 
#ifndef BSP_CFG_LPT_CLOCK_SOURCE
#define LPT_CFG_LPT_CLOCK_SOURCE    (0)
#endif

#endif /* LPT_CONFIG_H */
/***********************************************************************************************************************
 * End of File
 ***********************************************************************************************************************/
