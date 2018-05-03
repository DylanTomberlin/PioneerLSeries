/*******************************************************************************
* File Name: R1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_R1_H) /* Pins R1_H */
#define CY_PINS_R1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "R1_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} R1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   R1_Read(void);
void    R1_Write(uint8 value);
uint8   R1_ReadDataReg(void);
#if defined(R1__PC) || (CY_PSOC4_4200L) 
    void    R1_SetDriveMode(uint8 mode);
#endif
void    R1_SetInterruptMode(uint16 position, uint16 mode);
uint8   R1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void R1_Sleep(void); 
void R1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(R1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define R1_DRIVE_MODE_BITS        (3)
    #define R1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - R1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the R1_SetDriveMode() function.
         *  @{
         */
        #define R1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define R1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define R1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define R1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define R1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define R1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define R1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define R1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define R1_MASK               R1__MASK
#define R1_SHIFT              R1__SHIFT
#define R1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in R1_SetInterruptMode() function.
     *  @{
     */
        #define R1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define R1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define R1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define R1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(R1__SIO)
    #define R1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(R1__PC) && (CY_PSOC4_4200L)
    #define R1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define R1_USBIO_DISABLE              ((uint32)(~R1_USBIO_ENABLE))
    #define R1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define R1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define R1_USBIO_ENTER_SLEEP          ((uint32)((1u << R1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << R1_USBIO_SUSPEND_DEL_SHIFT)))
    #define R1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << R1_USBIO_SUSPEND_SHIFT)))
    #define R1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << R1_USBIO_SUSPEND_DEL_SHIFT)))
    #define R1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(R1__PC)
    /* Port Configuration */
    #define R1_PC                 (* (reg32 *) R1__PC)
#endif
/* Pin State */
#define R1_PS                     (* (reg32 *) R1__PS)
/* Data Register */
#define R1_DR                     (* (reg32 *) R1__DR)
/* Input Buffer Disable Override */
#define R1_INP_DIS                (* (reg32 *) R1__PC2)

/* Interrupt configuration Registers */
#define R1_INTCFG                 (* (reg32 *) R1__INTCFG)
#define R1_INTSTAT                (* (reg32 *) R1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define R1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(R1__SIO)
    #define R1_SIO_REG            (* (reg32 *) R1__SIO)
#endif /* (R1__SIO_CFG) */

/* USBIO registers */
#if !defined(R1__PC) && (CY_PSOC4_4200L)
    #define R1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define R1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define R1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define R1_DRIVE_MODE_SHIFT       (0x00u)
#define R1_DRIVE_MODE_MASK        (0x07u << R1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins R1_H */


/* [] END OF FILE */
