cmake_minimum_required(VERSION 3.20)
project(yashima VERSION 0.1.0 LANGUAGES CXX)

# C++20 requirement
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source directory to include paths
include_directories(
    ${PROJECT_SOURCE_DIR}/src/v1
)

# Core library
add_library(yashima_core
    src/v1/core/window/window.cpp
)

# Link dependecies
find_package(GLFW3 REQUIRED)
target_link_libraries(yashima_core PUBLIC glfw)

# Examples
add_executable(basic_window
    src/v1/examples/basic_window/main.cpp
)
target_link_libraries(basic_window PRIVATE yashima_core)

# Testing
enable_testing()
find_package(GTest REQUIRED)
add_subdirectory(tests/v1)