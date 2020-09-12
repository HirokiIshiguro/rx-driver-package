/*******************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only
 * intended for use with Renesas products. No other uses are authorized. This
 * software is owned by Renesas Electronics Corporation and is protected under
 * all applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
 * LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
 * ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
 * FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
 * ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
 * BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software
 * and to discontinue the availability of this software. By using this software,
 * you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 * Copyright (C) 2014(2018) Renesas Electronics Corporation. All rights reserved.
 ******************************************************************************/
/*******************************************************************************
 * File Name    : r_usb_phid_mini_config.h
 * Description  : USB Peripheral HID configuration
 ******************************************************************************/
/*******************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 01.09.2014 1.00    First Release
 *         : 30.11.2018 1.10    Supporting Smart Configurator
 ******************************************************************************/

#ifndef R_USB_PHID_MINI_CONFIG_H
#define R_USB_PHID_MINI_CONFIG_H

/******************************************************************************
 Macro definitions
 ******************************************************************************/

/** [Setting pipe to be used]
 * USB_CFG_PHID_INT_IN  : Pipe number (USB_PIPE6 to USB_PIPE9) HID Interrupt In Pipe
 * USB_CFG_PHID_INT_OUT : Pipe number (USB_PIPE6 to USB_PIPE9) HID Interrupt Out Pipe
 */
#define USB_CFG_PHID_INT_IN               (USB_PIPE6)
#define USB_CFG_PHID_INT_OUT              (USB_PIPE7)

#endif  /* R_USB_PHID_MINI_CONFIG_H */
/******************************************************************************
 End  Of File
 ******************************************************************************/
