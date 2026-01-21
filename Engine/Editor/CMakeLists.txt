# Editor application CMake configuration

set(ASOBO_EDITOR_SOURCES
     "${CMAKE_SOURCE_DIR}/Engine/Editor/Private/Main.cpp"
)

# Create editor executable
add_executable(Editor 
    ${ASOBO_EDITOR_SOURCES}
)

# Link with runtime library
target_link_libraries(Editor PRIVATE 
    Runtime
)

# Set output name
set_target_properties(Editor PROPERTIES
    OUTPUT_NAME "Amuse"
)

# Installation
install(TARGETS Editor
    RUNTIME DESTINATION bin
)
