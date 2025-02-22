#include "prosStuff.hpp"
#include "lemlibStuff.hpp"
#include "tasks.hpp"

ConveyorDirection_e convDir = STOP;
int convVelocity            = 0;
int armTimeout              = 0;
int jamTimeout              = 0;
bool doColorSort            = false;
bool armToLoadPos           = false;
bool armToStartPos          = false;
bool armToScorePos          = false;
bool armToScore             = false;

static void armPID(int target){
  uint32_t now = pros::millis();

  float kP = 0.015;

  int error = target - rotation.get_position();
  uint32_t startTime = pros::millis();

  while (abs(error) > 50){
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
        pros::Task::delay_until(&now, 30);
        conveyor.move_velocity(-600);
        pros::Task::delay_until(&now, 500);
        conveyor.move_velocity(600);
      }

      // else if (abs(conveyor.get_actual_velocity())<=1.0){
      //   pros::Task::delay_until(&now, 500);
      //   if (abs(conveyor.get_actual_velocity())<=1.0 && rotation.get_position()>3500 && rotation.get_position()<4500){
      //     conveyor.move_velocity(-600);
      //     pros::Task::delay_until(&now, 100);
      //     conveyor.move_velocity(600);
      //   }
      // }
      
      else {
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
    
    if (armToLoadPos){
      armPID(1500);
      // armToLoadPos = false;
      
    } if(armToStartPos){
      armPID(100);

    } else if(armToScore){
      armPID(22000);
      armToScore = false;

    } else if(armToScorePos){
      armPID(13250);
    }

    pros::Task::delay_until(&now, 50);
  }
}
