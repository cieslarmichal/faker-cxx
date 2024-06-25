#include "faker-cxx/Company.h"

#include <string>
#include <string_view>

#include "../../common/FormatHelper.h"
#include "CompanyData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/Person.h"

namespace faker::company
{
std::string name()
{
    std::string companyName;

    switch (faker::number::integer<int>(3))
    {
    case 0:
        companyName = FormatHelper::format("{} {}", Person::lastName(), Helper::arrayElement(companySuffixes));
        break;
    case 1:
        companyName = FormatHelper::format("{} {} {}", Person::firstName(), Person::lastName(), Person::jobArea());
        break;
    case 2:
        companyName =
            FormatHelper::format("{} {} {} Services", Person::firstName(), Person::lastName(), Person::jobArea());
        break;
    case 3:
        companyName = FormatHelper::format("{} {} {} {}", Person::firstName(), Person::lastName(), Person::jobArea(),
                                           Helper::arrayElement(companySuffixes));
        break;
    }

    return companyName;
}

std::string_view type()
{
    return Helper::arrayElement(companyTypes);
}

std::string_view industry()
{
    return Helper::arrayElement(companyIndustries);
}

std::string buzzPhrase()
{
    return FormatHelper::format("{} {} {}", buzzVerb(), buzzAdjective(), buzzNoun());
}

std::string_view buzzAdjective()
{
    return Helper::arrayElement(buzzAdjectives);
}

std::string_view buzzNoun()
{
    return Helper::arrayElement(buzzNouns);
}

std::string_view buzzVerb()
{
    return Helper::arrayElement(buzzVerbs);
}

std::string catchPhrase()
{
    return FormatHelper::format("{} {} {}", catchPhraseAdjective(), catchPhraseDescriptor(), catchPhraseNoun());
}

std::string_view catchPhraseAdjective()
{
    return Helper::arrayElement(catchPhraseAdjectives);
}

std::string_view catchPhraseDescriptor()
{
    return Helper::arrayElement(catchPhraseDescriptors);
}

std::string_view catchPhraseNoun()
{
    return Helper::arrayElement(catchPhraseNouns);
}
}
