cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_OSX_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk)

include("cmake/utils.cmake")

option(BGFX_BUILD_EXAMPLES "Build bgfx examples." OFF)
set(BGFX_BUILD_TOOLS_SHADER   ON  CACHE BOOL "" FORCE)

project("platformer" VERSION 0.1)

add_subdirectory("3rdparty/glfw")
add_subdirectory("3rdparty/bgfx.cmake")


file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_shaders_directory(${CMAKE_CURRENT_SOURCE_DIR}/shaders ${CMAKE_CURRENT_SOURCE_DIR}/runtime)


add_executable(platformer ${SRC_FILES})
target_include_directories(platformer PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty 
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/generated/shaders
)


target_link_libraries(platformer glfw bgfx bx bimg)
