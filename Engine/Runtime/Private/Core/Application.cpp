#include "Core/Application.h"

#include "Core/Window.h"

namespace Core
{
    Window* Application::GetFocusedWindow() const
    {
        for (const auto& window : windows)
        {
            if (windows->IsFocused())
            {
                return window.get();
            }
        }
        return nullptr;
    }
} // namespace Core