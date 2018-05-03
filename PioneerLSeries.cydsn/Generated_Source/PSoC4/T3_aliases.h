/*******************************************************************************
* File Name: T3.h  
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

#if !defined(CY_PINS_T3_ALIASES_H) /* Pins T3_ALIASES_H */
#define CY_PINS_T3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define T3_0			(T3__0__PC)
#define T3_0_PS		(T3__0__PS)
#define T3_0_PC		(T3__0__PC)
#define T3_0_DR		(T3__0__DR)
#define T3_0_SHIFT	(T3__0__SHIFT)
#define T3_0_INTR	((uint16)((uint16)0x0003u << (T3__0__SHIFT*2u)))

#define T3_INTR_ALL	 ((uint16)(T3_0_INTR))


#endif /* End Pins T3_ALIASES_H */


/* [] END OF FILE */
