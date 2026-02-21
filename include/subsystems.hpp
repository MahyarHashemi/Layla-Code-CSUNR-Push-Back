#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline ez::Piston rake('A');
inline ez::Piston angle('C');
inline ez::Piston outtake('B');
inline ez::Piston descore('D');

inline pros::MotorGroup top_intake({2, -12});
inline pros::MotorGroup bottom_intake({5, -15});

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');