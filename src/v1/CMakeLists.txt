# Core library components
add_library(yashima_core
    core/window/window.cpp
)

# Set include directories for the core library
target_include_directories(yashima_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link dependencies
find_package(GLFW3 REQUIRED)
target_link_libraries(yashima_core
    PUBLIC
        glfw
)

# Set compile features
target_compile_features(yashima_core
    PUBLIC
        cxx_std_20
)

# Examples
add_subdirectory(examples)

# Export targets
set_target_properties(yashima_core
    PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        CXX_VISIBILITY_PRESENT hidden
        VISIBILITY_INLINES_HIDDEN ON
)

# Installation rules
install(TARGETS yashima_core
    EXPORT yashima-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)