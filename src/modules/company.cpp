#include "../common/format_helper.h"
#include "company_data.h"
#include <faker/company.h>
#include <faker/helper.h>
#include <faker/person.h>

namespace faker::company {
// TODO: add internalization

std::string name()
{
    std::string companyName;

    switch (number::integer(3)) {
    case 0:
        companyName = FormatHelper::format(
            "{} {}", person::lastName(), Helper::arrayElement(data::companySuffixes));
        break;
    case 1:
        companyName = FormatHelper::format(
            "{} {} {}", person::firstName(), person::lastName(), person::jobArea());
        break;
    case 2:
        companyName = FormatHelper::format(
            "{} {} {} Services", person::firstName(), person::lastName(), person::jobArea());
        break;
    case 3:
        companyName = FormatHelper::format("{} {} {} {}", person::firstName(), person::lastName(),
            person::jobArea(), Helper::arrayElement(data::companySuffixes));
        break;
    }

    return companyName;
}

std::string_view type() { return Helper::arrayElement(data::companyTypes); }

std::string_view industry() { return Helper::arrayElement(data::companyIndustries); }

std::string buzzPhrase()
{
    return FormatHelper::format("{} {} {}", buzzVerb(), buzzAdjective(), buzzNoun());
}

std::string_view buzzAdjective() { return Helper::arrayElement(data::buzzAdjectives); }

std::string_view buzzNoun() { return Helper::arrayElement(data::buzzNouns); }

std::string_view buzzVerb() { return Helper::arrayElement(data::buzzVerbs); }

std::string catchPhrase()
{
    return FormatHelper::format(
        "{} {} {}", catchPhraseAdjective(), catchPhraseDescriptor(), catchPhraseNoun());
}

std::string_view catchPhraseAdjective()
{
    return Helper::arrayElement(data::catchPhraseAdjectives);
}

std::string_view catchPhraseDescriptor()
{
    return Helper::arrayElement(data::catchPhraseDescriptors);
}

std::string_view catchPhraseNoun() { return Helper::arrayElement(data::catchPhraseNouns); }
}
