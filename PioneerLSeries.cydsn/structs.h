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

// Encoder data struct
typedef struct
{
    int encRaw[NUM_MOTORS];
} encData;

// PWM data struct
typedef struct
{
    int pwmData[NUM_MOTORS];
} pwmData;

//Dummy data struct for debugging
typedef struct
{
    int number;
    char myChar[2];
} dummyData;


// an enum for whether a motor is a Talon or Cytron
enum motorType{Talon = 0, Cytron = 1};
// stores the type of each motor  as an int
typedef struct
{
    enum motorType my_Types[NUM_MOTORS];
} motorData;

#endif
