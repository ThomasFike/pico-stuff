cmake_minimum_required(VERSION 3.12)
include(../pico-sdk/external/pico_sdk_import.cmake)

project(RGB_LED C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(RGB_LED
    main.cpp
    RGB/RGB_main.cpp)

pico_add_extra_outputs(RGB_LED)

target_link_libraries(RGB_LED pico_stdlib hardware_pwm)
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)