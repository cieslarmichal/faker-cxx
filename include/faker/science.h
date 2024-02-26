#ifndef FAKER_SCIENCE_H
#define FAKER_SCIENCE_H

#include <string_view>

namespace faker::science {
struct ChemicalElement {
    std::string_view name;
    std::string_view symbol;
    int atomicNumber;
};

inline bool operator==(const ChemicalElement& lhs, const ChemicalElement& rhs)
{
    return lhs.name == rhs.name && lhs.symbol == rhs.symbol && lhs.atomicNumber == rhs.atomicNumber;
}

/**
 * @brief Returns a random chemical element from the periodic table.
 *
 * @returns ChemicalElement
 *
 * @code
 * science::chemical_element() // Object of ChemicalElement containing info about a random
 * element in the periodic table.
 * @endcode
 */
ChemicalElement chemical_element();

struct Unit {
    std::string_view name;
    std::string_view symbol;
    std::string_view usedToMeasure;
};

inline bool operator==(const Unit& lhs, const Unit& rhs)
{
    return lhs.name == rhs.name && lhs.symbol == rhs.symbol
        && lhs.usedToMeasure == rhs.usedToMeasure;
}

inline bool operator!=(const Unit& lhs, const Unit& rhs) { return !(lhs == rhs); }

/**
 * @brief Returns a unit of measurement for either distance, mass, time, temp, current.
 *
 * @returns Unit
 *
 * @code
 * science::unit() // Object of Unit containing info about a random unit of measurement.
 * @endcode
 */
Unit unit();

/**
 * @brief Returns a unit of measurement for either distance.
 *
 * @returns Unit
 *
 * @code
 * science::distance_unit() // Object of Unit containing info about a random unit of measurement
 * used to measure distance.
 * @endcode
 */
Unit distance_unit();

/**
 * @brief Returns a unit of measurement for either time.
 *
 * @returns Unit
 *
 * @code
 * science::time_unit() // Object of Unit containing info about a random unit of measurement used
 * to measure time.
 * @endcode
 */
Unit time_unit();

/**
 * @brief Returns a unit of measurement for either mass.
 *
 * @returns Unit
 *
 * @code
 * science::mass_unit() // Object of Unit containing info about a random unit of measurement used
 * to measure mass.
 * @endcode
 */
Unit mass_unit();

/**
 * @brief Returns a unit of measurement for either temp.
 *
 * @returns Unit
 *
 * @code
 * science::temperature_unit() // Object of Unit containing info about a random unit of measurement
 * used to measure temperature.
 * @endcode
 */
Unit temperature_unit();

/**
 * @brief Returns a unit of measurement for either current.
 *
 * @returns Unit
 *
 * @code
 * science::current_unit() // Object of Unit containing info about a random unit of measurement
 * used to measure current.
 * @endcode
 */
Unit current_unit();

}

#endif