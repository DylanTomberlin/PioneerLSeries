/*******************************************************************************
* File Name: QuadDec0.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QuadDec0
*  component.
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

#if !defined(CY_TCPWM_QuadDec0_H)
#define CY_TCPWM_QuadDec0_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} QuadDec0_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QuadDec0_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QuadDec0_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QuadDec0_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QuadDec0_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QuadDec0_QUAD_ENCODING_MODES            (0lu)
#define QuadDec0_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QuadDec0_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QuadDec0_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QuadDec0_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QuadDec0_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QuadDec0_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QuadDec0_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QuadDec0_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define QuadDec0_TC_RUN_MODE                    (0lu)
#define QuadDec0_TC_COUNTER_MODE                (0lu)
#define QuadDec0_TC_COMP_CAP_MODE               (2lu)
#define QuadDec0_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QuadDec0_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QuadDec0_TC_COUNT_SIGNAL_MODE           (3lu)
#define QuadDec0_TC_START_SIGNAL_MODE           (0lu)
#define QuadDec0_TC_STOP_SIGNAL_MODE            (0lu)
#define QuadDec0_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec0_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QuadDec0_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QuadDec0_TC_START_SIGNAL_PRESENT        (0lu)
#define QuadDec0_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QuadDec0_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec0_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QuadDec0_PWM_KILL_EVENT                 (0lu)
#define QuadDec0_PWM_STOP_EVENT                 (0lu)
#define QuadDec0_PWM_MODE                       (4lu)
#define QuadDec0_PWM_OUT_N_INVERT               (0lu)
#define QuadDec0_PWM_OUT_INVERT                 (0lu)
#define QuadDec0_PWM_ALIGN                      (0lu)
#define QuadDec0_PWM_RUN_MODE                   (0lu)
#define QuadDec0_PWM_DEAD_TIME_CYCLE            (0lu)
#define QuadDec0_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QuadDec0_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QuadDec0_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QuadDec0_PWM_START_SIGNAL_MODE          (0lu)
#define QuadDec0_PWM_STOP_SIGNAL_MODE           (0lu)
#define QuadDec0_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec0_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QuadDec0_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QuadDec0_PWM_START_SIGNAL_PRESENT       (0lu)
#define QuadDec0_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QuadDec0_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec0_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QuadDec0_TC_PERIOD_VALUE                (65535lu)
#define QuadDec0_TC_COMPARE_VALUE               (65535lu)
#define QuadDec0_TC_COMPARE_BUF_VALUE           (65535lu)
#define QuadDec0_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QuadDec0_PWM_PERIOD_VALUE               (65535lu)
#define QuadDec0_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QuadDec0_PWM_PERIOD_SWAP                (0lu)
#define QuadDec0_PWM_COMPARE_VALUE              (65535lu)
#define QuadDec0_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QuadDec0_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QuadDec0__LEFT 0
#define QuadDec0__RIGHT 1
#define QuadDec0__CENTER 2
#define QuadDec0__ASYMMETRIC 3

#define QuadDec0__X1 0
#define QuadDec0__X2 1
#define QuadDec0__X4 2

#define QuadDec0__PWM 4
#define QuadDec0__PWM_DT 5
#define QuadDec0__PWM_PR 6

#define QuadDec0__INVERSE 1
#define QuadDec0__DIRECT 0

#define QuadDec0__CAPTURE 2
#define QuadDec0__COMPARE 0

#define QuadDec0__TRIG_LEVEL 3
#define QuadDec0__TRIG_RISING 0
#define QuadDec0__TRIG_FALLING 1
#define QuadDec0__TRIG_BOTH 2

#define QuadDec0__INTR_MASK_TC 1
#define QuadDec0__INTR_MASK_CC_MATCH 2
#define QuadDec0__INTR_MASK_NONE 0
#define QuadDec0__INTR_MASK_TC_CC 3

#define QuadDec0__UNCONFIG 8
#define QuadDec0__TIMER 1
#define QuadDec0__QUAD 3
#define QuadDec0__PWM_SEL 7

#define QuadDec0__COUNT_UP 0
#define QuadDec0__COUNT_DOWN 1
#define QuadDec0__COUNT_UPDOWN0 2
#define QuadDec0__COUNT_UPDOWN1 3


/* Prescaler */
#define QuadDec0_PRESCALE_DIVBY1                ((uint32)(0u << QuadDec0_PRESCALER_SHIFT))
#define QuadDec0_PRESCALE_DIVBY2                ((uint32)(1u << QuadDec0_PRESCALER_SHIFT))
#define QuadDec0_PRESCALE_DIVBY4                ((uint32)(2u << QuadDec0_PRESCALER_SHIFT))
#define QuadDec0_PRESCALE_DIVBY8                ((uint32)(3u << QuadDec0_PRESCALER_SHIFT))
#define QuadDec0_PRESCALE_DIVBY16               ((uint32)(4u << QuadDec0_PRESCALER_SHIFT))
#define QuadDec0_PRESCALE_DIVBY32               ((uint32)(5u << QuadDec0_PRESCALER_SHIFT))
#define QuadDec0_PRESCALE_DIVBY64               ((uint32)(6u << QuadDec0_PRESCALER_SHIFT))
#define QuadDec0_PRESCALE_DIVBY128              ((uint32)(7u << QuadDec0_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QuadDec0_MODE_TIMER_COMPARE             ((uint32)(QuadDec0__COMPARE         <<  \
                                                                  QuadDec0_MODE_SHIFT))
