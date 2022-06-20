cmake_minimum_required(VERSION 3.21)
project(stepik)

set(CMAKE_CXX_STANDARD 14)

add_executable(hello_world step1.intro/hello_world.cpp)
add_executable(streams_io step1.intro/streams_io.cpp)
add_executable(functions step1.intro/functions.cpp)
add_executable(simple_app step1.intro/simple_app.cpp)
add_executable(quadratic step1.intro/quadratic.cpp)
add_executable(trim_space step1.intro/trim_space.cpp)
add_executable(log2 step1.intro/log2.cpp)
