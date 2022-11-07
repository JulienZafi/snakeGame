
#include "functions/functions.hpp"

#include <random>

unsigned int randomPosition(unsigned int const min, unsigned int const max)
{
	unsigned int res{};

	std::default_random_engine defaultEngine{};
	std::uniform_int_distribution<unsigned int> randomDistribution(min, max);
	res = randomDistribution(defaultEngine);

	return res;
}
