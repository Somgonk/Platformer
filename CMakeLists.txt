cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project("platformer" VERSION 0.1)

add_subdirectory("lib/glfw")

add_executable("platformer" "src/main.cpp")
target_link_libraries(platformer glfw)

