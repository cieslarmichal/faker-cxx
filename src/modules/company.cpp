#include "faker-cxx/company.h"

#include <string>
#include <string_view>

#include "common/format_helper.h"
#include "company_data.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/person.h"

namespace faker::company
{
    namespace{
        const struct CompanyDefinition& getCompanyDefinition(Locale locale)
        {
            switch(locale)
            {
                default:
                    return enUSCompanyDefinition;
            }
        }
    }
std::string companyName(std::optional<CompanyNameFormat> format, Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    CompanyNameFormat nameFormat = format ? *format : CompanyNameFormat::LastNameSuffix;

    std::string companyName;

    switch (nameFormat)
    {
    case CompanyNameFormat::LastNameSuffix:
        companyName = common::format("{} {}", person::lastName(), helper::randomElement(companyDefintion.companySuffixes));
        break;
    case CompanyNameFormat::FirstNameLastNameSuffix:
        companyName =
            common::format("{} {} {}", person::firstName(), person::lastName(), helper::randomElement(companyDefintion.companySuffixes));
        break;
    case CompanyNameFormat::FirstNameLastNameJobAreaSuffix:
        companyName = common::format("{} {} {} {}", person::firstName(), person::lastName(), person::jobArea(),
                                     helper::randomElement(companyDefintion.companySuffixes));
        break;
    }

    return companyName;
}

std::string_view type(Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    return helper::randomElement(companyDefintion.companyTypes);
}

std::string_view industry(Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    return helper::randomElement(companyDefintion.companyIndustries);
}

std::string buzzPhrase(Locale locale)
{
    return common::format("{} {} {}", buzzVerb(locale), buzzAdjective(locale), buzzNoun(locale));
}

std::string_view buzzAdjective(Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    return helper::randomElement(companyDefintion.buzzAdjectives);
}

std::string_view buzzNoun(Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    return helper::randomElement(companyDefintion.buzzNouns);
}

std::string_view buzzVerb(Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    return helper::randomElement(companyDefintion.buzzVerbs);
}

std::string catchPhrase(Locale locale)
{
    return common::format("{} {} {}", catchPhraseAdjective(locale), catchPhraseDescriptor(locale), catchPhraseNoun(locale));
}

std::string_view catchPhraseAdjective(Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    return helper::randomElement(companyDefintion.catchPhraseAdjectives);
}

std::string_view catchPhraseDescriptor(Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    return helper::randomElement(companyDefintion.catchPhraseDescriptors);
}

std::string_view catchPhraseNoun(Locale locale)
{
    const auto& companyDefintion = getCompanyDefinition(locale);
    return helper::randomElement(companyDefintion.catchPhraseNouns);
}
}
