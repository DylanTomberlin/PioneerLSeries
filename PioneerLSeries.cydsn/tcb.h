/* ========================================
TCB.h
Dylan Tomberlin
Husky Robotics Team 2017-2018
This file contains the struct for a task control block for the robotics arm motor board
* ========================================
*/
#ifndef TCB
#define TCB
    
typedef struct tcbStruct        //needed extra name in order to create self reference struct (line 15)
{
    void(*currTask)(void *currDataPtr);
    void *dataPtr;
    struct tcbStruct *nextTCBPtr;
    int index;
}tcb;        
    
#endif
