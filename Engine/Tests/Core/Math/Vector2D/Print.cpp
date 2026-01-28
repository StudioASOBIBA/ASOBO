#include <Math/Vector2D.h>

#include <cstdio>
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

int main(int, char**)
{
	// case 1. 직접 값을 참조하여 출력
	std::printf("LHS(without index): (%d, %d)\n", lhs.x, lhs.y);
	std::printf("RHS(without index): (%d, %d)\n", rhs.x, rhs.y);
	std::putchar('\n');

	// case 2. 인덱스를 사용하여 출력
	std::printf("LHS(with index): (%d, %d)\n", lhs[0], lhs[1]);
	std::printf("RHS(with index): (%d, %d)\n", rhs[0], rhs[1]);
	std::putchar('\n');

	// case 3. 입/출력 연산자를 사용하여 출력
	std::cout << "LHS(with isteam operator)" << lhs << "\n";
	std::cout << "RHS(with isteam operator)" << rhs << "\n";
}