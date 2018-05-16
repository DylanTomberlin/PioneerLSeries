/* ========================================
 * Dylan Tomberlin
 * Husky Robotics Team 2017-2018
 * This file contains all of the global constants for the PioneerLSeries project
 * It is a seperate file so that just it can be included in other .h files
 * ========================================
*/
#ifndef CONSTANTS
#define CONSTANTS
    
    #define NUM_MOTORS 3  //Number of motors in the project
    #define NUM_TASKS 3 //must == number of elements in taskArray in main global space
    
    //Can related constants
    #define CAN_RX_MAILBOX_0_SHIFT      (1u)
    #define CAN_RX_MAILBOX_1_SHIFT      (2u)
    #define CAN_RX_MAILBOX_2_SHIFT      (4u)
    
    #define SEND_POS_ID (0x1AAu)
#endif