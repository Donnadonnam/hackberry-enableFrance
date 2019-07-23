/* 
 *  =============================================================================================================================================
 *  Project : Hackberry e-Nable France
 *  Author  : Thomas Broussard
 * 
 *  ---------------------------------------------------------------------------------------------------------------------------------------------
 *  Description :
 *  List of instructions for Hackberry bluetooth library
 * 
 *  Template of an instruction : 
 * 
 *  CMD;param1;param2;...;paramN
 * 
 *  Credits : 
 *  Program inspired by the HACKberry project, created by exiii Inc.
 *  https://github.com/mission-arm/HACKberry
 * =============================================================================================================================================
 */

/*-----------------------------------
* File generated with cmdlist.py
-----------------------------------*/

#ifndef __BLUETOOTH_INSTRUCTIONS_H__
#define __BLUETOOTH_INSTRUCTIONS_H__

//-----------------------------------
//COMMAND LIST GEN
//-----------------------------------
	#define CMD_GEN_TEST 		0 	// check the bluetooth connection.
	#define CMD_GEN_SET_PASS 	1 	// set new bluetooth password.
	#define CMD_GEN_SET_NAME 	2 	// set new name.
	#define CMD_GEN_STOP 		3 	// stop the bluetooth device.
	#define CMD_GEN_RESET 		4 	// reset parameters.
	#define CMD_GEN_VERSION 	5 	// get version of the current software.
	#define CMD_GEN_BATTERY 	6 	// get the current level of battery (or -1 if battery can't be read).

//-----------------------------------
//COMMAND LIST SRV
//-----------------------------------
	#define CMD_SRV_MOVE 		7 	// move motor to the given position.
	#define CMD_SRV_MOVE_UP 	8 	// rotation of servomotors clockwise.
	#define CMD_SRV_MOVE_DOWN 	9 	// rotation of servomotors reverse clockwise.
	#define CMD_SRV_SAVE_MAX 	10 	// save current position as max limit.
	#define CMD_SRV_SAVE_MIN 	11 	// save current position as min limit.
	#define CMD_SRV_LOAD_MAX 	12 	// load max limit value.
	#define CMD_SRV_LOAD_MIN 	13 	// load min limit value.
	#define CMD_SRV_SET_HAND 	14 	// set type of hand.
	#define CMD_SRV_GET_HAND 	15 	// get current type of hand.
	#define CMD_SRV_CALIB 		16 	// launch servomotor calibration.
	#define CMD_SRV_CALIB_UP 	17 	// move up the servomotor (calibration only).
	#define CMD_SRV_CALIB_DOWN 	18 	// move down the servomotor (calibration only).
	#define CMD_SRV_CALIB_OK 	19 	// validate the position of servomotor (calibration only).
	#define CMD_SRV_SET_SPEED 	20 	// Set the motors speed.
	#define CMD_SRV_GET_SPEED 	21 	// Get the motors speed.
	#define CMD_SRV_TEST 		22 	// Launch the test procedure for motors.

//-----------------------------------
//COMMAND LIST SENS
//-----------------------------------
	#define CMD_SENS_GET_VALUE 	23 	// get current sensor value.
	#define CMD_SENS_SET_TYPE 	24 	// set type of sensor used (IR,EMG,etc…).
	#define CMD_SENS_GET_TYPE 	25 	// get type of sensor used (IR,EMG,etc…).
	#define CMD_SENS_CALIB 		26 	// launch sensor calibration.

#endif