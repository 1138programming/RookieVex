#ifndef _COMMANDS_STOPBASE_H_
#define _COMMANDS_STOPBASE_H_

#include "commands/Command.h"

class StopBase: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopBase();
  private:
};

#endif // _COMMANDS_STOPBASE_H_
