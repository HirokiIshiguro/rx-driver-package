/***********************************************************************************************************************
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : r_rsci_iic_rx671_private.h
 * Description  : Functions for using RSCI_IIC on RX devices. 
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 30.10.2025 1.00     First Release
 **********************************************************************************************************************/

/***********************************************************************************************************************
 Macro definitions
 **********************************************************************************************************************/
/* Guards against multiple inclusion */
#ifndef RSCI_IIC_RX671_PRIVATE_H
    #define RSCI_IIC_RX671_PRIVATE_H

/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
/* Access to peripherals and board defines. */
    #include "platform.h"
    #ifdef BSP_MCU_RX671

/***********************************************************************************************************************
 Macro definitions
 **********************************************************************************************************************/
/*----------------------------------------------------------------------------*/
/*   Define register setting.                                                 */
/*----------------------------------------------------------------------------*/
/* Sets to use multi-function pin controller. */
        #define RSCI_IIC_MPC_SSDA_INIT             ((uint8_t)(0x00)) /* Pin function select to Hi-Z */
        #define RSCI_IIC_MPC_SSCL_INIT             ((uint8_t)(0x00)) /* Pin function select to Hi-Z */

        #if (RSCI_IIC_CFG_CH10_INCLUDED)
            #define RSCI_IIC_MPC_SSDA010_ENABLE    ((uint8_t)(0x2C)) /* Pin function select to RSCI010 SSDA pin:b101100 */
            #define RSCI_IIC_MPC_SSCL010_ENABLE    ((uint8_t)(0x2C)) /* Pin function select to RSCI010 SSCL pin:b101100 */
        #endif /* RSCI_IIC_CFG_CH10_INCLUDED */

        #if RSCI_IIC_CFG_CH11_INCLUDED
            #define RSCI_IIC_MPC_SSDA011_ENABLE    ((uint8_t)(0x2C)) /* Pin function select to RSCI011 SSDA pin:b101100 */
            #define RSCI_IIC_MPC_SSCL011_ENABLE    ((uint8_t)(0x2C)) /* Pin function select to RSCI011 SSCL pin:b101100 */
        #endif /* RSCI_IIC_CFG_CH11_INCLUDED */

/* Interrupt register setting */
        #define RSCI_IIC_IR_CLR               ((uint8_t)(0x00)) /* Clears interrupt request register. */
        #define RSCI_IIC_IR_SET               ((uint8_t)(0x01)) /* Sets interrupt request register. */

/* Common register setting */
        #define RSCI_IIC_SCR3_MOD_INIT        ((uint8_t)(0x04)) /* Initializes SCR3.MOD to be I2C Mode. */
        #define RSCI_IIC_SCR3_CKE_INIT        ((uint8_t)(0x00)) /* Initializes SCR3.CKE. */

        #define RSCI_IIC_SCR0_INIT            ((uint32_t)(0x00000000)) /* Initializes SCR0. */
        #define RSCI_IIC_SCR1_INIT            ((uint32_t)(0x00000000)) /* Initializes SCR1. */
        #define RSCI_IIC_SCR2_INIT            ((uint32_t)(0x00000000)) /* Initializes SCR2. */
        #define RSCI_IIC_SCR3_INIT            ((uint32_t)(0x00000000)) /* Initializes SCR3. */

        #define RSCI_IIC_SCR0_ENABLE          ((uint32_t)(0x00300011)) /* Enable bit: TEIE, TIE, TE, RE bit */

        #define RSCI_IIC_SCR0_TE_RE           ((uint32_t)(0x00000011)) /* Enable bit:TE,RE bit */

        #define RSCI_IIC_BRR_INIT             ((uint8_t)(0xFF)) /* Initializes BRR. */

        #define RSCI_IIC_SIMR_INIT            ((uint8_t)(0x00)) /* Initializes SIMR. */

        #define RSCI_IIC_IICSTIF_CLEAR        ((uint8_t)(1)) /* Clear Generation condition. */

        #define RSCI_IIC_ST_CON_GENERATED     ((uint32_t)(0x51 << 16)) /* ST setting. */
        #define RSCI_IIC_RST_CON_GENERATED    ((uint32_t)(0x52 << 16)) /* RST setting. */
        #define RSCI_IIC_SP_CON_GENERATED     ((uint32_t)(0x54 << 16)) /* SP setting. */

        #define RSCI_IIC_COND_GEN_BIT_MASK    (BIT23_MASK | BIT22_MASK | BIT21_MASK | BIT20_MASK | BIT18_MASK | BIT17_MASK | BIT16_MASK)

/* Base register of DSCR used to calculate all DSCR register addresses. This is constant for all supported MCUs. */
    #define RSCI_IIC_PRV_DSCR_BASE_REG ((uint8_t volatile *)(&MPC.PWPR.BYTE-63))

