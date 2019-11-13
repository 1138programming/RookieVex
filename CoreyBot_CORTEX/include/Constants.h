/**
 * @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_


#include "main.h"
//#include "subsystems/Base.h"
//#include "subsystems/Arm.h"
//#include "subsystems/MobileGoal.h"

#define DEFAULT_TASK_TIME 10000
#define DELAY_TIME 10
#define MAX_MOTORS 10
#define MAX_FOLLOWERS 3

// Motor ports
// Left base motor ports
const int leftBasePort = 1;
const int rightBasePort = 10;

const int armPort = 5;
const int clawPort = 10;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

const unsigned char armIME = 0;


// Global things that we need

#endif
