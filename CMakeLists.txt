cmake_minimum_required(VERSION 3.20)

project(yashima VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/generators ${CMAKE_PREFIX_PATH})

find_package(glfw3 CONFIG REQUIRED)
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src/v1)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests/v1)
endif()