#pragma once

#include <string_view>
#include "faker-cxx/export.h"

namespace faker::hacker
{
    /**
     * @brief Returns a hacker abbreviation.
     *
     * @returns abbreviation.
     *
     * @code
     * faker::hacker::abbreviation() // "TCP"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view abbreviation();

    /**
     * @brief Returns a random adjective.
     *
     * @returns adjective.
     *
     * @code
     * faker::hacker::adjective() // "open-source"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view adjective();

    /**
     * @brief Returns a random noun.
     *
     * @returns noun.
     *
     * @code
     * faker::hacker::noun() // "coder"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view noun();

    /**
     * @brief Returns a random verb.
     *
     * @returns verb.
     *
     * @code
     * faker::hacker::verb() // "run"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view verb();

    /**
     * @brief Returns a random ingverb.
     *
     * @returns ingverb.
     *
     * @code
     * faker::hacker::ingverb() // "backing up"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view ingverb();

    /**
     * @brief Returns a random phrase.
     *
     * @return phrase.
     *
     * @code
     * faker::hacker::phrase() // "If we bypass the monitor, we can get to the TCP monitor through the neural EXE monitor!"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string phrase();
}
