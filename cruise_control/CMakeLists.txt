cmake_minimum_required(VERSION 3.20.0)

set(BOARD esp32_devkitc_wroom)
set(DTO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/boards)
set(DTC_OVERLAY_FILE ${DTO_DIR}/esp32_devkit_wroom.overlay)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(cruise_control)

target_sources(app PRIVATE 
    src/control/motor.c
    src/control/pid.c
    src/control/moving_avg.c
    src/control/encoder.c
    src/can/can.c
    src/main.c
)
