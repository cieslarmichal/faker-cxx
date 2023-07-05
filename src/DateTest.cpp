#include "Date.h"

#include <boost/date_time/posix_time/posix_time.hpp>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

namespace
{
const auto secondsInYear = 31556926;
const auto secondsInDay = 86400;
}

class DateTest : public Test
{
public:
};

TEST_F(DateTest, shouldGeneratePastDate)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto pastDate = Date::past();

    EXPECT_TRUE((currentDate - pastDate).total_seconds() < secondsInYear);
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

    const auto pastDate = Date::recent(recentDays);

    EXPECT_TRUE((currentDate - pastDate).total_seconds() < secondsInDay * recentDays);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateISO)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto recentDays = 5;

    const auto pastDateISO = Date::recentISOString();

    const auto pastDate = boost::posix_time::from_iso_extended_string(pastDateISO);

    EXPECT_TRUE((currentDate - pastDate).total_seconds() < secondsInDay * recentDays);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateFutureDate)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto futureDate = Date::future();

    EXPECT_TRUE((futureDate - currentDate).total_seconds() < secondsInYear);
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

    EXPECT_TRUE((soonDate - currentDate).total_seconds() <  secondsInDay * soonDays);
    EXPECT_TRUE(soonDate > currentDate);
}

TEST_F(DateTest, shouldGenerateSoonDateISO)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto soonDays = 2;

    const auto soonDateISO = Date::soonISOString(soonDays);

    const auto soonDate = boost::posix_time::from_iso_extended_string(soonDateISO);

    EXPECT_TRUE((soonDate - currentDate).total_seconds() <  secondsInDay * soonDays);
    EXPECT_TRUE(soonDate > currentDate);
}
