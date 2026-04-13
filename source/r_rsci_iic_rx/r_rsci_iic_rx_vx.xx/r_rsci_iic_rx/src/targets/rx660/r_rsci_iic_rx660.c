/***********************************************************************************************************************
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : r_rsci_iic_rx660.c
 * Description  : Functions for using RSCI_IIC on RX devices. 
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 30.10.2025 1.00     First Release
 **********************************************************************************************************************/
/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
/* Access to peripherals and board defines. */
#include "platform.h"

#ifdef BSP_MCU_RX660
/* Defines for RSCI_IIC support */
    #include "r_rsci_iic_rx_pin_config.h"
    #include "r_rsci_iic_rx_private.h"
    #include "r_rsci_iic_rx660_private.h"
    #include "r_rsci_iic_rx_if.h"
    #include "r_rsci_iic_rx_config.h"

/***********************************************************************************************************************
 Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
/*----------------------------------------------------------------------------*/
/*   Defines specific information for each RSCI IIC channel.                   */
/*----------------------------------------------------------------------------*/
    #if RSCI_IIC_CFG_CH10_INCLUDED
/* rom info */
const rsci_iic_ch_rom_t g_rsci_iic_ch10_rom =
{
    BSP_LOCK_RSCI10,
    (rsci_regs_t)&RSCI10, /* Cast to rsci_regs_t */
    (volatile uint32_t R_BSP_EVENACCESS_SFR *)&SYSTEM.MSTPCRD.LONG, BIT3_MASK, /* Cast to R_BSP_EVENACCESS_SFR */
    &ICU.IPR[IPR_RSCI10_TXI].BYTE,
    &ICU.IR[IR_RSCI10_TXI].BYTE,
    (volatile uint32_t R_BSP_EVENACCESS_SFR *)&ICU.GRPAL0.LONG, BIT24_MASK,
    &ICU.IER[IER_RSCI10_TXI].BYTE, BIT1_MASK,
    (volatile uint32_t R_BSP_EVENACCESS_SFR *)&ICU.GENAL0.LONG, BIT24_MASK,
    BSP_INT_SRC_AL0_RSCI10_TEI,
    rsci_iic_int_rsci_iic10_tei_isr,
    RSCI_IIC_CFG_CH10_INT_PRIORITY,
    RSCI_IIC_CH10_SSCL_GP,
    RSCI_IIC_CH10_SSCL_PIN,
    RSCI_IIC_MPC_SSCL010_ENABLE,
    RSCI_IIC_CH10_SSDA_GP,
    RSCI_IIC_CH10_SSDA_PIN,
    RSCI_IIC_MPC_SSDA010_ENABLE,
    RSCI_IIC_CFG_CH10_SSDA_DELAY_SELECT,
    RSCI_IIC_CFG_CH10_BITRATE_BPS,
    RSCI_IIC_CFG_CH10_DIGITAL_FILTER,
    RSCI_IIC_CFG_CH10_FILTER_CLOCK
};

/* channel control block */
rsci_iic_ch_ctrl_t g_rsci_iic_ch10_ctrl =
{
    &g_rsci_iic_ch10_rom,
    RSCI_IIC_EV_INIT,
    RSCI_IIC_MODE_NONE,
    RSCI_IIC_STS_NO_INIT,
    RSCI_IIC_STS_NO_INIT,
    (uint8_t)INT_ZERO, /* Cast to uint8_t */
    (rsci_iic_info_t *)NULL
};
    #endif /* RSCI_IIC_CFG_CH10_INCLUDED */

    #if RSCI_IIC_CFG_CH11_INCLUDED
