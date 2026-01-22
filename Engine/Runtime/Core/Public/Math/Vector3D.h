#ifndef AMUSE_INCLUDE_VECTOR3D_H
#define AMUSE_INCLUDE_VECTOR3D_H

#include <type_traits>

namespace Amuse::Math
{
    /**
     * @struct Vector3D
     *
     * @brief 3차원 벡터를 정의합니다.
     */
    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    struct Vector3D final
    {
        explicit Vector3D() noexcept
            : x(static_cast<TValue>(0))
            , y(static_cast<TValue>(0))
            , z(static_cast<TValue>(0))
        {
        }

        explicit Vector3D(TValue x_, TValue y_, TValue z_) noexcept
            : x(x_)
            , y(y_)
            , z(z_)
        {
        }

        explicit Vector3D(TValue value) noexcept
            : x(value)
            , y(value)
            , z(value)
        {
        }

        explicit Vector3D(const Vector3D& other_) noexcept
            : x(other_.x)
            , y(other_.y)
            , z(other_.z)
        {
        }

        [[nodiscard]]
        constexpr const TValue& operator[](std::size_t index_) const noexcept
        {
            switch (index_)
            {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                default:
                    static_assert(false, "Invalid index");
                    break;
            }
        }

        [[nodiscard]]
        constexpr Vector3D<TValue> operator+(const Vector3D<TValue>& other_) const noexcept
        {
            return Vector3D<TValue>(x + other_.x, y + other_.y, z + other_.z);
		}

        [[nodiscard]]
        constexpr Vector3D<TValue> operator+=(const Vector3D<TValue>& other_) noexcept
        {
            x += other_.x;
            y += other_.y;
            z += other_.z;

            return *this;
        }

        [[nodiscard]]
        constexpr Vector3D<TValue> operator-(const Vector3D<TValue>& other_) const noexcept
        {
            return Vector3D<TValue>(x - other_.x, y - other_.y, z - other_.z);
		}

        [[nodiscard]]
        constexpr Vector3D<TValue> operator-=(const Vector3D<TValue>& other_) noexcept
        {
            x -= other_.x;
            y -= other_.y;
            z -= other_.z;

            return *this;
		}

        [[nodiscard]]
        constexpr Vector3D<TValue> operator*(TValue scalar_) const noexcept
        {
            return Vector3D<TValue>(x * scalar_, y * scalar_, z * scalar_);
        }

        [[nodiscard]]
        constexpr Vector3D<TValue> operator*=(TValue scalar_) noexcept
        {
            x *= scalar_;
            y *= scalar_;
            z *= scalar_;

            return *this;
		}

        [[nodiscard]]
        constexpr Vector3D operator/(TValue scalar) const
        {
            return Vector3D(x / scalar, y / scalar, z / scalar);
        }

        constexpr Vector3D& operator/=(TValue scalar)
        {
            x /= scalar;
            y /= scalar;
            z /= scalar;

            return *this;
        }

        /**
         * @brief
         */
        TValue x;

        /**
         * @brief
         */
        TValue y;

        /**
         * @brief
         */
        TValue z;
    };
} // namespace Amuse::Math

#endif // !AMUSE_INCLUDE_VECTOR3D_H