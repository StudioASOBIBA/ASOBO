add_library(AmuseApp STATIC
        "App.h"
        "Private/Application.cpp"
        "Private/Window.cpp"
        "Public/Application.h"
        "Public/Window.h"
)

target_include_directories(AmuseApp PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Public"
)

target_link_libraries(AmuseApp
        PUBLIC
        AmuseCore
        PRIVATE
        ThirdParty
        glfw
        OpenGL32
)