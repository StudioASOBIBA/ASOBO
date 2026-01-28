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
        /**
         * @brief 생성자.
         */
        explicit Vector2D() noexcept;

        /**
         * @brief 생성자.
         *
         * @param x_ 생성할 2차원 벡터의 x 좌표 값
         * @param y_ 생성할 2차원 벡터의 y 좌표 값
		 */
        explicit Vector2D(TValue x_, TValue y_) noexcept;

        /**
         * @brief 생성자.
         * 
		 * @param value 생성할 2차원 벡터의 x, y 좌표 값
         */
        explicit Vector2D(TValue value) noexcept;

        /**
         * @brief 복사 생성자.
         *
         * @param other_ 복사할 2차원 벡터
		 */
        explicit Vector2D(const Vector2D& other_) noexcept;

#pragma region Operators
        /**
		 * @brief 인덱스 연산자.
         * 
         * @param index_ 지정할 인덱스
         * 
         * @return TValue& 지정한 인덱스에 따른 해당 벡터의 좌표 값
         */
        [[nodiscard]]
        constexpr TValue& operator[](std::size_t index_) const noexcept;

        /**
		 * @brief 더하기 연산자.
         * 
		 * @param other_ 지정할 2차원 벡터
         * 
		 * @return Vector2D<TValue> 해당 2차원 벡터에 지정한 2차원 벡터와 더한 결과
         */
        [[nodiscard]]
        constexpr Vector2D<TValue> operator+(const Vector2D<TValue>& other_) const noexcept;

        /**
		 * @brief 더하기 & 대입 연산자.
         * 
         * @param other_ 지정할 2차원 벡터
         * 
		 * @return Vector2D<TValue>& 해당 2차원 벡터에 지정한 2차원 벡터를 더한 결과
         */
        [[nodiscard]]
        constexpr Vector2D<TValue>& operator+=(const Vector2D<TValue>& other_) noexcept;

        /**
		 * @brief 뺄셈 연산자.
         * 
         * @param other_ 지정할 2차원 벡터
         * 
		 * @return Vector2D<TValue> 해당 2차원 벡터에 지정한 2차원 벡터를 뺀 결과
         */
        [[nodiscard]]
        constexpr Vector2D<TValue> operator-(const Vector2D<TValue>& other_) const noexcept;

        /**
		 * @brief 뺄셈 & 대입 연산자.
         * 
         * @param other_ 지정할 2차원 벡터
         * 
		 * @return Vector2D<TValue>& 해당 2차원 벡터에 지정한 2차원 벡터를 뺀 결과
         */
        [[nodiscard]]
        constexpr Vector2D<TValue>& operator-=(const Vector2D<TValue>& other_) noexcept;

        /**
		 * @brief 곱셈 연산자.
         * 
		 * @param scalar_ 지정할 스칼라 값
         * 
		 * @return Vector2D<TValue> 해당 2차원 벡터에 지정한 스칼라 값을 곱한 결과
         */
        [[nodiscard]]
        constexpr Vector2D<TValue> operator*(TValue scalar_) const noexcept;

        /**
		 * @brief 곱셈 & 대입 연산자.
         * 
         * @param scalar_ 지정할 스칼라 값
         * 
		 * @return Vector2D<TValue> 해당 2차원 벡터에 지정한 스칼라 값을 곱한 결과
         */
        [[nodiscard]]
        constexpr Vector2D<TValue>& operator*=(TValue scalar_) noexcept;

        /**
		 * @brief 나눗셈 연산자.
         * 
         * @param scalar 지정할 스칼라 값
         * 
		 * @return Vector2D<TValue> 해당 2차원 벡터에 지정한 스칼라 값을 나눈 결과
		 */
        [[nodiscard]]
        constexpr Vector2D operator/(TValue scalar) const noexcept;

        /**
		 * @brief 나눗셈 & 대입 연산자.
         * 
		 * @param scalar 지정할 스칼라 값
         * 
		 * @return Vector2D<TValue>& 해당 2차원 벡터에 지정한 스칼라 값을 나눈 결과
         */
        constexpr Vector2D& operator/=(TValue scalar) noexcept;
#pragma endregion Operators

        /**
         * @brief x 좌표.
         */
        TValue x;

        /**
         * @brief y 좌표.
         */
        TValue y;
    };

    template <typename TValue>
		requires std::is_arithmetic_v<TValue>
    Vector2D<TValue>::Vector2D() noexcept
        : x(static_cast<TValue>(0))
        , y(static_cast<TValue>(0))
    {
	}

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    Vector2D<TValue>::Vector2D(TValue x_, TValue y_) noexcept
        : x(x_)
        , y(y_)
    {
	}

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    Vector2D<TValue>::Vector2D(TValue value) noexcept
        : x(value)
        , y(value)
    {
	}

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    Vector2D<TValue>::Vector2D(const Vector2D& other_) noexcept
        : x(other_.x)
        , y(other_.y)
    {
	}

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr TValue& Vector2D<TValue>::operator[](std::size_t index_) const noexcept
    {
        switch (index_)
        {
            case 0:
            {
                return x;
            }
            case 1:
            {
                return y;
            }
            default:
            {
                static_assert(index_ < 2, "Index out of bounds in Vector2D.");
                break;
            }
        }
	}

    template <typename TValue>
		requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue> Vector2D<TValue>::operator+(const Vector2D<TValue>& other_) const noexcept
    {
        return Vector2D<TValue>(x + other_.x, y + other_.y);
	}

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue>& Vector2D<TValue>::operator+=(const Vector2D<TValue>& other_) noexcept
    {
        x += other_.x;
        y += other_.y;

        return *this;
	}

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue> Vector2D<TValue>::operator-(const Vector2D<TValue>& other_) const noexcept
    {
        return Vector2D<TValue>(x - other_.x, y - other_.y);
	}

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue>& Vector2D<TValue>::operator-=(const Vector2D<TValue>& other_) noexcept
    {
        x -= other_.x;
        y -= other_.y;

        return *this;
	}

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue> Vector2D<TValue>::operator*(TValue scalar_) const noexcept
    {
        return Vector2D<TValue>(x * scalar_, y * scalar_);
    }
    
    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue>& Vector2D<TValue>::operator*=(TValue scalar_) noexcept
    {
        x *= scalar_;
        y *= scalar_;
        return *this;
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue> Vector2D<TValue>::operator/(TValue scalar) const noexcept
    {
        return Vector2D<TValue>(x / scalar, y / scalar);
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue>& Vector2D<TValue>::operator/=(TValue scalar) noexcept
    {
        x /= scalar;
        y /= scalar;

        return *this;
	}
} // namespace Core::Math

#endif // !AMUSE_INCLUDE_VECTOR2D_H