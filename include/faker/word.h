#ifndef FAKER_WORD_H
#define FAKER_WORD_H

#include <optional>
#include <string>

namespace faker::word {
/**
 * @brief Returns a random word.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Random sample word.
 *
 * @code
 * word::sample() // "protection"
 * word::sample(5) // "spell"
 * @endcode
 */
std::string_view sample(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a string containing a number of space separated random words.
 *
 * @param count The number of words to generate.
 *
 * @returns Random words separated with spaces.
 *
 * @code
 * word::words() // "protection"
 * word::words(5) // "before hourly patiently dribble equal"
 * @endcode
 */
std::string words(unsigned count = 1);

/**
 * @brief Returns a random adjective.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Adjective.
 *
 * @code
 * word::adjective() // "complete"
 * word::adjective(3) // "bad"
 * @endcode
 */
std::string_view adjective(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random adverb.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Adverb.
 *
 * @code
 * word::adverb() // "deliberately"
 * word::adverb(5) // "almost"
 * @endcode
 */
std::string_view adverb(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random conjunction.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Conjunction.
 *
 * @code
 * word::conjunction() // "because"
 * word::conjunction(6) // "indeed"
 * @endcode
 */
std::string_view conjunction(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random interjection.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Interjection.
 *
 * @code
 * word::interjection() // "psst"
 * word::interjection(4) // "yuck"
 * @endcode
 */
std::string_view interjection(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random noun.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Noun.
 *
 * @code
 * word::noun() // "pudding"
 * word::noun(8) // "distance"
 * @endcode
 */
std::string_view noun(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random preposition.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Preposition.
 *
 * @code
 * word::preposition() // "besides"
 * word::preposition(4) // "from"
 * @endcode
 */
std::string_view preposition(std::optional<unsigned> length = std::nullopt);

/**
 * @brief Returns a random verb.
 *
 * @param length The expected length of the word.
 * If no word with given length will be found, it will return a random word.
 *
 * @returns Verb.
 *
 * @code
 * word::verb() // "override"
 * word::verb(9) // "stabilise"
 * @endcode
 */
std::string_view verb(std::optional<unsigned> length = std::nullopt);
}

#endif