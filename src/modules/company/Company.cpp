#include "faker-cxx/Company.h"

#include <string>
#include <string_view>

#include "../../common/FormatHelper.h"
#include "CompanyData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/Person.h"

namespace faker
{
std::string Company::name()
{
    std::string companyName;

    switch (Number::integer<int>(3))
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

std::string_view Company::type()
{
    return Helper::arrayElement(companyTypes);
}

std::string_view Company::industry()
{
    return Helper::arrayElement(companyIndustries);
}

std::string Company::buzzPhrase()
{
    return FormatHelper::format("{} {} {}", buzzVerb(), buzzAdjective(), buzzNoun());
}

std::string_view Company::buzzAdjective()
{
    return Helper::arrayElement(buzzAdjectives);
}

std::string_view Company::buzzNoun()
{
    return Helper::arrayElement(buzzNouns);
}

std::string_view Company::buzzVerb()
{
    return Helper::arrayElement(buzzVerbs);
}

std::string Company::catchPhrase()
{
    return FormatHelper::format("{} {} {}", catchPhraseAdjective(), catchPhraseDescriptor(), catchPhraseNoun());
}

std::string_view Company::catchPhraseAdjective()
{
    return Helper::arrayElement(catchPhraseAdjectives);
}

std::string_view Company::catchPhraseDescriptor()
{
    return Helper::arrayElement(catchPhraseDescriptors);
}

std::string_view Company::catchPhraseNoun()
{
    return Helper::arrayElement(catchPhraseNouns);
}
}
