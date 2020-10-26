#include <BPG/Maths/Random.hpp>

namespace Maths
{

	std::random_device Random::device;
	std::default_random_engine Random::engine(device());

	void Random::setSeed(uint32_t newSeed)
	{
		engine.seed(newSeed);
	}

}