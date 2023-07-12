#include "Color.h"

#include "gtest/gtest.h"

#include "data/Colors.h"
#include "StringHelper.h"

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

TEST_F(ColorTest, shouldGenerateRgbColorWithoutAlpha)
{
    const auto generatedRgbColor = Color::rgb();

    const auto rgbNumbers = StringHelper::split(generatedRgbColor.substr(4, generatedRgbColor.size() - 1), " ");

    const auto& red = std::stoi(rgbNumbers[0]);
    const auto& green = std::stoi(rgbNumbers[1]);
    const auto& blue = std::stoi(rgbNumbers[2]);

    ASSERT_TRUE(generatedRgbColor.starts_with("rgb("));
    ASSERT_TRUE(generatedRgbColor.ends_with(")"));
    ASSERT_TRUE(red >= 0 && red <= 255);
    ASSERT_TRUE(green >= 0 && red <= 255);
    ASSERT_TRUE(blue >= 0 && red <= 255);
}

TEST_F(ColorTest, shouldGenerateRgbColorWithAlpha)
{
    const auto generatedRgbaColor = Color::rgb(true);

    const auto rgbaNumbers = StringHelper::split(generatedRgbaColor.substr(5, generatedRgbaColor.size() - 1), " ");

    const auto& red = std::stoi(rgbaNumbers[0]);
    const auto& green = std::stoi(rgbaNumbers[1]);
    const auto& blue = std::stoi(rgbaNumbers[2]);
    const auto& alpha = std::stod(rgbaNumbers[3]);

    ASSERT_TRUE(generatedRgbaColor.starts_with("rgba("));
    ASSERT_TRUE(generatedRgbaColor.ends_with(")"));
    ASSERT_TRUE(red >= 0 && red <= 255);
    ASSERT_TRUE(green >= 0 && red <= 255);
    ASSERT_TRUE(blue >= 0 && red <= 255);
    ASSERT_TRUE(alpha >= 0 && alpha <= 1);
}
