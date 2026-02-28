#include "main.h"
#include "subsystems.hpp"

void rake_down() { rake.set(true); }
void rake_up() { rake.set(false); }
void outtake_down() { outtake.set(false); }
void outtake_up() { outtake.set(true); }
void angle_down() { angle.set(false); }
void angle_up() { angle.set(true); }
void descore_up() { descore.set(true); }
void descore_down() { descore.set(false); }

void pneumatic_control() {
  rake.button_toggle(master.get_digital(DIGITAL_DOWN));
  descore.set(master.get_digital(DIGITAL_DOWN));
  angle.set(master.get_digital(DIGITAL_L2));
  outtake.set(master.get_digital(DIGITAL_L1));
}