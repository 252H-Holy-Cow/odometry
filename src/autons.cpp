#include "main.h"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"
#include "tasks.hpp"

ASSET(rr_corner1_txt);

void redRush(){
  // rush mogo
  intakeLift.set_value(true);
  doinker.set_value(true);
  convDir = FIRST;
  convVelocity = 600;
  conveyor.move_velocity(600);
  chassis.moveToPoint(-1.5, 33, 975);
  pros::delay(875);
  rushMech.set_value(true);

  // go back
  chassis.moveToPoint(2, 10, 1000, {.forwards = false});
  pros::delay(750);
  rushMech.set_value(false);
  pros::delay(150);
  doinker.set_value(false);

  // clamp mogo and score ring 1
  chassis.turnToHeading(195, 800);
  chassis.moveToPoint(5, 42, 2400, {.forwards = false, .maxSpeed=55});
  pros::delay(1200);
  clamp.set_value(true);
  convDir = STOP;
  convDir = FORWARD;
  pros::delay(1200);
  chassis.moveToPoint(4, 35, 800);
  chassis.turnToHeading(-60, 700);
  pros::delay(600);
  clamp.set_value(false);

  // get mogo 2
  chassis.turnToHeading(110, 700);
  chassis.moveToPoint(-28, 40, 500, {.forwards = false, .earlyExitRange=8});
  chassis.moveToPoint(-28, 35, 600, {.forwards = false, .maxSpeed=40});
  pros::delay(500);
  clamp.set_value(true);

  // go to corner
  chassis.turnToHeading(160, 700);
  chassis.moveToPoint(1, -14, 1000, {.maxSpeed=100});
  chassis.moveToPoint(1, -14, 1400, {.maxSpeed=50});
  chassis.moveToPoint(-5, 8, 1300, {.forwards=false});

  // ending
  chassis.turnToHeading(140, 700);
  pros::delay(1000);
  clamp.set_value(false);
  chassis.turnToHeading(230, 700);
}

void blueRush(){
  // rush mogo
  intakeLift.set_value(true);
  doinker.set_value(true);
  convDir = FIRST;
  convVelocity = 600;
  conveyor.move_velocity(600);
  chassis.moveToPoint(-1.5, 33, 975);
  pros::delay(875);
  rushMech.set_value(true);

  // go back
  chassis.moveToPoint(2, 10, 1000, {.forwards = false});
  pros::delay(750);
  rushMech.set_value(false);
  pros::delay(150);
  doinker.set_value(false);

  // clamp mogo and score ring 1
  chassis.turnToHeading(180, 800);
  chassis.moveToPoint(4, 42, 2400, {.forwards = false, .maxSpeed=55});
  pros::delay(1200);
  clamp.set_value(true);
  convDir = STOP;
  convDir = FORWARD;
  pros::delay(1200);
  chassis.moveToPoint(-2, 38, 800);
  chassis.turnToHeading(90, 700);
  pros::delay(600);
  clamp.set_value(false);

  // get mogo 2
  chassis.turnToHeading(-30, 700);
  chassis.moveToPoint(15, 20, 1500, {.forwards = false, .maxSpeed=60});
  pros::delay(1200);
  clamp.set_value(true);

  // get to corner
  chassis.turnToHeading(-110, 700);
  chassis.moveToPoint(-4, 16, 500, {.maxSpeed=100});
  pros::delay(1200);
  chassis.moveToPoint(-35, -1, 1400, {.maxSpeed=100});

  // back up
  chassis.moveToPoint(4, 18, 1500, {.forwards = false, .maxSpeed=50});
  pros::delay(1500);
  clamp.set_value(false);

}

