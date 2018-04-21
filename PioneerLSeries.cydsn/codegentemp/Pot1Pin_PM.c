/*******************************************************************************
* File Name: Pot1Pin.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Pot1Pin.h"

static Pot1Pin_BACKUP_STRUCT  Pot1Pin_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Pot1Pin_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Pot1Pin_SUT.c usage_Pot1Pin_Sleep_Wakeup
*******************************************************************************/
void Pot1Pin_Sleep(void)
{
    #if defined(Pot1Pin__PC)
        Pot1Pin_backup.pcState = Pot1Pin_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Pot1Pin_backup.usbState = Pot1Pin_CR1_REG;
            Pot1Pin_USB_POWER_REG |= Pot1Pin_USBIO_ENTER_SLEEP;
            Pot1Pin_CR1_REG &= Pot1Pin_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Pot1Pin__SIO)
        Pot1Pin_backup.sioState = Pot1Pin_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Pot1Pin_SIO_REG &= (uint32)(~Pot1Pin_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Pot1Pin_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Pot1Pin_Sleep() for an example usage.
*******************************************************************************/
void Pot1Pin_Wakeup(void)
{
    #if defined(Pot1Pin__PC)
        Pot1Pin_PC = Pot1Pin_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Pot1Pin_USB_POWER_REG &= Pot1Pin_USBIO_EXIT_SLEEP_PH1;
            Pot1Pin_CR1_REG = Pot1Pin_backup.usbState;
            Pot1Pin_USB_POWER_REG &= Pot1Pin_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Pot1Pin__SIO)
        Pot1Pin_SIO_REG = Pot1Pin_backup.sioState;
    #endif
}


/* [] END OF FILE */
