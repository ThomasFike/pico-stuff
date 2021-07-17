/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 */

#include <stdio.h>

#include "LED/LED_pub.hpp"
#include "pico/stdlib.h"

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

int main(void) {
  LED_init();
  stdio_init_all();

  while (TRUE) {
    printf("Blinking\r\n");
    LED_toggle(LEDS::BUILT_IN_LED);
    sleep_ms(250);
  }
}