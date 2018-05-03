/*******************************************************************************
* File Name: isrLim2.h
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
#if !defined(CY_ISR_isrLim2_H)
#define CY_ISR_isrLim2_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrLim2_Start(void);
void isrLim2_StartEx(cyisraddress address);
void isrLim2_Stop(void);

CY_ISR_PROTO(isrLim2_Interrupt);

void isrLim2_SetVector(cyisraddress address);
cyisraddress isrLim2_GetVector(void);

void isrLim2_SetPriority(uint8 priority);
uint8 isrLim2_GetPriority(void);

void isrLim2_Enable(void);
uint8 isrLim2_GetState(void);
void isrLim2_Disable(void);

void isrLim2_SetPending(void);
void isrLim2_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrLim2 ISR. */
#define isrLim2_INTC_VECTOR            ((reg32 *) isrLim2__INTC_VECT)

/* Address of the isrLim2 ISR priority. */
#define isrLim2_INTC_PRIOR             ((reg32 *) isrLim2__INTC_PRIOR_REG)

/* Priority of the isrLim2 interrupt. */
#define isrLim2_INTC_PRIOR_NUMBER      isrLim2__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrLim2 interrupt. */
#define isrLim2_INTC_SET_EN            ((reg32 *) isrLim2__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrLim2 interrupt. */
#define isrLim2_INTC_CLR_EN            ((reg32 *) isrLim2__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrLim2 interrupt state to pending. */
#define isrLim2_INTC_SET_PD            ((reg32 *) isrLim2__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrLim2 interrupt. */
#define isrLim2_INTC_CLR_PD            ((reg32 *) isrLim2__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrLim2_H */


/* [] END OF FILE */
