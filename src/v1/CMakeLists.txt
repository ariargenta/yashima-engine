add_library(yashima_core
    core/window/window.cpp
)

target_include_directories(yashima_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(yashima_core
    PUBLIC
        glfw
)

target_compile_features(yashima_core
    PUBLIC
        cxx_std_20
)

add_subdirectory(examples)