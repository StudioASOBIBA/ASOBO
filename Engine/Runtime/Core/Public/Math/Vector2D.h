#ifndef AMUSE_INCLUDE_VECTOR2D_H
#define AMUSE_INCLUDE_VECTOR2D_H

#include <iostream>
#include <type_traits>

namespace Amuse::Core::Math
{
    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    struct Vector2D;

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    std::ostream& operator<<(std::ostream& os_, const Vector2D<TValue>& vec_) noexcept;

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    std::istream& operator>>(std::istream& is_, Vector2D<TValue>& vec_) noexcept;

    /**
     * @struct Vector2D
     *
     * @brief 2차원 벡터를 정의합니다.
     */
    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    struct Vector2D final
    {
#pragma region Constructor
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

        /**
         * @brief 이동 생성자.
         *
         * @param other_ 이동할 2차원 벡터
		 */
		explicit Vector2D(Vector2D&& other_) noexcept;
#pragma endregion
#pragma region Operators
        /**
		 * @brief 인덱스 연산자.
         * 
         * @param index_ 지정할 인덱스
         * 
         * @return TValue& 지정한 인덱스에 따른 해당 벡터의 좌표 값
         */
        [[nodiscard]]
        constexpr const TValue& operator[](std::size_t index_) const noexcept;

        /**
		 * @brief 덧셈 연산자.
         * 
		 * @param other_ 지정할 2차원 벡터
         * 
		 * @return Vector2D<TValue> 해당 2차원 벡터에 지정한 2차원 벡터와 더한 결과
         */
        [[nodiscard]]
        constexpr Vector2D<TValue> operator+(const Vector2D<TValue>& other_) const noexcept;

        /**
		 * @brief 덧셈 대입 연산자.
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
		 * @brief 뺄셈 대입 연산자.
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
		 * @brief 곱셈 대입 연산자.
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
		 * @brief 나눗셈 대입 연산자.
         * 
		 * @param scalar 지정할 스칼라 값
         * 
		 * @return Vector2D<TValue>& 해당 2차원 벡터에 지정한 스칼라 값을 나눈 결과
         */ 
        [[nodiscard]]
        constexpr Vector2D& operator/=(TValue scalar) noexcept;

        /**
         * @brief 동등 비교 연산자.
         *
         * @param other_ 지정할 2차원 벡터
         *
         * @return bool 지정한 2차원 벡터와 해당 2차원 벡터가 같은지 여부
         */
        [[nodiscard]]
        constexpr bool operator==(const Vector2D& other_) const noexcept;

        /**
         * @brief 부등 비교 연산자.
         *
         * @param other_ 지정할 2차원 벡터
         *
         * @return bool 지정한 2차원 벡터와 해당 2차원 벡터가 다른지 여부
         */
        [[nodiscard]]
        constexpr bool operator!=(const Vector2D& other_) const noexcept;

        /**
         * @brief 작음 비교 연산자.
         *
         * @param other_ 지정할 2차원 벡터
         *
         * @return bool 해당 2차원 벡터가 지정한 2차원 벡터보다 작은지 여부
         */
        [[nodiscard]]
        constexpr bool operator<(const Vector2D& other_) const noexcept;

        /**
         * @brief 작거나 같음 비교 연산자.
         *
         * @param other_ 지정할 2차원 벡터
         *
         * @return bool 해당 2차원 벡터가 지정한 2차원 벡터보다 작거나 같은지 여부
         */
        [[nodiscard]]
        constexpr bool operator<=(const Vector2D& other_) const noexcept;

        /**
         * @brief 큼 비교 연산자.
         *
         * @param other_ 지정할 2차원 벡터
         *
         * @return bool 해당 2차원 벡터가 지정한 2차원 벡터보다 큰지 여부
         */
        [[nodiscard]]
        constexpr bool operator>(const Vector2D& other_) const noexcept;

        /**
         * @brief 크거나 같음 비교 연산자.
         *
         * @param other_ 지정할 2차원 벡터
         *
         * @return bool 해당 2차원 벡터가 지정한 2차원 벡터보다 크거나 같은지 여부
         */
        [[nodiscard]]
        constexpr bool operator>=(const Vector2D& other_) const noexcept;

        /**
         * @brief 대입 연산자.
         *
         * @param other_ 지정할 2차원 벡터
         *
         * @return Vector2D<TValue> 해당 2차원 벡터에 지정한 2차원 벡터를 대입한 결과
         */
        constexpr Vector2D<TValue>& operator=(const Vector2D<TValue>& other_) noexcept;

        /**
         * @brief 스트림 삽입 연산자
         * 
         * @param os_  지정할 std::ostream 객체
         * @param vec_ 지정할 2차원 벡터
         * 
         * @return std::ostream& 삽입된 std::ostream 객체
         */
        friend std::ostream& operator<<<TValue>(std::ostream& os_, const Vector2D& vec_) noexcept;

		/**
		 * @brief 스트림 추출 연산자
         * 
		 * @param is_  지정할 std::istream 객체
		 * @param vec_ 지정할 2차원 벡터
         * 
		 * @return std::istream& 추출된 std::istream 객체
		 */
		friend std::istream& operator>><TValue>(std::istream& is_, Vector2D& vec_) noexcept;
#pragma endregion Operators

        union 
        {
            struct
            {
                /**
                 * @brief x 좌표.
                 */
                TValue x;

                /**
                 * @brief y 좌표.
                 */
                TValue y;
            };

            /**
			 * @brief 인덱싱을 위한 배열.
             */
            TValue values[2];
        };
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

    template<typename TValue>
		requires std::is_arithmetic_v<TValue>
    Vector2D<TValue>::Vector2D(Vector2D&& other_) noexcept
        : x(other_.x)
		, y(other_.y)
    {
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr const TValue& Vector2D<TValue>::operator[](std::size_t index_) const noexcept
    {
        return values[index_];
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

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr bool Vector2D<TValue>::operator==(const Vector2D& other_) const noexcept
    {
        return (x == other_.x) && (y == other_.y);
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr bool Vector2D<TValue>::operator!=(const Vector2D& other_) const noexcept
    {
        return (x != other_.x) && (y != other_.y);
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr Vector2D<TValue>& Vector2D<TValue>::operator=(const Vector2D<TValue>& other_) noexcept
    {
        if (this != &other_)
        {
            x = other_.x;
            y = other_.y;
        }

        return *this;
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr bool Vector2D<TValue>::operator<(const Vector2D& other_) const noexcept
    {
        return (x < other_.x) && (y < other_.y);
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr bool Vector2D<TValue>::operator<=(const Vector2D& other_) const noexcept
    {
        return (x <= other_.x) && (y <= other_.y);
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr bool Vector2D<TValue>::operator>(const Vector2D& other_) const noexcept
    {
        return (x > other_.x) && (y > other_.y);
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    constexpr bool Vector2D<TValue>::operator>=(const Vector2D& other_) const noexcept
    {
        return (x >= other_.x) && (y >= other_.y);
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    std::ostream& operator<<(std::ostream& os_, const Vector2D<TValue>& vec_) noexcept
    {
        os_ << vec_.x << ", " << vec_.y;
        return os_;
    }

    template <typename TValue>
        requires std::is_arithmetic_v<TValue>
    std::istream& operator>>(std::istream& is_, Vector2D<TValue>& vec_) noexcept
    {
        is_ >> vec_.x >> vec_.y;
        return is_;
	}
} // namespace Core::Math

#endif // !AMUSE_INCLUDE_VECTOR2D_H