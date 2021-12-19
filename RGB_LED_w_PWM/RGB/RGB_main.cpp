#include <map>
#include <tuple>

#include "RGB_pub.hpp"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

enum { RED, GREEN, BLUE, PIN_COUNT };

static uint slices[PIN_COUNT];
static uint channels[PIN_COUNT];

static const std::map<RGB_COLOR, std::tuple<uint8_t, uint8_t, uint8_t>> colors =
    {{RGB_COLOR::RED, {255, 0, 0}},       {RGB_COLOR::GREEN, {0, 255, 0}},
     {RGB_COLOR::BLUE, {0, 0, 255}},      {RGB_COLOR::WHITE, {255, 255, 255}},
     {RGB_COLOR::YELLOW, {255, 255, 0}},  {RGB_COLOR::CYAN, {0, 255, 255}},
     {RGB_COLOR::MAGENTA, {255, 0, 255}}, {RGB_COLOR::MAROON, {128, 0, 0}},
     {RGB_COLOR::OLIVE, {128, 128, 0}},   {RGB_COLOR::PURPLE, {128, 0, 128}},
     {RGB_COLOR::TEAL, {0, 128, 128}},    {RGB_COLOR::NAVY, {0, 0, 128}}};

void RGB_init(void) {
  gpio_set_function(RED_PIN, GPIO_FUNC_PWM);
  gpio_set_function(GREEN_PIN, GPIO_FUNC_PWM);
  gpio_set_function(BLUE_PIN, GPIO_FUNC_PWM);

  slices[RED] = pwm_gpio_to_slice_num(RED_PIN);
  slices[GREEN] = pwm_gpio_to_slice_num(GREEN_PIN);
  slices[BLUE] = pwm_gpio_to_slice_num(BLUE_PIN);

  channels[RED] = pwm_gpio_to_channel(RED_PIN);
  channels[GREEN] = pwm_gpio_to_channel(GREEN_PIN);
  channels[BLUE] = pwm_gpio_to_channel(BLUE_PIN);

  for (int i = 0; i < PIN_COUNT; i++) {
    pwm_set_wrap(slices[i], 255);
    pwm_set_output_polarity(slices[i], true, true);
    pwm_set_enabled(slices[i], true);
  }
}

void RGB_set_color(const RGB_COLOR color, const int brightness) {
  auto [r, g, b] = colors.at(color);

  pwm_set_chan_level(slices[RED], channels[RED], int((brightness / 100.0) * r));
  pwm_set_chan_level(slices[GREEN], channels[GREEN],
                     int((brightness / 100.0) * g));
  pwm_set_chan_level(slices[BLUE], channels[BLUE],
                     int((brightness / 100.0) * b));
}