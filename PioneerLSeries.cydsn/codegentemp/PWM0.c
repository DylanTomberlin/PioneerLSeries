/*******************************************************************************
* File Name: PWM0.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the PWM0
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

#include "PWM0.h"

uint8 PWM0_initVar = 0u;


/*******************************************************************************
* Function Name: PWM0_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default PWM0 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (PWM0__QUAD == PWM0_CONFIG)
        PWM0_CONTROL_REG = PWM0_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        PWM0_TRIG_CONTROL1_REG  = PWM0_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        PWM0_SetInterruptMode(PWM0_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        PWM0_SetCounterMode(PWM0_COUNT_DOWN);
        PWM0_WritePeriod(PWM0_QUAD_PERIOD_INIT_VALUE);
        PWM0_WriteCounter(PWM0_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (PWM0__QUAD == PWM0_CONFIG) */

    #if (PWM0__TIMER == PWM0_CONFIG)
        PWM0_CONTROL_REG = PWM0_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        PWM0_TRIG_CONTROL1_REG  = PWM0_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        PWM0_SetInterruptMode(PWM0_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        PWM0_WritePeriod(PWM0_TC_PERIOD_VALUE );

        #if (PWM0__COMPARE == PWM0_TC_COMP_CAP_MODE)
            PWM0_WriteCompare(PWM0_TC_COMPARE_VALUE);

            #if (1u == PWM0_TC_COMPARE_SWAP)
                PWM0_SetCompareSwap(1u);
                PWM0_WriteCompareBuf(PWM0_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == PWM0_TC_COMPARE_SWAP) */
        #endif  /* (PWM0__COMPARE == PWM0_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (PWM0_CY_TCPWM_V2 && PWM0_TIMER_UPDOWN_CNT_USED && !PWM0_CY_TCPWM_4000)
            PWM0_WriteCounter(1u);
        #elif(PWM0__COUNT_DOWN == PWM0_TC_COUNTER_MODE)
            PWM0_WriteCounter(PWM0_TC_PERIOD_VALUE);
        #else
            PWM0_WriteCounter(0u);
        #endif /* (PWM0_CY_TCPWM_V2 && PWM0_TIMER_UPDOWN_CNT_USED && !PWM0_CY_TCPWM_4000) */
    #endif  /* (PWM0__TIMER == PWM0_CONFIG) */

    #if (PWM0__PWM_SEL == PWM0_CONFIG)
        PWM0_CONTROL_REG = PWM0_CTRL_PWM_BASE_CONFIG;

        #if (PWM0__PWM_PR == PWM0_PWM_MODE)
            PWM0_CONTROL_REG |= PWM0_CTRL_PWM_RUN_MODE;
            PWM0_WriteCounter(PWM0_PWM_PR_INIT_VALUE);
        #else
            PWM0_CONTROL_REG |= PWM0_CTRL_PWM_ALIGN | PWM0_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (PWM0_CY_TCPWM_V2 && PWM0_PWM_UPDOWN_CNT_USED && !PWM0_CY_TCPWM_4000)
                PWM0_WriteCounter(1u);
            #elif (PWM0__RIGHT == PWM0_PWM_ALIGN)
                PWM0_WriteCounter(PWM0_PWM_PERIOD_VALUE);
            #else 
                PWM0_WriteCounter(0u);
            #endif  /* (PWM0_CY_TCPWM_V2 && PWM0_PWM_UPDOWN_CNT_USED && !PWM0_CY_TCPWM_4000) */
        #endif  /* (PWM0__PWM_PR == PWM0_PWM_MODE) */

        #if (PWM0__PWM_DT == PWM0_PWM_MODE)
            PWM0_CONTROL_REG |= PWM0_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (PWM0__PWM_DT == PWM0_PWM_MODE) */

        #if (PWM0__PWM == PWM0_PWM_MODE)
            PWM0_CONTROL_REG |= PWM0_CTRL_PWM_PRESCALER;
        #endif  /* (PWM0__PWM == PWM0_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        PWM0_TRIG_CONTROL1_REG  = PWM0_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        PWM0_SetInterruptMode(PWM0_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (PWM0__PWM_PR == PWM0_PWM_MODE)
            PWM0_TRIG_CONTROL2_REG =
                    (PWM0_CC_MATCH_NO_CHANGE    |
                    PWM0_OVERLOW_NO_CHANGE      |
                    PWM0_UNDERFLOW_NO_CHANGE);
        #else
            #if (PWM0__LEFT == PWM0_PWM_ALIGN)
                PWM0_TRIG_CONTROL2_REG = PWM0_PWM_MODE_LEFT;
            #endif  /* ( PWM0_PWM_LEFT == PWM0_PWM_ALIGN) */

            #if (PWM0__RIGHT == PWM0_PWM_ALIGN)
                PWM0_TRIG_CONTROL2_REG = PWM0_PWM_MODE_RIGHT;
            #endif  /* ( PWM0_PWM_RIGHT == PWM0_PWM_ALIGN) */

            #if (PWM0__CENTER == PWM0_PWM_ALIGN)
                PWM0_TRIG_CONTROL2_REG = PWM0_PWM_MODE_CENTER;
            #endif  /* ( PWM0_PWM_CENTER == PWM0_PWM_ALIGN) */

            #if (PWM0__ASYMMETRIC == PWM0_PWM_ALIGN)
                PWM0_TRIG_CONTROL2_REG = PWM0_PWM_MODE_ASYM;
            #endif  /* (PWM0__ASYMMETRIC == PWM0_PWM_ALIGN) */
        #endif  /* (PWM0__PWM_PR == PWM0_PWM_MODE) */

        /* Set other values from customizer */
        PWM0_WritePeriod(PWM0_PWM_PERIOD_VALUE );
        PWM0_WriteCompare(PWM0_PWM_COMPARE_VALUE);

        #if (1u == PWM0_PWM_COMPARE_SWAP)
            PWM0_SetCompareSwap(1u);
            PWM0_WriteCompareBuf(PWM0_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == PWM0_PWM_COMPARE_SWAP) */

        #if (1u == PWM0_PWM_PERIOD_SWAP)
            PWM0_SetPeriodSwap(1u);
            PWM0_WritePeriodBuf(PWM0_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == PWM0_PWM_PERIOD_SWAP) */
    #endif  /* (PWM0__PWM_SEL == PWM0_CONFIG) */
    
}


