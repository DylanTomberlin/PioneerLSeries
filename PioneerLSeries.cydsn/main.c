/* ========================================
 *
 * Dylan Tomberlin
 * Husky Robotics Team 2017-2018
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
void initDummy(void);

//external function prototypes
//void addTask(tcb *newTask);
//void executeTask(tcb *tcbPtr);
void scheduler(void);

void readPot(void* currDataPtr);
void display(void *dataPointer);

void dummyTask1(void *dataPtr);
void dummyTask2(void *dataPtr);
void dummyTask3(void *dataPtr);

//void initMotor(motor *currMotorPtr, int motorID);
//void readPot();

//declare motor variables from motor.h
motor motor0;

//data structs
potData myPotData;
displayData myDisplayData;
dummyData dummyData1, dummyData2, dummyData3;

//declare global variables

//tcb structs
tcb potTCB;
tcb displayTCB;
tcb dummyTCB1, dummyTCB2, dummyTCB3;

char addFlags[NUM_TASKS];
char removeFlags[NUM_TASKS];
tcb *taskArray[NUM_TASKS] = {&potTCB, &displayTCB, &dummyTCB1, &dummyTCB2, &dummyTCB3};

int debugCount;

tcb *firstTCBPtr = 0;
tcb *lastTCBPtr = 0;


CY_ISR(isrLim0)
{
    //LCD_Position(0,0);
    //LCD_PrintString("Pot interrupt");
    //addTask(&potTCB);
    addFlags[1] = 1;
}

/*
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
    
    //int count = 0; //For testing/ call simulation purposes.
    //addTask(&displayTCB);
    for(;;)
    {
        scheduler();
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
    initDummy();
    
    for(int i = 0; i < NUM_TASKS; i++)
    {
        addFlags[i]         = 1;
        removeFlags[i]      = 0;
        taskArray[i]->index = i;
    }
    debugCount = 0;
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
    //LCD_PrintString("TCB Init");
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

void initDummy(void)
{
    dummyTCB1.dataPtr = (void *) &dummyData1;
    dummyTCB2.dataPtr = (void *) &dummyData2;
    dummyTCB3.dataPtr = (void *) &dummyData3;
    
    dummyTCB1.currTask = dummyTask1;
    dummyTCB2.currTask = dummyTask2;
    dummyTCB3.currTask = dummyTask3;
    
    dummyData1.myChar[0] = 'a';
    dummyData2.myChar[0] = 'b';
    dummyData3.myChar[0] = 'c';
    
    dummyData1.myChar[1] = 0;
    dummyData2.myChar[1] = 0;
    dummyData3.myChar[1] = 0;
}