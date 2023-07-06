#include "Number.h"

namespace faker
{

/**
 * @brief A random device used to seed the Number module pseudo-random generator.
 *
 */
std::random_device Number::randomDevice;

/**
 * @brief A pseudo-random generator used to generate random numbers.
 *
 */
std::mt19937 Number::pseudoRandomGenerator(Number::randomDevice());
}