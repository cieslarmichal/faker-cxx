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

    EXPECT_TRUE((pastDate - currentDate).total_seconds() < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGeneratePastDateISO)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto pastDateISO = Date::pastISOString();

    const auto pastDate = boost::posix_time::from_iso_extended_string(pastDateISO);

    EXPECT_TRUE((pastDate - currentDate).total_seconds() < secondsInYear);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDate)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto recentDays = 5;

    const auto pastDate = Date::recent(recentDays);

    EXPECT_TRUE((pastDate - currentDate).total_seconds() < secondsInDay * recentDays);
    EXPECT_TRUE(pastDate < currentDate);
}

TEST_F(DateTest, shouldGenerateRecentDateISO)
{
    const auto currentDate = boost::posix_time::second_clock::local_time();

    const auto recentDays = 5;

    const auto pastDateISO = Date::pastISOString();

    const auto pastDate = boost::posix_time::from_iso_extended_string(pastDateISO);

    EXPECT_TRUE((pastDate - currentDate).total_seconds() < secondsInDay * recentDays);
    EXPECT_TRUE(pastDate < currentDate);
}
