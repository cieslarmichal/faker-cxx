#include "../common/formatter.h"
#include "../common/strings.h"
#include "date_data.h"
#include <faker/date.h>
#include <faker/git.h>
#include <faker/internet.h>
#include <faker/number.h>
#include <faker/person.h>
#include <faker/string.h>
#include <faker/word.h>

namespace faker::git {

std::string branch(unsigned max_issue_number)
{
    switch (number::integer(1, 3)) {
    case 1:
        return utils::format("{}-{}", word::verb(), word::noun());
    case 2:
        return utils::format("{}-{}-{}", word::verb(), word::adjective(), word::noun());
    default:
        return utils::format("{}-{}-{}-{}", number::integer(1U, max_issue_number), word::verb(),
            word::adjective(), word::noun());
    }
}

std::string commit_date(unsigned max_years_ago)
{
    std::string date = date::past(max_years_ago);

    auto date_parts = utils::split(date, "-");
    std::string_view year = date_parts[0];
    std::string_view month = date_parts[1];
    std::string_view rest = date_parts[2];

    auto rest_parts = utils::split(rest, "T");
    auto day = rest_parts[0];

    auto time = utils::split(rest_parts[1], "Z")[0];

    int time_zone = number::integer(0, 12);
    std::string time_zone_string;
    if (number::integer(0, 1)) {
        time_zone_string += '-';
    } else {
        time_zone_string += '+';
    }
    if (time_zone <= 9) {
        time_zone_string += '0';
    }
    time_zone_string += std::to_string(time_zone * 100);
    if (!time_zone) {
        time_zone_string += "00";
    }

    return utils::format("{} {} {} {} {} {}", date::weekday_abbr_name(),
        date::data::month_abbr_names[size_t(utils::to_int(month) - 1)], day, time, year,
        time_zone_string);
}

std::string commit_entry(
    std::optional<unsigned> max_years_ago, std::optional<unsigned> sha_length, country_t country)
{
    auto sha = sha_length ? commit_sha(*sha_length) : commit_sha();
    auto first_name = std::string(person::first_name(country));
    auto last_name = std::string(person::last_name(country));
    auto email = internet::email(first_name, last_name);
    auto date_str = max_years_ago ? commit_date(*max_years_ago) : commit_date();
    auto message = commit_message();

    return utils::format("commit {}\nAuthor: {} {} {}\nDate: {}\n\n\t{}", sha, first_name,
        last_name, email, date_str, message);
}

std::string commit_message()
{
    switch (number::integer(1, 4)) {
    case 1:
        return utils::format("{} {}", word::verb(), word::noun());
    case 2:
        return utils::format("{} {} {}", word::verb(), word::adjective(), word::noun());
    case 3:
        return utils::format("{} {} {}", word::verb(), word::noun(), word::adverb());
    default:
        return utils::format(
            "{} {} {} {}", word::verb(), word::adjective(), word::noun(), word::adverb());
    }
}

std::string commit_sha(unsigned length)
{
    return faker::string::hexadecimal(length, hex_case_t::lower, hex_prefix_t::none);
}

author_info author()
{
    auto first_name = std::string(person::first_name());
    auto last_name = std::string(person::last_name());
    auto name = first_name + " " + last_name;
    auto email = internet::email(first_name, last_name);

    return { name, email };
}

}
