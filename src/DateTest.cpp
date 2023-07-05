#include "Date.h"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class DateTest : public Test
{
public:
};

TEST_F(DateTest, shouldGeneratePastDate)
{
    std::cerr << Date::futureISOString() << std::endl;
}

TEST_F(DateTest, shouldGenerateSoonDate) {}
