/*******************************************************************************
* File Name: PWM_JUMP_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_JUMP.h"

static PWM_JUMP_backupStruct PWM_JUMP_backup;


/*******************************************************************************
* Function Name: PWM_JUMP_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_JUMP_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_JUMP_SaveConfig(void) 
{

    #if(!PWM_JUMP_UsingFixedFunction)
        #if(!PWM_JUMP_PWMModeIsCenterAligned)
            PWM_JUMP_backup.PWMPeriod = PWM_JUMP_ReadPeriod();
        #endif /* (!PWM_JUMP_PWMModeIsCenterAligned) */
        PWM_JUMP_backup.PWMUdb = PWM_JUMP_ReadCounter();
        #if (PWM_JUMP_UseStatus)
            PWM_JUMP_backup.InterruptMaskValue = PWM_JUMP_STATUS_MASK;
        #endif /* (PWM_JUMP_UseStatus) */

        #if(PWM_JUMP_DeadBandMode == PWM_JUMP__B_PWM__DBM_256_CLOCKS || \
            PWM_JUMP_DeadBandMode == PWM_JUMP__B_PWM__DBM_2_4_CLOCKS)
            PWM_JUMP_backup.PWMdeadBandValue = PWM_JUMP_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_JUMP_KillModeMinTime)
             PWM_JUMP_backup.PWMKillCounterPeriod = PWM_JUMP_ReadKillTime();
        #endif /* (PWM_JUMP_KillModeMinTime) */

        #if(PWM_JUMP_UseControl)
            PWM_JUMP_backup.PWMControlRegister = PWM_JUMP_ReadControlRegister();
        #endif /* (PWM_JUMP_UseControl) */
    #endif  /* (!PWM_JUMP_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_JUMP_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_JUMP_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_JUMP_RestoreConfig(void) 
{
        #if(!PWM_JUMP_UsingFixedFunction)
            #if(!PWM_JUMP_PWMModeIsCenterAligned)
                PWM_JUMP_WritePeriod(PWM_JUMP_backup.PWMPeriod);
            #endif /* (!PWM_JUMP_PWMModeIsCenterAligned) */

            PWM_JUMP_WriteCounter(PWM_JUMP_backup.PWMUdb);

            #if (PWM_JUMP_UseStatus)
                PWM_JUMP_STATUS_MASK = PWM_JUMP_backup.InterruptMaskValue;
            #endif /* (PWM_JUMP_UseStatus) */

            #if(PWM_JUMP_DeadBandMode == PWM_JUMP__B_PWM__DBM_256_CLOCKS || \
                PWM_JUMP_DeadBandMode == PWM_JUMP__B_PWM__DBM_2_4_CLOCKS)
                PWM_JUMP_WriteDeadTime(PWM_JUMP_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_JUMP_KillModeMinTime)
                PWM_JUMP_WriteKillTime(PWM_JUMP_backup.PWMKillCounterPeriod);
            #endif /* (PWM_JUMP_KillModeMinTime) */

            #if(PWM_JUMP_UseControl)
                PWM_JUMP_WriteControlRegister(PWM_JUMP_backup.PWMControlRegister);
            #endif /* (PWM_JUMP_UseControl) */
        #endif  /* (!PWM_JUMP_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_JUMP_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_JUMP_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_JUMP_Sleep(void) 
{
    #if(PWM_JUMP_UseControl)
        if(PWM_JUMP_CTRL_ENABLE == (PWM_JUMP_CONTROL & PWM_JUMP_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_JUMP_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_JUMP_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_JUMP_UseControl) */

    /* Stop component */
    PWM_JUMP_Stop();

    /* Save registers configuration */
    PWM_JUMP_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_JUMP_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_JUMP_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_JUMP_Wakeup(void) 
{
     /* Restore registers values */
    PWM_JUMP_RestoreConfig();

    if(PWM_JUMP_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_JUMP_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
