#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace faker
{
class Word
{
public:
    /**
     * @brief Returns a random word.
     *
     * @param length The expected length of the word.
     * If no word with given length will be found, it will return a random word.
     *
     * @returns Random sample word.
     *
     * @code
     * Word::sample() // "protection"
     * Word::sample(5) // "spell"
     * @endcode
     */
    static std::string_view sample(std::optional<unsigned> length = std::nullopt);

    /**
     * @brief Returns a string containing a number of space separated random words.
     *
     * @param numberOfWords The number of words to generate.
     *
     * @returns Random words separated with spaces.
     *
     * @code
     * Word::words() // "protection"
     * Word::words(5) // "before hourly patiently dribble equal"
     * @endcode
     */
    static std::string words(unsigned numberOfWords = 1);

    /**
     * @brief Returns a random adjective.
     *
     * @param length The expected length of the word.
     * If no word with given length will be found, it will return a random word.
     *
     * @returns Adjective.
     *
     * @code
     * Word::adjective() // "complete"
     * Word::adjective(3) // "bad"
     * @endcode
     */
    static std::string_view adjective(std::optional<unsigned> length = std::nullopt);

    /**
     * @brief Returns a random adverb.
     *
     * @param length The expected length of the word.
     * If no word with given length will be found, it will return a random word.
     *
     * @returns Adverb.
     *
     * @code
     * Word::adverb() // "deliberately"
     * Word::adverb(5) // "almost"
     * @endcode
     */
    static std::string_view adverb(std::optional<unsigned> length = std::nullopt);

    /**
     * @brief Returns a random conjunction.
     *
     * @param length The expected length of the word.
     * If no word with given length will be found, it will return a random word.
     *
     * @returns Conjunction.
     *
     * @code
     * Word::conjunction() // "because"
     * Word::conjunction(6) // "indeed"
     * @endcode
     */
    static std::string_view conjunction(std::optional<unsigned> length = std::nullopt);

    /**
     * @brief Returns a random interjection.
     *
     * @param length The expected length of the word.
     * If no word with given length will be found, it will return a random word.
     *
     * @returns Interjection.
     *
     * @code
     * Word::interjection() // "psst"
     * Word::interjection(4) // "yuck"
     * @endcode
     */
    static std::string_view interjection(std::optional<unsigned> length = std::nullopt);

    /**
     * @brief Returns a random noun.
     *
     * @param length The expected length of the word.
     * If no word with given length will be found, it will return a random word.
     *
     * @returns Noun.
     *
     * @code
     * Word::noun() // "pudding"
     * Word::noun(8) // "distance"
     * @endcode
     */
    static std::string_view noun(std::optional<unsigned> length = std::nullopt);

    /**
     * @brief Returns a random preposition.
     *
     * @param length The expected length of the word.
     * If no word with given length will be found, it will return a random word.
     *
     * @returns Preposition.
     *
     * @code
     * Word::preposition() // "besides"
     * Word::preposition(4) // "from"
     * @endcode
     */
    static std::string_view preposition(std::optional<unsigned> length = std::nullopt);

    /**
     * @brief Returns a random verb.
     *
     * @param length The expected length of the word.
     * If no word with given length will be found, it will return a random word.
     *
     * @returns Verb.
     *
     * @code
     * Word::verb() // "override"
     * Word::verb(9) // "stabilise"
     * @endcode
     */
    static std::string_view verb(std::optional<unsigned> length = std::nullopt);
};
}
