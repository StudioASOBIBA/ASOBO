#include "Math/Vector2D.h"

#include <cstdlib>
#include <ctime>
#include <format>
#include <iostream>

using namespace Amuse::Core::Math;

/**
 * @brief 좌측 값.
 */
static Vector2D<int> lhs;

/**
 * @brief 우측 값.
 */
static Vector2D<int> rhs;

int main(int argc_, char** argv_)
{
    constexpr unsigned int testCount = 5;

    std::srand(std::time(nullptr));

    for (unsigned int count = 0; count < testCount; ++count)
    {
        {
            const int x = static_cast<int>(std::rand() % RAND_MAX) + 1;
            const int y = static_cast<int>(std::rand() % RAND_MAX) + 1;

            lhs = Vector2D<int>(x, y);
            std::cout << lhs;
        }
        {
            const int x = static_cast<int>(std::rand() % RAND_MAX) + 1;
            const int y = static_cast<int>(std::rand() % RAND_MAX) + 1;

            rhs = Vector2D<int>(x, y);
            std::cout << rhs;
        }

        if (lhs > rhs || lhs >= rhs)
        {
            std::cout << "Test " << (count + 1) << ": Passed\n";
        }
        else if (lhs < rhs || lhs <= rhs)
        {
            std::cout << "Test " << (count + 1) << ": Passed\n";
        }
        else
        {
            std::cout << "Test " << (count + 1) << ": Failed\n";
        }
    }

    return 0;
}