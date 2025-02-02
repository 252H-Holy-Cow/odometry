#include "prosStuff.hpp"
#include "lemlibStuff.hpp"
#include "tasks.hpp"

ConveyorDirection_e convDir = STOP;
int convVelocity            = 0;
int armTimeout              = 0;
bool doColorSort            = false;
bool armToLoadPos           = false;
bool armToStartPos          = false;
bool armToScorePos          = false;

static void armPID(int target){
  uint32_t now = pros::millis();

  float kP = 0.015;

  int error = target - rotation.get_position();
  uint32_t startTime = pros::millis();

  while (abs(error) > 50 && pros::millis() - startTime < armTimeout){
    arm.move_velocity(kP*error);
    error = target - rotation.get_position();
    pros::Task::delay_until(&now, 2);
  }
}

void debugLoop(void *params) {
  uint32_t now = pros::millis();

  while(1){
    pros::lcd::print(2, "heading: %f", chassis.getPose().theta);
    pros::lcd::print(3, "vertical: %f", chassis.getPose().y);
    pros::lcd::print(4, "horizontal: %f", chassis.getPose().x);

    pros::Task::delay_until(&now, 20);
  }
}

void conveyorLoop(void *params) {
  uint32_t now = pros::millis();

  while (true) {
    if (convDir == FORWARD) 
    {
      if (doColorSort 
      && optical.get_hue() > SORT_COLOUR - 20 
      && optical.get_hue() < SORT_COLOUR + 20 
      && optical.get_proximity() > 240){
        pros::Task::delay_until(&now, 125);
        conveyor.move_velocity(0);
        pros::Task::delay_until(&now, 300);
      }
      else{
        conveyor.move_velocity(convVelocity);
        intake.move_velocity(convVelocity);
      }
    } 
    else if (convDir == BACKWARD) 
    {
      conveyor.move_velocity(-600);
      intake.move_velocity(-600);
    } 
    else if (convDir == FIRST) 
    {
      conveyor.move_velocity(0);
      intake.move_velocity(600);
    } 
    else 
    {
      conveyor.move_velocity(0);
      intake.move_velocity(0);
    }

    pros::Task::delay_until(&now, 1);
  }
}

void armLoop(void *params) {
  uint32_t now = pros::millis();

  while (true) {
    pros::lcd::print(1, "arm: %d", rotation.get_position());
    
    // put arm in loading position
    if (armToLoadPos){
      armPID(3200);
      armToLoadPos = false;
      
    } else if(armToStartPos){
      armPID(100);
      armToStartPos = false;

    } else if(armToScorePos){
      armPID(22000);
      armToStartPos = false;
    }

    pros::Task::delay_until(&now, 50);
  }
}
