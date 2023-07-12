#pragma once

#include <string>

namespace faker
{
class Company
{
public:
    /**
     * @brief Returns a random company name.
     *
     * @returns Company name
     *
     * @code
     * Company::name() // "Adams Inc"
     * @endcode
     */
    static std::string name();
};
}
