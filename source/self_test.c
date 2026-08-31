/******************************************************************************
 * File Name:   self_test.c
 *
 * Description: Provides CAN FD (channel 0) initialization and the
 *              Class-B CAN FD internal loopback self-test wrapper.
 *
 *              SelfTest_CANFD() configures the channel for internal loopback,
 *              transmits test frames, and verifies reception entirely inside
 *              the peripheral - no external CAN transceiver or wiring is
 *              required.
 *
 * Related Document: See README.md
 *
 *
 *******************************************************************************
 * $ Copyright 2026 Infineon Technologies AG $
 *******************************************************************************/

/*******************************************************************************
* Header Files
*******************************************************************************/
#include "cy_retarget_io.h"
#include "self_test.h"

/*******************************************************************************
* Macros
*******************************************************************************/
/* Enables channel 0 in the MRAM channel mask */
#define CANFD_CHANNEL_MASK    (0x00000001UL)
/* Delay (in microseconds) required before the MRAM can be used after
 * Cy_CANFD_EnableMRAM() */
#define CANFD_MRAM_DELAY_US   (0x0006U)

/*******************************************************************************
* Global Variables
*******************************************************************************/
static cy_stc_canfd_context_t canfd_context;

/*******************************************************************************
* Function Name: CanfdInterruptHandler
********************************************************************************
* Summary:
*  Forwards the CAN FD interrupt to the PDL driver's IRQ handler.
*
* Parameters:
*  void
*
* Return:
*  void
*******************************************************************************/
static void CanfdInterruptHandler(void)
{
    Cy_CANFD_IrqHandler(CYBSP_CANFD_HW, CYBSP_CANFD_CHANNEL_NUM, &canfd_context);
}

/*******************************************************************************
* Function Name: canfd_self_test_init
********************************************************************************
* Summary:
*  Enables the CAN FD MRAM, initializes the CAN FD channel (channel 0),
*  and hooks/enables its interrupt. On XMC5200 (CAT1A), the CAN FD channel
*  interrupt is a system interrupt that is not directly wired to the CPU's
*  NVIC - it must be routed through an NVIC MUX slot first.
*
* Parameters:
*  void
*
* Return:
*  CANFD_TEST_INIT_SUCCESS or CANFD_TEST_INIT_FAILURE
*******************************************************************************/
uint32_t canfd_self_test_init(void)
{
    cy_en_canfd_status_t canfd_status;
    cy_en_sysint_status_t sysint_status;

    cy_stc_sysint_t irq_cfg =
    {
        .intrSrc      = (IRQn_Type)((uint32_t)(NvicMux0_IRQn << CY_SYSINT_INTRSRC_MUXIRQ_SHIFT) | CYBSP_CANFD_IRQ_0),
        .intrPriority = 2UL,
    };

    Cy_CANFD_EnableMRAM(CYBSP_CANFD_HW, CANFD_CHANNEL_MASK, CANFD_MRAM_DELAY_US);

    canfd_status = Cy_CANFD_Init(CYBSP_CANFD_HW, CYBSP_CANFD_CHANNEL_NUM,
                                  &CYBSP_CANFD_config, &canfd_context);
    if (CY_CANFD_SUCCESS != canfd_status)
    {
        return CANFD_TEST_INIT_FAILURE;
    }

    sysint_status = Cy_SysInt_Init(&irq_cfg, &CanfdInterruptHandler);
    if (CY_SYSINT_SUCCESS != sysint_status)
    {
        return CANFD_TEST_INIT_FAILURE;
    }

    NVIC_EnableIRQ((IRQn_Type)NvicMux0_IRQn);

    printf("CAN FD (channel 0) initialized - internal loopback test ready.\r\n\n");

    return CANFD_TEST_INIT_SUCCESS;
}

/*******************************************************************************
* Function Name: canfd_self_test
********************************************************************************
* Summary:
*  Runs the CAN FD internal loopback self-test once. SelfTest_CANFD()
*  configures test mode, transmits a rejected frame (ID 0x60) and an accepted
*  frame (ID 0x52), and verifies the RX FIFO contents, returning a single
*  final pass/fail result.
*
* Parameters:
*  void
*
* Return:
*  OK_STATUS    - test passed
*  ERROR_STATUS - test failed
*******************************************************************************/
uint8_t canfd_self_test(void)
{
    return SelfTest_CANFD(CYBSP_CANFD_HW, CYBSP_CANFD_CHANNEL_NUM,
                           &CYBSP_CANFD_config, &canfd_context,
                           CY_CANFD_TEST_MODE_INTERNAL_LOOP_BACK);
}

/* [] END OF FILE */
