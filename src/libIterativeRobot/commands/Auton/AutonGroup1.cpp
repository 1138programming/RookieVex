#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/commands/Auton/AutonGroup1.h"
#include "libIterativeRobot/commands/Miscellaneous/Delay.h"
#include "libIterativeRobot/commands/Base/BaseLinearMovement.h"
#include "libIterativeRobot/commands/Base/DriveForTime.h"

AutonGroup1::AutonGroup1() {
  addSequentialCommand(new BaseLinearMovement(10000, 10000, 1, 0.02));
}