/* rom info */
const rsci_iic_ch_rom_t g_rsci_iic_ch11_rom =
{
    BSP_LOCK_RSCI11,
    (rsci_regs_t)&RSCI11, /* Cast to rsci_regs_t */
    (volatile uint32_t R_BSP_EVENACCESS_SFR *)&SYSTEM.MSTPCRD.LONG, BIT2_MASK, /* Cast to R_BSP_EVENACCESS_SFR */
    &ICU.IPR[IPR_RSCI11_TXI].BYTE,
    &ICU.IR[IR_RSCI11_TXI].BYTE,
    (volatile uint32_t R_BSP_EVENACCESS_SFR *)&ICU.GRPAL0.LONG, BIT27_MASK,
    &ICU.IER[IER_RSCI11_TXI].BYTE, BIT3_MASK,
    (volatile uint32_t R_BSP_EVENACCESS_SFR *)&ICU.GENAL0.LONG, BIT27_MASK,
    BSP_INT_SRC_AL0_RSCI11_TEI,
    rsci_iic_int_rsci_iic11_tei_isr,
    RSCI_IIC_CFG_CH11_INT_PRIORITY,
    RSCI_IIC_CH11_SSCL_GP,
    RSCI_IIC_CH11_SSCL_PIN,
    RSCI_IIC_MPC_SSCL011_ENABLE,
    RSCI_IIC_CH11_SSDA_GP,
    RSCI_IIC_CH11_SSDA_PIN,
    RSCI_IIC_MPC_SSDA011_ENABLE,
    RSCI_IIC_CFG_CH11_SSDA_DELAY_SELECT,
    RSCI_IIC_CFG_CH11_BITRATE_BPS,
    RSCI_IIC_CFG_CH11_DIGITAL_FILTER,
    RSCI_IIC_CFG_CH11_FILTER_CLOCK
};

/* channel control block */
rsci_iic_ch_ctrl_t g_rsci_iic_ch11_ctrl =
{
    &g_rsci_iic_ch11_rom,
    RSCI_IIC_EV_INIT,
    RSCI_IIC_MODE_NONE,
    RSCI_IIC_STS_NO_INIT,
    RSCI_IIC_STS_NO_INIT,
    (uint8_t)INT_ZERO, /* Cast to uint8_t */
    (rsci_iic_info_t *)NULL
};
    #endif /* RSCI_IIC_CFG_CH11_INCLUDED */

/*----------------------------------------------------------------------------*/
/*   Array for start addresses of information for each RSCI IIC channel        */
/*----------------------------------------------------------------------------*/
const rsci_iic_hdl_t g_rsci_iic_handles[RSCI_IIC_NUM_CH_MAX] =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    #if RSCI_IIC_CFG_CH10_INCLUDED
    &g_rsci_iic_ch10_ctrl,
    #else
    NULL,
    #endif
    #if RSCI_IIC_CFG_CH11_INCLUDED
    &g_rsci_iic_ch11_ctrl,
    #else
    NULL,
    #endif
    NULL
};

/***********************************************************************************************************************
 Private global variables and functions
 **********************************************************************************************************************/
static rsci_iic_return_t rsci_iic_set_frequency (rsci_iic_info_t * p_rsci_iic_info);
static void rsci_iic_clear_ir_flag (rsci_iic_info_t * p_rsci_iic_info);

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_check_arguments
 * Description  : check to parameter.
 * Arguments    : rsci_iic_info_t * p_rsci_iic_info   ; IIC Information
 *              ; rsci_iic_api_mode_t called_api      ; Internal Mode
 * Return Value : RSCI_IIC_SUCCESS                    ; Successful operation
 *              ; RSCI_IIC_ERR_INVALID_CHAN           ; channel number invalid for part
 *              : RSCI_IIC_ERR_INVALID_ARG            ; Parameter error
 **********************************************************************************************************************/
rsci_iic_return_t r_rsci_iic_check_arguments(rsci_iic_info_t * p_rsci_iic_info, rsci_iic_api_mode_t called_api)
{

    if (NULL == p_rsci_iic_info)
    {
        return RSCI_IIC_ERR_INVALID_ARG;
    }

    if (RSCI_IIC_MODE_RECEIVE == called_api)
    {

        if (((NULL == p_rsci_iic_info->p_slv_adr) || (NULL == p_rsci_iic_info->p_data2nd))
                || ((uint32_t)NULL == p_rsci_iic_info->cnt2nd))
        {
            return RSCI_IIC_ERR_INVALID_ARG;
        }

    }

    if ((RSCI_IIC_MODE_SEND == called_api) || (RSCI_IIC_MODE_RECEIVE == called_api))
    {

        if (NULL == p_rsci_iic_info->callbackfunc)
        {
            return RSCI_IIC_ERR_INVALID_ARG;
        }

    }

    if ((RSCI_IIC_NUM_CH10 != p_rsci_iic_info->ch_no) && (RSCI_IIC_NUM_CH11 != p_rsci_iic_info->ch_no))
    {
        return RSCI_IIC_ERR_INVALID_CHAN;
    }

    return RSCI_IIC_SUCCESS;
} /* End of function r_rsci_iic_check_arguments() */

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_power_on
 * Description  : Turns on power to a RSCI_IIC channel.
 * Arguments    : channel -
 *                    Which channel to use.
 * Return Value : none
 **********************************************************************************************************************/
