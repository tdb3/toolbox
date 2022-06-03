cmake_minimum_required(VERSION 3.14)
project(static_library)

# Adding the inc directory, which contains header files
include_directories(inc)

# Using file(GLOB ...) to avoid having to manually add new source files
file(GLOB SOURCES "src/*.cpp")

# Create a static library
add_library(car STATIC ${SOURCES})
