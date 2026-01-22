#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <iostream>

namespace Amuse::App
{
    Application::Application(const Application::MetaData&      MetaData,
                             const Application::Specification& specification_) noexcept
		: isRunning(false)
		, windows()
		, metaData(MetaData)
		, specification(specification_)
    {
        if (!glfwInit())
        {
            return;
        }

        Window::Specification windowSpecifications;
		windowSpecifications.title    = MetaData.productName;
		windowSpecifications.position = specification.presentaion;
        windowSpecifications.size     = specification.resolution;
        
		auto mainWindow = EmplaceWindow(windowSpecifications);
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
        if (windows.empty())
        {
            std::cout << "No Window\n";
            return -1;
        }

        isRunning = true;
        float lastTime = static_cast<float>(glfwGetTime());

        while (isRunning)
        {
            glfwPollEvents();

            if (windows.empty())
            {
                isRunning = false;
                continue;
            }

            for (auto it = windows.begin(); it != windows.end(); )
            {
                auto& window = *it;

                bool shouldClose = false;

                if (!window->IsFocused())
                {
                    if (window->ShouldClose())
                    {
                        shouldClose = true;
                    }
                }
                else
                {
                    const float currentTime = static_cast<float>(glfwGetTime());
                    const float deltaTime   = currentTime - lastTime;

                    window->Update();

                    if (window->ShouldClose())
                    {
                        shouldClose = true;
                    }
                }

                if (shouldClose)
                {
                    window->Destroy();

                    it = windows.erase(it);

                    if (windows.empty())
                    {
                        isRunning = false;
                    }
                }
                else
                {
                    ++it;
                }
            }

            lastTime = static_cast<float>(glfwGetTime());
        }

        return 0;
    }

    void Application::Stop()
    {
        isRunning = false;
    }

    Window* Application::EmplaceWindow(const Window::Specification& specification_)
    {
        auto ptr = std::make_unique<Window>(specification_);
        ptr->Create();

        Window* raw = ptr.get();
        windows.emplace_back(std::move(ptr));
        return raw;
    }

    void Application::RemoveWindow(Window* window_)
    {
        auto it = std::find_if(
            windows.begin(),
            windows.end(),
            [window_](const std::unique_ptr<Window>& window) {
                return window.get() == window_;
            }
        );
        if (it != windows.end())
        {
            (*it)->Destroy();
            windows.erase(it);
        }
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