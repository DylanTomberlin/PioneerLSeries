/*******************************************************************************
* File Name: isrLim1.h
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
#if !defined(CY_ISR_isrLim1_H)
#define CY_ISR_isrLim1_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrLim1_Start(void);
void isrLim1_StartEx(cyisraddress address);
void isrLim1_Stop(void);

CY_ISR_PROTO(isrLim1_Interrupt);

void isrLim1_SetVector(cyisraddress address);
cyisraddress isrLim1_GetVector(void);

void isrLim1_SetPriority(uint8 priority);
uint8 isrLim1_GetPriority(void);

void isrLim1_Enable(void);
uint8 isrLim1_GetState(void);
void isrLim1_Disable(void);

void isrLim1_SetPending(void);
void isrLim1_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrLim1 ISR. */
#define isrLim1_INTC_VECTOR            ((reg32 *) isrLim1__INTC_VECT)

/* Address of the isrLim1 ISR priority. */
#define isrLim1_INTC_PRIOR             ((reg32 *) isrLim1__INTC_PRIOR_REG)

/* Priority of the isrLim1 interrupt. */
#define isrLim1_INTC_PRIOR_NUMBER      isrLim1__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrLim1 interrupt. */
#define isrLim1_INTC_SET_EN            ((reg32 *) isrLim1__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrLim1 interrupt. */
#define isrLim1_INTC_CLR_EN            ((reg32 *) isrLim1__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrLim1 interrupt state to pending. */
#define isrLim1_INTC_SET_PD            ((reg32 *) isrLim1__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrLim1 interrupt. */
#define isrLim1_INTC_CLR_PD            ((reg32 *) isrLim1__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrLim1_H */


/* [] END OF FILE */
