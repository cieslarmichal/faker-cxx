#include "faker-cxx/Word.h"

#include "../../common/StringHelper.h"
#include "data/Adjectives.h"
#include "data/Adverbs.h"
#include "data/Conjunctions.h"
#include "data/Interjections.h"
#include "data/Nouns.h"
#include "data/Prepositions.h"
#include "data/Verbs.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"

namespace faker
{
std::string Word::sample(std::optional<unsigned int> length)
{
    std::vector<std::string> allWords{adjectives};

    allWords.insert(allWords.end(), adverbs.begin(), adverbs.end());
    allWords.insert(allWords.end(), conjunctions.begin(), conjunctions.end());
    allWords.insert(allWords.end(), interjections.begin(), interjections.end());
    allWords.insert(allWords.end(), nouns.begin(), nouns.end());
    allWords.insert(allWords.end(), prepositions.begin(), prepositions.end());
    allWords.insert(allWords.end(), verbs.begin(), verbs.end());

    if (!length)
    {
        return Helper::arrayElement<std::string>(allWords);
    }

    const auto shuffledWords = Helper::shuffle(allWords);

    for (const auto& word : shuffledWords)
    {
        if (word.size() == length)
        {
            return word;
        }
    }

    return Helper::arrayElement<std::string>(shuffledWords);
}

std::string Word::words(unsigned numberOfWords)
{
    std::vector<std::string> words;

    for (unsigned i = 0; i < numberOfWords; i++)
    {
        words.push_back(sample());
    }

    return StringHelper::join(words, " ");
}

std::string Word::adjective(std::optional<unsigned int> length)
{
    if (!length)
    {
        return Helper::arrayElement<std::string>(adjectives);
    }

    const auto shuffledAdjectives = Helper::shuffle(adjectives);

    for (const auto& adjective : shuffledAdjectives)
    {
        if (adjective.size() == length)
        {
            return adjective;
        }
    }

    return Helper::arrayElement<std::string>(shuffledAdjectives);
}

std::string Word::adverb(std::optional<unsigned int> length)
{
    if (!length)
    {
        return Helper::arrayElement<std::string>(adverbs);
    }

    const auto shuffledAdverbs = Helper::shuffle(adverbs);

    for (const auto& adverb : shuffledAdverbs)
    {
        if (adverb.size() == length)
        {
            return adverb;
        }
    }

    return Helper::arrayElement<std::string>(shuffledAdverbs);
}

std::string Word::conjunction(std::optional<unsigned int> length)
{
    if (!length)
    {
        return Helper::arrayElement<std::string>(conjunctions);
    }

    const auto shuffledConjunctions = Helper::shuffle(conjunctions);

    for (const auto& conjunction : shuffledConjunctions)
    {
        if (conjunction.size() == length)
        {
            return conjunction;
        }
    }

    return Helper::arrayElement<std::string>(shuffledConjunctions);
}

std::string Word::interjection(std::optional<unsigned int> length)
{
    if (!length)
    {
        return Helper::arrayElement<std::string>(interjections);
    }

    const auto shuffledInterjections = Helper::shuffle(interjections);

    for (const auto& interjection : shuffledInterjections)
    {
        if (interjection.size() == length)
        {
            return interjection;
        }
    }

    return Helper::arrayElement<std::string>(shuffledInterjections);
}

std::string Word::noun(std::optional<unsigned int> length)
{
    if (!length)
    {
        return Helper::arrayElement<std::string>(nouns);
    }

    const auto shuffledNouns = Helper::shuffle(nouns);

    for (const auto& noun : shuffledNouns)
    {
        if (noun.size() == length)
        {
            return noun;
        }
    }

    return Helper::arrayElement<std::string>(shuffledNouns);
}

std::string Word::preposition(std::optional<unsigned int> length)
{
    if (!length)
    {
        return Helper::arrayElement<std::string>(prepositions);
    }

    const auto shuffledPrepositions = Helper::shuffle(prepositions);

    for (const auto& preposition : shuffledPrepositions)
    {
        if (preposition.size() == length)
        {
            return preposition;
        }
    }

    return Helper::arrayElement<std::string>(shuffledPrepositions);
}

std::string Word::verb(std::optional<unsigned int> length)
{
    if (!length)
    {
        return Helper::arrayElement<std::string>(verbs);
    }

    const auto shuffledVerbs = Helper::shuffle(verbs);

    for (const auto& verb : shuffledVerbs)
    {
        if (verb.size() == length)
        {
            return verb;
        }
    }

    return Helper::arrayElement<std::string>(shuffledVerbs);
}
}
