#include "Company.h"

#include <format>

#include "data/LastNames.h"
#include "Helper.h"
#include "Person.h"

namespace faker
{
namespace
{
const std::vector<std::string> companySuffixes{"Inc", "LLC", "Group"};
}

std::string Company::name()
{
    std::string companyName;

    switch (Number::integer<int>(3))
    {
    case 0:
        companyName = std::format("{} {}", Person::lastName(), Helper::arrayElement<std::string>(companySuffixes));
        break;
    case 1:
        companyName = std::format("{} {} {}", Person::firstName(), Person::lastName(), Person::jobArea());
        break;
    case 2:
        companyName = std::format("{} {} {} Services", Person::firstName(), Person::lastName(), Person::jobArea());
        break;
    case 3:
        companyName = std::format("{} {} {} {}", Person::firstName(), Person::lastName(), Person::jobArea(),
                                  Helper::arrayElement<std::string>(companySuffixes));
        break;
    }

    return companyName;
}
}