/***********************************************************************************************************************
 Typedef definitions
 **********************************************************************************************************************/
/* define rsci register type */
typedef volatile struct st_rsci R_BSP_EVENACCESS_SFR * rsci_regs_t;

/*----------------------------------------------------------------------------*/
/*   Define internal rsci_iic information structure type.                      */
/*----------------------------------------------------------------------------*/
/* Specifies register addresses and bits associated with the RSCI, module-stop, and ICU. */
typedef struct st_rsci_iic_ch_rom /* RSCI ROM info for channel control block */
{
    mcu_lock_t                               hd_lock;     /* Hardware Lock number */
    rsci_regs_t                              regs;        /* base ptr to ch registers */
    volatile uint32_t R_BSP_EVENACCESS_SFR * pmstp;       /* ptr to mstp register */
    uint32_t                                 stop_mask;   /* mstp mask to disable ch */
    volatile uint8_t R_BSP_EVENACCESS_SFR  * pipr;        /* ptr to IPR register */
    volatile uint8_t R_BSP_EVENACCESS_SFR  * pir_txi;     /* ptr to TXI IR register */
    volatile uint32_t R_BSP_EVENACCESS_SFR * pir_tei; /* ptr to TEI IR register */
    uint32_t                                 tei_ir_mask; /* bit mask to enable/disable txi INT in ICU */
    volatile uint8_t R_BSP_EVENACCESS_SFR  * picu_txi;
    uint8_t                                  txi_en_mask; /* bit mask to enable/disable txi INT in ICU */
    volatile uint32_t R_BSP_EVENACCESS_SFR * picu_tei;
    uint32_t                                 tei_en_mask; /* bit mask to enable/disable tei INT in ICU */
    bsp_int_src_t                            grp_tei_def;
    void                                   (*grp_tei_func) (void);
    uint8_t                                  ipr_set_val;
    uint8_t                                  sscl_port_gr;
    uint8_t                                  sscl_port_pin;
    uint8_t                                  sscl_en_val;
    uint8_t                                  ssda_port_gr;
    uint8_t                                  ssda_port_pin;
    uint8_t                                  ssda_en_val;
    uint8_t                                  ssda_delay;
    uint32_t                                 bitrate;
    uint8_t                                  df_sel;
    uint8_t                                  df_clk;
} rsci_iic_ch_rom_t;

/* CHANNEL CONTROL BLOCK */
typedef struct st_rsci_iic_ch_ctrl /* RSCI channel control (for handle) */
{
    const rsci_iic_ch_rom_t * prom;              /* pointer to rom info */
    rsci_iic_api_event_t      api_event;         /* Event flag pointer */
    rsci_iic_api_mode_t       api_mode;          /* Internal mode of control protocol */
    rsci_iic_api_status_t     api_n_status;      /* Internal Status of Now */
    rsci_iic_api_status_t     api_b_status;      /* Internal Status of Before */
    uint8_t                   mode;              /* Check I2C condition */
    rsci_iic_info_t         * prsci_iic_info_ch; /* Channel RSCI driver information */
} rsci_iic_ch_ctrl_t;

typedef rsci_iic_ch_ctrl_t * rsci_iic_hdl_t;

/***********************************************************************************************************************
 Exported global variables
 **********************************************************************************************************************/
extern const rsci_iic_hdl_t g_rsci_iic_handles[RSCI_IIC_NUM_CH_MAX];

/***********************************************************************************************************************
 Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
extern void r_rsci_iic_power_on (uint8_t channel);
extern void r_rsci_iic_power_off (uint8_t channel);
extern void r_rsci_iic_io_open (uint8_t port_gr, uint8_t pin_num);
extern rsci_iic_return_t r_rsci_iic_init_io_register (rsci_iic_info_t * p_rsci_iic_info);
extern void r_rsci_iic_clear_io_register (rsci_iic_info_t * p_rsci_iic_info);
extern void r_rsci_iic_int_disable (rsci_iic_info_t * p_rsci_iic_info);
extern void r_rsci_iic_int_enable (rsci_iic_info_t * p_rsci_iic_info);
extern void r_rsci_iic_mpc_setting (uint8_t port_gr, uint8_t pin_num, uint8_t set_value);

/*----------------------------------------------------------------------------*/
/*   Interrupt Function                                                       */
/*----------------------------------------------------------------------------*/
        #if RSCI_IIC_CFG_CH10_INCLUDED
/* ---- RSCI IIC CH10 TEI ---- */
void rsci_iic_int_rsci_iic10_tei_isr(void);
        #endif

        #if RSCI_IIC_CFG_CH11_INCLUDED
/* ---- RSCI IIC CH11 TEI ---- */
void rsci_iic_int_rsci_iic11_tei_isr(void);
        #endif

    #endif /* BSP_MCU_RX671 */
#endif /* RSCI_IIC_RX671_PRIVATE_H */

