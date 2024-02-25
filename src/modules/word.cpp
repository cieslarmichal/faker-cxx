#include "../common/string_helper.h"
#include "word_data.h"
#include <faker/helper.h>
#include <faker/word.h>

namespace faker::word {
std::string_view sample(std::optional<unsigned int> length)
{
    static std::vector<std::string_view> allWords;
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        allWords.reserve(data::adjectives.size() + data::adverbs.size() + data::conjunctions.size()
            + data::interjections.size() + data::nouns.size() + data::prepositions.size()
            + data::verbs.size());
        for (const auto& word : data::adjectives) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : data::adverbs) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : data::conjunctions) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : data::interjections) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : data::nouns) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : data::prepositions) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : data::verbs) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(allWords);
}

std::string words(unsigned numberOfWords)
{
    std::string result;
    for (unsigned i = 0; i < numberOfWords; i++) {
        if (i > 0) {
            result += ' ';
        }
        result += sample();
    }
    return result;
}

std::string_view adjective(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : data::adjectives) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(data::adjectives);
}

std::string_view adverb(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : data::adverbs) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(data::adverbs);
}

std::string_view conjunction(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : data::conjunctions) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(data::conjunctions);
}

std::string_view interjection(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : data::interjections) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(data::interjections);
}

std::string_view noun(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : data::nouns) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(data::nouns);
}

std::string_view preposition(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : data::prepositions) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(data::prepositions);
}

std::string_view verb(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : data::verbs) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(data::verbs);
}
}