void r_rsci_iic_power_on(uint8_t channel)
{
    R_BSP_VOLATILE_EVENACCESS const rsci_iic_ch_rom_t * p_rom = g_rsci_iic_handles[channel]->prom;

    uint32_t mstp;
    uint32_t stop_mask;

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    bsp_int_ctrl_t int_ctrl;
#endif

    /* Enable writing to MSTP registers. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_CGC_SWR);

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    R_BSP_InterruptControl(BSP_INT_SRC_EMPTY, BSP_INT_CMD_FIT_INTERRUPT_DISABLE, &int_ctrl);
#endif

    /* Enable selected RSCI_IIC Channel. */
    /* Bring module out of stop state. */
    mstp            = (*p_rom->pmstp);
    stop_mask       = p_rom->stop_mask;
    (*p_rom->pmstp) = mstp & (~stop_mask);

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    R_BSP_InterruptControl(BSP_INT_SRC_EMPTY, BSP_INT_CMD_FIT_INTERRUPT_ENABLE, &int_ctrl);
#endif

    /* Disable writing to MSTP registers. */
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_CGC_SWR);
} /* End of function r_rsci_iic_power_on() */

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_power_off
 * Description  : Turns off power to a RSCI_IIC channel.
 * Arguments    : channel -
 *                    Which channel to use.
 * Return Value : none
 **********************************************************************************************************************/
void r_rsci_iic_power_off(uint8_t channel)
{
    R_BSP_VOLATILE_EVENACCESS const rsci_iic_ch_rom_t * p_rom = g_rsci_iic_handles[channel]->prom;
    
    uint32_t mstp;
    uint32_t stop_mask;

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    bsp_int_ctrl_t int_ctrl;
#endif

    /* Enable writing to MSTP registers. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_CGC_SWR);

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    R_BSP_InterruptControl(BSP_INT_SRC_EMPTY, BSP_INT_CMD_FIT_INTERRUPT_DISABLE, &int_ctrl);
#endif

    /* Disable selected RSCI_IIC Channel. */
    /* Put module in stop state. */
    mstp            = (*p_rom->pmstp);
    stop_mask       = p_rom->stop_mask;
    (*p_rom->pmstp) = mstp | stop_mask;

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    R_BSP_InterruptControl(BSP_INT_SRC_EMPTY, BSP_INT_CMD_FIT_INTERRUPT_ENABLE, &int_ctrl);
#endif

    /* Disable writing to MSTP registers. */
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_CGC_SWR);
} /* End of function r_rsci_iic_power_off() */

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_io_open
 * Description  : Open Port Processing
 *                Sets ports to input mode. Ports input pull-up becomes "Off".
 * Arguments    : uint8_t port_gr      ;   port group
 *                uint8_t pin_num      ;   pin number
 * Return Value : None
 **********************************************************************************************************************/
void r_rsci_iic_io_open(uint8_t port_gr, uint8_t pin_num)
{

    R_BSP_VOLATILE_EVENACCESS uint8_t * const p_pcr = \
            (uint8_t *)((uint32_t)RSCI_IIC_PRV_PCR_BASE_REG+(uint32_t)port_gr);/* Get p_pcr */

    R_BSP_VOLATILE_EVENACCESS uint8_t * const p_pdr = \
            (uint8_t *)((uint32_t)RSCI_IIC_PRV_PDR_BASE_REG+(uint32_t)port_gr);/* Get p_pdr */

    R_BSP_VOLATILE_EVENACCESS uint8_t * const p_odr0 = \
            (uint8_t *)((uint32_t)RSCI_IIC_PRV_ODR0_BASE_REG+(uint32_t)(port_gr*2));/* Get p_odr0 */

    R_BSP_VOLATILE_EVENACCESS uint8_t * const p_odr1 = \
            (uint8_t *)((uint32_t)RSCI_IIC_PRV_ODR1_BASE_REG+(uint32_t)(port_gr*2));/* Get p_odr1 */

    R_BSP_VOLATILE_EVENACCESS uint8_t * const p_dscr = \
            (uint8_t *)((uint32_t)RSCI_IIC_PRV_DSCR_BASE_REG+(uint32_t)port_gr);/* Get p_dscr */

    /* Sets the port register */
    (*p_dscr) |= (1U<<pin_num); /* drive capacity control : High-drive output */
    (*p_pcr)  &= (~(1U<<pin_num)); /* input pull-up resister : off */
    (*p_pdr)  &= (~(1U<<pin_num)); /* input mode */

    /* Set N-channel open-drain output */
    if (pin_num <= 3)
    {
        (*p_odr0) |= (0x01 << (2*pin_num));
    }
    else
    {
        (*p_odr1) |= (0x01 << (2*(pin_num & 0x03)));
    }

    /* dummy read */
    if (*p_odr1)
    {
        R_BSP_NOP();
    }
} /* End of function r_rsci_iic_io_open() */

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_init_io_register
 * Description  : Initializes RSCI_IIC register.
 * Arguments    : rsci_iic_info_t * p_rsci_iic_info     ;   IIC Information
 * Return Value : RSCI_IIC_SUCCESS                      ; Successful operation
 *              : RSCI_IIC_ERR_INVALID_ARG              ; Parameter error
 **********************************************************************************************************************/
