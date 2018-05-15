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
void initEncoders(void);
void initPWMs(void);

//external function prototypes
//void addTask(tcb *newTask);
//void executeTask(tcb *tcbPtr);
void readPot(void* currDataPtr);
void display(void *dataPointer);

//void initMotor(motor *currMotorPtr, int motorID);
//void readPot();

//declare motor variables from motor.h
motor motor0;

//data structs
potData myPotData;
displayData myDisplayData;


//declare global variables

//tcb structs
tcb potTCB;
tcb displayTCB;

char addFlags[NUM_FLAGS];
char removeFlags[NUM_FLAGS];
tcb *taskArray[NUM_FLAGS] = {&potTCB, &displayTCB};

tcb *firstTCBPtr = 0;
tcb *lastTCBPtr = 0;

/*
CY_ISR(isrLim0)
{
    LCD_Position(0,0);
    LCD_PrintString("Pot interrupt");
    addTask(&potTCB);
}

CY_ISR(isrLim1)
{
    LCD_Position(0, 0);
    LCD_PrintString("Display interrupt");
    addTask(&displayTCB);   
}
*/

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    initialize();
    
    int count = 0; //For testing/ call simulation purposes.
    addTask(&displayTCB);
    for(;;)
    {
        tcb *myFirstTCBPtr = firstTCBPtr;
        addTask(&displayTCB);
        myFirstTCBPtr = firstTCBPtr;
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
        //if(NULL != firstTCBPtr)
          //  executeTask(firstTCBPtr);
        //addTask(&displayTCB);    
        executeTask(firstTCBPtr);
        myFirstTCBPtr = firstTCBPtr;
        LCD_PrintString("Hi");
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
    addTask(&potTCB);
    initEncoders();
    initPWMs();
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
    LCD_PrintString("TCB Init");
    potTCB.currTask = readPot;
    potTCB.dataPtr  = &myPotData;
    displayTCB.currTask = display;
    displayTCB.dataPtr = &myDisplayData;
}

// This may start an unnecessary number of decoders if less than 3 are used
void initEncoders(void)
{
    QuadDec0_Start();
    QuadDec1_Start();
    QuadDec2_Start();
}

// This may start the pwm signals at start which may make the motors run at startup, fix
void initPWMs(void)
{
    PWM0_Start();
    PWM1_Start();
    PWM2_Start();
}