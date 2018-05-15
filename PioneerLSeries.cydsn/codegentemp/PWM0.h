/*******************************************************************************
* File Name: PWM0.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the PWM0
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

#if !defined(CY_TCPWM_PWM0_H)
#define CY_TCPWM_PWM0_H


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
} PWM0_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  PWM0_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define PWM0_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define PWM0_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define PWM0_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define PWM0_QUAD_ENCODING_MODES            (0lu)
#define PWM0_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define PWM0_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define PWM0_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define PWM0_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define PWM0_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define PWM0_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define PWM0_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define PWM0_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define PWM0_TC_RUN_MODE                    (0lu)
#define PWM0_TC_COUNTER_MODE                (0lu)
#define PWM0_TC_COMP_CAP_MODE               (2lu)
#define PWM0_TC_PRESCALER                   (0lu)

/* Signal modes */
#define PWM0_TC_RELOAD_SIGNAL_MODE          (0lu)
#define PWM0_TC_COUNT_SIGNAL_MODE           (3lu)
#define PWM0_TC_START_SIGNAL_MODE           (0lu)
#define PWM0_TC_STOP_SIGNAL_MODE            (0lu)
#define PWM0_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define PWM0_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define PWM0_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define PWM0_TC_START_SIGNAL_PRESENT        (0lu)
#define PWM0_TC_STOP_SIGNAL_PRESENT         (0lu)
#define PWM0_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PWM0_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define PWM0_PWM_KILL_EVENT                 (0lu)
#define PWM0_PWM_STOP_EVENT                 (0lu)
#define PWM0_PWM_MODE                       (4lu)
#define PWM0_PWM_OUT_N_INVERT               (0lu)
#define PWM0_PWM_OUT_INVERT                 (0lu)
#define PWM0_PWM_ALIGN                      (0lu)
#define PWM0_PWM_RUN_MODE                   (0lu)
#define PWM0_PWM_DEAD_TIME_CYCLE            (0lu)
#define PWM0_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define PWM0_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define PWM0_PWM_COUNT_SIGNAL_MODE          (3lu)
#define PWM0_PWM_START_SIGNAL_MODE          (0lu)
#define PWM0_PWM_STOP_SIGNAL_MODE           (0lu)
#define PWM0_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define PWM0_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define PWM0_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define PWM0_PWM_START_SIGNAL_PRESENT       (0lu)
#define PWM0_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define PWM0_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PWM0_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define PWM0_TC_PERIOD_VALUE                (65535lu)
#define PWM0_TC_COMPARE_VALUE               (65535lu)
#define PWM0_TC_COMPARE_BUF_VALUE           (65535lu)
#define PWM0_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define PWM0_PWM_PERIOD_VALUE               (65535lu)
#define PWM0_PWM_PERIOD_BUF_VALUE           (65535lu)
#define PWM0_PWM_PERIOD_SWAP                (0lu)
#define PWM0_PWM_COMPARE_VALUE              (65535lu)
#define PWM0_PWM_COMPARE_BUF_VALUE          (65535lu)
#define PWM0_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define PWM0__LEFT 0
#define PWM0__RIGHT 1
#define PWM0__CENTER 2
#define PWM0__ASYMMETRIC 3

#define PWM0__X1 0
#define PWM0__X2 1
#define PWM0__X4 2

#define PWM0__PWM 4
#define PWM0__PWM_DT 5
#define PWM0__PWM_PR 6

#define PWM0__INVERSE 1
#define PWM0__DIRECT 0

#define PWM0__CAPTURE 2
#define PWM0__COMPARE 0

#define PWM0__TRIG_LEVEL 3
#define PWM0__TRIG_RISING 0
#define PWM0__TRIG_FALLING 1
#define PWM0__TRIG_BOTH 2

#define PWM0__INTR_MASK_TC 1
#define PWM0__INTR_MASK_CC_MATCH 2
#define PWM0__INTR_MASK_NONE 0
#define PWM0__INTR_MASK_TC_CC 3

