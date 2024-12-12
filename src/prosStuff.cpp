#include "prosStuff.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup right_motors({11, 2, 3}, pros::MotorGearset::blue);

pros::MotorGroup left_motors({-18, -9, -7}, pros::MotorGearset::blue);

pros::Imu imu(19);

pros::Rotation horizontal_encoder(12);

pros::Rotation vertical_encoder(-4);

pros::Motor conveyor(10);

pros::Motor arm(-1);

pros::Optical optical(6);

pros::Rotation rotation(8);

pros::adi::DigitalOut doinker('F');

pros::adi::DigitalOut clamp('E');

pros::adi::DigitalOut hang('C');

pros::adi::DigitalOut intakeLift('D');

void initHardware()
{
    pros::lcd::initialize();
    rotation.reset_position();
    optical.set_led_pwm(50);

    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    conveyor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}