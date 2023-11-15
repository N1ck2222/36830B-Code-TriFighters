#include "vex.h"
#include "robot-config.h"


int wheelCircum = 10;
float degreesToSpin;


// Shorthand for driving forward a number of seconds
// @param number of seconds to drive forward
void driveForwardFor(float number)
{
  FL.setVelocity(50, pct);
  FR.setVelocity(50, pct);
  BL.setVelocity(50, pct);
  BR.setVelocity(50, pct);
  wait(number, seconds);
  FL.setVelocity(0, pct);
  FR.setVelocity(0, pct);
  BL.setVelocity(0, pct);
  BR.setVelocity(0, pct);
}

// Shorthand for driving backwards a number of seconds
// @param number of seconds to drive backwards
void driveBackwardFor(float number)
{
  FL.setVelocity(-50, pct);
  FR.setVelocity(-50, pct);
  BL.setVelocity(-50, pct);
  BR.setVelocity(-50, pct);
  wait(number, seconds);
  FL.setVelocity(0, pct);
  FR.setVelocity(0, pct);
  BL.setVelocity(0, pct);
  BR.setVelocity(0, pct);
}

// Shorthand for turning left a number of seconds
// @param number of seconds to turn left for
void turnLeftFor(float number)
{
  FL.setVelocity(-50, pct);
  FR.setVelocity(50, pct);
  BL.setVelocity(-50, pct);
  BR.setVelocity(50, pct);
  wait(number, seconds);
  FL.setVelocity(0, pct);
  FR.setVelocity(0, pct);
  BL.setVelocity(0, pct);
  BR.setVelocity(0, pct);
}

// Shorthand for turning right a number of seconds
// @param number of seconds to turn right for
void turnRightFor(float number)
{
  FL.setVelocity(50, pct);
  FR.setVelocity(-50, pct);
  BL.setVelocity(50, pct);
  BR.setVelocity(-50, pct);
  wait(number, seconds);
  FL.setVelocity(0, pct);
  FR.setVelocity(0, pct);
  BL.setVelocity(0, pct);
  BR.setVelocity(0, pct);
}



// Shorthand for setting drivetrain velocities
// @param number how fast the drivetrain will drive
void driveVelocities(float number){
  FL.setVelocity(number, pct);
  FR.setVelocity(number, pct);
  BL.setVelocity(number, pct);
  BR.setVelocity(number, pct);
}

// Shorthand for stopping the drivetrain
void driveStop(){
  FL.stop();
  FR.stop();
  BL.stop();
  BR.stop();
}

// Shorthand for activating the drivetrain
void driveSpins(directionType FLr, directionType FRr, directionType BLr, directionType BRr){
  FL.spin(FLr);
  FR.spin(FRr);
  BL.spin(BLr);
  BR.spin(BRr);
}

// Shorthand for setting a drivetrain stopping mode
// @param type what type of stopping mode the drivetrain switches to
void driveModes(brakeType type){
  FL.setStopping(type);
  FR.setStopping(type);
  BL.setStopping(type);
  BR.setStopping(type);
}


void rightAuton(){
  driveBackwardFor(2.85);
  turnRightFor(0.7);
  intake.setVelocity(-100, percent);
  wait(2, seconds);
  intake.setVelocity(0, percent);
  driveBackwardFor(1);
  driveForwardFor(1);

}

void leftScoreAuton(){
  driveBackwardFor(2.85);
  turnLeftFor(0.7);
  intake.setVelocity(-100, percent);
  wait(2, seconds);
  intake.setVelocity(0, percent);
  driveBackwardFor(1);
  driveForwardFor(1);
}

void leftAuton(){
  CatL.setVelocity(25, percent);
  CatR.setVelocity(25, percent);
  
}

void skillsAuton(){
  CatL.setVelocity(50, percent);
  CatR.setVelocity(50, percent);
}