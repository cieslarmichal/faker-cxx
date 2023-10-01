#include "faker-cxx/Date.h"

#include <algorithm>
#include <chrono>

#include "gtest/gtest.h"

#include "data/MonthNames.h"
#include "data/WeekdayNames.h"

using namespace ::testing;
using namespace faker;

namespace
{
const auto secondsInYear = 31556926;
const auto numberOfHoursInDay = 24;
const auto numberOfDaysInYear = 365;
}

class DateTest : public Test
{
public:
    static std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<int64_t, std::ratio<1, 1000000000>>>
    parseISOFormattedStringToTimePoint(const std::string& isoString)
    {
        auto dateTime = parseISOFormattedStringToTm(isoString);

        return std::chrono::system_clock::from_time_t(timegm(&dateTime));
    }

    static tm parseISOFormattedStringToTm(const std::string& isoString)
    {
        tm tm{};

        std::istringstream iss(isoString);
        iss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%SZ");

        return tm;
    }
};

TEST_F(DateTest, shouldGeneratePastDate)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto pastDateISO = Date::pastDate();

    const auto pastDate = parseISOFormattedStringToTimePoint(pastDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count() < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDate)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto recentDays = 5;

    const auto recentDateISO = Date::recentDate(recentDays);

    const auto recentDate = parseISOFormattedStringToTimePoint(recentDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count() < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDate)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto futureDateISO = Date::futureDate();

    const auto futureDate = parseISOFormattedStringToTimePoint(futureDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDate)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto soonDays = 2;

    const auto soonDateISO = Date::soonDate(soonDays);

    const auto soonDate = parseISOFormattedStringToTimePoint(soonDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAge)
{
    const auto birthdateISO = Date::birthdateByAge(5, 15);

    const auto birthdate = parseISOFormattedStringToTimePoint(birthdateISO);

    const auto expectedStartDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * 15};

    const auto expectedEndDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * 5};

    EXPECT_TRUE(birthdate > expectedStartDate);
    EXPECT_TRUE(birthdate < expectedEndDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByExactYear)
{
    const auto birthdateISO = Date::birthdateByYear(1996, 1996);

    const auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_EQ(birthdate.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYear)
{
    const auto birthdateISO = Date::birthdateByYear(1990, 2000);

    const auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_GE(birthdate.tm_year + 1900, 1990);
    EXPECT_LE(birthdate.tm_year + 1900, 2000);
}

TEST_F(DateTest, shouldGenerateWeekdayName)
{
    const auto generatedWeekdayName = Date::weekdayName();

    ASSERT_TRUE(std::ranges::any_of(weekdayNames, [generatedWeekdayName](const std::string& weekdayName)
                                    { return weekdayName == generatedWeekdayName; }));
}

TEST_F(DateTest, shouldGenerateWeekdayAbbreviatedName)
{
    const auto generatedWeekdayAbbreviatedName = Date::weekdayAbbreviatedName();

    ASSERT_TRUE(std::ranges::any_of(weekdayAbbreviatedNames,
                                    [generatedWeekdayAbbreviatedName](const std::string& weekdayAbbreviatedName)
                                    { return weekdayAbbreviatedName == generatedWeekdayAbbreviatedName; }));
}

TEST_F(DateTest, shouldGenerateMonthName)
{
    const auto generatedMonthName = Date::monthName();

    ASSERT_TRUE(std::ranges::any_of(monthNames, [generatedMonthName](const std::string& monthName)
                                    { return monthName == generatedMonthName; }));
}

TEST_F(DateTest, shouldGenerateMonthAbbreviatedName)
{
    const auto generatedMonthAbbreviatedName = Date::monthAbbreviatedName();

    ASSERT_TRUE(std::ranges::any_of(monthAbbreviatedNames,
                                    [generatedMonthAbbreviatedName](const std::string& monthAbbreviatedName)
                                    { return monthAbbreviatedName == generatedMonthAbbreviatedName; }));
}
