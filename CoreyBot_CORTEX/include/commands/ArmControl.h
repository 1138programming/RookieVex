#ifndef _COMMANDS_ARMCONTROL_H_
#define _COMMANDS_ARMCONTROL_H_

#include "commands/Command.h"

class ArmControl: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ArmControl(bool Up);
  private:
    bool Up;
};

#endif // _COMMANDS_ARMCONTROL_H_