void redRing(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  convVelocity = 180;
  pros::delay(900);
  chassis.moveToPoint(0, 4.5, 400);
  convVelocity = 0;
  pros::delay(100);
  armToScorePos = true;

  // get first mogo 
  pros::delay(900);
  armToScorePos = false;
  chassis.moveToPoint(0, -25, 500, {.forwards = false});
  chassis.moveToPoint(-1, -29, 400, {.forwards = false, .maxSpeed=50});
  armToStartPos = true;
  pros::delay(400);
  clamp.set_value(true);
  intakeLift.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(160, 700);
  chassis.moveToPoint(6, -46.5, 800);
  chassis.moveToPoint(9, -43, 800, {.forwards = false});
  chassis.turnToHeading(115, 500);
  chassis.moveToPoint(14.5, -55.5, 900);
  chassis.moveToPoint(10, -50, 800, {.forwards = false});

  // get ring 3
  chassis.turnToHeading(45, 500);
  chassis.moveToPoint(24, -38, 600, {.maxSpeed=80});
  pros::delay(800);

  // get corner ring
  chassis.moveToPoint(26, -44, 600, {.forwards = false, .maxSpeed = 100});
  pros::delay(200);
  chassis.moveToPoint(67, -10, 700);
  chassis.moveToPoint(68, -7, 1200);
  pros::delay(400);
  chassis.moveToPoint(41, -12, 900, {.forwards = false, .maxSpeed = 40});

  // get middle ring
  chassis.turnToHeading(295, 700);
  chassis.moveToPoint(-11, 5, 900);
  pros::delay(200);
  intakeLift.set_value(false);
  chassis.moveToPoint(-11, 5, 700, {.maxSpeed = 60});
  pros::delay(800);
  intakeLift.set_value(true);
  chassis.moveToPoint(7, -3, 1500, {.forwards = false, .maxSpeed = 25});




}

void blueRing(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  convVelocity = 180;
  pros::delay(900);
  chassis.moveToPoint(0, 4.5, 400);
  convVelocity = 0;
  pros::delay(100);
  armToScorePos = true;

  // get first mogo 
  pros::delay(900);
  armToScorePos = false;
  chassis.moveToPoint(0, -25, 500, {.forwards = false});
  chassis.moveToPoint(1, -29, 400, {.forwards = false, .maxSpeed=50});
  armToStartPos = true;
  pros::delay(400);
  clamp.set_value(true);
  intakeLift.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(-160, 700);
  chassis.moveToPoint(-6, -46.5, 800);
  chassis.moveToPoint(-9, -43, 800, {.forwards = false});
  chassis.turnToHeading(-115, 500);
  chassis.moveToPoint(-14.5, -55.5, 900);
  chassis.moveToPoint(-10, -50, 800, {.forwards = false});

  // get ring 3
  chassis.turnToHeading(-45, 500);
  chassis.moveToPoint(-24, -38, 600, {.maxSpeed=80});
  pros::delay(800);

  // get corner ring
  chassis.moveToPoint(-26, -44, 600, {.forwards = false, .maxSpeed = 100});
  pros::delay(200);
  chassis.moveToPoint(-67, -10, 700);
  chassis.moveToPoint(-68, -7, 1200);
  pros::delay(400);
  chassis.moveToPoint(-41, -12, 900, {.forwards = false, .maxSpeed = 40});

  // get middle ring
  chassis.turnToHeading(-295, 700);
  chassis.moveToPoint(11, 5, 900);
  pros::delay(200);
  intakeLift.set_value(false);
  chassis.moveToPoint(11, 5, 700, {.maxSpeed = 60});
  pros::delay(800);
  intakeLift.set_value(true);
  chassis.moveToPoint(-7, -3, 1500, {.forwards = false, .maxSpeed = 25});

}

