#ifndef BlOCKDETECTOR_HPP
#define BLOCKDETECTOR_HPP

#include "Basic Control Classes/DistanceSenor.hpp"
#include "Basic Control Classes/OpticalSensor.hpp"

class BlockDetector {
private:
    bool colourSort = true;
    bool allianceColourRed;

    OpticalSensor::BlockType block = OpticalSensor::BlockType::None;

    bool badColour = false;

    int trapDoorTimer = 0;
    int delayTime = 23;

    OpticalSensor OpticalSensor_;
    DistanceSensor DistanceSensor_;
    

public:
    BlockDetector() : OpticalSensor_(19), DistanceSensor_(17) {
        SortOn();
    }

    void Tick() {
        OpticalSensor_.Tick();
        DistanceSensor_.Tick();

        if (!colourSort) return;

        if (DistanceSensor_.GetDistance() < 10 && trapDoorTimer < 0) {
            block = OpticalSensor_.GetBlock();
            switch (block)
            {
            case OpticalSensor::BlockType::Red:
                badColour = !allianceColourRed;
                break;
            case OpticalSensor::BlockType::Blue:
                badColour = allianceColourRed;
                break;
            default:
                badColour = false;
                break;
            }

            if (badColour) {
                trapDoorTimer = delayTime;
            }
            block = OpticalSensor::BlockType::None;
        }        
        trapDoorTimer--;
    }

    void SortOn() {
        colourSort = true;
        OpticalSensor_.LEDon();
    }
    void SortOff() {
        colourSort = false;
        OpticalSensor_.LEDoff();
    }

    int GetTrapDoorTimer() {
        return trapDoorTimer;
    }

    void SetAllianceAsRed(bool isRed) {
        allianceColourRed = isRed;
    }
};

#endif  // BlOCKDETECTOR_HPP