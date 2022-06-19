cmake_minimum_required(VERSION 3.21)
project(stepik)

set(CMAKE_CXX_STANDARD 14)

add_executable(hello_world step1.intro/hello_world.cpp)
add_executable(streams_io step1.intro/streams_io.cpp)
