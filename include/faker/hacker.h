#pragma once

#include <string>

namespace faker::hacker {
/**
 * @brief Returns a hacker abbreviation.
 *
 * @returns abbreviation.
 *
 * @code
 * hacker::abbreviation() // "TCP"
 * @endcode
 */
std::string_view abbreviation();

/**
 * @brief Returns a random adjective.
 *
 * @returns adjective.
 *
 * @code
 * hacker::adjective() // "open-source"
 * @endcode
 */
std::string_view adjective();

/**
 * @brief Returns a random noun.
 *
 * @returns noun.
 *
 * @code
 * hacker::noun() // "coder"
 * @endcode
 */
std::string_view noun();

/**
 * @brief Returns a random verb.
 *
 * @returns verb.
 *
 * @code
 * hacker::verb() // "run"
 * @endcode
 */
std::string_view verb();

/**
 * @brief Returns a random ingverb.
 *
 * @returns ingverb.
 *
 * @code
 * hacker::ingverb() // "backing up"
 * @endcode
 */
std::string_view ingverb();

/**
 * @brief Returns a random phrase.
 *
 * @return phrase.
 *
 * @code
 * hacker::phrase() // "If we bypass the monitor, we can get to the TCP monitor through the
 * neural EXE monitor!"
 * @endcode
 */
std::string phrase();
}
