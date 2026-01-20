cmake_minimum_required(VERSION 3.20)

project(ASOBO
    VERSION 0.1.0
    DESCRIPTION "Multi-platform 3D/2D game runtime library and editor"
    LANGUAGES C CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Platform detection
if(WIN32)
    set(ASOBO_PLATFORM "Windows")
    add_compile_definitions(ASOBO_PLATFORM_WINDOWS)
elseif(APPLE)
    set(ASOBO_PLATFORM "macOS")
    add_compile_definitions(ASOBO_PLATFORM_MACOS)
elseif(UNIX)
    set(ASOBO_PLATFORM "Linux")
    add_compile_definitions(ASOBO_PLATFORM_LINUX)
endif()

message(STATUS "ASOBO Platform: ${ASOBO_PLATFORM}")

# Build options
option(ASOBO_BUILD_RUNTIME "Build ASOBO runtime library" ON)
option(ASOBO_BUILD_EDITOR "Build ASOBO editor" ON)
option(ASOBO_BUILD_TESTS "Build ASOBO tests" ON)
option(ASOBO_BUILD_EXAMPLES "Build ASOBO examples" ON)

# Global include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories
if(ASOBO_BUILD_RUNTIME)
    add_subdirectory(runtime)
endif()

if(ASOBO_BUILD_EDITOR)
    add_subdirectory(editor)
endif()

if(ASOBO_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(ASOBO_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Installation
install(DIRECTORY include/ DESTINATION include)
