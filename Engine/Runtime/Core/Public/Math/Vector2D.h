#ifndef AMUSE_INCLUDE_VECTOR2D_H
#define AMUSE_INCLUDE_VECTOR2D_H

#include <type_traits>

namespace Amuse::Math
{
    /**
     * @struct Vector2D
     *
     * @brief 2차원 벡터를 정의합니다.
     */
    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    struct Vector2D final
    {
        explicit Vector2D() noexcept
            : values(static_cast<TValue>(0), static_cast<TValue>(0))
        {
        }

        explicit Vector2D(TValue x_, TValue y_) noexcept
            : values(x_, y_)
        {
        }

        explicit Vector2D(TValue value) noexcept
            : values(value, value)
        {
        }

        explicit Vector2D(const Vector2D& other_) noexcept
            : values(other_.values[0], other_.values[1])
        {
        }

        [[nodiscard]]
        constexpr const TValue& operator[](std::size_t index_) const noexcept
        {
            return values[index_];
        }

        [[nodiscard]]
        constexpr Vector2D<TValue> operator+(const Vector2D<TValue>& other_) const noexcept
        {
            return Vector2D<TValue>(x + other_.values[0], y + other_.values[1]);
		}

        [[nodiscard]]
        constexpr Vector2D<TValue> operator+=(const Vector2D<TValue>& other_) noexcept
        {
            x += other_.x;
            y += other_.y;

            return *this;
        }

        [[nodiscard]]
        constexpr Vector2D<TValue> operator-(const Vector2D<TValue>& other_) const noexcept
        {
            return Vector2D<TValue>(x - other_.values[0], y - other_.values[1]);
		}

        [[nodiscard]]
        constexpr Vector2D<TValue> operator-=(const Vector2D<TValue>& other_) noexcept
        {
            x -= other_.x;
            y -= other_.y;

            return *this;
		}

        [[nodiscard]]
        constexpr Vector2D<TValue> operator*(TValue scalar_) const noexcept
        {
            return Vector2D<TValue>(x * scalar_, y * scalar_);
        }

        [[nodiscard]]
        constexpr Vector2D<TValue> operator*=(TValue scalar_) noexcept
        {
            x *= scalar_;
            y *= scalar_;

            return *this;
		}

        [[nodiscard]]
        constexpr Vector2D operator/(TValue scalar) const
        {
            return Vector2D(x / scalar, y / scalar);
        }

        constexpr Vector2D& operator/=(TValue scalar)
        {
            x /= scalar;
            y /= scalar;

            return *this;
        }

        /**
         * @brief x 좌표.
         */
        TValue x;

        /**
         * @brief y 좌표.
         */
        TValue y;
    };
} // namespace Core::Math

#endif // !AMUSE_INCLUDE_VECTOR2D_H