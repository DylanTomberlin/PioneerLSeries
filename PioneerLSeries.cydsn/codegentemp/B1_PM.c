/*******************************************************************************
* File Name: B1.c  
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
#include "B1.h"

static B1_BACKUP_STRUCT  B1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: B1_Sleep
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
*  \snippet B1_SUT.c usage_B1_Sleep_Wakeup
*******************************************************************************/
void B1_Sleep(void)
{
    #if defined(B1__PC)
        B1_backup.pcState = B1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            B1_backup.usbState = B1_CR1_REG;
            B1_USB_POWER_REG |= B1_USBIO_ENTER_SLEEP;
            B1_CR1_REG &= B1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(B1__SIO)
        B1_backup.sioState = B1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        B1_SIO_REG &= (uint32)(~B1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: B1_Wakeup
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
*  Refer to B1_Sleep() for an example usage.
*******************************************************************************/
void B1_Wakeup(void)
{
    #if defined(B1__PC)
        B1_PC = B1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            B1_USB_POWER_REG &= B1_USBIO_EXIT_SLEEP_PH1;
            B1_CR1_REG = B1_backup.usbState;
            B1_USB_POWER_REG &= B1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(B1__SIO)
        B1_SIO_REG = B1_backup.sioState;
    #endif
}


/* [] END OF FILE */
