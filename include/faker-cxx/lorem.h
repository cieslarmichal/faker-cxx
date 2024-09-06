#pragma once

#include <string>
#include <vector>

#include "faker-cxx/export.h"

namespace faker::lorem
{
/**
 * @brief Generates and returns a dynamic array consisting of random lorem words.
 *
 * @returns A std::vector consisting of random lorem words
 *
 * @param numberOfWords The number of elements in the vector which is returned
 * 
 * @throws std::invalid_argument if the numberOfWords is less than 0
 * 
 * @code
 * faker::lorem::wordVector(3) // "temporibus", "ipsum", "alias"
 * @endcode
 */
FAKER_CXX_EXPORT std::vector<std::string_view> wordVector(int numberOfWords = 3);

/**
 * @brief Returns a random lorem word.
 *
 * @returns Lorem word.
 *
 * @code
 * faker::lorem::word() // "temporibus"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view word();

/**
 * @brief Returns a random lorem words.
 *
 * @param numberOfWords The number of words. Defaults to `3`.
 *
 * @returns Lorem words.
 *
 * @code
 * faker::lorem::words() // "qui praesentium pariatur"
 * @endcode
 */
FAKER_CXX_EXPORT std::string words(unsigned numberOfWords = 3);

/**
 * @brief Returns a random lorem sentence.
 *
 * @param minNumberOfWords The minimum number of words to generate. Defaults to `3`.
 * @param maxNumberOfWords The maximum number of words to generate. Defaults to `10`.
 *
 * @returns Lorem sentence.
 *
 * @code
 * faker::lorem::sentence() // "Laborum voluptatem officiis est et."
 * @endcode
 */
FAKER_CXX_EXPORT std::string sentence(unsigned minNumberOfWords = 3, unsigned maxNumberOfWords = 10);

/**
 * @brief Returns a random lorem sentences.
 *
 * @param minNumberOfSentences The minimum number of sentences to generate. Defaults to `2`.
 * @param maxNumberOfSentences The maximum number of sentences to generate. Defaults to `6`.
 *
 * @returns Lorem sentences separated with spaces.
 *
 * @code
 * faker::lorem::sentences(2, 2) // "Maxime vel numquam quibusdam. Dignissimos ex molestias quam nihil occaecati
 * maiores."
 * @endcode
 */
FAKER_CXX_EXPORT std::string sentences(unsigned minNumberOfSentences = 2, unsigned maxNumberOfSentences = 6);

/**
 * @brief Generates a slugified text consisting of the given number of hyphen separated words.
 *
 * @param numberOfWords The number of words. Defaults to `3`.
 *
 * @returns Hyphen separated words.
 *
 * @code
 * faker::lorem::slug(5) // "delectus-totam-iusto-itaque-placeat"
 * @endcode
 */
FAKER_CXX_EXPORT std::string slug(unsigned numberOfWords = 3);

/**
 * @brief Returns a random lorem paragraph.
 *
 * @param minNumberOfSentences The minimum number of sentences to generate. Defaults to `2`.
 * @param maxNumberOfSentences The maximum number of sentences to generate. Defaults to `6`.
 *
 * @returns Lorem paragraph.
 *
 * @code
 * faker::lorem::paragraph() // "Animi possimus nemo consequuntur ut ea et tempore unde qui. Quis corporis esse."
 * @endcode
 */
FAKER_CXX_EXPORT std::string paragraph(unsigned minNumberOfSentences = 2, unsigned maxNumberOfSentences = 6);

/**
 * @brief Returns a random lorem paragraphs.
 *
 * @param minNumberOfParagraphs The minimum number of paragraphs to generate. Defaults to `2`.
 * @param maxNumberOfParagraphs The maximum number of paragraphs to generate. Defaults to `4`.
 *
 * @returns Lorem paragraphs separated with newlines.
 *
 * @code
 * faker::lorem::paragraphs()
 * // "Beatae voluptatem dicta et assumenda fugit eaque quidem consequatur. Fuga unde provident.
 * // Voluptatibus quo pariatur est. Doloribus commodi et et exercitationem vel et. Omnis inventore cum aut amet.
 * // Sapiente deleniti et. Ducimus maiores eum. Rem dolorem itaque aliquam."
 * @endcode
 */
FAKER_CXX_EXPORT std::string paragraphs(unsigned minNumberOfParagraphs = 2, unsigned maxNumberOfParagraphs = 4);
}
