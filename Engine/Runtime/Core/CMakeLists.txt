set(AmuseCore_Public
    "Public/Debugging/Logger.h"
    "Public/Debugging/LogLevel.h"

    "Public/IO/Directory.h"
    "Public/IO/File.h"
    "Public/IO/Path.h"

    "Public/Math/Matrix.h"
    "Public/Math/Vector2D.h"
    "Public/Math/Vector3D.h"
    "Public/Math/Vector4D.h"

    "Public/Misc/DateTime.h"
)

set(AmuseCore_Private
    "Private/Debugging/Logger.cpp"

    "Private/IO/Directory.cpp"
    "Private/IO/File.cpp"
    "Private/IO/Path.cpp"
)

add_library(AmuseCore STATIC
    "Core.h"
    ${AmuseCore_Public}
    ${AmuseCore_Private}
)

target_include_directories(AmuseCore PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/Public"
    "${CMAKE_CURRENT_SOURCE_DIR}/Public/Debugging"
    "${CMAKE_CURRENT_SOURCE_DIR}/Public/IO"
    "${CMAKE_CURRENT_SOURCE_DIR}/Public/Math"
)

target_link_libraries(AmuseCore
    PUBLIC
        # 필요하면 뭐 넣어라
    PRIVATE
        Amuse_ThirdParty
        glfw
        OpenGL::GL
)