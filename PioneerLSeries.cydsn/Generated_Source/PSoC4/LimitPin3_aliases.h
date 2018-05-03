/*******************************************************************************
* File Name: LimitPin3.h  
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

#if !defined(CY_PINS_LimitPin3_ALIASES_H) /* Pins LimitPin3_ALIASES_H */
#define CY_PINS_LimitPin3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LimitPin3_0			(LimitPin3__0__PC)
#define LimitPin3_0_PS		(LimitPin3__0__PS)
#define LimitPin3_0_PC		(LimitPin3__0__PC)
#define LimitPin3_0_DR		(LimitPin3__0__DR)
#define LimitPin3_0_SHIFT	(LimitPin3__0__SHIFT)
#define LimitPin3_0_INTR	((uint16)((uint16)0x0003u << (LimitPin3__0__SHIFT*2u)))

#define LimitPin3_INTR_ALL	 ((uint16)(LimitPin3_0_INTR))


#endif /* End Pins LimitPin3_ALIASES_H */


/* [] END OF FILE */
