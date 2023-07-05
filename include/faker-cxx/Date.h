#pragma once

#include <boost/date_time/posix_time/ptime.hpp>
#include <string>

namespace faker
{
class Date
{
public:
    static boost::posix_time::ptime future(int years = 1);
    static boost::posix_time::ptime past(int years = 1);
    static boost::posix_time::ptime soon(int days = 3);
    static boost::posix_time::ptime recent(int days = 3);
    static boost::posix_time::ptime birthDateByAge(int minAge = 18, int maxAge = 80);
    static boost::posix_time::ptime birthDateByYear(int minYear = 1920, int maxYear = 2000);
    static boost::posix_time::ptime fromRange(boost::posix_time::ptime startDate, boost::posix_time::ptime endDate);
    static std::string futureISOString(int years = 1);
    static std::string pastISOString(int years = 1);
    static std::string soonISOString(int days = 3);
    static std::string recentISOString(int days = 3);
    static std::string birthDateByAgeISOString(int minAge = 18, int maxAge = 80);
    static std::string birthDateByYearISOString(int minYear = 1920, int maxYear = 2000);
    static std::string weekdayName();
    static std::string weekdayAbbreviatedName();
    static std::string monthName();
    static std::string monthAbbreviatedName();
};
}
