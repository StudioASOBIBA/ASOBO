#ifndef ASOBO_CORE_H
#define ASOBO_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Version information */
#define ASOBO_VERSION_MAJOR 0
#define ASOBO_VERSION_MINOR 1
#define ASOBO_VERSION_PATCH 0

/* Platform detection */
#if defined(_WIN32) || defined(_WIN64)
    #define ASOBO_PLATFORM_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
    #define ASOBO_PLATFORM_MACOS
#elif defined(__linux__)
    #define ASOBO_PLATFORM_LINUX
#endif

/* API export/import macros */
#ifdef ASOBO_PLATFORM_WINDOWS
    #ifdef ASOBO_BUILD_SHARED
        #define ASOBO_API __declspec(dllexport)
    #else
        #define ASOBO_API __declspec(dllimport)
    #endif
#else
    #define ASOBO_API __attribute__((visibility("default")))
#endif

/**
 * Initialize the ASOBO runtime
 * @return 0 on success, non-zero on failure
 */
ASOBO_API int asobo_init(void);

/**
 * Shutdown the ASOBO runtime
 */
ASOBO_API void asobo_shutdown(void);

/**
 * Get ASOBO version string
 * @return Version string in format "major.minor.patch"
 */
ASOBO_API const char* asobo_get_version(void);

#ifdef __cplusplus
}
#endif

#endif /* ASOBO_CORE_H */
