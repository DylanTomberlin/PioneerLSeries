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
#include "top.h"

//local function prototypes
void initialize(void);
void initDataStructs(void);
void initTCBs(void);
void initMotor(motor *currMotorPtr, int motorID);

//external function prototypes
void addTask(tcb *newTask);
void executeTask(tcb *tcbPtr);
void readPot(void* currDataPtr);
void display(void *dataPointer);

//void initMotor(motor *currMotorPtr, int motorID);
//void readPot();

//declare motor variables from motor.h
motor motor0;

//declare global variables
tcb *firstTCBPtr = 0;
tcb *lastTCBPtr = 0;

//data structs
potData myPotData;
displayData myDisplayData;

//tcb structs
tcb potTCB;
tcb displayTCB;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    initialize();
    
    int count = 0; //For testing/ call simulation purposes.
    
    for(;;)
    {
//        if(0 == count % 6)
//            addtask((void*) &pottcb);
//        if(0 == count % 17)
//            addtask((void*) &displaytcb);
        //readPot(&motor0);
        //CyDelay(500);
        //LCD_Position(1, 0);
        //LCD_PrintString("Reading: ");
        //readPot(&motor0);
        //LCD_PrintDecUint16(motor0.posRaw);
        //CyDelay(500);
        //addTask(&
        if(NULL != firstTCBPtr)
            executeTask(firstTCBPtr);
            
    }
}



void initialize()
{
    LCD_Start();
    ADC_Start();
    initMotor(&motor0, 0);
    //LCD_PrintString("Hello World");
    initDataStructs();
    initTCBs();
}

void initMotor(motor *currMotorPtr, int motorID)
{
    currMotorPtr->motorID = motorID;
    //readPot(currMotorPtr);
}

void initDataStructs(void)
{
    int i = 0;
    for(i = 0; i < NUM_MOTORS; i++)
    {
        myDisplayData.potRawPtr[i] = &(myPotData.potRaw[i]);
    }
}

void initTCBs(void)
{
    potTCB.currTask = readPot;
    displayTCB.currTask = &display;
}