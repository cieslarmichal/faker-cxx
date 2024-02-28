#include "../common/formatter.h"
#include "../common/random.h"
#include "company_data.h"
#include <faker/company.h>
#include <faker/number.h>
#include <faker/person.h>

namespace faker::company {

std::string name()
{
    std::string result;

    switch (number::integer(3)) {
    case 0:
        result
            = utils::format("{} {}", person::last_name(), random::element(data::company_suffixes));
        break;
    case 1:
        result = utils::format(
            "{} {} {}", person::first_name(), person::last_name(), person::job_area());
        break;
    case 2:
        result = utils::format(
            "{} {} {} Services", person::first_name(), person::last_name(), person::job_area());
        break;
    case 3:
        result = utils::format("{} {} {} {}", person::first_name(), person::last_name(),
            person::job_area(), random::element(data::company_suffixes));
        break;
    }

    return result;
}

std::string_view type() { return random::element(data::company_types); }

std::string_view industry() { return random::element(data::company_industries); }

std::string buzz_phrase()
{
    return utils::format("{} {} {}", buzz_verb(), buzz_adjective(), buzz_noun());
}

std::string_view buzz_adjective() { return random::element(data::buzz_adjectives); }

std::string_view buzz_noun() { return random::element(data::buzz_nouns); }

std::string_view buzz_verb() { return random::element(data::buzz_verbs); }

std::string catch_phrase()
{
    return utils::format(
        "{} {} {}", catch_phrase_adjective(), catch_phrase_descriptor(), catch_phrase_noun());
}

std::string_view catch_phrase_adjective() { return random::element(data::catch_phrase_adjectives); }

std::string_view catch_phrase_descriptor()
{
    return random::element(data::catch_phrase_descriptors);
}

std::string_view catch_phrase_noun() { return random::element(data::catch_phrase_nouns); }
}
