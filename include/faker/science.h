#ifndef FAKER_SCIENCE_H
#define FAKER_SCIENCE_H

#include <string_view>

namespace faker::science {
struct chemical_element_info {
    std::string_view name;
    std::string_view symbol;
    unsigned atomic_number;
};

inline bool operator==(const chemical_element_info& lhs, const chemical_element_info& rhs)
{
    return lhs.name == rhs.name && lhs.symbol == rhs.symbol && lhs.atomic_number == rhs.atomic_number;
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
chemical_element_info chemical_element();

struct unit_info {
    std::string_view name;
    std::string_view symbol;
    std::string_view used_to_measure;
};

inline bool operator==(const unit_info& lhs, const unit_info& rhs)
{
    return lhs.name == rhs.name && lhs.symbol == rhs.symbol
        && lhs.used_to_measure == rhs.used_to_measure;
}

inline bool operator!=(const unit_info& lhs, const unit_info& rhs) { return !(lhs == rhs); }

/**
 * @brief Returns a unit of measurement for either distance, mass, time, temp, current.
 *
 * @returns Unit
 *
 * @code
 * science::unit() // Object of unit_info containing info about a random unit of measurement.
 * @endcode
 */
unit_info unit();

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
unit_info distance_unit();

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
unit_info time_unit();

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
unit_info mass_unit();

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
unit_info temperature_unit();

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
unit_info current_unit();

}

#endif