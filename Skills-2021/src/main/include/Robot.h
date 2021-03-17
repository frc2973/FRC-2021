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
  CANSparkMax left_front;
  CANSparkMax left_back;
  CANSparkMax right_front;
  CANSparkMax right_back;
  CANSparkMax shooter;
  CANEncoder l_encoder = left_front.GetEncoder();
  CANEncoder r_encoder = right_front.GetEncoder();
  VictorSP elevator;
  VictorSP transfer;
  VictorSP intake;
  SendableChooser<std::string> paths;
  void TankDrive(float left_value, float right_value);
  void travel(float speed, float value);
  void left(float speed, float value);
  void right(float speed, float value);
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  Robot() : 
  xbox(Ports::XBOX_DRIVER), 
  left_front(Ports::LEFT_FRONT, CANSparkMax::MotorType::kBrushless), 
  left_back(Ports::LEFT_BACK, CANSparkMax::MotorType::kBrushless), 
  right_front(Ports::RIGHT_FRONT, CANSparkMax::MotorType::kBrushless), 
  right_back(Ports::RIGHT_BACK, CANSparkMax::MotorType::kBrushless),
  shooter(Ports::SHOOTER, CANSparkMax::MotorType::kBrushless),
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