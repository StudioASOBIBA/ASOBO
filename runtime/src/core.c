#include "asobo/core.h"
#include <stdio.h>

static int asobo_initialized = 0;

int asobo_init(void) {
    if (asobo_initialized) {
        fprintf(stderr, "ASOBO: Already initialized\n");
        return 1;
    }
    
    printf("ASOBO Runtime v%d.%d.%d initializing...\n",
           ASOBO_VERSION_MAJOR, ASOBO_VERSION_MINOR, ASOBO_VERSION_PATCH);
    
    #ifdef ASOBO_PLATFORM_WINDOWS
    printf("Platform: Windows\n");
    #elif defined(ASOBO_PLATFORM_MACOS)
    printf("Platform: macOS\n");
    #elif defined(ASOBO_PLATFORM_LINUX)
    printf("Platform: Linux\n");
    #endif
    
    asobo_initialized = 1;
    printf("ASOBO Runtime initialized successfully\n");
    
    return 0;
}

void asobo_shutdown(void) {
    if (!asobo_initialized) {
        fprintf(stderr, "ASOBO: Not initialized\n");
        return;
    }
    
    printf("ASOBO Runtime shutting down...\n");
    asobo_initialized = 0;
    printf("ASOBO Runtime shutdown complete\n");
}

const char* asobo_get_version(void) {
    static char version[32];
    snprintf(version, sizeof(version), "%d.%d.%d",
             ASOBO_VERSION_MAJOR, ASOBO_VERSION_MINOR, ASOBO_VERSION_PATCH);
    return version;
}
