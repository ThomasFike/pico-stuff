/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 */

#include <stdio.h>

#include <cctype>
#include <utility>

#include "LED/LED_pub.hpp"
#include "hardware/uart.h"
#include "pico/stdlib.h"

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define UART_TX_PIN 0
#define UART_RX_PIN 1

#define BAUD_RATE 115200

#define MENU_STR                          \
  "***********************************\n" \
  "Select from the options:\n"            \
  "Menu (m)\n"                            \
  "LED on (h)\n"                          \
  "LED off (l)\n"                         \
  "LED toggle (t)\n"                      \
  "***********************************\n"

enum class OPTIONS : char {
  MENU = 'm',
  LED_ON = 'h',
  LED_OFF = 'l',
  LED_TOGGLE = 't',
};

template <typename E>
constexpr typename std::underlying_type<E>::type to_under(E e) noexcept {
  return static_cast<typename std::underlying_type<E>::type>(e);
}

void prj_uart_init();

int main(void) {
  stdio_init_all();
  LED_init();
  prj_uart_init();

  uart_set_translate_crlf(uart0, true);

  uart_puts(uart0, MENU_STR);
  while (1) {
    const char input = uart_getc(uart0);
    switch (tolower(input)) {
      case to_under(OPTIONS::MENU):
        uart_puts(uart0, MENU_STR);
        break;
      case to_under(OPTIONS::LED_ON):
        LED_on(LEDS::BUILT_IN_LED);
        break;
      case to_under(OPTIONS::LED_OFF):
        LED_off(LEDS::BUILT_IN_LED);
        break;
      case to_under(OPTIONS::LED_TOGGLE):
        LED_toggle(LEDS::BUILT_IN_LED);
        break;
      case '\r':
        uart_putc_raw(uart0, '\n');
        break;
      case '\n':
        uart_putc_raw(uart0, '\r');
        break;
      default:
        uart_puts(uart0, "INVALID OPTION\n");
        break;
    }
    uart_putc_raw(uart0, input);
  }
  return 0;
}

/**
 * @brief Initalize UART
 *
 */
void prj_uart_init() {
  uart_init(uart0, BAUD_RATE);
  gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}