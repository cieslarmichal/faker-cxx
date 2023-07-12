#include "Color.h"

#include "gtest/gtest.h"

#include "data/Colors.h"

using namespace ::testing;
using namespace faker;

class ColorTest : public Test
{
public:
};

TEST_F(ColorTest, shouldGenerateColorName)
{
    const auto generatedColorName = Color::name();

    ASSERT_TRUE(std::any_of(colors.begin(), colors.end(),
                            [generatedColorName](const std::string& colorName)
                            { return colorName == generatedColorName; }));
}
