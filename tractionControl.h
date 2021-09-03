//"Include guard" - prevents this file from being #included more than once
#ifndef _TRACTIONCONTROL_H
#define _TRACTIONCONTROL_H

#include <stdlib.h>
#include "IO_CAN.h"
#include "IO_Driver.h"
#include "serial.h"
#include "motorController.h"
#include "wheelSpeeds.h"


//////////////////////////////////
//  LAUNCH OR TRACTION CONTROL  //
//////////////////////////////////

//Padding for WSS difference/torque limiting (in RPM)
#define LAUNCHCONTROL_DEFAULT_SENSITIVITY 500

void launchControl_init();

ubyte4 launchControl_getSensitivity();

ubyte1 launchControl_getAggressiveness();

void launchControl_setSensitivity(ubyte4 sens);

void launchControl_setAggressiveness(ubyte1 agr);

void launchControl_updateTorqueLimit();

#endif // _TRACTIONCONTROL_H
