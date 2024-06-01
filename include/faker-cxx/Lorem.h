#pragma once

#include <string>

namespace faker
{
class Lorem
{
public:
    /**
     * @brief Returns a random lorem word.
     *
     * @returns Lorem word.
     *
     * @code
     * Lorem::word() // "temporibus"
     * @endcode
     */
    static std::string_view word();

    /**
     * @brief Returns a random lorem words.
     *
     * @param numberOfWords The number of words. Defaults to `3`.
     *
     * @returns Lorem words.
     *
     * @code
     * Lorem::words() // "qui praesentium pariatur"
     * @endcode
     */
    static std::string words(unsigned numberOfWords = 3);

    /**
     * @brief Returns a random lorem sentence.
     *
     * @param minNumberOfWords The minimum number of words to generate. Defaults to `3`.
     * @param maxNumberOfWords The maximum number of words to generate. Defaults to `10`.
     *
     * @returns Lorem sentence.
     *
     * @code
     * Lorem::sentence() // "Laborum voluptatem officiis est et."
     * @endcode
     */
    static std::string sentence(unsigned minNumberOfWords = 3, unsigned maxNumberOfWords = 10);

    /**
     * @brief Returns a random lorem sentences.
     *
     * @param minNumberOfSentences The minimum number of sentences to generate. Defaults to `2`.
     * @param maxNumberOfSentences The maximum number of sentences to generate. Defaults to `6`.
     *
     * @returns Lorem sentences separated with spaces.
     *
     * @code
     * Lorem::sentences(2, 2) // "Maxime vel numquam quibusdam. Dignissimos ex molestias quam nihil occaecati maiores."
     * @endcode
     */
    static std::string sentences(unsigned minNumberOfSentences = 2, unsigned maxNumberOfSentences = 6);

    /**
     * @brief Generates a slugified text consisting of the given number of hyphen separated words.
     *
     * @param numberOfWords The number of words. Defaults to `3`.
     *
     * @returns Hyphen separated words.
     *
     * @code
     * Lorem::slug(5) // "delectus-totam-iusto-itaque-placeat"
     * @endcode
     */
    static std::string slug(unsigned numberOfWords = 3);

    /**
     * @brief Returns a random lorem paragraph.
     *
     * @param minNumberOfSentences The minimum number of sentences to generate. Defaults to `2`.
     * @param maxNumberOfSentences The maximum number of sentences to generate. Defaults to `6`.
     *
     * @returns Lorem paragraph.
     *
     * @code
     * Lorem::paragraph() // "Animi possimus nemo consequuntur ut ea et tempore unde qui. Quis corporis esse."
     * @endcode
     */
    static std::string paragraph(unsigned minNumberOfSentences = 2, unsigned maxNumberOfSentences = 6);

    /**
     * @brief Returns a random lorem paragraphs.
     *
     * @param minNumberOfParagraphs The minimum number of paragraphs to generate. Defaults to `2`.
     * @param maxNumberOfParagraphs The maximum number of paragraphs to generate. Defaults to `4`.
     *
     * @returns Lorem paragraphs separated with newlines.
     *
     * @code
     * Lorem::paragraphs()
     * // "Beatae voluptatem dicta et assumenda fugit eaque quidem consequatur. Fuga unde provident.
     * // Voluptatibus quo pariatur est. Doloribus commodi et et exercitationem vel et. Omnis inventore cum aut amet.
     * // Sapiente deleniti et. Ducimus maiores eum. Rem dolorem itaque aliquam."
     * @endcode
     */
    static std::string paragraphs(unsigned minNumberOfParagraphs = 2, unsigned maxNumberOfParagraphs = 4);
};
}
