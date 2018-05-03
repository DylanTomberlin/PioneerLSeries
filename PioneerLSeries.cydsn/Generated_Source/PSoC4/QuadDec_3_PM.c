/*******************************************************************************
* File Name: QuadDec_3_PM.c
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

#include "QuadDec_3.h"

static QuadDec_3_BACKUP_STRUCT QuadDec_3_backup;


/*******************************************************************************
* Function Name: QuadDec_3_SaveConfig
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
void QuadDec_3_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_3_Sleep
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
void QuadDec_3_Sleep(void)
{
    if(0u != (QuadDec_3_BLOCK_CONTROL_REG & QuadDec_3_MASK))
    {
        QuadDec_3_backup.enableState = 1u;
    }
    else
    {
        QuadDec_3_backup.enableState = 0u;
    }

    QuadDec_3_Stop();
    QuadDec_3_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_3_RestoreConfig
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
void QuadDec_3_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_3_Wakeup
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
void QuadDec_3_Wakeup(void)
{
    QuadDec_3_RestoreConfig();

    if(0u != QuadDec_3_backup.enableState)
    {
        QuadDec_3_Enable();
    }
}


/* [] END OF FILE */
