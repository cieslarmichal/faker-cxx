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
 * science::chemicalElement() // Object of ChemicalElement containing info about a random
 * element in the periodic table.
 * @endcode
 */
ChemicalElement chemicalElement();

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
 * science::distanceUnit() // Object of Unit containing info about a random unit of measurement
 * used to measure distance.
 * @endcode
 */
Unit distanceUnit();

/**
 * @brief Returns a unit of measurement for either time.
 *
 * @returns Unit
 *
 * @code
 * science::timeUnit() // Object of Unit containing info about a random unit of measurement used
 * to measure time.
 * @endcode
 */
Unit timeUnit();

/**
 * @brief Returns a unit of measurement for either mass.
 *
 * @returns Unit
 *
 * @code
 * science::massUnit() // Object of Unit containing info about a random unit of measurement used
 * to measure mass.
 * @endcode
 */
Unit massUnit();

/**
 * @brief Returns a unit of measurement for either temp.
 *
 * @returns Unit
 *
 * @code
 * science::tempUnit() // Object of Unit containing info about a random unit of measurement used
 * to measure temp.
 * @endcode
 */
Unit tempUnit();

/**
 * @brief Returns a unit of measurement for either current.
 *
 * @returns Unit
 *
 * @code
 * science::currentUnit() // Object of Unit containing info about a random unit of measurement
 * used to measure current.
 * @endcode
 */
Unit currentUnit();

}

#endif