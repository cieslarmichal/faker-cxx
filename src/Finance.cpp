#include "Finance.h"

#include <format>
#include <sstream>

#include "data/AccountTypes.h"
#include "data/Currencies.h"
#include "Helper.h"
#include "Number.h"

namespace faker
{
std::string Finance::currencyCode()
{
    return Helper::arrayElement<std::string>(currenciesCodes);
}

std::string Finance::accountType()
{
    return Helper::arrayElement<std::string>(accountTypes);
}

std::string Finance::amount(unsigned int min, unsigned int max, unsigned int decimalPlaces, const std::string& symbol)
{
    const std::floating_point auto generatedNumber =
        Number::decimal<float>(static_cast<float>(min), static_cast<float>(max));

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(decimalPlaces);

    ss << generatedNumber;

    return std::format("{}{}", symbol, ss.str());
}
}
