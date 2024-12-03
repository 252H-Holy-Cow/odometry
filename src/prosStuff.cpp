#include "prosStuff.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup right_motors({18, 19, 20}, pros::MotorGearset::blue);

pros::MotorGroup left_motors({-16, -15, -17}, pros::MotorGearset::blue);

pros::Imu imu(9);

pros::Rotation horizontal_encoder(5);

pros::Rotation vertical_encoder(-4);

pros::Motor conveyor(11);

pros::Motor arm(-10);

pros::Optical optical(12);

pros::Rotation rotation(14);

pros::adi::DigitalOut doinker('B');

pros::adi::DigitalOut clamp('A');

pros::adi::DigitalOut hang('D');

pros::adi::DigitalOut intakeLift('C');

void initHardware()
{
    pros::lcd::initialize();
    rotation.reset_position();
    optical.set_led_pwm(50);

    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    conveyor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}