/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

#define SERVO_RAISED 2400
#define SERVO_CLICKED 2850

int JUMP_COUNTER = 0;

void initDino(){
    PWM_JUMP_Start();
    PWM_DUCK_Start();
    ADC_Start();
    LCD_Start();
}

void jumpLEDtoggle(){
    LED1_Write(~LED1_Read());
    LED2_Write(~LED2_Read());
}

void duckLEDtoggle(){
    LED3_Write(~LED3_Read());
    LED4_Write(~LED4_Read());
}

void jump(){
    jumpLEDtoggle();
    PWM_JUMP_WriteCompare(SERVO_CLICKED);
    CyDelay(100);
    PWM_JUMP_WriteCompare(SERVO_RAISED);
    CyDelay(100);
    jumpLEDtoggle();
    JUMP_COUNTER++;
    
}

void duck(){
    duckLEDtoggle();
    PWM_DUCK_WriteCompare(SERVO_CLICKED);
    CyDelay(100);
    PWM_DUCK_WriteCompare(SERVO_RAISED);
    CyDelay(100);
    duckLEDtoggle();
    JUMP_COUNTER++;
}

void sw1(){
    jump();
}

void sw2(){
    duck();
}

void sw3(){
    JUMP_COUNTER = 0;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    initDino();
    
    for(;;)
    {
        if(SW1_Read()){
            sw1();
        }
        if(SW2_Read()){
            sw2();
        }
        uint16_t i = ADC_Read16();
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintNumber(i);
        if(i>=15000){
           
            jump();
        }
    }
}

/* [] END OF FILE */
