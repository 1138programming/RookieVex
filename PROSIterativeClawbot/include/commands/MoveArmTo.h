#ifndef _COMMANDS_MOVEARMTO_H_
#define _COMMANDS_MOVEARMTO_H_

#include "commands/Command.h"

class MoveArmTo: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveArmTo(int target);
  private:
    int target = 0;
};

#endif // _COMMANDS_MOVEARMTO_H_
