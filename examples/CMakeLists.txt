# Examples CMake configuration

# Basic example
add_executable(basic_example basic_example.c)
target_link_libraries(basic_example PRIVATE asobo_runtime)

set_target_properties(basic_example PROPERTIES
    OUTPUT_NAME "basic-example"
)

# Installation
install(TARGETS basic_example
    RUNTIME DESTINATION bin/examples
)
