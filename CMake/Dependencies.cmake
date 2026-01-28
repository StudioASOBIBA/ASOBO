set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory("Engine/ThirdParty/assimp")
add_subdirectory("Engine/ThirdParty/glfw")
add_subdirectory("Engine/ThirdParty/spdlog")

set(FMOD_ROOT "${CMAKE_SOURCE_DIR}/Engine/ThirdParty/fmod")

add_library(fmod_core SHARED IMPORTED)
set_target_properties(fmod_core PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${FMOD_ROOT}/core/inc"
        IMPORTED_IMPLIB "${FMOD_ROOT}/core/lib/x64/fmod_vc.lib"
        IMPORTED_LOCATION "${FMOD_ROOT}/core/lib/x64/fmod.dll"
)

add_library(fmod_studio SHARED IMPORTED)
set_target_properties(fmod_studio PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${FMOD_ROOT}/studio/inc"
        IMPORTED_IMPLIB "${FMOD_ROOT}/studio/lib/x64/fmodstudio_vc.lib"
        IMPORTED_LOCATION "${FMOD_ROOT}/studio/lib/x64/fmodstudio.dll"
)

add_library(fmod_fsbank SHARED IMPORTED)
set_target_properties(fmod_fsbank PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${FMOD_ROOT}/fsbank/inc"
        IMPORTED_IMPLIB "${FMOD_ROOT}/fsbank/lib/x64/fsbank_vc.lib"
        IMPORTED_LOCATION "${FMOD_ROOT}/fsbank/lib/x64/fsbank.dll"
)