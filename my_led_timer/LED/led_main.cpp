#include "LED_pub.hpp"
#include "pico/stdlib.h"

/// Memory Constants
static constexpr uint LED_array[] = {PICO_DEFAULT_LED_PIN};

static_assert(static_cast<uint>(LEDS::NUMBER_OF_LEDS) == (sizeof(LED_array) / sizeof(LED_array[0])) );

/**
 * @brief LED_init initalizes
 *
 */
void LED_init(void) {
  for (int i = 0; i < static_cast<uint>(LEDS::NUMBER_OF_LEDS); i++) {
    gpio_init(LED_array[i]);
    gpio_set_dir(LED_array[i], GPIO_OUT);
  }
}

void LED_off(LEDS led) { gpio_put(LED_array[static_cast<uint>(led)], GPIO_CLEAR); }
void LED_on(LEDS led) { gpio_put(LED_array[static_cast<uint>(led)], GPIO_SET); }
void LED_toggle(LEDS led) {
  bool status = gpio_get(LED_array[static_cast<uint>(led)]);
  gpio_put(LED_array[static_cast<uint>(led)], !status);
}