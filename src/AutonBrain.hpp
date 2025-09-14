#ifndef AUTONBRAIN_HPP
#define AUTONBRAIN_HPP

#include "Robot.hpp"
#include "Basic Control Classes/LimitSwitch.hpp"

class AutonBrain
{

private:

    Robot* Robot_;
    LimitSwitch LimSwitch_;
   
public:
    AutonBrain(Robot* Robot)
        : Robot_(Robot), LimSwitch_('C')
    {

    }

    bool intakeOn = false;
    bool descoreOn = false;
    bool trapDoorOn = false;
    bool rollerOnly = false;

    void Tick()
    {
        LimSwitch_.Tick();
        Robot_->InputTick();

        if (intakeOn) {
            if(rollerOnly) {
                Robot_->Intake_.PreRollForward();
            }
            else {
                Robot_->Intake_.Forward();
            }
        }
        else {
            Robot_->Intake_.Stop();
        }
        if (descoreOn) {
            Robot_->Descore_.Activate();
        }
        else {
            Robot_->Descore_.Deactivate();
        }

        if (trapDoorOn) {
            Robot_->TrapDoor_.Activate();
        }
        else {
            Robot_->TrapDoor_.Deactivate();
        }
        Robot_->AutonOutputTick();
    }

    void SetAllianceAsRed(bool isRed) {
        Robot_->SetAllianceAsRed(isRed);
    }
};
#endif // AUTONBRAIN_HPP