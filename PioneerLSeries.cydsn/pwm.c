/* ========================================
 * pwm.c
 * Blake Rose
 * Husky Robotics Team, 2017-2018
 * This file contains functions pertaining to PWM
 * ========================================
*/

int SPEED_RES = 255; // input speed resolution
int CLK_FREQ = 12000000; // input clock frequency to PWM block
int PWM_FREQ = 333; // Must be 333 Hz for Talon, use same frequency for Cytron
int PWM_PERIOD = 36036; // PWM PERIOD should be CLK_FREQ / PWM_Freq

#include "top.h"

// writes the given compare values to each of the PWM blocks
// the compare values will have to be computed from another function
void writePWMs(void *dataPtr)
{
    pwmData *pwmDataPtr = (pwmData*) dataPtr;
    // Put this in a loop if possible
    // may throw an error if less than 3 motors
    PWM0_WriteCompare(pwmDataPtr->pwmData[0]);
    PWM1_WriteCompare(pwmDataPtr->pwmData[1]);
    PWM2_WriteCompare(pwmDataPtr->pwmData[2]);
}

// a start at a function that takes a pointer of input pwm data and the type of each motor
// and calculates and writes the pwm compare values needed for each motor
// Assumes the input pwm data is from 0 to SPEED_RES, with zero being full reverse, 
// SPEED_RES/2 being stopped, and SPEED_RES being full forward
void pwmCalc(void *dataPtr, void* typePtr) 
{
    pwmData *pwmDataPtr = (pwmData*) dataPtr;
    motorData *motorDataPtr = (motorData*) typePtr;
    
    int pwmComp[NUM_MOTORS]; // an array of the calculated pwm compare values
    
    int i = 0;
    for(i = 0; i < NUM_MOTORS; i++)
    {
        if (motorDataPtr->my_Types[i]==1) // if a Cytron
        {
            pwmComp[i] = (pwmDataPtr->pwmData[i])* PWM_PERIOD / SPEED_RES;  
        } else // if a Talon
        {
            // this math should output a compare value between 1/3 and 2/3 of PWM_PERIOD
            // as this is the input PWM period requirement of the talons
            int delta = (pwmDataPtr->pwmData[i])-SPEED_RES/2;
            pwmComp[i] = PWM_PERIOD/2 + delta*PWM_PERIOD/(3*SPEED_RES); 
        }    
    }
    // Function currently writes the calculated compare values
    // May want to change this function to output the compare values
    // to be passed to writePWMs
    PWM0_WriteCompare(pwmComp[0]);
    PWM1_WriteCompare(pwmComp[1]);
    PWM2_WriteCompare(pwmComp[2]);
}

/* [] END OF FILE */