void redSoloAWP(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  convVelocity = 180;
  pros::delay(900);
  chassis.moveToPoint(0, 4.5, 400);
  convVelocity = 0;
  pros::delay(100);
  armToScorePos = true;

  // get first mogo 
  pros::delay(900);
  armToScorePos = false;
  chassis.moveToPoint(0, -25, 500, {.forwards = false});
  chassis.moveToPoint(-1, -29, 400, {.forwards = false, .maxSpeed=50});
  armToStartPos = true;
  pros::delay(400);
  clamp.set_value(true);
  intakeLift.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(160, 700);
  chassis.moveToPoint(6, -46.5, 800);
  chassis.moveToPoint(9, -43, 800, {.forwards = false});
  chassis.turnToHeading(115, 500);
  chassis.moveToPoint(14.5, -55.5, 900);

  // get ring 3 4
  chassis.turnToHeading(50, 500);
  chassis.moveToPoint(24, -36, 1000, {.maxSpeed=80});
  pros::delay(800);
  doColorSort = false;
  chassis.moveToPoint(-7, -4, 700);
  pros::delay(950);
  clamp.set_value(false);
  chassis.moveToPoint(-28, 4, 1000);

  // get mogo and touch ladder
  chassis.moveToPoint(-61, 4, 1250);
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
  chassis.moveToPoint(0, 4.5, 400);
  convVelocity = 0;
  pros::delay(100);
  armToScorePos = true;

  // get first mogo 
  pros::delay(900);
  armToScorePos = false;
  chassis.moveToPoint(0, -25, 500, {.forwards = false});
  chassis.moveToPoint(1, -29, 400, {.forwards = false, .maxSpeed=50});
  armToStartPos = true;
  pros::delay(400);
  clamp.set_value(true);
  intakeLift.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(-160, 700);
  chassis.moveToPoint(-6, -46.5, 800);
  chassis.moveToPoint(-9, -43, 800, {.forwards = false});
  chassis.turnToHeading(-115, 500);
  chassis.moveToPoint(-14.5, -55.5, 900);

  // get ring 3 4
  chassis.turnToHeading(-50, 500);
  chassis.moveToPoint(-24, -36, 1000, {.maxSpeed=80});
  pros::delay(800);
  doColorSort = false;
  chassis.moveToPoint(7, -4, 700);
  pros::delay(950);
  clamp.set_value(false);
  chassis.moveToPoint(28, 4, 1000);

  // get mogo and touch ladder
  chassis.moveToPoint(61, 4, 1250);
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
  intakeLift.set_value(true);
  doColorSort = false;
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  convDir = FORWARD;
  convVelocity = 600;
  pros::delay(300);
  chassis.moveToPoint(0, 15, 1000, {.maxSpeed = 40});
  chassis.turnToHeading(-90, 600);
  chassis.moveToPoint(24, 15, 300, {.forwards = false});
  chassis.moveToPoint(24, 15, 400, {.forwards = false, .maxSpeed = 50});
  pros::delay(400);
  clamp.set_value(true);

  // get rings 1 2
  chassis.turnToHeading(10, 500);
  chassis.moveToPoint(24, 39, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(40, 53, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(43, 86, 850);

  // wallstake ring 3
  pros::delay(800);
  armToLoadPos = true;
  chassis.turnToHeading(160, 500);
  chassis.moveToPoint(55, 69, 1400, {.maxSpeed = 60});
  chassis.turnToHeading(90, 600);
  chassis.moveToPoint(70, 68, 600);
  pros::delay(1200);
  convVelocity = 0;
  armToScorePos = true;

  // get rings 4 5 6
  pros::delay(800);
  armToScorePos = false;
  armToStartPos = true;
  chassis.moveToPoint(50, 65, 850, {.forwards = false});
  convVelocity = 600;
  chassis.turnToHeading(180, 700);
  chassis.moveToPoint(51, 4, 400);
  armToStartPos = true;
  chassis.moveToPoint(51, 4, 1200, {.maxSpeed = 60});
  chassis.moveToPoint(51, 4, 1200, {.maxSpeed = 30});

  // get ring 7 and put mogo in corner
  chassis.turnToHeading(45, 700);
  chassis.moveToPoint(65, 15, 1000);
  chassis.turnToHeading(-45, 700);
  chassis.moveToPoint(72, 2, 500, {.forwards = false});
  pros::delay(500);
  clamp.set_value(false);
  pros::delay(100);
  
  // get second mogo
  chassis.moveToPoint(54, 12, 500);
  chassis.turnToHeading(90, 600);
  chassis.moveToPoint(-26, 13, 1200, {.forwards = false, .maxSpeed = 100});
  chassis.moveToPoint(-32, 15, 850, {.forwards = false, .maxSpeed = 50});
  pros::delay(800);
  clamp.set_value(true);

  // get rings 8 9
  chassis.turnToHeading(10, 500);
  chassis.moveToPoint(-20, 39, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(-39, 53, 650, {.earlyExitRange = 8});
  chassis.moveToPoint(-44, 83, 800);

  // wallstake ring 10
  pros::delay(800);
  armToLoadPos = true;
  chassis.turnToHeading(-160, 500);
  chassis.moveToPoint(-51, 66, 1300, {.maxSpeed = 60});
  chassis.turnToHeading(-90, 600);
  chassis.moveToPoint(-70, 65, 600);
  pros::delay(1400);
  convVelocity = 0;
  armToScorePos = true;

  // get rings 11 12 13
  pros::delay(800);
  // chassis.moveToPoint(70, 69, 300);
  chassis.moveToPoint(-40, 65, 850, {.forwards = false});
  armToScorePos = false;
  armToStartPos = true;
  convVelocity = 600;
  chassis.turnToHeading(200, 700);
  chassis.moveToPoint(-44, 4, 400);
  armToStartPos = true;
  chassis.moveToPoint(-44, 4, 1200, {.maxSpeed = 60});
  chassis.moveToPoint(-44, 4, 1200, {.maxSpeed = 30});

  // get ring 14 and put mogo in corner
  chassis.turnToHeading(-45, 700);
  chassis.moveToPoint(-57, 15, 1300);
  chassis.turnToHeading(45, 700);
  chassis.moveToPoint(-63, 2, 500, {.forwards = false});
  pros::delay(500);
  clamp.set_value(false);
  pros::delay(100);

  // get ring 15 
  chassis.turnToHeading(5, 300);
  convDir = STOP;
  convDir = FIRST;
  chassis.moveToPoint(-38, 83, 700, {.earlyExitRange = 10});
  chassis.moveToPoint(-21, 84, 1000);

  // get mogo 3
  chassis.turnToHeading(205, 700);
  chassis.moveToPoint(4, 112, 500, {.forwards = false});
  pros::delay(500);
  chassis.moveToPoint(4, 112, 700, {.forwards = false, .maxSpeed = 50});
  pros::delay(700);
  clamp.set_value(true);

  // get rings 16 17 and 18
  doColorSort = true;
  convDir = STOP;
  convDir = FORWARD;
  chassis.moveToPoint(-58, 106, 1000);
  chassis.moveToPoint(-58, 104, 1400, {.maxSpeed=50});
  chassis.moveToPoint(-36, 104, 1000, {.forwards = false});
  chassis.moveToPoint(-43, 120, 1400);
  
  // get rings 19 20 and 21
  chassis.turnToHeading(100, 700);
  chassis.moveToPoint(20, 106, 1000, {.earlyExitRange = 8});
  chassis.moveToPoint(23, 89, 1200);
  chassis.turnToHeading(40, 500);
  chassis.moveToPoint(45, 105, 500, {.earlyExitRange = 8});
  chassis.moveToPoint(45, 120, 1000);

  // put mogo 3 in corner 
  chassis.turnToHeading(260, 700);
  chassis.moveToPoint(56, 128, 800, {.forwards = false});
  pros::delay(500);
  clamp.set_value(false);
  chassis.moveToPoint(60, 128, 600, {.forwards = false});

  // get mogo 4
  chassis.moveToPoint(0, 100, 1000, {.earlyExitRange = 8});
  chassis.turnToHeading(110, 700);
  chassis.moveToPoint(-22, 120, 500, {.forwards = false});
  chassis.moveToPoint(-22, 120, 800, {.forwards = false, .maxSpeed = 50});
  pros::delay(800);
  clamp.set_value(true);

  // put mogo 4 in corner
  chassis.turnToHeading(80, 400);
  chassis.moveToPoint(-65, 105, 500, {.forwards = false, .earlyExitRange = 10});
  chassis.moveToPoint(-70, 130, 1000, {.forwards = false});
  pros::delay(900);
  clamp.set_value(false);

  chassis.moveToPoint(-53, 106, 1000);




}