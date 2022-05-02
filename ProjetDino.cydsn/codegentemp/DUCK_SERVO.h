/*******************************************************************************
* File Name: DUCK_SERVO.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DUCK_SERVO_H) /* Pins DUCK_SERVO_H */
#define CY_PINS_DUCK_SERVO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DUCK_SERVO_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DUCK_SERVO__PORT == 15 && ((DUCK_SERVO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DUCK_SERVO_Write(uint8 value);
void    DUCK_SERVO_SetDriveMode(uint8 mode);
uint8   DUCK_SERVO_ReadDataReg(void);
uint8   DUCK_SERVO_Read(void);
void    DUCK_SERVO_SetInterruptMode(uint16 position, uint16 mode);
uint8   DUCK_SERVO_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DUCK_SERVO_SetDriveMode() function.
     *  @{
     */
        #define DUCK_SERVO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DUCK_SERVO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DUCK_SERVO_DM_RES_UP          PIN_DM_RES_UP
        #define DUCK_SERVO_DM_RES_DWN         PIN_DM_RES_DWN
        #define DUCK_SERVO_DM_OD_LO           PIN_DM_OD_LO
        #define DUCK_SERVO_DM_OD_HI           PIN_DM_OD_HI
        #define DUCK_SERVO_DM_STRONG          PIN_DM_STRONG
        #define DUCK_SERVO_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DUCK_SERVO_MASK               DUCK_SERVO__MASK
#define DUCK_SERVO_SHIFT              DUCK_SERVO__SHIFT
#define DUCK_SERVO_WIDTH              1u

/* Interrupt constants */
#if defined(DUCK_SERVO__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DUCK_SERVO_SetInterruptMode() function.
     *  @{
     */
        #define DUCK_SERVO_INTR_NONE      (uint16)(0x0000u)
        #define DUCK_SERVO_INTR_RISING    (uint16)(0x0001u)
        #define DUCK_SERVO_INTR_FALLING   (uint16)(0x0002u)
        #define DUCK_SERVO_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DUCK_SERVO_INTR_MASK      (0x01u) 
#endif /* (DUCK_SERVO__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DUCK_SERVO_PS                     (* (reg8 *) DUCK_SERVO__PS)
/* Data Register */
#define DUCK_SERVO_DR                     (* (reg8 *) DUCK_SERVO__DR)
/* Port Number */
#define DUCK_SERVO_PRT_NUM                (* (reg8 *) DUCK_SERVO__PRT) 
/* Connect to Analog Globals */                                                  
#define DUCK_SERVO_AG                     (* (reg8 *) DUCK_SERVO__AG)                       
/* Analog MUX bux enable */
#define DUCK_SERVO_AMUX                   (* (reg8 *) DUCK_SERVO__AMUX) 
/* Bidirectional Enable */                                                        
#define DUCK_SERVO_BIE                    (* (reg8 *) DUCK_SERVO__BIE)
/* Bit-mask for Aliased Register Access */
#define DUCK_SERVO_BIT_MASK               (* (reg8 *) DUCK_SERVO__BIT_MASK)
/* Bypass Enable */
#define DUCK_SERVO_BYP                    (* (reg8 *) DUCK_SERVO__BYP)
/* Port wide control signals */                                                   
#define DUCK_SERVO_CTL                    (* (reg8 *) DUCK_SERVO__CTL)
/* Drive Modes */
#define DUCK_SERVO_DM0                    (* (reg8 *) DUCK_SERVO__DM0) 
#define DUCK_SERVO_DM1                    (* (reg8 *) DUCK_SERVO__DM1)
#define DUCK_SERVO_DM2                    (* (reg8 *) DUCK_SERVO__DM2) 
/* Input Buffer Disable Override */
#define DUCK_SERVO_INP_DIS                (* (reg8 *) DUCK_SERVO__INP_DIS)
/* LCD Common or Segment Drive */
#define DUCK_SERVO_LCD_COM_SEG            (* (reg8 *) DUCK_SERVO__LCD_COM_SEG)
/* Enable Segment LCD */
#define DUCK_SERVO_LCD_EN                 (* (reg8 *) DUCK_SERVO__LCD_EN)
/* Slew Rate Control */
#define DUCK_SERVO_SLW                    (* (reg8 *) DUCK_SERVO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DUCK_SERVO_PRTDSI__CAPS_SEL       (* (reg8 *) DUCK_SERVO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DUCK_SERVO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DUCK_SERVO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DUCK_SERVO_PRTDSI__OE_SEL0        (* (reg8 *) DUCK_SERVO__PRTDSI__OE_SEL0) 
#define DUCK_SERVO_PRTDSI__OE_SEL1        (* (reg8 *) DUCK_SERVO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DUCK_SERVO_PRTDSI__OUT_SEL0       (* (reg8 *) DUCK_SERVO__PRTDSI__OUT_SEL0) 
#define DUCK_SERVO_PRTDSI__OUT_SEL1       (* (reg8 *) DUCK_SERVO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DUCK_SERVO_PRTDSI__SYNC_OUT       (* (reg8 *) DUCK_SERVO__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DUCK_SERVO__SIO_CFG)
    #define DUCK_SERVO_SIO_HYST_EN        (* (reg8 *) DUCK_SERVO__SIO_HYST_EN)
    #define DUCK_SERVO_SIO_REG_HIFREQ     (* (reg8 *) DUCK_SERVO__SIO_REG_HIFREQ)
    #define DUCK_SERVO_SIO_CFG            (* (reg8 *) DUCK_SERVO__SIO_CFG)
    #define DUCK_SERVO_SIO_DIFF           (* (reg8 *) DUCK_SERVO__SIO_DIFF)
#endif /* (DUCK_SERVO__SIO_CFG) */

/* Interrupt Registers */
#if defined(DUCK_SERVO__INTSTAT)
    #define DUCK_SERVO_INTSTAT            (* (reg8 *) DUCK_SERVO__INTSTAT)
    #define DUCK_SERVO_SNAP               (* (reg8 *) DUCK_SERVO__SNAP)
    
	#define DUCK_SERVO_0_INTTYPE_REG 		(* (reg8 *) DUCK_SERVO__0__INTTYPE)
#endif /* (DUCK_SERVO__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DUCK_SERVO_H */


/* [] END OF FILE */
