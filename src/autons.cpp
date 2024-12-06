#include "main.h"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"
#include "tasks.hpp"

ASSET(rr_corner1_txt);

void redRush(){
  int SORT_COLOUR = 210;
  // doink the mogo
  intakeLift.set_value(true);
  chassis.moveToPoint(-11, 31, 1100);
  pros::delay(900);
  convDir = FORWARD;
  convVelocity = 70;
  doinker.set_value(true);

  // clamp the mogo
  chassis.moveToPoint(-36, 26, 800, {.forwards = false});
  chassis.moveToPoint(-38, 26, 1000, {.forwards = false, .maxSpeed = 55});
  doinker.set_value(false);
  pros::delay(500);
  clamp.set_value(true);
  convVelocity = 600;

  // get preload and go to corner
  chassis.turnToHeading(160, 600);
  chassis.moveToPoint(-13, -6, 1000, {.minSpeed=60, .earlyExitRange=21});
  chassis.moveToPoint(-3, 0, 500, {.earlyExitRange=15});
  chassis.moveToPoint(25, -15, 1000);
  chassis.moveToPoint(-1, 0, 600, {.forwards = false});

  // diddle
  pros::delay(1200);
  chassis.moveToPoint(37, -25, 1000);
  chassis.moveToPoint(-1, 0, 600, {.forwards = false, .maxSpeed=70});
  pros::delay(1200);
  chassis.moveToPoint(37, -25, 1000);
  chassis.moveToPoint(-1, 0, 600, {.forwards = false, .maxSpeed=70});
  pros::delay(1200);
  chassis.moveToPoint(37, -25, 1000);
  chassis.moveToPoint(-1, 0, 600, {.forwards = false, .maxSpeed=70});
}

void blueRush(){
  int SORT_COLOUR = 20;
  // doink the mogo
  intakeLift.set_value(true);
  chassis.moveToPoint(11, 31, 600, {.minSpeed=60, .earlyExitRange=10});
  chassis.moveToPoint(8, 32, 300);
  convDir = FORWARD;
  convVelocity = 70;
  pros::delay(500);
  doinker.set_value(true);

  // clamp the mogo
  chassis.moveToPoint(36, 26, 800, {.forwards = false});
  chassis.moveToPoint(38, 26, 1000, {.forwards = false, .maxSpeed = 55});
  doinker.set_value(false);
  pros::delay(500);
  clamp.set_value(true);
  convVelocity = 600;

  // get preload and go to corner
  chassis.turnToHeading(160, 600);
  chassis.moveToPoint(13, -6, 1000, {.minSpeed=60, .earlyExitRange=21});
  chassis.moveToPoint(3, 0, 500, {.earlyExitRange=15});
  chassis.moveToPoint(-15, -30, 1000);
  chassis.moveToPoint(1, 0, 600, {.forwards = false});

  // diddle
  pros::delay(1200);
  chassis.moveToPoint(-37, -45, 1000);
  chassis.moveToPoint(1, 0, 600, {.forwards = false, .maxSpeed=70});
  pros::delay(1200);
  chassis.moveToPoint(1, 0, 600, {.forwards = false, .maxSpeed=70});

}

void redRing(){
    
}

void blueRing(){
    
}

void redSoloAWP(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  convVelocity = 180;
  pros::delay(900);
  armToScorePos = true;
  convVelocity = 0;

  // get first mogo 
  pros::delay(900);
  armToScorePos = false;
  chassis.moveToPoint(-15, -20, 700, {.forwards = false});
  chassis.moveToPoint(-17, -27, 750, {.forwards = false, .maxSpeed=50});
  armToStartPos = true;
  pros::delay(700);
  clamp.set_value(true);
  intakeLift.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(180, 700);  
  chassis.moveToPoint(-20, -45, 700);
  chassis.moveToPoint(-20, -43, 200, {.forwards = false});
  chassis.turnToHeading(155, 400);
  chassis.moveToPoint(-16, -50, 700);
  // chassis.moveToPoint(17, -20, 500, {.forwards = false});

  // // get ring 3
  // chassis.turnToHeading(40, 400);
  // chassis.moveToPoint(18, -6, 700);
  

}

void blueSoloAWP(){

}

void autoSkills(){
    
}