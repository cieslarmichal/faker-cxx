#include "../common/formatter.h"
#include "../common/helper.h"
#include "company_data.h"
#include <faker/company.h>
#include <faker/person.h>

namespace faker::company {
// TODO: add internalization

std::string name()
{
    std::string companyName;

    switch (number::integer(3)) {
    case 0:
        companyName = utils::format(
            "{} {}", person::last_name(), Helper::arrayElement(data::companySuffixes));
        break;
    case 1:
        companyName = utils::format(
            "{} {} {}", person::first_name(), person::last_name(), person::job_area());
        break;
    case 2:
        companyName = utils::format(
            "{} {} {} Services", person::first_name(), person::last_name(), person::job_area());
        break;
    case 3:
        companyName = utils::format("{} {} {} {}", person::first_name(), person::last_name(),
            person::job_area(), Helper::arrayElement(data::companySuffixes));
        break;
    }

    return companyName;
}

std::string_view type() { return Helper::arrayElement(data::companyTypes); }

std::string_view industry() { return Helper::arrayElement(data::companyIndustries); }

std::string buzz_phrase()
{
    return utils::format("{} {} {}", buzz_verb(), buzz_adjective(), buzz_noun());
}

std::string_view buzz_adjective() { return Helper::arrayElement(data::buzzAdjectives); }

std::string_view buzz_noun() { return Helper::arrayElement(data::buzzNouns); }

std::string_view buzz_verb() { return Helper::arrayElement(data::buzzVerbs); }

std::string catch_phrase()
{
    return utils::format(
        "{} {} {}", catch_phrase_adjective(), catch_phrase_descriptor(), catch_phrase_noun());
}

std::string_view catch_phrase_adjective()
{
    return Helper::arrayElement(data::catchPhraseAdjectives);
}

std::string_view catch_phrase_descriptor()
{
    return Helper::arrayElement(data::catchPhraseDescriptors);
}

std::string_view catch_phrase_noun() { return Helper::arrayElement(data::catchPhraseNouns); }
}
