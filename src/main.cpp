#include "main.h"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"

bool clamp_state = false;
bool hang_state = false;
bool doinker_state = false;
bool intakeLift_state = false;

int red = 20;
int blue = 210;
int color = red;

const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;

bool colorSort = false;
bool load = false;

bool loadPos = false;
bool start = false;


typedef enum { 
  FORWARD = 0, 
  BACKWARD, 
  STOP 
} status;

status conveyorStatus;

void task1(void *params) {
  uint32_t now = pros::millis();

  while (true) {
    if (conveyorStatus == FORWARD) 
    {
      conveyor.move_velocity(1000);
    } 
    else if (conveyorStatus == BACKWARD) 
    {
      conveyor.move_velocity(-200);
    } 
    else 
    {
      conveyor.move_velocity(0);
    }

    pros::Task::delay_until(&now, 50);
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

void task2(void *params) {
  uint32_t now = pros::millis();

  while (true) {
    printf("Tick Position: %d \n", rotation.get_position());
    
    // put arm in loading position
    if (loadPos){
      armPID(3500);
      loadPos = false;
      
    } else if(start){
      armPID(100);
      start = false;
    }
    pros::Task::delay_until(&now, 50);
  }
}

void task3(void *params) {
  uint32_t now = pros::millis();

  while(1){
    pros::lcd::print(2, "heading: %f", chassis.getPose().theta);
    pros::lcd::print(3, "vertical: %f", chassis.getPose().y);
    pros::lcd::print(4, "horizontal: %f", chassis.getPose().x);

    pros::Task::delay_until(&now, 20);
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() { 
  pros::lcd::initialize(); 
  chassis.calibrate();
  }

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.moveToPoint(24, 24, 5000);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

pros::Controller controller(pros::E_CONTROLLER_MASTER);

void opcontrol() {
  pros::Task taskA(task1, nullptr, TASK_PRIORITY_DEFAULT,
                   TASK_STACK_DEPTH_DEFAULT, "task 1");

  pros::Task taskB(task2, nullptr, TASK_PRIORITY_DEFAULT,
                   TASK_STACK_DEPTH_DEFAULT, "task 2");

  pros::Task taskC(task3, nullptr, TASK_PRIORITY_DEFAULT,
                   TASK_STACK_DEPTH_DEFAULT, "task 3");

  arm.set_brake_mode(MOTOR_BRAKE_HOLD);
  conveyor.set_brake_mode(MOTOR_BRAKE_BRAKE);

  // loop forever
  while (true) {
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    chassis.tank(leftY, rightY);

    optical.set_led_pwm(100);

    // intake and conveyor
    if (controller.get_digital(DIGITAL_R2)) {
      conveyorStatus = FORWARD;
    } else if (controller.get_digital(DIGITAL_R1)) {
      conveyorStatus = BACKWARD;
    } else {
      conveyorStatus = STOP;
    }

    // color sorting
    if (controller.get_digital_new_press(DIGITAL_LEFT)) {
      colorSort = !colorSort;
    }

    // arm loading
    if (controller.get_digital_new_press(DIGITAL_DOWN)) {
      chassis.moveToPoint(0, -26, 1000, {.forwards = false});
      pros::delay(800);
      clamp.set_value(true);



    }

    // arm going up
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      arm.move_velocity(200);
    // arm not moving
    } else {
      arm.move(0);
    }

    // mogo mech
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
      clamp.set_value(!clamp_state);
      clamp_state = !clamp_state;
    }

    // hang
    if (controller.get_digital_new_press(DIGITAL_Y)) {
      hang.set_value(!hang_state);
      hang_state = !hang_state;
    }

    // doinker
    if (controller.get_digital_new_press(DIGITAL_B)) {
      doinker.set_value(!doinker_state);
      doinker_state = !doinker_state;
    }

    // intake lift
    if (controller.get_digital_new_press(DIGITAL_UP)) {
      intakeLift.set_value(!intakeLift_state);
      intakeLift_state = !intakeLift_state;
    }

    pros::delay(50);
  }
}
