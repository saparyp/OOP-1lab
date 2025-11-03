cmake_minimum_required(VERSION 3.10)
project(lab_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main src/array.cpp src/three.cpp src/main.cpp)

add_executable(tests tests/test_three.cpp src/array.cpp src/three.cpp)