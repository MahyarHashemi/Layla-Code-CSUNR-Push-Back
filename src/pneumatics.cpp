#include "main.h"
#include "subsystems.hpp"

void rake_down() { rake.set(true); }
void rake_up() { rake.set(false); }
void outtake_down() { outtake.set(false); }
void outtake_up() { outtake.set(true); }
// void angle_down() { angle.set(false); }
// void angle_up() { angle.set(true); }
void descore_up() { descore.set(true); }
void descore_down() { descore.set(false); }

extern bool up_status = false;

// void rake_down() { rake.set(false); }
// void rake_up() { rake.set(true); }
// void outtake_down() { outtake.set(true); }
// void outtake_up() { outtake.set(false); }
void angle_down() { angle.set(true); }
void angle_up() { angle.set(false); }
// void descore_up() { descore.set(false); }
// void descore_down() { descore.set(true); }

void pneumatic_control() {
  // rake.button_toggle(master.get_digital(DIGITAL_B));
  // descore.set(master.get_digital(DIGITAL_DOWN));
  // angle.set(master.get_digital(DIGITAL_L2));
  // outtake.set(master.get_digital(DIGITAL_L1));

  rake.button_toggle(master.get_digital(DIGITAL_B));
  descore.set(master.get_digital(DIGITAL_L1));
  // angle.set(master.get_digital(DIGITAL_L2));
  outtake.set(master.get_digital(DIGITAL_R2));

  if (up_status && master.get_digital(DIGITAL_L2)){
    angle.set(true);
  }
  else if (up_status && !master.get_digital(DIGITAL_L2)){
    angle.set(false);
  }
  else if (!up_status && master.get_digital(DIGITAL_L2)){
    up_status = true;
  }
  else if (!up_status){
    angle.set(true);
  }
} 