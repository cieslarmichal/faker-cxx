#include "faker-cxx/Color.h"

#include <algorithm>
#include <charconv>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "../string/data/Characters.h"
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

    ASSERT_TRUE(std::ranges::any_of(colors, [generatedColorName](const std::string& colorName)
                                    { return colorName == generatedColorName; }));
}

TEST_F(ColorTest, shouldGenerateRgbColorWithoutAlpha)
{
    const auto generatedRgbColor = Color::rgb();

    const auto rgbNumbers = StringHelper::split(generatedRgbColor.substr(4, generatedRgbColor.size() - 1), " ");

    int red, green, blue;
    std::from_chars(rgbNumbers[0].data(), rgbNumbers[0].data() + rgbNumbers[0].size(), red);
    std::from_chars(rgbNumbers[1].data(), rgbNumbers[1].data() + rgbNumbers[1].size(), green);
    std::from_chars(rgbNumbers[2].data(), rgbNumbers[2].data() + rgbNumbers[2].size(), blue);

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

    int red, green, blue, alpha;
    std::from_chars(rgbaNumbers[0].data(), rgbaNumbers[0].data() + rgbaNumbers[0].size(), red);
    std::from_chars(rgbaNumbers[1].data(), rgbaNumbers[1].data() + rgbaNumbers[1].size(), green);
    std::from_chars(rgbaNumbers[2].data(), rgbaNumbers[2].data() + rgbaNumbers[2].size(), blue);
    std::from_chars(rgbaNumbers[3].data(), rgbaNumbers[3].data() + rgbaNumbers[3].size(), alpha);

    ASSERT_TRUE(generatedRgbaColor.starts_with("rgba("));
    ASSERT_TRUE(generatedRgbaColor.ends_with(")"));
    ASSERT_TRUE(red >= 0 && red <= 255);
    ASSERT_TRUE(green >= 0 && red <= 255);
    ASSERT_TRUE(blue >= 0 && red <= 255);
    ASSERT_TRUE(alpha >= 0 && alpha <= 1);
}

TEST_F(ColorTest, shouldGenerateHexColorWithoutAlpha)
{
    const auto hexadecimal = Color::hex();

    const auto prefix = hexadecimal.substr(0, 1);
    const auto hexNumber = hexadecimal.substr(1);

    ASSERT_EQ(hexadecimal.size(), 7);
    ASSERT_EQ(prefix, "#");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                    { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(ColorTest, shouldGenerateHexColorWithAlpha)
{
    const auto hexadecimal = Color::hex(HexCasing::Upper, HexPrefix::ZeroX, true);

    const auto prefix = hexadecimal.substr(0, 2);
    const auto hexNumber = hexadecimal.substr(2);

    ASSERT_EQ(hexadecimal.size(), 10);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(ColorTest, shouldGenerateHslWithoutAlpha)
{
    const auto generatedHslColor = faker::Color::hsl();
    const auto hslValues = faker::StringHelper::split(generatedHslColor.substr(4, generatedHslColor.size() - 1), " ");

    int hue, staturation, lightness;

    std::from_chars(hslValues[0].data(), hslValues[0].data() + hslValues[0].size(), hue);
    std::from_chars(hslValues[1].data(), hslValues[1].data() + hslValues[1].size(), staturation);
    std::from_chars(hslValues[2].data(), hslValues[2].data() + hslValues[2].size(), lightness);

    ASSERT_TRUE(generatedHslColor.starts_with("hsl("));
    ASSERT_TRUE(generatedHslColor.ends_with(")"));
    ASSERT_TRUE(hue >= 0 && hue <= 360);
    ASSERT_TRUE(staturation >= 0 && staturation <= 100);
    ASSERT_TRUE(lightness >= 0 && lightness <= 100);
}

TEST_F(ColorTest, shouldGenerateHslWithAlpha)
{
    const auto generatedHslaColor = faker::Color::hsl(true);
    const auto hslValues = faker::StringHelper::split(generatedHslaColor.substr(5, generatedHslaColor.size() - 1), " ");

    int hue, staturation, lightness;

    std::from_chars(hslValues[0].data(), hslValues[0].data() + hslValues[0].size(), hue);
    std::from_chars(hslValues[1].data(), hslValues[1].data() + hslValues[1].size(), staturation);
    std::from_chars(hslValues[2].data(), hslValues[2].data() + hslValues[2].size(), lightness);

    auto offset = hslValues[3].size();
    const auto alpha = std::stod(hslValues[3].data(), &offset);

    ASSERT_TRUE(generatedHslaColor.starts_with("hsla("));
    ASSERT_TRUE(generatedHslaColor.ends_with(")"));
    ASSERT_TRUE(hue >= 0 && hue <= 360);
    ASSERT_TRUE(staturation >= 0 && staturation <= 100);
    ASSERT_TRUE(lightness >= 0 && lightness <= 100);
    ASSERT_TRUE(alpha >= 0 && alpha <= 1);
}
