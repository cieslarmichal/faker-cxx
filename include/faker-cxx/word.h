#pragma once

#include <algorithm>
#include <optional>
#include <string>
#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/helper.h"

#include "faker-cxx/types/locale.h"

namespace faker::word
{
/**
 * @brief fills the tables with differente languages words
 * 
 */
FAKER_CXX_EXPORT   void init();
/**
 * @brief Returns a random .
 *
 * @param length The expected length of the .
 * If no  with given length will be found, it will return a random .
 *
 * @returns Random sample word.
 *
 * @code
 * faker::word::sample() // "protection"
 * faker::word::sample(5) // "spell"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view sample(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a string containing a number of space separated random words.
 *
 * @param numberOfWords The number of words to generate.
 *
 * @returns Random words separated with spaces.
 *
 * @code
 * faker::word::words() // "protection"
 * faker::word::words(5) // "before hourly patiently dribble equal"
 * @endcode
 */
FAKER_CXX_EXPORT std::string words(unsigned numberOfWords = 1);

/**
 * @brief Returns a random adjective.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Adjective.
 *
 * @code
 * faker::word::adjective() // "complete"
 * faker::word::adjective(3) // "bad"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view adjective(std::optional<unsigned> length = std::nullopt);


/**
 * @brief Returns a random adjective, using locale.
 *
 * @param length The expected length of the word. 
 * @param locale The locale. Defaults to `Locale::en_US`. 
 *
 * @returns Adjective.
 *
 * @code
 * faker::word::adjective() // "complete"
 * faker::word::adjective(3) // "bad"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view adjectiveL(unsigned length = 0,const faker::Locale locale = Locale::en_US);

/**
 * @brief Returns a random adverb.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Adverb.
 *
 * @code
 * faker::word::adverb() // "deliberately"
 * faker::word::adverb(5) // "almost"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view adverb(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random conjunction.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Conjunction.
 *
 * @code
 * faker::word::conjunction() // "because"
 * faker::word::conjunction(6) // "indeed"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view conjunction(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random interjection.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Interjection.
 *
 * @code
 * faker::word::interjection() // "psst"
 * faker::word::interjection(4) // "yuck"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view interjection(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random noun.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Noun.
 *
 * @code
 * faker::word::noun() // "pudding"
 * faker::word::noun(8) // "distance"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view noun(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random preposition.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Preposition.
 *
 * @code
 * faker::word::preposition() // "besides"
 * faker::word::preposition(4) // "from"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view preposition(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random verb.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Verb.
 *
 * @code
 * faker::word::verb() // "override"
 * faker::word::verb(9) // "stabilise"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view verb(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns random element of length
 *
 * @param length The length of the elements to be picked from
 *
 * @ range The range of elements
 *
 * @returns An element of the range value type
 *
 * @code
 * faker::word::sortedSizeRandomElement(3, {"hi, "hello", "hey"}) // "hey" - Since "hey" is the only element of length 3
 * @endcode
 */
template <std::ranges::range Range>
auto sortedSizeRandomElement(std::optional<unsigned int> length, Range&& range) -> decltype(auto)
{
    if (!length)
    {
        return helper::randomElement(range);
    }

    size_t length_64 = *length;
    auto start = range.begin();
    auto end = range.end();

    auto lower_it = ::std::lower_bound(start, end, length_64,
                                       [](const auto& lhs, const auto& value) { return lhs.size() < value; });

    if (lower_it == end)
    {
        return helper::randomElement(range);
    }

    if (lower_it->size() != length)
    {
        return *lower_it;
    }

    auto upper_it = lower_it;

    for (; upper_it != end; upper_it++)
    {
        if (upper_it->size() != lower_it->size())
        {
            break;
        }
    }

    return helper::randomElement(std::ranges::subrange(lower_it, upper_it));
}
}
