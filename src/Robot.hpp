#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "../include/pros/adi.h"

#include "Basic Control Classes/Piston.hpp"
#include "Intake.hpp"
#include "TrapDoor.hpp"
#include "DriveTrainJoystickMath.hpp"

class Robot
{

public:
    Pistonf Descore_;
    Pistonf DoublePark_;
    Pistonf Wings_;
    Pistonf MatchLoad_;
    TrapDoor TrapDoor_;

    Intake Intake_;

    DriveTrainCurveJoystickMath DriveTrain_;

    bool IsAutonomous = false;
    bool HalfSpeed = false;

public:
    Robot()
        : Descore_('A'),
          DoublePark_('B'),
          MatchLoad_('D'),
          Wings_('E'),
          TrapDoor_(Pistonf('F')),
          Intake_(Motor(12), Motor(14), Motor(-15)),
          DriveTrain_()
          //optical in 19, distance in 17

    {
        TrapDoor_.SortOn();
    }

    void InputTick()
    {
        Intake_.InputTick();
        TrapDoor_.InputTick();
        DriveTrain_.SetHalfSpeedValue(HalfSpeed);
        DriveTrain_.InputTick();
    }

    void OutputTick() {
        Intake_.OutputTick();
        TrapDoor_.OutputTick();
        DriveTrain_.OutputTick();
    }

    void AutonOutputTick() {
        Intake_.OutputTick();
        TrapDoor_.OutputTick();
    }

    void SetAllianceAsRed(bool isRed) {
        TrapDoor_.SetAllianceAsRed(isRed);
    }
};


#endif // ROBOT_HPP