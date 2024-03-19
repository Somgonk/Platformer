cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

project("platformer" VERSION 0.1)

add_subdirectory("lib/glfw")

add_executable("platformer" "src/main.cpp")
target_link_libraries(platformer glfw)

