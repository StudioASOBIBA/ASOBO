# Runtime library CMake configuration

set(ASOBO_RUNTIME_SOURCES
    src/core.c
    src/graphics.c
)

set(ASOBO_RUNTIME_HEADERS
    ${CMAKE_SOURCE_DIR}/include/asobo.h
    ${CMAKE_SOURCE_DIR}/include/asobo/core.h
    ${CMAKE_SOURCE_DIR}/include/asobo/graphics.h
)

# Create runtime library
add_library(asobo_runtime STATIC ${ASOBO_RUNTIME_SOURCES} ${ASOBO_RUNTIME_HEADERS})

target_include_directories(asobo_runtime
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Set output name
set_target_properties(asobo_runtime PROPERTIES
    OUTPUT_NAME "asobo"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Platform specific configurations
if(WIN32)
    target_compile_definitions(asobo_runtime PRIVATE ASOBO_PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(asobo_runtime PRIVATE ASOBO_PLATFORM_MACOS)
elseif(UNIX)
    target_compile_definitions(asobo_runtime PRIVATE ASOBO_PLATFORM_LINUX)
endif()

# Installation
install(TARGETS asobo_runtime
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
