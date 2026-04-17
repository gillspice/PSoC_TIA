/*******************************************************************************
* File Name: Control_Knob.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Control_Knob_ALIASES_H) /* Pins Control_Knob_ALIASES_H */
#define CY_PINS_Control_Knob_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Control_Knob_0			(Control_Knob__0__PC)
#define Control_Knob_0_PS		(Control_Knob__0__PS)
#define Control_Knob_0_PC		(Control_Knob__0__PC)
#define Control_Knob_0_DR		(Control_Knob__0__DR)
#define Control_Knob_0_SHIFT	(Control_Knob__0__SHIFT)
#define Control_Knob_0_INTR	((uint16)((uint16)0x0003u << (Control_Knob__0__SHIFT*2u)))

#define Control_Knob_INTR_ALL	 ((uint16)(Control_Knob_0_INTR))


#endif /* End Pins Control_Knob_ALIASES_H */


/* [] END OF FILE */