rsci_iic_return_t r_rsci_iic_init_io_register(rsci_iic_info_t * p_rsci_iic_info)
{
    rsci_regs_t pregs = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom->regs;

    R_BSP_VOLATILE_EVENACCESS const rsci_iic_ch_rom_t * p_rom = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom;

    /* Sets SCLn and SDAn to non-driven state. */
    /* SCR0 -  Control Register 0
     b31:b25 Reserved - These bits are read as 0.
     b24     SSE - Valid in simple SPI Mode
     b21     TEIE - Transmit End Interrupt enable - TEI Interrupt request is enable.
     b20     TIE - Transmit Interrupt enable - TXI Interrupt request is enable.
     b19:b17 Reserved - These bits are read as 0.
     b16     RIE - Receive Interrupt enable - RXI and ERI Interrupt requests are enable.
     b15:b11 Reserved - These bits are read as 0.
     b10     IDSEL - Valid only in asynchronous mode.
     b9      DCME - Valid only in asynchronous mode.
     b8      MPIE - Valid in asynchronous mode and Manchester mode.
     b7:b5   Reserved - These bits are read as 0.
     b4      TE - Transmit Enable - Serial transmission is enabled.
     b3:1    Reserved - These bits are read as 0.
     b0      RE - Reception Enable - Serial Reception is enable. */
    /* Confirm SCR0 bits are 0 before setting. */
    pregs->SCR0.LONG = RSCI_IIC_SCR0_INIT;

    /* Sets a transfer clock. */
    /* Includes I/O register read operation at the end of the following function. */
    if (RSCI_IIC_SUCCESS != rsci_iic_set_frequency(p_rsci_iic_info))
    {
        return RSCI_IIC_ERR_INVALID_ARG;
    }

    /* Setting noise filter, communication pin status, parity check, CTS/RTS Function */
    /* SCR1 - Control register 1
     b31:b29 Reserved - These bits are read as 0.
     b28     NFEN - Digital noise filter enable.
     b27     Reserved - These bits are read as 0.
     b26:b24 NFCS - Noise Filter Clock Select.
     b23:b21 Reserved - These bits are read as 0.
     b20     HDSEL - Set to 0 in simple I2C Mode
     b19:b17 Reserved - These bits are read as 0.
     b16     LOOP - Not used in simple I2C Mode.
     b15:b14 Reserved - These bits are read as 0.
     b13     RINV - Receiver input invert.
     b12     TINV - Transmitter input invert
     b11:b10 Reserved - These bits are read as 0.
     b9      PM - Parity mode.
     b8      PE - Parity enable.
     b7:b6   Reserved - These bits are read as 0.
     b5      SPB2IO - Serial Port Break I/O.
     b4      SPB2DT - Serial Port Break Data.
     b3:b2   Reserved - These bits are read as 0.
     b1      CRSEP - CTS/RTS Seperation - Set to 0 in simple I2C Mode.
     b0      CTSE - CTS Enable. */
    pregs->SCR1.LONG     = RSCI_IIC_SCR1_INIT;
    pregs->SCR1.BIT.NFEN = p_rom->df_sel;
    pregs->SCR1.BIT.NFCS = p_rom->df_clk;

    /* Resets RSCI IIC internal status. */
    /* SISCR - I2C Clear Status Register
     b3     IICSTIFC - Clear SISR.IICSTIF Flag */
    pregs->SISCR.BIT.IICSTIFC = RSCI_IIC_STIF_CLEAR;

    /* SSCR  - Status clear register */
    pregs->SSCR.LONG = RSCI_IIC_SSCR_CLEAR; /* Ignore clearing TDRE Flag */

    return RSCI_IIC_SUCCESS;

} /* End of function r_rsci_iic_init_io_register() */

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_clear_io_register
 * Description  : Reset RSCI I/O register.
 * Arguments    : rsci_iic_info_t * p_rsci_iic_info     ;   IIC Information
 * Return Value : None
 **********************************************************************************************************************/
