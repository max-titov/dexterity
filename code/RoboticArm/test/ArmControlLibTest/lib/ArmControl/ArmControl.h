#ifndef ARM_CONTROL_H
#define ARM_CONTROL_H

#include <Arduino.h>
#include <FastLED.h>
#include <FingerControl.h>
#include <WristControl.h>
#include <General_ESPNOW.h>
#include <RoboticArm.h>

// built in LED
#define NUM_LEDS 1

//initializes finger control and wrist control libraries
void armControlSetup();

//controls fingers and wrist based on data from control glove
void controlArm(position_packet* arm_inData);

//prints servo position data to serial in a teleplot compatable format
void printServoPositions();

#endif