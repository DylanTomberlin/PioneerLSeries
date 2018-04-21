/* ========================================
structs.h
Dylan Tomberlin
Husky Robotics Team 2017-2018
This file contains the data structs for the robotics arm motor board
 * ========================================
*/
#ifndef MY_STRUCTS
#define MY_STRUCTS
//#include "top.h"
    
//Potentiometer data struct
typedef struct
{
    int16 potRaw[NUM_MOTORS];
    //int potRaw[NUM_MOTORS];
} potData;

//LCD Display data for debug purposes
typedef struct
{
    int16 *potRawPtr[NUM_MOTORS];
} displayData;

#endif
