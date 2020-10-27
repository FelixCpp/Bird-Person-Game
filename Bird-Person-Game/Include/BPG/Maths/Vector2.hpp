#pragma once

#include <type_traits>
#include <cstdint>
#include <cmath>
#include <string>

#include <SFML/System/Vector2.hpp>

namespace Maths
{

	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	struct Vector2 {
	
		static const Vector2<T> Zero;
		static const Vector2<T> Up;
		static const Vector2<T> Down;
		static const Vector2<T> Left;
		static const Vector2<T> Right;

		union { T x, width;  };
		union { T y, height; };

		inline Vector2() :
			x(T()), y(T())
		{  
		}

		inline Vector2(T x, T y) :
			x(x), y(y)
		{
		}

		template<typename O, typename = std::enable_if_t<std::is_convertible_v<O, T>>>
		inline Vector2(const Vector2<O> & other) :
			x(static_cast<T>(other.x)),
			y(static_cast<T>(other.y))
		{
		}

		inline Vector2(const sf::Vector2<T> & sfVector2) :
			x(sfVector2.x),
			y(sfVector2.y)
		{
		}

		inline T lengthSq() const
		{
			return (this->x * this->x) + (this->y * this->y);
		}

		inline T length() const
		{
			return std::sqrt(this->lengthSq());
		}

		inline T cross(const Vector2 & other) const
		{
			return this->x * other.y - this->y * other.x;
		}

		inline T dot(const Vector2 & other) const
		{
			return this->x * other.x + this->y * other.y;
		}

		inline T distance(const Vector2 & point) const
		{
			return (*this - point).length();
		}

		inline double heading() const
		{
			return std::atan2((double)this->y, (double)this->x);
		}

		inline Vector2 & normalize()
		{
			const T len = this->length();
			if (len != 0 && len != 1)
			{
				this->x /= len;
				this->y /= len;
			}

			return *this;
		}

		inline Vector2 normalized() const
		{
			return Vector2(*this).normalize();
		}

		inline Vector2 operator+() const { return Vector2( std::abs(this->x),  std::abs(this->y)); }
		inline Vector2 operator-() const { return Vector2(-std::abs(this->x), -std::abs(this->y)); }

		inline Vector2 operator+(const Vector2 & other) const { return Vector2(this->x + other.x, this->y + other.y); }
		inline Vector2 operator-(const Vector2 & other) const { return Vector2(this->x - other.x, this->y - other.y); }
		inline Vector2 operator/(const Vector2 & other) const { return Vector2(this->x / other.x, this->y / other.y); }
		inline Vector2 operator*(const Vector2 & other) const { return Vector2(this->x * other.x, this->y * other.y); }

		inline Vector2 operator+(T value) const { return Vector2(this->x + value, this->y + value); }
		inline Vector2 operator-(T value) const { return Vector2(this->x - value, this->y - value); }
		inline Vector2 operator/(T value) const { return Vector2(this->x / value, this->y / value); }
		inline Vector2 operator*(T value) const { return Vector2(this->x * value, this->y * value); }
		
		inline Vector2 & operator+=(const Vector2 & other) { return *this = *this + other; }
		inline Vector2 & operator-=(const Vector2 & other) { return *this = *this - other; }
		inline Vector2 & operator/=(const Vector2 & other) { return *this = *this / other; }
		inline Vector2 & operator*=(const Vector2 & other) { return *this = *this * other; }

		inline Vector2 & operator+=(T value) { return *this = *this + value; }
		inline Vector2 & operator-=(T value) { return *this = *this - value; }
		inline Vector2 & operator/=(T value) { return *this = *this / value; }
		inline Vector2 & operator*=(T value) { return *this = *this * value; }

		inline bool operator==(const Vector2 & other) const { return this->x == other.x && this->y == other.y; }
		inline bool operator!=(const Vector2 & other) const { return !(*this == other); }

		inline std::string toString() const
		{
			return '[' + std::to_string(this->x) + ", " + std::to_string(this->y) + ']';
		}

		inline sf::Vector2<T> toSFVector2() const
		{
			return sf::Vector2<T>(this->x, this->y);
		}

	};
	
	template<typename T> const Vector2<T> Zero  = Vector2<T>( 0,  0);
	template<typename T> const Vector2<T> Up    = Vector2<T>( 0, -1);
	template<typename T> const Vector2<T> Down  = Vector2<T>( 0,  1);
	template<typename T> const Vector2<T> Left  = Vector2<T>(-1,  0);
	template<typename T> const Vector2<T> Right = Vector2<T>( 1,  0);

	typedef Vector2<float_t>  FVector2;
	typedef Vector2<int32_t>  IVector2;
	typedef Vector2<uint32_t> UVector2;

}