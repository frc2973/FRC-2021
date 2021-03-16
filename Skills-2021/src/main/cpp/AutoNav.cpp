#include "Robot.h"

void Robot::TankDrive(float left_value, float right_value) {
    left_front.Set(left_value);
    left_back.Set(left_value);
    right_front.Set(-right_value);
    right_back.Set(-right_value);
}

void Robot::travel(float speed, float value) {
    double target = encoder.GetPosition() + value;
    while(encoder.GetPosition() < target) {
        TankDrive(speed, speed);
        frc::SmartDashboard::PutNumber("Reading", encoder.GetPosition());
    }
    TankDrive(0.001, 0.001);
}