void r_rsci_iic_clear_io_register(rsci_iic_info_t * p_rsci_iic_info)
{
    rsci_regs_t pregs = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom->regs;

    /* Initializes RSCI I/O register */
    pregs->SCR0.LONG  = RSCI_IIC_SCR0_INIT;
    pregs->SCR2.LONG  = RSCI_IIC_SCR2_INIT;
    pregs->SCR3.LONG  = RSCI_IIC_SCR3_INIT;

    pregs->SCR2.BIT.BRR        = RSCI_IIC_BRR_INIT;
    pregs->SCR1.LONG           = RSCI_IIC_SCR1_INIT;
    pregs->SIMR.LONG           = RSCI_IIC_SIMR_INIT;
    pregs->SISCR.BIT.IICSTIFC  = RSCI_IIC_STIF_CLEAR;

} /* End of function r_rsci_iic_clear_io_register() */

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_int_disable
 * Description  : Disables interrupt.
 *              : Sets interrupt source priority.
 *              : Clears interrupt request register.
 * Arguments    : rsci_iic_info_t * p_rsci_iic_info     ;   IIC Information
 * Return Value : None
 **********************************************************************************************************************/
void r_rsci_iic_int_disable(rsci_iic_info_t * p_rsci_iic_info)
{
    R_BSP_VOLATILE_EVENACCESS const rsci_iic_ch_rom_t * p_rom = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom;
    uint32_t ipl;
    uint8_t  icu_txi;
    uint8_t  txi_en_mask;
    uint32_t icu_tei;
    uint32_t tei_en_mask;
#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    bsp_int_ctrl_t int_ctrl;
#endif

    /* TEI interrupt set to callback function of group interrupt in bsp */
    R_BSP_InterruptWrite(p_rom->grp_tei_def, (bsp_int_cb_t) (FIT_NO_FUNC));

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    R_BSP_InterruptControl(BSP_INT_SRC_EMPTY, BSP_INT_CMD_FIT_INTERRUPT_DISABLE, &int_ctrl);
#endif

    /* Disables interrupt. */
    /* Disables TXI interrupt request enable register. */
    icu_txi            = (*p_rom->picu_txi);
    txi_en_mask        = p_rom->txi_en_mask;
    (*p_rom->picu_txi) = icu_txi & (~txi_en_mask);

    /* Disables TEI interrupt request enable register. */
    icu_tei            = (*p_rom->picu_tei);
    tei_en_mask        = p_rom->tei_en_mask;
    (*p_rom->picu_tei) = icu_tei & (~tei_en_mask);

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    R_BSP_InterruptControl(BSP_INT_SRC_EMPTY, BSP_INT_CMD_FIT_INTERRUPT_ENABLE, &int_ctrl);
#endif

    /* Clears interrupt source priority. */
    (*p_rom->pipr) = 0; /* Clears TXI interrupt source priority register. */

    /* dummy read */
    if (*p_rom->pipr)
    {
        R_BSP_NOP();
    }

    /* Disables interrupt request enable register. */
    ipl = 0; /* Clears TEI interrupt source priority register. */
    R_BSP_InterruptControl(p_rom->grp_tei_def, BSP_INT_CMD_GROUP_INTERRUPT_DISABLE, (void *) &ipl);

    /* Clears the interrupt request register. */
    rsci_iic_clear_ir_flag(p_rsci_iic_info);
} /* End of function r_rsci_iic_int_disable() */

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_int_enable
 * Description  : Clears interrupt request register.
 *              : Enables interrupt.
 * Arguments    : rsci_iic_info_t * p_rsci_iic_info     ;   IIC Information
 * Return Value : None
 **********************************************************************************************************************/
