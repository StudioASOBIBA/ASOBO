# C 표준 설정
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ImGui 수학 연산자 정의 설정
add_compile_definitions(IMGUI_DEFINE_MATH_OPERATORS)

# Unicode 설정
add_compile_definitions(UNICODE _UNICODE)

# 디버그 빌드일 경우, _DEBUG 매크로 정의
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG)
endif()

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Library")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Library")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Binary")

# 빌드 플랫폼 감지
if(WIN32)
    set(AMUSE_TARGET_PLATFORM "Windows")
    add_compile_definitions(AMUSE_PLATFORM_WINDOWS)
elseif(APPLE)
    set(AMUSE_TARGET_PLATFORM "MacOS")
    add_compile_definitions(AMUSE_PLATFORM_MACOS)
elseif(UNIX)
    set(AMUSE_TARGET_PLATFORM "Linux")
    add_compile_definitions(AMUSE_PLATFORM_LINUX)
endif()

message(STATUS "Amuse Platform: ${AMUSE_TARGET_PLATFORM}")