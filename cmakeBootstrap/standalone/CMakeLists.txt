cmake_minimum_required(VERSION 3.14)
project(standalone)

# Adding the inc directory, which contains header files
include_directories(inc)

# Using file(GLOB ...) to avoid having to add new souce files
file(GLOB SOURCES "main.cpp" "src/*.cpp")

add_executable(main ${SOURCES})
