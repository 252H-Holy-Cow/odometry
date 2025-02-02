#include "lemlib/api.hpp" // IWYU pragma: keep
#include "main.h"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"
#include "autons.hpp"
#include "tasks.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() { 
  initHardware();
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
  convDir       = STOP;
  convVelocity  = 600;
  armTimeout    = 1000;
  doColorSort   = true;
  armToLoadPos  = false;
  armToStartPos = false;
  armToScorePos = false;

  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

  pros::Task debugTask(debugLoop, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task 1");
  pros::Task converyortask(conveyorLoop, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task 2");
  pros::Task armTask(armLoop, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task 3");

  redRush();
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

void opcontrol() {
  bool clamp_state      = false;
  bool hang_state       = false;
  bool doinker_state    = false;
  bool intakeLift_state = false;
  bool rush_state       = false;

  convDir       = STOP;
  convVelocity  = 600;
  armTimeout    = 1000;
  doColorSort   = true;
  armToLoadPos  = false;
  armToStartPos = false;
  armToScorePos = false;

  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

  pros::Task debugTask(debugLoop, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task 1");
  pros::Task converyortask(conveyorLoop, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task 2");
  pros::Task armTask(armLoop, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task 3");

  // loop forever
  while (true) {
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    chassis.tank(leftY, rightY);

    // intake and conveyor
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      convDir = FORWARD;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      convDir = BACKWARD;
    } else {
      convDir = STOP;
    }

    // color sorting
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      doColorSort = !doColorSort;
    }

    // arm loading
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      armToLoadPos = !armToLoadPos;
    }

    // arm loading
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      armToStartPos = !armToStartPos;
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

    // doinker
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
      doinker.set_value(!doinker_state);
      doinker_state = !doinker_state;
    }

    // intake lift
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
      intakeLift.set_value(!intakeLift_state);
      intakeLift_state = !intakeLift_state;
    }

    // rush mech
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      rushMech.set_value(!rush_state);
      rush_state = !rush_state;
    }

    pros::delay(50);
  }
}
