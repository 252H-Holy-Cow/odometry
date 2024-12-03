#include "autons.hpp"

#include "main.h"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"
#include "tasks.hpp"

ASSET(rr_corner1_txt);
ASSET(rr_corner2_txt);

void redRush(){
  // doink the mogo
  intakeLift.set_value(true);
  chassis.moveToPoint(-12, 31, 1100);
  pros::delay(700);
  conveyor.move_velocity(90);
  pros::delay(200);
  doinker.set_value(true);

  // clamp the mogo
  chassis.moveToPoint(-36, 26, 800, {.forwards = false});
  chassis.moveToPoint(-36, 26, 800, {.forwards = false, .maxSpeed = 50});
  doinker.set_value(false);
  pros::delay(500);
  clamp.set_value(true);
  conveyor.move_velocity(200);

  // get preload and go to corner
  chassis.turnToHeading(160, 600);
  chassis.follow(rr_corner1_txt, 12, 3000);
  pros::delay(2300);
  chassis.moveToPoint(20, -20, 1000);
  chassis.moveToPoint(-5, -2, 800, {.forwards = false});

  // diddle
  chassis.moveToPoint(25, -30, 800);
  chassis.moveToPoint(-5, 0, 800, {.forwards = false});
  chassis.moveToPoint(25, -30, 800);
  chassis.moveToPoint(-5, 0, 800, {.forwards = false});



}

void blueRush(){

}

void redRing(){
    
}

void blueRing(){
    
}

void autoSkills(){
    
}