#define PWM0__UNCONFIG 8
#define PWM0__TIMER 1
#define PWM0__QUAD 3
#define PWM0__PWM_SEL 7

#define PWM0__COUNT_UP 0
#define PWM0__COUNT_DOWN 1
#define PWM0__COUNT_UPDOWN0 2
#define PWM0__COUNT_UPDOWN1 3


/* Prescaler */
#define PWM0_PRESCALE_DIVBY1                ((uint32)(0u << PWM0_PRESCALER_SHIFT))
#define PWM0_PRESCALE_DIVBY2                ((uint32)(1u << PWM0_PRESCALER_SHIFT))
#define PWM0_PRESCALE_DIVBY4                ((uint32)(2u << PWM0_PRESCALER_SHIFT))
#define PWM0_PRESCALE_DIVBY8                ((uint32)(3u << PWM0_PRESCALER_SHIFT))
#define PWM0_PRESCALE_DIVBY16               ((uint32)(4u << PWM0_PRESCALER_SHIFT))
#define PWM0_PRESCALE_DIVBY32               ((uint32)(5u << PWM0_PRESCALER_SHIFT))
#define PWM0_PRESCALE_DIVBY64               ((uint32)(6u << PWM0_PRESCALER_SHIFT))
#define PWM0_PRESCALE_DIVBY128              ((uint32)(7u << PWM0_PRESCALER_SHIFT))

/* TCPWM set modes */
#define PWM0_MODE_TIMER_COMPARE             ((uint32)(PWM0__COMPARE         <<  \
                                                                  PWM0_MODE_SHIFT))
#define PWM0_MODE_TIMER_CAPTURE             ((uint32)(PWM0__CAPTURE         <<  \
                                                                  PWM0_MODE_SHIFT))
#define PWM0_MODE_QUAD                      ((uint32)(PWM0__QUAD            <<  \
                                                                  PWM0_MODE_SHIFT))
#define PWM0_MODE_PWM                       ((uint32)(PWM0__PWM             <<  \
                                                                  PWM0_MODE_SHIFT))
#define PWM0_MODE_PWM_DT                    ((uint32)(PWM0__PWM_DT          <<  \
                                                                  PWM0_MODE_SHIFT))
#define PWM0_MODE_PWM_PR                    ((uint32)(PWM0__PWM_PR          <<  \
                                                                  PWM0_MODE_SHIFT))

/* Quad Modes */
#define PWM0_MODE_X1                        ((uint32)(PWM0__X1              <<  \
                                                                  PWM0_QUAD_MODE_SHIFT))
#define PWM0_MODE_X2                        ((uint32)(PWM0__X2              <<  \
                                                                  PWM0_QUAD_MODE_SHIFT))
#define PWM0_MODE_X4                        ((uint32)(PWM0__X4              <<  \
                                                                  PWM0_QUAD_MODE_SHIFT))

/* Counter modes */
#define PWM0_COUNT_UP                       ((uint32)(PWM0__COUNT_UP        <<  \
                                                                  PWM0_UPDOWN_SHIFT))
#define PWM0_COUNT_DOWN                     ((uint32)(PWM0__COUNT_DOWN      <<  \
                                                                  PWM0_UPDOWN_SHIFT))
#define PWM0_COUNT_UPDOWN0                  ((uint32)(PWM0__COUNT_UPDOWN0   <<  \
                                                                  PWM0_UPDOWN_SHIFT))
#define PWM0_COUNT_UPDOWN1                  ((uint32)(PWM0__COUNT_UPDOWN1   <<  \
                                                                  PWM0_UPDOWN_SHIFT))

/* PWM output invert */
#define PWM0_INVERT_LINE                    ((uint32)(PWM0__INVERSE         <<  \
                                                                  PWM0_INV_OUT_SHIFT))
#define PWM0_INVERT_LINE_N                  ((uint32)(PWM0__INVERSE         <<  \
                                                                  PWM0_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define PWM0_TRIG_RISING                    ((uint32)PWM0__TRIG_RISING)
