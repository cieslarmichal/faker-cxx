#include "faker-cxx/Date.h"

#include <algorithm>
#include <chrono>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "data/MonthNames.h"
#include "data/WeekdayNames.h"
#include "data/TimeZones.h"

#ifdef _WIN32
#define timegm _mkgmtime
#endif

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

TEST_F(DateTest, shouldGeneratePastDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto pastDateISO = Date::pastDate();

    const auto pastDate = parseISOFormattedStringToTimePoint(pastDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count() < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGeneratePastDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto pastDateTimestamp = Date::pastDate(1, Date::DateFormat::Timestamp);

    const auto pastDate = std::chrono::system_clock::from_time_t(std::stoi(pastDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count() < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto recentDays = 5;

    const auto recentDateISO = Date::recentDate(recentDays);

    const auto recentDate = parseISOFormattedStringToTimePoint(recentDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count() < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto recentDays = 5;

    const auto recentDateTimestamp = Date::recentDate(recentDays, Date::DateFormat::Timestamp);

    const auto recentDate = std::chrono::system_clock::from_time_t(std::stoi(recentDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count() < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto futureDateISO = Date::futureDate();

    const auto futureDate = parseISOFormattedStringToTimePoint(futureDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto futureDateTimestamp = Date::futureDate(1, Date::DateFormat::Timestamp);

    const auto futureDate = std::chrono::system_clock::from_time_t(std::stoi(futureDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto soonDays = 2;

    const auto soonDateISO = Date::soonDate(soonDays);

    const auto soonDate = parseISOFormattedStringToTimePoint(soonDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto soonDays = 2;

    const auto soonDateTimestamp = Date::soonDate(soonDays, Date::DateFormat::Timestamp);

    const auto soonDate = std::chrono::system_clock::from_time_t(std::stoi(soonDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAgeISO)
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

TEST_F(DateTest, shouldGenerateBirthDateByAgeTimestamp)
{
    const auto birthdateTimestamp = Date::birthdateByAge(5, 15, Date::DateFormat::Timestamp);

    const auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    const auto expectedStartDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * 15};

    const auto expectedEndDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * 5};

    EXPECT_TRUE(birthdate > expectedStartDate);
    EXPECT_TRUE(birthdate < expectedEndDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByExactYearISO)
{
    const auto birthdateISO = Date::birthdateByYear(1996, 1996);

    const auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_EQ(birthdate.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByExactYearTimestamp)
{
    const auto birthdateTimestamp = Date::birthdateByYear(1996, 1996, Date::DateFormat::Timestamp);

    const auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    // Convert std::chrono::system_clock::time_point to std::time_t
    std::time_t birthdateTimeT = std::chrono::system_clock::to_time_t(birthdate);

    // Convert std::time_t to std::tm
    std::tm birthdateStruct = *std::localtime(&birthdateTimeT);

    EXPECT_EQ(birthdateStruct.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYearISO)
{
    const auto birthdateISO = Date::birthdateByYear(1990, 2000);

    const auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_GE(birthdate.tm_year + 1900, 1990);
    EXPECT_LE(birthdate.tm_year + 1900, 2000);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYearTimestamp)
{
    const auto birthdateTimestamp = Date::birthdateByYear(1990, 2000, Date::DateFormat::Timestamp);

    const auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    // Convert std::chrono::system_clock::time_point to std::time_t
    std::time_t birthdateTimeT = std::chrono::system_clock::to_time_t(birthdate);

    // Convert std::time_t to std::tm
    std::tm birthdateStruct = *std::localtime(&birthdateTimeT);

    EXPECT_GE(birthdateStruct.tm_year + 1900, 1990);
    EXPECT_LE(birthdateStruct.tm_year + 1900, 2000);
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

TEST_F(DateTest, shouldGenerateRandomYear)
{
    const auto generatedYear = Date::year();

    ASSERT_LE(generatedYear, 2050u);
    ASSERT_GE(generatedYear, 1950u);
}

TEST_F(DateTest, shouldGenerateRandomMonth)
{
    const auto genereatedMonth = Date::month();

    ASSERT_LE(genereatedMonth, 12u);
    ASSERT_GE(genereatedMonth, 1u);
}

TEST_F(DateTest, shouldGenerateRandomHour)
{
    const auto generatedHour = Date::hour();

    ASSERT_LE(generatedHour, 23u);
    ASSERT_GE(generatedHour, 0u);
}

TEST_F(DateTest, shouldGenerateRandomMinute)
{
    const auto generatedMinute = Date::minute();

    ASSERT_LE(generatedMinute, 59u);
    ASSERT_GE(generatedMinute, 0u);
}

TEST_F(DateTest, shouldGenerateRandomSecond)
{
    const auto generatedSecond = Date::minute();

    ASSERT_LE(generatedSecond, 59u);
    ASSERT_GE(generatedSecond, 0u);
}

TEST_F(DateTest, shouldGenerateRandomDayOfMonth)
{
    const auto generatedDayOfMonth = Date::dayOfMonth();

    ASSERT_LE(generatedDayOfMonth, 31u);
    ASSERT_GE(generatedDayOfMonth, 1u);
}

TEST_F(DateTest, shouldGenerateRandomDayOfWeek)
{
    const auto generatedDayOfWeek = Date::dayOfWeek();

    ASSERT_LE(generatedDayOfWeek, 7u);
    ASSERT_GE(generatedDayOfWeek, 1u);
}

TEST_F(DateTest, shouldGenerateRandomTimezone)
{
    const auto generatedTimeZone = Date::timezone();

    ASSERT_TRUE(std::ranges::any_of(timezonesAbbreviatedNames,
                                    [generatedTimeZone](const std::string& timezoneName)
                                    { return timezoneName == generatedTimeZone; }));
}

TEST_F(DateTest, shouldGenerateRandomTime)
{
    const auto generatedTime = Date::time();
    const auto generatedTimeParts = StringHelper::split(generatedTime, ":");

    ASSERT_EQ(generatedTimeParts.size(), 2);

    const auto& hour = atoi(generatedTimeParts[0].c_str());
    const auto& minute = atoi(generatedTimeParts[1].c_str());

    ASSERT_LE(hour, 23);
    ASSERT_GE(hour, 0);

    ASSERT_LE(minute, 59);
    ASSERT_GE(minute, 0);
}
