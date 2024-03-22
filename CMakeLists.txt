cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project("platformer" VERSION 0.1)

add_subdirectory("lib/glfw")
add_subdirectory("lib/bgfx.cmake")

add_executable("platformer" "src/main.cpp")
target_include_directories(platformer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(platformer glfw)

