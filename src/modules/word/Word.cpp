#include "faker-cxx/Word.h"

#include "faker-cxx/Helper.h"

#include "wordData.h"

namespace faker {
    std::string words(unsigned numberOfWords = 1) {
        std::vector<std::string> allWords;

        allWords.insert(allWords.end(), Words::adjectives.begin(), Words::adjectives.end());
        allWords.insert(allWords.end(), Words::adverbs.begin(), Words::adverbs.end());
        allWords.insert(allWords.end(), Words::conjunctions.begin(), Words::conjunctions.end());
        allWords.insert(allWords.end(), Words::interjections.begin(), Words::interjections.end());
        allWords.insert(allWords.end(), Words::nouns.begin(), Words::nouns.end());
        allWords.insert(allWords.end(), Words::prepositions.begin(), Words::prepositions.end());
        allWords.insert(allWords.end(), Words::verbs.begin(), Words::verbs.end());

        const auto shuffledWords = Helper::shuffle(allWords);

        std::vector<std::string> words;
        for (unsigned i = 0; i < numberOfWords; i++) {
            words.push_back(shuffledWords[i]);
        }

        return Helper::arrayElement(words);
    }

    std::string adjective(std::optional<unsigned> length = std::nullopt) {
        if (!length) {
            return Helper::arrayElement<std::string>(Words::adjectives);
        }

        auto shuffledAdjectives = Words::adjectives;
        std::shuffle(shuffledAdjectives.begin(), shuffledAdjectives.end(), std::default_random_engine());

        for (const auto& adjective : shuffledAdjectives) {
            if (adjective.size() == length.value()) {
                return std::string(adjective);  // cast to std::string
            }
        }
    }

    std::string adverb(std::optional<unsigned> length = std::nullopt) {
        if (!length) {
            return Helper::arrayElement<std::string>(Words::adverbs);
        }

        auto shuffledAdverbs = Words::adverbs;
        std::shuffle(shuffledAdverbs.begin(), shuffledAdverbs.end(), std::default_random_engine());

        for (const auto& adverb : shuffledAdverbs) {
            if (adverb.size() == length.value()) {
                std::string(adverb);  // cast to std::string
            }
        }
    }

    std::string conjunction(std::optional<unsigned> length = std::nullopt) {
        if (!length) {
            return Helper::arrayElement<std::string>(Words::conjunctions);
        }

        auto shuffledConjunctions = Words::conjunctions;
        std::shuffle(shuffledConjunctions.begin(), shuffledConjunctions.end(), std::default_random_engine());

        for (const auto& conjunction : shuffledConjunctions) {
            if (conjunction.size() == length.value()) {
                return std::string(conjunction);  // cast to std::string
            }
        }
    }

    std::string interjection(std::optional<unsigned> length = std::nullopt) {
        if (!length) {
            return Helper::arrayElement<std::string>(Words::interjections);
        }

        auto shuffledInterjections = Words::interjections;
        std::shuffle(shuffledInterjections.begin(), shuffledInterjections.end(), std::default_random_engine());

        for (const auto& interjection : shuffledInterjections) {
            if (interjection.size() == length.value()) {
                return std::string(interjection);  // cast to std::string
            }
        }
    }

    std::string noun(std::optional<unsigned> length = std::nullopt) {
        if (!length) {
            return Helper::arrayElement<std::string>(Words::nouns);
        }

        auto shuffledNouns = Words::nouns;
        std::shuffle(shuffledNouns.begin(), shuffledNouns.end(), std::default_random_engine());

        for (const auto& noun : shuffledNouns) {
            if (noun.size() == length.value()) {
                return std::string(noun);  // cast to std::string
            }
        }
    }

    std::string preposition(std::optional<unsigned> length = std::nullopt) {
        if (!length) {
            return Helper::arrayElement<std::string>(Words::prepositions);
        }

        auto shuffledPrepositions = Words::prepositions;
        std::shuffle(shuffledPrepositions.begin(), shuffledPrepositions.end(), std::default_random_engine());

        for (const auto& preposition : shuffledPrepositions) {
            if (preposition.size() == length.value()) {
                return std::string(preposition);  // cast to std::string
            }
        }
    }
    
    std::string verb(std::optional<unsigned> length = std::nullopt) {
        if (!length) {
            return Helper::arrayElement<std::string>(Words::verbs);
        }

        auto shuffledVerbs = Words::verbs;
        std::shuffle(shuffledVerbs.begin(), shuffledVerbs.end(), std::default_random_engine());

        for (const auto& verb : shuffledVerbs) {
            if (verb.size() == length.value()) {
                return std::string(verb);  // cast to std::string
            }
        }
    }

} // namespace faker