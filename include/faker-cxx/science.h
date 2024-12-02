#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

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
 * @returns Chemical element.
 *
 * @code
 * faker::science::chemicalElement() // Object of ChemicalElement containing info about a random element in the periodic
 * table.
 * @endcode
 */
FAKER_CXX_EXPORT ChemicalElement chemicalElement(Locale locale = Locale::en_US);

struct FAKER_CXX_EXPORT Unit
{
    std::string_view name;
    std::string_view symbol;
    std::string_view usedToMeasure;
};

/**
 * @brief Returns a unit of measurement for either distance, mass, time, temp, current.
 *
 * @returns Unit.
 *
 * @code
 * faker::science::unit() // Object of Unit containing info about a random unit of measurement.
 * @endcode
 */
FAKER_CXX_EXPORT Unit unit(Locale locale = Locale::en_US);

/**
 * @brief Returns a unit of measurement for either distance.
 *
 * @returns Distance unit.
 *
 * @code
 * faker::science::distanceUnit() // Object of Unit containing info about a random unit of measurement used to measure
 * distance.
 * @endcode
 */
FAKER_CXX_EXPORT Unit distanceUnit(Locale locale = Locale::en_US);

/**
 * @brief Returns a unit of measurement for either time.
 *
 * @returns Time unit.
 *
 * @code
 * faker::science::timeUnit() // Object of Unit containing info about a random unit of measurement used to measure time.
 * @endcode
 */
FAKER_CXX_EXPORT Unit timeUnit(Locale locale = Locale::en_US);

/**
 * @brief Returns a unit of measurement for either mass.
 *
 * @returns Mass unit.
 *
 * @code
 * faker::science::massUnit() // Object of Unit containing info about a random unit of measurement used to measure mass.
 * @endcode
 */
FAKER_CXX_EXPORT Unit massUnit(Locale locale = Locale::en_US);

/**
 * @brief Returns a unit of measurement for either temp.
 *
 * @returns Temperture unit.
 *
 * @code
 * faker::science::tempUnit() // Object of Unit containing info about a random unit of measurement used to measure temp.
 * @endcode
 */
FAKER_CXX_EXPORT Unit tempUnit(Locale locale = Locale::en_US);

/**
 * @brief Returns a unit of measurement for either current.
 *
 * @returns Current unit.
 *
 * @code
 * faker::science::currentUnit() // Object of Unit containing info about a random unit of measurement used to measure
 * current.
 * @endcode
 */
FAKER_CXX_EXPORT Unit currentUnit(Locale locale = Locale::en_US);
}
