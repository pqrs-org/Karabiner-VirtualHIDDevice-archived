#pragma once

#include <stdint.h>

struct __attribute__((packed)) karabiner_virtualhiddevice_hid_pointing_input_report {
  uint8_t buttons[4]; // 32 bits for each button (32 buttons)
  uint8_t x;
  uint8_t y;
  uint8_t vertical_wheel;
  uint8_t horizontal_wheel;

  // buttons[0] = (0x1 << 0) -> button 1
  // buttons[0] = (0x1 << 1) -> button 2
  // buttons[0] = (0x1 << 2) -> button 3
  // ...
  // buttons[1] = (0x1 << 0) -> button 9
  // ...
  // buttons[2] = (0x1 << 0) -> button 17
  // ...
  // buttons[3] = (0x1 << 0) -> button 25
};

enum karabiner_virtualhiddevice_user_client_method {
  karabiner_virtualhiddevice_user_client_method_pointing_input_report,
  karabiner_virtualhiddevice_user_client_method_end_,
};
