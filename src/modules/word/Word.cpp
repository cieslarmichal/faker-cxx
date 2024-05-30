#include "faker-cxx/Word.h"
#include "faker-cxx/Helper.h"
#include "wordData.h"

namespace faker {
    std::vector<std::string_view> Word::createAllWords() {
        std::vector<std::string_view> allWords;

        allWords.insert(allWords.end(), Words::adjectives.begin(), Words::adjectives.end());
        allWords.insert(allWords.end(), Words::adverbs.begin(), Words::adverbs.end());
        allWords.insert(allWords.end(), Words::conjunctions.begin(), Words::conjunctions.end());
        allWords.insert(allWords.end(), Words::interjections.begin(), Words::interjections.end());
        allWords.insert(allWords.end(), Words::nouns.begin(), Words::nouns.end());
        allWords.insert(allWords.end(), Words::prepositions.begin(), Words::prepositions.end());
        allWords.insert(allWords.end(), Words::verbs.begin(), Words::verbs.end());

        return allWords;
    }

    std::string_view Word::sample(std::optional<unsigned> length) {
        auto allWords = createAllWords();
        
        if (!length) {
            return Helper::arrayElement(allWords);
        }

        std::shuffle(allWords.begin(), allWords.end(), std::default_random_engine());

        for (const auto& word : allWords) {
            if (word.size() == length.value()) {
                return word;
            }
        }

        return "";  // Return a default value if no match is found
    }

    std::string_view Word::words(unsigned numberOfWords) {
        auto allWords = createAllWords();
        const auto shuffledWords = Helper::shuffle(allWords);

        std::vector<std::string_view> words;
        for (unsigned i = 0; i < numberOfWords; i++) {
            words.push_back(shuffledWords[i]);
        }

        return Helper::arrayElement(words);
    }

    std::string_view Word::adjective(std::optional<unsigned> length) {
        if (!length) {
            return Helper::arrayElement(Words::adjectives);
        }

        auto shuffledAdjectives = Words::adjectives;
        std::shuffle(shuffledAdjectives.begin(), shuffledAdjectives.end(), std::default_random_engine());

        for (const auto& adjective : shuffledAdjectives) {
            if (adjective.size() == length.value()) {
                return adjective;
            }
        }

        return "";  // Return a default value if no match is found
    }

    std::string_view Word::adverb(std::optional<unsigned> length) {
        if (!length) {
            return Helper::arrayElement(Words::adverbs);
        }

        auto shuffledAdverbs = Words::adverbs;
        std::shuffle(shuffledAdverbs.begin(), shuffledAdverbs.end(), std::default_random_engine());

        for (const auto& adverb : shuffledAdverbs) {
            if (adverb.size() == length.value()) {
                return adverb;
            }
        }

        return "";  // Return a default value if no match is found
    }

    std::string_view Word::conjunction(std::optional<unsigned> length) {
        if (!length) {
            return Helper::arrayElement(Words::conjunctions);
        }

        auto shuffledConjunctions = Words::conjunctions;
        std::shuffle(shuffledConjunctions.begin(), shuffledConjunctions.end(), std::default_random_engine());

        for (const auto& conjunction : shuffledConjunctions) {
            if (conjunction.size() == length.value()) {
                return conjunction;
            }
        }
        
        return "";  // Return a default value if no match is found
    }

    std::string_view Word::interjection(std::optional<unsigned> length) {
        if (!length) {
            return Helper::arrayElement(Words::interjections);
        }

        auto shuffledInterjections = Words::interjections;
        std::shuffle(shuffledInterjections.begin(), shuffledInterjections.end(), std::default_random_engine());

        for (const auto& interjection : shuffledInterjections) {
            if (interjection.size() == length.value()) {
                return interjection;
            }
        }

        return "";  // Return a default value if no match is found
    }

    std::string_view Word::noun(std::optional<unsigned> length) {
        if (!length) {
            return Helper::arrayElement(Words::nouns);
        }

        auto shuffledNouns = Words::nouns;
        std::shuffle(shuffledNouns.begin(), shuffledNouns.end(), std::default_random_engine());

        for (const auto& noun : shuffledNouns) {
            if (noun.size() == length.value()) {
                return noun;
            }
        }

       return "";  // Return a default value if no match is found
    }

    std::string_view Word::preposition(std::optional<unsigned> length) {
        if (!length) {
            return Helper::arrayElement(Words::prepositions);
        }

        auto shuffledPrepositions = Words::prepositions;
        std::shuffle(shuffledPrepositions.begin(), shuffledPrepositions.end(), std::default_random_engine());

        for (const auto& preposition : shuffledPrepositions) {
            if (preposition.size() == length.value()) {
                return preposition;
            }
        }

        return "";  // Return a default value if no match is found
    }
    
    std::string_view Word::verb(std::optional<unsigned> length) {
        if (!length) {
            return Helper::arrayElement(Words::verbs);
        }

        auto shuffledVerbs = Words::verbs;
        std::shuffle(shuffledVerbs.begin(), shuffledVerbs.end(), std::default_random_engine());

        for (const auto& verb : shuffledVerbs) {
            if (verb.size() == length.value()) {
                return verb;
            }
        }

        return "";  // Return a default value if no match is found
    }
} // namespace faker
