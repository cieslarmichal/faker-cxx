#include "Date.h"

#include <boost/date_time/posix_time/posix_time.hpp>

#include "gtest/gtest.h"

#include "data/MonthNames.h"
#include "data/WeekdayNames.h"

using namespace ::testing;
using namespace faker;

namespace
{
const auto secondsInYear = 31556926;
const auto secondsInDay = 86400;
const auto numberOfHoursInDay = 24;
const auto numberOfDaysInYear = 365;
}

class DateTest : public Test
{
public:
};

TEST_F(DateTest, shouldGeneratePastDate)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto pastYears = 5;

    const auto pastDate = Date::past(pastYears);

    EXPECT_TRUE((currentDate - pastDate).total_seconds() < secondsInYear * pastYears);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGeneratePastDateISO)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto pastDateISO = Date::pastISOString();

    const auto pastDate = boost::posix_time::from_iso_extended_string(pastDateISO);

    EXPECT_TRUE((currentDate - pastDate).total_seconds() < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDate)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto recentDays = 5;

    const auto recentDate = Date::recent(recentDays);

    EXPECT_TRUE((currentDate - recentDate).total_seconds() < secondsInDay * recentDays);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateISO)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto recentDays = 5;

    const auto recentDateISO = Date::recentISOString();

    const auto recentDate = boost::posix_time::from_iso_extended_string(recentDateISO);

    EXPECT_TRUE((currentDate - recentDate).total_seconds() < secondsInDay * recentDays);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDate)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto futureYears = 3;

    const auto futureDate = Date::future(futureYears);

    EXPECT_TRUE((futureDate - currentDate).total_seconds() < secondsInYear * futureYears);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateISO)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto futureDateISO = Date::futureISOString();

    const auto futureDate = boost::posix_time::from_iso_extended_string(futureDateISO);

    EXPECT_TRUE((futureDate - currentDate).total_seconds() < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDate)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto soonDays = 2;

    const auto soonDate = Date::soon(soonDays);

    EXPECT_TRUE((soonDate - currentDate).total_seconds() < secondsInDay * soonDays);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateISO)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto soonDays = 2;

    const auto soonDateISO = Date::soonISOString(soonDays);

    const auto soonDate = boost::posix_time::from_iso_extended_string(soonDateISO);

    EXPECT_TRUE((soonDate - currentDate).total_seconds() < secondsInDay * soonDays);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateDateFromRange)
{
    const auto startDate =
        boost::posix_time::second_clock::local_time() - boost::posix_time::hours(numberOfHoursInDay * 2);
    const auto endDate =
        boost::posix_time::second_clock::local_time() + boost::posix_time::hours(numberOfHoursInDay * 2);

    const auto dateWithinRage = Date::between(startDate, endDate);

    EXPECT_TRUE(dateWithinRage > startDate);
    EXPECT_TRUE(dateWithinRage < endDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAge)
{
    const auto birthdate = Date::birthdateByAge(25, 30);

    const auto expectedStartDate = boost::posix_time::second_clock::local_time() -
                                   boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * 30);

    const auto expectedEndDate = boost::posix_time::second_clock::local_time() -
                                 boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * 25);

    EXPECT_TRUE(birthdate > expectedStartDate);
    EXPECT_TRUE(birthdate < expectedEndDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAgeISO)
{
    const auto birthdateISO = Date::birthdateByAgeISOString(5, 15);

    const auto birthdate = boost::posix_time::from_iso_extended_string(birthdateISO);

    const auto expectedStartDate = boost::posix_time::second_clock::local_time() -
                                   boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * 15);

    const auto expectedEndDate = boost::posix_time::second_clock::local_time() -
                                 boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * 5);

    EXPECT_TRUE(birthdate > expectedStartDate);
    EXPECT_TRUE(birthdate < expectedEndDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByYear)
{
    const auto birthdate = Date::birthdateByYear(2000, 2023);

    EXPECT_TRUE(birthdate.date().year() >= 2000);
    EXPECT_TRUE(birthdate.date().year() <= 2023);
}

TEST_F(DateTest, shouldGenerateBirthDateByYearISO)
{
    const auto birthdateISO = Date::birthdateByYearISOString(1996, 1996);

    const auto birthdate = boost::posix_time::from_iso_extended_string(birthdateISO);

    EXPECT_TRUE(birthdate.date().year() == 1996);
}

TEST_F(DateTest, shouldGenerateWeekdayName)
{
    const auto generatedWeekdayName = Date::weekdayName();

    ASSERT_TRUE(std::any_of(weekdayNames.begin(), weekdayNames.end(),
                            [generatedWeekdayName](const std::string& weekdayName)
                            { return weekdayName == generatedWeekdayName; }));
}

TEST_F(DateTest, shouldGenerateWeekdayAbbreviatedName)
{
    const auto generatedWeekdayAbbreviatedName = Date::weekdayAbbreviatedName();

    ASSERT_TRUE(std::any_of(weekdayAbbreviatedNames.begin(), weekdayAbbreviatedNames.end(),
                            [generatedWeekdayAbbreviatedName](const std::string& weekdayAbbreviatedName)
                            { return weekdayAbbreviatedName == generatedWeekdayAbbreviatedName; }));
}

TEST_F(DateTest, shouldGenerateMonthName)
{
    const auto generatedMonthName = Date::monthName();

    ASSERT_TRUE(std::any_of(monthNames.begin(), monthNames.end(),
                            [generatedMonthName](const std::string& monthName)
                            { return monthName == generatedMonthName; }));
}

TEST_F(DateTest, shouldGenerateMonthAbbreviatedName)
{
    const auto generatedMonthAbbreviatedName = Date::monthAbbreviatedName();

    ASSERT_TRUE(std::any_of(monthAbbreviatedNames.begin(), monthAbbreviatedNames.end(),
                            [generatedMonthAbbreviatedName](const std::string& monthAbbreviatedName)
                            { return monthAbbreviatedName == generatedMonthAbbreviatedName; }));
}
