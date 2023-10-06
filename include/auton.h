


int wheelCircum = 10;
float degreesToSpin;

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


// Drives the robot in a straight line during autonomous
// @param driveDirection determines if the robot will drive forwards or backwards
// @param distance tells the robot how far to drive (in inches)
// @param driveVelocity specifies how fast the robot will drive
void autonDrive(directionType driveDirection, float distance, float driveVelocity)
{
  if (driveDirection == forward)
  {
    degreesToSpin = (distance * (1/wheelCircum) * 360);
    driveVelocities(driveVelocity);
    FL.spinFor(fwd, degreesToSpin, deg, false);
    FR.spinFor(fwd, degreesToSpin, deg, false);
    BL.spinFor(fwd, degreesToSpin, deg, false);
    BR.spinFor(fwd, degreesToSpin, deg, false);
    waitUntil(InertialSensor.acceleration(xaxis) > 3);
    waitUntil(InertialSensor.acceleration(xaxis) < 3);
    driveStop();

  }
  else if (driveDirection == reverse)
  {
    degreesToSpin = (distance * (1/wheelCircum) * 360);
    driveVelocities(driveVelocity);
    FL.spinFor(reverse, degreesToSpin, deg);
    FR.spinFor(reverse, degreesToSpin, deg);
    BL.spinFor(reverse, degreesToSpin, deg);
    BR.spinFor(reverse, degreesToSpin, deg);
    waitUntil(InertialSensor.acceleration(xaxis) > 3);
    waitUntil(InertialSensor.acceleration(xaxis) < 3);
    driveStop();

  }
  else
  {
    Brain.Screen.print("error: invalid autonomous function argument");
  }
}


void autonTurn(turnType turnDirection, float turnAngle, float turnVelocity)
{
  driveModes(hold);

  // Workaround for being unable to convert turnType to bool
  bool boolDirection;

  if (turnDirection == right){
    boolDirection = true;
  }
  else {
    boolDirection = false;
  }

  switch(boolDirection){
    case true:
    float prevHeading = InertialSensor.heading(deg);
    driveVelocities(turnVelocity);
    driveSpins(forward, reverse, forward, reverse);

    if (prevHeading + turnAngle < 360){
      waitUntil(InertialSensor.heading(deg) > prevHeading + turnAngle);
      driveStop(); return;
    }
    else{
      waitUntil(InertialSensor.heading(deg) > 1 && InertialSensor.heading(deg) < 90);
      waitUntil(InertialSensor.heading(deg) >= (prevHeading + turnAngle) - 360);
      driveStop(); return;
    }
    

    case false:
    prevHeading = InertialSensor.heading(deg) + 1;
    driveVelocities(turnVelocity);
    driveSpins(reverse, forward, reverse, forward);

    if (prevHeading - turnAngle > 0){
      waitUntil(InertialSensor.heading(deg) <= prevHeading - turnAngle);
      driveStop(); return;
    }
    else {
      waitUntil(InertialSensor.heading(deg) > 350 && InertialSensor.heading(deg) <= 360);
      waitUntil(InertialSensor.heading(deg) <= 360 - (turnAngle - prevHeading));
      driveStop(); return;
    }
  }
}