/* ========================================
 *
 * Dylan Tomberlin
 * Husky Robotics 2017-2018
 *
 * ========================================
*/
#include "top.h"
void sendPositionCAN(void *dataPtr)
{
    sendCANData *myTaskData = (sendCANData *) dataPtr;
    CAN_TX_MSG myMessage;

    //most of this setup is constant and should be only performed upon set up, needs to move elsewhere.
    myMessage.dlc = 2 * NUM_MOTORS;//data size: 2 bytes of data per motor, data must be <= 4 bytes long
    myMessage.id  = SEND_POS_ID;//need to work this out with software team
    myMessage.ide = 0u; //Standard message (not extended)
    myMessage.irq = 0u; //No transmit IRQ, whatever an IRQ is?
    myMessage.rtr = 0u; //No RTR (request data from another node bit)
    
    myMessage.msg = (CAN_DATA_BYTES_MSG *) (myTaskData->pwmValues); //cast data ptr to messageDataPtr
        
    //CAN_TX_TRANSMIT_MESSAGE
    CAN_SendMsg(&myMessage);
}