#define QuadDec0_MODE_TIMER_CAPTURE             ((uint32)(QuadDec0__CAPTURE         <<  \
                                                                  QuadDec0_MODE_SHIFT))
#define QuadDec0_MODE_QUAD                      ((uint32)(QuadDec0__QUAD            <<  \
                                                                  QuadDec0_MODE_SHIFT))
#define QuadDec0_MODE_PWM                       ((uint32)(QuadDec0__PWM             <<  \
                                                                  QuadDec0_MODE_SHIFT))
#define QuadDec0_MODE_PWM_DT                    ((uint32)(QuadDec0__PWM_DT          <<  \
                                                                  QuadDec0_MODE_SHIFT))
#define QuadDec0_MODE_PWM_PR                    ((uint32)(QuadDec0__PWM_PR          <<  \
                                                                  QuadDec0_MODE_SHIFT))

/* Quad Modes */
#define QuadDec0_MODE_X1                        ((uint32)(QuadDec0__X1              <<  \
                                                                  QuadDec0_QUAD_MODE_SHIFT))
#define QuadDec0_MODE_X2                        ((uint32)(QuadDec0__X2              <<  \
                                                                  QuadDec0_QUAD_MODE_SHIFT))
#define QuadDec0_MODE_X4                        ((uint32)(QuadDec0__X4              <<  \
                                                                  QuadDec0_QUAD_MODE_SHIFT))

/* Counter modes */
#define QuadDec0_COUNT_UP                       ((uint32)(QuadDec0__COUNT_UP        <<  \
                                                                  QuadDec0_UPDOWN_SHIFT))
#define QuadDec0_COUNT_DOWN                     ((uint32)(QuadDec0__COUNT_DOWN      <<  \
                                                                  QuadDec0_UPDOWN_SHIFT))
#define QuadDec0_COUNT_UPDOWN0                  ((uint32)(QuadDec0__COUNT_UPDOWN0   <<  \
                                                                  QuadDec0_UPDOWN_SHIFT))
#define QuadDec0_COUNT_UPDOWN1                  ((uint32)(QuadDec0__COUNT_UPDOWN1   <<  \
                                                                  QuadDec0_UPDOWN_SHIFT))

/* PWM output invert */
#define QuadDec0_INVERT_LINE                    ((uint32)(QuadDec0__INVERSE         <<  \
                                                                  QuadDec0_INV_OUT_SHIFT))
#define QuadDec0_INVERT_LINE_N                  ((uint32)(QuadDec0__INVERSE         <<  \
                                                                  QuadDec0_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QuadDec0_TRIG_RISING                    ((uint32)QuadDec0__TRIG_RISING)
