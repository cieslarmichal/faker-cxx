#include "faker-cxx/git.h"

#include <optional>
#include <string>

#include "common/format_helper.h"
#include "faker-cxx/date.h"
#include "faker-cxx/internet.h"
#include "faker-cxx/number.h"
#include "faker-cxx/person.h"
#include "faker-cxx/types/hex.h"
#include "faker-cxx/types/locale.h"
#include "faker-cxx/word.h"

namespace faker::git
{
std::string branch(std::optional<BranchIssueType> issueType, unsigned maxIssueNum)
{
    const auto targetIssueType = issueType ? *issueType : BranchIssueType::WithIssueNumber;

    std::string generatedBranch;

    switch (targetIssueType)
    {
    case BranchIssueType::WithoutIssueNumber:
        generatedBranch = common::format("{}-{}", word::verb(), word::noun());
        break;
    case BranchIssueType::WithIssueNumber:
        generatedBranch = common::format("{}-{}-{}-{}", number::integer(unsigned(1), maxIssueNum), word::verb(),
                                         word::adjective(), word::noun());
        break;
    }

    return generatedBranch;
}

std::string commitDate(unsigned years)
{
    return faker::date::pastDate(int(years));
}

std::string commitEntry(std::optional<unsigned> dateYears, std::optional<unsigned> shaLength, Locale locale)
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

    const auto firstName = static_cast<std::string>(person::firstName(locale));
    const auto lastName = static_cast<std::string>(person::lastName(locale));

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
    return common::format("{} {}", word::verb(), word::noun());
}

std::string commitSha(unsigned length)
{
    return faker::number::hexadecimal(length, HexCasing::Lower, HexPrefix::None);
}

}
