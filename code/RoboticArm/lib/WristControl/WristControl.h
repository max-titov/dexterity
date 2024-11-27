#ifndef WRIST_CONTROL_H
#define WRIST_CONTROL_H

#include "Arduino.h"
#include "RoboticArm.h"

void wristControlSetup();
void controlWrist(uint8_t* wrist_pos);

#endif