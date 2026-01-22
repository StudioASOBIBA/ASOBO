# Runtime library CMake configuration

set(AMUSE_RUNTIME_SOURCES
    "${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Private/Application.cpp"
    "${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Private/Window.cpp"
)

set(AMUSE_RUNTIME_HEADERS
    "${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Public/Math/Matrix.h"
    "${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Public/Math/Vector2D.h"
    "${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Public/Math/Vector3D.h"
    "${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Public/Math/Vector4D.h"
    "${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Public/Application.h"
    "${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Public/Window.h"
)

# Create runtime library
add_library(Runtime STATIC
    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/glad/glad.c"

    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui.cpp"
    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui_demo.cpp"
    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui_draw.cpp"
    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui_tables.cpp"
    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui_widgets.cpp"
    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/backends/imgui_impl_glfw.cpp"
    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/backends/imgui_impl_opengl3.cpp"

    "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imguizmo/ImGuizmo.cpp"

    ${AMUSE_RUNTIME_SOURCES}
    ${AMUSE_RUNTIME_HEADERS}
 "Core/Public/Math/Vector3D.h")

target_include_directories(Runtime
    PUBLIC
        ${CMAKE_SOURCE_DIR}/Engine/Runtime/Core/Public
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/assimp/include

        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/dr_libs

        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/fmod/core/inc
        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/fmod/fsbank/inc
        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/fmod/studio/inc

        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/glad

        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/glfw/include

        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/glm

        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui
        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/backends

        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imguizmo

        ${CMAKE_SOURCE_DIR}/Engine/ThirdParty/stb
)

target_link_libraries(Runtime
        PUBLIC
        OpenGL32
        glfw  # GLFW 라이브러리를 Runtime과 연결하고, 이를 사용하는 Example1에도 전파
)

set_target_properties(Runtime PROPERTIES
    OUTPUT_NAME "Amuse"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

if(WIN32)
    target_compile_definitions(Runtime PRIVATE ASOBO_PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(Runtime PRIVATE ASOBO_PLATFORM_MACOS)
elseif(UNIX)
    target_compile_definitions(Runtime PRIVATE ASOBO_PLATFORM_LINUX)
endif()

target_compile_definitions(Runtime PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)

install(TARGETS Runtime
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)