/*******************************************************************************
* File Name: LimitPin3.h  
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

#if !defined(CY_PINS_LimitPin3_H) /* Pins LimitPin3_H */
#define CY_PINS_LimitPin3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LimitPin3_aliases.h"


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
} LimitPin3_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LimitPin3_Read(void);
void    LimitPin3_Write(uint8 value);
uint8   LimitPin3_ReadDataReg(void);
#if defined(LimitPin3__PC) || (CY_PSOC4_4200L) 
    void    LimitPin3_SetDriveMode(uint8 mode);
#endif
void    LimitPin3_SetInterruptMode(uint16 position, uint16 mode);
uint8   LimitPin3_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LimitPin3_Sleep(void); 
void LimitPin3_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LimitPin3__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LimitPin3_DRIVE_MODE_BITS        (3)
    #define LimitPin3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LimitPin3_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LimitPin3_SetDriveMode() function.
         *  @{
         */
        #define LimitPin3_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LimitPin3_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LimitPin3_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LimitPin3_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LimitPin3_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LimitPin3_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LimitPin3_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LimitPin3_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LimitPin3_MASK               LimitPin3__MASK
#define LimitPin3_SHIFT              LimitPin3__SHIFT
#define LimitPin3_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LimitPin3_SetInterruptMode() function.
     *  @{
     */
        #define LimitPin3_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LimitPin3_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LimitPin3_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LimitPin3_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LimitPin3__SIO)
    #define LimitPin3_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LimitPin3__PC) && (CY_PSOC4_4200L)
    #define LimitPin3_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LimitPin3_USBIO_DISABLE              ((uint32)(~LimitPin3_USBIO_ENABLE))
    #define LimitPin3_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LimitPin3_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LimitPin3_USBIO_ENTER_SLEEP          ((uint32)((1u << LimitPin3_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LimitPin3_USBIO_SUSPEND_DEL_SHIFT)))
    #define LimitPin3_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LimitPin3_USBIO_SUSPEND_SHIFT)))
    #define LimitPin3_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LimitPin3_USBIO_SUSPEND_DEL_SHIFT)))
    #define LimitPin3_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LimitPin3__PC)
    /* Port Configuration */
    #define LimitPin3_PC                 (* (reg32 *) LimitPin3__PC)
#endif
/* Pin State */
#define LimitPin3_PS                     (* (reg32 *) LimitPin3__PS)
/* Data Register */
#define LimitPin3_DR                     (* (reg32 *) LimitPin3__DR)
/* Input Buffer Disable Override */
#define LimitPin3_INP_DIS                (* (reg32 *) LimitPin3__PC2)

/* Interrupt configuration Registers */
#define LimitPin3_INTCFG                 (* (reg32 *) LimitPin3__INTCFG)
#define LimitPin3_INTSTAT                (* (reg32 *) LimitPin3__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LimitPin3_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LimitPin3__SIO)
    #define LimitPin3_SIO_REG            (* (reg32 *) LimitPin3__SIO)
#endif /* (LimitPin3__SIO_CFG) */

/* USBIO registers */
#if !defined(LimitPin3__PC) && (CY_PSOC4_4200L)
    #define LimitPin3_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LimitPin3_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LimitPin3_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LimitPin3_DRIVE_MODE_SHIFT       (0x00u)
#define LimitPin3_DRIVE_MODE_MASK        (0x07u << LimitPin3_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LimitPin3_H */


/* [] END OF FILE */
