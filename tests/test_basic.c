#include <asobo.h>
#include <assert.h>
#include <stdio.h>

void test_init_shutdown(void) {
    printf("Testing init/shutdown...\n");
    assert(asobo_init() == 0);
    asobo_shutdown();
    printf("  PASSED\n");
}

void test_version(void) {
    printf("Testing version...\n");
    const char* version = asobo_get_version();
    assert(version != NULL);
    printf("  Version: %s\n", version);
    printf("  PASSED\n");
}

void test_graphics_init_shutdown(void) {
    printf("Testing graphics init/shutdown...\n");
    assert(asobo_init() == 0);
    assert(asobo_graphics_init(ASOBO_GRAPHICS_API_OPENGL) == 0);
    asobo_graphics_shutdown();
    asobo_shutdown();
    printf("  PASSED\n");
}

void test_graphics_clear(void) {
    printf("Testing graphics clear...\n");
    assert(asobo_init() == 0);
    assert(asobo_graphics_init(ASOBO_GRAPHICS_API_OPENGL) == 0);
    asobo_graphics_clear(1.0f, 0.0f, 0.0f, 1.0f);
    asobo_graphics_shutdown();
    asobo_shutdown();
    printf("  PASSED\n");
}

int main(void) {
    printf("Running ASOBO Tests\n");
    printf("===================\n\n");
    
    test_init_shutdown();
    test_version();
    test_graphics_init_shutdown();
    test_graphics_clear();
    
    printf("\n===================\n");
    printf("All tests passed!\n");
    
    return 0;
}
