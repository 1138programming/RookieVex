#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/commands/Auton/AutonGroup1.h"
#include "libIterativeRobot/commands/Miscellaneous/Delay.h"
#include "libIterativeRobot/commands/Base/BaseLinearMovement.h"
#include "libIterativeRobot/commands/Base/DriveForTime.h"

AutonGroup1::AutonGroup1() {
  addSequentialCommand(new DriveForTime(100, 100, 1000));
  addSequentialCommand(new DriveForTime(80, -80, 2000));
  addSequentialCommand(new DriveForTime(100, 100, 1000));
  addSequentialCommand(new DriveForTime(80, -80, 2000));
  addSequentialCommand(new DriveForTime(100, 100, 1000));
  addSequentialCommand(new DriveForTime(80, -80, 2000));
  addSequentialCommand(new DriveForTime(100, 100, 1000));
}