void r_rsci_iic_int_enable(rsci_iic_info_t * p_rsci_iic_info)
{
    R_BSP_VOLATILE_EVENACCESS const rsci_iic_ch_rom_t * p_rom = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom;

    uint32_t      ipl;
    bsp_int_src_t grp_tei_def;
    uint8_t       icu_txi;
    uint8_t       txi_en_mask;
    uint32_t      icu_tei;
    uint32_t      tei_en_mask;
    uint8_t       ipr_set_val;

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    bsp_int_ctrl_t int_ctrl;
#endif

    /* Clears the interrupt request register. */
    rsci_iic_clear_ir_flag(p_rsci_iic_info);

    /* TEI interrupt set to callback function of group interrupt in bsp */
    grp_tei_def = p_rom->grp_tei_def;

    /* Cast to bsp_int_cb_t */
    R_BSP_InterruptWrite(grp_tei_def, (bsp_int_cb_t) (*p_rom->grp_tei_func));

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    R_BSP_InterruptControl(BSP_INT_SRC_EMPTY, BSP_INT_CMD_FIT_INTERRUPT_DISABLE, &int_ctrl);
#endif

    /* Enables interrupt. */
    /* Enables TXI interrupt request enable register. */
    icu_txi            = (*p_rom->picu_txi);
    txi_en_mask        = p_rom->txi_en_mask;
    (*p_rom->picu_txi) = icu_txi | txi_en_mask;

    /* Enables TEI interrupt request enable register. */
    icu_tei            = (*p_rom->picu_tei);
    tei_en_mask        = p_rom->tei_en_mask;
    (*p_rom->picu_tei) = icu_tei | tei_en_mask;

#if ((R_BSP_VERSION_MAJOR == 5) && (R_BSP_VERSION_MINOR >= 30)) || (R_BSP_VERSION_MAJOR >= 6)
    R_BSP_InterruptControl(BSP_INT_SRC_EMPTY, BSP_INT_CMD_FIT_INTERRUPT_ENABLE, &int_ctrl);
#endif

    /* Sets interrupt source priority. */
    ipr_set_val    = p_rom->ipr_set_val;
    (*p_rom->pipr) = ipr_set_val; /* Sets TXI interrupt source priority register. */

    /* dummy read */
    if (*p_rom->pipr)
    {
        R_BSP_NOP();
    }

    /* Enables interrupt request enable register. */
    ipl = p_rom->ipr_set_val; /* Sets TEI interrupt source priority register. */
    R_BSP_InterruptControl(p_rom->grp_tei_def, BSP_INT_CMD_GROUP_INTERRUPT_ENABLE, (void *) &ipl);
} /* End of function r_rsci_iic_int_enable() */

/***********************************************************************************************************************
 * Function Name: rsci_iic_set_frequency
 * Description  : Set IIC Frequency Processing.
 *                Sets SMR,BRR registers.
 * Arguments    : rsci_iic_info_t * p_rsci_iic_info   ;   IIC Information
 * Return Value : RSCI_IIC_SUCCESS                    ; Successful operation
 *              : RSCI_IIC_ERR_INVALID_ARG            ; Parameter error
 **********************************************************************************************************************/
