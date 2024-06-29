#pragma once

#include <string_view>
#include "faker-cxx/Export.h"

namespace faker::science
{
struct FAKER_CXX_EXPORT ChemicalElement
{
    std::string_view name;
    std::string_view symbol;
    int atomicNumber;
};

/**
 * @brief Returns a random chemical element from the periodic table.
 *
 * @returns ChemicalElement
 *
 * @code
 * faker::science::chemicalElement() // Object of ChemicalElement containing info about a random element in the periodic
 * table.
 * @endcode
 */
FAKER_CXX_EXPORT ChemicalElement chemicalElement();

struct FAKER_CXX_EXPORT Unit
{
    std::string_view name;
    std::string_view symbol;
    std::string_view usedToMeasure;
};

/**
 * @brief Returns a unit of measurement for either distance, mass, time, temp, current.
 *
 * @returns Unit
 *
 * @code
 * faker::science::unit() // Object of Unit containing info about a random unit of measurement.
 * @endcode
 */
FAKER_CXX_EXPORT Unit unit();

/**
 * @brief Returns a unit of measurement for either distance.
 *
 * @returns Unit
 *
 * @code
 * faker::science::distanceUnit() // Object of Unit containing info about a random unit of measurement used to measure
 * distance.
 * @endcode
 */
FAKER_CXX_EXPORT Unit distanceUnit();

/**
 * @brief Returns a unit of measurement for either time.
 *
 * @returns Unit
 *
 * @code
 * faker::science::timeUnit() // Object of Unit containing info about a random unit of measurement used to measure time.
 * @endcode
 */
FAKER_CXX_EXPORT Unit timeUnit();

/**
 * @brief Returns a unit of measurement for either mass.
 *
 * @returns Unit
 *
 * @code
 * faker::science::massUnit() // Object of Unit containing info about a random unit of measurement used to measure mass.
 * @endcode
 */
FAKER_CXX_EXPORT Unit massUnit();

/**
 * @brief Returns a unit of measurement for either temp.
 *
 * @returns Unit
 *
 * @code
 * faker::science::tempUnit() // Object of Unit containing info about a random unit of measurement used to measure temp.
 * @endcode
 */
FAKER_CXX_EXPORT Unit tempUnit();

/**
 * @brief Returns a unit of measurement for either current.
 *
 * @returns Unit
 *
 * @code
 * faker::science::currentUnit() // Object of Unit containing info about a random unit of measurement used to measure
 * current.
 * @endcode
 */
FAKER_CXX_EXPORT Unit currentUnit();
}
