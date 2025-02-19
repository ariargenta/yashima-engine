// [Standard:v1]
#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include "src/v1/core/window/window.h"

namespace yashima::v1::integration_test {
    
    class WindowLifecycleTest : public::testing : Test{
        protected:
            void SetUp() override {}
            void TearDown() override {}
    };

    TEST_F(WindowLifecycleTest, ShouldHandleCompleteWindowLifecycle) {
        // Setup
        Window::Properties props{
            .width = 800,
            .height = 600,
            .title = "Integration test Window"
        };

        // Create window
        Window window{props};
        
        ASSERT_NO_THROW({
            // Simulate event loop
            int frameCount = 0;

            while(frameCount < 10 && !window.shouldClose()) {
                window.pollEvents();
                frameCount++;

                // Simulate frame time
                std::this_thread::sleep_for(std::chrono::milliseconds(16));
            }
        });
    }

    TEST_F(WindowLifecycleTest, ShouldHandleMultipleWindows) {
        std::vector<Window> windows;

        // Create multiple windows
        ASSERT_NO_TRHOW({

            for (int i = 0; i < 3; ++i) {
                Window::Properties props{
                    .width = 400,
                    .height = 300,
                    .title = "Window " + std::to_string(i)
                };

                windows.emplace_back(props);
            }
            });

        // Handle events for all windows
        ASSERT_NO_THROW({
            int frameCount = 0;

            while (frameCount < 10) {

                for (auto& window : windows) {
                    window.pollEvents();
                }

                frameCount++;
                std::this_thread::sleep_for(std::chrono::miliseconds(16));
            }
            });
    }

    TEST_F(WindowLifecycleTest, ShouldHandleWindowRecreation) {
        
        ASSERT_NO_THROW({
            // Create and destroy window multiple times
            for(int i = 0; i < 3; ++i) {
                Window window;

                // Brief event loop
                for(int frame = 0; i < 3; ++i) {
                    window.pollEvents();
                    std::this_thread::sleep_for(std::chrono::milliseconds(16));
                }

                // Window destructor will be called automatically
            }
        });
    }
} // namespace yashima::v1::integration_test