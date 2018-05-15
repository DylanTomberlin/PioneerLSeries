/*******************************************************************************
* File Name: QuadDec0.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the QuadDec0
*  component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "QuadDec0.h"

uint8 QuadDec0_initVar = 0u;


/*******************************************************************************
* Function Name: QuadDec0_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default QuadDec0 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (QuadDec0__QUAD == QuadDec0_CONFIG)
        QuadDec0_CONTROL_REG = QuadDec0_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        QuadDec0_TRIG_CONTROL1_REG  = QuadDec0_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        QuadDec0_SetInterruptMode(QuadDec0_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        QuadDec0_SetCounterMode(QuadDec0_COUNT_DOWN);
        QuadDec0_WritePeriod(QuadDec0_QUAD_PERIOD_INIT_VALUE);
        QuadDec0_WriteCounter(QuadDec0_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (QuadDec0__QUAD == QuadDec0_CONFIG) */

    #if (QuadDec0__TIMER == QuadDec0_CONFIG)
        QuadDec0_CONTROL_REG = QuadDec0_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        QuadDec0_TRIG_CONTROL1_REG  = QuadDec0_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        QuadDec0_SetInterruptMode(QuadDec0_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        QuadDec0_WritePeriod(QuadDec0_TC_PERIOD_VALUE );

        #if (QuadDec0__COMPARE == QuadDec0_TC_COMP_CAP_MODE)
            QuadDec0_WriteCompare(QuadDec0_TC_COMPARE_VALUE);

            #if (1u == QuadDec0_TC_COMPARE_SWAP)
                QuadDec0_SetCompareSwap(1u);
                QuadDec0_WriteCompareBuf(QuadDec0_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == QuadDec0_TC_COMPARE_SWAP) */
        #endif  /* (QuadDec0__COMPARE == QuadDec0_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (QuadDec0_CY_TCPWM_V2 && QuadDec0_TIMER_UPDOWN_CNT_USED && !QuadDec0_CY_TCPWM_4000)
            QuadDec0_WriteCounter(1u);
        #elif(QuadDec0__COUNT_DOWN == QuadDec0_TC_COUNTER_MODE)
            QuadDec0_WriteCounter(QuadDec0_TC_PERIOD_VALUE);
        #else
            QuadDec0_WriteCounter(0u);
        #endif /* (QuadDec0_CY_TCPWM_V2 && QuadDec0_TIMER_UPDOWN_CNT_USED && !QuadDec0_CY_TCPWM_4000) */
    #endif  /* (QuadDec0__TIMER == QuadDec0_CONFIG) */

    #if (QuadDec0__PWM_SEL == QuadDec0_CONFIG)
        QuadDec0_CONTROL_REG = QuadDec0_CTRL_PWM_BASE_CONFIG;

        #if (QuadDec0__PWM_PR == QuadDec0_PWM_MODE)
            QuadDec0_CONTROL_REG |= QuadDec0_CTRL_PWM_RUN_MODE;
            QuadDec0_WriteCounter(QuadDec0_PWM_PR_INIT_VALUE);
        #else
            QuadDec0_CONTROL_REG |= QuadDec0_CTRL_PWM_ALIGN | QuadDec0_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (QuadDec0_CY_TCPWM_V2 && QuadDec0_PWM_UPDOWN_CNT_USED && !QuadDec0_CY_TCPWM_4000)
                QuadDec0_WriteCounter(1u);
            #elif (QuadDec0__RIGHT == QuadDec0_PWM_ALIGN)
                QuadDec0_WriteCounter(QuadDec0_PWM_PERIOD_VALUE);
            #else 
                QuadDec0_WriteCounter(0u);
            #endif  /* (QuadDec0_CY_TCPWM_V2 && QuadDec0_PWM_UPDOWN_CNT_USED && !QuadDec0_CY_TCPWM_4000) */
        #endif  /* (QuadDec0__PWM_PR == QuadDec0_PWM_MODE) */

        #if (QuadDec0__PWM_DT == QuadDec0_PWM_MODE)
            QuadDec0_CONTROL_REG |= QuadDec0_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (QuadDec0__PWM_DT == QuadDec0_PWM_MODE) */

        #if (QuadDec0__PWM == QuadDec0_PWM_MODE)
            QuadDec0_CONTROL_REG |= QuadDec0_CTRL_PWM_PRESCALER;
        #endif  /* (QuadDec0__PWM == QuadDec0_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        QuadDec0_TRIG_CONTROL1_REG  = QuadDec0_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        QuadDec0_SetInterruptMode(QuadDec0_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (QuadDec0__PWM_PR == QuadDec0_PWM_MODE)
            QuadDec0_TRIG_CONTROL2_REG =
                    (QuadDec0_CC_MATCH_NO_CHANGE    |
                    QuadDec0_OVERLOW_NO_CHANGE      |
                    QuadDec0_UNDERFLOW_NO_CHANGE);
        #else
            #if (QuadDec0__LEFT == QuadDec0_PWM_ALIGN)
                QuadDec0_TRIG_CONTROL2_REG = QuadDec0_PWM_MODE_LEFT;
            #endif  /* ( QuadDec0_PWM_LEFT == QuadDec0_PWM_ALIGN) */

            #if (QuadDec0__RIGHT == QuadDec0_PWM_ALIGN)
                QuadDec0_TRIG_CONTROL2_REG = QuadDec0_PWM_MODE_RIGHT;
            #endif  /* ( QuadDec0_PWM_RIGHT == QuadDec0_PWM_ALIGN) */

            #if (QuadDec0__CENTER == QuadDec0_PWM_ALIGN)
                QuadDec0_TRIG_CONTROL2_REG = QuadDec0_PWM_MODE_CENTER;
            #endif  /* ( QuadDec0_PWM_CENTER == QuadDec0_PWM_ALIGN) */

            #if (QuadDec0__ASYMMETRIC == QuadDec0_PWM_ALIGN)
                QuadDec0_TRIG_CONTROL2_REG = QuadDec0_PWM_MODE_ASYM;
            #endif  /* (QuadDec0__ASYMMETRIC == QuadDec0_PWM_ALIGN) */
        #endif  /* (QuadDec0__PWM_PR == QuadDec0_PWM_MODE) */

        /* Set other values from customizer */
        QuadDec0_WritePeriod(QuadDec0_PWM_PERIOD_VALUE );
        QuadDec0_WriteCompare(QuadDec0_PWM_COMPARE_VALUE);

        #if (1u == QuadDec0_PWM_COMPARE_SWAP)
            QuadDec0_SetCompareSwap(1u);
            QuadDec0_WriteCompareBuf(QuadDec0_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == QuadDec0_PWM_COMPARE_SWAP) */

        #if (1u == QuadDec0_PWM_PERIOD_SWAP)
            QuadDec0_SetPeriodSwap(1u);
            QuadDec0_WritePeriodBuf(QuadDec0_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == QuadDec0_PWM_PERIOD_SWAP) */
    #endif  /* (QuadDec0__PWM_SEL == QuadDec0_CONFIG) */
    
}


