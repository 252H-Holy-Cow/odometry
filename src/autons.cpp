#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"
#include "tasks.hpp"

ASSET(rr_corner1_txt);

void redRush(){
  // rush mogo
  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  doinker.set_value(true);
  convDir = FIRST;
  convVelocity = 600;
  conveyor.move_velocity(600);
  chassis.moveToPoint(1, 34, 995);
  pros::delay(900);
  rushMech.set_value(true);

  // go back
  chassis.moveToPoint(-10, 5, 1300, {.forwards = false});
  pros::delay(1300);
  convDir = STOP;
  rushMech.set_value(false);
  doinker.set_value(false);

  // get second mogo
  chassis.turnToHeading(150, 600);
  chassis.moveToPoint(-24, 35, 550, {.forwards = false});
  chassis.moveToPoint(-28, 36, 900, {.forwards = false, .maxSpeed=40});
  pros::delay(800);
  clamp.set_value(true);

  // go to corner
  convDir = FORWARD;
  chassis.turnToHeading(180, 600);
  chassis.moveToPoint(0, -10, 950, {.earlyExitRange=5});
  pros::delay(100);
  doinker.set_value(true);
  chassis.moveToPoint(2, -12, 500, {.maxSpeed=40});

  // clear corner with doinker
  convDir=STOP;
  chassis.turnToHeading(20, 800);
  pros::delay(800);
  doinker.set_value(false);
  convDir=FIRST;

  // get corner ring 1
  chassis.moveToPoint(-1, 18, 800, {.maxSpeed=60});
  clamp.set_value(false);

  // get mogo 2
  chassis.turnToHeading(275, 700);




}

void blueRush(){
  // rush mogo
  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  doinker.set_value(true);
  convDir = FIRST;
  convVelocity = 600;
  conveyor.move_velocity(600);
  chassis.moveToPoint(1, 34, 995);
  pros::delay(900);
  rushMech.set_value(true);

  // go back
  chassis.moveToPoint(-5, 15, 1000, {.forwards = false});
  chassis.turnToHeading(-80, 500);
  chassis.moveToPoint(10, 3, 800, {.forwards = false});
  pros::delay(700);
  rushMech.set_value(false);
  chassis.turnToHeading(-120, 700);
  pros::delay(700);
  doinker.set_value(false);

  // get mogo 2
  chassis.moveToPoint(18, 21, 1600, {.forwards = false, .maxSpeed=70});
  pros::delay(1000);
  clamp.set_value(true);
  convDir = STOP;
  convDir = FORWARD;
  pros::delay(500);
  convDir = STOP;

  // get to corner
  chassis.turnToHeading(-120, 700);
  chassis.moveToPoint(-15, 10, 800);

  // doinker rings
  doinker.set_value(true);
  chassis.moveToPoint(-35, -8, 1000);
  chassis.turnToHeading(80, 700);

  // get rings
  chassis.turnToHeading(300, 700);
  doinker.set_value(false);


  // back up
  chassis.moveToPoint(-6, 8, 800, {.forwards = false, .maxSpeed=50});
  pros::delay(500);
  clamp.set_value(false);
  chassis.turnToHeading(220, 600);
  chassis.moveToPoint(-3, 34, 1200, {.forwards = false, .maxSpeed=60});
  pros::delay(1150);
  clamp.set_value(true);
  convDir = FORWARD;


  

}

