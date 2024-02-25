#include "../common/string_helper.h"
#include "word_data.h"
#include <faker/helper.h>
#include <faker/word.h>

namespace faker {
std::string_view word::sample(std::optional<unsigned int> length)
{
    static std::vector<std::string_view> allWords;
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        allWords.reserve(words::adjectives.size() + words::adverbs.size()
            + words::conjunctions.size() + words::interjections.size() + words::nouns.size()
            + words::prepositions.size() + words::verbs.size());
        for (const auto& word : words::adjectives) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : words::adverbs) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : words::conjunctions) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : words::interjections) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : words::nouns) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : words::prepositions) {
            allWords.push_back(word);
            wordsByLength[word.size()].push_back(word);
        }
        for (const auto& word : words::verbs) {
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

std::string word::words(unsigned numberOfWords)
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

std::string_view word::adjective(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : words::adjectives) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(words::adjectives);
}

std::string_view word::adverb(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : words::adverbs) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(words::adverbs);
}

std::string_view word::conjunction(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : words::conjunctions) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(words::conjunctions);
}

std::string_view word::interjection(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : words::interjections) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(words::interjections);
}

std::string_view word::noun(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : words::nouns) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(words::nouns);
}

std::string_view word::preposition(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : words::prepositions) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(words::prepositions);
}

std::string_view word::verb(std::optional<unsigned int> length)
{
    static std::unordered_map<unsigned int, std::vector<std::string_view>> wordsByLength;

    if (wordsByLength.empty()) {
        for (const auto& word : words::verbs) {
            wordsByLength[word.size()].push_back(word);
        }
    }

    if (length) {
        auto it = wordsByLength.find(*length);
        if (it != wordsByLength.end()) {
            return Helper::arrayElement(it->second);
        }
    }

    return Helper::arrayElement(words::verbs);
}
}
