#pragma once

#include <optional>
#include <string_view>

#include "faker-cxx/export.h"

namespace faker::company
{
enum class CompanyNameFormat;
/**
 * @brief Returns a random company name.
 *
 * @returns Company name.
 *
 * @code
 * faker::company::companyName() // "Peterson Inc"
 * faker::company::companyName(CompanyNameFormat::FirstNameLastNameSuffix) // "Adams Peterson Inc"
 * @endcode
 */
FAKER_CXX_EXPORT std::string companyName(std::optional<CompanyNameFormat> format = std::nullopt);

/**
 * @brief Returns a random company type.
 *
 * @returns Company type.
 *
 * @code
 * faker::company::type() // "Nonprofit"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view type();

/**
 * @brief Returns a random company industry.
 *
 * @returns Company industry.
 *
 * @code
 * faker::company::industry() // "Biotechnology"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view industry();

/**
 * @brief Returns a random buzz phrase.
 *
 * @returns Buzz phrase.
 *
 * @code
 * faker::company::buzzPhrase() // "cultivate synergistic e-market"
 * @endcode
 */
FAKER_CXX_EXPORT std::string buzzPhrase();

/**
 * @brief Returns a random buzz adjective.
 *
 * @returns Buzz adjective.
 *
 * @code
 * faker::company::buzzAdjective() // "one-to-one"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view buzzAdjective();

/**
 * @brief Returns a random buzz noun.
 *
 * @returns Buzz noun.
 *
 * @code
 * faker::company::buzzNoun() // "paradigms"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view buzzNoun();

/**
 * @brief Returns a random buzz verb.
 *
 * @returns Buzz verb.
 *
 * @code
 * faker::company::buzzVerb() // "empower"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view buzzVerb();

/**
 * @brief Returns a random catch phrase.
 *
 * @returns Catch phrase.
 *
 * @code
 * faker::company::catchPhrase() // "Upgradable systematic flexibility"
 * @endcode
 */
FAKER_CXX_EXPORT std::string catchPhrase();

/**
 * @brief Returns a random catch phrase adjective.
 *
 * @returns Catch phrase adjective.
 *
 * @code
 * faker::company::catchPhraseAdjective() // "Multi-tiered"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view catchPhraseAdjective();

/**
 * @brief Returns a random catch phrase descriptor.
 *
 * @returns Catch phrase descriptor.
 *
 * @code
 * faker::company::catchPhraseDescriptor() // "composite"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view catchPhraseDescriptor();

/**
 * @brief Returns a random catch phrase noun.
 *
 * @returns Catch phrase noun.
 *
 * @code
 * faker::company::catchPhraseNoun() // "leverage"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view catchPhraseNoun();

enum class CompanyNameFormat
{
    LastNameSuffix,
    FirstNameLastNameSuffix,
    FirstNameLastNameJobAreaSuffix,
};
}
