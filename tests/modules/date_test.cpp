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
    auto currentDate = std::chrono::system_clock::now();

    auto pastDateISO = date::pastDate();

    auto pastDate = parseISOFormattedStringToTimePoint(pastDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count()
        < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGeneratePastDateTimestamp)
{
    auto currentDate = std::chrono::system_clock::now();

    auto pastDateTimestamp = date::pastDate(1, date::DateFormat::Timestamp);

    auto pastDate = std::chrono::system_clock::from_time_t(std::stoi(pastDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - pastDate).count()
        < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateISO)
{
    auto currentDate = std::chrono::system_clock::now();

    auto recentDays = 5;

    auto recentDateISO = date::recentDate(recentDays);

    auto recentDate = parseISOFormattedStringToTimePoint(recentDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count()
        < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateTimestamp)
{
    auto currentDate = std::chrono::system_clock::now();

    auto recentDays = 5;

    auto recentDateTimestamp = date::recentDate(recentDays, date::DateFormat::Timestamp);

    auto recentDate = std::chrono::system_clock::from_time_t(std::stoi(recentDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(currentDate - recentDate).count()
        < secondsInYear);
    EXPECT_TRUE(recentDate < currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateISO)
{
    auto currentDate = std::chrono::system_clock::now();

    auto futureDateISO = date::futureDate();

    auto futureDate = parseISOFormattedStringToTimePoint(futureDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count()
        < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDateTimestamp)
{
    auto currentDate = std::chrono::system_clock::now();

    auto futureDateTimestamp = date::futureDate(1, date::DateFormat::Timestamp);

    auto futureDate = std::chrono::system_clock::from_time_t(std::stoi(futureDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(futureDate - currentDate).count()
        < secondsInYear);
    EXPECT_TRUE(futureDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateISO)
{
    auto currentDate = std::chrono::system_clock::now();

    auto soonDays = 2;

    auto soonDateISO = date::soonDate(soonDays);

    auto soonDate = parseISOFormattedStringToTimePoint(soonDateISO);

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count()
        < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateTimestamp)
{
    auto currentDate = std::chrono::system_clock::now();

    auto soonDays = 2;

    auto soonDateTimestamp = date::soonDate(soonDays, date::DateFormat::Timestamp);

    auto soonDate = std::chrono::system_clock::from_time_t(std::stoi(soonDateTimestamp));

    EXPECT_TRUE(std::chrono::duration_cast<std::chrono::seconds>(soonDate - currentDate).count()
        < secondsInYear);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAgeISO)
{
    auto birthdateISO = date::birthdateByAge(5, 15);

    auto birthdate = parseISOFormattedStringToTimePoint(birthdateISO);

    auto expectedStartDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * 15 };

    auto expectedEndDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * 5 };

    EXPECT_TRUE(birthdate > expectedStartDate);
    EXPECT_TRUE(birthdate < expectedEndDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByAgeTimestamp)
{
    auto birthdateTimestamp = date::birthdateByAge(5, 15, date::DateFormat::Timestamp);

    auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    auto expectedStartDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * 15 };

    auto expectedEndDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * 5 };

    EXPECT_TRUE(birthdate > expectedStartDate);
    EXPECT_TRUE(birthdate < expectedEndDate);
}

TEST_F(DateTest, shouldGenerateBirthDateByExactYearISO)
{
    auto birthdateISO = date::birthdateByYear(1996, 1996);

    auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_EQ(birthdate.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByExactYearTimestamp)
{
    auto birthdateTimestamp = date::birthdateByYear(1996, 1996, date::DateFormat::Timestamp);

    auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    // Convert std::chrono::system_clock::time_point to std::time_t
    std::time_t birthdateTimeT = std::chrono::system_clock::to_time_t(birthdate);

    // Convert std::time_t to std::tm
    std::tm birthdateStruct = *std::localtime(&birthdateTimeT);

    EXPECT_EQ(birthdateStruct.tm_year + 1900, 1996);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYearISO)
{
    auto birthdateISO = date::birthdateByYear(1990, 2000);

    auto birthdate = parseISOFormattedStringToTm(birthdateISO);

    EXPECT_GE(birthdate.tm_year + 1900, 1990);
    EXPECT_LE(birthdate.tm_year + 1900, 2000);
}

TEST_F(DateTest, shouldGenerateBirthDateByRangeYearTimestamp)
{
    auto birthdateTimestamp = date::birthdateByYear(1990, 2000, date::DateFormat::Timestamp);

    auto birthdate = std::chrono::system_clock::from_time_t(std::stoi(birthdateTimestamp));

    // Convert std::chrono::system_clock::time_point to std::time_t
    std::time_t birthdateTimeT = std::chrono::system_clock::to_time_t(birthdate);

    // Convert std::time_t to std::tm
    std::tm birthdateStruct = *std::localtime(&birthdateTimeT);

    EXPECT_GE(birthdateStruct.tm_year + 1900, 1990);
    EXPECT_LE(birthdateStruct.tm_year + 1900, 2000);
}

TEST_F(DateTest, shouldGenerateWeekdayName)
{
    auto generatedWeekdayName = date::weekdayName();

    FAKER_EXPECT_CONTAINS(date::data::weekdayNames, generatedWeekdayName);
}

TEST_F(DateTest, shouldGenerateWeekdayAbbreviatedName)
{
    auto generatedWeekdayAbbreviatedName = date::weekdayAbbreviatedName();

    FAKER_EXPECT_CONTAINS(date::data::weekdayAbbreviatedNames, generatedWeekdayAbbreviatedName);
}

TEST_F(DateTest, shouldGenerateMonthName)
{
    auto generatedMonthName = date::monthName();

    FAKER_EXPECT_CONTAINS(date::data::monthNames, generatedMonthName);
}

TEST_F(DateTest, shouldGenerateMonthAbbreviatedName)
{
    auto generatedMonthAbbreviatedName = date::monthAbbreviatedName();

    FAKER_EXPECT_CONTAINS(date::data::monthAbbreviatedNames, generatedMonthAbbreviatedName);
}
