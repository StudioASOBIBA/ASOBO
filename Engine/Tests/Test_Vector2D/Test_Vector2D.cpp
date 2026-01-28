#include <format>
#include <iostream>
#include <string>
#include <string_view>

#include "Math/Vector2D.h"
#include "Math/Vector3D.h"
#include "Math/Vector4D.h"

using namespace Amuse::Math;

int main(int argc_, char** argv_)
{
	Vector2D<int> lhs(1, 1);
	Vector2D<int> rhs(2, 3);

	std::cout << std::format("lhs: ({}, {})\n", lhs.x, lhs.y);
	std::cout << std::format("rhs: ({}, {})\n", rhs.x, rhs.y);

	std::cout << std::endl;

	std::cout << std::format("lhs(with indexer): ({}, {})\n", lhs[0], lhs[1]);
	std::cout << std::format("rhs(with indexer): ({}, {})\n", rhs[0], rhs[1]);

	std::cout << std::endl;

	Vector2D<int> sum = lhs + rhs;
	std::cout << std::format("sum: ({}, {})\n", sum[0], sum[1]);

	Vector2D<int> diff = lhs - rhs;
	std::cout << std::format("diff: ({}, {})\n", diff[0], diff[1]);

	Vector2D<int> scaled = lhs * 3;
	std::cout << std::format("scaled: ({}, {})\n", scaled[0], scaled[1]);

	Vector2D<int> divided = rhs / 2;
	std::cout << std::format("divided: ({}, {})\n", divided[0], divided[1]);

	return 0;
}