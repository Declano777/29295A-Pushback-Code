#ifndef OPTICALSENSOR_HPP
#define OPTICALSENSOR_HPP

#include "../include/pros/optical.hpp"

class OpticalSensor {
private:
    pros::Optical OpticalSensor_;
    int Hue_;
    int Proximity_;

    const int MIN_BLOCK_DISTANCE = 150;

public:
    OpticalSensor(char PortNum) : OpticalSensor_{ PortNum } {}

    enum BlockType { None, Red, Blue };

    void Tick() {
        Proximity_ = OpticalSensor_.get_proximity();
        Hue_ = OpticalSensor_.get_hue();
    }

    BlockType GetBlock() {
        if (Proximity_ <= MIN_BLOCK_DISTANCE) return BlockType::None;
        if (Hue_ >= 180 && Hue_ <= 245) return BlockType::Blue;
        if (Hue_ >= 340 || Hue_ <= 20) return BlockType::Red;
        return BlockType::None;
    }

    void LEDon() {
        OpticalSensor_.set_led_pwm(100);
    }

    void LEDoff() {
        OpticalSensor_.set_led_pwm(0);
    }
};
#endif  // OPTICALSENSOR_HPP