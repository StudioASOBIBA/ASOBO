# Editor application CMake configuration

set(ASOBO_EDITOR_SOURCES
    src/main.c
)

# Create editor executable
add_executable(asobo_editor ${ASOBO_EDITOR_SOURCES})

# Link with runtime library
target_link_libraries(asobo_editor PRIVATE asobo_runtime)

# Set output name
set_target_properties(asobo_editor PROPERTIES
    OUTPUT_NAME "asobo-editor"
)

# Installation
install(TARGETS asobo_editor
    RUNTIME DESTINATION bin
)
