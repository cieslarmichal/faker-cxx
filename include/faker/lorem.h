#pragma once

#include <string>

namespace faker::lorem {
/**
 * @brief Returns a random lorem word.
 *
 * @returns lorem word.
 *
 * @code
 * lorem::word() // "temporibus"
 * @endcode
 */
std::string_view word();

/**
 * @brief Returns a random lorem words.
 *
 * @param numberOfWords The number of words. Defaults to `3`.
 *
 * @returns lorem words.
 *
 * @code
 * lorem::words() // "qui praesentium pariatur"
 * @endcode
 */
std::string words(unsigned numberOfWords = 3);

/**
 * @brief Returns a random lorem sentence.
 *
 * @param minNumberOfWords The minimum number of words to generate. Defaults to `3`.
 * @param maxNumberOfWords The maximum number of words to generate. Defaults to `10`.
 *
 * @returns lorem sentence.
 *
 * @code
 * lorem::sentence() // "Laborum voluptatem officiis est et."
 * @endcode
 */
std::string sentence(unsigned minNumberOfWords = 3, unsigned maxNumberOfWords = 10);

/**
 * @brief Returns a random lorem sentences.
 *
 * @param minNumberOfSentences The minimum number of sentences to generate. Defaults to `2`.
 * @param maxNumberOfSentences The maximum number of sentences to generate. Defaults to `6`.
 *
 * @returns lorem sentences separated with spaces.
 *
 * @code
 * lorem::sentences(2, 2) // "Maxime vel numquam quibusdam. Dignissimos ex molestias quam nihil
 * occaecati maiores."
 * @endcode
 */
std::string sentences(unsigned minNumberOfSentences = 2, unsigned maxNumberOfSentences = 6);

/**
 * @brief Generates a slugified text consisting of the given number of hyphen separated words.
 *
 * @param numberOfWords The number of words. Defaults to `3`.
 *
 * @returns Hyphen separated words.
 *
 * @code
 * lorem::slug(5) // "delectus-totam-iusto-itaque-placeat"
 * @endcode
 */
std::string slug(unsigned numberOfWords = 3);

/**
 * @brief Returns a random lorem paragraph.
 *
 * @param minNumberOfSentences The minimum number of sentences to generate. Defaults to `2`.
 * @param maxNumberOfSentences The maximum number of sentences to generate. Defaults to `6`.
 *
 * @returns lorem paragraph.
 *
 * @code
 * lorem::paragraph() // "Animi possimus nemo consequuntur ut ea et tempore unde qui. Quis
 * corporis esse."
 * @endcode
 */
std::string paragraph(unsigned minNumberOfSentences = 2, unsigned maxNumberOfSentences = 6);

/**
 * @brief Returns a random lorem paragraphs.
 *
 * @param minNumberOfParagraphs The minimum number of paragraphs to generate. Defaults to `2`.
 * @param maxNumberOfParagraphs The maximum number of paragraphs to generate. Defaults to `4`.
 *
 * @returns lorem paragraphs separated with newlines.
 *
 * @code
 * lorem::paragraphs()
 * // "Beatae voluptatem dicta et assumenda fugit eaque quidem consequatur. Fuga unde provident.
 * // Voluptatibus quo pariatur est. Doloribus commodi et et exercitationem vel et. Omnis
 * inventore cum aut amet.
 * // Sapiente deleniti et. Ducimus maiores eum. Rem dolorem itaque aliquam."
 * @endcode
 */
std::string paragraphs(unsigned minNumberOfParagraphs = 2, unsigned maxNumberOfParagraphs = 4);
}
