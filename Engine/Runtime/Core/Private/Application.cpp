#include "../Public/Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <algorithm>

namespace Amuse::Core
{
    Application::Application(const Application::Specification& specification_) noexcept
    {
        glfwInit();

        windows.emplace_back(std::make_unique<Window>(specification_.windowSpec));
        windows.back()->Create();
    }

    Application::~Application() noexcept
    {
        for (const std::unique_ptr<Window>& window : windows)
        {
            window->Destroy();
        }

        glfwTerminate();
    }

    int Application::Run()
    {
        isRunning = true;

        float lastTime = static_cast<float>(glfwGetTime());

        while (isRunning)
        {
            for (const std::unique_ptr<Window>& window : windows)
            {
                if (!window->IsFocused())
                    continue;

                glfwPollEvents();

                float currentTime = static_cast<float>(glfwGetTime());
                float deltaTime   = currentTime - lastTime;
                lastTime = currentTime;

                window->Update();

                if (window->ShouldClose())
                {
                    if (windows.size() == 1)
                    {
                        window->Destroy();
                        isRunning = false;
                    }
                    else
                    {
                        window->Destroy();

                        const auto begin = windows.begin();
                        const auto end   = windows.end();
                        const auto pred  = [&window](const std::unique_ptr<Window>& w) { return w.get() == window.get(); };

                        windows.erase(std::remove_if(begin, end, pred), windows.end());
                    }
                }
            }
        }

        return 0;
    }

    void Application::Stop()
    {
        isRunning = false;
    }

    Window* Application::GetFocusedWindow() const
    {
        for (const std::unique_ptr<Window>& window : windows)
        {
            if (window->IsFocused())
            {
                return window.get();
            }
        }

        return nullptr;
    }
} // namespace Core