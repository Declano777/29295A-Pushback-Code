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

    int reverseTimer = 0;

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

        if (DistanceSensor_.GetDistance() < 10 && reverseTimer < 0) {
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
                reverseTimer = 23;
            }
            block = OpticalSensor::BlockType::None;
        }        
        reverseTimer--;
    }

    void SortOn() {
        colourSort = true;
        OpticalSensor_.LEDon();
    }
    void SortOff() {
        colourSort = false;
        OpticalSensor_.LEDoff();
    }

    int GetReverseTimer() {
        return reverseTimer;
    }

    void SetAllianceAsRed(bool isRed) {
        allianceColourRed = isRed;
    }
};

#endif  // BlOCKDETECTOR_HPP