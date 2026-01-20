# Tests CMake configuration

# Basic test
add_executable(test_basic test_basic.c)
target_link_libraries(test_basic PRIVATE asobo_runtime)

# Add to CTest
add_test(NAME BasicTests COMMAND test_basic)
