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
<<<<<<< HEAD
#include "rev/CANSparkMax.h"
=======
#include <rev/CANSparkMax.h>
>>>>>>> master

//Custom classes
#include "CustomController.h"
#include "Limelight.h"
#include "ports.h"

using namespace frc;
using namespace rev;

class Robot : public frc::TimedRobot {
 public:
  CustomController xbox;
  RobotDrive driveTrain;
<<<<<<< HEAD
  Limelight limelight;
  bool square;
=======
  CANSparkMax shooter;
>>>>>>> master
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
<<<<<<< HEAD
  Robot() : xbox(0), driveTrain(0, 1), limelight() {
    square = false;
=======
  Robot() : xbox(Ports::XBOX_DRIVER),
    driveTrain(Ports::LEFT_DRIVE_TRAIN, Ports::RIGHT_DRIVE_TRAIN),
    shooter(Ports::SHOOTER, rev::CANSparkMax::MotorType::kBrushless) {

>>>>>>> master
  }
 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
