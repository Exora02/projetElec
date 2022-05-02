/*******************************************************************************
* File Name: JUMP_SERVO.h  
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

#if !defined(CY_PINS_JUMP_SERVO_H) /* Pins JUMP_SERVO_H */
#define CY_PINS_JUMP_SERVO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "JUMP_SERVO_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 JUMP_SERVO__PORT == 15 && ((JUMP_SERVO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    JUMP_SERVO_Write(uint8 value);
void    JUMP_SERVO_SetDriveMode(uint8 mode);
uint8   JUMP_SERVO_ReadDataReg(void);
uint8   JUMP_SERVO_Read(void);
void    JUMP_SERVO_SetInterruptMode(uint16 position, uint16 mode);
uint8   JUMP_SERVO_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the JUMP_SERVO_SetDriveMode() function.
     *  @{
     */
        #define JUMP_SERVO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define JUMP_SERVO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define JUMP_SERVO_DM_RES_UP          PIN_DM_RES_UP
        #define JUMP_SERVO_DM_RES_DWN         PIN_DM_RES_DWN
        #define JUMP_SERVO_DM_OD_LO           PIN_DM_OD_LO
        #define JUMP_SERVO_DM_OD_HI           PIN_DM_OD_HI
        #define JUMP_SERVO_DM_STRONG          PIN_DM_STRONG
        #define JUMP_SERVO_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define JUMP_SERVO_MASK               JUMP_SERVO__MASK
#define JUMP_SERVO_SHIFT              JUMP_SERVO__SHIFT
#define JUMP_SERVO_WIDTH              1u

/* Interrupt constants */
#if defined(JUMP_SERVO__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in JUMP_SERVO_SetInterruptMode() function.
     *  @{
     */
        #define JUMP_SERVO_INTR_NONE      (uint16)(0x0000u)
        #define JUMP_SERVO_INTR_RISING    (uint16)(0x0001u)
        #define JUMP_SERVO_INTR_FALLING   (uint16)(0x0002u)
        #define JUMP_SERVO_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define JUMP_SERVO_INTR_MASK      (0x01u) 
#endif /* (JUMP_SERVO__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define JUMP_SERVO_PS                     (* (reg8 *) JUMP_SERVO__PS)
/* Data Register */
#define JUMP_SERVO_DR                     (* (reg8 *) JUMP_SERVO__DR)
/* Port Number */
#define JUMP_SERVO_PRT_NUM                (* (reg8 *) JUMP_SERVO__PRT) 
/* Connect to Analog Globals */                                                  
#define JUMP_SERVO_AG                     (* (reg8 *) JUMP_SERVO__AG)                       
/* Analog MUX bux enable */
#define JUMP_SERVO_AMUX                   (* (reg8 *) JUMP_SERVO__AMUX) 
/* Bidirectional Enable */                                                        
#define JUMP_SERVO_BIE                    (* (reg8 *) JUMP_SERVO__BIE)
/* Bit-mask for Aliased Register Access */
#define JUMP_SERVO_BIT_MASK               (* (reg8 *) JUMP_SERVO__BIT_MASK)
/* Bypass Enable */
#define JUMP_SERVO_BYP                    (* (reg8 *) JUMP_SERVO__BYP)
/* Port wide control signals */                                                   
#define JUMP_SERVO_CTL                    (* (reg8 *) JUMP_SERVO__CTL)
/* Drive Modes */
#define JUMP_SERVO_DM0                    (* (reg8 *) JUMP_SERVO__DM0) 
#define JUMP_SERVO_DM1                    (* (reg8 *) JUMP_SERVO__DM1)
#define JUMP_SERVO_DM2                    (* (reg8 *) JUMP_SERVO__DM2) 
/* Input Buffer Disable Override */
#define JUMP_SERVO_INP_DIS                (* (reg8 *) JUMP_SERVO__INP_DIS)
/* LCD Common or Segment Drive */
#define JUMP_SERVO_LCD_COM_SEG            (* (reg8 *) JUMP_SERVO__LCD_COM_SEG)
/* Enable Segment LCD */
#define JUMP_SERVO_LCD_EN                 (* (reg8 *) JUMP_SERVO__LCD_EN)
/* Slew Rate Control */
#define JUMP_SERVO_SLW                    (* (reg8 *) JUMP_SERVO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define JUMP_SERVO_PRTDSI__CAPS_SEL       (* (reg8 *) JUMP_SERVO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define JUMP_SERVO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) JUMP_SERVO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define JUMP_SERVO_PRTDSI__OE_SEL0        (* (reg8 *) JUMP_SERVO__PRTDSI__OE_SEL0) 
#define JUMP_SERVO_PRTDSI__OE_SEL1        (* (reg8 *) JUMP_SERVO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define JUMP_SERVO_PRTDSI__OUT_SEL0       (* (reg8 *) JUMP_SERVO__PRTDSI__OUT_SEL0) 
#define JUMP_SERVO_PRTDSI__OUT_SEL1       (* (reg8 *) JUMP_SERVO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define JUMP_SERVO_PRTDSI__SYNC_OUT       (* (reg8 *) JUMP_SERVO__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(JUMP_SERVO__SIO_CFG)
    #define JUMP_SERVO_SIO_HYST_EN        (* (reg8 *) JUMP_SERVO__SIO_HYST_EN)
    #define JUMP_SERVO_SIO_REG_HIFREQ     (* (reg8 *) JUMP_SERVO__SIO_REG_HIFREQ)
    #define JUMP_SERVO_SIO_CFG            (* (reg8 *) JUMP_SERVO__SIO_CFG)
    #define JUMP_SERVO_SIO_DIFF           (* (reg8 *) JUMP_SERVO__SIO_DIFF)
#endif /* (JUMP_SERVO__SIO_CFG) */

/* Interrupt Registers */
#if defined(JUMP_SERVO__INTSTAT)
    #define JUMP_SERVO_INTSTAT            (* (reg8 *) JUMP_SERVO__INTSTAT)
    #define JUMP_SERVO_SNAP               (* (reg8 *) JUMP_SERVO__SNAP)
    
	#define JUMP_SERVO_0_INTTYPE_REG 		(* (reg8 *) JUMP_SERVO__0__INTTYPE)
#endif /* (JUMP_SERVO__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_JUMP_SERVO_H */


/* [] END OF FILE */
