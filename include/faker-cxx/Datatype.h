#pragma once

#include <optional>

namespace faker
{
class Datatype
{
public:
    /**
     * @brief Returns a random boolean.
     *
     * @returns Boolean.
     *
     * @code
     * Datatype::boolean() // "false"
     * @endcode
     */
    static bool boolean();

    /**
     * @brief Returns a random boolean.
     * **Note:**
     * A probability of `0.75` results in `true` being returned `75%` of the calls; likewise `0.3` => `30%`.
     * If the probability is `<= 0.0`, it will always return `false`.
     * If the probability is `>= 1.0`, it will always return `true`.
     * The probability is limited to two decimal places.
     *
     * @param probability The probability (`[0.00, 1.00]`) of returning `true`.
     *
     * @returns Boolean.
     *
     * @code
     * Datatype::boolean() // "false"
     * Datatype::boolean(0.9) // "true"
     * Datatype::boolean(0.1) // "false"
     * @endcode
     */
    static bool boolean(double probability);
};
}
