/* ========================================
 * top.h
 * Dylan Tomberlin
 * Husky Robotics Team 2017-2018
 * This file is a master preprocessor file for the PSoC L Series
 * Project
 * ========================================
*/ 

#ifndef TOP
#define TOP
    //global constants
    #include "constants.h"
    
    //global includes
    #include "project.h"
    #include "motor.h"
    #include "tcb.h"
    #include "structs.h"
   
     //global function prototypes
    tcb* findPreviousTask(tcb *targetTaskPtr);
    void groundTask(tcb *taskPtr);
    void addTask(tcb *newTask);
    void executeTask(tcb *tcbPtr);
    //cypress files:
    //#include "cytypes.h"
    
#endif
