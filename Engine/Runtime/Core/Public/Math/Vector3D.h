#ifndef AMUSE_INCLUDE_VECTOR3D_H
#define AMUSE_INCLUDE_VECTOR3D_H

#include <type_traits>

/**
 * @struct Vector3D
 *
 * @brief 3차원 벡터를 정의합니다.
 */
template <typename TValue>
    requires std::is_arithmetic_v<TValue>
class Vector3D final
{
public:
    Vector3D() noexcept
        : values(static_cast<TValue>(0), static_cast<TValue>(0), static_cast<TValue>(0))
    {
    }

    Vector3D(TValue x_, TValue y_, TValue z_) noexcept
        : values(x_, y_, z_)
    {
    }

    Vector3D(TValue value_) noexcept
        : values(value_, value_, value_)
    {
	}

    Vector3D(const Vector3D& other_) noexcept
        : values(other_.values[0], other_.values[1], other_.values[2])
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

private:
    /**
     * @brief 해당 벡터의 좌표들.
     */
    TValue values[3];
};

#endif // !AMUSE_INCLUDE_VECTOR3D_H