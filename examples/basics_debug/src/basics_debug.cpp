/* 
 *  =============================================================================================================================================
 *  Project : Hackberry e-Nable France
 *  Author  : Thomas Broussard
 * 
 *  ---------------------------------------------------------------------------------------------------------------------------------------------
 *  Description : Minimalist example of Hackberry_buttons library usage
 * 
 *  Credits : 
 *  Program inspired by the HACKberry project, created by exiii Inc.
 *  https://github.com/mission-arm/HACKberry
 * =============================================================================================================================================
 */

#include <Arduino.h>
#include "hackberry.h"

Hackberry hackberry;

int intervalBetweenPrint = 1000; // ms
bool enableDebug = true;

void setup() {
  hackberry.begin(RIGHT_HAND, enableDebug);
}

void loop() 
{  
  // Print sensor infos
  hackberry.debug.printSensor();
  delay(intervalBetweenPrint);

  // Print servo infos
  hackberry.debug.printServos();
  delay(intervalBetweenPrint);

  // Print all infos
  hackberry.debug.printAll();
  delay(intervalBetweenPrint);
}