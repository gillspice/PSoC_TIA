/*******************************************************************************
* File Name: AUDF.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_AUDF_H) /* CY_CONTROL_REG_AUDF_H */
#define CY_CONTROL_REG_AUDF_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} AUDF_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    AUDF_Write(uint8 control) ;
uint8   AUDF_Read(void) ;

void AUDF_SaveConfig(void) ;
void AUDF_RestoreConfig(void) ;
void AUDF_Sleep(void) ; 
void AUDF_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define AUDF_Control        (* (reg8 *) AUDF_Sync_ctrl_reg__CONTROL_REG )
#define AUDF_Control_PTR    (  (reg8 *) AUDF_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_AUDF_H */


/* [] END OF FILE */
