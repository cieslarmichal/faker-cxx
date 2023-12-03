#include "BioHelper.h"

#include "../../include/faker-cxx/Internet.h"
#include "../../src/modules/person/data/Bio.h"
#include "../../src/modules/word/data/Nouns.h"

namespace faker
{
bool BioHelper::checkTokenFormat(const std::string& bio)
{

    const std::regex firstRegex{R"(^[a-zA-Z0-9_]+$)"};
    const std::regex secondRegex{R"(^(\w+\s?\w+), (\w+\s?\w+)$)"};
    const std::regex thirdRegex{R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+)$)"};
    const std::regex fourthRegex{R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+), (\S+)$)"};
    const std::regex fifthRegex{R"(^(\w+) (\w+)$)"};
    const std::regex sixthRegex{R"(^(\w+) (\w+) (\S+)$)"};
    const std::regex seventhRegex{R"(^(\w+) (\w+), (\w+\s?\w+)$)"};
    const std::regex eigthRegex{R"(^(\w+) (\w+), (\w+\s?\w+) (\S+)$)"};

    std::smatch matches;
    //
    if (std::regex_match(bio, matches, firstRegex))
    {
        // In this case the bio is in the format {bio_part} so check that the value is present in the bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[0]) != bioPart.end())
            return true;

        else
            return false;
    }
    else if (std::regex_match(bio, matches, secondRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part} so check that the value is present in the
        // bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end())
            return true;

        else
            return false;
    }
    else if (std::regex_match(bio, matches, thirdRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part} so check that the value is present
        // in the bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end())
            return true;

        else
            return false;
    }
    else if (std::regex_match(bio, matches, fourthRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part}, {emoji} so check that the value is
        // present in the bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end() && 
            Internet::checkIfEmojiIsValid(matches[4]))
            return true;

        else
            return false;
    }
    else if (std::regex_match(bio, matches, fifthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end())
            return true;

        else
            return false;
    }
    else if (std::regex_match(bio, matches, sixthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} {emoji} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            Internet::checkIfEmojiIsValid(matches[3]))
            return true;

        else
            return false;
    }
    else if (std::regex_match(bio, matches, seventhRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end())
            return true;

        else
            return false;
    }
    else if (std::regex_match(bio, matches, eigthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} {emoji} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end() && 
            Internet::checkIfEmojiIsValid(matches[4]))
            return true;

        else
            return false;
    }

    return false;
}
}
