#pragma once

#include "api.h"

extern pros::Controller controller;

extern pros::MotorGroup left_motors;

extern pros::MotorGroup right_motors;

extern pros::Rotation horizontal_encoder;

extern pros::Rotation vertical_encoder;

extern pros::Imu imu;

extern pros::Motor intake;

extern pros::Motor conveyor;

extern pros::Motor arm;

extern pros::Optical optical;

extern pros::Rotation rotation;

extern pros::adi::DigitalOut doinker;

extern pros::adi::DigitalOut clamp;

extern pros::adi::DigitalOut hang;

extern pros::adi::DigitalOut intakeLift;

void initHardware();