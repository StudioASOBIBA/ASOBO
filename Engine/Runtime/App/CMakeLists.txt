add_library(App OBJECT
        "App.h"
        "Private/Application.cpp"
        "Private/Window.cpp"
        "Public/Application.h"
        "Public/Window.h"
)

target_include_directories(App PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Public"
)

target_link_libraries(App
        PUBLIC
        Core
        PRIVATE
        ThirdParty
        glfw
        OpenGL32
)