#include "faker-cxx/Hacker.h"
#include "../../common/StringHelper.h"

#include <string>
#include <vector>

#include "data/Abbreviations.h"
#include "data/Adjectives.h"
#include "data/Ingverbs.h"
#include "data/Nouns.h"
#include "data/Phrases.h"
#include "data/Verbs.h"

namespace faker
{
std::string Hacker::abbreviation()
{
    return faker::Helper::arrayElement<std::string>(faker::abbreviations);
}

std::string Hacker::adjective()
{
    return faker::Helper::arrayElement<std::string>(faker::adjectives);
}

std::string Hacker::noun()
{
    return faker::Helper::arrayElement<std::string>(faker::nouns);
}

std::string Hacker::verb()
{
    return faker::Helper::arrayElement<std::string>(faker::verbs);
}

std::string Hacker::ingverb()
{
    return faker::Helper::arrayElement<std::string>(faker::ingverbs);
}

std::string Hacker::phrase()
{
    auto splitRandomPhrase = StringHelper::split(faker::Helper::arrayElement<std::string>(faker::phrases));
    std::string ret;

    for (auto& word : splitRandomPhrase)
    {
        word = StringHelper::removePunctuation(word);
        if (word == "{abbreviation}")
        {
            word = abbreviation();
        }
        else if (word == "{adjective}")
        {
            word = adjective();
        }
        else if (word == "{noun}")
        {
            word = noun();
        }
        else if (word == "{verb}")
        {
            word = verb();
        }
        else if (word == "{ingverb}")
        {
            word = ingverb();
        }

        ret += word + " ";
    }

    return ret;
}
}
