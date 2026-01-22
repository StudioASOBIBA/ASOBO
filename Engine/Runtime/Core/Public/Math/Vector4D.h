#ifndef AMUSE_INCLUDE_VECTOR4D_H
#define AMUSE_INCLUDE_VECTOR4D_H

#include <type_traits>

/**
 * @struct Vector4D
 *
 * @brief 3차원 벡터를 정의합니다.
 */
template <typename TValue>
    requires std::is_arithmetic_v<TValue>
class Vector4D final
{
public:
    Vector4D() noexcept
        : values(static_cast<TValue>(0), static_cast<TValue>(0))
    {
    }

    Vector4D(TValue x_, TValue y_, TValue z_, TValue w_) noexcept
        : values(x_, y_, z_, w_)
    {
    }

    Vector4D(TValue value) noexcept
        : values(value, value, value, value)
    {
    }

    Vector4D(const Vector4D& other_) noexcept
        : values(other_.values[0], other_.values[1], other_.value[2], other_.value[3])
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

    [[nodiscard]]
    constexpr inline TValue GetZ() const noexcept
    {
        return values[2];
	}

    inline void SetZ(TValue z_) noexcept
    {
        values[2] = z_;
	}

    [[nodiscard]]
    constexpr inline TValue GetW() const noexcept
    {
        return values[3];
    }

    inline void SetW(TValue w_) noexcept
    {
        values[3] = w_;
	}

private:
    /**
     * @brief 해당 벡터의 좌표들.
     */
    TValue values[4];
};

#endif // !AMUSE_INCLUDE_VECTOR4D_H