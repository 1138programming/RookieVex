#ifndef _COMMANDS_EXAMPLECOMMAND_H_
#define _COMMANDS_EXAMPLECOMMAND_H_

#include "commands/Command.h"

class ExampleCommand : public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ExampleCommand();
};

#endif // _COMMANDS_EXAMPLECOMMAND_H_