/*******************************************************************************
* Function Name: QuadDec0_Enable
********************************************************************************
*
* Summary:
*  Enables the QuadDec0.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    QuadDec0_BLOCK_CONTROL_REG |= QuadDec0_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (QuadDec0__PWM_SEL == QuadDec0_CONFIG)
        #if (0u == QuadDec0_PWM_START_SIGNAL_PRESENT)
            QuadDec0_TriggerCommand(QuadDec0_MASK, QuadDec0_CMD_START);
        #endif /* (0u == QuadDec0_PWM_START_SIGNAL_PRESENT) */
    #endif /* (QuadDec0__PWM_SEL == QuadDec0_CONFIG) */

    #if (QuadDec0__TIMER == QuadDec0_CONFIG)
        #if (0u == QuadDec0_TC_START_SIGNAL_PRESENT)
            QuadDec0_TriggerCommand(QuadDec0_MASK, QuadDec0_CMD_START);
        #endif /* (0u == QuadDec0_TC_START_SIGNAL_PRESENT) */
    #endif /* (QuadDec0__TIMER == QuadDec0_CONFIG) */
    
    #if (QuadDec0__QUAD == QuadDec0_CONFIG)
        #if (0u != QuadDec0_QUAD_AUTO_START)
            QuadDec0_TriggerCommand(QuadDec0_MASK, QuadDec0_CMD_RELOAD);
        #endif /* (0u != QuadDec0_QUAD_AUTO_START) */
    #endif  /* (QuadDec0__QUAD == QuadDec0_CONFIG) */
}


