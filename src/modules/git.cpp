#include "../common/format_helper.h"
#include "../common/string_helper.h"
#include "date_data.h"
#include <faker/date.h>
#include <faker/git.h>
#include <faker/internet.h>
#include <faker/number.h>
#include <faker/person.h>
#include <faker/string.h>
#include <faker/word.h>

namespace faker::git {

std::string branch(unsigned maxIssueNum)
{
    switch (number::integer(1, 3)) {
    case 1:
        return FormatHelper::format("{}-{}", word::verb(), word::noun());
    case 2:
        return FormatHelper::format("{}-{}-{}", word::verb(), word::adjective(), word::noun());
    default:
        return FormatHelper::format("{}-{}-{}-{}", number::integer(unsigned(1), maxIssueNum),
            word::verb(), word::adjective(), word::noun());
    }
}

std::string commit_date(unsigned years)
{
    std::string date = date::past(int(years));
    // std::string_view outputDate = date::weekday_abbr_name();

    std::vector<std::string> dateSplit = StringHelper::split(date, "-");
    std::string year = dateSplit[0];
    std::string month = dateSplit[1];
    std::string rest = dateSplit[2];

    std::vector<std::string> restSplit = StringHelper::split(rest, "T");
    std::string day = restSplit[0];

    std::string time = StringHelper::split(restSplit[1], "Z")[0];

    int timeZone = number::integer(0, 12);
    std::string timeZoneString;
    if (number::integer(0, 1)) {
        timeZoneString += "-";
    } else {
        timeZoneString += "+";
    }

    if (timeZone <= 9) {
        timeZoneString += "0";
    }

    timeZoneString += std::to_string(timeZone * 100);

    if (!timeZone) {
        timeZoneString += "00";
    }

    return FormatHelper::format("{} {} {} {} {} {}", date::weekday_abbr_name(),
        date::data::monthAbbreviatedNames[size_t(std::stoi(month) - 1)], day, time, year,
        timeZoneString);
}

std::string commit_entry(
    std::optional<unsigned> dateYears, std::optional<unsigned> shaLength, Country country)
{
    std::string entry = "commit ";

    if (shaLength) {
        entry += commit_sha(shaLength.emplace());
    } else {
        entry += commit_sha();
    }

    const auto firstName = person::first_name(country);
    const auto lastName = person::last_name(country);

    entry += "\nAuthor: " + firstName + " " + lastName + " " + internet::email(firstName, lastName)
        + "\nDate: ";

    if (dateYears) {
        entry += commit_date(dateYears.emplace());
    } else {
        entry += commit_date();
    }

    entry += "\n\n\t" + commit_message();

    return entry;
}

std::string commit_message()
{
    switch (number::integer(1, 4)) {
    case 1:
        return FormatHelper::format("{} {}", word::verb(), word::noun());
    case 2:
        return FormatHelper::format("{} {} {}", word::verb(), word::adjective(), word::noun());
    case 3:
        return FormatHelper::format("{} {} {}", word::verb(), word::noun(), word::adverb());
    default:
        return FormatHelper::format(
            "{} {} {} {}", word::verb(), word::adjective(), word::noun(), word::adverb());
    }
}

std::string commit_sha(unsigned length)
{
    return faker::string::hexadecimal(length, HexCasing::Lower, HexPrefix::None);
}

Author author()
{
    const std::string firstName = person::first_name();
    const std::string lastName = person::last_name();

    const std::string name = firstName + " " + lastName;
    const std::string email = internet::email(firstName, lastName);

    return { name, email };
}

}
