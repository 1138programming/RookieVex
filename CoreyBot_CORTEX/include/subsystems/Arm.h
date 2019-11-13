// 6 motors
#include "abstractBaseClasses/PIDController.h"

#ifndef ARM_H
#define ARM_H

#include "main.h"

class Arm : public Subsystem {
  private:
    static Arm* instance;

    // Arm motors
    Motor* armMotor;

    Encoder armRightEncoder;
    PIDController* armController;

    Arm();
  public:
    void initDefaultCommand();
    void move(int speed);
    void setSetpoint(int setpoint);
    bool atSetpoint();
    void loop();
    void lock();
    void disablePID();
    void enablePID();
    static Arm* getInstance();
};

#endif
