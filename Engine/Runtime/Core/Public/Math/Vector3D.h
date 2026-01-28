#ifndef AMUSE_INCLUDE_VECTOR3D_H
#define AMUSE_INCLUDE_VECTOR3D_H

#include <type_traits>

namespace Amuse::Core::Math
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

                /**
                 * @brief z 좌표.
                 */
				TValue z;
            };

			/**
			 * @brief 인덱싱을 위한 배열.
             */
			TValue values[3];
        };
    };
} // namespace Amuse::Math

#endif // !AMUSE_INCLUDE_VECTOR3D_H