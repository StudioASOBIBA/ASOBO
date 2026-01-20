#include <asobo.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("===========================================\n");
    printf("  ASOBO Editor v%s\n", asobo_get_version());
    printf("  Multi-platform 3D/2D Game Editor\n");
    printf("===========================================\n\n");
    
    /* Initialize ASOBO runtime */
    if (asobo_init() != 0) {
        fprintf(stderr, "Failed to initialize ASOBO runtime\n");
        return 1;
    }
    
    /* Initialize graphics subsystem */
    #ifdef ASOBO_PLATFORM_WINDOWS
    if (asobo_graphics_init(ASOBO_GRAPHICS_API_DIRECTX) != 0) {
    #elif defined(ASOBO_PLATFORM_MACOS)
    if (asobo_graphics_init(ASOBO_GRAPHICS_API_METAL) != 0) {
    #else
    if (asobo_graphics_init(ASOBO_GRAPHICS_API_OPENGL) != 0) {
    #endif
        fprintf(stderr, "Failed to initialize graphics\n");
        asobo_shutdown();
        return 1;
    }
    
    printf("\nEditor is running. Press Ctrl+C to exit.\n");
    printf("(This is a minimal editor placeholder)\n\n");
    
    /* Simulate editor loop */
    asobo_graphics_clear(0.2f, 0.3f, 0.3f, 1.0f);
    
    /* Cleanup */
    asobo_graphics_shutdown();
    asobo_shutdown();
    
    return 0;
}
