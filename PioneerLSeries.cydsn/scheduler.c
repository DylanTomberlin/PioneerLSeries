/* ========================================
 * scheduler.c
 * Dylan Tomberlin
 * Husky Robotics team 2017-2018
 * ========================================
 */

//#include "tcb.h"
#include "top.h"

extern tcb *firstTCBPtr;
extern tcb *lastTCBPtr;

extern char addFlags[];
extern char removeFlag[];
extern tcb *taskArray[];

//fuction prototypes
void executeTask(tcb *tcbPtr);
void addTask(tcb *newTask);
void removeTask(tcb *task);

void scheduler(void)
{
    int i = 0;
    for(i = 0; i < NUM_FLAGS; i++)
    {
        if(addFlags[i])
        {
            addTask(taskArray[i]);
            addFlags[i] = 0;
        }
        
        if(removeFlag[i])
        {
            removeTask(taskArray[i]);
            removeFlag[i] = 0;
        }
    }
    executeTask(firstTCBPtr);
}

void executeTask(tcb *tcbPtr)
{
    
    tcbPtr->currTask((void*) tcbPtr->dataPtr);
    //moves linked list pointer forward unless there is nothing left, at which point it grounds the first element pointer
    if(0 == tcbPtr->nextTCBPtr)
        firstTCBPtr = 0;
    else
        firstTCBPtr = (tcbPtr->nextTCBPtr); //probably need some malloc and free so that a bunch of tasks don't take up all the memory.
}

void addTask(tcb *newTask)
{
    if(NULL != lastTCBPtr)
    {
        lastTCBPtr->nextTCBPtr = newTask;  //add new task to the end of the linked list
        lastTCBPtr = newTask;           //move forward the last item pointer to newTask
        lastTCBPtr->nextTCBPtr = 0;        //ground pointer of new last list item
    } else
    {
        firstTCBPtr = newTask;
        lastTCBPtr = newTask;           //Check this else statement... Is it possible for lastTCBPtr == 0 but firstTCBPtr != 0??
    }
}

void removeTask(tcb *task)
{
    if(NULL != task)
    {
        
    }
}