cmake_minimum_required(VERSION 3.20)

project(Amuse
    VERSION     1.0.0
    DESCRIPTION "Multi-platform 2D & 3D game runtime library and editor"
    LANGUAGES   C CXX
)

include("CMake/Settings.cmake")
include("CMake/Dependencies.cmake")

# Build options
option(AMUSE_BUILD_RUNTIME "Build ASOBO runtime library" ON)
option(AMUSE_BUILD_EDITOR "Build ASOBO editor" ON)

# Global include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories
if(AMUSE_BUILD_RUNTIME)
    add_subdirectory("Engine/Runtime")
endif()

if(AMUSE_BUILD_EDITOR)
    add_subdirectory("Engine/Editor")
endif()

# Installation
install(DIRECTORY include/ DESTINATION include)