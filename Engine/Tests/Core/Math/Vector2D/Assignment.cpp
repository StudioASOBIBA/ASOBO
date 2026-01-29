#include "Math/Vector2D.h"

#include <format>
#include <iostream>

using namespace Amuse::Core::Math;

/**
 * @brief 좌측 값.
 */
static Vector2D<int> lhs(10, 20);

/**
 * @brief 우측 값.
 */
static Vector2D<int> rhs(30, 40);

int main(int argc_, char** argv_)
{
    // 대입 연산자 테스트
    std::cout << "Before\n";
    std::cout << std::format("lhs: ({}, {})\n", lhs.x, lhs.y);
    std::cout << std::format("rhs: ({}, {})\n", rhs.x, rhs.y);
    std::cout << '\n';

    lhs = rhs;
    std::cout << "After\n";
    std::cout << std::format("lhs: ({}, {})\n", lhs.x, lhs.y);
    std::cout << std::format("rhs: ({}, {})\n", rhs.x, rhs.y);
    std::cout << '\n';

    return 0;
}