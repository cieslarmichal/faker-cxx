#include "../common/random.h"
#include "string_data.h"
#include <cassert>
#include <faker/number.h>
#include <faker/string.h>
#include <random>
#include <stdexcept>
#include <unordered_map>

namespace faker::string {

std::string_view to_string(hex_prefix_t prefix)
{
    switch (prefix) {
    case hex_prefix_t::zero_x:
        return "0x";
    case hex_prefix_t::hash:
        return "#";
    case hex_prefix_t::none:
        return "";
    default:
        assert(false && "Invalid hex prefix");
        return "";
    }
}

/**
 * @brief Checks if the given specs map is valid for given set of allowed characters and length.
 *
 * @returns a bool.
 *
 * @param specs A std::map that maps the count range of specific characters required
 * @param allowed_chars A std::string consisting of all chars available for that string
 * generating function
 * @param length The number of characters to generate.
 *
 * @code
 * std::vector<Spec> specs = {{'0', {5, 10}}, {'1', {6, 10}}};
 * faker::is_valid_guarantee(specs, "01", 10) // false
 * @endcode
 */
bool is_valid_guarantee(
    const std::vector<Spec>& specs, std::string_view allowed_chars, unsigned length)
{
    unsigned min_count = 0;
    unsigned max_count = 0;
    for (auto& it : specs) {
        if (allowed_chars.find(it.c) == std::string::npos) {
            return false;
        }
        if (it.min_count > it.max_count) {
            return false;
        }
        min_count += it.min_count;
        max_count += it.max_count;
    }
    // if min sums up greater than total length of string, it is an invalid guarantee
    // if all chars in allowed_chars are mapped in guarantee, we need to check for validity of
    // max if max sumps up less than total length of string, it in an invalid
    // guarantee
    return min_count <= length && (specs.size() != allowed_chars.size() || max_count >= length);
}

std::string generate(const std::vector<Spec>& specs)
{
    std::string result;
    for (auto& spec : specs) {
        result += std::string(spec.min_count, spec.c);
    }
    return result;
}

std::string generateStringWithGuarantee(
    const std::vector<Spec>& guarantee, std::string_view allowed_chars, unsigned length)
{
    assert(is_valid_guarantee(guarantee, allowed_chars, length) && "Invalid guarantee.");

    std::string result;
    std::unordered_map<char, unsigned> counts;

    for (auto& spec : guarantee) {
        unsigned count = random::integer(spec.min_count, spec.min_count);
        result += std::string(count, spec.c);
        counts[spec.c] += spec.max_count - count;
    }

    while (true) {
        if (result.size() >= length) {
            break;
        }
        char ch = random::element(allowed_chars);
        auto it = counts.find(ch);
        if (it != counts.end()) {
            if (it->second > 0) {
                result += ch;
                --it->second;
            }
        } else {
            result += ch;
        }
    }

    return random::shuffle_string(result);
}

template <typename T> class RandomGenerator {
public:
    RandomGenerator()
        : generator_ { T(std::random_device {}()) }
    {
    }

    ~RandomGenerator() = default;

    RandomGenerator(const RandomGenerator&) = default;
    RandomGenerator(RandomGenerator&&) = default;
    RandomGenerator& operator=(const RandomGenerator&) = default;
    RandomGenerator& operator=(RandomGenerator&&) = default;

    int operator()(std::uniform_int_distribution<>& dist) { return dist(generator_); }

private:
    T generator_;
};

template <typename T = std::mt19937>
std::string uuid(RandomGenerator<T> gen = RandomGenerator<std::mt19937> {})
{
    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);
    static std::string_view hexCharacters { "0123456789abcdef" };

    std::string result;
    result.reserve(36);

    for (int i = 0; i < 8; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    }
    result.append(1, '-');

    for (int i = 0; i < 4; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    }
    result.append(1, '-');

    result.append(1, '4');
    for (int i = 0; i < 3; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    }
    result.append(1, '-');

