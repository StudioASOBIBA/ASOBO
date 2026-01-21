#ifndef AMUSE_INCLUDE_APPLICATION_H
#define AMUSE_INCLUDE_APPLICATION_H

#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "Window.h"

namespace Amuse::Core
{
    /**
     * @file Application.h
     *
     * @brief 애플리케이션을 정의합니다.
     */
    class Application
    {
    public:
        /**
         * @struct Specification
         *
         * @brief 애플리케이션의 사양을 정의합니다.
         */
        struct Specification final
        {
            /**
             * @brief 애플리케이션의 이름.
             */
            std::string name = "New Application";

            /**
             * @brief 애플리케이션의 윈도우 사양.
             */
            Window::Specification windowSpec = Window::Specification();
        };

        /**
         * @brief 생성자.
         */
        explicit Application(const Application::Specification& specification_ = Specification()) noexcept;

        /**
         * @brief 소멸자.
         */
        virtual ~Application() noexcept;

        /**
         * @brief 애플리케이션을 실행합니다.
         *
         * @return int 애플리케이션 종료 코드.
         */
        int Run();

        /**
         * @brief 애플리케이션을 중지합니다.
         */
        void Stop();

        /**
         * @brief 애플리케이션의 윈도우들을 반환합니다.
         *
         * @return Window* 애플리케이션의 윈도우들.
         */
        [[nodiscard]]
        inline Window* GetFocusedWindow() const;

    private:
        /**
         * @brief 애플리케이션 실행 상태.
         */
        bool isRunning;

        /**
         * @brief 해당 애플리케이션의 윈도우들.
         */
        std::vector<std::unique_ptr<Window>> windows;
    };
} // namespace Core

#endif // AMUSE_INCLUDE_APPLICATION_H