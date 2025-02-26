cmake_minimum_required(VERSION 3.20)

project(YashimaEngine
    VERSION 0.1.0
    DESCRIPTION "An educational graphics engine focusing on x86_64 optimization"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(YASHIMA_BUILD_EXAMPLES "Build example applications" OFF)
option(YASHIMA_BUILD_TESTS "Build test suite" OFF)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")