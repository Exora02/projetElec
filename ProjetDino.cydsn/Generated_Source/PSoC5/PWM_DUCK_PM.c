/*******************************************************************************
* File Name: PWM_DUCK_PM.c
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

#include "PWM_DUCK.h"

static PWM_DUCK_backupStruct PWM_DUCK_backup;


/*******************************************************************************
* Function Name: PWM_DUCK_SaveConfig
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
*  PWM_DUCK_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_DUCK_SaveConfig(void) 
{

    #if(!PWM_DUCK_UsingFixedFunction)
        #if(!PWM_DUCK_PWMModeIsCenterAligned)
            PWM_DUCK_backup.PWMPeriod = PWM_DUCK_ReadPeriod();
        #endif /* (!PWM_DUCK_PWMModeIsCenterAligned) */
        PWM_DUCK_backup.PWMUdb = PWM_DUCK_ReadCounter();
        #if (PWM_DUCK_UseStatus)
            PWM_DUCK_backup.InterruptMaskValue = PWM_DUCK_STATUS_MASK;
        #endif /* (PWM_DUCK_UseStatus) */

        #if(PWM_DUCK_DeadBandMode == PWM_DUCK__B_PWM__DBM_256_CLOCKS || \
            PWM_DUCK_DeadBandMode == PWM_DUCK__B_PWM__DBM_2_4_CLOCKS)
            PWM_DUCK_backup.PWMdeadBandValue = PWM_DUCK_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_DUCK_KillModeMinTime)
             PWM_DUCK_backup.PWMKillCounterPeriod = PWM_DUCK_ReadKillTime();
        #endif /* (PWM_DUCK_KillModeMinTime) */

        #if(PWM_DUCK_UseControl)
            PWM_DUCK_backup.PWMControlRegister = PWM_DUCK_ReadControlRegister();
        #endif /* (PWM_DUCK_UseControl) */
    #endif  /* (!PWM_DUCK_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_DUCK_RestoreConfig
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
*  PWM_DUCK_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_DUCK_RestoreConfig(void) 
{
        #if(!PWM_DUCK_UsingFixedFunction)
            #if(!PWM_DUCK_PWMModeIsCenterAligned)
                PWM_DUCK_WritePeriod(PWM_DUCK_backup.PWMPeriod);
            #endif /* (!PWM_DUCK_PWMModeIsCenterAligned) */

            PWM_DUCK_WriteCounter(PWM_DUCK_backup.PWMUdb);

            #if (PWM_DUCK_UseStatus)
                PWM_DUCK_STATUS_MASK = PWM_DUCK_backup.InterruptMaskValue;
            #endif /* (PWM_DUCK_UseStatus) */

            #if(PWM_DUCK_DeadBandMode == PWM_DUCK__B_PWM__DBM_256_CLOCKS || \
                PWM_DUCK_DeadBandMode == PWM_DUCK__B_PWM__DBM_2_4_CLOCKS)
                PWM_DUCK_WriteDeadTime(PWM_DUCK_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_DUCK_KillModeMinTime)
                PWM_DUCK_WriteKillTime(PWM_DUCK_backup.PWMKillCounterPeriod);
            #endif /* (PWM_DUCK_KillModeMinTime) */

            #if(PWM_DUCK_UseControl)
                PWM_DUCK_WriteControlRegister(PWM_DUCK_backup.PWMControlRegister);
            #endif /* (PWM_DUCK_UseControl) */
        #endif  /* (!PWM_DUCK_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_DUCK_Sleep
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
*  PWM_DUCK_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_DUCK_Sleep(void) 
{
    #if(PWM_DUCK_UseControl)
        if(PWM_DUCK_CTRL_ENABLE == (PWM_DUCK_CONTROL & PWM_DUCK_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_DUCK_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_DUCK_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_DUCK_UseControl) */

    /* Stop component */
    PWM_DUCK_Stop();

    /* Save registers configuration */
    PWM_DUCK_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_DUCK_Wakeup
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
*  PWM_DUCK_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_DUCK_Wakeup(void) 
{
     /* Restore registers values */
    PWM_DUCK_RestoreConfig();

    if(PWM_DUCK_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_DUCK_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
