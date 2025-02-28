#include <iostream>
#include "../../../include/yashima/v1/core/application.h"


namespace yashima {

    Application::Application()
        : m_isRunning(false) {
    }

    Application::~Application() {
        Shutdown();
    }

    void Application::Run() {
        m_isRunning = true;
        Initialize();

        while (m_isRunning) {
            Update();
        }

        Shutdown();
    }

    void Application::Initialize() {
        std::cout << "Application initialized\n";
    }

    void Application::Update() {
        std::cout << "Application running...\n";
        m_isRunning = false; // Por ahora, solo ejecutamos una vez
    }

    void Application::Shutdown() {
        std::cout << "Application shutting down\n";
    }

} // namespace yashima