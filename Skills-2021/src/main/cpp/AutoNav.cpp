#include "Robot.h"

void Robot::TankDrive(float left_value, float right_value) {
    left_front.Set(left_value);
    left_back.Set(left_value);
    right_front.Set(-right_value);
    right_back.Set(-right_value);
}

void Robot::travel(float speed, float value) {
    rev::CANEncoder encoder = left_front.GetEncoder();
    encoder.SetPosition(0);
    while(encoder.GetPosition() < value) {
        left_front.Set(speed);
        left_back.Set(speed);
        //TankDrive(speed, speed);
        frc::SmartDashboard::PutNumber("Reading", encoder.GetPosition());
    }
    //TankDrive(0.001, 0.001);
    left_front.Set(0.001);
    left_back.Set(0.001);
}