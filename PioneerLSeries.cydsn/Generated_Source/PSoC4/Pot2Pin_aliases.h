/*******************************************************************************
* File Name: Pot2Pin.h  
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

#if !defined(CY_PINS_Pot2Pin_ALIASES_H) /* Pins Pot2Pin_ALIASES_H */
#define CY_PINS_Pot2Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Pot2Pin_0			(Pot2Pin__0__PC)
#define Pot2Pin_0_PS		(Pot2Pin__0__PS)
#define Pot2Pin_0_PC		(Pot2Pin__0__PC)
#define Pot2Pin_0_DR		(Pot2Pin__0__DR)
#define Pot2Pin_0_SHIFT	(Pot2Pin__0__SHIFT)
#define Pot2Pin_0_INTR	((uint16)((uint16)0x0003u << (Pot2Pin__0__SHIFT*2u)))

#define Pot2Pin_INTR_ALL	 ((uint16)(Pot2Pin_0_INTR))


#endif /* End Pins Pot2Pin_ALIASES_H */


/* [] END OF FILE */
