#include "Math/Vector2D.h"

#include <format>
#include <iostream>
#include <string>
#include <string_view>

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
	std::cout << std::format("lhs: ({}, {})\n", lhs.x, lhs.y);
	std::cout << std::format("rhs: ({}, {})\n", rhs.x, rhs.y);
	std::cout << std::endl;

	// case 1. 덧셈
	Vector2D<int> sum = lhs + rhs;
	std::cout << std::format("sum: ({}, {})\n", sum[0], sum[1]);

	// case 2. 뺄셈
	Vector2D<int> diff = lhs - rhs;
	std::cout << std::format("diff: ({}, {})\n", diff[0], diff[1]);

	// case 3. 스칼라 곱셈
	Vector2D<int> scaled = lhs * 3;
	std::cout << std::format("scaled: ({}, {})\n", scaled[0], scaled[1]);

	// case 4. 스칼라 나눗셈
	Vector2D<int> divided = rhs / 2;
	std::cout << std::format("divided: ({}, {})\n", divided[0], divided[1]);

	return 0;
}