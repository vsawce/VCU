#include "tractionControl.h"

#include "canManager.h"

static ubyte1 launchControlAggressiveness;
static ubyte4 launchControlSensitivity;

void launchControl_init()
{
    launchControlSensitivity = LAUNCHCONTROL_DEFAULT_SENSITIVITY;
    launchControlAggressiveness = 0;
}

ubyte4 launchControl_getSensitivity()
{
    return launchControlSensitivity;
}

ubyte1 launchControl_getAggressiveness()
{
    return launchControlAggressiveness;
}

void launchControl_setSensitivity(ubyte4 sens)
{
    //Represents the amount of padding (difference) between the F and R WSS values
    //Responsible for determining when torque limiting kicks in
    launchControlSensitivity = sens;
}

void launchControl_setAggressiveness(ubyte1 agr)
{
    //0 sensitivity = off
    //255 sensitivity (max) = aggressive torque limiting
    launchControlAggressiveness = agr;
}

void launchControl_updateTorqueLimit(MotorController* mcm_obj, WheelSpeeds *wss_obj)
{
    // FR WSS is broke rn
    //ubyte4 averageWheelSpeed_front = (ubyte4) (((WheelSpeeds_getWheelSpeedRPM(wss_obj, FL, TRUE) + 0.5)
    //                                + (WheelSpeeds_getWheelSpeedRPM(wss_obj, FR, TRUE) + 0.5)) / 2);
    
    // Since FR WSS is inaccurate rn, take only FL WSS value
    ubyte4 averageWheelSpeed_front = (ubyte4) (WheelSpeeds_getWheelSpeedRPM(wss_obj, FL, TRUE) + 0.5);

    ubyte4 averageWheelSpeed_rear = (ubyte4) (((WheelSpeeds_getWheelSpeedRPM(wss_obj, RL, TRUE) + 0.5)
                                    + (WheelSpeeds_getWheelSpeedRPM(wss_obj, RR, TRUE) + 0.5)) / 2);



    if (averageWheelSpeed_front < averageWheelSpeed_rear + launchControlSensitivity)
    {
        //WIP
        //Do limiting based on aggressiveness value
        sbyte2 aggressivenessCalculation = TORQUELIMIT_DEFAULT;
        MCM_commands_setTorqueLimit(mcm_obj, aggressivenessCalculation);
    }
}