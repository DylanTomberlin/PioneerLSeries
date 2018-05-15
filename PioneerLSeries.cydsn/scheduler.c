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
extern char removeFlags[];
extern tcb *taskArray[];



//fuction prototypes
void executeTask(tcb *tcbPtr);
void addTask(tcb *newTask);
void removeTask(tcb *task);
char isInQueue(tcb *targetTCBPtr);

void scheduler(void)
{
    int i = 0;
    for(i = 0; i < NUM_TASKS; i++)
    {
        //if both add and remove flags are true, task is moved to end of task queue
        if(removeFlags[i])
        {
            removeTask(taskArray[i]);
            removeFlags[i] = 0;
        }
        
        if(addFlags[i])
        {
            addTask(taskArray[i]);
            addFlags[i] = 0;
        }        
    }
    executeTask(firstTCBPtr);
    
}

void executeTask(tcb *tcbPtr)
{
    if(NULL == tcbPtr ) return;
    
    tcbPtr->currTask((void*) tcbPtr->dataPtr);
    removeFlags[tcbPtr->index] = 1;
    /*
    //moves linked list pointer forward unless there is nothing left, at which point it grounds the first element pointer
    if(NULL == tcbPtr->nextTCBPtr)
        firstTCBPtr = NULL;
    else
        firstTCBPtr = (tcbPtr->nextTCBPtr); //probably need some malloc and free so that a bunch of tasks don't take up all the memory.
    //groundTask(tcbPtr);
    */
    
}

void addTask(tcb *newTask)
{
    if(NULL == firstTCBPtr)//NULL first task implies no task is in queue
    {
        firstTCBPtr = newTask;
        lastTCBPtr  = newTask;
        
        firstTCBPtr->nextTCBPtr = NULL;
        
        //lastTCBPtr->nextTCBPtr = newTask;  //add new task to the end of the linked list
        //lastTCBPtr = newTask;           //move forward the last item pointer to newTask
        //lastTCBPtr->nextTCBPtr = 0;        //ground pointer of new last list item
    } else if(!isInQueue(newTask)) //leaves task alone if already in queue (i.e. doesn't move it to the back)
    {
        lastTCBPtr->nextTCBPtr = newTask;
        lastTCBPtr = newTask;
        lastTCBPtr->nextTCBPtr = NULL;
        //firstTCBPtr = newTask;
        //lastTCBPtr = newTask;           //Check this else statement... Is it possible for lastTCBPtr == 0 but firstTCBPtr != 0??
    }
    addFlags[newTask->index] = 0;   //reset add flag
}

//This function removes a task from the queue, no matter what postion it is in.
void removeTask(tcb *currTaskPtr)
{
    if(NULL == currTaskPtr) return; //no task Ptr passed
    
    tcb *previousTask = findPreviousTask(currTaskPtr);
    if(NULL != previousTask)        //target is not at front 
    {
        previousTask->nextTCBPtr = currTaskPtr->nextTCBPtr;      
    } else
    {
        firstTCBPtr = currTaskPtr->nextTCBPtr;
    }
    currTaskPtr->nextTCBPtr = NULL;
    
    removeFlags[currTaskPtr->index] = 0; //reset remove flag
}

/*
void groundTask(tcb *taskPtr)
{
    tcb *previousTask = findPreviousTask(taskPtr);
    if(NULL != previousTask)
        previousTask->nextTCBPtr = NULL;
    taskPtr->nextTCBPtr = NULL;
}
*/

tcb* findPreviousTask(tcb *targetTaskPtr)//not the cleanest code ever, work in progress
{
    //Targets which do not have previous tasks
    if(NULL == targetTaskPtr)
        return NULL;
    else if(NULL == firstTCBPtr)
        return NULL;
    else if(targetTaskPtr == firstTCBPtr)
        return NULL;
    
    //Target is second task
    if(firstTCBPtr->nextTCBPtr == targetTaskPtr)
        return firstTCBPtr;
    
    //Target is third or later task
    tcb *currentTaskPtr = firstTCBPtr;
    while(NULL != currentTaskPtr->nextTCBPtr->nextTCBPtr)
        currentTaskPtr = currentTaskPtr->nextTCBPtr;   
    return currentTaskPtr;
}

char isInQueue(tcb *targetTCBPtr)
{
    if(NULL == targetTCBPtr) return 0;//passed incorrect ptr
    
    //if(targetTCBPtr == firstTCBPtr) return 1;//passed first ptr
    
    tcb *currPtr = firstTCBPtr;
    while(NULL != currPtr->nextTCBPtr)
    {
        if(currPtr == targetTCBPtr) return 1;
        currPtr = currPtr->nextTCBPtr;
    }
    return 0;
}