#include "commands/ArmUpArmDown.h"
#include "commands/MoveArmFor.h"
#include "commands/MoveClawFor.h"
#include "Robot.h"
#include "Constants.h"

ArmUpArmDown::ArmUpArmDown() {
  addSequentialCommand(new MoveArmFor(1000, 127));
  addParallelCommand(new MoveClawFor(500, 127));
  addSequentialCommand(new MoveArmFor(1000, -127));
}
