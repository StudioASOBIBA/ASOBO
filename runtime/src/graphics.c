#include "asobo/graphics.h"
#include <stdio.h>

static int graphics_initialized = 0;
static AsoboGraphicsAPI current_api;

int asobo_graphics_init(AsoboGraphicsAPI api) {
    if (graphics_initialized) {
        fprintf(stderr, "ASOBO Graphics: Already initialized\n");
        return 1;
    }
    
    current_api = api;
    
    const char* api_name = "Unknown";
    switch (api) {
        case ASOBO_GRAPHICS_API_OPENGL:
            api_name = "OpenGL";
            break;
        case ASOBO_GRAPHICS_API_VULKAN:
            api_name = "Vulkan";
            break;
        case ASOBO_GRAPHICS_API_DIRECTX:
            api_name = "DirectX";
            break;
        case ASOBO_GRAPHICS_API_METAL:
            api_name = "Metal";
            break;
    }
    
    printf("ASOBO Graphics initializing with %s API...\n", api_name);
    graphics_initialized = 1;
    printf("ASOBO Graphics initialized successfully\n");
    
    return 0;
}

void asobo_graphics_shutdown(void) {
    if (!graphics_initialized) {
        fprintf(stderr, "ASOBO Graphics: Not initialized\n");
        return;
    }
    
    printf("ASOBO Graphics shutting down...\n");
    graphics_initialized = 0;
    printf("ASOBO Graphics shutdown complete\n");
}

void asobo_graphics_clear(float r, float g, float b, float a) {
    if (!graphics_initialized) {
        fprintf(stderr, "ASOBO Graphics: Not initialized\n");
        return;
    }
    
    /* Placeholder implementation */
    printf("Clearing screen with color RGBA(%.2f, %.2f, %.2f, %.2f)\n", r, g, b, a);
}
