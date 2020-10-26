#pragma once

#include <SFML/System/Vector2.hpp>

namespace Extensions
{

	template<typename T>
	struct Vector2 : public sf::Vector2<T> {
	
		using sf::Vector2<T>::Vector2;

		Vector2 & normalize()
		{
			return *this = this->normalized();
		}

		Vector2 normalized() const
		{
			Vector2 result = *this;
			const T len = result.length();
			
			if (len != 0 && len != 1)
			{
				result.x /= len;
				result.y /= len;
			}

			return result;
		}

		T lengthSq() const
		{
			return (this->x * this->x) + (this->y * this->y);
		}

		T length() const
		{
			return std::sqrt(this->lengthSq());
		}

		Vector2 & setLength(T newLength)
		{
			this->normalize();
			*this *= newLength;
			return *this;
		}

	};

	typedef Vector2<float> Vector2f;
	typedef Vector2<int32_t> Vector2i;
	typedef Vector2<uint32_t> Vector2u;

}

namespace sf
{
	template<typename T>
	Vector2<T> operator*(const Vector2<T> & lhs, const Vector2<T> & rhs)
	{
		return Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
	}
}