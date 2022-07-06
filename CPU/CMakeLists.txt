cmake_minimum_required(VERSION 3.7)
project(NBody)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp Body.h Integrator.cpp Integrator.h numcpp/matrix.cpp numcpp/matrix.h numcpp/vector.h store/Store.cpp store/Store.h Parser.h Parser.cpp)

add_executable(NBody ${SOURCE_FILES})
