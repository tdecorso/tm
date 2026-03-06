cmake_minimum_required(VERSION 3.31)

project(tm)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

add_executable(test_vec2i tests/test_vec2i.c)
add_executable(test_vec2f tests/test_vec2f.c)
add_executable(test_vec3i tests/test_vec3i.c)
add_executable(test_vec3f tests/test_vec3f.c)

target_include_directories(test_vec2i PUBLIC include)
target_include_directories(test_vec2f PUBLIC include)
target_include_directories(test_vec3i PUBLIC include)
target_include_directories(test_vec3f PUBLIC include)

target_link_libraries(test_vec2i PRIVATE m)
target_link_libraries(test_vec2f PRIVATE m)
target_link_libraries(test_vec3i PRIVATE m)
target_link_libraries(test_vec3f PRIVATE m)
