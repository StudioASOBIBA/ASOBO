add_executable(Example1 "Example1.cpp")
target_link_libraries(Example1 PRIVATE Runtime)

set_target_properties(Example1 PROPERTIES
    RUNTIME_OUTPUT_NAME "Example1"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/Examples"
)

install(TARGETS Example1
    RUNTIME DESTINATION bin/Examples
)