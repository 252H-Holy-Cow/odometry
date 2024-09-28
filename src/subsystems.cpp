#include "subsystems.hpp"
#include "lemlib/chassis/chassis.hpp"

pros::MotorGroup right_motors({12, 5, 4}, pros::MotorGearset::blue);

pros::MotorGroup left_motors({-15, -20, -1}, pros::MotorGearset::blue);

lemlib::Drivetrain drivetrain(
    &left_motors, // left motor group
    &right_motors, // right motor group
    11.5, // 10 inch track width
    lemlib::Omniwheel::NEW_325, // using new 4" omnis
    450, // drivetrain rpm is 360
    2 // horizontal drift is 2 (for now)
);

pros::Imu imu(10);

pros::Rotation horizontal_encoder(20);

pros::Rotation vertical_encoder(19);

lemlib::TrackingWheel horizontal_tracking_wheel(
    &horizontal_encoder,
    lemlib::Omniwheel::NEW_2, 
    -5.75);

lemlib::TrackingWheel vertical_tracking_wheel(
    &vertical_encoder, 
    lemlib::Omniwheel::NEW_2, 
    -2.5);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

lemlib::ControllerSettings lateral_controller(
    10, // proportional gain (kP)
    0, // integral gain (kI)
    3, // derivative gain (kD)
    3, // anti windup
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);

lemlib::ControllerSettings angular_controller(
    2, // proportional gain (kP)
    0, // integral gain (kI)
    10, // derivative gain (kD)
    3, // anti windup
    1, // small error range, in degrees
    100, // small error range timeout, in milliseconds
    3, // large error range, in degrees
    500, // large error range timeout, in milliseconds
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