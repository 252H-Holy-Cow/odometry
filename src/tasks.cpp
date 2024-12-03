#include "prosStuff.hpp"
#include "lemlibStuff.hpp"
#include "tasks.hpp"

bool doColorSort = true;
bool armToLoadPos = false;
bool armToStartPos = false;

ConveyorDirection_e convDir = STOP;

void debugTask(void *params) {
  uint32_t now = pros::millis();

  while(1){
    pros::lcd::print(2, "heading: %f", chassis.getPose().theta);
    pros::lcd::print(3, "vertical: %f", chassis.getPose().y);
    pros::lcd::print(4, "horizontal: %f", chassis.getPose().x);

    pros::Task::delay_until(&now, 20);
  }
}

void conveyorTask(void *params) {
  uint32_t now = pros::millis();

  while (true) {
    if (convDir == FORWARD) 
    {
      if (doColorSort 
      && optical.get_hue() > SORT_COLOUR - 20 
      && optical.get_hue() < SORT_COLOUR + 20 
      && optical.get_proximity() > 240){
        pros::Task::delay_until(&now, 50);
        conveyor.move_velocity(0);
        pros::Task::delay_until(&now, 600);
      }
      else{
        conveyor.move_velocity(1000);
      }
    } 
    else if (convDir == BACKWARD) 
    {
      conveyor.move_velocity(-200);
    } 
    else 
    {
      conveyor.move_velocity(0);
    }

    pros::Task::delay_until(&now, 5);
  }
}

void armPID(int target){
  uint32_t now = pros::millis();

  float kP = 0.02;

  int error = target - rotation.get_position();
  uint32_t startTime = pros::millis();

  while (abs(error) > 50 && pros::millis()-startTime < 1000){
    arm.move_velocity(kP*error);
    error = target - rotation.get_position();
    pros::Task::delay_until(&now, 2);
  }
}

void armTask(void *params) {
  uint32_t now = pros::millis();

  while (true) {
    pros::lcd::print(1, "arm: %d", rotation.get_position());
    
    // put arm in loading position
    if (armToLoadPos){
      armPID(3800);
      armToLoadPos = false;
      
    } else if(armToStartPos){
      armPID(100);
      armToStartPos = false;
    }
    pros::Task::delay_until(&now, 50);
  }
}

void autonColorSort(void *params) {
  uint32_t now = pros::millis();

  while (true) {
    if (optical.get_hue() > SORT_COLOUR - 20 
    && optical.get_hue() < SORT_COLOUR + 20 
    && optical.get_proximity() > 240){
      conveyor.move_velocity(0);
      pros::Task::delay_until(&now, 600);
    } 
  }
}