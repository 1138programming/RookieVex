// 6 motors

#ifndef BASE_H
#define BASE_H

#include "main.h"

class Base : public Subsystem {
  private:
    static Base* instance;

    // Base motors
    Motor* leftMotor;
    Motor* rightMotor;

    Encoder baseRightEncoder;

    Base();
  public:
    void initDefaultCommand();
    void move(int left, int right);
    static Base* getInstance();
};

#endif
