#ifndef AMUSE_INCLUDE_VECTOR2D_H
#define AMUSE_INCLUDE_VECTOR2D_H

#include <type_traits>

/**
 * @struct Vector2D
 *
 * @brief 2차원 벡터를 정의합니다.
 */
template <typename TValue>
    requires std::is_arithmetic_v<TValue>
class Vector2D final
{
public:
    Vector2D() noexcept
        : values(static_cast<TValue>(0), static_cast<TValue>(0))
    {
	}

    Vector2D(TValue x_, TValue y_) noexcept
        : values(x_, y_)
    {
    }

    Vector2D(TValue value) noexcept
        : values(value, value)
    {
    }

    Vector2D(const Vector2D& other_) noexcept
        : values(other_.values[0], other_.values[1])
    {
	}

    [[nodiscard]]
    constexpr TValue operator[](std::size_t index_) const noexcept
    {
        return values[index_];
	}

    [[nodiscard]]
    constexpr inline TValue GetX() const noexcept
    {
        return values[0];
    }

    inline void SetX(TValue x_) noexcept
    {
        values[0] = x_;
	}

    [[nodiscard]] 
    constexpr inline TValue GetY() const noexcept
    {
        return values[1];
    }

    inline void SetY(TValue y_) noexcept
    {
        values[1] = y_;
	}

private:
    /**
     * @brief 해당 벡터의 좌표들.
     */
    TValue values[2];
};

#endif // !AMUSE_INCLUDE_VECTOR2D_H