#define QuadDec0_TRIG_FALLING                   ((uint32)QuadDec0__TRIG_FALLING)
#define QuadDec0_TRIG_BOTH                      ((uint32)QuadDec0__TRIG_BOTH)
#define QuadDec0_TRIG_LEVEL                     ((uint32)QuadDec0__TRIG_LEVEL)

/* Interrupt mask */
#define QuadDec0_INTR_MASK_TC                   ((uint32)QuadDec0__INTR_MASK_TC)
#define QuadDec0_INTR_MASK_CC_MATCH             ((uint32)QuadDec0__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QuadDec0_CC_MATCH_SET                   (0x00u)
#define QuadDec0_CC_MATCH_CLEAR                 (0x01u)
#define QuadDec0_CC_MATCH_INVERT                (0x02u)
#define QuadDec0_CC_MATCH_NO_CHANGE             (0x03u)
#define QuadDec0_OVERLOW_SET                    (0x00u)
#define QuadDec0_OVERLOW_CLEAR                  (0x04u)
#define QuadDec0_OVERLOW_INVERT                 (0x08u)
#define QuadDec0_OVERLOW_NO_CHANGE              (0x0Cu)
#define QuadDec0_UNDERFLOW_SET                  (0x00u)
#define QuadDec0_UNDERFLOW_CLEAR                (0x10u)
#define QuadDec0_UNDERFLOW_INVERT               (0x20u)
#define QuadDec0_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QuadDec0_PWM_MODE_LEFT                  (QuadDec0_CC_MATCH_CLEAR        |   \
                                                         QuadDec0_OVERLOW_SET           |   \
                                                         QuadDec0_UNDERFLOW_NO_CHANGE)
#define QuadDec0_PWM_MODE_RIGHT                 (QuadDec0_CC_MATCH_SET          |   \
                                                         QuadDec0_OVERLOW_NO_CHANGE     |   \
                                                         QuadDec0_UNDERFLOW_CLEAR)
#define QuadDec0_PWM_MODE_ASYM                  (QuadDec0_CC_MATCH_INVERT       |   \
                                                         QuadDec0_OVERLOW_SET           |   \
                                                         QuadDec0_UNDERFLOW_CLEAR)

#if (QuadDec0_CY_TCPWM_V2)
    #if(QuadDec0_CY_TCPWM_4000)
        #define QuadDec0_PWM_MODE_CENTER                (QuadDec0_CC_MATCH_INVERT       |   \
                                                                 QuadDec0_OVERLOW_NO_CHANGE     |   \
                                                                 QuadDec0_UNDERFLOW_CLEAR)
    #else
        #define QuadDec0_PWM_MODE_CENTER                (QuadDec0_CC_MATCH_INVERT       |   \
                                                                 QuadDec0_OVERLOW_SET           |   \
                                                                 QuadDec0_UNDERFLOW_CLEAR)
    #endif /* (QuadDec0_CY_TCPWM_4000) */
#else
    #define QuadDec0_PWM_MODE_CENTER                (QuadDec0_CC_MATCH_INVERT       |   \
                                                             QuadDec0_OVERLOW_NO_CHANGE     |   \
                                                             QuadDec0_UNDERFLOW_CLEAR)
#endif /* (QuadDec0_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QuadDec0_CMD_CAPTURE                    (0u)
#define QuadDec0_CMD_RELOAD                     (8u)
#define QuadDec0_CMD_STOP                       (16u)
#define QuadDec0_CMD_START                      (24u)

/* Status */
#define QuadDec0_STATUS_DOWN                    (1u)
#define QuadDec0_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QuadDec0_Init(void);
void   QuadDec0_Enable(void);
void   QuadDec0_Start(void);
void   QuadDec0_Stop(void);

void   QuadDec0_SetMode(uint32 mode);
void   QuadDec0_SetCounterMode(uint32 counterMode);
void   QuadDec0_SetPWMMode(uint32 modeMask);
void   QuadDec0_SetQDMode(uint32 qdMode);

void   QuadDec0_SetPrescaler(uint32 prescaler);
void   QuadDec0_TriggerCommand(uint32 mask, uint32 command);
void   QuadDec0_SetOneShot(uint32 oneShotEnable);
uint32 QuadDec0_ReadStatus(void);

