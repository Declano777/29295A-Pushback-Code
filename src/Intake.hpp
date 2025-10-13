#ifndef INTAKE_HPP
#define INTAKE_HPP

#include "Basic Control Classes/Motor.hpp"
#include "BlockDetector.hpp"

class Intake
{

private:
    Motor PreRoller_;
    Motor S_Roller_;
    Motor Hood_;

    int PreRollerSpeed_;
    int S_RollerSpeed_;
    int HoodSpeed_;
    int maxSpeed = 127;

public:
    Intake(Motor PreRoller, Motor S_Roller, Motor Hood)
        : PreRoller_(PreRoller), S_Roller_(S_Roller), Hood_(Hood)
    {
        SetS_RollerBrakeCoast();
    }

    void InputTick() {
       // BlockDetector_.Tick();
        S_Roller_.Tick();
    }

    void OutputTick() {
        PreRoller_.SetSpeed(PreRollerSpeed_);
        S_Roller_.SetSpeed(S_RollerSpeed_);
        Hood_.SetSpeed(HoodSpeed_);
        }

    void Forward()
    {
        PreRollerSpeed_ = maxSpeed;
        S_RollerSpeed_ = maxSpeed;
        HoodSpeed_ = maxSpeed;
    }

    void Reverse()
    {
        PreRollerSpeed_ = -maxSpeed;
        S_RollerSpeed_ = -maxSpeed;
        HoodSpeed_ = -maxSpeed;
    }

    void M_Forward()
    {
        PreRollerSpeed_ = maxSpeed;
        S_RollerSpeed_ = maxSpeed;
        HoodSpeed_ = -maxSpeed;
    }

    void M_Reverse()
    {
        PreRollerSpeed_ = -maxSpeed;
        S_RollerSpeed_ = -maxSpeed;
        HoodSpeed_ = maxSpeed;
    }

    void PreRollForward()
    {
        PreRollerSpeed_ = maxSpeed;
        S_RollerSpeed_ = 0;
        HoodSpeed_ = 0;
    }
    void PreRollReverse()
    {
        PreRollerSpeed_ = -maxSpeed;
        S_RollerSpeed_ = 0;
        HoodSpeed_ = 0;
    }

    void Stop()
    {
        PreRollerSpeed_ = 0;
        S_RollerSpeed_ = 0;
        HoodSpeed_ = 0;
    }

    void ChangePreRollerSpeed(int speed)
    {
        PreRollerSpeed_ = speed;
    }

    void ChangeS_RollerSpeed(int speed)
    {
        S_RollerSpeed_ = speed;
    }

        void ChangeHoodSpeed(int speed)
    {
        HoodSpeed_ = speed;
    }

    void SetS_RollerBrakeBrake() {
        S_Roller_.SetBrakeMode(MOTOR_BRAKE_BRAKE);
    }

    void SetS_RollerBrakeCoast() {
        S_Roller_.SetBrakeMode(MOTOR_BRAKE_COAST);
    }

};
#endif // INTAKE_HPP