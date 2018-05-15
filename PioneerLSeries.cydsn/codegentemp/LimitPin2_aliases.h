/*******************************************************************************
* File Name: LimitPin2.h  
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

#if !defined(CY_PINS_LimitPin2_ALIASES_H) /* Pins LimitPin2_ALIASES_H */
#define CY_PINS_LimitPin2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LimitPin2_0			(LimitPin2__0__PC)
#define LimitPin2_0_PS		(LimitPin2__0__PS)
#define LimitPin2_0_PC		(LimitPin2__0__PC)
#define LimitPin2_0_DR		(LimitPin2__0__DR)
#define LimitPin2_0_SHIFT	(LimitPin2__0__SHIFT)
#define LimitPin2_0_INTR	((uint16)((uint16)0x0003u << (LimitPin2__0__SHIFT*2u)))

#define LimitPin2_INTR_ALL	 ((uint16)(LimitPin2_0_INTR))


#endif /* End Pins LimitPin2_ALIASES_H */


/* [] END OF FILE */
