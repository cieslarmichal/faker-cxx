#ifndef FAKER_COMPANY_H
#define FAKER_COMPANY_H

#include <string>

namespace faker::company {
/**
 * @brief Returns a random company name.
 *
 * @returns company name.
 *
 * @code
 * company::name() // "Adams Inc"
 * @endcode
 */
std::string name();

/**
 * @brief Returns a random company type.
 *
 * @returns company type.
 *
 * @code
 * company::type() // "Nonprofit"
 * @endcode
 */
std::string_view type();

/**
 * @brief Returns a random company industry.
 *
 * @returns company industry.
 *
 * @code
 * company::industry() // "Biotechnology"
 * @endcode
 */
std::string_view industry();

/**
 * @brief Returns a random buzz phrase.
 *
 * @returns Buzz phrase.
 *
 * @code
 * company::buzz_phrase() // "cultivate synergistic e-market"
 * @endcode
 */
std::string buzz_phrase();

/**
 * @brief Returns a random buzz adjective.
 *
 * @returns Buzz adjective.
 *
 * @code
 * company::buzz_adjective() // "one-to-one"
 * @endcode
 */
std::string_view buzz_adjective();

/**
 * @brief Returns a random buzz noun.
 *
 * @returns Buzz noun.
 *
 * @code
 * company::buzz_noun() // "paradigms"
 * @endcode
 */
std::string_view buzz_noun();

/**
 * @brief Returns a random buzz verb.
 *
 * @returns Buzz verb.
 *
 * @code
 * company::buzz_verb() // "empower"
 * @endcode
 */
std::string_view buzz_verb();

/**
 * @brief Returns a random catch phrase.
 *
 * @returns Catch phrase.
 *
 * @code
 * company::catch_phrase() // "Upgradable systematic flexibility"
 * @endcode
 */
std::string catch_phrase();

/**
 * @brief Returns a random catch phrase adjective.
 *
 * @returns Catch phrase adjective.
 *
 * @code
 * company::catch_phrase_adjective() // "Multi-tiered"
 * @endcode
 */
std::string_view catch_phrase_adjective();

/**
 * @brief Returns a random catch phrase descriptor.
 *
 * @returns Catch phrase descriptor.
 *
 * @code
 * company::catch_phrase_descriptor() // "composite"
 * @endcode
 */
std::string_view catch_phrase_descriptor();

/**
 * @brief Returns a random catch phrase noun.
 *
 * @returns Catch phrase noun.
 *
 * @code
 * company::catch_phrase_noun() // "leverage"
 * @endcode
 */
std::string_view catch_phrase_noun();
}

#endif