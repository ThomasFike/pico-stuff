#pragma once

#include "../RGB_proj.h"

#ifndef BLUE_PIN
static_assert(0, "BLUE_PIN is not defined");
#endif

#ifndef RED_PIN
static_assert(0, "RED_PIN is not defined");
#endif

#ifndef GREEN_PIN
static_assert(0, "GREEN_PIN is not defined");
#endif

/// Memory constants
enum class RGB_COLOR {
  RED,
  GREEN,
  BLUE,
  WHITE,
  YELLOW,
  CYAN,
  MAGENTA,
  MAROON,
  OLIVE,
  PURPLE,
  TEAL,
  NAVY
};

void RGB_init(void);
void RGB_set_color(const RGB_COLOR color, const int brightness);