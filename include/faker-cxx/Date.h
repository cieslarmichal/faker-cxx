#pragma once

#include <string>

namespace faker
{
class Date
{
public:
    static std::string future(int years = 1);
    static std::string past(int years = 1);
    static std::string soon(int days = 3);
    static std::string recent(int days = 3);
    static std::string weekDayName();
    static std::string monthName();
    static std::string birthDateByAge(int minAge = 18, int maxAge = 80);
    static std::string birthDateByYear(int minYear = 1920, int maxYear = 2000);
};
}
