add_executable(window_lifecycle_tests
    window_lifecycle_test.cpp
)

target_link_libraries(window_lifecycle_tests
    PRIVATE
        yashima_core
        GTest::gtest
        GTest::gtest_main
)

add_test(NAME WindowLifecycleTests COMMAND window_lifecycle_tests)