static rsci_iic_return_t rsci_iic_set_frequency(rsci_iic_info_t * p_rsci_iic_info)
{
    volatile uint16_t brr_n     = 32U; /* default: 64*2^(2*0-1) = 32 */
    volatile uint8_t  cks_value = 0U; /* default: PCLK/1 */
    volatile uint32_t brr_value = 0U;

    uint32_t pclk;
    uint16_t brr_n_tmp;
    uint8_t  cks_value_tmp;

    rsci_regs_t pregs = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom->regs;

    R_BSP_VOLATILE_EVENACCESS const rsci_iic_ch_rom_t * p_rom = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom;

    pclk = BSP_PCLKA_HZ;

    /*  ---- Calculation BRR ---- */
    /* Macro definition does not have the type of declaration. The cast for the calculation of the floating point, 
     has been cast in the double type. After that, it is cast to type long to fit on the left-hand side. 
     Calculation results are not affected by casting, it is no problem. */
    brr_n_tmp = brr_n;

    /* Cast to double */
    brr_value = (uint32_t)((double)((double)((double)pclk / (brr_n_tmp *(p_rom->bitrate)))) - 1);

    /* Set clock source */
    /* WAIT_LOOP */
    while (brr_value > 255)
    {
        /* Counter over 0xff */
        switch (brr_n)
        {
            case 32 :
                brr_n     = 128; /* 64*(2^(2*1-1)) */
                cks_value = 1; /* clock select: PCLK/4 */
                break;

            case 128 :
                brr_n     = 512; /* 64*(2^(2*2-1))  */
                cks_value = 2; /* clock select: PCLK/16 */
                break;

            case 512 :
                brr_n     = 2048; /* 64*(2^(2*3-1)) */
                cks_value = 3; /* clock select: PCLK/64 */
                break;

            default :

                /* nothing to do */
                break;
        }

        /*  ---- Calculation BRR ---- */
        /* Macro definition does not have the type of declaration. The cast for the calculation of the floating point, 
         has been cast in the double type. After that, it is cast to type long to fit on the left-hand side. 
         Calculation results are not affected by casting, it is no problem. */
        brr_n_tmp = brr_n;

        /* Cast to double */
        brr_value = (uint32_t) ((double)(((double)pclk / (brr_n_tmp *(p_rom->bitrate)))) - 1);

        /* When the clock source of the on-chip baud rate generator is PCLK/64 and when the value
         of brr_value is greater than 255. */
        if ((3 == cks_value) && (255 < brr_value))
        {
            brr_value = 255;
        }
    }

    cks_value_tmp             = cks_value;
    pregs->SCR2.BIT.CKS       = cks_value_tmp; /* Sets SMR */
    pregs->SCR2.BIT.BRR       = brr_value; /* Sets BRR */

    return RSCI_IIC_SUCCESS;

} /* End of function rsci_iic_set_frequency() */

/***********************************************************************************************************************
 * Function Name: r_rsci_iic_mpc_setting
 * Description  : Set RSCI_IIC multi-function pin controller.
 * Arguments    : uint8_t port_gr      ;   port group
 *                uint8_t pin_num      ;   pin number
 *                uint8_t set_value    ;   value of pin function select setting
 * Return Value : None
 **********************************************************************************************************************/
void r_rsci_iic_mpc_setting(uint8_t port_gr, uint8_t pin_num, uint8_t set_value)
{
    R_BSP_VOLATILE_EVENACCESS uint8_t * const p_pmr = \
            (uint8_t *)((uint32_t)RSCI_IIC_PRV_PMR_BASE_REG+(uint32_t)port_gr); /* Get p_pmr */

    R_BSP_VOLATILE_EVENACCESS uint8_t * const p_pfs = \
            (uint8_t *)((uint32_t)RSCI_IIC_PRV_PFS_BASE_REG+(uint32_t)((port_gr*8)+pin_num)); /* Get p_pfs */

    if ((*p_pfs) != set_value)
    {
        (*p_pmr) &= (~(1U << pin_num)); /* Uses as a GPIO (Input port). */
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC); /* Enables the PFS register writing. */
        (*p_pfs) = set_value; /* Pin function select to "SSCL/SSDA" or "Hi-Z" pin. */
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC); /* Disables the PFS register writing. */

        /* Verifies "set_value" (setting value for the PFS register). */
        /* If "set_value" is a value other than 0 (default), sets the pin mode control bit to be used 
         as I/O port for peripheral functions. */
        if (RSCI_IIC_MPC_SSCL_INIT != set_value)
        {
            (*p_pmr) |= (1U << pin_num); /* Uses as RSCI_IIC (SSCL/SSDA). */
        }

        /* dummy read */
        if (*p_pmr)
        {
            R_BSP_NOP();
        }
    }
} /* End of function r_rsci_iic_mpc_setting() */

/***********************************************************************************************************************
 * Function Name: rsci_iic_clear_ir_flag
 * Description  : Clears Interrupt Request Flag Processing.
 *                Clears interrupt request register.
 * Arguments    : rsci_iic_info_t * p_rsci_iic_info     ;   IIC Information
 * Return Value : None
 **********************************************************************************************************************/
static void rsci_iic_clear_ir_flag(rsci_iic_info_t * p_rsci_iic_info)
{
    rsci_regs_t pregs = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom->regs;

    R_BSP_VOLATILE_EVENACCESS const rsci_iic_ch_rom_t * p_rom = g_rsci_iic_handles[p_rsci_iic_info->ch_no]->prom;

    /* Checks IR flag. */
    /* If IR flag is set, clears IR flag. */

    if (RSCI_IIC_IR_SET == (*p_rom->pir_txi))
    {
        /* Initializes ICIER->SCR0 register. */
        pregs->SCR0.LONG = RSCI_IIC_SCR0_INIT;

        /* WAIT_LOOP */
        while (RSCI_IIC_SCR0_INIT != pregs->SCR0.LONG)
        {
            /* nothing to do */
            R_BSP_NOP();
        }

        /* Clears TXI interrupt request register. */
        (*p_rom->pir_txi) = RSCI_IIC_IR_CLR;

        /* dummy read */
        if (*p_rom->pir_txi)
        {
            R_BSP_NOP();
        }
    }
} /* End of function rsci_iic_clear_ir_flag() */

    #if RSCI_IIC_CFG_CH10_INCLUDED
