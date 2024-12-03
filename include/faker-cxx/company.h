#pragma once

#include <optional>
#include <string>
#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::company
{
enum class CompanyNameFormat
{
    LastNameSuffix,
    FirstNameLastNameSuffix,
    FirstNameLastNameJobAreaSuffix,
};

/**
 * @brief Returns a random company name.
 *
 * @param format The optional format of the company name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Company name.
 *
 * @code
 * faker::company::companyName() // "Peterson Inc"
 * faker::company::companyName(CompanyNameFormat::FirstNameLastNameSuffix) // "Adams Peterson Inc"
 * @endcode
 */
FAKER_CXX_EXPORT std::string companyName(std::optional<CompanyNameFormat> format = std::nullopt,
                                         Locale locale = Locale::en_US);

/**
 * @brief Returns a random company type.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Company type.
 *
 * @code
 * faker::company::type() // "Nonprofit"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view type(Locale locale = Locale::en_US);

/**
 * @brief Returns a random company industry.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Company industry.
 *
 * @code
 * faker::company::industry() // "Biotechnology"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view industry(Locale locale = Locale::en_US);

/**
 * @brief Returns a random buzz phrase.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Buzz phrase.
 *
 * @code
 * faker::company::buzzPhrase() // "cultivate synergistic e-market"
 * @endcode
 */
FAKER_CXX_EXPORT std::string buzzPhrase(Locale locale = Locale::en_US);

/**
 * @brief Returns a random buzz adjective.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Buzz adjective.
 *
 * @code
 * faker::company::buzzAdjective() // "one-to-one"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view buzzAdjective(Locale locale = Locale::en_US);

/**
 * @brief Returns a random buzz noun.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Buzz noun.
 *
 * @code
 * faker::company::buzzNoun() // "paradigms"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view buzzNoun(Locale locale = Locale::en_US);

/**
 * @brief Returns a random buzz verb.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Buzz verb.
 *
 * @code
 * faker::company::buzzVerb() // "empower"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view buzzVerb(Locale locale = Locale::en_US);

/**
 * @brief Returns a random catch phrase.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Catch phrase.
 *
 * @code
 * faker::company::catchPhrase() // "Upgradable systematic flexibility"
 * @endcode
 */
FAKER_CXX_EXPORT std::string catchPhrase(Locale locale = Locale::en_US);

/**
 * @brief Returns a random catch phrase adjective.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Catch phrase adjective.
 *
 * @code
 * faker::company::catchPhraseAdjective() // "Multi-tiered"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view catchPhraseAdjective(Locale locale = Locale::en_US);

/**
 * @brief Returns a random catch phrase descriptor.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Catch phrase descriptor.
 *
 * @code
 * faker::company::catchPhraseDescriptor() // "composite"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view catchPhraseDescriptor(Locale locale = Locale::en_US);

/**
 * @brief Returns a random catch phrase noun.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * 
 * @returns Catch phrase noun.
 *
 * @code
 * faker::company::catchPhraseNoun() // "leverage"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view catchPhraseNoun(Locale locale = Locale::en_US);

}
