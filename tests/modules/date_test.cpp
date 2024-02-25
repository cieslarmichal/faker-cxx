#include "../test_helpers.h"
#include <algorithm>
#include <chrono>
#include <faker/date.h>
#include <iomanip>
#include <modules/date_data.h>

#ifdef _WIN32
#define timegm _mkgmtime
#endif

using namespace ::testing;
using namespace faker;

namespace {
const auto secondsInYear = 31556926;
const auto numberOfHoursInDay = 24;
const auto numberOfDaysInYear = 365;
}

class DateTest : public Test {
public:
    static std::chrono::time_point<std::chrono::system_clock,
        std::chrono::duration<int64_t, std::ratio<1, 1000000000>>>
    parseISOFormattedStringToTimePoint(const std::string& isoString)
    {
        auto dateTime = parseISOFormattedStringToTm(isoString);

        return std::chrono::system_clock::from_time_t(timegm(&dateTime));
    }

    static tm parseISOFormattedStringToTm(const std::string& isoString)
    {
        tm tm {};

        std::istringstream iss(isoString);
        iss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%SZ");

        return tm;
    }
};

TEST_F(DateTest, shouldGeneratePastDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto pastDateISO = date::pastDate();

    const auto pastDate = parseISOFormattedStringToTimePoint(pastDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count()
        < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGeneratePastDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto pastDateTimestamp = date::pastDate(1, date::DateFormat::Timestamp);

    const auto pastDate = std::chrono::system_clock::from_time_t(std::stoi(pastDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count()
        < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto recentDays = 5;

    const auto recentDateISO = date::recentDate(recentDays);

    const auto recentDate = parseISOFormattedStringToTimePoint(recentDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count()
        < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto recentDays = 5;

    const auto recentDateTimestamp = date::recentDate(recentDays, date::DateFormat::Timestamp);

    const auto recentDate = std::chrono::system_clock::from_time_t(std::stoi(recentDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count()
        < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto futureDateISO = date::futureDate();

    const auto futureDate = parseISOFormattedStringToTimePoint(futureDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count()
        < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto futureDateTimestamp = date::futureDate(1, date::DateFormat::Timestamp);

    const auto futureDate = std::chrono::system_clock::from_time_t(std::stoi(futureDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count()
        < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateISO)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto soonDays = 2;

    const auto soonDateISO = date::soonDate(soonDays);

    const auto soonDate = parseISOFormattedStringToTimePoint(soonDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count()
        < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateTimestamp)
{
    const auto currentDate = std::chrono::system_clock::now();

    const auto soonDays = 2;

    const auto soonDateTimestamp = date::soonDate(soonDays, date::DateFormat::Timestamp);

    const auto soonDate = std::chrono::system_clock::from_time_t(std::stoi(soonDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count()
        < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAgeISO)
{
    const auto birthdateISO = date::birthdateByAge(5, 15);

    const auto birthdate = parseISOFormattedStringToTimePoint(birthdateISO);

    const auto expectedStartDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * 15 };

    const auto expectedEndDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * 5 };

    EXPECT_TRUE(birthdate > expectedStartDate);
    EXPECT_TRUE(birthdate < expectedEndDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAgeTimestamp)
{
    const auto birthdateTimestamp = date::birthdateByAge(5, 15, date::DateFormat::Timestamp);

    const auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    const auto expectedStartDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * 15 };

    const auto expectedEndDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * 5 };

    EXPECT_TRUE(birthdate > expectedStartDate);
    EXPECT_TRUE(birthdate < expectedEndDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByExactYearISO)
{
    const auto birthdateISO = date::birthdateByYear(1996, 1996);

    const auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_EQ(birthdate.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByExactYearTimestamp)
{
    const auto birthdateTimestamp = date::birthdateByYear(1996, 1996, date::DateFormat::Timestamp);

    const auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    // Convert std::chrono::system_clock::time_point to std::time_t
    std::time_t birthdateTimeT = std::chrono::system_clock::to_time_t(birthdate);

    // Convert std::time_t to std::tm
    std::tm birthdateStruct = *std::localtime(&birthdateTimeT);

    EXPECT_EQ(birthdateStruct.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYearISO)
{
    const auto birthdateISO = date::birthdateByYear(1990, 2000);

    const auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_GE(birthdate.tm_year + 1900, 1990);
    EXPECT_LE(birthdate.tm_year + 1900, 2000);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYearTimestamp)
{
    const auto birthdateTimestamp = date::birthdateByYear(1990, 2000, date::DateFormat::Timestamp);

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
    const auto generatedWeekdayName = date::weekdayName();

    FAKER_EXPECT_CONTAINS(weekdayNames, generatedWeekdayName);
}

TEST_F(DateTest, shouldGenerateWeekdayAbbreviatedName)
{
    const auto generatedWeekdayAbbreviatedName = date::weekdayAbbreviatedName();

    FAKER_EXPECT_CONTAINS(weekdayAbbreviatedNames, generatedWeekdayAbbreviatedName);
}

TEST_F(DateTest, shouldGenerateMonthName)
{
    const auto generatedMonthName = date::monthName();

    FAKER_EXPECT_CONTAINS(monthNames, generatedMonthName);
}

TEST_F(DateTest, shouldGenerateMonthAbbreviatedName)
{
    const auto generatedMonthAbbreviatedName = date::monthAbbreviatedName();

    FAKER_EXPECT_CONTAINS(monthAbbreviatedNames, generatedMonthAbbreviatedName);
}
