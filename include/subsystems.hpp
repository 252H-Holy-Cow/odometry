#pragma once

#include "api.h"
#include "lemlib/api.hpp"

extern pros::MotorGroup left_motors;

extern pros::MotorGroup right_motors;

extern lemlib::Drivetrain drivetrain;

extern pros::Rotation horizontal_encoder;

extern pros::Rotation vertical_encoder;

extern lemlib::TrackingWheel horizontal_tracking_wheel;

extern lemlib::TrackingWheel vertical_tracking_wheel;

extern pros::Imu imu;

extern lemlib::OdomSensors sensors;

extern lemlib::ControllerSettings lateral_controller;

extern lemlib::ControllerSettings angular_controller;

extern lemlib::Chassis chassis;