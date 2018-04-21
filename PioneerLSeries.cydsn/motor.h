/* ========================================
 * motor.h
 * Dylan Tomberlin
 * Husky Robotics Team, 2017-2018
 * This file contains the motor struct, which 
 * organizes all information related to a single motor unit
 *
 *  THIS FILE IS OBSOLETE!!!
 * ========================================
*/

#ifndef MOTOR
#define MOTOR
    
typedef struct{
    int motorID;
    int posRaw;
    float currPos;
    void (*readPotFunctPtr)(void);
    void (*readEncodFunctPtr)(void);
    void (*writePWMFunctPtr)(void);
    //limit switch 
    
}motor;
    
#endif