#include "main.h"
#include "subsystems.hpp"

void intake_speed(int speed){
    top_intake_antijam.enable();
    bottom_intake_antijam.enable();

    top_intake_antijam.set_motors(speed);
    bottom_intake_antijam.set_motors(speed);
}

void intake_zero(){
    top_intake.tare_position();
    bottom_intake.tare_position();
}

void intake_set_pos(double pos, int speed){
    top_intake_antijam.disable();
    bottom_intake_antijam.disable();

    top_intake.move_absolute(pos, speed);
    bottom_intake.move_absolute(pos, speed);
}

void intake_control(){
    if (master.get_digital(DIGITAL_R1)) {
      bottom_intake_antijam.set_motors(127);
      top_intake_antijam.set_motors(127);
    } 
    else if (master.get_digital(DIGITAL_R2)) {
      bottom_intake_antijam.set_motors(-127);
      top_intake_antijam.set_motors(-127);
    } 
    else if (master.get_digital(DIGITAL_X)) {
        bottom_intake_antijam.set_motors(63);
      top_intake_antijam.set_motors(63);
    }
    else {
      bottom_intake_antijam.set_motors(0);
      top_intake_antijam.set_motors(0);
    }

}