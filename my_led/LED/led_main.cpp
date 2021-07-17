#include "LED_pub.hpp"
#include "pico/stdlib.h"

/**
 * @brief LED_init initalizes
 *
 */
void LED_init(void) {
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
}

void LED_off(LEDS led) { gpio_put(static_cast<uint>(led), GPIO_CLEAR); }
void LED_on(LEDS led) { gpio_put(static_cast<uint>(led), GPIO_SET); }
void LED_toggle(LEDS led) {
  bool status = gpio_get(static_cast<uint>(led));
  gpio_put(static_cast<uint>(led), !status);
}