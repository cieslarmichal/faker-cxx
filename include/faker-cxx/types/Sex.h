#pragma once

namespace faker
{
enum class Sex
{
    Male,
    Female,
};

inline std::string toString(Sex sex)
{
    std::map<Sex, std::string> sexToStringMapping{{Sex::Male, "Male"}, {Sex::Female, "Female"}};

    return sexToStringMapping.at(sex);
}

inline std::ostream& operator<<(std::ostream& os, Sex sex)
{
    return os << toString(sex);
}
}
