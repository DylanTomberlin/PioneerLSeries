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

CY_ISR_PROTO(CAN_isr);

//external function prototypes
//void addTask(tcb *newTask);
//void executeTask(tcb *tcbPtr);
void scheduler(void);

void readPot(void* currDataPtr);
void display(void *dataPointer);
void sendPositionCAN(void *dataPtr);

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
sendCANData mySendCANData;

//declare global variables
volatile uint8 receiveMailboxNumber = 0xFFu;

//tcb structs
tcb potTCB, displayTCB, sendCANTCB;
tcb dummyTCB1, dummyTCB2, dummyTCB3;

char addFlags[NUM_TASKS];
char removeFlags[NUM_TASKS];
tcb *taskArray[NUM_TASKS] = {&potTCB, &displayTCB, &sendCANTCB};

int debugCount;

tcb *firstTCBPtr = 0;
tcb *lastTCBPtr = 0;

/*
CY_ISR(isrLim0)
{
    //LCD_Position(0,0);
    //LCD_PrintString("Pot interrupt");
    //addTask(&potTCB);
    addFlags[1] = 1;
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
    
    mySendCANData.pwmValues = myPotData.potRaw;
}

void initTCBs(void)
{
    //LCD_PrintString("TCB Init");
    potTCB.currTask     = readPot;
    potTCB.dataPtr      = &myPotData;
    
    displayTCB.currTask = display;
    displayTCB.dataPtr  = &myDisplayData;
    
    sendCANTCB.currTask = sendPositionCAN;
    sendCANTCB.dataPtr  = &mySendCANData;
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

//Interrupts (may be moved to another file soon)
CY_ISR(CAN_isr)
{
    static uint16 tmpbuf; 
    /* Clear Receive Message flag */
    CAN_INT_SR_REG = CAN_RX_MESSAGE_MASK;
    tmpbuf = CAN_BUF_SR_REG; 
    
    /* Switch status message received */
    if ((CAN_BUF_SR_REG & CAN_RX_MAILBOX_0_SHIFT) != 0u)
    {
        receiveMailboxNumber = CAN_RX_MAILBOX_ping;

        /* Acknowledges receipt of new message */
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_ping);
        //(set ping flag)
    }
    
    if ((CAN_BUF_SR_REG & CAN_RX_MAILBOX_1_SHIFT) != 0u)
    {
        receiveMailboxNumber = CAN_RX_MAILBOX_positionRX;
        
        /* Acknowledges receipt of new message */
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_positionRX);
        addFlags[1] = 1;//add flag to measure pot data
        //add flag to conver raw data to postion data
        addFlags[2] = 1; //add flag to send position data over CAN
    }
    
        if ((CAN_BUF_SR_REG & CAN_RX_MAILBOX_2_SHIFT) != 0u)
    {
        receiveMailboxNumber = CAN_RX_MAILBOX_speedRX;
        
        /* Acknowledges receipt of new message */
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_speedRX);
        //addFlags[x] = 1; add flags for motor controller set speed
    }
}