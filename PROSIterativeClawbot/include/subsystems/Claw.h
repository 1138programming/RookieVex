// 6 motors

#ifndef CLAW_H
#define CLAW_H

#include "main.h"

class Claw : public Subsystem {
  private:
    static Claw* instance;

    // Claw motors
    Motor* clawMotor;

    Encoder clawRightEncoder;

    Claw();
  public:
    void initDefaultCommand();
    void move(int speed);
    static Claw* getInstance();
};

#endif
