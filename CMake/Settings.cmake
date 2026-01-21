# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_definitions(IMGUI_DEFINE_MATH_OPERATORS)

# Set Unicode definitions
add_compile_definitions(UNICODE _UNICODE)

# Set Debug definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG)
endif()

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Platform detection
if(WIN32)
    set(AMUSE_TARGET_PLATFORM "Windows")
    add_compile_definitions(AMUSE_PLATFORM_WINDOWS)
elseif(APPLE)
    set(AMUSE_TARGET_PLATFORM "macOS")
    add_compile_definitions(AMUSE_PLATFORM_MACOS)
elseif(UNIX)
    set(AMUSE_TARGET_PLATFORM "Linux")
    add_compile_definitions(AMUSE_PLATFORM_LINUX)
endif()

message(STATUS "Amuse Platform: ${AMUSE_TARGET_PLATFORM}")