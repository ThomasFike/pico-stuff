cmake_minimum_required(VERSION 3.12)
include(../pico-sdk/external/pico_sdk_import.cmake)

project(UART_MENU C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(UART_MENU
    main.cpp
    LED/led_main.cpp)

pico_add_extra_outputs(UART_MENU)

target_link_libraries(UART_MENU pico_stdlib)
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 0)