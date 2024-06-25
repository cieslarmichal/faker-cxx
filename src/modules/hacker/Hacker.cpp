#include "faker-cxx/Hacker.h"

#include <string>
#include <string_view>

#include "../../common/StringHelper.h"
#include "faker-cxx/Helper.h"
#include "HackerData.h"

namespace faker::hacker
{
std::string_view abbreviation()
{
    return Helper::arrayElement(abbreviations);
}

std::string_view adjective()
{
    return Helper::arrayElement(adjectives);
}

std::string_view noun()
{
    return Helper::arrayElement(nouns);
}

std::string_view verb()
{
    return Helper::arrayElement(verbs);
}

std::string_view ingverb()
{
    return Helper::arrayElement(ingverbs);
}

std::string phrase()
{
    const auto splitRandomPhrase = StringHelper::split(static_cast<std::string>(Helper::arrayElement(phrases)));

    std::string phrase;

    for (const auto& word : splitRandomPhrase)
    {
        const auto normalizedWord = StringHelper::removePunctuation(word);

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
