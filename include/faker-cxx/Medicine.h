#pragma once

#include <string>

namespace faker
{
class Medicine
{

public:
    /**
     * @brief Returns a random medical condition.
     *
     * @returns Medical condition.
     *
     * @code
     * Medicine::condition() // "AIDS"
     * @endcode
     *
     */
    static std::string condition();

    /**
     * @brief Returns a random medical test
     *
     * @returns Medical test.
     *
     * @code
     * Medicine::medicalTest() // "pulmonary auscultation"
     * @endcode
     *
     */
    static std::string medicalTest();

    /**
     * @brief Returns a random Medical specialty
     *
     * @returns Medical specialty.
     * @code
     * Medicine::specialty() // "Cardiology"
     * @endcode
     *
     */

    static std::string specialty();
};
}
