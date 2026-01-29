#include <iostream>

int main(int, char**)
{
#if defined(AMUSE_PLATFORM_WINDOWS)
        std::cout << "Platform: Windows\n";
#elif defined(AMUSE_PLATFORM_LINUX)
        std::cout << "Platform: Linux\n";
#elif defined(AMUSE_PLATFORM_MACOS)
        std::cout << "Platform: macOS\n";
#else
        std::cout << "Platform: Unknown\n";
#endif
}