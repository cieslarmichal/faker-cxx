#include "faker-cxx/hacker.h"

#include <string>
#include <string_view>

#include "common/string_helper.h"
#include "faker-cxx/helper.h"
#include "hacker_data.h"

namespace faker::hacker
{
std::string_view abbreviation()
{
    return helper::arrayElement(abbreviations);
}

std::string_view adjective()
{
    return helper::arrayElement(adjectives);
}

std::string_view noun()
{
    return helper::arrayElement(nouns);
}

std::string_view verb()
{
    return helper::arrayElement(verbs);
}

std::string_view ingverb()
{
    return helper::arrayElement(ingverbs);
}

std::string phrase()
{
    const auto splitRandomPhrase = common::split(static_cast<std::string>(helper::arrayElement(phrases)));

    std::string phrase;

    for (const auto& word : splitRandomPhrase)
    {
        const auto normalizedWord = common::removePunctuation(word);

        if (normalizedWord == "{abbreviation}")
        {
            phrase += abbreviation();
        }
        else if (normalizedWord == "{adjective}")
        {
            phrase += adjective();
        }
        else if (normalizedWord == "{noun}")
        {
            phrase += noun();
        }
        else if (normalizedWord == "{verb}")
        {
            phrase += verb();
        }
        else if (normalizedWord == "{ingverb}")
        {
            phrase += ingverb();
        }
        else
        {
            phrase += normalizedWord;
        }

        phrase += " ";
    }

    return phrase;
}
}
