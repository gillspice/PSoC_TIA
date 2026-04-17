/*******************************************************************************
* File Name: Frequency_CV.h  
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

#if !defined(CY_PINS_Frequency_CV_H) /* Pins Frequency_CV_H */
#define CY_PINS_Frequency_CV_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Frequency_CV_aliases.h"


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
} Frequency_CV_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Frequency_CV_Read(void);
void    Frequency_CV_Write(uint8 value);
uint8   Frequency_CV_ReadDataReg(void);
#if defined(Frequency_CV__PC) || (CY_PSOC4_4200L) 
    void    Frequency_CV_SetDriveMode(uint8 mode);
#endif
void    Frequency_CV_SetInterruptMode(uint16 position, uint16 mode);
uint8   Frequency_CV_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Frequency_CV_Sleep(void); 
void Frequency_CV_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Frequency_CV__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Frequency_CV_DRIVE_MODE_BITS        (3)
    #define Frequency_CV_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Frequency_CV_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Frequency_CV_SetDriveMode() function.
         *  @{
         */
        #define Frequency_CV_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Frequency_CV_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Frequency_CV_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Frequency_CV_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Frequency_CV_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Frequency_CV_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Frequency_CV_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Frequency_CV_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Frequency_CV_MASK               Frequency_CV__MASK
#define Frequency_CV_SHIFT              Frequency_CV__SHIFT
#define Frequency_CV_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Frequency_CV_SetInterruptMode() function.
     *  @{
     */
        #define Frequency_CV_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Frequency_CV_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Frequency_CV_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Frequency_CV_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Frequency_CV__SIO)
    #define Frequency_CV_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Frequency_CV__PC) && (CY_PSOC4_4200L)
    #define Frequency_CV_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Frequency_CV_USBIO_DISABLE              ((uint32)(~Frequency_CV_USBIO_ENABLE))
    #define Frequency_CV_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Frequency_CV_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Frequency_CV_USBIO_ENTER_SLEEP          ((uint32)((1u << Frequency_CV_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Frequency_CV_USBIO_SUSPEND_DEL_SHIFT)))
    #define Frequency_CV_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Frequency_CV_USBIO_SUSPEND_SHIFT)))
    #define Frequency_CV_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Frequency_CV_USBIO_SUSPEND_DEL_SHIFT)))
    #define Frequency_CV_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Frequency_CV__PC)
    /* Port Configuration */
    #define Frequency_CV_PC                 (* (reg32 *) Frequency_CV__PC)
#endif
/* Pin State */
#define Frequency_CV_PS                     (* (reg32 *) Frequency_CV__PS)
/* Data Register */
#define Frequency_CV_DR                     (* (reg32 *) Frequency_CV__DR)
/* Input Buffer Disable Override */
#define Frequency_CV_INP_DIS                (* (reg32 *) Frequency_CV__PC2)

/* Interrupt configuration Registers */
#define Frequency_CV_INTCFG                 (* (reg32 *) Frequency_CV__INTCFG)
#define Frequency_CV_INTSTAT                (* (reg32 *) Frequency_CV__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Frequency_CV_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Frequency_CV__SIO)
    #define Frequency_CV_SIO_REG            (* (reg32 *) Frequency_CV__SIO)
#endif /* (Frequency_CV__SIO_CFG) */

/* USBIO registers */
#if !defined(Frequency_CV__PC) && (CY_PSOC4_4200L)
    #define Frequency_CV_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Frequency_CV_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Frequency_CV_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Frequency_CV_DRIVE_MODE_SHIFT       (0x00u)
#define Frequency_CV_DRIVE_MODE_MASK        (0x07u << Frequency_CV_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Frequency_CV_H */


/* [] END OF FILE */
