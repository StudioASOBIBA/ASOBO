#ifndef AMUSE_INCLUDE_APPLICATION_H
#define AMUSE_INCLUDE_APPLICATION_H

#include <memory>
#include <vector>

namespace Amuse::Core
{
    class Window;

    /**
     * @file Application.h
     *
     * @brief 애플리케이션을 정의합니다.
     */
    class Application
    {
    public:
        /**
         * @brief 애플리케이션의 윈도우들을 반환합니다.
         *
         * @return Window* 애플리케이션의 윈도우들.
         */
        [[nodiscard]]
        inline Window* GetFocusedWindow() const;

    private:
        /**
         * @brief 해당 애플리케이션의 윈도우들.
         */
        std::vector<std::unique_ptr<Window>> windows;
    };
} // namespace Core

#endif // AMUSE_INCLUDE_APPLICATION_H