void redSAWP(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  pros::delay(100);
  convVelocity = 180;
  pros::delay(900);
  chassis.moveToPoint(0, 8, 600);
  convVelocity = 0;
  pros::delay(100);
  armToLoadPos = false;
  pros::delay(200);
  armToScore = true;

  // get first mogo 
  pros::delay(900);
  armToScore = false;
  chassis.moveToPoint(0, -25, 500, {.forwards = false});
  chassis.moveToPoint(-1, -29, 650, {.forwards = false, .maxSpeed=50});
  convDir = STOP;
  armToStartPos = true;
  pros::delay(650);
  clamp.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(160, 700);
  convDir = FORWARD;
  chassis.moveToPoint(7, -50, 800);
  chassis.turnToHeading(115, 300);
  chassis.moveToPoint(16.5, -57, 800);
  chassis.moveToPoint(10, -50, 800, {.forwards = false});

  // get ring 3
  chassis.turnToHeading(45, 500);
  chassis.moveToPoint(24, -38, 600, {.maxSpeed=80});
  pros::delay(800);

  // get ring 4
  doColorSort = false;
  chassis.moveToPoint(-7, -4, 700);
  pros::delay(850);
  clamp.set_value(false);
  chassis.moveToPoint(-28, 4, 1000);

  // get mogo
  chassis.moveToPoint(-60, 2, 1200);
  pros::delay(1520);
  convVelocity = 0;
  pros::delay(300);
  chassis.turnToHeading(-65, 400);
  chassis.moveToPoint(-45, -11, 1000, {.forwards = false, .maxSpeed=80});
  pros::delay(900);
  clamp.set_value(true);

  // touch ladder
  pros::delay(200);
  convVelocity = 600;
  chassis.turnToHeading(165, 1000, {.maxSpeed = 80});
  armToStartPos = false;
  pros::delay(200);
  arm.move_velocity(70);





}

