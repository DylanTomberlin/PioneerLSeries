/*******************************************************************************
* File Name: LimitPin1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LimitPin1_ALIASES_H) /* Pins LimitPin1_ALIASES_H */
#define CY_PINS_LimitPin1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LimitPin1_0			(LimitPin1__0__PC)
#define LimitPin1_0_PS		(LimitPin1__0__PS)
#define LimitPin1_0_PC		(LimitPin1__0__PC)
#define LimitPin1_0_DR		(LimitPin1__0__DR)
#define LimitPin1_0_SHIFT	(LimitPin1__0__SHIFT)
#define LimitPin1_0_INTR	((uint16)((uint16)0x0003u << (LimitPin1__0__SHIFT*2u)))

#define LimitPin1_INTR_ALL	 ((uint16)(LimitPin1_0_INTR))


#endif /* End Pins LimitPin1_ALIASES_H */


/* [] END OF FILE */
