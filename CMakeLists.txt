cmake_minimum_required(VERSION 3.30)
project(Learning-C C)

set(CMAKE_C_STANDARD 11)

# Find required packages
find_package(SDL2 REQUIRED HINTS /opt/homebrew/Cellar/sdl2/2.30.11/include)
include_directories(${SDL2_INCLUDE_DIRS})

# Add the executable
add_executable(Learning-C main.c)

# Link libraries
target_link_libraries(Learning-C SDL2::SDL2)