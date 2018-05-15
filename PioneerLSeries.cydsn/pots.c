/* ========================================
 * pots.c
 * Dylan Tomberlin
 * Husky Robotics Team, 2017-2018
 * This file contains functions pertaining to the potentiometers
 * ========================================
*/
#include "top.h"

#define VOLT_OVER_POT 5  //Total voltage applied over potentiometer poles
#define POT_OFFSET 0     //Tuning factor
#define NORMALIZE  32768 //=2^15, Normalize the raw input data to a scale of 0 to 1

//void readPot(motor *currMotorPtr){
//    int raw = ADC_GetResult16(currMotorPtr->motorID);
//    currMotorPtr->posRaw = raw;
//    //currMotorPtr->currPos = ((float) (raw - POT_OFFSET)) / NORMALIZE;
//}

void readPot(void *currDataPtr){
    //Cast generic Data struct pointer to potData struct pointer
    potData *potDataPtr = (potData*) currDataPtr;
    
    int i = 0;
    for(i = 0; i < NUM_MOTORS; i++)
    {
        //potDataPtr->potRaw[i] = ADC_GetResult16(i);   
        potDataPtr->potRaw[i] = i;//Debug
    }
}