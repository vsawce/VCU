#ifndef _DASHCONTROLUNIT_H
#define _DASHCONTROLUNIT_H

#include <stdio.h>
#include <stdint.h>

#include "serial.h"
#include "IO_CAN.h"


typedef struct _DashControlUnit DashControlUnit;

/**
* @brief DCU object constructor
*
* @return      dcu object
*/
DashControlUnit* DCU_new(ubyte2 canMessageBaseID);


/**
* @brief Stores data received from the DCU CAN message into our DCU object
*
* @param[in]   me	       Pointer to the dcu object
* @param[in]   canMessage  The message to be parsed
*/
void DCU_parseCanMessage(DashControlUnit* me, IO_CAN_DATA_FRAME* canMessage);




#endif // _DASHCONTROLUNIT_H



