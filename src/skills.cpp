#include "lemlib/chassis/chassis.hpp"
#include "skills.hpp"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"
#include "tasks.hpp"

void skillsAuton(){
    // score alliance stake
    doColorSort = false;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    convDir = FORWARD;
    convVelocity = 600;
    pros::delay(300);
    chassis.moveToPoint(0, 12, 800, {.maxSpeed = 80});
  
    // // get first mogo
    chassis.turnToHeading(-88, 700);
    convVelocity = 0;
    chassis.moveToPoint(11, 14, 1000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPoint(20, 14, 750, {.forwards = false, .maxSpeed = 30});
    pros::delay(500);
    clamp.set_value(true);
  
    // // get rings 1 2
    chassis.turnToHeading(7, 800);
    chassis.moveToPoint(23.5, 32, 2000, {.minSpeed = 50, .earlyExitRange = 1});
    convVelocity = 600;
    chassis.moveToPose(33, 45, 45, 4000, {.minSpeed = 50, .earlyExitRange = 1});
    //chassis.moveToPoint(33, 48, 2000, {.minSpeed = 50, .earlyExitRange = 1});
    chassis.moveToPoint(48, 85, 2000);
   
    // ring 3 wallstake
    chassis.moveToPoint(44, 63, 2000, {.forwards = false});
    chassis.turnToHeading(89, 2000);
    armToLoadPos = true;
    chassis.moveToPoint(60, 62, 2000,{.minSpeed = 80, .earlyExitRange = 1});
    pros::delay(2000);
    convVelocity = 0;
    armToLoadPos = false;
    armToScore = true;
    pros::delay(800);
    convVelocity = 600;
    armToScore = false;
    armToStartPos = true;
  
    // // get rings 4 5 6
    // chassis.moveToPoint(50, 59.5, 850, {.forwards = false});
    // chassis.turnToHeading(180, 700);
    // chassis.moveToPoint(51, 4, 400);
    // chassis.moveToPoint(51, 2, 1200, {.maxSpeed = 60});
    // chassis.moveToPoint(51, 0, 1200, {.maxSpeed = 50});
  
    // // get ring 7 and put mogo in corner
    // chassis.turnToHeading(35, 700);
    // chassis.moveToPoint(65, 19, 1000);
    // chassis.turnToHeading(-45, 700);
    // chassis.moveToPoint(72, -2, 600, {.forwards = false});
    // pros::delay(500);
    // clamp.set_value(false);
    // pros::delay(100);
    // arm.move_velocity(0);
    
    // // get second mogo
    // chassis.moveToPoint(54, 12, 500);
    // chassis.turnToHeading(90, 600);
    // chassis.moveToPoint(-22, 11, 1000, {.forwards = false, .maxSpeed = 100});
    // chassis.moveToPoint(-32, 11, 1000, {.forwards = false, .maxSpeed = 30});
    // pros::delay(950);
    // clamp.set_value(true);
  
  
    // // get rings 8 9
    // chassis.turnToHeading(7, 500);
    // chassis.moveToPoint(-22, 39, 400, {.earlyExitRange = 10});
    // chassis.moveToPoint(-40, 50, 650, {.earlyExitRange = 8});
    // chassis.moveToPoint(-44, 83, 800);
  
    // // wallstake ring 10
    // chassis.turnToHeading(-160, 500);
    // chassis.moveToPoint(-51, 60, 1400, {.maxSpeed = 100});
    // armToLoadPos = true;
    // chassis.turnToHeading(-90, 600);
    // chassis.moveToPoint(-70, 60, 600);
    // pros::delay(1400);
    // convVelocity = 0;
    // armToLoadPos = false;
    // armToScore = true;
  
    // // get rings 11 12 13
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
    // arm.move_velocity(0);
    // chassis.turnToHeading(-45, 700);
    // chassis.moveToPoint(-57, 15, 1300);
    // chassis.turnToHeading(45, 700);
    // chassis.moveToPoint(-63, 2, 500, {.forwards = false});
    // pros::delay(500);
    // clamp.set_value(false);
    // pros::delay(100);
  
    // // get ring 15 
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