/***********************************************************************************************************************
 * Function Name: rsci_iic_int_rsci_iic10_txi_isr
 * Description  : Interrupt TXI handler for channel 10.
 *                Types of interrupt requests transmission end.
 * Arguments    : None
 * Return Value : None
 **********************************************************************************************************************/
R_BSP_PRAGMA_STATIC_INTERRUPT (rsci_iic_int_rsci_iic10_txi_isr, VECT_RSCI10_TXI)
R_BSP_ATTRIB_STATIC_INTERRUPT void rsci_iic_int_rsci_iic10_txi_isr(void)
{
    r_rsci_iic_txi_isr_processing(RSCI_IIC_NUM_CH10);

    /* Calls advance function */
    r_rsci_iic_advance(g_rsci_iic_handles[RSCI_IIC_NUM_CH10]->prsci_iic_info_ch);
} /* End of function rsci_iic_int_rsci_iic10_txi_isr() */
    #endif

    #if RSCI_IIC_CFG_CH11_INCLUDED
/***********************************************************************************************************************
 * Function Name: rsci_iic_int_rsci_iic11_txi_isr
 * Description  : Interrupt TXI handler for channel 11.
 *                Types of interrupt requests transmission end.
 * Arguments    : None
 * Return Value : None
 **********************************************************************************************************************/
R_BSP_PRAGMA_STATIC_INTERRUPT (rsci_iic_int_rsci_iic11_txi_isr, VECT_RSCI11_TXI)
R_BSP_ATTRIB_STATIC_INTERRUPT void rsci_iic_int_rsci_iic11_txi_isr(void)
{
    r_rsci_iic_txi_isr_processing(RSCI_IIC_NUM_CH11);

    /* Calls advance function */
    r_rsci_iic_advance(g_rsci_iic_handles[RSCI_IIC_NUM_CH11]->prsci_iic_info_ch);
} /* End of function rsci_iic_int_rsci_iic11_txi_isr() */
    #endif

    #if RSCI_IIC_CFG_CH10_INCLUDED
/***********************************************************************************************************************
 * Function Name: rsci_iic_int_rsci_iic10_tei_isr
 * Description  : Interrupt TEI handler for channel 10.
 *                Types of interrupt requests transfer error or event generation.
 *              : The event generations are arbitration-lost, NACK detection, timeout detection, 
 *              : start condition detection, and stop condition detection.
 * Arguments    : None
 * Return Value : None
 **********************************************************************************************************************/
void rsci_iic_int_rsci_iic10_tei_isr(void)
{
    r_rsci_iic_tei_isr_processing(RSCI_IIC_NUM_CH10);

    /* Calls advance function */
    r_rsci_iic_advance(g_rsci_iic_handles[RSCI_IIC_NUM_CH10]->prsci_iic_info_ch);
} /* End of function rsci_iic_int_rsci_iic10_tei_isr() */
    #endif

    #if RSCI_IIC_CFG_CH11_INCLUDED
/***********************************************************************************************************************
 * Function Name: rsci_iic_int_rsci_iic11_tei_isr
 * Description  : Interrupt TEI handler for channel 11.
 *                Types of interrupt requests transfer error or event generation.
 *              : The event generations are arbitration-lost, NACK detection, timeout detection, 
 *              : start condition detection, and stop condition detection.
 * Arguments    : None
 * Return Value : None
 **********************************************************************************************************************/
void rsci_iic_int_rsci_iic11_tei_isr(void)
{
    r_rsci_iic_tei_isr_processing(RSCI_IIC_NUM_CH11);

    /* Calls advance function */
    r_rsci_iic_advance(g_rsci_iic_handles[RSCI_IIC_NUM_CH11]->prsci_iic_info_ch);
} /* End of function rsci_iic_int_rsci_iic11_tei_isr() */
    #endif

#endif /* BSP_MCU_RX660 */

