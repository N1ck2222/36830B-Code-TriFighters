#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FL = motor(PORT1, ratio18_1, true);
motor FR = motor(PORT2, ratio18_1, false);
motor BL = motor(PORT3, ratio18_1, true);
motor BR = motor(PORT4, ratio18_1, false);
motor CatL = motor(PORT11, ratio18_1, true);
motor CatR = motor(PORT12, ratio18_1, false);
motor intake = motor(PORT5, ratio18_1, false);
motor endgame = motor(PORT14, ratio18_1, true);
digital_out wings = digital_out(Brain.ThreeWirePort.A);
inertial InertialSensor = inertial(PORT10);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}