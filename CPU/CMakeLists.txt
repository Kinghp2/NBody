cmake_minimum_required(VERSION 3.7)
project(NBody)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp Body.h Integrator.cpp Integrator.h numcpp/matrix.cpp numcpp/matrix.h numcpp/vector.h store/Store.cpp store/Store.h Parser.h Parser.cpp)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-O1")
set(CMAKE_CXX_FLAGS_DEBUG "-lstdc++fs")

if(CMAKE_SYSTEM_PROCESSOR MATCHES “BCM28|armv7”)
    add_compile_options(-march=armv8-a+crc -mcpu=cortex-a53 -mfpu=neon-fp-armv8)
endif()
add_executable(NBody ${SOURCE_FILES})
