cmake_minimum_required(VERSION 3.14)
project(lab1)

set(CMAKE_CXX_STANDART 11)

add_executable(program src/main.cpp src/f.cpp)

target_include_directories(program PRIVATE ${CMAKE_SOURCE_DIR}/include)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
