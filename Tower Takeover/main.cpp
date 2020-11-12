/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontRight           motor         6               
// BackRight            motor         5               
// FrontLeft            motor         7               
// BackLeft             motor         4               
// Controller1          controller                    
// HingeMotor           motor         1               
// IntakeLeft           motor         9               
// IntakeRight          motor         2               
// SonarFront           sonar         C, D            
// SonarBack            sonar         A, B            
// BarLift              motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void moveback (void){
  FrontRight.spin(directionType::rev,90, velocityUnits::pct);
  FrontLeft.spin(directionType::rev,90, velocityUnits::pct);
  BackRight.spin(directionType::rev,90, velocityUnits::pct);
  BackLeft.spin(directionType::rev,90, velocityUnits::pct);
}
void moveforward (void){
  FrontRight.spin(directionType::fwd,100, velocityUnits::pct);
  FrontLeft.spin(directionType::fwd,100, velocityUnits::pct);
  BackRight.spin(directionType::fwd,100, velocityUnits::pct);
  BackLeft.spin(directionType::fwd,100, velocityUnits::pct);
}
void motoroff (void){
  FrontRight.spin(directionType::rev,0, velocityUnits::pct);
  FrontLeft.spin(directionType::rev,0, velocityUnits::pct);
  BackRight.spin(directionType::fwd,0, velocityUnits::pct);
  BackLeft.spin(directionType::fwd,0, velocityUnits::pct);
}
void turnleft (void){
  FrontRight.spin(directionType::fwd, 100, velocityUnits::pct);
  BackRight.spin(directionType::fwd, 100, velocityUnits::pct);
}
void turnright (void){
  FrontLeft.spin(directionType::fwd, 100, velocityUnits::pct);
  BackLeft.spin(directionType::fwd, 100, velocityUnits::pct);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void intakeout (void){
   IntakeLeft.spin(directionType::rev, 25 , velocityUnits::pct);
   IntakeRight.spin(directionType::rev, 25 , velocityUnits::pct);
    
 }
void intakein (void){
   IntakeLeft.spin(directionType::fwd, 90 , velocityUnits::pct);
   IntakeRight.spin(directionType::fwd, 90 , velocityUnits::pct);
   
 }
void intakehold (void){
   IntakeLeft.stop(brakeType::hold);
   IntakeRight.stop(brakeType::hold);
   
 } 
void intakeoff (void){
   IntakeLeft.spin(directionType::fwd, 0, velocityUnits::pct);
   IntakeRight.spin(directionType::fwd, 0 ,velocityUnits::pct);
     
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hingeup (void){
   HingeMotor.spin(directionType::fwd, 50, velocityUnits::rpm);
 }
void hingedown (void){
   HingeMotor.spin(directionType::rev, 50, velocityUnits::rpm);
 }
void hingestop (void){
   HingeMotor.stop(brakeType::hold);
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int speed = 0;
int hingeposition;
//autonomous calls the void and then moves for amount of time and then sleeps and turns motors off
void autonomous(void) {
  
int speed = 0;


speed = 50;
FrontRight.spin(directionType::rev, speed, velocityUnits::pct);
FrontLeft.spin(directionType::rev, speed, velocityUnits::pct);
BackRight.spin(directionType::rev, speed, velocityUnits::pct);
FrontLeft.spin(directionType::rev, speed, velocityUnits::pct);
vex::task::sleep(1500);
speed = 80;
FrontRight.spin(directionType::fwd, speed, velocityUnits::pct);
FrontLeft.spin(directionType::fwd, speed, velocityUnits::pct);
BackRight.spin(directionType::fwd, speed, velocityUnits::pct);
FrontLeft.spin(directionType::fwd, speed, velocityUnits::pct);
vex::task::sleep(900);
motoroff();
IntakeLeft.spin(directionType::rev, 80, velocityUnits::pct);
IntakeRight.spin(directionType::rev, 80, velocityUnits::pct);
vex::task::sleep(500);
intakeoff();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
 
 
void usercontrol(void) {
  int intakemoving;
  intakemoving = 0;
  int X2 = 0, Y1 = 0, X1 = 0, threshold = 5; //creates controller deadzone
  while (1) {
    //displays sonar sensors in "cm"
    Brain.Screen.clearLine(1,color::black);
    Brain.Screen.clearLine(2,color::black);
    Brain.Screen.clearLine(3,color::black);
    Brain.Screen.clearLine(4,color::black);
    Brain.Screen.clearLine(5,color::black);
    Brain.Screen.clearLine(6,color::black);
    
    Brain.Screen.setCursor(1,0);
    Brain.Screen.print(hingeposition);
    Brain.Screen.setCursor(2,0);
    Brain.Screen.print(SonarBack.distance(vex::distanceUnits::cm));

    Brain.Screen.setCursor(3,0);
    Brain.Screen.print(FrontLeft.position(degrees));
    Brain.Screen.setCursor(4,0);
    Brain.Screen.print(BackLeft.position(degrees));
    Brain.Screen.setCursor(5,0);
    Brain.Screen.print(FrontRight.position(degrees));
    Brain.Screen.setCursor(6,0);
    Brain.Screen.print(BackRight.position(degrees));

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //hinge (Button L2 and L1)
    if (Controller1.ButtonL1.pressing()){
      hingeup();
    }
    else if(Controller1.ButtonL2.pressing()){
      hingedown();
    }
    else{
      hingestop();
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (Controller1.ButtonR2.pressing()){
      BarLift.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    else if (Controller1.ButtonR1.pressing()){
      BarLift.spin(directionType::rev, 100, velocityUnits::pct);
    }
    else {
      BarLift.stop(brakeType::hold);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    
    if (Controller1.ButtonA.pressing() == 1){
      hingeposition = 650;
      HingeMotor.spinToPosition(hingeposition,degrees, 40, velocityUnits::pct, true);
    }
    if (Controller1.ButtonX.pressing() == 1 && hingeposition <840){
      hingeposition = hingeposition + 20;
      HingeMotor.spinToPosition(hingeposition,degrees, 40, velocityUnits::pct, true);
    }
    if (Controller1.ButtonY.pressing() == 1){
      hingeposition = 0;
      HingeMotor.spinToPosition(hingeposition,degrees, 40, velocityUnits::pct, true);
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(Controller1.ButtonB.pressing()){
       hingeposition = 200;
       HingeMotor.spinToPosition(hingeposition,degrees, 40, velocityUnits::pct, false);

       IntakeLeft.spin(directionType::rev, 34, velocityUnits::pct);
       IntakeRight.spin(directionType::rev, 34, velocityUnits::pct);
       vex::task::sleep(150);

       speed = 40;
       FrontRight.spin(directionType::rev,speed, velocityUnits::pct);
       FrontLeft.spin(directionType::rev,speed, velocityUnits::pct);
       BackRight.spin(directionType::rev,speed, velocityUnits::pct);
       BackLeft.spin(directionType::rev,speed, velocityUnits::pct);
      vex::task::sleep(1500);
      intakeoff();
      //intake goes out while robot is moving backwards at set SPEED
    
      // intake goes down, hinge goes back to normal, and everything stops and gives the user control back
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //intake (ButtonUp, Down, and Left)
    /*
    Controller1.ButtonUp.pressed(intakein);
    Controller1.ButtonDown.pressed(intakeout);
    Controller1.ButtonLeft.pressed(intakehold);
    Controller1.ButtonRight.pressed(intakeoff);
*/  
  

    
    if (Controller1.ButtonUp.pressing() && intakemoving % 2 == 0){
    IntakeRight.spin(directionType::fwd, 100, velocityUnits::pct);
    IntakeLeft.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    if(Controller1.ButtonDown.pressing() && intakemoving % 2 == 0){
    IntakeRight.spin(directionType::rev, 40, velocityUnits::pct);
    IntakeLeft.spin(directionType::rev, 40, velocityUnits::pct);
    }
    if(Controller1.ButtonLeft.pressing() || Controller1.ButtonRight.pressing()){
      IntakeRight.stop(brakeType::hold);
      IntakeLeft.stop(brakeType::hold);
    }
    

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //advanced remote control drive WITH deadzones
    //Create "deadzone" for Y1/Ch3
    if(abs(Controller1.Axis3.value()) > threshold)
      Y1 = Controller1.Axis3.value();
    else 
      Y1 = 0;
     //Create "deadzone" for X1/Ch4 
    if(abs(Controller1.Axis4.value()) > threshold)
       X1 = Controller1.Axis4.value();
    else
      X1 = 0;
    //Create "deadzone" for X2/Ch1
    if(abs(Controller1.Axis1.value()) > threshold)
      X2 = Controller1.Axis1.value();
    else
      X2 = 0; 
    
    //drive commands
    /*
    FrontRight.spin(directionType::fwd, (Y1 - X2 - X1)*0.40, velocityUnits::pct);
    BackRight.spin(directionType::fwd, (Y1 - X2 + X1)*0.40, velocityUnits::pct);
    FrontLeft.spin(directionType::fwd, (Y1 + X2 + X1)*0.40, velocityUnits::pct);
    BackLeft.spin(directionType::fwd, (Y1 + X2 - X1)*0.40, velocityUnits::pct);
    */


        FrontLeft.spin(directionType::fwd, (Controller1.Axis3.value() + (Controller1.Axis1.value()*.5))/2, velocityUnits::pct); //(Axis3+Axis4)/2;
        FrontRight.spin(directionType::fwd, (Controller1.Axis3.value() - (Controller1.Axis1.value()*.5))/2, velocityUnits::pct);//(Axis3-Axis4)/2;
        BackLeft.spin(directionType::fwd, (Controller1.Axis3.value() + (Controller1.Axis1.value()*.5))/2, velocityUnits::pct); //(Axis3+Axis4)/2;
        BackRight.spin(directionType::fwd, (Controller1.Axis3.value() - (Controller1.Axis1.value()*.5))/2, velocityUnits::pct);//(Axis3-Axis4)/2;
        

      if (Controller1.ButtonLeft.pressing() == 1){
      FrontLeft.spin(directionType::fwd, 40, velocityUnits::pct);
      FrontRight.spin(directionType::fwd, 40, velocityUnits::pct);
      BackLeft.spin(directionType::rev, 40,  velocityUnits::pct);
      BackRight.spin(directionType::rev, 40,  velocityUnits::pct);
      }
      if (Controller1.ButtonRight.pressing() == 1){
      FrontLeft.spin(directionType::rev, 40, velocityUnits::pct);
      FrontRight.spin(directionType::rev, 40, velocityUnits::pct);
      BackLeft.spin(directionType::fwd, 40,  velocityUnits::pct);
      BackRight.spin(directionType::fwd, 40,  velocityUnits::pct);
      }
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}
//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Run the pre-autonomous function.
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
