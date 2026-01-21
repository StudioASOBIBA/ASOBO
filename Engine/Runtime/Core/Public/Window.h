#ifndef GUARD_WINDOW_H
#define GUARD_WINDOW_H

#include <string>
#include <string_view>

#include "Math/Vector2D.h"

struct GLFWwindow;

namespace Amuse::Core
{
    /**
     * @file Window.h
     *
     * @brief 윈도우를 정의합니다.
     */
    class Window
    {
    public:
        /**
         * @struct Specification
         *
         * @brief 윈도우의 사양을 정의합니다.
         */
        struct Specification final
        {
            /**
             * @brief 윈도우의 제목.
             */
            std::string title = "New Window";

            /**
             * @brief 윈도우의 위치.
             */
            Vector2D<int> position = {100, 100};

            /**
             * @brief 윈도우의 크기.
             */
            Vector2D<int> size = {800, 600};
        };

        /**
         * @brief 기본 생성자입니다.
         *
         * @param specification_ 윈도우의 사양.
         */
        explicit Window(const Window::Specification& specification_) noexcept;

        /**
         * @brief 기본 소멸자입니다.
         */
        virtual ~Window();

        /**
         * @brief 해당 윈도우를 생성합니다.
         */
        void Create();

        /**
         * @brief 해당 윈도우를 파괴합니다.
         */
        void Destroy();

        /**
         * @brief 해당 윈도우를 업데이트합니다.
         */
        void Update() const;

        /**
         * @brief 해당 윈도우의 순수 핸들을 반환합니다.
         *
         * @return NativeWindow 윈도우의 순수 핸들.
         */
        [[nodiscard]]
        GLFWwindow* GetNativeHandle() const noexcept;

        /**
         * @brief 해당 윈도우의 사양을 반환합니다.
         *
         * @return const Window::Specification& 윈도우의 사양.
         */
        [[nodiscard]]
        const Window::Specification& GetSpecification() const noexcept;

        /**
         * @brief 해당 윈도우의 사양을 설정합니다.
         *
         * @param specification_ 윈도우의 사양.
         */
        void SetSpecification(const Window::Specification& specification_) noexcept;

        /**
         * @brief 해당 윈도우가 포커스되었는지 여부를 반환합니다.
         *
         * @return bool 포커스 여부.
         */
        [[nodiscard]]
        bool IsFocused() const;

        /**
         * @brief 해당 윈도우의 포커스 상태를 설정합니다.
         */
        void Focus() const noexcept;

        /**
         * @brief 해당 윈도우가 닫혀야 하는지 여부를 반환합니다.
         *
         * @return bool 닫힘 여부.
         */
        [[nodiscard]]
        bool ShouldClose() const noexcept;

    private:
        /**
         * @brief 해당 윈도우의 순수 핸들.
         */
        GLFWwindow* handle;

        /**
         * @brief 해당 윈도우의 사양.
         */
        Window::Specification specification;
    };
} // namespace Amuse::Core

#endif // !GUARD_WINDOW_H