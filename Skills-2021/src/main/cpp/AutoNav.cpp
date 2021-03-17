#include "Robot.h"

void Robot::TankDrive(float left_value, float right_value) {
    left_front.Set(left_value);
    left_back.Set(left_value);
    right_front.Set(-right_value);
    right_back.Set(-right_value);
}

void Robot::travel(float speed, float value) {
    float target = l_encoder.GetPosition() + value;
    while(l_encoder.GetPosition() < target) {
        TankDrive(speed, speed);
    }
}

void Robot::left(float speed, float value) {
    float target = r_encoder.GetPosition() + value;
    while(r_encoder.GetPosition() < target) {
        TankDrive(-speed, speed);
    }
}

void Robot::right(float speed, float value) {
    float target = l_encoder.GetPosition() + value;
    while(l_encoder.GetPosition() < target) {
        TankDrive(speed, -speed);
    }
}