#include "Robot.h"

void Robot::TankDrive(float left_value, float right_value) {
    left_front.Set(left_value);
    left_back.Set(left_value);
    right_front.Set(-right_value);
    right_back.Set(-right_value);
}