#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cassert>
#include <stdexcept>

namespace Amuse::App
{
    Window::Window(const Window::Specification& specification_) noexcept
        : specification(specification_)
        , handle(nullptr)
    {
    }

    Window::~Window()
    {
        Destroy();
    }

    void Window::Create()
    {
        constexpr int CONTEXT_MAJOR_VERSION = 3;
        constexpr int CONTEXT_MINOR_VERSION = 3;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, CONTEXT_MAJOR_VERSION);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, CONTEXT_MINOR_VERSION);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if defined(_DEBUG)
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

        handle = glfwCreateWindow(
            specification.size.x,
            specification.size.y,
            specification.title.c_str(),
            nullptr,
            nullptr
        );

        if (!handle)
        {
            throw std::runtime_error("Failed to create GLFW window.");
        }

        glfwMakeContextCurrent(handle);
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            throw std::runtime_error("Failed to load OpenGL functions.");
        }
    }

    void Window::Destroy()
    {
        if (handle)
        {
            glfwDestroyWindow(handle);
            handle = nullptr;
        }
    }

    void Window::Update() const
    {
        glfwSwapBuffers(handle);
    }

    Window::NativeWindow Window::GetNativeHandle() const noexcept
    {
        return handle;
    }

    const Window::Specification& Window::GetSpecification() const noexcept
    {
        return specification;
    }

    void Window::SetSpecification(const Window::Specification& specification_) noexcept
    {
        specification = specification_;
    }

    bool Window::IsFocused() const
    {
        return glfwGetWindowAttrib(handle, GLFW_FOCUSED) == GLFW_TRUE;
    }

    void Window::Focus() const noexcept
    {
        glfwFocusWindow(handle);
    }

    bool Window::ShouldClose() const noexcept
    {
        return glfwWindowShouldClose(handle) == GLFW_TRUE;
    }
} // namespace Amuse::Core