void   QuadDec0_SetPWMSyncKill(uint32 syncKillEnable);
void   QuadDec0_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QuadDec0_SetPWMDeadTime(uint32 deadTime);
void   QuadDec0_SetPWMInvert(uint32 mask);

void   QuadDec0_SetInterruptMode(uint32 interruptMask);
uint32 QuadDec0_GetInterruptSourceMasked(void);
uint32 QuadDec0_GetInterruptSource(void);
void   QuadDec0_ClearInterrupt(uint32 interruptMask);
void   QuadDec0_SetInterrupt(uint32 interruptMask);

void   QuadDec0_WriteCounter(uint32 count);
uint32 QuadDec0_ReadCounter(void);

uint32 QuadDec0_ReadCapture(void);
uint32 QuadDec0_ReadCaptureBuf(void);

void   QuadDec0_WritePeriod(uint32 period);
uint32 QuadDec0_ReadPeriod(void);
void   QuadDec0_WritePeriodBuf(uint32 periodBuf);
uint32 QuadDec0_ReadPeriodBuf(void);

void   QuadDec0_WriteCompare(uint32 compare);
uint32 QuadDec0_ReadCompare(void);
void   QuadDec0_WriteCompareBuf(uint32 compareBuf);
uint32 QuadDec0_ReadCompareBuf(void);

void   QuadDec0_SetPeriodSwap(uint32 swapEnable);
void   QuadDec0_SetCompareSwap(uint32 swapEnable);

void   QuadDec0_SetCaptureMode(uint32 triggerMode);
void   QuadDec0_SetReloadMode(uint32 triggerMode);
void   QuadDec0_SetStartMode(uint32 triggerMode);
void   QuadDec0_SetStopMode(uint32 triggerMode);
void   QuadDec0_SetCountMode(uint32 triggerMode);

void   QuadDec0_SaveConfig(void);
void   QuadDec0_RestoreConfig(void);
void   QuadDec0_Sleep(void);
void   QuadDec0_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QuadDec0_BLOCK_CONTROL_REG              (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec0_BLOCK_CONTROL_PTR              ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec0_COMMAND_REG                    (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec0_COMMAND_PTR                    ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec0_INTRRUPT_CAUSE_REG             (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec0_INTRRUPT_CAUSE_PTR             ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec0_CONTROL_REG                    (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec0_CONTROL_PTR                    ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec0_STATUS_REG                     (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec0_STATUS_PTR                     ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec0_COUNTER_REG                    (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec0_COUNTER_PTR                    ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec0_COMP_CAP_REG                   (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__CC )
#define QuadDec0_COMP_CAP_PTR                   ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__CC )
#define QuadDec0_COMP_CAP_BUF_REG               (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec0_COMP_CAP_BUF_PTR               ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec0_PERIOD_REG                     (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec0_PERIOD_PTR                     ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec0_PERIOD_BUF_REG                 (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec0_PERIOD_BUF_PTR                 ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec0_TRIG_CONTROL0_REG              (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec0_TRIG_CONTROL0_PTR              ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec0_TRIG_CONTROL1_REG              (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec0_TRIG_CONTROL1_PTR              ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec0_TRIG_CONTROL2_REG              (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec0_TRIG_CONTROL2_PTR              ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec0_INTERRUPT_REQ_REG              (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__INTR )
#define QuadDec0_INTERRUPT_REQ_PTR              ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__INTR )
#define QuadDec0_INTERRUPT_SET_REG              (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec0_INTERRUPT_SET_PTR              ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec0_INTERRUPT_MASK_REG             (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec0_INTERRUPT_MASK_PTR             ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec0_INTERRUPT_MASKED_REG           (*(reg32 *) QuadDec0_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QuadDec0_INTERRUPT_MASKED_PTR           ( (reg32 *) QuadDec0_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QuadDec0_MASK                           ((uint32)QuadDec0_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QuadDec0_RELOAD_CC_SHIFT                (0u)
#define QuadDec0_RELOAD_PERIOD_SHIFT            (1u)
#define QuadDec0_PWM_SYNC_KILL_SHIFT            (2u)
#define QuadDec0_PWM_STOP_KILL_SHIFT            (3u)
#define QuadDec0_PRESCALER_SHIFT                (8u)
#define QuadDec0_UPDOWN_SHIFT                   (16u)
#define QuadDec0_ONESHOT_SHIFT                  (18u)
#define QuadDec0_QUAD_MODE_SHIFT                (20u)
#define QuadDec0_INV_OUT_SHIFT                  (20u)
#define QuadDec0_INV_COMPL_OUT_SHIFT            (21u)
#define QuadDec0_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QuadDec0_RELOAD_CC_MASK                 ((uint32)(QuadDec0_1BIT_MASK        <<  \
                                                                            QuadDec0_RELOAD_CC_SHIFT))
#define QuadDec0_RELOAD_PERIOD_MASK             ((uint32)(QuadDec0_1BIT_MASK        <<  \
                                                                            QuadDec0_RELOAD_PERIOD_SHIFT))
#define QuadDec0_PWM_SYNC_KILL_MASK             ((uint32)(QuadDec0_1BIT_MASK        <<  \
                                                                            QuadDec0_PWM_SYNC_KILL_SHIFT))