#define PWM0_TRIG_FALLING                   ((uint32)PWM0__TRIG_FALLING)
#define PWM0_TRIG_BOTH                      ((uint32)PWM0__TRIG_BOTH)
#define PWM0_TRIG_LEVEL                     ((uint32)PWM0__TRIG_LEVEL)

/* Interrupt mask */
#define PWM0_INTR_MASK_TC                   ((uint32)PWM0__INTR_MASK_TC)
#define PWM0_INTR_MASK_CC_MATCH             ((uint32)PWM0__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define PWM0_CC_MATCH_SET                   (0x00u)
#define PWM0_CC_MATCH_CLEAR                 (0x01u)
#define PWM0_CC_MATCH_INVERT                (0x02u)
#define PWM0_CC_MATCH_NO_CHANGE             (0x03u)
#define PWM0_OVERLOW_SET                    (0x00u)
#define PWM0_OVERLOW_CLEAR                  (0x04u)
#define PWM0_OVERLOW_INVERT                 (0x08u)
#define PWM0_OVERLOW_NO_CHANGE              (0x0Cu)
#define PWM0_UNDERFLOW_SET                  (0x00u)
#define PWM0_UNDERFLOW_CLEAR                (0x10u)
#define PWM0_UNDERFLOW_INVERT               (0x20u)
#define PWM0_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define PWM0_PWM_MODE_LEFT                  (PWM0_CC_MATCH_CLEAR        |   \
                                                         PWM0_OVERLOW_SET           |   \
                                                         PWM0_UNDERFLOW_NO_CHANGE)
#define PWM0_PWM_MODE_RIGHT                 (PWM0_CC_MATCH_SET          |   \
                                                         PWM0_OVERLOW_NO_CHANGE     |   \
                                                         PWM0_UNDERFLOW_CLEAR)
#define PWM0_PWM_MODE_ASYM                  (PWM0_CC_MATCH_INVERT       |   \
                                                         PWM0_OVERLOW_SET           |   \
                                                         PWM0_UNDERFLOW_CLEAR)

#if (PWM0_CY_TCPWM_V2)
    #if(PWM0_CY_TCPWM_4000)
        #define PWM0_PWM_MODE_CENTER                (PWM0_CC_MATCH_INVERT       |   \
                                                                 PWM0_OVERLOW_NO_CHANGE     |   \
                                                                 PWM0_UNDERFLOW_CLEAR)
    #else
        #define PWM0_PWM_MODE_CENTER                (PWM0_CC_MATCH_INVERT       |   \
                                                                 PWM0_OVERLOW_SET           |   \
                                                                 PWM0_UNDERFLOW_CLEAR)
    #endif /* (PWM0_CY_TCPWM_4000) */
#else
    #define PWM0_PWM_MODE_CENTER                (PWM0_CC_MATCH_INVERT       |   \
                                                             PWM0_OVERLOW_NO_CHANGE     |   \
                                                             PWM0_UNDERFLOW_CLEAR)
#endif /* (PWM0_CY_TCPWM_NEW) */

/* Command operations without condition */
#define PWM0_CMD_CAPTURE                    (0u)
#define PWM0_CMD_RELOAD                     (8u)
#define PWM0_CMD_STOP                       (16u)
#define PWM0_CMD_START                      (24u)

/* Status */
#define PWM0_STATUS_DOWN                    (1u)
#define PWM0_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   PWM0_Init(void);
void   PWM0_Enable(void);
void   PWM0_Start(void);
void   PWM0_Stop(void);

void   PWM0_SetMode(uint32 mode);
void   PWM0_SetCounterMode(uint32 counterMode);
void   PWM0_SetPWMMode(uint32 modeMask);
void   PWM0_SetQDMode(uint32 qdMode);

void   PWM0_SetPrescaler(uint32 prescaler);
void   PWM0_TriggerCommand(uint32 mask, uint32 command);
void   PWM0_SetOneShot(uint32 oneShotEnable);
uint32 PWM0_ReadStatus(void);

