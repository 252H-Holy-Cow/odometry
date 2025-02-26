#include "lemlib/chassis/chassis.hpp"
#include "skills.hpp"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"
#include "tasks.hpp"

void skillsAuton(){
  //chassis.turnToHeading(90, 5000);
  //chassis.moveToPoint(0,50,2000,{.minSpeed = 50, .earlyExitRange = 1});
  //chassis.moveToPose(0, 60, 0, 5000);
    // score alliance stake
    doColorSort = false;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    convDir = FORWARD;
    convVelocity = 600;
    pros::delay(300);
    chassis.moveToPoint(0, 13.5, 2000); //800
  
    // // get first mogo
    chassis.turnToHeading(-90, 2000); //700
    convVelocity = 0;
    chassis.moveToPoint(11, 14, 1000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPoint(20, 14, 750, {.forwards = false, .maxSpeed = 30});
    pros::delay(500);
    clamp.set_value(true);
  
    // // get rings 1 2
    chassis.turnToHeading(7, 2000); //800
    chassis.moveToPoint(23.5, 32, 2000, {.minSpeed = 50, .earlyExitRange = 1});
    convVelocity = 600;
    chassis.moveToPoint(35, 50, 2000, {.maxSpeed = 60, .minSpeed = 30, .earlyExitRange = 1});
    chassis.moveToPoint(48, 85, 2000, {.maxSpeed = 80});
   
    // ring 3 wallstake

    chassis.moveToPoint(45.7, 71, 2000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPose(44, 61, 10, 2000, {.forwards = false});
    chassis.turnToHeading(90, 2000);
    armToLoadPos = true;
    chassis.moveToPoint(60, 62, 2000,{.minSpeed = 65, .earlyExitRange = 1});
    pros::delay(2000);
    convVelocity = 0;
    armToLoadPos = false;
    armToScore = true;
    pros::delay(800);
    convVelocity = 600;
    armToScore = false;
    armToStartPos = true;
  
    // // get rings 4 5 6
    chassis.moveToPoint(50, 62, 2000, {.forwards = false});
    chassis.turnToHeading(180, 2000);
    chassis.moveToPoint(51, 20, 400);
    chassis.moveToPoint(51, 10, 1200, {.maxSpeed = 60});
    chassis.moveToPoint(51, 3, 1200, {.maxSpeed = 50});
  
    // // get ring 7 and put mogo in corner
    chassis.turnToHeading(55, 2000);
    chassis.moveToPoint(61, 12, 1000);
    chassis.turnToHeading(-30, 700);
    chassis.moveToPoint(63.5, 4.5, 2000, {.forwards = false});
    pros::delay(500);
    clamp.set_value(false);
    convVelocity = 0;
    // pros::delay(100);
    // arm.move_velocity(0);
    
    // // get second mogo
    chassis.moveToPoint(56.5, 12.5, 2000);
    chassis.turnToHeading(90, 2000);
    chassis.moveToPoint(15, 12, 2000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPose(-10, 12, 90, 2000, {.forwards = false});
    chassis.moveToPoint(-23, 12, 2000, {.forwards = false, .maxSpeed = 30});
    pros::delay(800);
    clamp.set_value(true);
    pros::delay(200);
    // pros::delay(950);
    // clamp.set_value(true);

    // get rings 8 9
    chassis.swingToHeading(-38, DriveSide::LEFT, 4000);
    convVelocity = 600;
    chassis.moveToPoint(-22, 35, 2000, {.minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPoint(-39, 68, 2000,{.maxSpeed = 90, .minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPose(-43, 83, -15, 2000);

    // chassis.turnToHeading(7, 500);
    // chassis.moveToPoint(-22, 39, 400, {.earlyExitRange = 10});
    // chassis.moveToPoint(-40, 50, 650, {.earlyExitRange = 8});
    // chassis.moveToPoint(-44, 83, 800);
  
    // wallstake ring 10
    chassis.moveToPoint(-40.7, 69, 2000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPose(-39, 59, -10, 2000, {.forwards = false});
    chassis.turnToHeading(-90, 2000);
    armToLoadPos = true;
    chassis.moveToPoint(-60, 60, 2000,{.minSpeed = 65, .earlyExitRange = 1});
    pros::delay(2000);
    convVelocity = 0;
    armToLoadPos = false;
    armToScore = true;
    pros::delay(800);
    convVelocity = 600;
    armToScore = false;
    armToStartPos = true;
    // chassis.turnToHeading(-160, 500);
    // chassis.moveToPoint(-51, 60, 1400, {.maxSpeed = 100});
    // armToLoadPos = true;
    // chassis.turnToHeading(-90, 600);
    // chassis.moveToPoint(-70, 60, 600);
    // pros::delay(1400);
    // convVelocity = 0;
    // armToLoadPos = false;
    // armToScore = true;
  
    // get rings 11 12 13
    chassis.moveToPoint(-45, 60, 2000, {.forwards = false});
    chassis.turnToHeading(180, 2000);
    chassis.moveToPoint(-46, 18, 400);
    chassis.moveToPoint(-46, 8, 1200, {.maxSpeed = 60});
    chassis.moveToPoint(-46, 1, 1200, {.maxSpeed = 50});
    // pros::delay(800);
    // // chassis.moveToPoint(70, 69, 300);
    // chassis.moveToPoint(-40, 60, 850, {.forwards = false});
    // armToScore = false;
    // armToStartPos = true;
    // convVelocity = 600;
    // chassis.turnToHeading(200, 700);
    // chassis.moveToPoint(-44, 4, 400);
    // armToStartPos = true;
    // chassis.moveToPoint(-44, 4, 1200, {.maxSpeed = 60});
    // chassis.moveToPoint(-44, 4, 1200, {.maxSpeed = 30});
  
    // // get ring 14 and put mogo in corner
    chassis.turnToHeading(-55, 2000);
    chassis.moveToPoint(-57, 10, 1000);
    chassis.turnToHeading(30, 700);
    chassis.moveToPoint(-59, 2.5, 2000, {.forwards = false});
    pros::delay(500);
    clamp.set_value(false);

    // arm.move_velocity(0);
    // chassis.turnToHeading(-45, 700);
    // chassis.moveToPoint(-57, 15, 1300);
    // chassis.turnToHeading(45, 700);
    // chassis.moveToPoint(-63, 2, 500, {.forwards = false});
    // pros::delay(500);
    // clamp.set_value(false);
    // pros::delay(100);
  
    // // get ring 15 
    chassis.moveToPose(-46, 107, 0,5000, {.lead = 0.5});
    chassis.turnToHeading(-90, 2000);
    convVelocity = 0;
    chassis.moveToPose(5, 107, -90 , 3000, {.forwards = false, .lead = 0.5});
    // chassis.turnToHeading(5, 300);
    // convDir = STOP;
    // convDir = FIRST;
    // chassis.moveToPoint(-38, 83, 700, {.earlyExitRange = 10});
    // chassis.moveToPoint(-21, 84, 900);
  
    // // get mogo 3
    // chassis.turnToHeading(205, 700);
    // chassis.moveToPoint(4, 108, 500, {.forwards = false, .maxSpeed=100});
    // pros::delay(500);
    // chassis.moveToPoint(4, 110, 700, {.forwards = false, .maxSpeed = 50});
    // pros::delay(700);
    // clamp.set_value(true);
  
    // // get rings 16 17 and 18
    // doColorSort = true;
    // convDir = STOP;
    // convDir = FORWARD;
    // chassis.moveToPoint(-58, 106, 1000);
    // chassis.moveToPoint(-58, 104, 1400, {.maxSpeed=50});
    // chassis.moveToPoint(-36, 104, 1000, {.forwards = false});
    // chassis.moveToPoint(-43, 120, 1400);
    
    // // get rings 19 20 and 21
    // chassis.turnToHeading(100, 700);
    // chassis.moveToPoint(20, 94, 800, {.earlyExitRange = 10});
    // chassis.moveToPoint(23, 89, 1200);
    // chassis.turnToHeading(40, 500);
    // chassis.moveToPoint(45, 105, 500, {.earlyExitRange = 8});
    // chassis.moveToPoint(45, 120, 1000);
  
    // // put mogo 3 in corner 
    // chassis.turnToHeading(260, 700);
    // chassis.moveToPoint(56, 128, 800, {.forwards = false});
    // pros::delay(500);
    // clamp.set_value(false);
    // chassis.moveToPoint(60, 128, 600, {.forwards = false});
  
    // // get mogo 4
    // chassis.moveToPoint(0, 100, 1000, {.earlyExitRange = 8});
    // chassis.turnToHeading(110, 700);
    // chassis.moveToPoint(-22, 120, 500, {.forwards = false});
    // chassis.moveToPoint(-22, 120, 800, {.forwards = false, .maxSpeed = 50});
    // pros::delay(800);
    // clamp.set_value(true);
  
    // // put mogo 4 in corner
    // chassis.turnToHeading(80, 400);
    // chassis.moveToPoint(-65, 105, 500, {.forwards = false, .earlyExitRange = 10});
    // chassis.moveToPoint(-70, 130, 1000, {.forwards = false});
    // pros::delay(900);
    // clamp.set_value(false);
  
    // // hang
    // chassis.moveToPoint(-26, 94, 1000);
    // chassis.turnToHeading(-45, 800);
    // armToScore = true;
    // chassis.moveToPoint(-6, 70, 500, {.forwards=false, .earlyExitRange=8});
    // chassis.moveToPoint(-6, 70, 1000, {.forwards=false, .maxSpeed=40});
    // chassis.moveToPoint(-11, 80, 800, {.maxSpeed=50});
  
  
  
  }