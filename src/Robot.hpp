#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "../include/pros/adi.h"

#include "Basic Control Classes/Piston.hpp"
#include "Intake.hpp"
#include "DriveTrainJoystickMath.hpp"

class Robot
{

public:
    Pistonf Descore_;
    Pistonf TrapDoor_;

    Intake Intake_;

    DriveTrainCurveJoystickMath DriveTrain_;

    bool IsAutonomous = false;

    bool HalfSpeed = false;

public:
    Robot()
        : Descore_('A'),
          TrapDoor_('B'),
          Intake_(Motor(11), Motor(12), Motor(13)),
          DriveTrain_()

    {
        Intake_.SortOn();
    }

    void InputTick()
    {
        Intake_.InputTick();
        DriveTrain_.SetHalfSpeedValue(HalfSpeed);
        DriveTrain_.InputTick();
    }

    void OutputTick() {
        Intake_.OutputTick();
        DriveTrain_.OutputTick();
    }

    void AutonOutputTick() {
        Intake_.OutputTick();
    }

    void SetAllianceAsRed(bool isRed) {
        Intake_.SetAllianceAsRed(isRed);
    }
};


#endif // ROBOT_HPP