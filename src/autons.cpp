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
  convVelocity = 60;
  pros::delay(500);
  doinker.set_value(true);

  // clamp the mogo
  chassis.moveToPoint(36, 26, 800, {.forwards = false});
  chassis.moveToPoint(40, 26, 1000, {.forwards = false, .maxSpeed = 55});
  doinker.set_value(false);
  pros::delay(450);
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
  chassis.moveToPoint(-37, -45, 1000);
  chassis.moveToPoint(1, 0, 600, {.forwards = false, .maxSpeed=70});
  pros::delay(1200);
  chassis.moveToPoint(1, 0, 600, {.forwards = false, .maxSpeed=70});

}

void redRing(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  convVelocity = 180;
  pros::delay(900);
  chassis.moveToPoint(0, 4.5, 300);
  convVelocity = 0;
  pros::delay(100);
  armToScorePos = true;

  // get first mogo 
  pros::delay(900);
  armToScorePos = false;
  chassis.moveToPoint(0, -25, 600, {.forwards = false});
  chassis.moveToPoint(0, -29, 300, {.forwards = false, .maxSpeed=50});
  armToStartPos = true;
  pros::delay(400);
  clamp.set_value(true);
  intakeLift.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  convVelocity = 600;
  chassis.turnToHeading(160, 700);
  chassis.moveToPoint(7, -47, 800);
  // pros::delay(500);
  chassis.moveToPoint(9, -43, 500, {.forwards = false});
  // pros::delay(500);
  chassis.turnToHeading(125, 500);
  chassis.moveToPoint(12, -54, 800);

  // get ring 3
  chassis.turnToHeading(40, 500);
  chassis.moveToPoint(16, -35, 800);

}

void blueRing(){
    
}

void redSoloAWP(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  convVelocity = 180;
  pros::delay(900);
  chassis.moveToPoint(0, 4.5, 300);
  convVelocity = 0;
  pros::delay(100);
  armToScorePos = true;

  // get first mogo 
  pros::delay(900);
  armToScorePos = false;
  chassis.moveToPoint(0, -25, 600, {.forwards = false});
  chassis.moveToPoint(-1, -29, 300, {.forwards = false, .maxSpeed=50});
  armToStartPos = true;
  pros::delay(400);
  clamp.set_value(true);
  intakeLift.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(160, 700);
  chassis.moveToPoint(7, -47, 800);
  // pros::delay(500);
  chassis.moveToPoint(9, -43, 500, {.forwards = false});
  // pros::delay(500);
  chassis.turnToHeading(125, 500);
  chassis.moveToPoint(12, -54, 800);

  // get ring 3 4
  chassis.turnToHeading(45, 500);
  chassis.moveToPoint(18, -35, 1000, {.maxSpeed=80});
  pros::delay(800);
  doColorSort = false;
  chassis.moveToPoint(-7, -4, 700);
  pros::delay(950);
  clamp.set_value(false);
  chassis.moveToPoint(-28, 4, 1000);

  // get mogo mech and touch ladder
  chassis.moveToPoint(-60, 2, 1200);
  pros::delay(1520);
  convVelocity = 0;
  pros::delay(300);
  chassis.turnToHeading(-65, 400);
  chassis.moveToPoint(-41, -12, 1000, {.forwards = false, .maxSpeed=80});
  pros::delay(900);
  clamp.set_value(true);
  pros::delay(200);
  convVelocity = 600;
  chassis.turnToHeading(165, 1000, {.maxSpeed = 80});
  pros::delay(200);
  arm.move_velocity(65);
}

void blueSoloAWP(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  convVelocity = 180;
  pros::delay(900);
  chassis.moveToPoint(0, 4.5, 300);
  convVelocity = 0;
  pros::delay(100);
  armToScorePos = true;

  // get first mogo 
  pros::delay(900);
  armToScorePos = false;
  chassis.moveToPoint(0, -25, 600, {.forwards = false});
  chassis.moveToPoint(3, -29, 300, {.forwards = false, .maxSpeed=50});
  armToStartPos = true;
  pros::delay(400);
  clamp.set_value(true);
  intakeLift.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(-160, 700);
  chassis.moveToPoint(-7, -48, 800);
  // pros::delay(500);
  chassis.moveToPoint(-9, -43, 500, {.forwards = false});
  // pros::delay(500);
  chassis.turnToHeading(-125, 500);
  chassis.moveToPoint(-12, -54, 800);

  // get ring 3 4
  chassis.turnToHeading(-40, 500);
  chassis.moveToPoint(-18, -35, 1000, {.maxSpeed=80});
  pros::delay(800);
  doColorSort = false;
  chassis.moveToPoint(7, -4, 700);
  pros::delay(850);
  clamp.set_value(false);
  chassis.moveToPoint(28, 4, 1000);

  // get mogo mech and touch ladder
  chassis.moveToPoint(60, 2, 1200);
  pros::delay(1520);
  convVelocity = 0;
  pros::delay(300);
  chassis.turnToHeading(65, 400);
  chassis.moveToPoint(41, -12, 1000, {.forwards = false, .maxSpeed=80});
  pros::delay(900);
  clamp.set_value(true);
  pros::delay(200);
  convVelocity = 600;
  chassis.turnToHeading(-165, 1000, {.maxSpeed = 80});
  pros::delay(200);
  arm.move_velocity(65);
}