void blueSAWP(){
  // score alliance stake
  convDir = FORWARD;
  armToLoadPos = true;
  convVelocity = 180;
  pros::delay(900);
  chassis.moveToPoint(0, 8, 600);
  convVelocity = 0;
  pros::delay(100);
  armToLoadPos = false;
  armToScore = true;

  // get first mogo 
  pros::delay(900);
  armToScore = false;
  chassis.moveToPoint(0, -25, 500, {.forwards = false});
  chassis.moveToPoint(1, -29, 650, {.forwards = false, .maxSpeed=50});
  convDir = STOP;
  armToStartPos = true;
  pros::delay(650);
  clamp.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(-160, 700);
  convDir = FORWARD;
  chassis.moveToPoint(-7, -50, 800);
  chassis.turnToHeading(-115, 300);
  chassis.moveToPoint(-16.5, -57, 800);
  chassis.moveToPoint(-10, -50, 800, {.forwards = false});

  // get ring 3
  chassis.turnToHeading(-45, 500);
  chassis.moveToPoint(-24, -38, 600, {.maxSpeed=80});
  pros::delay(800);

  // get ring 4
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

void redRing(){
  // score alliance stake
  armToLoadPos = true;
  pros::delay(100);
  convDir = FORWARD;
  convVelocity = 600;
  // pros::delay(300);
  chassis.moveToPoint(0, 4.5, 650);
  pros::delay(600);
  armToLoadPos = false;
  pros::delay(200);
  convVelocity = 0;
  armToScore = true;

  // get first mogo 
  pros::delay(1200);
  armToScore = false;
  chassis.moveToPoint(0, -27, 450, {.forwards = false});
  chassis.moveToPoint(-1, -31, 700, {.forwards = false, .maxSpeed=50});
  convDir = STOP;
  armToStartPos = true;
  pros::delay(700);
  clamp.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(160, 700);

  chassis.moveToPoint(7, -49, 650, {.earlyExitRange = 8});
  convDir = FORWARD;
  // chassis.turnToHeading(115, 300);
  chassis.moveToPoint(26, -62, 1250, {.maxSpeed=75});
  pros::delay(400);

  // get ring 3
  chassis.moveToPoint(10, -50, 800, {.forwards = false});
  chassis.turnToHeading(50, 550, {.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
  chassis.moveToPoint(25, -38, 600, {.maxSpeed=80});
  pros::delay(500);

  // get corner ring
  // chassis.moveToPoint(26, -48, 800, {.forwards = false, .maxSpeed = 50});
  // pros::delay(200);
  // chassis.moveToPoint(15, -30, 700);
  chassis.moveToPoint(68, -5, 1500, {.maxSpeed=20});
  chassis.moveToPoint(68, -5, 1000, {.maxSpeed=80});
  pros::delay(400);
  chassis.moveToPoint(41, -12, 900, {.forwards = false, .maxSpeed = 40});

  // get middle ring
  chassis.turnToHeading(295, 700);
  chassis.moveToPoint(-11, 0, 700);
  pros::delay(125);
  intakeLift.set_value(true);
  chassis.moveToPoint(-6, -1, 900, {.maxSpeed = 40});
  chassis.moveToPoint(7, -3, 1500, {.forwards = false, .maxSpeed = 45});
  // pros::delay(300);
  intakeLift.set_value(false);
}

void blueRing(){
  // score alliance stake
  armToLoadPos = true;
  pros::delay(100);
  convDir = FORWARD;
  convVelocity = 600;
  // pros::delay(300);
  chassis.moveToPoint(0, 4.5, 650);
  pros::delay(600);
  armToLoadPos = false;
  pros::delay(200);
  convVelocity = 0;
  armToScore = true;

  // get first mogo 
  pros::delay(1200);
  armToScore = false;
  chassis.moveToPoint(0, -27, 450, {.forwards = false});
  chassis.moveToPoint(1, -31, 700, {.forwards = false, .maxSpeed=50});
  convDir = STOP;
  armToStartPos = true;
  pros::delay(700);
  clamp.set_value(true);
  convVelocity = 600;

  // get ring 1 2
  chassis.turnToHeading(-160, 700);

  chassis.moveToPoint(-7, -49, 650, {.earlyExitRange = 8});
  convDir = FORWARD;
  // chassis.turnToHeading(115, 300);
  chassis.moveToPoint(-26, -62, 1250, {.maxSpeed=75});
  pros::delay(400);

  // get ring 3
  chassis.moveToPoint(-10, -50, 800, {.forwards = false});
  chassis.turnToHeading(-50, 550, {.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
  chassis.moveToPoint(-25, -38, 600, {.maxSpeed=80});
  pros::delay(500);

  // get corner ring
  // chassis.moveToPoint(26, -48, 800, {.forwards = false, .maxSpeed = 50});
  // pros::delay(200);
  // chassis.moveToPoint(15, -30, 700);
  chassis.moveToPoint(-68, -5, 1500, {.maxSpeed=20});
  chassis.moveToPoint(-68, -5, 1000, {.maxSpeed=80});
  pros::delay(400);
  chassis.moveToPoint(-41, -12, 900, {.forwards = false, .maxSpeed = 40});

  // get middle ring
  chassis.turnToHeading(-295, 700);
  chassis.moveToPoint(11, 0, 700);
  pros::delay(125);
  intakeLift.set_value(true);
  chassis.moveToPoint(6, -1, 900, {.maxSpeed = 40});
  chassis.moveToPoint(-7, -3, 1500, {.forwards = false, .maxSpeed = 45});
  // pros::delay(300);
  intakeLift.set_value(false);
}

void autoSkills(){
  // score alliance stake
  doColorSort = false;
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  convDir = FORWARD;
  convVelocity = 600;
  pros::delay(300);
  chassis.moveToPoint(0, 15, 1000, {.maxSpeed = 40});

  // get first mogo
  chassis.turnToHeading(-90, 600);
  chassis.moveToPoint(24, 15, 300, {.forwards = false});
  chassis.moveToPoint(26, 13, 550, {.forwards = false, .maxSpeed = 50});
  pros::delay(500);
  clamp.set_value(true);

  // get rings 1 2
  chassis.turnToHeading(7, 500);
  chassis.moveToPoint(22, 39, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(40, 53, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(43, 82, 700);

  // wallstake ring 3
  chassis.turnToHeading(160, 500);
  chassis.moveToPoint(55, 59.5, 1400, {.maxSpeed = 100});
  armToLoadPos = true;
  chassis.turnToHeading(90, 600);
  chassis.moveToPoint(70, 59.5, 600);   
  pros::delay(1200);
  convVelocity = 0;
  armToLoadPos = false;
  armToScore = true;

  // get rings 4 5 6
  pros::delay(800);
  armToScore = false;
  armToStartPos = true;
  chassis.moveToPoint(50, 59.5, 850, {.forwards = false});
  convVelocity = 600;
  chassis.turnToHeading(180, 700);
  chassis.moveToPoint(51, 4, 400);
  armToStartPos = true;
  chassis.moveToPoint(51, 2, 1200, {.maxSpeed = 60});
  chassis.moveToPoint(51, 0, 1200, {.maxSpeed = 50});

  // get ring 7 and put mogo in corner
  chassis.turnToHeading(35, 700);
  chassis.moveToPoint(65, 19, 1000);
  chassis.turnToHeading(-45, 700);
  chassis.moveToPoint(72, -2, 600, {.forwards = false});
  pros::delay(500);
  clamp.set_value(false);
  pros::delay(100);
  arm.move_velocity(0);
  
  // get second mogo
  chassis.moveToPoint(54, 12, 500);
  chassis.turnToHeading(90, 600);
  chassis.moveToPoint(-22, 11, 1000, {.forwards = false, .maxSpeed = 100});
  chassis.moveToPoint(-32, 11, 1000, {.forwards = false, .maxSpeed = 30});
  pros::delay(950);
  clamp.set_value(true);


  // get rings 8 9
  chassis.turnToHeading(7, 500);
  chassis.moveToPoint(-22, 39, 400, {.earlyExitRange = 10});
  chassis.moveToPoint(-40, 50, 650, {.earlyExitRange = 8});
  chassis.moveToPoint(-44, 83, 800);

  // wallstake ring 10
  chassis.turnToHeading(-160, 500);
  chassis.moveToPoint(-51, 60, 1400, {.maxSpeed = 100});
  armToLoadPos = true;
  chassis.turnToHeading(-90, 600);
  chassis.moveToPoint(-70, 60, 600);
  pros::delay(1400);
  convVelocity = 0;
  armToLoadPos = false;
  armToScore = true;

  // get rings 11 12 13
  pros::delay(800);
  // chassis.moveToPoint(70, 69, 300);
  chassis.moveToPoint(-40, 60, 850, {.forwards = false});
  armToScore = false;
  armToStartPos = true;
  convVelocity = 600;
  chassis.turnToHeading(200, 700);
  chassis.moveToPoint(-44, 4, 400);
  armToStartPos = true;
  chassis.moveToPoint(-44, 4, 1200, {.maxSpeed = 60});
  chassis.moveToPoint(-44, 4, 1200, {.maxSpeed = 30});

  // get ring 14 and put mogo in corner
  arm.move_velocity(0);
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
  chassis.moveToPoint(-21, 84, 900);

  // get mogo 3
  chassis.turnToHeading(205, 700);
  chassis.moveToPoint(4, 108, 500, {.forwards = false, .maxSpeed=100});
  pros::delay(500);
  chassis.moveToPoint(4, 110, 700, {.forwards = false, .maxSpeed = 50});
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
  chassis.moveToPoint(20, 94, 800, {.earlyExitRange = 10});
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

  // hang
  chassis.moveToPoint(-26, 94, 1000);
  chassis.turnToHeading(-45, 800);
  armToScore = true;
  chassis.moveToPoint(-6, 70, 500, {.forwards=false, .earlyExitRange=8});
  chassis.moveToPoint(-6, 70, 1000, {.forwards=false, .maxSpeed=40});
  chassis.moveToPoint(-11, 80, 800, {.maxSpeed=50});



}