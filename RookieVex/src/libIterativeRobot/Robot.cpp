#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/Base/StopBase.h"
#include "libIterativeRobot/commands/Base/DriveWithJoy.h"
#include "libIterativeRobot/commands/Base/BaseLinearMovement.h"

#include "libIterativeRobot/commands/LambdaGroup.h"
#include "libIterativeRobot/commands/Auton/AutonGroup1.h"

Robot* Robot::instance = 0;

Base* Robot::base = 0;

AutonChooser* Robot::autonChooser = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");

  // Initialize any subsystems
  base = new Base();

  autonChooser = AutonChooser::getInstance();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  libIterativeRobot::JoystickChannel* RightX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_X);
  libIterativeRobot::JoystickChannel* LeftX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_X);
  libIterativeRobot::JoystickButton* ArmToLowTower = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_B);
  libIterativeRobot::JoystickButton* ArmToMidTower = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_A);
  libIterativeRobot::JoystickButton* AnglerDown = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  libIterativeRobot::JoystickButton* AnglerUp = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  libIterativeRobot::JoystickButton* IntakeOpen = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  libIterativeRobot::JoystickButton* IntakeClose = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  libIterativeRobot::JoystickButton* AnglerToStart = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  libIterativeRobot::JoystickButton* AnglerToHorizontal = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_RIGHT);
  libIterativeRobot::JoystickButton* AnglerToTop = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  libIterativeRobot::JoystickButton* AnglerToBack = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_LEFT);

  // Add commands to be run to buttons
  LeftX->setThreshold(50);
  LeftY->setThreshold(50);
  DriveWithJoy* driveCommand = new DriveWithJoy();
  LeftX->whilePastThreshold(driveCommand);
  LeftY->whilePastThreshold(driveCommand);
}

void Robot::robotInit() {
  printf("Robot created.\n");
  autonChooser->addAutonCommand(new AutonGroup1(), "AutonGroup1");
  //autonChooser->addAutonCommand(new AutonGroup1(), "AutonGroup1");
  //autonChooser->addAutonCommand(new FlipOut(), "FlipOut");
}

void Robot::autonInit() {
  printf("Auton init, auton command is %x\n", autonChooser->getAutonCommand());
  autonChooser->uninit();
  autonChooser->runAuton();
}

void Robot::autonPeriodic() {
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::teleopInit() {
  //BaseLinearMovement* c = new BaseLinearMovement(3000, 3000);
  //GetData* c = new GetData();

  //TuneLinearProfile* c = new TuneLinearProfile(base->getLeftProfiler(), LeftFrontBaseData, base, 3000);

  /*libIterativeRobot::LambdaGroup* c = new libIterativeRobot::LambdaGroup();
  TuneLinearProfile* leftBackprop = new TuneLinearProfile(base->getLeftProfiler(), LeftFrontBaseData, base, 3000);
  TuneLinearProfile* rightBackprop = new TuneLinearProfile(base->getRightProfiler(), RightFrontBaseData, base, 3000);

  for (int i = 0; i < 1; i++) {
    c->addSequentialCommand(leftBackprop);
    c->addParallelCommand(rightBackprop);
  }*/

  autonChooser->init();
  //FlipOut* c = new FlipOut();
  //c->run();
}

void Robot::teleopPeriodic() {
  //printf("Teleop periodic\n");
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::disabledInit() {
  autonChooser->uninit();
}

void Robot::disabledPeriodic() {
}

Robot* Robot::getInstance() {
    if (instance == NULL) {
        instance = new Robot();
    }
    return instance;
}
