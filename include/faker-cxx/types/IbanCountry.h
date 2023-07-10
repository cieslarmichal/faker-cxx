#pragma once

#include <map>
#include <ostream>
#include <string>
#include <vector>

namespace faker
{
enum class IbanCountry
{
    Poland,
    France,
    Germany,
    Italy
};

const std::vector<IbanCountry> ibanCountries = {IbanCountry::Poland, IbanCountry::France, IbanCountry::Germany,
                                                IbanCountry::Italy};

inline std::string toString(IbanCountry ibanCountry)
{
    const std::map<IbanCountry, std::string> ibanCountryToStringMapping{{IbanCountry::Poland, "Poland"},
                                                                        {IbanCountry::France, "France"},
                                                                        {IbanCountry::Germany, "Germany"},
                                                                        {IbanCountry::Italy, "Italy"}};

    return ibanCountryToStringMapping.at(ibanCountry);
}

inline std::ostream& operator<<(std::ostream& os, IbanCountry ibanCountry)
{
    return os << toString(ibanCountry);
}

}
