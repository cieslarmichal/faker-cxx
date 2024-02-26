#ifndef FAKER_GIT_H
#define FAKER_GIT_H

#include <faker/types/country.h>
#include <optional>
#include <string>

namespace faker::git {
struct Author {
    std::string name;
    std::string email;
};

/**
 * @brief Returns a random branch name.
 *
 * @param maxIssueNum The maximum issue number in branch name. Defaults to `100`.
 * @returns Branch name.
 *
 * @code
 * git::branch() // "capitalize-bus"
 * @endcode
 */
std::string branch(unsigned maxIssueNum = 100);

/**
 * @brief Generates a random date in form of string.
 *
 * @param years The range of years the date may be in the past. Defaults to `15`.
 * @returns Commit date.
 *
 * @code
 * git::commit_date() // "Mon Jan 17 15:05:53 2022 +1100"
 * @endcode
 */
std::string commit_date(unsigned years = 15);

/**
 * @brief Generates a random commit entry in form of string.
 *
 * @param dateYears The range of years the date may be in the past. Defaults to `15`.
 * @param shaLength The length of output SHA hash. Defaults to `40`.
 * @param country The country set for name generating. Defaults to `England` (could be random,
 if there was a random language generator).
 * @returns Commit entry.
 *
 * @code
 * git::commit_entry() // "commit 9cbc41bb8ce0438c8de9cb25a1c6ad33441d8aca
                        Author: Rachel McLaughlin Rachel_McLaughlin@gmail.com
                        Date: Mon Jan 17 15:05:53 2022 +1100

                            spawn polyp"
 * @endcode
 */
std::string commit_entry(std::optional<unsigned> dateYears = std::nullopt,
    std::optional<unsigned> shaLength = std::nullopt, Country country = Country::England);

/**
 * @brief Generates a random commit message.
 *
 * @returns Commit message.
 *
 * @code
 * git::commit_message() // "spawn polyp"
 * @endcode
 */
std::string commit_message();

/**
 * @brief Returns a random SHA hash.
 *
 * @param length The length of output SHA hash. Defaults to `40`.
 *
 * @returns SHA hash.
 *
 * @code
 * git::commit_sha() // "9cbc41bb8ce0438c8de9cb25a1c6ad33441d8aca"
 * @endcode
 */
std::string commit_sha(unsigned length = 40);

/**
 * @brief Returns a random author name and email.
 *
 * @param
 *
 * @returns Author.
 *
 * @code
 * git::author // {Author.name = "Rachel McLaughlin", Author.email =
 * "Rachel_McLaughlin@gmail.com"}
 * @endcode
 */
Author author();
}

#endif