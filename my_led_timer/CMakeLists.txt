cmake_minimum_required(VERSION 3.12)
include(../pico-sdk/external/pico_sdk_import.cmake)

project(my_led C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(my_led
    main.cpp
    LED/led_main.cpp)


pico_add_extra_outputs(my_led)

target_link_libraries(my_led pico_stdlib)
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)