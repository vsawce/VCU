#include "IO_Driver.h"

#include "eeprom.h"

#define LOCAL static

LOCAL bool getAddress(eepromValue value, ubyte2* address, ubyte1* bytes);
LOCAL ? readInitialValues(?);

//---------------------------------------------------------------
// Constructor
//---------------------------------------------------------------
/**
* @brief 
*
* @param[in]   value       Which EEPROM value we want the address/length of
* @param[out]  address     The EEPROM address of the desired value
* @param[out]  bytes       The length (number of bytes) of the value
* @return      Whether or not the address/length were successfully found.
*/
EEPROMManager* EEPROMManager_new()
{
    //Allocate memory for EEPROMManager object
    EEPROMManager* me = (EEPROMManager*)malloc(sizeof(struct _EEPROMManager));

    //Allocate memory for EEPROM data (2x)

    me->status = EEPROM_op_initialize;

    //Start initial EEPROM read
    readInitialValues();
    
    return me;
}

//---------------------------------------------------------------
// Accessors / Mutators
//---------------------------------------------------------------
/**  @ingroup FunctionGroup
* @brief Specific description
*/
bool EEPROMManager_get_ubyte1(EEPROMManager* me, eepromValue parameter, ubyte1* value)
{

}


//---------------------------------------------------------------
// Helper functions (private)
//---------------------------------------------------------------
/**
 * @brief Returns the address and length of any variable in the eepromValue enum
 *
 * @param[in]   value       Which EEPROM value we want the address/length of
 * @param[out]  address     The EEPROM address of the desired value
 * @param[out]  bytes       The length (number of bytes) of the value
 * @return      Whether or not the address/length were successfully found.
 */
LOCAL bool getAddress(eepromValue value, ubyte2* address, ubyte1* bytes)
{
    bool success = FALSE;


    *address = 0;
    *bytes = 0;
    return success;
}


LOCAL ? readInitialValues(?)
{

}