void autoSkills(){
  // score alliance stake and get first mogo
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  convDir = FORWARD;
  convVelocity = 600;
  pros::delay(400);
  intakeLift.set_value(true);
  chassis.moveToPoint(0, 15, 1200, {.maxSpeed = 40});
  chassis.turnToHeading(-90, 600);
  chassis.moveToPoint(24, 15, 300, {.forwards = false});
  chassis.moveToPoint(24, 15, 400, {.forwards = false, .maxSpeed = 50});
  pros::delay(400);
  clamp.set_value(true);

  // get rings 1 2
  chassis.turnToHeading(20, 500);
  chassis.moveToPoint(24, 39, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(36, 53, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(46, 87, 1000);

  // wallstake ring 3
  chassis.turnToHeading(160, 500);
  chassis.moveToPoint(58, 67, 1200, {.maxSpeed = 60});
  pros::delay(800);
  armToLoadPos = true;
  chassis.turnToHeading(90, 600);
  chassis.moveToPoint(70, 67, 600);
  pros::delay(1000);
  convVelocity = 0;
  armToScorePos = true;

  // get rings 4 5 6
  pros::delay(800);
  chassis.moveToPoint(70, 67, 300);
  chassis.moveToPoint(51, 67, 800, {.forwards = false});
  armToScorePos = false;
  armToStartPos = true;
  convVelocity = 600;
  chassis.turnToHeading(180, 700);
  chassis.moveToPoint(54, 4, 400);
  armToStartPos = true;
  chassis.moveToPoint(54, 4, 1200, {.maxSpeed = 60});
  chassis.moveToPoint(54, 4, 1200, {.maxSpeed = 30});

  // get ring 7 and put mogo in corner
  chassis.turnToHeading(45, 700);
  chassis.moveToPoint(61, 14, 1000);
  chassis.turnToHeading(-45, 700);
  chassis.moveToPoint(72, 2, 500, {.forwards = false});
  pros::delay(500);
  clamp.set_value(false);
  pros::delay(100);
  

  // get second mogo
  chassis.moveToPoint(54, 12, 500);
  chassis.turnToHeading(90, 600);
  chassis.moveToPoint(-26, 12, 1050, {.forwards = false});
  chassis.moveToPoint(-28, 14, 600, {.forwards = false, .maxSpeed = 50});
  pros::delay(800);
  clamp.set_value(true);

  // get rings 8 9
  chassis.turnToHeading(20, 500);
  chassis.moveToPoint(-22, 39, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(-40, 53, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(-44, 87, 1000);

  // wallstake ring 10
  chassis.turnToHeading(-160, 500);
  chassis.moveToPoint(-54, 58.5, 1300, {.maxSpeed = 60});
  pros::delay(800);
  armToLoadPos = true;
  chassis.turnToHeading(-90, 600);
  chassis.moveToPoint(-70, 58.5, 600);
  pros::delay(1000);
  convVelocity = 0;
  armToScorePos = true;

  // get rings 11 12 13
  pros::delay(800);
  chassis.moveToPoint(-70, 58.5, 300);
  chassis.moveToPoint(-43, 58.5, 900, {.forwards = false});
  armToScorePos = false;
  armToStartPos = true;
  convVelocity = 600;
  chassis.turnToHeading(-180, 700);
  chassis.moveToPoint(-43, 4, 400);
  armToStartPos = true;
  chassis.moveToPoint(-43, 4, 1200, {.maxSpeed = 60});
  armToStartPos = true;
  chassis.moveToPoint(-43, 4, 1200, {.maxSpeed = 30});

  // get ring 14 and put mogo in corner
  chassis.turnToHeading(-45, 700);
  chassis.moveToPoint(-51, 11, 800);
  chassis.turnToHeading(45, 700);
  chassis.moveToPoint(-57, 4, 500, {.forwards = false});
  pros::delay(500);
  clamp.set_value(false);
  pros::delay(200);

  // get ring 15
  chassis.moveToPoint(-48, 70, 1200, {.earlyExitRange = 16});
  chassis.moveToPoint(-10, 95, 1000);


}