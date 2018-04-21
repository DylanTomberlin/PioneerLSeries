/*******************************************************************************
* File Name: Pot1Pin.h  
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

#if !defined(CY_PINS_Pot1Pin_ALIASES_H) /* Pins Pot1Pin_ALIASES_H */
#define CY_PINS_Pot1Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Pot1Pin_0			(Pot1Pin__0__PC)
#define Pot1Pin_0_PS		(Pot1Pin__0__PS)
#define Pot1Pin_0_PC		(Pot1Pin__0__PC)
#define Pot1Pin_0_DR		(Pot1Pin__0__DR)
#define Pot1Pin_0_SHIFT	(Pot1Pin__0__SHIFT)
#define Pot1Pin_0_INTR	((uint16)((uint16)0x0003u << (Pot1Pin__0__SHIFT*2u)))

#define Pot1Pin_INTR_ALL	 ((uint16)(Pot1Pin_0_INTR))


#endif /* End Pins Pot1Pin_ALIASES_H */


/* [] END OF FILE */
