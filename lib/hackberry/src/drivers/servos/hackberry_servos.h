/* 
 *  =============================================================================================================================================
 *  Project : Hackberry e-Nable France
 *  Author  : Thomas Broussard
 * 
 *  ---------------------------------------------------------------------------------------------------------------------------------------------
 *  Description :
 *  Library for controlling Hackberry hand servomotors
 * 
 *  Credits : 
 *  Program inspired by the HACKberry project, created by exiii Inc.
 *  https://github.com/mission-arm/HACKberry
 * =============================================================================================================================================
 */

#ifndef __HACKBERRY_SERVOS_H__
#define __HACKBERRY_SERVOS_H__

// Dependencies
#include <Arduino.h>
#include "hackberry_global.h"
#include "dependencies/VarSpeedServo.h"

// Members
#ifndef THUMB
#define THUMB 1
#endif

#ifndef INDEX
#define INDEX 2
#endif

#ifndef FINGERS
#define FINGERS 3
#endif

// Hand
#ifndef LEFT_HAND
#define LEFT_HAND false
#endif

#ifndef RIGHT_HAND
#define RIGHT_HAND true
#endif


// class
class Hackberry_servos{

    public: 
    Hackberry_servos(int indexPin, int thumbPin, int fingersPin);
    void init(bool selectedHand);

    // Hand type
    void setHand(bool selectedHand);

    // speed
    void setSpeed(int speed);
    int getSpeed();

    // moving fingers
    void move(int member, int position, bool waitEnabled);
    void relativeMove(int member, int degree, bool waitEnabled);
    
    void open(int member);
    void close(int member);
    void openAll();
    void closeAll();

    // Positions of fingers
    void setLimitPositions(int member, int limit1, int limit2);

    int getPosition(int member);
    int getOpenPosition(int member);
    int getClosePosition(int member);
    
    private:
    // wiring pins
    int _pinServoIndex;
    int _pinServoThumb;
    int _pinServoFingers;

    // Selected hand (right or left)
    bool _selectedHand;
    
    // Servomotors
    VarSpeedServo  servoIndex;  
    VarSpeedServo  servoThumb;  
    VarSpeedServo  servoFingers; 

    // limit of movements
    int _openThumb , _closedThumb;
    int _openIndex , _closedIndex;
    int _openFingers , _closedFingers;

    // speed
    int _speed;

    // servomotor move
    void moveServo(int member, int wantedPosition);
    void moveServo(int member, int wantedPosition, bool waitEnabled);
    
    // utils
    int frameInteger(int value, int lim1, int lim2);
    
};


#endif