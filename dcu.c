
#include <stdio.h>
#include "bms.h"
#include <stdlib.h>
#include "IO_Driver.h"
#include "IO_RTC.h"
#include "serial.h"
#include "mathFunctions.h"


struct _DashControlUnit {

    ubyte2 canMessageBaseId;


};

DashControlUnit* BMS_new(SerialManager* serialMan, ubyte2 canMessageBaseID) {

	DashControlUnit* me = (DashControlUnit*)malloc(sizeof(struct _DashControlUnit));

    me->canMessageBaseId = canMessageBaseID;
    
    return me;

}
