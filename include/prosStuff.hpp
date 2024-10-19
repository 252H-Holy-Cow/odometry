#pragma once
#include "api.h"

extern pros::MotorGroup left_motors;

extern pros::MotorGroup right_motors;

extern pros::Rotation horizontal_encoder;

extern pros::Rotation vertical_encoder;

extern pros::Imu imu;

extern pros::adi::DigitalOut arm;

extern pros::adi::DigitalOut clamp;

extern pros::adi::DigitalOut hang;

extern pros::Motor intake;

extern pros::Motor conveyor;

extern pros::Motor rightArm;

extern pros::Motor leftArm;

extern pros::Optical optical;