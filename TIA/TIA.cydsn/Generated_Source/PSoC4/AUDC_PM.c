/*******************************************************************************
* File Name: AUDC_PM.c
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

#include "AUDC.h"

/* Check for removal by optimization */
#if !defined(AUDC_Sync_ctrl_reg__REMOVED)

static AUDC_BACKUP_STRUCT  AUDC_backup = {0u};

    
/*******************************************************************************
* Function Name: AUDC_SaveConfig
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
void AUDC_SaveConfig(void) 
{
    AUDC_backup.controlState = AUDC_Control;
}


/*******************************************************************************
* Function Name: AUDC_RestoreConfig
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
void AUDC_RestoreConfig(void) 
{
     AUDC_Control = AUDC_backup.controlState;
}


/*******************************************************************************
* Function Name: AUDC_Sleep
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
void AUDC_Sleep(void) 
{
    AUDC_SaveConfig();
}


/*******************************************************************************
* Function Name: AUDC_Wakeup
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
void AUDC_Wakeup(void)  
{
    AUDC_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
