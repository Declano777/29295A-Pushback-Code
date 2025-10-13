#ifndef TRAPDOOR_HPP
#define TRAPDOOR_HPP

#include "Basic Control Classes/Motor.hpp"
#include "BlockDetector.hpp"
#include "Basic Control Classes/Piston.hpp"

class TrapDoor
{
    private:
        Pistonf TrapDoor_;
        bool TrapDoorOn_ = false;
        BlockDetector BlockDetector_;
    public:
        TrapDoor(Pistonf TrapDoor) : TrapDoor_(TrapDoor) {
            SortOn();
        }

        void InputTick() {
            BlockDetector_.Tick();
        }

        void OutputTick() {
           if (BlockDetector_.GetTrapDoorTimer() > 0 && BlockDetector_.GetTrapDoorTimer() < 20) {
            TrapDoorOn_ = true;
           }
           else {
           TrapDoorOn_ = false;
           }
        }

        void SetAllianceAsRed(bool isRed) {
            BlockDetector_.SetAllianceAsRed(isRed);
        }

        void Toggle() {
            TrapDoorOn_ = !TrapDoorOn_;
            TrapDoor_.SetValue(TrapDoorOn_);
        }
        void SortOn() {
            BlockDetector_.SortOn();
        }

        void SortOff() {
            BlockDetector_.SortOff();
        }
};
#endif // TRAPDOOR_HPP