#pragma once

#include "types/ChemicalElement.h"
#include "types/Unit.h"

namespace faker
{
class Science
{
public:
    /**
     * @brief Returns a random chemical element from the periodic table.
     *
     * @returns ChemicalElement
     *
     * @code
     * Science::chemicalElement() // Object of ChemicalElement containing info about a random element in the periodic
     * table.
     * @endcode
     */
    static ChemicalElement chemicalElement();

    /**
     * @brief Returns a unit of measurement for either distance, mass, time, temp, current.
     *
     * @returns Unit
     *
     * @code
     * Science::unit() // Object of Unit containing info about a random unit of measurement.
     * @endcode
     */
    static Unit unit();

    /**
     * @brief Returns a unit of measurement for either distance.
     *
     * @returns Unit
     *
     * @code
     * Science::distanceUnit() // Object of Unit containing info about a random unit of measurement used to measure
     * distance.
     * @endcode
     */
    static Unit distanceUnit();

    /**
     * @brief Returns a unit of measurement for either time.
     *
     * @returns Unit
     *
     * @code
     * Science::timeUnit() // Object of Unit containing info about a random unit of measurement used to measure time.
     * @endcode
     */
    static Unit timeUnit();

    /**
     * @brief Returns a unit of measurement for either mass.
     *
     * @returns Unit
     *
     * @code
     * Science::massUnit() // Object of Unit containing info about a random unit of measurement used to measure mass.
     * @endcode
     */
    static Unit massUnit();

    /**
     * @brief Returns a unit of measurement for either temp.
     *
     * @returns Unit
     *
     * @code
     * Science::tempUnit() // Object of Unit containing info about a random unit of measurement used to measure temp.
     * @endcode
     */
    static Unit tempUnit();

    /**
     * @brief Returns a unit of measurement for either current.
     *
     * @returns Unit
     *
     * @code
     * Science::currentUnit() // Object of Unit containing info about a random unit of measurement used to measure
     * current.
     * @endcode
     */
    static Unit currentUnit();
};

}
