add_executable(window_tests
    window_test.cpp
)

target_link_libraries(window_tests
    PRIVATE
        yashima_core
        GTest::gtest
        GTest::gtest_main
)

add_test(NAME WindowTests COMMAND window_tests)