void   PWM0_SetPWMSyncKill(uint32 syncKillEnable);
void   PWM0_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   PWM0_SetPWMDeadTime(uint32 deadTime);
void   PWM0_SetPWMInvert(uint32 mask);

void   PWM0_SetInterruptMode(uint32 interruptMask);
uint32 PWM0_GetInterruptSourceMasked(void);
uint32 PWM0_GetInterruptSource(void);
void   PWM0_ClearInterrupt(uint32 interruptMask);
void   PWM0_SetInterrupt(uint32 interruptMask);

void   PWM0_WriteCounter(uint32 count);
uint32 PWM0_ReadCounter(void);

uint32 PWM0_ReadCapture(void);
uint32 PWM0_ReadCaptureBuf(void);

void   PWM0_WritePeriod(uint32 period);
uint32 PWM0_ReadPeriod(void);
void   PWM0_WritePeriodBuf(uint32 periodBuf);
uint32 PWM0_ReadPeriodBuf(void);

void   PWM0_WriteCompare(uint32 compare);
uint32 PWM0_ReadCompare(void);
void   PWM0_WriteCompareBuf(uint32 compareBuf);
uint32 PWM0_ReadCompareBuf(void);

void   PWM0_SetPeriodSwap(uint32 swapEnable);
void   PWM0_SetCompareSwap(uint32 swapEnable);

void   PWM0_SetCaptureMode(uint32 triggerMode);
void   PWM0_SetReloadMode(uint32 triggerMode);
void   PWM0_SetStartMode(uint32 triggerMode);
void   PWM0_SetStopMode(uint32 triggerMode);
void   PWM0_SetCountMode(uint32 triggerMode);

void   PWM0_SaveConfig(void);
void   PWM0_RestoreConfig(void);
void   PWM0_Sleep(void);
void   PWM0_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define PWM0_BLOCK_CONTROL_REG              (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM0_BLOCK_CONTROL_PTR              ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM0_COMMAND_REG                    (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM0_COMMAND_PTR                    ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM0_INTRRUPT_CAUSE_REG             (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM0_INTRRUPT_CAUSE_PTR             ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM0_CONTROL_REG                    (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__CTRL )
#define PWM0_CONTROL_PTR                    ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__CTRL )
#define PWM0_STATUS_REG                     (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__STATUS )
#define PWM0_STATUS_PTR                     ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__STATUS )
#define PWM0_COUNTER_REG                    (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__COUNTER )
#define PWM0_COUNTER_PTR                    ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__COUNTER )
#define PWM0_COMP_CAP_REG                   (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__CC )
#define PWM0_COMP_CAP_PTR                   ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__CC )
#define PWM0_COMP_CAP_BUF_REG               (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM0_COMP_CAP_BUF_PTR               ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM0_PERIOD_REG                     (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__PERIOD )
#define PWM0_PERIOD_PTR                     ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__PERIOD )
#define PWM0_PERIOD_BUF_REG                 (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM0_PERIOD_BUF_PTR                 ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM0_TRIG_CONTROL0_REG              (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM0_TRIG_CONTROL0_PTR              ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM0_TRIG_CONTROL1_REG              (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM0_TRIG_CONTROL1_PTR              ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM0_TRIG_CONTROL2_REG              (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM0_TRIG_CONTROL2_PTR              ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM0_INTERRUPT_REQ_REG              (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__INTR )
#define PWM0_INTERRUPT_REQ_PTR              ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__INTR )
#define PWM0_INTERRUPT_SET_REG              (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM0_INTERRUPT_SET_PTR              ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM0_INTERRUPT_MASK_REG             (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM0_INTERRUPT_MASK_PTR             ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM0_INTERRUPT_MASKED_REG           (*(reg32 *) PWM0_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PWM0_INTERRUPT_MASKED_PTR           ( (reg32 *) PWM0_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define PWM0_MASK                           ((uint32)PWM0_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define PWM0_RELOAD_CC_SHIFT                (0u)
#define PWM0_RELOAD_PERIOD_SHIFT            (1u)
#define PWM0_PWM_SYNC_KILL_SHIFT            (2u)
#define PWM0_PWM_STOP_KILL_SHIFT            (3u)
#define PWM0_PRESCALER_SHIFT                (8u)
#define PWM0_UPDOWN_SHIFT                   (16u)
#define PWM0_ONESHOT_SHIFT                  (18u)
#define PWM0_QUAD_MODE_SHIFT                (20u)
#define PWM0_INV_OUT_SHIFT                  (20u)
#define PWM0_INV_COMPL_OUT_SHIFT            (21u)
#define PWM0_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define PWM0_RELOAD_CC_MASK                 ((uint32)(PWM0_1BIT_MASK        <<  \
                                                                            PWM0_RELOAD_CC_SHIFT))
#define PWM0_RELOAD_PERIOD_MASK             ((uint32)(PWM0_1BIT_MASK        <<  \
                                                                            PWM0_RELOAD_PERIOD_SHIFT))
