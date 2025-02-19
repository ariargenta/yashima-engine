cmake_minimum_required(VERSION 3.20)
project(yashima VERSION 0.1.0 LANGUAGES CXX)

# Project-wide settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source subdirectory
add_subdirectory(src/v1)

# Testing
if(BUILD_TESTING)
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(tests/v1)
endif()