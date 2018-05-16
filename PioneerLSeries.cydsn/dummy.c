/* ========================================
 *This file is full of dummy tasks for the sake of testing and debugging the scheduler
*/
#include <top.h>
void debugPrintCount(void);


void dummyTask1(void *dataPtr)
{
   debugPrintCount();
   dummyData *myDummyData = (dummyData*) dataPtr;
   myDummyData->number = 1;
   LCD_PrintString(myDummyData->myChar);
   //addFlags[2] = 1;
}

void dummyTask2(void *dataPtr)
{
   dummyData *myDummyData = (dummyData*) dataPtr;
   myDummyData->number = 2;
   LCD_PrintString(myDummyData->myChar);
   //addFlags[3] = 1;
}

void dummyTask3(void *dataPtr)
{
   dummyData *myDummyData = (dummyData*) dataPtr;
   myDummyData->number = 3;
   LCD_PrintString(myDummyData->myChar);
   //addFlags[4] = 1;
}
void debugPrintCount(void)
{
    LCD_Position(1, 0);
    LCD_PrintNumber(debugCount);
    debugCount++;
    LCD_Position(0, 0);
}