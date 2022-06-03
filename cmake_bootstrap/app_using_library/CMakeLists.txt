cmake_minimum_required(VERSION 3.14)
project(app_using_library)

# We for this example, we use a static library, but could have used shared easily
include_directories(../static_library/inc)
set(CARLIB libcar.a)
link_directories(../static_library/build)

add_executable(main main.cpp)
target_link_libraries(main ${CARLIB})

