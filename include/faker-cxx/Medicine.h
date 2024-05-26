#pragma once

#include <string_view>

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
     */
    static std::string_view condition();

    /**
     * @brief Returns a random medical test
     *
     * @returns Medical test.
     *
     * @code
     * Medicine::medicalTest() // "pulmonary auscultation"
     * @endcode
     */
    static std::string_view medicalTest();

    /**
     * @brief Returns a random Medical specialty
     *
     * @returns Medical specialty.
     *
     * @code
     * Medicine::specialty() // "Cardiology"
     * @endcode
     */

    static std::string_view specialty();
};
}
