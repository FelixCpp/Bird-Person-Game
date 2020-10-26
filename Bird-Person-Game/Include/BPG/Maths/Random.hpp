#pragma once

#include <random>

#include <BPG/Utils/StaticObject.hpp>

namespace Maths
{

	class Random : public Utils::StaticObject {
		
		template<typename T> inline static constexpr bool IsInt = std::_Is_any_of_v<T, short, int, long, long long, unsigned short, unsigned int, unsigned long, unsigned long long>;
		template<typename T> inline static constexpr bool IsFloatingPoint = std::_Is_any_of_v<T, float, double, long double>;

	public:

		inline static constexpr uint32_t DEFAULT_SEED = std::default_random_engine::default_seed;

		template<typename T, typename = std::enable_if_t<IsInt<T> || IsFloatingPoint<T>>>
		inline static T get(T min, T max)
		{
			if constexpr (IsInt<T>)
			{
				std::uniform_int_distribution<T> dist(min, max);
				return dist(engine);
			} else if constexpr (IsFloatingPoint<T>)
			{
				std::uniform_real_distribution<T> dist(min, max);
				return dist(engine);
			}
		}

		static void setSeed(uint32_t newSeed);

	private:

		static std::random_device device;
		static std::default_random_engine engine;

	};

}