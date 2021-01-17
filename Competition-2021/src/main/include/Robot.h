/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/WPILib.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "rev/CANSparkMax.h"

//Custom classes
#include "CustomController.h"
#include "Limelight.h"
#include "ports.h"

using namespace frc;

class Robot : public frc::TimedRobot {
 public:
  CustomController xbox;
  RobotDrive driveTrain;
  Limelight limelight;
  bool square;
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  Robot() : xbox(0), driveTrain(0, 1), limelight() {
    square = false;
  }
 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
