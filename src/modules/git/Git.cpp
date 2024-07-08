#include "faker-cxx/Git.h"

#include <optional>
#include <string>

#include "common/FormatHelper.h"
#include "common/StringHelper.h"
#include "../date/DateData.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/String.h"
#include "faker-cxx/types/Country.h"
#include "faker-cxx/types/Hex.h"
#include "faker-cxx/Word.h"

namespace faker::git
{

std::string branch(unsigned maxIssueNum)
{
    switch (number::integer(1, 2))
    {
    case 1:
        return common::format("{}-{}", word::verb(), word::noun());
    default:
        return common::format("{}-{}-{}-{}", number::integer(unsigned(1), maxIssueNum), word::verb(),
                                    word::adjective(), word::noun());
    }
}

std::string commitDate(unsigned years)
{
    const std::string pastDate = faker::date::pastDate(int(years));

    return pastDate;
}

std::string commitEntry(std::optional<unsigned> dateYears, std::optional<unsigned> shaLength, Country country)
{
    std::string entry = "commit ";

    if (shaLength.value_or(0))
    {
        entry += commitSha(shaLength.value_or(0));
    }
    else
    {
        entry += commitSha();
    }

    const auto firstName = static_cast<std::string>(person::firstName(country));
    const auto lastName = static_cast<std::string>(person::lastName(country));

    entry += "\nAuthor: " + firstName + " " + lastName + " " + internet::email(firstName, lastName) + "\nDate: ";

    if (dateYears.value_or(0))
    {
        entry += commitDate(dateYears.value_or(0));
    }
    else
    {
        entry += commitDate();
    }

    entry += "\n\n\t" + commitMessage();

    return entry;
}

std::string commitMessage()
{
    switch (number::integer(1, 2))
    {
    case 1:
        return common::format("{} {}", word::verb(), word::noun());
    default:
        return common::format("{} {} {}", word::verb(), word::adjective(), word::noun());
    }
}

std::string commitSha(unsigned length)
{
    return faker::string::hexadecimal(length, HexCasing::Lower, HexPrefix::None);
}

}