#define PWM0_PWM_SYNC_KILL_MASK             ((uint32)(PWM0_1BIT_MASK        <<  \
                                                                            PWM0_PWM_SYNC_KILL_SHIFT))
#define PWM0_PWM_STOP_KILL_MASK             ((uint32)(PWM0_1BIT_MASK        <<  \
                                                                            PWM0_PWM_STOP_KILL_SHIFT))
#define PWM0_PRESCALER_MASK                 ((uint32)(PWM0_8BIT_MASK        <<  \
                                                                            PWM0_PRESCALER_SHIFT))
#define PWM0_UPDOWN_MASK                    ((uint32)(PWM0_2BIT_MASK        <<  \
                                                                            PWM0_UPDOWN_SHIFT))
#define PWM0_ONESHOT_MASK                   ((uint32)(PWM0_1BIT_MASK        <<  \
                                                                            PWM0_ONESHOT_SHIFT))
#define PWM0_QUAD_MODE_MASK                 ((uint32)(PWM0_3BIT_MASK        <<  \
                                                                            PWM0_QUAD_MODE_SHIFT))
#define PWM0_INV_OUT_MASK                   ((uint32)(PWM0_2BIT_MASK        <<  \
                                                                            PWM0_INV_OUT_SHIFT))
#define PWM0_MODE_MASK                      ((uint32)(PWM0_3BIT_MASK        <<  \
                                                                            PWM0_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define PWM0_CAPTURE_SHIFT                  (0u)
#define PWM0_COUNT_SHIFT                    (2u)
#define PWM0_RELOAD_SHIFT                   (4u)
#define PWM0_STOP_SHIFT                     (6u)
#define PWM0_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define PWM0_CAPTURE_MASK                   ((uint32)(PWM0_2BIT_MASK        <<  \
                                                                  PWM0_CAPTURE_SHIFT))
#define PWM0_COUNT_MASK                     ((uint32)(PWM0_2BIT_MASK        <<  \
                                                                  PWM0_COUNT_SHIFT))
#define PWM0_RELOAD_MASK                    ((uint32)(PWM0_2BIT_MASK        <<  \
                                                                  PWM0_RELOAD_SHIFT))
#define PWM0_STOP_MASK                      ((uint32)(PWM0_2BIT_MASK        <<  \
                                                                  PWM0_STOP_SHIFT))
#define PWM0_START_MASK                     ((uint32)(PWM0_2BIT_MASK        <<  \
                                                                  PWM0_START_SHIFT))

/* MASK */
#define PWM0_1BIT_MASK                      ((uint32)0x01u)
#define PWM0_2BIT_MASK                      ((uint32)0x03u)
#define PWM0_3BIT_MASK                      ((uint32)0x07u)
#define PWM0_6BIT_MASK                      ((uint32)0x3Fu)
#define PWM0_8BIT_MASK                      ((uint32)0xFFu)
#define PWM0_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define PWM0_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define PWM0_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(PWM0_QUAD_ENCODING_MODES     << PWM0_QUAD_MODE_SHIFT))       |\
         ((uint32)(PWM0_CONFIG                  << PWM0_MODE_SHIFT)))

