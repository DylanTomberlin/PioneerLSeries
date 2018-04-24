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
    if(0 != lastTCBPtr)
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

void groundTask(tcb *taskPtr)
{
       
}

tcb* findPreviousTask(tcb *targetTaskPtr)//not the cleanest code ever, work in progress
{
    if(NULL == targetTaskPtr)
        return NULL;
    else if(NULL == firstTCBPtr)
        return NULL;
    else {
        tcb *currentTaskPtr = firstTCBPtr;
        while(currentTaskPtr.nextTask
    }
}