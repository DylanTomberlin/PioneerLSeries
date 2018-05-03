/*******************************************************************************
* File Name: QuadDec2_PM.c
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

#include "QuadDec2.h"

static QuadDec2_BACKUP_STRUCT QuadDec2_backup;


/*******************************************************************************
* Function Name: QuadDec2_SaveConfig
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
void QuadDec2_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec2_Sleep
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
void QuadDec2_Sleep(void)
{
    if(0u != (QuadDec2_BLOCK_CONTROL_REG & QuadDec2_MASK))
    {
        QuadDec2_backup.enableState = 1u;
    }
    else
    {
        QuadDec2_backup.enableState = 0u;
    }

    QuadDec2_Stop();
    QuadDec2_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec2_RestoreConfig
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
void QuadDec2_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec2_Wakeup
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
void QuadDec2_Wakeup(void)
{
    QuadDec2_RestoreConfig();

    if(0u != QuadDec2_backup.enableState)
    {
        QuadDec2_Enable();
    }
}


/* [] END OF FILE */
