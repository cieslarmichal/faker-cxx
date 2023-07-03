#include "InternetDataGenerator.h"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker::internet;

class InternetDataGeneratorTest : public Test
{
public:
};

TEST_F(InternetDataGeneratorTest, xxx)
{
    for (int i = 0; i <= 1000; i++)
    {
        std::cout << InternetDataGenerator::email() << std::endl;
    }
}
