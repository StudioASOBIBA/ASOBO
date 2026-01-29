cmake_minimum_required(VERSION 3.22)

project(Amuse
    VERSION     1.0.0
    DESCRIPTION "Multi-platform 2D & 3D game runtime library and editor"
    LANGUAGES   C CXX
)

include("CMake/Settings.cmake")
include("CMake/Dependencies.cmake")

# Build options
option(AMUSE_BUILD_RUNTIME "Build Amuse runtime library" ON)
option(AMUSE_BUILD_EDITOR "Build Amuse editor" ON)
option(AMUSE_BUILD_EXAMPLES "Build Amuse examples" ON)
option(AMUSE_BUILD_TESTS "Build Amuse tests" ON)

# Add subdirectories
if(AMUSE_BUILD_RUNTIME)
    add_subdirectory("Engine/Runtime")
endif()

if(AMUSE_BUILD_EDITOR)
    add_subdirectory("Engine/Editor")
endif()

if(AMUSE_BUILD_EXAMPLES)
    add_subdirectory("Engine/Examples")
endif()

if (AMUSE_BUILD_TESTS)
    add_subdirectory("Engine/Tests")
endif()

# Installation
# install(DIRECTORY include/ DESTINATION include)