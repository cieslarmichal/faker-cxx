#ifndef FAKER_GIT_H
#define FAKER_GIT_H

#include <faker/types/country.h>
#include <optional>
#include <string>

namespace faker::git {
struct author_info {
    std::string name;
    std::string email;
};

/**
 * @brief Returns a random branch name.
 *
 * @param max_issue_number The maximum issue number in branch name. Defaults to `100`.
 * @returns Branch name.
 *
 * @code
 * git::branch() // "capitalize-bus"
 * @endcode
 */
std::string branch(unsigned max_issue_number = 100);

/**
 * @brief Generates a random date in form of string.
 *
 * @param max_years_ago The range of max_years_ago the date may be in the past. Defaults to `15`.
 * @returns Commit date.
 *
 * @code
 * git::commit_date() // "Mon Jan 17 15:05:53 2022 +1100"
 * @endcode
 */
std::string commit_date(unsigned max_years_ago = 15);

/**
 * @brief Generates a random commit entry in form of string.
 *
 * @param max_years_ago The range of max_years_ago the date may be in the past. Defaults to `15`.
 * @param sha_length The length of output SHA hash. Defaults to `40`.
 * @param country The country set for name generating. Defaults to `england` (could be random, if
 there was a random language generator).
 * @returns Commit entry.
 *
 * @code
 * git::commit_entry() // "commit 9cbc41bb8ce0438c8de9cb25a1c6ad33441d8aca
                        Author: Rachel McLaughlin Rachel_McLaughlin@gmail.com
                        Date: Mon Jan 17 15:05:53 2022 +1100

                            spawn polyp"
 * @endcode
 */
std::string commit_entry(std::optional<unsigned> max_years_ago = std::nullopt,
    std::optional<unsigned> sha_length = std::nullopt, country_t country = country_t::england);

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
 * @returns author_info.
 *
 * @code
 * git::author // {author_info.name = "Rachel McLaughlin", author_info.email =
 * "Rachel_McLaughlin@gmail.com"}
 * @endcode
 */
author_info author();
}

#endif