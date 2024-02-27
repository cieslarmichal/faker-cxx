#include "../common/formatter.h"
#include "../common/random.h"
#include "company_data.h"
#include <faker/company.h>
#include <faker/number.h>
#include <faker/person.h>

namespace faker::company {
// TODO: add internalization

std::string name()
{
    std::string companyName;

    switch (number::integer(3)) {
    case 0:
        companyName
            = utils::format("{} {}", person::last_name(), random::element(data::companySuffixes));
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
            person::job_area(), random::element(data::companySuffixes));
        break;
    }

    return companyName;
}

std::string_view type() { return random::element(data::companyTypes); }

std::string_view industry() { return random::element(data::companyIndustries); }

std::string buzz_phrase()
{
    return utils::format("{} {} {}", buzz_verb(), buzz_adjective(), buzz_noun());
}

std::string_view buzz_adjective() { return random::element(data::buzzAdjectives); }

std::string_view buzz_noun() { return random::element(data::buzzNouns); }

std::string_view buzz_verb() { return random::element(data::buzzVerbs); }

std::string catch_phrase()
{
    return utils::format(
        "{} {} {}", catch_phrase_adjective(), catch_phrase_descriptor(), catch_phrase_noun());
}

std::string_view catch_phrase_adjective() { return random::element(data::catchPhraseAdjectives); }

std::string_view catch_phrase_descriptor() { return random::element(data::catchPhraseDescriptors); }

std::string_view catch_phrase_noun() { return random::element(data::catchPhraseNouns); }
}
