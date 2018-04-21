/*******************************************************************************
* File Name: Pot0Pin.h  
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

#if !defined(CY_PINS_Pot0Pin_ALIASES_H) /* Pins Pot0Pin_ALIASES_H */
#define CY_PINS_Pot0Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Pot0Pin_0			(Pot0Pin__0__PC)
#define Pot0Pin_0_PS		(Pot0Pin__0__PS)
#define Pot0Pin_0_PC		(Pot0Pin__0__PC)
#define Pot0Pin_0_DR		(Pot0Pin__0__DR)
#define Pot0Pin_0_SHIFT	(Pot0Pin__0__SHIFT)
#define Pot0Pin_0_INTR	((uint16)((uint16)0x0003u << (Pot0Pin__0__SHIFT*2u)))

#define Pot0Pin_INTR_ALL	 ((uint16)(Pot0Pin_0_INTR))


#endif /* End Pins Pot0Pin_ALIASES_H */


/* [] END OF FILE */
