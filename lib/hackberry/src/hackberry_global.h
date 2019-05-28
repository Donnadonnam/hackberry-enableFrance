#ifndef __HACKBERRY_GLOBAL_H__
#define __HACKBERRY_GLOBAL_H__

#define ERROR_CODE -1

// Hand Selection
#define RIGHT_HAND true
#define LEFT_HAND false

// LIST OF EXISTING SENSORS
#define TYPE_IR_SENSOR 0
#define TYPE_EMG_SENSOR 1

// ---------------------------------------------------
// Constants for servomotor
// ---------------------------------------------------
#define THUMB   1
#define INDEX   2
#define FINGERS  3

// POSITIONS OF MEMBERS
#define ANGLE               30
#define THUMB_INIT_POS      45 
#define INDEX_INIT_POS      45
#define FINGERS_INIT_POS    45 

//right:open, left:close (temp)
#define THUMB_MAX           (THUMB_INIT_POS + ANGLE)
#define INDEX_MAX           (INDEX_INIT_POS + ANGLE)    
#define FINGERS_MAX         (FINGERS_INIT_POS + ANGLE)

//right:close, left:open (temp)
#define THUMB_MIN           (THUMB_INIT_POS - ANGLE) 
#define INDEX_MIN           (INDEX_INIT_POS - ANGLE)
#define FINGERS_MIN         (FINGERS_INIT_POS - ANGLE)


// INITIAL SPEED OF SERVOMOTOR
#define DEFAULT_SPEED 50


// ---------------------------------------------------
// Constants for bluetooth
// ---------------------------------------------------




#endif