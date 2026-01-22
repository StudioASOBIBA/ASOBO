#ifndef AMUSE_INCLUDE_VECTOR4D_H
#define AMUSE_INCLUDE_VECTOR4D_H

#include <type_traits>

namespace Amuse::Math
{
    /**
     * @struct Vector4D
     *
     * @brief 3차원 벡터를 정의합니다.
     */
    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    struct Vector4D final
    {
        explicit Vector4D() noexcept
            : x(static_cast<TValue>(0))
            , y(static_cast<TValue>(0))
            , z(static_cast<TValue>(0))
            , w(static_cast<TValue>(0))
        {
        }

        explicit Vector4D(TValue x_, TValue y_, TValue z_, TValue w_) noexcept
            : x(x_)
            , y(y_)
            , z(z_)
            , w(w_)
        {
        }

        explicit Vector4D(TValue value) noexcept
            : x(value)
            , y(value)
            , z(value)
            , w(value)
        {
        }

        explicit Vector4D(const Vector4D& other_) noexcept
            : x(other_.x)
            , y(other_.y)
            , z(other_.z)
            , w(other_.w)
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
                case 3:
                    return w;
                default:
                    static_assert(false, "Invalid index");
                    break;
            }
        }

        [[nodiscard]]
        constexpr Vector4D<TValue> operator+(const Vector4D<TValue>& other_) const noexcept
        {
            return Vector3D<TValue>(x + other_.x, y + other_.y, z + other_.z, w + other_.w);
		}

        [[nodiscard]]
        constexpr Vector4D<TValue> operator+=(const Vector4D<TValue>& other_) noexcept
        {
            x += other_.x;
            y += other_.y;
            z += other_.z;
            w += other_.w;

            return *this;
        }

        [[nodiscard]]
        constexpr Vector4D<TValue> operator-(const Vector4D<TValue>& other_) const noexcept
        {
            return Vector3D<TValue>(x - other_.x, y - other_.y, z - other_.z, w - other_.w);
		}

        [[nodiscard]]
        constexpr Vector4D<TValue> operator-=(const Vector4D<TValue>& other_) noexcept
        {
            x -= other_.x;
            y -= other_.y;
            z -= other_.z;
            w -= other_.w;

            return *this;
		}

        [[nodiscard]]
        constexpr Vector4D<TValue> operator*(TValue scalar_) const noexcept
        {
            return Vector4D<TValue>(x * scalar_, y * scalar_, z * scalar_, w * scalar_);
        }

        [[nodiscard]]
        constexpr Vector4D<TValue> operator*=(TValue scalar_) noexcept
        {
            x *= scalar_;
            y *= scalar_;
            z *= scalar_;
            w *= scalar_;

            return *this;
		}

        [[nodiscard]]
        constexpr Vector4D operator/(TValue scalar) const
        {
            return Vector4D(x / scalar, y / scalar, z / scalar, w / scalar);
        }

        constexpr Vector4D& operator/=(TValue scalar)
        {
            x /= scalar;
            y /= scalar;
            z /= scalar;
            w /= scalar;

            return *this;
        }

        /**
         * @brief 해당 벡터의 x 좌표.
         */
        TValue x;

        /**
         * @brief 해당 벡터의 y 좌표.
         */
        TValue y;

        /**
         * @brief 해당 벡터의 z 좌표.
         */
        TValue z;

        /**
         * @brief 해당 벡터의 w 좌표.
         */
        TValue w;
    };
} // namespace Amuse::Math

#endif // !AMUSE_INCLUDE_VECTOR4D_H