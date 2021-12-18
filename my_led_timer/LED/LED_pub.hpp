
#ifndef LED_PUB_HPP
#define LED_PUB_HPP
#include "pico/stdlib.h"
#ifndef GPIO_CLEAR
enum {
  GPIO_CLEAR = 0,
  GPIO_SET = 1,
};
#endif

enum class LEDS : uint {
  BUILT_IN_LED,
  NUMBER_OF_LEDS,
};

void LED_init(void);
void LED_off(LEDS led);
void LED_on(LEDS led);
void LED_toggle(LEDS led);

#endif