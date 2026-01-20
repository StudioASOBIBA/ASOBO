#include <asobo.h>
#include <stdio.h>

int main(void) {
    printf("ASOBO Runtime Example\n");
    printf("====================\n\n");
    
    /* Initialize runtime */
    if (asobo_init() != 0) {
        return 1;
    }
    
    /* Get version */
    printf("ASOBO Version: %s\n\n", asobo_get_version());
    
    /* Initialize graphics */
    if (asobo_graphics_init(ASOBO_GRAPHICS_API_OPENGL) != 0) {
        asobo_shutdown();
        return 1;
    }
    
    /* Clear screen */
    asobo_graphics_clear(0.0f, 0.0f, 0.0f, 1.0f);
    
    /* Cleanup */
    asobo_graphics_shutdown();
    asobo_shutdown();
    
    printf("\nExample completed successfully!\n");
    return 0;
}
