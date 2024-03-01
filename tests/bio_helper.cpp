#include "bio_helper.h"
#include <faker/internet.h>
#include <modules/person_data.h>
#include <modules/word_data.h>
#include <regex>
#include <vector>

namespace faker {

template <typename ContainerT>
bool findBioPart(const ContainerT& cont, std::smatch::const_reference match)
{
    std::string_view matchView(&*match.first, match.length());
    return std::find(cont.begin(), cont.end(), matchView) != cont.end();
}

bool BioHelper::checkTokenFormat(const std::string& bio)
{
    const std::regex firstRegex { R"(^(\w+\s?\w+)$)" };
    const std::regex secondRegex { R"(^(\w+\s?\w+), (\w+\s?\w+)$)" };
    const std::regex thirdRegex { R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+)$)" };
    const std::regex fourthRegex { R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+), (\S+)$)" };
    const std::regex fifthRegex { R"(^(\w+\-?\w+) (\w+)$)" };
    const std::regex sixthRegex { R"(^(\w+\-?\w+) (\w+) (\S+)$)" };
    const std::regex seventhRegex { R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+)$)" };
    const std::regex eigthRegex { R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+) (\S+)$)" };

    std::smatch matches;

    if (std::regex_match(std::begin(bio), std::end(bio), matches, firstRegex)) {
        // In this case the bio is in the format {bio_part} so check that the value is present in
        // the bio_part vector.
        if (findBioPart(person::data::bio_parts, matches[0])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, secondRegex)) {
        // In this case the bio is in the format {bio_part}, {bio_part} so check that the value is
        // present in the bio_part vector.
        if (findBioPart(person::data::bio_parts, matches[1])
            && findBioPart(person::data::bio_parts, matches[2])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, thirdRegex)) {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part} so check that
        // the value is present in the bio_part vector.
        if (findBioPart(person::data::bio_parts, matches[1])
            && findBioPart(person::data::bio_parts, matches[2])
            && findBioPart(person::data::bio_parts, matches[3])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, fourthRegex)) {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part}, {emoji} so
        // check that the value is present in the bio_part vector.
        if (findBioPart(person::data::bio_parts, matches[1])
            && findBioPart(person::data::bio_parts, matches[2])
            && findBioPart(person::data::bio_parts, matches[3])
            && internet::is_valid_emoji(matches[4])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, fifthRegex)) {
        // In this case the bio is in the format {noun} {bio_supporter} so check that the value is
        // present in the bio_part vector.
        if (findBioPart(word::data::nouns, matches[1])
            && findBioPart(person::data::bio_supporters, matches[2])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, sixthRegex)) {
        // In this case the bio is in the format {noun} {bio_supporter} {emoji} so check that the
        // value is present in the bio_part vector.
        if (findBioPart(word::data::nouns, matches[1])
            && findBioPart(person::data::bio_supporters, matches[2])
            && internet::is_valid_emoji(matches[3])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, seventhRegex)) {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} so check that
        // the value is present in the bio_part vector.
        if (findBioPart(word::data::nouns, matches[1])
            && findBioPart(person::data::bio_supporters, matches[2])
            && findBioPart(person::data::bio_parts, matches[3])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, eigthRegex)) {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} {emoji} so check
        // that the value is present in the bio_part vector.
        if (findBioPart(word::data::nouns, matches[1])
            && findBioPart(person::data::bio_supporters, matches[2])
            && findBioPart(person::data::bio_parts, matches[3])
            && internet::is_valid_emoji(matches[4])) {
            return true;
        }
    }

    return false;
}
}
