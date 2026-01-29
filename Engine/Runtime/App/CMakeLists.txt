set(AmuseApp_Public
    "Public/Application.h"
    "Public/Window.h"
)

set (AmuseApp_Private
    "Private/Application.cpp"
    "Private/Window.cpp"
)

add_library(AmuseApp STATIC
    "App.h"
    ${AmuseApp_Public}
    ${AmuseApp_Private}
)

target_include_directories(AmuseApp PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/Public"
)

target_link_libraries(AmuseApp
    PUBLIC
        AmuseCore
    PRIVATE
        Amuse_ThirdParty
        glfw
        OpenGL::GL
)