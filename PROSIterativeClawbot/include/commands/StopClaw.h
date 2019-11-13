#ifndef _COMMANDS_STOPCLAW_H_
#define _COMMANDS_STOPCLAW_H_

#include "commands/Command.h"

class StopClaw: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopClaw();
  private:
};

#endif // _COMMANDS_STOPCLAW_H_
