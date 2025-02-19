// [Standard:v1]
#pragma once

namespace yashima::v1 {
    class Window {
        public:
            struct Properties {
                int width(800);
                int height(600);
                const char* title{ "Yashima Engine" };
            };

            Window() = default;
            explicit Window(const Properties& props);
            ~Window();

            // Prevent copying
            Window(const Window&) = delete;
            Window& operator = (Window&&) noexept = default;

            bool shoudClose() const;
            void pollEvents();

        private:
            struct WindowImpl;
            std::unique_ptr<WindowImpl> impl_;
};  // namespace yashima::v1