/*******************************************************************************
* Function Name: PWM0_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM0.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    PWM0_BLOCK_CONTROL_REG |= PWM0_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (PWM0__PWM_SEL == PWM0_CONFIG)
        #if (0u == PWM0_PWM_START_SIGNAL_PRESENT)
            PWM0_TriggerCommand(PWM0_MASK, PWM0_CMD_START);
        #endif /* (0u == PWM0_PWM_START_SIGNAL_PRESENT) */
    #endif /* (PWM0__PWM_SEL == PWM0_CONFIG) */

    #if (PWM0__TIMER == PWM0_CONFIG)
        #if (0u == PWM0_TC_START_SIGNAL_PRESENT)
            PWM0_TriggerCommand(PWM0_MASK, PWM0_CMD_START);
        #endif /* (0u == PWM0_TC_START_SIGNAL_PRESENT) */
    #endif /* (PWM0__TIMER == PWM0_CONFIG) */
    
    #if (PWM0__QUAD == PWM0_CONFIG)
        #if (0u != PWM0_QUAD_AUTO_START)
            PWM0_TriggerCommand(PWM0_MASK, PWM0_CMD_RELOAD);
        #endif /* (0u != PWM0_QUAD_AUTO_START) */
    #endif  /* (PWM0__QUAD == PWM0_CONFIG) */
}


/*******************************************************************************
* Function Name: PWM0_Start
********************************************************************************
*
* Summary:
*  Initializes the PWM0 with default customizer
*  values when called the first time and enables the PWM0.
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
*  PWM0_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time PWM0_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the PWM0_Start() routine.
*
*******************************************************************************/
void PWM0_Start(void)
{
    if (0u == PWM0_initVar)
    {
        PWM0_Init();
        PWM0_initVar = 1u;
    }

    PWM0_Enable();
}


