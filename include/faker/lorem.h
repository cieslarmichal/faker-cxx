#ifndef FAKER_LOREM_H
#define FAKER_LOREM_H

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
 * @param count The number of words. Defaults to `3`.
 *
 * @returns lorem words.
 *
 * @code
 * lorem::words() // "qui praesentium pariatur"
 * @endcode
 */
std::string words(unsigned count = 3);

/**
 * @brief Returns a random lorem sentence.
 *
 * @param min_word_count The minimum number of words to generate. Defaults to `3`.
 * @param max_word_count The maximum number of words to generate. Defaults to `10`.
 *
 * @returns lorem sentence.
 *
 * @code
 * lorem::sentence() // "Laborum voluptatem officiis est et."
 * @endcode
 */
std::string sentence(unsigned min_word_count = 3, unsigned max_word_count = 10);

/**
 * @brief Returns a random lorem sentences.
 *
 * @param min_count The minimum number of sentences to generate. Defaults to `2`.
 * @param max_count The maximum number of sentences to generate. Defaults to `6`.
 *
 * @returns lorem sentences separated with spaces.
 *
 * @code
 * lorem::sentences(2, 2) // "Maxime vel numquam quibusdam. Dignissimos ex molestias quam nihil
 * occaecati maiores."
 * @endcode
 */
std::string sentences(unsigned min_count = 2, unsigned max_count = 6);

/**
 * @brief Generates a slugified text consisting of the given number of hyphen separated words.
 *
 * @param word_count The number of words. Defaults to `3`.
 *
 * @returns Hyphen separated words.
 *
 * @code
 * lorem::slug(5) // "delectus-totam-iusto-itaque-placeat"
 * @endcode
 */
std::string slug(unsigned word_count = 3);

/**
 * @brief Returns a random lorem paragraph.
 *
 * @param min_sentence_count The minimum number of sentences to generate. Defaults to `2`.
 * @param max_sentence_count The maximum number of sentences to generate. Defaults to `6`.
 *
 * @returns lorem paragraph.
 *
 * @code
 * lorem::paragraph() // "Animi possimus nemo consequuntur ut ea et tempore unde qui. Quis
 * corporis esse."
 * @endcode
 */
std::string paragraph(unsigned min_sentence_count = 2, unsigned max_sentence_count = 6);

/**
 * @brief Returns a random lorem paragraphs.
 *
 * @param min_count The minimum number of paragraphs to generate. Defaults to `2`.
 * @param max_count The maximum number of paragraphs to generate. Defaults to `4`.
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
std::string paragraphs(unsigned min_count = 2, unsigned max_count = 4);
}

#endif