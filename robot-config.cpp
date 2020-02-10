#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
inertial Inertial = inertial(PORT3);
motor frontRight = motor(PORT6, ratio18_1, true);
motor backRight = motor(PORT5, ratio18_1, true);
motor frontLeft = motor(PORT7, ratio18_1, false);
motor backLeft = motor(PORT8, ratio18_1, false);
controller Controller1 = controller(primary);
motor hingeMotor = motor(PORT1, ratio36_1, true);
motor intakeLeft = motor(PORT9, ratio36_1, false);
motor intakeRight = motor(PORT2, ratio36_1, true);
sonar sonarBack = sonar(Brain.ThreeWirePort.A);
motor intakeArm = motor(PORT10, ratio36_1, false);
sonar SonarLeft = sonar(Brain.ThreeWirePort.C);
sonar SonarRight = sonar(Brain.ThreeWirePort.E);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}