/*******************************************************************************
* Function Name: QuadDec0_Start
********************************************************************************
*
* Summary:
*  Initializes the QuadDec0 with default customizer
*  values when called the first time and enables the QuadDec0.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  QuadDec0_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time QuadDec0_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the QuadDec0_Start() routine.
*
*******************************************************************************/
void QuadDec0_Start(void)
{
    if (0u == QuadDec0_initVar)
    {
        QuadDec0_Init();
        QuadDec0_initVar = 1u;
    }

    QuadDec0_Enable();
}


/*******************************************************************************
* Function Name: QuadDec0_Stop
********************************************************************************
*
* Summary:
*  Disables the QuadDec0.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_BLOCK_CONTROL_REG &= (uint32)~QuadDec0_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the QuadDec0. This function is used when
*  configured as a generic QuadDec0 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the QuadDec0 to operate in
*   Values:
*   - QuadDec0_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - QuadDec0_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - QuadDec0_MODE_QUAD - Quadrature decoder
*         - QuadDec0_MODE_PWM - PWM
*         - QuadDec0_MODE_PWM_DT - PWM with dead time
*         - QuadDec0_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_MODE_MASK;
    QuadDec0_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - QuadDec0_MODE_X1 - Counts on phi 1 rising
*         - QuadDec0_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - QuadDec0_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_QUAD_MODE_MASK;
    QuadDec0_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - QuadDec0_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - QuadDec0_PRESCALE_DIVBY2    - Divide by 2
*         - QuadDec0_PRESCALE_DIVBY4    - Divide by 4
*         - QuadDec0_PRESCALE_DIVBY8    - Divide by 8
*         - QuadDec0_PRESCALE_DIVBY16   - Divide by 16
*         - QuadDec0_PRESCALE_DIVBY32   - Divide by 32
*         - QuadDec0_PRESCALE_DIVBY64   - Divide by 64
*         - QuadDec0_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_PRESCALER_MASK;
    QuadDec0_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the QuadDec0 runs
*  continuously or stops when terminal count is reached.  By default the
*  QuadDec0 operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_ONESHOT_MASK;
    QuadDec0_CONTROL_REG |= ((uint32)((oneShotEnable & QuadDec0_1BIT_MASK) <<
                                                               QuadDec0_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetPWMMode(uint32 modeMask)
{
    QuadDec0_TRIG_CONTROL2_REG = (modeMask & QuadDec0_6BIT_MASK);
}



/*******************************************************************************
* Function Name: QuadDec0_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_PWM_SYNC_KILL_MASK;
    QuadDec0_CONTROL_REG |= ((uint32)((syncKillEnable & QuadDec0_1BIT_MASK)  <<
                                               QuadDec0_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_PWM_STOP_KILL_MASK;
    QuadDec0_CONTROL_REG |= ((uint32)((stopOnKillEnable & QuadDec0_1BIT_MASK)  <<
                                                         QuadDec0_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_PRESCALER_MASK;
    QuadDec0_CONTROL_REG |= ((uint32)((deadTime & QuadDec0_8BIT_MASK) <<
                                                          QuadDec0_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - QuadDec0_INVERT_LINE   - Inverts the line output
*         - QuadDec0_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_INV_OUT_MASK;
    QuadDec0_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: QuadDec0_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_WriteCounter(uint32 count)
{
    QuadDec0_COUNTER_REG = (count & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 QuadDec0_ReadCounter(void)
{
    return (QuadDec0_COUNTER_REG & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - QuadDec0_COUNT_UP       - Counts up
*     - QuadDec0_COUNT_DOWN     - Counts down
*     - QuadDec0_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - QuadDec0_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_UPDOWN_MASK;
    QuadDec0_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_WritePeriod(uint32 period)
{
    QuadDec0_PERIOD_REG = (period & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 QuadDec0_ReadPeriod(void)
{
    return (QuadDec0_PERIOD_REG & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_RELOAD_CC_MASK;
    QuadDec0_CONTROL_REG |= (swapEnable & QuadDec0_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_WritePeriodBuf(uint32 periodBuf)
{
    QuadDec0_PERIOD_BUF_REG = (periodBuf & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 QuadDec0_ReadPeriodBuf(void)
{
    return (QuadDec0_PERIOD_BUF_REG & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_CONTROL_REG &= (uint32)~QuadDec0_RELOAD_PERIOD_MASK;
    QuadDec0_CONTROL_REG |= ((uint32)((swapEnable & QuadDec0_1BIT_MASK) <<
                                                            QuadDec0_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void QuadDec0_WriteCompare(uint32 compare)
{
    #if (QuadDec0_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (QuadDec0_CY_TCPWM_4000) */

    #if (QuadDec0_CY_TCPWM_4000)
        currentMode = ((QuadDec0_CONTROL_REG & QuadDec0_UPDOWN_MASK) >> QuadDec0_UPDOWN_SHIFT);

        if (((uint32)QuadDec0__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)QuadDec0__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (QuadDec0_CY_TCPWM_4000) */
    
    QuadDec0_COMP_CAP_REG = (compare & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 QuadDec0_ReadCompare(void)
{
    #if (QuadDec0_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (QuadDec0_CY_TCPWM_4000) */

    #if (QuadDec0_CY_TCPWM_4000)
        currentMode = ((QuadDec0_CONTROL_REG & QuadDec0_UPDOWN_MASK) >> QuadDec0_UPDOWN_SHIFT);
        
        regVal = QuadDec0_COMP_CAP_REG;
        
        if (((uint32)QuadDec0__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)QuadDec0__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & QuadDec0_16BIT_MASK);
    #else
        return (QuadDec0_COMP_CAP_REG & QuadDec0_16BIT_MASK);
    #endif /* (QuadDec0_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: QuadDec0_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void QuadDec0_WriteCompareBuf(uint32 compareBuf)
{
    #if (QuadDec0_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (QuadDec0_CY_TCPWM_4000) */

    #if (QuadDec0_CY_TCPWM_4000)
        currentMode = ((QuadDec0_CONTROL_REG & QuadDec0_UPDOWN_MASK) >> QuadDec0_UPDOWN_SHIFT);

        if (((uint32)QuadDec0__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)QuadDec0__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (QuadDec0_CY_TCPWM_4000) */
    
    QuadDec0_COMP_CAP_BUF_REG = (compareBuf & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 QuadDec0_ReadCompareBuf(void)
{
    #if (QuadDec0_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (QuadDec0_CY_TCPWM_4000) */

    #if (QuadDec0_CY_TCPWM_4000)
        currentMode = ((QuadDec0_CONTROL_REG & QuadDec0_UPDOWN_MASK) >> QuadDec0_UPDOWN_SHIFT);

        regVal = QuadDec0_COMP_CAP_BUF_REG;
        
        if (((uint32)QuadDec0__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)QuadDec0__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & QuadDec0_16BIT_MASK);
    #else
        return (QuadDec0_COMP_CAP_BUF_REG & QuadDec0_16BIT_MASK);
    #endif /* (QuadDec0_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: QuadDec0_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 QuadDec0_ReadCapture(void)
{
    return (QuadDec0_COMP_CAP_REG & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 QuadDec0_ReadCaptureBuf(void)
{
    return (QuadDec0_COMP_CAP_BUF_REG & QuadDec0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec0_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec0_TRIG_LEVEL     - Level
*     - QuadDec0_TRIG_RISING    - Rising edge
*     - QuadDec0_TRIG_FALLING   - Falling edge
*     - QuadDec0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_TRIG_CONTROL1_REG &= (uint32)~QuadDec0_CAPTURE_MASK;
    QuadDec0_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec0_TRIG_LEVEL     - Level
*     - QuadDec0_TRIG_RISING    - Rising edge
*     - QuadDec0_TRIG_FALLING   - Falling edge
*     - QuadDec0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_TRIG_CONTROL1_REG &= (uint32)~QuadDec0_RELOAD_MASK;
    QuadDec0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QuadDec0_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec0_TRIG_LEVEL     - Level
*     - QuadDec0_TRIG_RISING    - Rising edge
*     - QuadDec0_TRIG_FALLING   - Falling edge
*     - QuadDec0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_TRIG_CONTROL1_REG &= (uint32)~QuadDec0_START_MASK;
    QuadDec0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QuadDec0_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec0_TRIG_LEVEL     - Level
*     - QuadDec0_TRIG_RISING    - Rising edge
*     - QuadDec0_TRIG_FALLING   - Falling edge
*     - QuadDec0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_TRIG_CONTROL1_REG &= (uint32)~QuadDec0_STOP_MASK;
    QuadDec0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QuadDec0_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec0_TRIG_LEVEL     - Level
*     - QuadDec0_TRIG_RISING    - Rising edge
*     - QuadDec0_TRIG_FALLING   - Falling edge
*     - QuadDec0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_TRIG_CONTROL1_REG &= (uint32)~QuadDec0_COUNT_MASK;
    QuadDec0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QuadDec0_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - QuadDec0_CMD_CAPTURE    - Trigger Capture/Switch command
*     - QuadDec0_CMD_RELOAD     - Trigger Reload/Index command
*     - QuadDec0_CMD_STOP       - Trigger Stop/Kill command
*     - QuadDec0_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec0_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec0_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the QuadDec0.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - QuadDec0_STATUS_DOWN    - Set if counting down
*     - QuadDec0_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 QuadDec0_ReadStatus(void)
{
    return ((QuadDec0_STATUS_REG >> QuadDec0_RUNNING_STATUS_SHIFT) |
            (QuadDec0_STATUS_REG & QuadDec0_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: QuadDec0_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - QuadDec0_INTR_MASK_TC       - Terminal count mask
*     - QuadDec0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetInterruptMode(uint32 interruptMask)
{
    QuadDec0_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: QuadDec0_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - QuadDec0_INTR_MASK_TC       - Terminal count mask
*     - QuadDec0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 QuadDec0_GetInterruptSourceMasked(void)
{
    return (QuadDec0_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: QuadDec0_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - QuadDec0_INTR_MASK_TC       - Terminal count mask
*     - QuadDec0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 QuadDec0_GetInterruptSource(void)
{
    return (QuadDec0_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: QuadDec0_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - QuadDec0_INTR_MASK_TC       - Terminal count mask
*     - QuadDec0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_ClearInterrupt(uint32 interruptMask)
{
    QuadDec0_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: QuadDec0_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - QuadDec0_INTR_MASK_TC       - Terminal count mask
*     - QuadDec0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SetInterrupt(uint32 interruptMask)
{
    QuadDec0_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
