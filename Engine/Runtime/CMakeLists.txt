add_library(ThirdParty STATIC
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/glad/glad.c"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui.cpp"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui_demo.cpp"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui_draw.cpp"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui_tables.cpp"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/imgui_widgets.cpp"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/backends/imgui_impl_glfw.cpp"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/backends/imgui_impl_opengl3.cpp"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imguizmo/ImGuizmo.cpp"
)

target_include_directories(ThirdParty PUBLIC
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/glad"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imgui/backends"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/imguizmo"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/glfw/include"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/glm"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/stb"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/assimp/include"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/fmod/core/inc"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/fmod/studio/inc"
        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/fmod/fsbank/inc"

        "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/dr_libs"
)

target_compile_definitions(ThirdParty
        PUBLIC
        IMGUI_IMPL_OPENGL_LOADER_GLAD
)

add_subdirectory(Core)
add_subdirectory(App)

add_library(Runtime STATIC
        $<TARGET_OBJECTS:App>
        $<TARGET_OBJECTS:Core>
)

target_link_libraries(Runtime INTERFACE
        PUBLIC
        App     # App의 헤더 경로 등을 상속
        Core    # Core의 헤더 경로 등을 상속
        PRIVATE
        ThirdParty
        glfw
        OpenGL32
)