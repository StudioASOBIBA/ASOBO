#ifndef AMUSE_INCLUDE_APPLICATION_H
#define AMUSE_INCLUDE_APPLICATION_H

#include "Window.h"

#include "Math/Vector2D.h"

#include <format>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

using namespace Amuse::Core;

namespace Amuse::App
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
         * @brief 애플리케이션의 기본 설정을 정의합니다.
         */
        struct MetaData final
        {
            /**
             * @brief 애플리케이션의 이름.
             */
            std::string productName;

            /**
             * @brief 애플리케이션의 회사 이름.
			 */
            std::string companyName;

			/**
			 * @brief 애플리케이션의 버전.
			 */
			std::string version;

			/**
			 * @brief 애플리케이션의 식별자.
			 */
            std::string identifier;
        };

        struct Specification final
        {
            /**
             * @brief 애플리케이션의 위치.
             */
            Math::Vector2D<int> presentaion;

            /**
			 * @brief 애플리케이션의 해상도.
             */
            Math::Vector2D<int> resolution;

            // TODO: 아이콘, 커서 설정 필요
        };

        /**
         * @brief 생성자.
         * 
		 * @param publishSettings_ 애플리케이션의 기본 설정.
		 * @param specifications_  애플리케이션의 플랫폼별 설정.
         */
        explicit Application(const Application::MetaData& publishSettings_,
                             const Application::Specification&  specifications_) noexcept;

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
         * @brief 애플리케이션의 윈도우를 생성합니다.
         *
         * @param specification_ 윈도우의 사양.
         *
         * @return Window* 생성된 윈도우의 포인터.
		 */
		Window* EmplaceWindow(const Window::Specification& specification_);

        /**
         * @brief 애플리케이션의 윈도우를 파괴합니다.
         *
         * @param window_ 파괴할 윈도우의 포인터.
		 */
		void RemoveWindow(Window* window_);

        /**
         * @brief 애플리케이션의 윈도우들을 반환합니다.
         *
         * @return Window* 애플리케이션의 윈도우들.
         */
        [[nodiscard]]
        Window* GetFocusedWindow() const;

    private:
        /**
         * @brief 애플리케이션의 기본 설정.
		 */
		Application::MetaData metaData;

        /**
         * @brief 애플리케이션의 플랫폼별 설정.
		 */
		Application::Specification specification;

        /**
         * @brief 애플리케이션 실행 상태.
         */
        bool isRunning;

		/**
		 * @brief 메인 윈도우.
		 */
    	Window* mainWindow;

        /**
         * @brief 해당 애플리케이션의 윈도우들.
         */
        std::vector<std::unique_ptr<Window>> windows;
    };
} // namespace Core

#endif // AMUSE_INCLUDE_APPLICATION_H