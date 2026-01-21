#ifndef GUARD_VECTOR2D_H
#define GUARD_VECTOR2D_H

#include <type_traits>

/**
 * @struct Vector2D
 *
 * @brief 2차원 벡터를 정의합니다.
 */
template <typename TValue>
    requires std::is_arithmetic_v<TValue>
struct Vector2D final
{
    /**
     * @brief X 좌표.
     */
    TValue x;

    /**
     * @brief Y 좌표.
     */
    TValue y;
};

#endif // !GUARD_VECTOR2D_H