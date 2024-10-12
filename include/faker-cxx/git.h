#pragma once

#include <optional>
#include <string>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::git
{
struct FAKER_CXX_EXPORT Author
{
    std::string name;
    std::string email;
};

enum class BranchIssueType
{
    WithoutIssueNumber,
    WithIssueNumber,
};

/**
 * @brief Returns a random branch name.
 *
 * @param issueType The optional branch issue type.
 * @param maxIssueNum The maximum issue number in branch name. Defaults to `100`.
 *
 * @returns Branch name.
 *
 * @code
 * faker::git::branch() // "capitalize-bus"
 * @endcode
 */
FAKER_CXX_EXPORT std::string branch(std::optional<BranchIssueType> issueType = std::nullopt,
                                    unsigned maxIssueNum = 100);

/**
 * @brief Generates a random date in form of string.
 *
 * @param years The range of years the date may be in the past. Defaults to `15`.
 *
 * @returns Commit date.
 *
 * @code
 * faker::git::commitDate() // "Mon Jan 17 15:05:53 2022 +1100"
 * @endcode
 */
FAKER_CXX_EXPORT std::string commitDate(unsigned years = 15);

/**
 * @brief Generates a random commit entry in form of string.
 *
 * @param dateYears The range of years the date may be in the past. Defaults to `15`.
 * @param shaLength The length of output SHA hash. Defaults to `40`.
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Commit entry.
 *
 * @code
 * faker::git::commitEntry() // "commit 9cbc41bb8ce0438c8de9cb25a1c6ad33441d8aca
                        Author: Rachel McLaughlin Rachel_McLaughlin@gmail.com
                        Date: Mon Jan 17 15:05:53 2022 +1100

                            spawn polyp"
 * @endcode
 */
FAKER_CXX_EXPORT std::string commitEntry(std::optional<unsigned> dateYears = std::nullopt,
                                         std::optional<unsigned> shaLength = std::nullopt,
                                         Locale locale = Locale::en_US);

/**
 * @brief Generates a random commit message.
 *
 * @returns Commit message.
 *
 * @code
 * faker::git::commitMessage() // "spawn polyp"
 * @endcode
 */
FAKER_CXX_EXPORT std::string commitMessage();

/**
 * @brief Returns a random SHA hash.
 *
 * @param length The length of output SHA hash. Defaults to `40`.
 *
 * @returns SHA hash.
 *
 * @code
 * faker::git::commitSha() // "9cbc41bb8ce0438c8de9cb25a1c6ad33441d8aca"
 * @endcode
 */
FAKER_CXX_EXPORT std::string commitSha(unsigned length = 40);
}
