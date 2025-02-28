#pragma once

namespace yashima {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;

    protected:
        virtual void Initialize();
        virtual void Update();
        virtual void Shutdown();

    private:
        bool m_isRunning;
    };

} // namespace yashima