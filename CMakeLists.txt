cmake_minimum_required(VERSION 3.5)

project(BatteryBeep)

set(SOURCES main.cpp removeWhitespace.cpp findLabelValue.cpp)

add_executable(BatteryBeep ${SOURCES})