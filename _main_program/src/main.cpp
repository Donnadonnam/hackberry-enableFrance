/* 
 *  =============================================================================================================================================
 *  Project : Hackberry e-Nable France
 *  Author  : Thomas Broussard
 * 
 *  ---------------------------------------------------------------------------------------------------------------------------------------------
 *  Description : Main program of Hackberry Hand
 * 
 *  Credits : 
 *  Program inspired by the HACKberry project, created by exiii Inc.
 *  https://github.com/mission-arm/HACKberry
 * 
 *  TaskScheduler Library, created by Anatoli Arkhipenko.
 *  https://github.com/arkhipenko/TaskScheduler
 * =============================================================================================================================================
 */

// -----------------------------------------------
// Select your extension board here (optional)
// -----------------------------------------------

//#define EXTENSION_GPIO
//#define EXTENSION_BLUETOOTH
#define EXTENSION_LEDS

// -----------------------------------------------


// Task Scheduler configuration (must be define before include)
#define _TASK_SLEEP_ON_IDLE_RUN // Enable sleep mode when tasks aren't running, to save power
#define _TASK_PRIORITY          // Enable the task priority system



// libraries dependencies
#include <Arduino.h>
#include "TaskScheduler.h"
#include "hackberry.h"
#include "hackberry_mapping.h"

Hackberry hackberry;

// function call
void setPriorities();

// Scheduler (Priority order : critical > high > runner)
Scheduler runner;
Scheduler highPriority;
Scheduler criticalPriority;

/* 
 * =============================================================================================
 *                                  MAIN PROGRAM
 * =============================================================================================
 */
void setup() 
{
  Serial.begin(9600);
  Serial.println(F("Start"));
  hackberry.init();
  setPriorities();
}

void loop() 
{  
  runner.execute();
}


/* 
 * =============================================================================================
 *                                  FUNCTIONS
 * =============================================================================================
 */


void setPriorities()
{
  runner.setHighPriorityScheduler(&highPriority);
  highPriority.setHighPriorityScheduler(&criticalPriority);
  runner.enableAll(true);
}



/* 
 * =============================================================================================
 *                                   MAIN DRIVERS ROUTINES
 * =============================================================================================
 */

// --------------------------------
//            BUTTONS
// --------------------------------
void Task_Buttonhandler()
{
  hackberry.routine.buttons.execute();
}
Task TaskButton(100  * TASK_MILLISECOND, TASK_FOREVER, &Task_Buttonhandler, &runner, true); 


// --------------------------------
//            MOVES
// --------------------------------
void Task_Moves()
{
  hackberry.routine.moves.execute();
}
Task T2(10 * TASK_MILLISECOND, TASK_FOREVER, &Task_Moves, &runner, true); 


// --------------------------------
//            CALIBRATIONS
// --------------------------------
void Task_Calibration()
{
  switch(hackberry.hand.getMode())
  {
    case SensorCalibration :
      hackberry.routine.calibration_sensor.execute();  
    break;

    case ServosCalibration :
      hackberry.routine.calibration_servos.execute(); 
    break;

    default:break;
  }
}
Task TaskCalibration(50  * TASK_MILLISECOND, TASK_FOREVER, &Task_Calibration, &criticalPriority, true); 



/* 
 * =============================================================================================
 *                                 SPECIFIC DRIVERS ROUTINES
 * =============================================================================================
 */

// --------------------------------
//  BATTERY MONITORING (MK3 only)
// --------------------------------
#ifdef BATTERY_MONITORING_ENABLED
  void Task_BatteryMonitoring()
  {
    hackberry.routine.batteryMonitoring.execute();
  }

  Task TaskBattery(10*TASK_SECOND, TASK_FOREVER, &Task_BatteryMonitoring, &highPriority, true);  
#endif



/* 
 * =============================================================================================
 *                                    EXTENSIONS ROUTINES
 * =============================================================================================
 */

// --------------------------------
//       BLUETOOTH MODULE
// --------------------------------
#ifdef EXTENSION_BLUETOOTH
  void Task_ExtensionBluetooth()
  {
    hackberry.routine.bluetooth.execute();
  }
  Task TaskBluetooth(100 * TASK_MILLISECOND, TASK_FOREVER, &Task_ExtensionBluetooth, &criticalPriority, true); 
#endif

// --------------------------------
//        LEDS STRIP
// --------------------------------
#ifdef EXTENSION_LEDS
  #include "extensions/leds_board/leds_board.h"
  Extension_Leds leds;

  void Task_ExtensionLeds()
  {
      leds.display();
  }
  Task TaskLeds(20 * TASK_MILLISECOND, TASK_FOREVER, &Task_ExtensionLeds, &runner, true); 
#endif