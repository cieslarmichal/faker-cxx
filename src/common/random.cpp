#include "random.h"
#include "luhn_check.h"
#include "strings.h"
#include <cassert>
#include <regex>

namespace faker::random {
std::random_device randomDevice;
std::mt19937_64 random_engine(randomDevice());

bool boolean(double prob)
{
    assert(!std::isnan(prob) && "Probability must be a number.");

    if (prob <= 0.f) {
        return false;
    }
    if (prob >= 1.f) {
        return true;
    }
    return decimal(0.f, 1.f) < prob;
}

int integer(int min, int max)
{
    assert(min <= max && "Minimum value must be smaller than maximum value.");

    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(random_engine);
}

unsigned integer(unsigned min, unsigned max)
{
    assert(min <= max && "Minimum value must be smaller than maximum value.");

    std::uniform_int_distribution<unsigned> distribution(min, max);
    return distribution(random_engine);
}

long integer(long min, long max)
{
    assert(min <= max && "Minimum value must be smaller than maximum value.");

    std::uniform_int_distribution<long> distribution(min, max);
    return distribution(random_engine);
}

unsigned long integer(unsigned long min, unsigned long max)
{
    assert(min <= max && "Minimum value must be smaller than maximum value.");

    std::uniform_int_distribution<unsigned long> distribution(min, max);
    return distribution(random_engine);
}

long long integer(long long min, long long max)
{
    assert(min <= max && "Minimum value must be smaller than maximum value.");

    std::uniform_int_distribution<long long> distribution(min, max);
    return distribution(random_engine);
}

unsigned long long integer(unsigned long long min, unsigned long long max)
{
    assert(min <= max && "Minimum value must be smaller than maximum value.");

    std::uniform_int_distribution<unsigned long long> distribution(min, max);
    return distribution(random_engine);
}

float decimal(float min, float max)
{
    assert(min <= max && "Minimum value must be smaller than maximum value.");

    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(random_engine);
}

double decimal(double min, double max)
{
    assert(min <= max && "Minimum value must be smaller than maximum value.");

    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(random_engine);
}

size_t container_index(size_t size)
{
    if (size == 0) {
        throw std::invalid_argument("Data is empty.");
    }

    std::uniform_int_distribution<size_t> distribution(0, size - 1);

    return distribution(random_engine);
}

size_t weighted_container_index(const std::vector<unsigned>& weights)
{
    if (weights.empty()) {
        throw std::invalid_argument("Weights are empty.");
    }

    std::discrete_distribution<size_t> distribution(weights.begin(), weights.end());

    return distribution(random_engine);
}

std::string shuffle_string(std::string data)
{
    std::shuffle(data.begin(), data.end(), random_engine);

    return data;
}

std::string replace_symbol_with_number(const std::string& str, const char& symbol)
{
    std::string result;

    for (const auto& ch : str) {
        if (ch == symbol) {
            result += std::to_string(integer(0, 9));
        } else if (ch == '!') {
            result += std::to_string(integer(2, 9));
        } else {
            result += ch;
        }
    }

    return result;
}

std::string replace_symbol_with_number(const std::string_view& str, const char& symbol)
{
    std::string result;

    for (const auto& ch : str) {
        if (ch == symbol) {
            result += std::to_string(integer(0, 9));
        } else if (ch == '!') {
            result += std::to_string(integer(2, 9));
        } else {
            result += ch;
        }
    }

    return result;
}

std::string replace_credit_card_symbols(std::string_view inputString, char symbol)
{
    // Replace regex-like expressions in the given string with matching values.
    std::string modifiedString = regexp_style_string_parse(inputString);

    // Replace ### with random numbers (where ### is the symbol)
    modifiedString = replace_symbol_with_number(modifiedString, symbol);

    // Calculate the luhnCheckValue and replace 'L' with the checkNum
    int checkNum = utils::luhn_check_value(modifiedString);

    size_t pos = modifiedString.find('L');

    if (pos != std::string::npos) {
        modifiedString.replace(pos, 1, std::to_string(checkNum));
    }

    return modifiedString;
}

std::string regexp_style_string_parse(const std::string& input)
{
    std::string string = input;
    // Deal with range repeat `{min,max}`
    const std::regex RANGE_REP_REG(R"((.)\{(\d+),(\d+)\})");
    const std::regex REP_REG(R"((.)\{(\d+)\})");
    const std::regex RANGE_REG(R"(\[(\d+)-(\d+)\])");
    std::smatch token;

    while (std::regex_search(string, token, RANGE_REP_REG)) {
        int min = std::stoi(token[2]);
        int max = std::stoi(token[3]);
        // switch min and max
        if (min > max) {
            std::swap(min, max);
        }

        int repetitions = integer(min, max);
        string = string.substr(0, static_cast<unsigned long>(token.position()))
            + utils::repeat(token[1], repetitions)
            + string.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    // Deal with repeat `{num}`
    while (std::regex_search(string, token, REP_REG)) {
        int repetitions = std::stoi(token[2]);
        string = string.substr(0, static_cast<unsigned long>(token.position()))
            + utils::repeat(token[1], repetitions)
            + string.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    // Deal with range `[min-max]` (only works with numbers for now)
    // TODO: implement for letters e.g. [0-9a-zA-Z] etc.
    while (std::regex_search(string, token, RANGE_REG)) {
        int min = std::stoi(token[1]); // This time we are not capturing the char before `[]`
        int max = std::stoi(token[2]);
        // switch min and max
        if (min > max) {
            std::swap(min, max);
        }

        string = string.substr(0, static_cast<unsigned long>(token.position()))
            + std::to_string(integer(min, max))
            + string.substr(static_cast<unsigned long>(token.position() + token.length()));
    }

    return string;
}
}
