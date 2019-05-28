/* 
 *  =============================================================================================================================================
 *  Project : Hackberry e-Nable France
 *  Author  : Thomas Broussard
 * 
 *  ---------------------------------------------------------------------------------------------------------------------------------------------
 *  Description :
 *  Library to control the push buttons of the Hackberry hand
 * 
 *  Credits : 
 *  Program inspired by the HACKberry project, created by exiii Inc.
 *  https://github.com/mission-arm/HACKberry
 * =============================================================================================================================================
 */

#ifndef __HACKBERRY_BUTTONS_H__
#define __HACKBERRY_BUTTONS_H__

#define BUTTONPRESSED LOW

// dependencies
#include <Arduino.h>
#include "hackberry_global.h"

/**
 * TODO : A6 and A7 are analog inputs. Can't use DigitalRead function on them --> replace them by GPIO ?
 */
class Hackberry_buttons{


    public: 
    Hackberry_buttons(int pinCalib, int pinExtra, int pinThumb, int pinLock);

    void init();

     // Get button state
    bool isCalibButtonPressed();
    bool isExtraButtonPressed();
    bool isThumbButtonPressed();
    bool isLockButtonPressed();

    private:

    // Wiring pins
    int _pinCalib;       // Start hand calibration
    int _pinExtra;       // Reverse the direction of rotation of the fingers
    int _pinThumb;       // Thumb opening / closing
    int _pinLock;        // lock / unlock the fingers 
};




#endif