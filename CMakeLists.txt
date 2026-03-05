cmake_minimum_required(VERSION 3.31)

project(tm)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

add_executable(test_vec tests/test_vec.c)

target_include_directories(test_vec PUBLIC include)
target_link_libraries(test_vec PRIVATE m)