/*******************************************************************************
* Function Name: PWM0_Stop
********************************************************************************
*
* Summary:
*  Disables the PWM0.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_BLOCK_CONTROL_REG &= (uint32)~PWM0_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the PWM0. This function is used when
*  configured as a generic PWM0 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the PWM0 to operate in
*   Values:
*   - PWM0_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - PWM0_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - PWM0_MODE_QUAD - Quadrature decoder
*         - PWM0_MODE_PWM - PWM
*         - PWM0_MODE_PWM_DT - PWM with dead time
*         - PWM0_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_MODE_MASK;
    PWM0_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - PWM0_MODE_X1 - Counts on phi 1 rising
*         - PWM0_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - PWM0_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_QUAD_MODE_MASK;
    PWM0_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - PWM0_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - PWM0_PRESCALE_DIVBY2    - Divide by 2
*         - PWM0_PRESCALE_DIVBY4    - Divide by 4
*         - PWM0_PRESCALE_DIVBY8    - Divide by 8
*         - PWM0_PRESCALE_DIVBY16   - Divide by 16
*         - PWM0_PRESCALE_DIVBY32   - Divide by 32
*         - PWM0_PRESCALE_DIVBY64   - Divide by 64
*         - PWM0_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_PRESCALER_MASK;
    PWM0_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM0 runs
*  continuously or stops when terminal count is reached.  By default the
*  PWM0 operates in the continuous mode.
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
void PWM0_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_ONESHOT_MASK;
    PWM0_CONTROL_REG |= ((uint32)((oneShotEnable & PWM0_1BIT_MASK) <<
                                                               PWM0_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetPWMMode
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
void PWM0_SetPWMMode(uint32 modeMask)
{
    PWM0_TRIG_CONTROL2_REG = (modeMask & PWM0_6BIT_MASK);
}



/*******************************************************************************
* Function Name: PWM0_SetPWMSyncKill
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
void PWM0_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_PWM_SYNC_KILL_MASK;
    PWM0_CONTROL_REG |= ((uint32)((syncKillEnable & PWM0_1BIT_MASK)  <<
                                               PWM0_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetPWMStopOnKill
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
void PWM0_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_PWM_STOP_KILL_MASK;
    PWM0_CONTROL_REG |= ((uint32)((stopOnKillEnable & PWM0_1BIT_MASK)  <<
                                                         PWM0_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetPWMDeadTime
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
void PWM0_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_PRESCALER_MASK;
    PWM0_CONTROL_REG |= ((uint32)((deadTime & PWM0_8BIT_MASK) <<
                                                          PWM0_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetPWMInvert
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
*         - PWM0_INVERT_LINE   - Inverts the line output
*         - PWM0_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_INV_OUT_MASK;
    PWM0_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: PWM0_WriteCounter
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
void PWM0_WriteCounter(uint32 count)
{
    PWM0_COUNTER_REG = (count & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_ReadCounter
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
uint32 PWM0_ReadCounter(void)
{
    return (PWM0_COUNTER_REG & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - PWM0_COUNT_UP       - Counts up
*     - PWM0_COUNT_DOWN     - Counts down
*     - PWM0_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - PWM0_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_UPDOWN_MASK;
    PWM0_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_WritePeriod
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
void PWM0_WritePeriod(uint32 period)
{
    PWM0_PERIOD_REG = (period & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_ReadPeriod
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
uint32 PWM0_ReadPeriod(void)
{
    return (PWM0_PERIOD_REG & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_SetCompareSwap
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
void PWM0_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_RELOAD_CC_MASK;
    PWM0_CONTROL_REG |= (swapEnable & PWM0_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_WritePeriodBuf
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
void PWM0_WritePeriodBuf(uint32 periodBuf)
{
    PWM0_PERIOD_BUF_REG = (periodBuf & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_ReadPeriodBuf
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
uint32 PWM0_ReadPeriodBuf(void)
{
    return (PWM0_PERIOD_BUF_REG & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_SetPeriodSwap
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
void PWM0_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_CONTROL_REG &= (uint32)~PWM0_RELOAD_PERIOD_MASK;
    PWM0_CONTROL_REG |= ((uint32)((swapEnable & PWM0_1BIT_MASK) <<
                                                            PWM0_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_WriteCompare
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
void PWM0_WriteCompare(uint32 compare)
{
    #if (PWM0_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (PWM0_CY_TCPWM_4000) */

    #if (PWM0_CY_TCPWM_4000)
        currentMode = ((PWM0_CONTROL_REG & PWM0_UPDOWN_MASK) >> PWM0_UPDOWN_SHIFT);

        if (((uint32)PWM0__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)PWM0__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (PWM0_CY_TCPWM_4000) */
    
    PWM0_COMP_CAP_REG = (compare & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_ReadCompare
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
uint32 PWM0_ReadCompare(void)
{
    #if (PWM0_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (PWM0_CY_TCPWM_4000) */

    #if (PWM0_CY_TCPWM_4000)
        currentMode = ((PWM0_CONTROL_REG & PWM0_UPDOWN_MASK) >> PWM0_UPDOWN_SHIFT);
        
        regVal = PWM0_COMP_CAP_REG;
        
        if (((uint32)PWM0__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)PWM0__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & PWM0_16BIT_MASK);
    #else
        return (PWM0_COMP_CAP_REG & PWM0_16BIT_MASK);
    #endif /* (PWM0_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: PWM0_WriteCompareBuf
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
void PWM0_WriteCompareBuf(uint32 compareBuf)
{
    #if (PWM0_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (PWM0_CY_TCPWM_4000) */

    #if (PWM0_CY_TCPWM_4000)
        currentMode = ((PWM0_CONTROL_REG & PWM0_UPDOWN_MASK) >> PWM0_UPDOWN_SHIFT);

        if (((uint32)PWM0__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)PWM0__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (PWM0_CY_TCPWM_4000) */
    
    PWM0_COMP_CAP_BUF_REG = (compareBuf & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_ReadCompareBuf
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
uint32 PWM0_ReadCompareBuf(void)
{
    #if (PWM0_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (PWM0_CY_TCPWM_4000) */

    #if (PWM0_CY_TCPWM_4000)
        currentMode = ((PWM0_CONTROL_REG & PWM0_UPDOWN_MASK) >> PWM0_UPDOWN_SHIFT);

        regVal = PWM0_COMP_CAP_BUF_REG;
        
        if (((uint32)PWM0__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)PWM0__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & PWM0_16BIT_MASK);
    #else
        return (PWM0_COMP_CAP_BUF_REG & PWM0_16BIT_MASK);
    #endif /* (PWM0_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: PWM0_ReadCapture
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
uint32 PWM0_ReadCapture(void)
{
    return (PWM0_COMP_CAP_REG & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_ReadCaptureBuf
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
uint32 PWM0_ReadCaptureBuf(void)
{
    return (PWM0_COMP_CAP_BUF_REG & PWM0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PWM0_SetCaptureMode
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
*     - PWM0_TRIG_LEVEL     - Level
*     - PWM0_TRIG_RISING    - Rising edge
*     - PWM0_TRIG_FALLING   - Falling edge
*     - PWM0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_TRIG_CONTROL1_REG &= (uint32)~PWM0_CAPTURE_MASK;
    PWM0_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM0_TRIG_LEVEL     - Level
*     - PWM0_TRIG_RISING    - Rising edge
*     - PWM0_TRIG_FALLING   - Falling edge
*     - PWM0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_TRIG_CONTROL1_REG &= (uint32)~PWM0_RELOAD_MASK;
    PWM0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PWM0_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM0_TRIG_LEVEL     - Level
*     - PWM0_TRIG_RISING    - Rising edge
*     - PWM0_TRIG_FALLING   - Falling edge
*     - PWM0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_TRIG_CONTROL1_REG &= (uint32)~PWM0_START_MASK;
    PWM0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PWM0_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM0_TRIG_LEVEL     - Level
*     - PWM0_TRIG_RISING    - Rising edge
*     - PWM0_TRIG_FALLING   - Falling edge
*     - PWM0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_TRIG_CONTROL1_REG &= (uint32)~PWM0_STOP_MASK;
    PWM0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PWM0_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PWM0_TRIG_LEVEL     - Level
*     - PWM0_TRIG_RISING    - Rising edge
*     - PWM0_TRIG_FALLING   - Falling edge
*     - PWM0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_TRIG_CONTROL1_REG &= (uint32)~PWM0_COUNT_MASK;
    PWM0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PWM0_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_TriggerCommand
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
*     - PWM0_CMD_CAPTURE    - Trigger Capture/Switch command
*     - PWM0_CMD_RELOAD     - Trigger Reload/Index command
*     - PWM0_CMD_STOP       - Trigger Stop/Kill command
*     - PWM0_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PWM0_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PWM0_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the PWM0.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - PWM0_STATUS_DOWN    - Set if counting down
*     - PWM0_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 PWM0_ReadStatus(void)
{
    return ((PWM0_STATUS_REG >> PWM0_RUNNING_STATUS_SHIFT) |
            (PWM0_STATUS_REG & PWM0_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: PWM0_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - PWM0_INTR_MASK_TC       - Terminal count mask
*     - PWM0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetInterruptMode(uint32 interruptMask)
{
    PWM0_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: PWM0_GetInterruptSourceMasked
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
*     - PWM0_INTR_MASK_TC       - Terminal count mask
*     - PWM0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PWM0_GetInterruptSourceMasked(void)
{
    return (PWM0_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: PWM0_GetInterruptSource
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
*     - PWM0_INTR_MASK_TC       - Terminal count mask
*     - PWM0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PWM0_GetInterruptSource(void)
{
    return (PWM0_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: PWM0_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - PWM0_INTR_MASK_TC       - Terminal count mask
*     - PWM0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_ClearInterrupt(uint32 interruptMask)
{
    PWM0_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: PWM0_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - PWM0_INTR_MASK_TC       - Terminal count mask
*     - PWM0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PWM0_SetInterrupt(uint32 interruptMask)
{
    PWM0_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
