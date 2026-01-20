#ifndef ASOBO_GRAPHICS_H
#define ASOBO_GRAPHICS_H

#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Graphics API types */
typedef enum {
    ASOBO_GRAPHICS_API_OPENGL,
    ASOBO_GRAPHICS_API_VULKAN,
    ASOBO_GRAPHICS_API_DIRECTX,
    ASOBO_GRAPHICS_API_METAL
} AsoboGraphicsAPI;

/**
 * Initialize graphics subsystem
 * @param api Graphics API to use
 * @return 0 on success, non-zero on failure
 */
ASOBO_API int asobo_graphics_init(AsoboGraphicsAPI api);

/**
 * Shutdown graphics subsystem
 */
ASOBO_API void asobo_graphics_shutdown(void);

/**
 * Clear the screen with specified color
 * @param r Red component (0.0 - 1.0)
 * @param g Green component (0.0 - 1.0)
 * @param b Blue component (0.0 - 1.0)
 * @param a Alpha component (0.0 - 1.0)
 */
ASOBO_API void asobo_graphics_clear(float r, float g, float b, float a);

#ifdef __cplusplus
}
#endif

#endif /* ASOBO_GRAPHICS_H */
