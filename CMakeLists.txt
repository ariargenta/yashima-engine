cmake_minimum_required(VERSION 3.20)

project(yashima-engine
    VERSION 0.1.0
    DESCRIPTION "An educational graphics engine focusing on x86_64 optimization"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(YASHIMA_BUILD_EXAMPLES "Build example applications" OFF)
option(YASHIMA_BUILD_TESTS "Build test suite" OFF)

set(YASHIMA_VERSION "v1" CACHE STRING "Engine version to build: ")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SOURCES_V1
    src/v1/core/application.cpp
    src/main.cpp
)

set(HEADERS_V1
    include/yashima/v1/core/application.h
)

add_executable(${PROJECT_NAME}
    $<$<STREQUAL:${YASHIMA_VERSION},v1>:${SOURCES_V1}>
    $<$<STREQUAL:${YASHIMA_VERSION},v1>:${HEADERS_V1}>
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        YASHIMA_VERSION="${YASHIMA_VERSION}"
)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")