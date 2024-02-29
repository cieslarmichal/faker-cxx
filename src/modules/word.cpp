#include "../common/random.h"
#include "../common/strings.h"
#include "word_data.h"
#include <faker/word.h>
#include <unordered_map>

namespace faker::word {
namespace {

    template <size_t N>
    std::unordered_map<unsigned, std::vector<std::string_view>> group_by_length(
        const std::array<std::string_view, N>& arr)
    {
        std::unordered_map<unsigned, std::vector<std::string_view>> result;

        for (auto word : arr) {
            result[word.size()].push_back(word);
        }

        return result;
    }

}

std::string_view sample(std::optional<unsigned> length)
{
    static std::vector<std::string_view> all_words;
    static std::unordered_map<unsigned, std::vector<std::string_view>> words_by_length;

    // TODO Instead of this, use 2-step algorithm:
    // 1. determine category (weighted, weights are based on the number of words in each category)
    // 2. pick a word from the category
    if (words_by_length.empty()) {
        all_words.reserve(data::adjectives.size() + data::adverbs.size() + data::conjunctions.size()
            + data::interjections.size() + data::nouns.size() + data::prepositions.size()
            + data::verbs.size());

        for (const auto& word : data::adjectives) {
            all_words.push_back(word);
            words_by_length[word.size()].push_back(word);
        }
        for (const auto& word : data::adverbs) {
            all_words.push_back(word);
            words_by_length[word.size()].push_back(word);
        }
        for (const auto& word : data::conjunctions) {
            all_words.push_back(word);
            words_by_length[word.size()].push_back(word);
        }
        for (const auto& word : data::interjections) {
            all_words.push_back(word);
            words_by_length[word.size()].push_back(word);
        }
        for (const auto& word : data::nouns) {
            all_words.push_back(word);
            words_by_length[word.size()].push_back(word);
        }
        for (const auto& word : data::prepositions) {
            all_words.push_back(word);
            words_by_length[word.size()].push_back(word);
        }
        for (const auto& word : data::verbs) {
            all_words.push_back(word);
            words_by_length[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = words_by_length.find(*length);
        if (it != words_by_length.end()) {
            return random::element(it->second);
        }
    }

    return random::element(all_words);
}

std::string words(unsigned count)
{
    std::string result;
    for (unsigned i = 0; i < count; i++) {
        if (i > 0) {
            result += ' ';
        }
        result += sample();
    }
    return result;
}

std::string_view adjective(std::optional<unsigned> length)
{
    static const auto words_by_length = group_by_length(data::adjectives);

    if (length) {
        auto it = words_by_length.find(*length);
        if (it != words_by_length.end()) {
            return random::element(it->second);
        }
    }
    return random::element(data::adjectives);
}

std::string_view adverb(std::optional<unsigned> length)
{
    static const auto words_by_length = group_by_length(data::adverbs);

    if (length) {
        auto it = words_by_length.find(*length);
        if (it != words_by_length.end()) {
            return random::element(it->second);
        }
    }

    return random::element(data::adverbs);
}

std::string_view conjunction(std::optional<unsigned> length)
{
    static const auto words_by_length = group_by_length(data::conjunctions);

    if (length) {
        auto it = words_by_length.find(*length);
        if (it != words_by_length.end()) {
            return random::element(it->second);
        }
    }

    return random::element(data::conjunctions);
}

std::string_view interjection(std::optional<unsigned> length)
{
    static const auto words_by_length = group_by_length(data::interjections);

    if (length) {
        auto it = words_by_length.find(*length);
        if (it != words_by_length.end()) {
            return random::element(it->second);
        }
    }

    return random::element(data::interjections);
}

std::string_view noun(std::optional<unsigned> length)
{
    static const auto words_by_length = group_by_length(data::nouns);

    if (length) {
        auto it = words_by_length.find(*length);
        if (it != words_by_length.end()) {
            return random::element(it->second);
        }
    }

    return random::element(data::nouns);
}

std::string_view preposition(std::optional<unsigned> length)
{
    static const auto words_by_length = group_by_length(data::prepositions);

    if (length) {
        auto it = words_by_length.find(*length);
        if (it != words_by_length.end()) {
            return random::element(it->second);
        }
    }

    return random::element(data::prepositions);
}

std::string_view verb(std::optional<unsigned> length)
{
    static const auto words_by_length = group_by_length(data::verbs);

    if (length) {
        auto it = words_by_length.find(*length);
        if (it != words_by_length.end()) {
            return random::element(it->second);
        }
    }

    return random::element(data::verbs);
}
}
