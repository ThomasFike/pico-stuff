/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 */

#include <stdio.h>

#include "RGB/RGB_pub.hpp"
#include "pico/stdlib.h"

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

int main(void) {
  stdio_init_all();

  RGB_init();

  const RGB_COLOR color = RGB_COLOR::RED;
  while (TRUE) {
    for (int i = 0; i <= 100; i++) {
      RGB_set_color(color, i);
      sleep_ms(10);
    }
    for (int i = 100; i >= 0; i--) {
      RGB_set_color(color, i);
      sleep_ms(10);
    }
    printf("Done with Loop\n");
  }
}