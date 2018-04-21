/* ========================================
 * display.c
 * Dylan Tomberlin
 * Husky Robotics Team 2017-2018
 * This file contains functions related to displaying to a character LCD for the purposes of debugging a PSoC L Board
 * Part of the Arm Motor Board project
 * ========================================
*/
#include "top.h"


void display(void *dataPointer)
{
    displayData *displayDataPtr = (displayData*) dataPointer; //cast from generic data struct pointer to displayData struct pointer
    LCD_Position(0, 0);
    LCD_PrintDecUint16(*(displayDataPtr->potRawPtr));
}
