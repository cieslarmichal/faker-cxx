#include "faker-cxx/Hacker.h"

#include "../../common/StringHelper.h"
#include "faker-cxx/Helper.h"
#include "HackerData.h"

namespace faker
{
std::string_view Hacker::abbreviation()
{
    return Helper::arrayElement(abbreviations);
}

std::string_view Hacker::adjective()
{
    return Helper::arrayElement(adjectives);
}

std::string_view Hacker::noun()
{
    return Helper::arrayElement(nouns);
}

std::string_view Hacker::verb()
{
    return Helper::arrayElement(verbs);
}

std::string_view Hacker::ingverb()
{
    return Helper::arrayElement(ingverbs);
}

std::string Hacker::phrase()
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
