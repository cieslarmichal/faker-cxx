#include "Date.h"

#include "gtest/gtest.h"

#include "data/MonthNames.h"
#include "data/WeekdayNames.h"
#include "StringHelper.h"

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

        return std::chrono::system_clock::from_time_t(mktime(&dateTime));
    }

    static tm parseISOFormattedStringToTm(const std::string& isoString)
    {
        const auto isoStringDateTime = StringHelper::split(isoString, "T");

        const auto& date = isoStringDateTime[0];
        const auto dateElements = StringHelper::split(date, "-");
        const auto& year = std::stoi(dateElements[0]);
        const auto& month = std::stoi(dateElements[1]);
        const auto& day = std::stoi(dateElements[2]);

        const auto& time = isoStringDateTime[1];
        const auto timeElements = StringHelper::split(time, ":");
        const auto& hour = std::stoi(timeElements[0]);
        const auto& minutes = std::stoi(timeElements[1]);
        const auto& seconds = std::stoi(timeElements[2]);

        tm dateTime{};

        dateTime.tm_year = year - 1900;
        dateTime.tm_mon = month - 1;
        dateTime.tm_mday = day;
        dateTime.tm_hour = hour;
        dateTime.tm_min = minutes;
        dateTime.tm_sec = seconds;
        dateTime.tm_isdst = -1;

        return dateTime;
    }
};

TEST_F(DateTest, shouldGeneratePastDate)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto pastDateISO = Date::pastDate();

    std::cerr << pastDateISO;

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
