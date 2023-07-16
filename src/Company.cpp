#include "include/faker-cxx/Company.h"

#include <format>

#include "data/company/BuzzAdjectives.h"
#include "data/company/BuzzNouns.h"
#include "data/company/BuzzVerbs.h"
#include "data/company/CatchPhraseAdjectives.h"
#include "data/company/CatchPhraseDescriptors.h"
#include "data/company/CatchPhraseNouns.h"
#include "data/company/CompanyTypes.h"
#include "data/company/Industries.h"
#include "data/company/Suffixes.h"
#include "include/faker-cxx/Helper.h"
#include "include/faker-cxx/Person.h"

namespace faker
{
std::string Company::name()
{
    std::string companyName;

    switch (Number::integer<int>(3))
    {
    case 0:
        companyName = std::format("{} {}", Person::lastName(), Helper::arrayElement<std::string>(companySuffixes));
        break;
    case 1:
        companyName = std::format("{} {} {}", Person::firstName(), Person::lastName(), Person::jobArea());
        break;
    case 2:
        companyName = std::format("{} {} {} Services", Person::firstName(), Person::lastName(), Person::jobArea());
        break;
    case 3:
        companyName = std::format("{} {} {} {}", Person::firstName(), Person::lastName(), Person::jobArea(),
                                  Helper::arrayElement<std::string>(companySuffixes));
        break;
    }

    return companyName;
}

std::string Company::type()
{
    return Helper::arrayElement<std::string>(companyTypes);
}

std::string Company::industry()
{
    return Helper::arrayElement<std::string>(companyIndustries);
}

std::string Company::buzzPhrase()
{
    return std::format("{} {} {}", buzzVerb(), buzzAdjective(), buzzNoun());
}

std::string Company::buzzAdjective()
{
    return Helper::arrayElement<std::string>(buzzAdjectives);
}

std::string Company::buzzNoun()
{
    return Helper::arrayElement<std::string>(buzzNouns);
}

std::string Company::buzzVerb()
{
    return Helper::arrayElement<std::string>(buzzVerbs);
}

std::string Company::catchPhrase()
{
    return std::format("{} {} {}", catchPhraseAdjective(), catchPhraseDescriptor(), catchPhraseNoun());
}

std::string Company::catchPhraseAdjective()
{
    return Helper::arrayElement<std::string>(catchPhraseAdjectives);
}

std::string Company::catchPhraseDescriptor()
{
    return Helper::arrayElement<std::string>(catchPhraseDescriptors);
}

std::string Company::catchPhraseNoun()
{
    return Helper::arrayElement<std::string>(catchPhraseNouns);
}
}
