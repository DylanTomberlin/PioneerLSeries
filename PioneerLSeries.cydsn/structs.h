/* ========================================
structs.h
Dylan Tomberlin
Husky Robotics Team 2017-2018
This file contains the data structs for the robotics arm motor board
 * ========================================
*/
#ifndef MY_STRUCTS
#define MY_STRUCTS
    
#include "constants.h"
    
//Potentiometer data struct
typedef struct
{
    int potRaw[NUM_MOTORS];
} potData;

//LCD Display data for debug purposes
typedef struct
{
    int *potRawPtr[NUM_MOTORS];
} displayData;

#endif
