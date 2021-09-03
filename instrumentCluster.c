#include "instrumentCluster.h"

#include "canManager.h"


struct _InstrumentCluster
{
    SerialManager* serialMan;
    
    ubyte2 canMessageBaseId;  //Starting message ID for messages that will come in from this controller

    ubyte1 torqueMapMode;
    
};

InstrumentCluster* InstrumentCluster_new(SerialManager* sm, ubyte2 canMessageBaseID)
{
    InstrumentCluster* me = (InstrumentCluster*)malloc(sizeof(struct _InstrumentCluster));

    me->serialMan = sm;

    me->canMessageBaseId = canMessageBaseID;

    me->torqueMapMode=0;
    
    return me;
}

void IC_parseCanMessage(InstrumentCluster* me, IO_CAN_DATA_FRAME* icCanMessage)
{
    switch (icCanMessage->id)
    {
        case 0x702:
            me->torqueMapMode = icCanMessage->data[0];
            break;
        case 0x703:
            launchControl_setAggressiveness(icCanMessage->data[0]);
            break;
    }
}

ubyte1 IC_getTorqueMapMode(InstrumentCluster *me)
{
    return me->torqueMapMode;
}