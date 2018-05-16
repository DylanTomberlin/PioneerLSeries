/* ========================================
structs.h
Dylan Tomberlin
Husky Robotics Team 2017-2018
This file contains the data structs for the robotics arm motor board
 * ========================================
*/
#ifndef MY_STRUCTS
#define MY_STRUCTS

#include <cytypes.h>
#include "constants.h"
    
//Potentiometer data struct
typedef struct
{
    int16 potRaw[NUM_MOTORS];
} potData;

//LCD Display data for debug purposes
typedef struct
{
    int16 *potRawPtr[NUM_MOTORS];
} displayData;

// Encoder data struct
typedef struct
{
    int encRaw[NUM_MOTORS];
} encData;

// PWM data struct
typedef struct
{
    int pwmValues[NUM_MOTORS];
} pwmData;

//Dummy data struct for debugging
typedef struct
{
    int number;
    char myChar[2];
} dummyData;

//data struct for sending postion data over CAN
typedef struct
{
   int16 *pwmValues;//pointer to first element in array of raw pwmData
    
} sendCANData;


// an enum for whether a motor is a Talon or Cytron
enum motorType{Talon = 0, Cytron = 1};
// stores the type of each motor  as an int
typedef struct
{
    enum motorType my_Types[NUM_MOTORS];
} motorData;

#endif
