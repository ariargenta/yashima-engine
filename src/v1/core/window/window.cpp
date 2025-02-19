// [Standard:v1]
#include "window.h"
#include <GLFW/glfw3.h>

namespace yashima::v1 {
    
    struct Window::WindowImpl {
        GLFWwindow* handle{nullptr};
    };

    Window::Window(const Properties& props) : impl_(
        std::make_unique<WindowImpl>()) {
        if(!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        impl_->handle = glfwCreateWindow(
            props.width,
            props.height,
            props.title,
            nullptr,
            nullptr
        );

        if(!impl_->handle) {
            glfwTerminate();
            throw std::runtime_error("Failed to create window");
        }
    }

    Window::~Window() {
        if (impl_->handle) {
            glfwDestroyWindow(impl_->handle);
            glfwTerminate();
        }
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(impl_->handle);
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }
} // namespace yashima::v1