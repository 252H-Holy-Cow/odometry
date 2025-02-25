#include "lemlibStuff.hpp"
#include "prosStuff.hpp"

lemlib::Drivetrain drivetrain(
    &left_motors, // left motor group
    &right_motors, // right motor group
    11, // 10 inch track width
    lemlib::Omniwheel::NEW_325, // using new 4" omnis
    480, // drivetrain rpm is 360
    2 // horizontal drift is 2 (for now)
);

lemlib::TrackingWheel horizontal_tracking_wheel(
    &horizontal_encoder,
    2.75, 
    -3);

lemlib::TrackingWheel vertical_tracking_wheel(
    &vertical_encoder, 
    2.75, 
    0);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

lemlib::ControllerSettings lateral_controller(
    5.28, // proportional gain (kP) 6.2
    0, // integral gain (kI)
    16, // derivative gain (kD) 28
    0, // anti windup
    0.6, // small error range, in inches
    100, // small error range timeout, in milliseconds
    2, // large error range, in inches
    500, // large error range timeout, in milliseconds
    30 // maximum acceleration (slew) 30
);

lemlib::ControllerSettings angular_controller(
    1.35, // proportional gain (kP)1.35
    0, // integral gain (kI)
    8.3, // derivative gain (kD)8.3
    0, // anti windup
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
