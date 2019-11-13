#ifndef _COMMANDS_LOOPPID_H_
#define _COMMANDS_LOOPPID_H_

#include "commands/Command.h"

class LoopPID: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    LoopPID();
  private:
};

#endif // _COMMANDS_ARMCONTROL_H_
