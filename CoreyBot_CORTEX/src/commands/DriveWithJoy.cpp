#include "commands/DriveWithJoy.h"
#include "Robot.h"
#include "Constants.h"

DriveWithJoy::DriveWithJoy() {
  requires(Robot::base);
  this->priority = 2;
}

bool DriveWithJoy::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveWithJoy::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  rightSideSpeed = joystickGetAnalog(1, 2);
  leftSideSpeed = joystickGetAnalog(1, 3);
}

void DriveWithJoy::execute() {
  Robot::base->move(leftSideSpeed, rightSideSpeed);
}

bool DriveWithJoy::isFinished() {
  return true;
}

void DriveWithJoy::end() {
  // Code that runs when isFinished() returns true.
}

void DriveWithJoy::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::base->move(0, 0);
}
