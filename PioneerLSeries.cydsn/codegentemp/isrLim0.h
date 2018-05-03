/*******************************************************************************
* File Name: isrLim0.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isrLim0_H)
#define CY_ISR_isrLim0_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrLim0_Start(void);
void isrLim0_StartEx(cyisraddress address);
void isrLim0_Stop(void);

CY_ISR_PROTO(isrLim0_Interrupt);

void isrLim0_SetVector(cyisraddress address);
cyisraddress isrLim0_GetVector(void);

void isrLim0_SetPriority(uint8 priority);
uint8 isrLim0_GetPriority(void);

void isrLim0_Enable(void);
uint8 isrLim0_GetState(void);
void isrLim0_Disable(void);

void isrLim0_SetPending(void);
void isrLim0_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrLim0 ISR. */
#define isrLim0_INTC_VECTOR            ((reg32 *) isrLim0__INTC_VECT)

/* Address of the isrLim0 ISR priority. */
#define isrLim0_INTC_PRIOR             ((reg32 *) isrLim0__INTC_PRIOR_REG)

/* Priority of the isrLim0 interrupt. */
#define isrLim0_INTC_PRIOR_NUMBER      isrLim0__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrLim0 interrupt. */
#define isrLim0_INTC_SET_EN            ((reg32 *) isrLim0__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrLim0 interrupt. */
#define isrLim0_INTC_CLR_EN            ((reg32 *) isrLim0__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrLim0 interrupt state to pending. */
#define isrLim0_INTC_SET_PD            ((reg32 *) isrLim0__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrLim0 interrupt. */
#define isrLim0_INTC_CLR_PD            ((reg32 *) isrLim0__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrLim0_H */


/* [] END OF FILE */
