/*******************************************************************************
* File Name: AUDF_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "AUDF.h"

/* Check for removal by optimization */
#if !defined(AUDF_Sync_ctrl_reg__REMOVED)

static AUDF_BACKUP_STRUCT  AUDF_backup = {0u};

    
/*******************************************************************************
* Function Name: AUDF_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void AUDF_SaveConfig(void) 
{
    AUDF_backup.controlState = AUDF_Control;
}


/*******************************************************************************
* Function Name: AUDF_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void AUDF_RestoreConfig(void) 
{
     AUDF_Control = AUDF_backup.controlState;
}


/*******************************************************************************
* Function Name: AUDF_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void AUDF_Sleep(void) 
{
    AUDF_SaveConfig();
}


/*******************************************************************************
* Function Name: AUDF_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void AUDF_Wakeup(void)  
{
    AUDF_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