#define QuadDec0_PWM_STOP_KILL_MASK             ((uint32)(QuadDec0_1BIT_MASK        <<  \
                                                                            QuadDec0_PWM_STOP_KILL_SHIFT))
#define QuadDec0_PRESCALER_MASK                 ((uint32)(QuadDec0_8BIT_MASK        <<  \
                                                                            QuadDec0_PRESCALER_SHIFT))
#define QuadDec0_UPDOWN_MASK                    ((uint32)(QuadDec0_2BIT_MASK        <<  \
                                                                            QuadDec0_UPDOWN_SHIFT))
#define QuadDec0_ONESHOT_MASK                   ((uint32)(QuadDec0_1BIT_MASK        <<  \
                                                                            QuadDec0_ONESHOT_SHIFT))
#define QuadDec0_QUAD_MODE_MASK                 ((uint32)(QuadDec0_3BIT_MASK        <<  \
                                                                            QuadDec0_QUAD_MODE_SHIFT))
#define QuadDec0_INV_OUT_MASK                   ((uint32)(QuadDec0_2BIT_MASK        <<  \
                                                                            QuadDec0_INV_OUT_SHIFT))
#define QuadDec0_MODE_MASK                      ((uint32)(QuadDec0_3BIT_MASK        <<  \
                                                                            QuadDec0_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QuadDec0_CAPTURE_SHIFT                  (0u)
#define QuadDec0_COUNT_SHIFT                    (2u)
#define QuadDec0_RELOAD_SHIFT                   (4u)
#define QuadDec0_STOP_SHIFT                     (6u)
#define QuadDec0_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QuadDec0_CAPTURE_MASK                   ((uint32)(QuadDec0_2BIT_MASK        <<  \
                                                                  QuadDec0_CAPTURE_SHIFT))
#define QuadDec0_COUNT_MASK                     ((uint32)(QuadDec0_2BIT_MASK        <<  \
                                                                  QuadDec0_COUNT_SHIFT))
#define QuadDec0_RELOAD_MASK                    ((uint32)(QuadDec0_2BIT_MASK        <<  \
                                                                  QuadDec0_RELOAD_SHIFT))
#define QuadDec0_STOP_MASK                      ((uint32)(QuadDec0_2BIT_MASK        <<  \
                                                                  QuadDec0_STOP_SHIFT))
#define QuadDec0_START_MASK                     ((uint32)(QuadDec0_2BIT_MASK        <<  \
                                                                  QuadDec0_START_SHIFT))

/* MASK */
#define QuadDec0_1BIT_MASK                      ((uint32)0x01u)
#define QuadDec0_2BIT_MASK                      ((uint32)0x03u)
#define QuadDec0_3BIT_MASK                      ((uint32)0x07u)
#define QuadDec0_6BIT_MASK                      ((uint32)0x3Fu)
#define QuadDec0_8BIT_MASK                      ((uint32)0xFFu)
#define QuadDec0_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QuadDec0_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QuadDec0_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QuadDec0_QUAD_ENCODING_MODES     << QuadDec0_QUAD_MODE_SHIFT))       |\
         ((uint32)(QuadDec0_CONFIG                  << QuadDec0_MODE_SHIFT)))

