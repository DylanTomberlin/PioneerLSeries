/*******************************************************************************
* File Name: QuadDec0_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "QuadDec0.h"

static QuadDec0_BACKUP_STRUCT QuadDec0_backup;


/*******************************************************************************
* Function Name: QuadDec0_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec0_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_Sleep(void)
{
    if(0u != (QuadDec0_BLOCK_CONTROL_REG & QuadDec0_MASK))
    {
        QuadDec0_backup.enableState = 1u;
    }
    else
    {
        QuadDec0_backup.enableState = 0u;
    }

    QuadDec0_Stop();
    QuadDec0_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec0_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec0_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec0_Wakeup(void)
{
    QuadDec0_RestoreConfig();

    if(0u != QuadDec0_backup.enableState)
    {
        QuadDec0_Enable();
    }
}


/* [] END OF FILE */
