cmake_minimum_required(VERSION 3.5)

project(BatteryBeep)

set(SOURCES src/main.cpp src/removeWhitespace.cpp src/findLabelValue.cpp)

add_executable(BatteryBeep ${SOURCES})