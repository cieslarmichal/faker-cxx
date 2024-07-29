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
std::string companyName(std::optional<CompanyNameFormat> format)
{
    CompanyNameFormat nameFormat = format ? *format : CompanyNameFormat::LastNameSuffix;

    std::string companyName = "";

    switch (nameFormat)
    {
    case CompanyNameFormat::LastNameSuffix:
        companyName = common::format("{} {}", person::lastName(), helper::arrayElement(companySuffixes));
        break;
    case CompanyNameFormat::FirstNameLastNameSuffix:
        companyName = common::format("{} {} {}", person::firstName(), person::lastName(), helper::arrayElement(companySuffixes));
        break;
    case CompanyNameFormat::FirstNameLastNameJobAreaSuffix:
        companyName =
            common::format("{} {} {} {}", person::firstName(), person::lastName(), person::jobArea(), 
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
