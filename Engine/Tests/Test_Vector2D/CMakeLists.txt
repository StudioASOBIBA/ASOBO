add_executable(Test_Vector2D "Test_Vector2D.cpp")
target_link_libraries(Test_Vector2D PRIVATE Runtime)

set_target_properties(Test_Vector2D PROPERTIES
    RUNTIME_OUTPUT_NAME "Test_Vector2D"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/Tests/Test_Vector2D"
)

install(TARGETS Test_Vector2D
    RUNTIME DESTINATION bin/Tests
)