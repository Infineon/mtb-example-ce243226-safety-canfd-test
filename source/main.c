/*******************************************************************************
 * File Name:   main.c
 *
 * Description: This is the source code for the MTB STL CAN FD Safety Test
 *              for XMC5000 MCUs.
 *
 *              Initializes CAN FD (channel 0) with internal loopback, runs
 *              the CAN FD self-test once at startup using the
 *              SelfTest_CANFD() API, prints the result, and halts.
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
#include "cybsp.h"
#include "cy_pdl.h"
#include "mtb_hal.h"
#include "cy_retarget_io.h"
#include "self_test.h"

/*******************************************************************************
* Global Variables
*******************************************************************************/
/* Debug UART context and HAL wrapper object (retarget-io / printf) */
static cy_stc_scb_uart_context_t DEBUG_UART_context;
static mtb_hal_uart_t            DEBUG_UART_hal_obj;

/*******************************************************************************
* Function Name: main
*********************************************************************************
* Summary:
* This is the main function. It does...
*    1. Initialize the device and board peripherals and retarget-io for prints
*    2. Initialize the CAN FD (channel 0) for internal loopback testing
*    3. Run the CAN FD self-test once
*    4. Print PASS/FAIL result and halt
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;
    uint8_t ret;

    /* Initialize the device and board peripherals */
    result = cybsp_init();
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Initialize the debug UART (SCB0) */
    result = Cy_SCB_UART_Init(CYBSP_DEBUG_UART_HW, &CYBSP_DEBUG_UART_config,
                               &DEBUG_UART_context);
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }
    Cy_SCB_UART_Enable(CYBSP_DEBUG_UART_HW);

    /* Setup the HAL UART wrapper (required by retarget-io) */
    result = mtb_hal_uart_setup(&DEBUG_UART_hal_obj, &CYBSP_DEBUG_UART_hal_config,
                                 &DEBUG_UART_context, NULL);
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Initialize retarget-io so printf routes to the debug UART */
    result = cy_retarget_io_init(&DEBUG_UART_hal_obj);
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Enable global interrupts */
    __enable_irq();

    /* \x1b[2J\x1b[;H - ANSI ESC sequence for clear screen */
    printf("\x1b[2J\x1b[;H");
    printf("****************** "
           "MTB STL: CAN FD Safety Test"
           " ******************\r\n\n");

    /* Initialize CAN FD (channel 0) */
    if (canfd_self_test_init() != CANFD_TEST_INIT_SUCCESS)
    {
        printf("ERROR: CAN FD initialization failed.\r\n");
        for (;;)
        {
        }
    }

    /* Run the CAN FD self-test. SelfTest_CANFD() configures internal
     * loopback, transmits/receives test frames, and returns a single
     * OK_STATUS/ERROR_STATUS result - no repeated calls are needed. */
    ret = canfd_self_test();

    if (ret == OK_STATUS)
    {
        printf("SUCCESS: CAN FD loopback test passed.\r\n");
    }
    else
    {
        printf("ERROR: CAN FD loopback test failed (status=%d).\r\n", (int)ret);
    }

    printf("\r\nTest complete.\r\n");

    /* Halt - test is done */
    for (;;)
    {
    }
}

/* [] END OF FILE */
