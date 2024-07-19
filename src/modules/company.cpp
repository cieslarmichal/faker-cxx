#include "faker-cxx/company.h"

#include <string>
#include <string_view>

#include "common/format_helper.h"
#include "company_data.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/person.h"

namespace faker::company
{
std::string name()
{
    std::string companyName;

    switch (number::integer<int>(3))
    {
    case 0:
        companyName = common::format("{} {}", person::lastName(), helper::arrayElement(companySuffixes));
        break;
    case 1:
        companyName = common::format("{} {} {}", person::firstName(), person::lastName(), person::jobArea());
        break;
    case 2:
        companyName =
            common::format("{} {} {} Services", person::firstName(), person::lastName(), person::jobArea());
        break;
    case 3:
        companyName = common::format("{} {} {} {}", person::firstName(), person::lastName(), person::jobArea(),
                                           helper::arrayElement(companySuffixes));
        break;
    }

    return companyName;
}

std::string_view type()
{
    return helper::arrayElement(companyTypes);
}

std::string_view industry()
{
    return helper::arrayElement(companyIndustries);
}

std::string buzzPhrase()
{
    return common::format("{} {} {}", buzzVerb(), buzzAdjective(), buzzNoun());
}

std::string_view buzzAdjective()
{
    return helper::arrayElement(buzzAdjectives);
}

std::string_view buzzNoun()
{
    return helper::arrayElement(buzzNouns);
}

std::string_view buzzVerb()
{
    return helper::arrayElement(buzzVerbs);
}

std::string catchPhrase()
{
    return common::format("{} {} {}", catchPhraseAdjective(), catchPhraseDescriptor(), catchPhraseNoun());
}

std::string_view catchPhraseAdjective()
{
    return helper::arrayElement(catchPhraseAdjectives);
}

std::string_view catchPhraseDescriptor()
{
    return helper::arrayElement(catchPhraseDescriptors);
}

std::string_view catchPhraseNoun()
{
    return helper::arrayElement(catchPhraseNouns);
}
}
