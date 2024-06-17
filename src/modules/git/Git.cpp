#include "faker-cxx/Git.h"

#include <optional>
#include <string>

#include "../../common/FormatHelper.h"
#include "../../common/StringHelper.h"
#include "../date/DateData.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/String.h"
#include "faker-cxx/types/Country.h"
#include "faker-cxx/types/Hex.h"
#include "faker-cxx/Word.h"

namespace faker
{

std::string Git::branch(unsigned maxIssueNum)
{
    switch (Number::integer(1, 3))
    {
    case 1:
        return FormatHelper::format("{}-{}", word::verb(), word::noun());
    case 2:
        return FormatHelper::format("{}-{}-{}", word::verb(), word::adjective(), word::noun());
    default:
        return FormatHelper::format("{}-{}-{}-{}", Number::integer(unsigned(1), maxIssueNum), word::verb(),
                                    word::adjective(), word::noun());
    }
}

std::string Git::commitDate(unsigned years)
{
    const auto date = Date::pastDate(int(years));

    const auto dateSplit = StringHelper::split(date, "-");

    const auto& year = dateSplit[0];
    const auto& month = dateSplit[1];
    const auto& rest = dateSplit[2];

    const auto restSplit = StringHelper::split(rest, "T");

    const auto& day = restSplit[0];

    const auto time = StringHelper::split(restSplit[1], "Z")[0];

    int timeZone = Number::integer(0, 12);

    std::string timeZoneString;

    if (Number::integer(0, 1))
    {
        timeZoneString += "-";
    }
    else
    {
        timeZoneString += "+";
    }

    if (timeZone <= 9)
    {
        timeZoneString += "0";
    }

    timeZoneString += std::to_string(timeZone * 100);

    if (!timeZone)
    {
        timeZoneString += "00";
    }

    return FormatHelper::format("{} {} {} {} {} {}", Date::weekdayAbbreviatedName(),
                                monthAbbreviatedNames[size_t(std::stoi(month) - 1)], day, time, year, timeZoneString);
}

std::string Git::commitEntry(std::optional<unsigned> dateYears, std::optional<unsigned> shaLength, Country country)
{
    std::string entry = "commit ";

    if (shaLength)
    {
        entry += commitSha(shaLength.emplace());
    }
    else
    {
        entry += commitSha();
    }

    const auto firstName = static_cast<std::string>(Person::firstName(country));
    const auto lastName = static_cast<std::string>(Person::lastName(country));

    entry += "\nAuthor: " + firstName + " " + lastName + " " + Internet::email(firstName, lastName) + "\nDate: ";

    if (dateYears)
    {
        entry += commitDate(dateYears.emplace());
    }
    else
    {
        entry += commitDate();
    }

    entry += "\n\n\t" + commitMessage();

    return entry;
}

std::string Git::commitMessage()
{
    switch (Number::integer(1, 4))
    {
    case 1:
        return FormatHelper::format("{} {}", word::verb(), word::noun());
    case 2:
        return FormatHelper::format("{} {} {}", word::verb(), word::adjective(), word::noun());
    case 3:
        return FormatHelper::format("{} {} {}", word::verb(), word::noun(), word::adverb());
    default:
        return FormatHelper::format("{} {} {} {}", word::verb(), word::adjective(), word::noun(), word::adverb());
    }
}

std::string Git::commitSha(unsigned length)
{
    return faker::String::hexadecimal(length, HexCasing::Lower, HexPrefix::None);
}

}
