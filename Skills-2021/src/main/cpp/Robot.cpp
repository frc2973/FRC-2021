/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>
#include <frc/WPILib.h>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  frc::SmartDashboard::PutNumber("Shooter", 0);
  frc::SmartDashboard::PutNumber("Elevator", 0);
  frc::SmartDashboard::PutNumber("Transfer", 0);
  frc::SmartDashboard::PutNumber("Intake", 0);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  TankDrive(-xbox.GetLeftDriveTrain(), -xbox.GetRightDriveTrain());
  shooter.Set(frc::SmartDashboard::GetNumber("Shooter", 0));
  elevator.Set(frc::SmartDashboard::GetNumber("Elevator", 0));
  transfer.Set(frc::SmartDashboard::GetNumber("Transfer", 0));
  intake.Set(frc::SmartDashboard::GetNumber("Intake", 0));

  //Debugging
  if(xbox.GetAButton()) {
    limelight.set("ledMode", 3);
  }
  if(xbox.GetBButton()) {
    limelight.set("ledMode", 1);
  }

  //Activate Limelight tracking
  if (xbox.GetYButton()) {
    limelight.set("ledMode", 3); //LED on
    while (xbox.GetYButton()) {}
    if (limelight.get("tv") == 1) { //If target detected
      float uplimit = -6.55;
      float lowlimit = -6.6;
      float turnspeed = 0.07;
      while((limelight.get("tx") > uplimit || limelight.get("tx") < lowlimit) && !xbox.GetYButton()) {
        if(limelight.get("tx") < lowlimit) {
          TankDrive(-turnspeed, turnspeed);
        }
        else if(limelight.get("tx") > uplimit) {
          TankDrive(turnspeed, -turnspeed);
        }
      }
      TankDrive(0.001, 0.001);
    }
    limelight.set("ledMode", 1); //LED off
  }
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
