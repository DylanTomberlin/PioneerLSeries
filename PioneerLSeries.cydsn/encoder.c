/* ========================================
 * encoder.c
 * Blake Rose
 * Husky Robotics Team, 2017-2018
 * This file contains functions pertaining to encoders
 * ========================================
*/

#include "top.h"

// Reads all 3 of the encoders
void readEncoders(void *dataPtr) {
    encData *encDataPtr = (encData*) dataPtr;
    // Put this into a loop if possible
    // May throw an error if NUM_MOTORS < 3
    encDataPtr->encRaw[0] = QuadDec0_ReadCounter();
    encDataPtr->encRaw[1] = QuadDec1_ReadCounter();
    encDataPtr->encRaw[2] = QuadDec2_ReadCounter();
}
/* [] END OF FILE */
