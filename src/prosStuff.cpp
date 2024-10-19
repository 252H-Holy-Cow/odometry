#include "prosStuff.hpp"

pros::MotorGroup right_motors({12, 5, 4}, pros::MotorGearset::blue);

pros::MotorGroup left_motors({-15, -20, -1}, pros::MotorGearset::blue);

pros::Imu imu(10);

pros::Rotation horizontal_encoder(11);

pros::Rotation vertical_encoder(3);

pros::adi::DigitalOut arm('B');

pros::adi::DigitalOut clamp('A');

pros::adi::DigitalOut hang('C');

pros::Motor intake(2);

pros::Motor conveyor(13);

pros::Motor rightArm(19);

pros::Motor leftArm(14);

pros::Optical optical(9);