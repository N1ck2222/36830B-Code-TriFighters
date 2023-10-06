/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/


//test 
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// FL                   motor         1
// FR                   motor         2
// BL                   motor         3
// BR                   motor         4
// CatL                 motor         11
// CatR                 motor         12
// Intake               motor         5
// wings                digital_out   A
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"


using namespace vex;
competition Competition;
bool turnMotor = false;
bool doPiston = false;
bool resetAllowedY = false;
bool resetAllowedX = false;


void startMotors()
{
  FL.spin(forward);
  FR.spin(forward);
  BL.spin(forward);
  BR.spin(forward);
  CatL.spin(forward);
  CatR.spin(forward);
  intake.spin(forward);
  endgame.spin(forward);
}
void drives()
{
  FL.setVelocity(Controller1.Axis3.position() * 2 +
                     Controller1.Axis1.position() * 2,
                 percent);
  FR.setVelocity(Controller1.Axis3.position() * 2 -
                     Controller1.Axis1.position() * 2,
                 percent);
  BL.setVelocity(Controller1.Axis3.position() * 2 +
                     Controller1.Axis1.position() * 2,
                 percent);
  BR.setVelocity(Controller1.Axis3.position() * 2 -
                     Controller1.Axis1.position() * 2,
                 percent);
}
void intakeSpin() {
  if (Controller1.ButtonL1.pressing())  {
    intake.setVelocity(100, percent);
  }
  else if (Controller1.ButtonL2.pressing())  {
    intake.setVelocity(-100, percent);
  }
  else {
    intake.setVelocity(0, percent);
  }
}
void endgameSpin()  {
  if (Controller1.ButtonLeft.pressing())  {
    endgame.setVelocity(100, percent);
  }
  else if (Controller1.ButtonRight.pressing())  {
    endgame.setVelocity(-100, percent);
  }
  else {
    endgame.setVelocity(0, percent);
  }
}
int buttonYToggle()
{
  while (1)
  {
    if (Controller1.ButtonY.pressing())
    {
      if (resetAllowedY)
      {
        resetAllowedY = false;
        turnMotor = not turnMotor;
      }
    }
    else
    {
      resetAllowedY = true;
    }
  }
  return 1;
}

int buttonXToggle()
{
  while (1)
  {
    if (Controller1.ButtonX.pressing())
    {
      if (resetAllowedX)
      {
        resetAllowedX = false;
        doPiston = not doPiston;
      }
    }
    else
    {
      resetAllowedX = true;
    }
  }
  return 1;
}

void pre_auton(void)
{
  vexcodeInit();

  Brain.Screen.clearScreen();
  wait(1, seconds);
  startMotors();
}

void autonomous(void) {}

void usercontrol(void)
{
  Brain.Screen.clearScreen();
  vex::task catapultToggle(buttonYToggle);
  vex::task wingsToggle(buttonXToggle);

  while (1)
  {
    drives();
    intakeSpin();
    endgameSpin();
    if (turnMotor)
    {
      CatL.setVelocity(50, percent);
      CatR.setVelocity(50, percent);
    }
    else
    {
      CatL.setVelocity(0, percent);
      CatR.setVelocity(0, percent);
    }

    if (doPiston)
    {
      wings.set(true);
    }
    else
    {
      wings.set(false);
    }

    wait(20, msec);
  }
}

int main()
{

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true)
  {
    wait(100, msec);
  }
}
