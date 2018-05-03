/*******************************************************************************
* File Name: QuadClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_QuadClock_H)
#define CY_CLOCK_QuadClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void QuadClock_StartEx(uint32 alignClkDiv);
#define QuadClock_Start() \
    QuadClock_StartEx(QuadClock__PA_DIV_ID)

#else

void QuadClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void QuadClock_Stop(void);

void QuadClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 QuadClock_GetDividerRegister(void);
uint8  QuadClock_GetFractionalDividerRegister(void);

#define QuadClock_Enable()                         QuadClock_Start()
#define QuadClock_Disable()                        QuadClock_Stop()
#define QuadClock_SetDividerRegister(clkDivider, reset)  \
    QuadClock_SetFractionalDividerRegister((clkDivider), 0u)
#define QuadClock_SetDivider(clkDivider)           QuadClock_SetDividerRegister((clkDivider), 1u)
#define QuadClock_SetDividerValue(clkDivider)      QuadClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define QuadClock_DIV_ID     QuadClock__DIV_ID

#define QuadClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define QuadClock_CTRL_REG   (*(reg32 *)QuadClock__CTRL_REGISTER)
#define QuadClock_DIV_REG    (*(reg32 *)QuadClock__DIV_REGISTER)

#define QuadClock_CMD_DIV_SHIFT          (0u)
#define QuadClock_CMD_PA_DIV_SHIFT       (8u)
#define QuadClock_CMD_DISABLE_SHIFT      (30u)
#define QuadClock_CMD_ENABLE_SHIFT       (31u)

#define QuadClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << QuadClock_CMD_DISABLE_SHIFT))
#define QuadClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << QuadClock_CMD_ENABLE_SHIFT))

#define QuadClock_DIV_FRAC_MASK  (0x000000F8u)
#define QuadClock_DIV_FRAC_SHIFT (3u)
#define QuadClock_DIV_INT_MASK   (0xFFFFFF00u)
#define QuadClock_DIV_INT_SHIFT  (8u)

#else 

#define QuadClock_DIV_REG        (*(reg32 *)QuadClock__REGISTER)
#define QuadClock_ENABLE_REG     QuadClock_DIV_REG
#define QuadClock_DIV_FRAC_MASK  QuadClock__FRAC_MASK
#define QuadClock_DIV_FRAC_SHIFT (16u)
#define QuadClock_DIV_INT_MASK   QuadClock__DIVIDER_MASK
#define QuadClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_QuadClock_H) */

/* [] END OF FILE */
