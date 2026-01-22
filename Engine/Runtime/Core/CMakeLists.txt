add_library(Core OBJECT
        "Core.h"
        "Public/Math/Vector2D.h"
        "Public/Math/Vector3D.h"
)

target_include_directories(Core PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/Public"
)

target_link_libraries(Core
        PUBLIC
        # 필요하면 뭐 넣어라
        PRIVATE
        ThirdParty
        glfw
        OpenGL32
)