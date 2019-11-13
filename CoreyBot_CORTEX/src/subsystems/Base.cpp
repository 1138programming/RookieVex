#include "main.h"
#include "commands/StopBase.h"

Base* Base::instance = 0;

Base::Base() {
  // Get base motors
  leftMotor = Motor::getMotor(leftBasePort);
  rightMotor = Motor::getMotor(rightBasePort);

  rightMotor->reverse();
}

void Base::initDefaultCommand() {
  setDefaultCommand(new StopBase());
}

/**
 * Move the base
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Base::move(int left, int right) {
  left = threshold((int)left);
  right = threshold((int)right);

  leftMotor->setSpeed(left);
  rightMotor->setSpeed(right);
}

Base* Base::getInstance() {
    if (instance == 0) {
      instance = new Base();
    }

    return instance;
}
