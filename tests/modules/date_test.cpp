#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <ratio>
#include <sstream>
#include <string>
#include <string_view>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "date_data.h"
#include "faker-cxx/date.h"

#ifdef _WIN32
#define timegm _mkgmtime
#endif

using namespace ::testing;
using namespace faker;
using namespace faker::date;

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

    const auto pastDateISO = pastDate();

    const auto pastDate = parseISOFormattedStringToTimePoint(pastDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count() < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGeneratePastDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto pastDateTimestamp = pastDate(1, DateFormat::Timestamp);

    const auto pastDate = std::chrono::system_clock::from_time_t(std::stoi(pastDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count() < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto recentDays = 5;

    const auto recentDateISO = recentDate(recentDays);

    const auto recentDate = parseISOFormattedStringToTimePoint(recentDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count() < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto recentDays = 5;

    const auto recentDateTimestamp = recentDate(recentDays, DateFormat::Timestamp);

    const auto recentDate = std::chrono::system_clock::from_time_t(std::stoi(recentDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count() < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto futureDateISO = futureDate();

    const auto futureDate = parseISOFormattedStringToTimePoint(futureDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto futureDateTimestamp = futureDate(1, DateFormat::Timestamp);

    const auto futureDate = std::chrono::system_clock::from_time_t(std::stoi(futureDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}
TEST_F(DateTest, shouldGenerateAnytimeISO)
{
    const auto currentDate = std::chrono::system_clock::now();
    const auto unixEpoch = std::chrono::system_clock::time_point{};

    for (int i = 0; i < 100; ++i)
    {
        const auto anytimeISO = anytime(DateFormat::ISO);
        const auto generatedDate = parseISOFormattedStringToTimePoint(anytimeISO);
        EXPECT_GT(generatedDate, unixEpoch) << "Generated date is before Unix epoch: " << anytimeISO;

        auto duration = generatedDate - currentDate;
        double durationInYears = std::chrono::duration_cast<std::chrono::seconds>(duration).count() / (365.25 * 24 * 3600);
        durationInYears = std::abs(durationInYears);
        EXPECT_LT(durationInYears, 201) << "Generated date is more than 201 years in the future: " << anytimeISO;
    }
}

TEST_F(DateTest, shouldGenerateAnytimeTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();
    const auto unixEpoch = std::chrono::system_clock::time_point{};

    for (int i = 0; i < 100; ++i)
    {
        const auto anytimeTimestamp = anytime(DateFormat::Timestamp);
        int64_t timestampSeconds = std::stoll(anytimeTimestamp);
        auto generatedDate = std::chrono::system_clock::time_point{std::chrono::seconds{timestampSeconds}};
        EXPECT_GT(generatedDate, unixEpoch) << "Generated date is before Unix epoch: " << anytimeTimestamp;

        auto duration = generatedDate - currentDate;
        double durationInYears = std::chrono::duration_cast<std::chrono::seconds>(duration).count() / (365.25 * 24 * 3600);
        durationInYears = std::abs(durationInYears);
        EXPECT_LT(durationInYears, 201) << "Generated date is more than 201 years in the future: " << anytimeTimestamp;
    }
}

TEST_F(DateTest, shouldGenerateSoonDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto soonDays = 2;

    const auto soonDateISO = soonDate(soonDays);

    const auto soonDate = parseISOFormattedStringToTimePoint(soonDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto soonDays = 2;

    const auto soonDateTimestamp = soonDate(soonDays, DateFormat::Timestamp);

    const auto soonDate = std::chrono::system_clock::from_time_t(std::stoi(soonDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count() < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAgeISO)
{
    const auto birthdateISO = birthdateByAge(5, 15);

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
    const auto birthdateTimestamp = birthdateByAge(5, 15, DateFormat::Timestamp);

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
    const auto birthdateISO = birthdateByYear(1996, 1996);

    const auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_EQ(birthdate.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByExactYearTimestamp)
{
    const auto birthdateTimestamp = birthdateByYear(1996, 1996, DateFormat::Timestamp);

    const auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    std::time_t birthdateTimeT = std::chrono::system_clock::to_time_t(birthdate);

    std::tm birthdateStruct = *std::localtime(&birthdateTimeT);

    EXPECT_EQ(birthdateStruct.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYearISO)
{
    const auto birthdateISO = birthdateByYear(1990, 2000);

    const auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_GE(birthdate.tm_year + 1900, 1990);
    EXPECT_LE(birthdate.tm_year + 1900, 2000);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYearTimestamp)
{
    const auto birthdateTimestamp = birthdateByYear(1990, 2000, DateFormat::Timestamp);

    const auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    std::time_t birthdateTimeT = std::chrono::system_clock::to_time_t(birthdate);

    std::tm birthdateStruct = *std::localtime(&birthdateTimeT);

    EXPECT_GE(birthdateStruct.tm_year + 1900, 1990);
    EXPECT_LE(birthdateStruct.tm_year + 1900, 2000);
}

TEST_F(DateTest, shouldGenerateWeekdayName)
{
    const auto generatedWeekdayName = weekdayName();

    ASSERT_TRUE(std::ranges::any_of(weekdayNames, [generatedWeekdayName](const std::string_view& weekdayName)
                                    { return weekdayName == generatedWeekdayName; }));
}

TEST_F(DateTest, shouldGenerateWeekdayAbbreviatedName)
{
    const auto generatedWeekdayAbbreviatedName = weekdayAbbreviatedName();

    ASSERT_TRUE(std::ranges::any_of(weekdayAbbreviatedNames,
                                    [generatedWeekdayAbbreviatedName](const std::string_view& weekdayAbbreviatedName)
                                    { return weekdayAbbreviatedName == generatedWeekdayAbbreviatedName; }));
}

TEST_F(DateTest, shouldGenerateMonthName)
{
    const auto generatedMonthName = monthName();

    ASSERT_TRUE(std::ranges::any_of(monthNames, [generatedMonthName](const std::string_view& monthName)
                                    { return monthName == generatedMonthName; }));
}

TEST_F(DateTest, shouldGenerateMonthAbbreviatedName)
{
    const auto generatedMonthAbbreviatedName = monthAbbreviatedName();

    ASSERT_TRUE(std::ranges::any_of(monthAbbreviatedNames,
                                    [generatedMonthAbbreviatedName](const std::string_view& monthAbbreviatedName)
                                    { return monthAbbreviatedName == generatedMonthAbbreviatedName; }));
}

TEST_F(DateTest, shouldGenerateRandomYear)
{
    const auto generatedYear = year();

    ASSERT_LE(generatedYear, 2050u);
    ASSERT_GE(generatedYear, 1950u);
}

TEST_F(DateTest, shouldGenerateRandomMonth)
{
    const auto genereatedMonth = month();

    ASSERT_LE(genereatedMonth, 12u);
    ASSERT_GE(genereatedMonth, 1u);
}

TEST_F(DateTest, shouldGenerateRandomHour)
{
    const auto generatedHour = hour();

    ASSERT_LE(generatedHour, 23u);
    ASSERT_GE(generatedHour, 0u);
}

TEST_F(DateTest, shouldGenerateRandomMinute)
{
    const auto generatedMinute = minute();

    ASSERT_LE(generatedMinute, 59u);
    ASSERT_GE(generatedMinute, 0u);
}

TEST_F(DateTest, shouldGenerateRandomSecond)
{
    const auto generatedSecond = second();

    ASSERT_LE(generatedSecond, 59u);
    ASSERT_GE(generatedSecond, 0u);
}

TEST_F(DateTest, shouldGenerateRandomDayOfMonth)
{
    const auto generatedDayOfMonth = dayOfMonth();

    ASSERT_LE(generatedDayOfMonth, 31u);
    ASSERT_GE(generatedDayOfMonth, 1u);
}

TEST_F(DateTest, shouldGenerateRandomDayOfWeek)
{
    const auto generatedDayOfWeek = dayOfWeek();

    ASSERT_LE(generatedDayOfWeek, 7u);
    ASSERT_GE(generatedDayOfWeek, 1u);
}

TEST_F(DateTest, shouldGenerateRandomTimezone)
{
    const auto generatedTimeZone = timezoneRandom();

    ASSERT_TRUE(std::ranges::any_of(timezonesAbbreviatedNames, [generatedTimeZone](const std::string_view& timezoneName)
                                    { return timezoneName == generatedTimeZone; }));
}

TEST_F(DateTest, shouldGenerateRandomTime)
{
    const auto generatedTime = time();
    const auto generatedTimeParts = common::split(generatedTime, ":");

    ASSERT_EQ(generatedTimeParts.size(), 2);

    ASSERT_EQ(generatedTimeParts[0].length(), 2);
    ASSERT_EQ(generatedTimeParts[1].length(), 2);

    const auto& hour = atoi(generatedTimeParts[0].c_str());
    const auto& minute = atoi(generatedTimeParts[1].c_str());

    ASSERT_LE(hour, 23);
    ASSERT_GE(hour, 0);

    ASSERT_LE(minute, 59);
    ASSERT_GE(minute, 0);
}
