#include "main.h"
#include "lemlibStuff.hpp"
#include "prosStuff.hpp"

bool arm_state = false;
bool sort = false;
bool load = false;
bool clamp_state = false;
bool hang_state = false;

int red = 30;
int blue = 210;
int color = red;

enum status { FORWARD = 0, BACKWARD, STOP };

enum status conveyorStatus;

void task1(void *params) {
  while (1) {
    if (conveyorStatus == FORWARD) {
      conveyor.move_velocity(190);
      intake.move_velocity(200);

      if (optical.get_hue() > color - 30 && 
          optical.get_hue() < color + 30 &&
          optical.get_proximity() <= 80 && 
          load) {
        conveyor.move_velocity(-200);
        pros::delay(800);
      } else if (optical.get_hue() > color - 30 &&
                 optical.get_hue() < color + 30 &&
                 optical.get_proximity() <= 80 && 
                 sort) {
        pros::delay(120);
        conveyor.move_velocity(0);
        pros::delay(200);
      }
    } else if (conveyorStatus == BACKWARD) {
      conveyor.move_velocity(-200);
      intake.move_velocity(-200);
    } else {
      conveyor.move_velocity(0);
      intake.move_velocity(0);
    }

    pros::delay(1);
  }
}

void task2(void *params) {
  while(1){
    pros::lcd::print(0, "heading: %f", imu.get_heading());
    pros::lcd::print(1, "vertical: %f", vertical_encoder.get_position()*2*M_PI/36000);
    pros::lcd::print(2, "horizontal: %f", horizontal_encoder.get_position()*2*M_PI/36000);
    pros::delay(20);
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
  chassis.setPose(0, 0, 0);
  chassis.turnToHeading(180, 10000);
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
                   TASK_STACK_DEPTH_DEFAULT, "task 1");

  leftArm.set_brake_mode(MOTOR_BRAKE_HOLD);
  rightArm.set_brake_mode(MOTOR_BRAKE_HOLD);
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
      sort = !sort;
    }

    // arm loading
    if (controller.get_digital_new_press(DIGITAL_DOWN)) {
      load = !load;
    }

    // mogo mech
    if (controller.get_digital_new_press(DIGITAL_L2)) {
      clamp.set_value(!clamp_state);
      clamp_state = !clamp_state;
    }

    // corner clear
    if (controller.get_digital_new_press(DIGITAL_Y)) {
      arm.set_value(!arm_state);
      arm_state = !arm_state;
    }

    // hang
    if (controller.get_digital_new_press(DIGITAL_X)) {
      hang.set_value(!hang_state);
      hang_state = !hang_state;
    }

    // arm going up
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      rightArm.move_velocity(-127);
      leftArm.move_velocity(127);

      // arm going down
    } else if (controller.get_digital(DIGITAL_A)) {
      leftArm.move_velocity(-100);
      rightArm.move_velocity(100);

      // arm not moving
    } else {
      leftArm.move_velocity(0);
      rightArm.move_velocity(0);
    }

    pros::delay(50);
  }
}