#define PWM0_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(PWM0_PWM_STOP_EVENT          << PWM0_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(PWM0_PWM_OUT_INVERT          << PWM0_INV_OUT_SHIFT))         |\
         ((uint32)(PWM0_PWM_OUT_N_INVERT        << PWM0_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(PWM0_PWM_MODE                << PWM0_MODE_SHIFT)))

#define PWM0_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(PWM0_PWM_RUN_MODE         << PWM0_ONESHOT_SHIFT))
            
#define PWM0_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(PWM0_PWM_ALIGN            << PWM0_UPDOWN_SHIFT))

#define PWM0_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(PWM0_PWM_KILL_EVENT      << PWM0_PWM_SYNC_KILL_SHIFT))

#define PWM0_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(PWM0_PWM_DEAD_TIME_CYCLE  << PWM0_PRESCALER_SHIFT))

#define PWM0_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(PWM0_PWM_PRESCALER        << PWM0_PRESCALER_SHIFT))

#define PWM0_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(PWM0_TC_PRESCALER            << PWM0_PRESCALER_SHIFT))       |\
         ((uint32)(PWM0_TC_COUNTER_MODE         << PWM0_UPDOWN_SHIFT))          |\
         ((uint32)(PWM0_TC_RUN_MODE             << PWM0_ONESHOT_SHIFT))         |\
         ((uint32)(PWM0_TC_COMP_CAP_MODE        << PWM0_MODE_SHIFT)))
        
#define PWM0_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(PWM0_QUAD_PHIA_SIGNAL_MODE   << PWM0_COUNT_SHIFT))           |\
         ((uint32)(PWM0_QUAD_INDEX_SIGNAL_MODE  << PWM0_RELOAD_SHIFT))          |\
         ((uint32)(PWM0_QUAD_STOP_SIGNAL_MODE   << PWM0_STOP_SHIFT))            |\
         ((uint32)(PWM0_QUAD_PHIB_SIGNAL_MODE   << PWM0_START_SHIFT)))

#define PWM0_PWM_SIGNALS_MODES                                                              \
        (((uint32)(PWM0_PWM_SWITCH_SIGNAL_MODE  << PWM0_CAPTURE_SHIFT))         |\
         ((uint32)(PWM0_PWM_COUNT_SIGNAL_MODE   << PWM0_COUNT_SHIFT))           |\
         ((uint32)(PWM0_PWM_RELOAD_SIGNAL_MODE  << PWM0_RELOAD_SHIFT))          |\
         ((uint32)(PWM0_PWM_STOP_SIGNAL_MODE    << PWM0_STOP_SHIFT))            |\
         ((uint32)(PWM0_PWM_START_SIGNAL_MODE   << PWM0_START_SHIFT)))

#define PWM0_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(PWM0_TC_CAPTURE_SIGNAL_MODE  << PWM0_CAPTURE_SHIFT))         |\
         ((uint32)(PWM0_TC_COUNT_SIGNAL_MODE    << PWM0_COUNT_SHIFT))           |\
         ((uint32)(PWM0_TC_RELOAD_SIGNAL_MODE   << PWM0_RELOAD_SHIFT))          |\
         ((uint32)(PWM0_TC_STOP_SIGNAL_MODE     << PWM0_STOP_SHIFT))            |\
         ((uint32)(PWM0_TC_START_SIGNAL_MODE    << PWM0_START_SHIFT)))
        
#define PWM0_TIMER_UPDOWN_CNT_USED                                                          \
                ((PWM0__COUNT_UPDOWN0 == PWM0_TC_COUNTER_MODE)                  ||\
                 (PWM0__COUNT_UPDOWN1 == PWM0_TC_COUNTER_MODE))

#define PWM0_PWM_UPDOWN_CNT_USED                                                            \
                ((PWM0__CENTER == PWM0_PWM_ALIGN)                               ||\
                 (PWM0__ASYMMETRIC == PWM0_PWM_ALIGN))               
        
#define PWM0_PWM_PR_INIT_VALUE              (1u)
#define PWM0_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_PWM0_H */

/* [] END OF FILE */