#define QuadDec0_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QuadDec0_PWM_STOP_EVENT          << QuadDec0_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QuadDec0_PWM_OUT_INVERT          << QuadDec0_INV_OUT_SHIFT))         |\
         ((uint32)(QuadDec0_PWM_OUT_N_INVERT        << QuadDec0_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QuadDec0_PWM_MODE                << QuadDec0_MODE_SHIFT)))

#define QuadDec0_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QuadDec0_PWM_RUN_MODE         << QuadDec0_ONESHOT_SHIFT))
            
#define QuadDec0_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QuadDec0_PWM_ALIGN            << QuadDec0_UPDOWN_SHIFT))

#define QuadDec0_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QuadDec0_PWM_KILL_EVENT      << QuadDec0_PWM_SYNC_KILL_SHIFT))

#define QuadDec0_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QuadDec0_PWM_DEAD_TIME_CYCLE  << QuadDec0_PRESCALER_SHIFT))

#define QuadDec0_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QuadDec0_PWM_PRESCALER        << QuadDec0_PRESCALER_SHIFT))

#define QuadDec0_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QuadDec0_TC_PRESCALER            << QuadDec0_PRESCALER_SHIFT))       |\
         ((uint32)(QuadDec0_TC_COUNTER_MODE         << QuadDec0_UPDOWN_SHIFT))          |\
         ((uint32)(QuadDec0_TC_RUN_MODE             << QuadDec0_ONESHOT_SHIFT))         |\
         ((uint32)(QuadDec0_TC_COMP_CAP_MODE        << QuadDec0_MODE_SHIFT)))
        
#define QuadDec0_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QuadDec0_QUAD_PHIA_SIGNAL_MODE   << QuadDec0_COUNT_SHIFT))           |\
         ((uint32)(QuadDec0_QUAD_INDEX_SIGNAL_MODE  << QuadDec0_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec0_QUAD_STOP_SIGNAL_MODE   << QuadDec0_STOP_SHIFT))            |\
         ((uint32)(QuadDec0_QUAD_PHIB_SIGNAL_MODE   << QuadDec0_START_SHIFT)))

#define QuadDec0_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QuadDec0_PWM_SWITCH_SIGNAL_MODE  << QuadDec0_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec0_PWM_COUNT_SIGNAL_MODE   << QuadDec0_COUNT_SHIFT))           |\
         ((uint32)(QuadDec0_PWM_RELOAD_SIGNAL_MODE  << QuadDec0_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec0_PWM_STOP_SIGNAL_MODE    << QuadDec0_STOP_SHIFT))            |\
         ((uint32)(QuadDec0_PWM_START_SIGNAL_MODE   << QuadDec0_START_SHIFT)))

#define QuadDec0_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QuadDec0_TC_CAPTURE_SIGNAL_MODE  << QuadDec0_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec0_TC_COUNT_SIGNAL_MODE    << QuadDec0_COUNT_SHIFT))           |\
         ((uint32)(QuadDec0_TC_RELOAD_SIGNAL_MODE   << QuadDec0_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec0_TC_STOP_SIGNAL_MODE     << QuadDec0_STOP_SHIFT))            |\
         ((uint32)(QuadDec0_TC_START_SIGNAL_MODE    << QuadDec0_START_SHIFT)))
        
#define QuadDec0_TIMER_UPDOWN_CNT_USED                                                          \
                ((QuadDec0__COUNT_UPDOWN0 == QuadDec0_TC_COUNTER_MODE)                  ||\
                 (QuadDec0__COUNT_UPDOWN1 == QuadDec0_TC_COUNTER_MODE))

#define QuadDec0_PWM_UPDOWN_CNT_USED                                                            \
                ((QuadDec0__CENTER == QuadDec0_PWM_ALIGN)                               ||\
                 (QuadDec0__ASYMMETRIC == QuadDec0_PWM_ALIGN))               
        
#define QuadDec0_PWM_PR_INIT_VALUE              (1u)
#define QuadDec0_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QuadDec0_H */

/* [] END OF FILE */
