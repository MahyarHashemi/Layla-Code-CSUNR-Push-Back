#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "antijam.hpp"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::MotorGroup bottom_intake({13, -14});

// Hook antijam variables
inline const int intake_wait_time = 30;           // The time in ms that the intake has to have 0 velocity before deciding a jam is happening
inline const int intake_outtake_time = 100;       // The time to outtake for to unjam
inline const int intake_stuck_retry_time = 1000;  // When scoring, wait before trying to unjam the intake
inline const int intake_min_speed = 20;           // Minimum speed that allows antijam to trigger (out of 127)

inline antijam bottom_intake_antijam(&bottom_intake, intake_wait_time, intake_outtake_time, intake_min_speed, intake_stuck_retry_time);  // Create the antijam

/////
// Top Intake
/////

inline pros::MotorGroup top_intake({-2, 12});

// Hook antijam variables
inline const int conveyor_bottom_wait_time = 40;  // The time in ms that the intake has to have 0 velocity before deciding a jam is happening
inline const int conveyor_bottom_time = 150;      // The time to outtake for to unjam
inline const int conveyor_bottom_speed = 20;      // Minimum speed that allows antijam to trigger (out of 127)

inline antijam top_intake_antijam(&top_intake, conveyor_bottom_wait_time, conveyor_bottom_time, conveyor_bottom_speed);  // Create the antijam

/////
// Pneumatics
/////

inline ez::Piston rake('A');
inline ez::Piston outtake('B', true);
inline ez::Piston angle('C');
inline ez::Piston descore('D');

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');