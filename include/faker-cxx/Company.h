#pragma once

#include <string_view>

namespace faker::company
{
/**
 * @brief Returns a random company name.
 *
 * @returns Company name.
 *
 * @code
 * company::name() // "Adams Inc"
 * @endcode
 */
std::string name();

/**
 * @brief Returns a random company type.
 *
 * @returns Company type.
 *
 * @code
 * company::type() // "Nonprofit"
 * @endcode
 */
std::string_view type();

/**
 * @brief Returns a random company industry.
 *
 * @returns Company industry.
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
 * company::buzzPhrase() // "cultivate synergistic e-market"
 * @endcode
 */
std::string buzzPhrase();

/**
 * @brief Returns a random buzz adjective.
 *
 * @returns Buzz adjective.
 *
 * @code
 * company::buzzAdjective() // "one-to-one"
 * @endcode
 */
std::string_view buzzAdjective();

/**
 * @brief Returns a random buzz noun.
 *
 * @returns Buzz noun.
 *
 * @code
 * company::buzzNoun() // "paradigms"
 * @endcode
 */
std::string_view buzzNoun();

/**
 * @brief Returns a random buzz verb.
 *
 * @returns Buzz verb.
 *
 * @code
 * company::buzzVerb() // "empower"
 * @endcode
 */
std::string_view buzzVerb();

/**
 * @brief Returns a random catch phrase.
 *
 * @returns Catch phrase.
 *
 * @code
 * company::catchPhrase() // "Upgradable systematic flexibility"
 * @endcode
 */
std::string catchPhrase();

/**
 * @brief Returns a random catch phrase adjective.
 *
 * @returns Catch phrase adjective.
 *
 * @code
 * company::catchPhraseAdjective() // "Multi-tiered"
 * @endcode
 */
std::string_view catchPhraseAdjective();

/**
 * @brief Returns a random catch phrase descriptor.
 *
 * @returns Catch phrase descriptor.
 *
 * @code
 * company::catchPhraseDescriptor() // "composite"
 * @endcode
 */
std::string_view catchPhraseDescriptor();

/**
 * @brief Returns a random catch phrase noun.
 *
 * @returns Catch phrase noun.
 *
 * @code
 * company::catchPhraseNoun() // "leverage"
 * @endcode
 */
std::string_view catchPhraseNoun();
}
