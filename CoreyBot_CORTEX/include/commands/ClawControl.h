#ifndef _COMMANDS_CLAWCONTROL_H_
#define _COMMANDS_CLAWCONTROL_H_

#include "commands/Command.h"

class ClawControl: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ClawControl(bool Open);
  private:
    bool Open;
};

#endif // _COMMANDS_CLAWCONTROL_H_
