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

bool led_callback(struct repeating_timer *t) {
  LED_toggle(LEDS::BUILT_IN_LED);
  return true;
}

int main(void) {
  LED_init();
  stdio_init_all();
  printf("INIT DONE\r\n");
  struct repeating_timer led_timer;
  add_repeating_timer_ms(500, led_callback, NULL, &led_timer);
  while (TRUE) {
    sleep_ms(1000);
    printf("1ms\r\n");
  }
}