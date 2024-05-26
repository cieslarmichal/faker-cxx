#pragma once

#include <string_view>

namespace faker
{
class Company
{
public:
    /**
     * @brief Returns a random company name.
     *
     * @returns Company name.
     *
     * @code
     * Company::name() // "Adams Inc"
     * @endcode
     */
    static std::string name();

    /**
     * @brief Returns a random company type.
     *
     * @returns Company type.
     *
     * @code
     * Company::type() // "Nonprofit"
     * @endcode
     */
    static std::string_view type();

    /**
     * @brief Returns a random company industry.
     *
     * @returns Company industry.
     *
     * @code
     * Company::industry() // "Biotechnology"
     * @endcode
     */
    static std::string_view industry();

    /**
     * @brief Returns a random buzz phrase.
     *
     * @returns Buzz phrase.
     *
     * @code
     * Company::buzzPhrase() // "cultivate synergistic e-market"
     * @endcode
     */
    static std::string buzzPhrase();

    /**
     * @brief Returns a random buzz adjective.
     *
     * @returns Buzz adjective.
     *
     * @code
     * Company::buzzAdjective() // "one-to-one"
     * @endcode
     */
    static std::string_view buzzAdjective();

    /**
     * @brief Returns a random buzz noun.
     *
     * @returns Buzz noun.
     *
     * @code
     * Company::buzzNoun() // "paradigms"
     * @endcode
     */
    static std::string_view buzzNoun();

    /**
     * @brief Returns a random buzz verb.
     *
     * @returns Buzz verb.
     *
     * @code
     * Company::buzzVerb() // "empower"
     * @endcode
     */
    static std::string_view buzzVerb();

    /**
     * @brief Returns a random catch phrase.
     *
     * @returns Catch phrase.
     *
     * @code
     * Company::catchPhrase() // "Upgradable systematic flexibility"
     * @endcode
     */
    static std::string catchPhrase();

    /**
     * @brief Returns a random catch phrase adjective.
     *
     * @returns Catch phrase adjective.
     *
     * @code
     * Company::catchPhraseAdjective() // "Multi-tiered"
     * @endcode
     */
    static std::string_view catchPhraseAdjective();

    /**
     * @brief Returns a random catch phrase descriptor.
     *
     * @returns Catch phrase descriptor.
     *
     * @code
     * Company::catchPhraseDescriptor() // "composite"
     * @endcode
     */
    static std::string_view catchPhraseDescriptor();

    /**
     * @brief Returns a random catch phrase noun.
     *
     * @returns Catch phrase noun.
     *
     * @code
     * Company::catchPhraseNoun() // "leverage"
     * @endcode
     */
    static std::string_view catchPhraseNoun();
};
}
