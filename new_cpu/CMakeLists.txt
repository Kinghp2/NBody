cmake_minimum_required(VERSION 3.7)
project(new_cpu)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp Integrators/BaseIntegrator.h Integrators/Euler.h Integrators/Euler.cpp numcpp/Matrix.h numcpp/Matrix.cpp storer/Store.h storer/Store.cpp)

if(CMAKE_SYSTEM_PROCESSOR MATCHES “BCM28|armv7”)
    add_compile_options(-march=armv8-a+crc -mcpu=cortex-a53 -mfpu=neon-fp-armv8)
endif()

add_executable(new_cpu ${SOURCE_FILES})