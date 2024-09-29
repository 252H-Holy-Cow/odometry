#include "subsystems.hpp"
#include "lemlib/chassis/chassis.hpp"

pros::MotorGroup right_motors({12, 5, 4}, pros::MotorGearset::blue);

pros::MotorGroup left_motors({-15, -20, -1}, pros::MotorGearset::blue);

lemlib::Drivetrain drivetrain(
    &left_motors, // left motor group
    &right_motors, // right motor group
    11.5, // 10 inch track width
    lemlib::Omniwheel::NEW_275, // using new 4" omnis
    450, // drivetrain rpm is 360
    2 // horizontal drift is 2 (for now)
);

pros::Imu imu(10);

pros::Rotation horizontal_encoder(11);

pros::Rotation vertical_encoder(-3);

lemlib::TrackingWheel horizontal_tracking_wheel(
    &horizontal_encoder,
    lemlib::Omniwheel::NEW_2, 
    -1);

lemlib::TrackingWheel vertical_tracking_wheel(
    &vertical_encoder, 
    lemlib::Omniwheel::NEW_2, 
    -1);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

lemlib::ControllerSettings lateral_controller(
    7, // proportional gain (kP)
    0.0001, // integral gain (kI)
    30, // derivative gain (kD)
    0, // anti windup
    0, // small error range, in inches
    0, // small error range timeout, in milliseconds
    0, // large error range, in inches
    0, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);

lemlib::ControllerSettings angular_controller(
    2.7, // proportional gain (kP)
    0.001, // integral gain (kI)
    30, // derivative gain (kD)
    0, // anti windup
    0, // small error range, in degrees
    0, // small error range timeout, in milliseconds
    0, // large error range, in degrees
    0, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew)
);

lemlib::Chassis chassis(drivetrain, // drivetrain settings
    lateral_controller, // lateral PID settings
    angular_controller, // angular PID settings
    sensors // odometry sensors
);

pros::adi::DigitalOut arm('B');

pros::adi::DigitalOut clamp('A');

pros::adi::DigitalOut hang('C');

pros::Motor intake(2);

pros::Motor conveyor(13);

pros::Motor rightArm(19);

pros::Motor leftArm(14);

pros::Optical optical(9);

