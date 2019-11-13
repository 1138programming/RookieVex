#include "commands/LoopPID.h"
#include "Robot.h"
#include "Constants.h"

LoopPID::LoopPID() {
  this->priority = DefaultCommandPriority;
}

bool LoopPID::canRun() {
  //printf("Can run?\n");
  return true; // This is the default value anyways, so this method can be removed
}

void LoopPID::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //printf("Initializing loopPID");
}

void LoopPID::execute() {
  //printf("Running loop PID\n");
  PIDController::loopAll();
}

bool LoopPID::isFinished() {
  return true;
}

void LoopPID::end() {
  // Code that runs when isFinished() returns true.
}

void LoopPID::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
