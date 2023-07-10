#pragma once

#include <string>
#include <vector>

namespace faker
{
enum class BicCountry
{
    Poland,
};

const std::vector<BicCountry> bicCountries = {BicCountry::Poland};
}
