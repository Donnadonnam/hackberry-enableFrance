/* 
 *  =============================================================================================================================================
 *  Project : Hackberry e-Nable France
 *  Author  : Thomas Broussard
 * 
 *  ---------------------------------------------------------------------------------------------------------------------------------------------
 *  Description : Handle the behavior of buttons
 * 
 *  Credits : 
 *  Program inspired by the HACKberry project, created by exiii Inc.
 *  https://github.com/mission-arm/HACKberry
 * =============================================================================================================================================
 */

#include "routine_buttons.h"


Routine_buttons::Routine_buttons()
{}

void Routine_buttons::init(Hackberry_hand *hand)
{
    this->hand = hand;
}


void Routine_buttons::execute()
{
    // change button gesture here
    if (this->hand->buttons.isCalibButtonPressed())
    {
        if (this->isDebounced(&this->lastCalibDebounce, DEBOUNCE_DELAY))
        {
            this->actionCalib();
        }
    }


    else if (this->hand->buttons.isExtraButtonPressed())
    {
        if (this->isDebounced(&this->lastExtraDebounce, DEBOUNCE_DELAY))
        {
            this->actionExtra();
        }
    }

    else if (this->hand->buttons.isThumbButtonPressed())
    {
        if (this->isDebounced(&this->lastThumbDebounce, DEBOUNCE_DELAY))
        {
            this->actionThumb();
        }
    }


    else if (this->hand->buttons.isLockButtonPressed())
    {
        if (this->isDebounced(&this->lastLockDebounce, DEBOUNCE_DELAY))
        {
            this->actionLock();
        }
    }

}

/**
 * Action executed when Calib button is pressed
 * 
 * Trigger the calibration sequence for the sensor
 */
void Routine_buttons::actionCalib()
{
    #ifdef DEBUG_ROUTINE_ENABLED
        Serial.println("Calib Button Pressed");
    #endif
    
    // Sensor Calibration Mode
    if (this->hand->isSensorCalibrationEnabled())
    {}

    // Servos Calibration Mode
    else if(this->hand->isServosCalibrationEnabled())
    {}

    // Standard Mode
    else
    {
        #ifdef DEBUG_ROUTINE_ENABLED
            Serial.println("Sensor Calibration Started");
        #endif
        this->hand->startSensorCalibration();
    }
}

/**
 * Action executed when Extra button is pressed
 * 
 * idea : enable/disable bluetooth here ? 
 */
void Routine_buttons::actionExtra()
{
    #ifdef DEBUG_ROUTINE_ENABLED
        Serial.println("Extra Button Pressed");
    #endif

    // Sensor Calibration Mode
    if (this->hand->isSensorCalibrationEnabled())
    {}

    // Servos Calibration Mode
    else if(this->hand->isServosCalibrationEnabled())
    {}

    // Standard Mode
    else
    {

        #ifdef MAPPING_MK2
            #ifdef DEBUG_ROUTINE_ENABLED
                Serial.println("Servomotors Calibration Started");
            #endif
            this->hand->startServosCalibration();
        #endif

        #ifdef MAPPING_MK3
            if (this->hand->bluetooth.isEnabled())
            {
                #ifdef DEBUG_ROUTINE_ENABLED
                Serial.println("Bluetooth stopped");
                #endif
                this->hand->bluetooth.stop();
            }
            else
            {
                #ifdef DEBUG_ROUTINE_ENABLED
                Serial.println("Bluetooth started");
                #endif
                this->hand->bluetooth.start();
            }
        #endif
    }
    
}

/**
 * Action executed when Thumb button is pressed
 * 
 * put Thumb in open or close position
 */
void Routine_buttons::actionThumb()
{
    #ifdef DEBUG_ROUTINE_ENABLED
        Serial.println("Thumb Button Pressed");
    #endif

    // Sensor Calibration Mode
    if (this->hand->isSensorCalibrationEnabled())
    {}

    // Servos Calibration Mode
    else if(this->hand->isServosCalibrationEnabled())
    {}
    else
    {
        if (isThumbOpen)
        {
            this->hand->servos.close(THUMB);
            this->isThumbOpen = false;
        }
        else
        {
            this->hand->servos.open(THUMB);
            this->isThumbOpen = true;
        }
    }
    
}

/**
 * Action executed when Lock button is pressed
 * 
 */
void Routine_buttons::actionLock()
{
    #ifdef DEBUG_ROUTINE_ENABLED
        Serial.println("Lock Button Pressed");
    #endif
    
    // Sensor Calibration Mode
    if (this->hand->isSensorCalibrationEnabled())
    {}

    // Servos Calibration Mode
    else if(this->hand->isServosCalibrationEnabled())
    {}
    
    // Standard mode
    else
    {
        if (isLockEnabled)
        {
            this->hand->servos.unlockMember(FINGERS);
            this->isLockEnabled = false;
        }
        else
        {
            this->hand->servos.lockMember(FINGERS);
            this->isLockEnabled = true;
        }
    }
}

/**
 * Check if a button is debounced or not
 * 
 * @param lastDebounceTime pointer to last debounce time of the button (to update it)
 * @param debounceDelay minimum delay between toggles to debounce the circuit
 *  
 * @return true if debounce is finished ; false otherwise
 */
bool Routine_buttons::isDebounced(unsigned long *lastDebounceTime, unsigned long debounceDelay)
{
    bool result = false;
    
    result = (millis() - *lastDebounceTime) > debounceDelay;
    *lastDebounceTime = millis();
    return result;
}