    result.append(1, hexCharacters[gen(dist2)]);
    for (int i = 0; i < 3; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    }
    result.append(1, '-');

    for (int i = 0; i < 12; i++) {
        result.append(1, hexCharacters[gen(dist)]);
    };

    return result;
}

std::string uuid()
{
    static RandomGenerator<std::mt19937> gen;

    return uuid(gen);
}

std::string sample(unsigned length)
{
    std::string sample;

    for (unsigned i = 0; i < length; i++) {
        sample += static_cast<char>(number::integer(33, 125));
    }

    return sample;
}

std::string sample(const std::vector<Spec>& guarantee, unsigned length)
{
    if (!is_valid_guarantee(guarantee, data::all_allowed_chars, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    return generateStringWithGuarantee(guarantee, data::all_allowed_chars, length);
}

std::string from_chars(const std::string& characters, unsigned length)
{
    std::string result;

    for (unsigned i = 0; i < length; i++) {
        result += random::element(characters);
    }

    return result;
}

std::string from_chars(
    const std::vector<Spec>& guarantee, const std::string& allowed_chars, unsigned length)
{
    if (!is_valid_guarantee(guarantee, allowed_chars, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    return generateStringWithGuarantee(guarantee, allowed_chars, length);
}

std::string_view chars_for_casing(string_case casing)
{
    switch (casing) {
    case string_case::lower:
        return data::ascii_lower_letters;
    case string_case::upper:
        return data::ascii_upper_letters;
    case string_case::mixed:
        return data::ascii_letters;
    default:
        assert(false && "Invalid string case");
        return std::string_view();
    }
}

std::string alpha(unsigned length, string_case casing, const std::string& excluded_chars)
{
    auto allowed_chars = chars_for_casing(casing);

    std::string final_allowed_chars;
    for (auto ch : allowed_chars) {
        if (excluded_chars.find(ch) == std::string::npos) {
            final_allowed_chars += ch;
        }
    }

    std::string result;
    for (unsigned i = 0; i < length; i++) {
        result += random::element(final_allowed_chars);
    }
    return result;
}

std::string alpha(const std::vector<Spec>& guarantee, unsigned length, string_case casing)
{
    auto allowed_chars = chars_for_casing(casing);

    if (!is_valid_guarantee(guarantee, allowed_chars, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    return generateStringWithGuarantee(guarantee, allowed_chars, length);
}

std::string alphanumeric(unsigned length, string_case casing, const std::string& excluded_chars)
{
    std::string allowed_chars;

    switch (casing) {
    case string_case::lower:
        allowed_chars = data::ascii_lower_alphanum;
        break;
    case string_case::upper:
        allowed_chars = data::ascii_upper_alphanum;
        break;
    case string_case::mixed:
        allowed_chars = data::ascii_alphanum;
        break;
    }

    std::string final_allowed_chars;

    for (auto ch : allowed_chars) {
        if (excluded_chars.find(ch) == std::string::npos) {
            final_allowed_chars += ch;
        }
    }

    std::string result;
    result.reserve(length);

    for (unsigned i = 0; i < length; i++) {
        result += random::element(final_allowed_chars);
    }

    return result;
}

std::string alphanumeric(const std::vector<Spec>& guarantee, unsigned length, string_case casing)
{
    std::string allowed_chars { data::digits };
    allowed_chars += chars_for_casing(casing);

    if (!is_valid_guarantee(guarantee, allowed_chars, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    return generateStringWithGuarantee(guarantee, allowed_chars, length);
}

std::string numeric(unsigned length, bool allow_leading_zeroes)
{
    std::string alphanumeric;

    for (unsigned i = 0; i < length; i++) {
        if (i == 0 && allow_leading_zeroes) {
            alphanumeric += random::element(data::digits);
        } else {
            alphanumeric += random::element(data::non_zero_digits);
        }
    }

    return alphanumeric;
}

std::string numeric(
    const std::vector<Spec>& guarantee, const unsigned length, bool allow_leading_zeroes)
{
    // if leading zero not allowed, min of '0' cannot be equal to length
    if (!allow_leading_zeroes) {
        auto it = std::find_if(
            guarantee.begin(), guarantee.end(), [](auto& spec) { return spec.c == '0'; });
        if (it != guarantee.end() && it->min_count > length - 1) {
            throw std::invalid_argument { "Invalid guarantee." };
        }
    }

    if (!is_valid_guarantee(guarantee, data::digits, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    if (allow_leading_zeroes)
        return generateStringWithGuarantee(guarantee, data::digits, length);
    // if leading zero not allowed, pick first digit a non zero
    else {
        auto firstChar = std::to_string(number::integer(1, 9));

        std::vector<Spec> restSpecs;
        restSpecs.reserve(guarantee.size());
        std::transform(guarantee.begin(), guarantee.end(), std::back_inserter(restSpecs),
            [&firstChar](auto spec) {
                unsigned max_count = spec.max_count;
                if (firstChar[0] == spec.c) {
                    --max_count;
                }
                return Spec { spec.c, spec.min_count, max_count };
            });

        return firstChar + generateStringWithGuarantee(restSpecs, data::digits, length - 1);
    }
}

std::string hexadecimal(unsigned length, hex_case_t casing, hex_prefix_t prefix)
{
    auto hexadecimalPrefix = to_string(prefix);

    std::string hexadecimal;
    hexadecimal.reserve(length + hexadecimalPrefix.size());
    hexadecimal += hexadecimalPrefix;

    switch (casing) {
    case hex_case_t::lower:
        for (unsigned i = 0; i < length; i++) {
            hexadecimal += random::element(data::hex_lower_digits);
        }
        break;
    case hex_case_t::upper:
        for (unsigned i = 0; i < length; i++) {
            hexadecimal += random::element(data::hex_upper_digits);
        }
        break;
    default:
        assert(false && "Invalid hex casing");
    }

    return hexadecimal;
}

std::string hexadecimal(
    const std::vector<Spec>& guarantee, unsigned length, hex_case_t casing, hex_prefix_t prefix)
{
    std::string_view allowed_chars;

    switch (casing) {
    case hex_case_t::lower:
        allowed_chars = data::hex_lower_digits;
        break;
    case hex_case_t::upper:
        allowed_chars = data::hex_upper_digits;
        break;
    default:
        break;
    }

    if (!is_valid_guarantee(guarantee, allowed_chars, length)) {
        throw std::invalid_argument("Invalid guarantee.");
    }

    std::string result { to_string(prefix) };
    return result + generateStringWithGuarantee(guarantee, allowed_chars, length);
}

std::string binary(unsigned length)
{
    std::string binaryNumber;
    for (unsigned i = 0; i < length; ++i) {
        binaryNumber += static_cast<char>(number::integer(1));
    }
    return "0b" + binaryNumber;
}

std::string binary(const std::vector<Spec>& specs, unsigned length)
{
    const std::string_view allowed_chars { "01" };

    if (!is_valid_guarantee(specs, allowed_chars, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    return "0b" + generateStringWithGuarantee(specs, allowed_chars, length);
}

std::string octal(unsigned length)
{
    std::string octalNumber;
    for (unsigned i = 0; i < length; ++i) {
        octalNumber += static_cast<char>(number::integer(7));
    }
    return "0o" + octalNumber;
}

std::string octal(const std::vector<Spec>& guarantee, unsigned length)
{
    static const std::string_view allowed_chars { "01234567" };

    if (!is_valid_guarantee(guarantee, allowed_chars, length)) {
        throw std::invalid_argument { "Invalid guarantee." };
    }

    return "0o" + generateStringWithGuarantee(guarantee, allowed_chars, length);
}

}
