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
    float l_speed, r_speed;
    float l_target = l_encoder.GetPosition() - value;
    float r_target = r_encoder.GetPosition() - value;
    while(l_encoder.GetPosition() > l_target || r_encoder.GetPosition() > r_target) {
        if(l_encoder.GetPosition() > l_target) {
            l_speed = speed;
        }
        else {
            l_speed = 0.001;
        }
        if(r_encoder.GetPosition() > r_target) {
            r_speed = speed;
        }
        else {
            r_speed = 0.001;
        }
        TankDrive(-l_speed, r_speed);
    }
}

void Robot::right(float speed, float value) {
    float l_speed, r_speed;
    float l_target = l_encoder.GetPosition() + value;
    float r_target = r_encoder.GetPosition() + value;
    while(l_encoder.GetPosition() < l_target || r_encoder.GetPosition() < r_target) {
        if(l_encoder.GetPosition() < l_target) {
            l_speed = speed;
        }
        else {
            l_speed = 0.001;
        }
        if(r_encoder.GetPosition() < r_target) {
            r_speed = speed;
        }
        else {
            r_speed = 0.001;
        }
        TankDrive(l_speed, -r_speed);
    }
}

void Robot::l_circle(float speed, float value) {
    float target = l_encoder.GetPosition() + value;
    while(l_encoder.GetPosition() < target) {
        TankDrive(speed / 3, speed * 2);
    }
}

void Robot::r_circle(float speed, float value) {
    float target = l_encoder.GetPosition() + value;
    while(l_encoder.GetPosition() < target) {
        TankDrive(speed * 2, speed / 3);
    }
}