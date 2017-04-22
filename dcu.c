
#include <stdio.h>
#include <stdlib.h>

#include "IO_Driver.h"
#include "IO_CAN.h"

#include "dcu.h"

struct _DashControlUnit
{

    ubyte2 canMessageBaseId;

	//These values should be made accessible to the public.
	//Pick a style of accessor function(s) to write, e.g.
	//DCU_getRegenTorqueLimitDNm() //one accessor function per variable
	//or DCU_getUbyte2(enum valueName) //One accessor function per datatype, plus enums in the header

	//They will come in from the DCU via CAN, but they may be formatted differently.
	//The data DCU_parseCanMessage() will contain these values.
	sbyte2	torqueMaximumDNm;
	ubyte2	regen_torqueLimitDNm;
	ubyte2	regen_torqueAtZeroPedalDNm;
	float4	regen_percentAPPSForCoasting;	
	float4	regen_percentBPSForMaxRegen;
	ubyte2	regen_minimumSpeedKPH;
	ubyte2	regen_speedRampStart;
	sbyte1	cooling_airTempOverride;
	//...more variables TBD


};

DashControlUnit* DCU_new(ubyte2 canMessageBaseID)
{

	DashControlUnit* me = (DashControlUnit*)malloc(sizeof(struct _DashControlUnit));

    me->canMessageBaseId = canMessageBaseID;
    
    return me;

}

void DCU_parseCanMessage(DashControlUnit* me, IO_CAN_DATA_FRAME* canMessage)
{

	switch (canMessage->id)
	{
	case 0x800:
		break;
	}
}
