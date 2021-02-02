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
#include <rev/CANSparkMax.h>

//our custom controller
#include "CustomController.h"
#include "ports.h"

using namespace frc;
using namespace rev;

class Robot : public frc::TimedRobot {
 public:
  CustomController xbox;
  RobotDrive driveTrain;
  CANSparkMax shooter;
  VictorSP elevator;
  VictorSP transfer;
  VictorSP intake;
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  Robot() : xbox(Ports::XBOX_DRIVER),
    driveTrain(Ports::LEFT_DRIVE_TRAIN, Ports::RIGHT_DRIVE_TRAIN),
    shooter(Ports::SHOOTER, rev::CANSparkMax::MotorType::kBrushless),
    elevator(Ports::ELEVATOR),
    transfer(Ports::TRANSFER),
    intake(Ports::INTAKE) {

  }
 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
