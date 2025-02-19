// [Standard:v1]
#include <gtest/gtest.h>
#include "src/v1/core/window/window.h"

namespace yashima::v1::test {

    class WindowTest : public::testing::Test {
        protected:
            void Setup() override {}
            void TearDown() override {}
    };

    TEST_F(WindowTest, ShouldCreateWindowWithDefaultProperties) {

        EXPECT_NO_THROW({
            Window window;
        });
    }

    TEST_F(WindowTest, ShouldCreateWindowWithCustomProperties) {

        Window::Properties props{
            .width = 1024,
            .height = 768,
            .title = "Test Window"
        };

        EXPECT_NO_THROW({
            Window window{props};
        });
    }

    TEST_F(WindowTest, ShouldNotBeClosedInitially) {
        Window window;
        EXPECT_FALSE(window.shouldClose());
    }

    TEST_F(WindowTest, ShouldHandleEvents) {
        Window window;

        EXPECT_NO_THROW({
            window.pollEvents();
        });
    }

    TEST_F(WindowTest, ShouldNotAllowCopying) {
        // Verify copy constructor is deleted
        EXPECT_FALSE(std::is_copy_constructible_v<Window>);

        // Verify copy assignment is deleted
        EXPECT_FALSE(std::is_copy_assignable_v<Window>);
    }

    TEST_F(WindowTest, ShouldAllowMoving) {
        // Verify move constructor exists
        EXPECT_TRUE(std::is_move_constructible_v<Window>);

        // Verify move assignment exists
        EXPECT_TRUE(std::is_move_assignable_v<Window>);
    }
}  // namespace yashima::v1::test