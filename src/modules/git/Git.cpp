#include "faker-cxx/Git.h"

#include <string>

#include "../../common/StringHelper.h"
#include "../date/data/MonthNames.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/String.h"
#include "faker-cxx/types/Language.h"
#include "faker-cxx/Word.h"
#include "fmt/format.h"

namespace faker
{

std::string Git::branch(unsigned maxIssueNum)
{
    switch (Number::integer(1, 3))
    {
    case 1:
        return fmt::format("{}-{}", Word::verb(), Word::noun());
    case 2:
        return fmt::format("{}-{}-{}", Word::verb(), Word::adjective(), Word::noun());
    default:
        return fmt::format("{}-{}-{}-{}", Number::integer(unsigned(1), maxIssueNum), Word::verb(), Word::adjective(),
                           Word::noun());
    }
}

std::string Git::commitDate(unsigned years)
{
    std::string date = Date::pastDate(int(years));
    std::string outputDate = Date::weekdayAbbreviatedName();

    std::vector<std::string> dateSplit = StringHelper::split(date, "-");
    std::string year = dateSplit[0];
    std::string month = dateSplit[1];
    std::string rest = dateSplit[2];

    std::vector<std::string> restSplit = StringHelper::split(rest, "T");
    std::string day = restSplit[0];

    std::string time = StringHelper::split(restSplit[1], "Z")[0];

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

    return fmt::format("{} {} {} {} {} {}", Date::weekdayAbbreviatedName(),
                       monthAbbreviatedNames[size_t(std::stoi(month) - 1)], day, time, year, timeZoneString);
}

std::string Git::commitEntry(std::optional<unsigned> dateYears, std::optional<unsigned> shaLength, Language language)
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

    std::string firstName = Person::firstName(language);
    std::string lastName = Person::lastName(language);
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
        return fmt::format("{} {}", Word::verb(), Word::noun());
    case 2:
        return fmt::format("{} {} {}", Word::verb(), Word::adjective(), Word::noun());
    case 3:
        return fmt::format("{} {} {}", Word::verb(), Word::noun(), Word::adverb());
    default:
        return fmt::format("{} {} {} {}", Word::verb(), Word::adjective(), Word::noun(), Word::adverb());
    }
}

std::string Git::commitSha(unsigned length)
{
    return faker::String::hexadecimal(length, HexCasing::Lower, HexPrefix::None);
}
}
