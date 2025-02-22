#include "prosStuff.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup right_motors({1, -2, 3}, pros::MotorGearset::blue);

pros::MotorGroup left_motors({-10, 9, -7}, pros::MotorGearset::blue);

pros::Imu imu(8);

pros::Rotation horizontal_encoder(11);

pros::Rotation vertical_encoder(12);

pros::Motor conveyor(-5);

pros::Motor intake(6);

pros::Motor arm(13);

pros::Optical optical(4);

pros::Rotation rotation(-20);

pros::adi::DigitalOut doinker('G');

pros::adi::DigitalOut clamp('E');

pros::adi::DigitalOut intakeLift('H');

pros::adi::DigitalOut rushMech('F');

void initHardware()
{
    pros::lcd::initialize();
    rotation.reset_position();
    optical.set_led_pwm(50);

    optical.set_integration_time(10);

    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    conveyor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}