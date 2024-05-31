#include "faker-cxx/Color.h"

#include <algorithm>
#include <charconv>

#include "gtest/gtest.h"

#include "color/ColorData.h"
#include "common/StringHelper.h"
#include "string/StringData.h"

using namespace ::testing;
using namespace faker;

class ColorTest : public Test
{
public:
};

TEST_F(ColorTest, shouldGenerateColorName)
{
    const auto generatedColorName = Color::name();

    ASSERT_TRUE(std::ranges::any_of(colors, [generatedColorName](const std::string_view& colorName)
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
                                    { return string::hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(ColorTest, shouldGenerateHexColorWithAlpha)
{
    const auto hexadecimal = Color::hex(HexCasing::Upper, HexPrefix::ZeroX, true);

    const auto prefix = hexadecimal.substr(0, 2);
    const auto hexNumber = hexadecimal.substr(2);

    ASSERT_EQ(hexadecimal.size(), 10);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                    { return string::hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
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

    int hue, saturation, lightness;

    std::from_chars(hslValues[0].data(), hslValues[0].data() + hslValues[0].size(), hue);
    std::from_chars(hslValues[1].data(), hslValues[1].data() + hslValues[1].size(), saturation);
    std::from_chars(hslValues[2].data(), hslValues[2].data() + hslValues[2].size(), lightness);

    auto offset = hslValues[3].size();
    const auto alpha = std::stod(hslValues[3], &offset);

    ASSERT_TRUE(generatedHslaColor.starts_with("hsla("));
    ASSERT_TRUE(generatedHslaColor.ends_with(")"));
    ASSERT_TRUE(hue >= 0 && hue <= 360);
    ASSERT_TRUE(saturation >= 0 && saturation <= 100);
    ASSERT_TRUE(lightness >= 0 && lightness <= 100);
    ASSERT_TRUE(alpha >= 0 && alpha <= 1);
}

TEST_F(ColorTest, shouldGenerateLchWithoutAlpha)
{
    const auto generatedLchColor = faker::Color::lch();
    const auto lchValues = faker::StringHelper::split(generatedLchColor.substr(4, generatedLchColor.size() - 1), " ");

    int luminance, chroma, hue;

    std::from_chars(lchValues[0].data(), lchValues[0].data() + lchValues[0].size(), luminance);
    std::from_chars(lchValues[1].data(), lchValues[1].data() + lchValues[1].size(), chroma);
    std::from_chars(lchValues[2].data(), lchValues[2].data() + lchValues[2].size(), hue);

    ASSERT_TRUE(generatedLchColor.starts_with("lch("));
    ASSERT_TRUE(generatedLchColor.ends_with(")"));
    ASSERT_TRUE(luminance >= 0 && luminance <= 100);
    ASSERT_TRUE(chroma >= 0 && chroma <= 100);
    ASSERT_TRUE(hue >= 0 && hue <= 360);
}

TEST_F(ColorTest, shouldGenerateLchWithAlpha)
{
    const auto generatedLchaColor = faker::Color::lch(true);
    const auto lchValues = faker::StringHelper::split(generatedLchaColor.substr(5, generatedLchaColor.size() - 1), " ");

    int luminance, chroma, hue;

    std::from_chars(lchValues[0].data(), lchValues[0].data() + lchValues[0].size(), luminance);
    std::from_chars(lchValues[1].data(), lchValues[1].data() + lchValues[1].size(), chroma);
    std::from_chars(lchValues[2].data(), lchValues[2].data() + lchValues[2].size(), hue);

    auto offset = lchValues[3].size();
    const auto alpha = std::stod(lchValues[3], &offset);

    ASSERT_TRUE(generatedLchaColor.starts_with("lcha("));
    ASSERT_TRUE(generatedLchaColor.ends_with(")"));
    ASSERT_TRUE(luminance >= 0 && luminance <= 100);
    ASSERT_TRUE(chroma >= 0 && chroma <= 100);
    ASSERT_TRUE(hue >= 0 && hue <= 360);
    ASSERT_TRUE(alpha >= 0 && alpha <= 1);
}

TEST_F(ColorTest, shouldGenerateCmykColor)
{
    const auto generatedCmykColor = faker::Color::cmyk();
    const auto cmykValues =
        faker::StringHelper::split(generatedCmykColor.substr(5, generatedCmykColor.size() - 1), " ");

    auto offset = cmykValues[0].size();
    const auto cyan = std::stod(cmykValues[0], &offset);
    offset = cmykValues[1].size();
    const auto magenta = std::stod(cmykValues[1], &offset);
    offset = cmykValues[2].size();
    const auto yellow = std::stod(cmykValues[2], &offset);
    offset = cmykValues[3].size();
    const auto key = std::stod(cmykValues[3], &offset);

    ASSERT_TRUE(generatedCmykColor.starts_with("cmyk("));
    ASSERT_TRUE(generatedCmykColor.ends_with(")"));
    ASSERT_TRUE(0. <= cyan && cyan <= 1.);
    ASSERT_TRUE(0. <= magenta && magenta <= 1.);
    ASSERT_TRUE(0. <= yellow && yellow <= 1.);
    ASSERT_TRUE(0. <= key && key <= 1.);
}

TEST_F(ColorTest, shouldGenerateLabColor)
{
    const auto generatedLabColor = faker::Color::lab();
    const auto labValues = faker::StringHelper::split(generatedLabColor.substr(4, generatedLabColor.size() - 1), " ");

    auto offset = labValues[0].size();
    const auto lightness = std::stod(labValues[0], &offset);
    offset = labValues[1].size();
    const auto redGreenValue = std::stod(labValues[1], &offset);
    offset = labValues[2].size();
    const auto blueYellowValue = std::stod(labValues[2], &offset);

    ASSERT_TRUE(generatedLabColor.starts_with("lab("));
    ASSERT_TRUE(generatedLabColor.ends_with(")"));
    ASSERT_TRUE(lightness >= 0. && lightness <= 100.);
    ASSERT_TRUE(redGreenValue >= -128. && redGreenValue <= 128.);
    ASSERT_TRUE(blueYellowValue >= -128. && blueYellowValue <= 128.);
}

TEST_F(ColorTest, shouldGenerateHsb)
{
    const auto generatedHsbColor = faker::Color::hsb();
    const auto hsbValues = faker::StringHelper::split(generatedHsbColor.substr(4, generatedHsbColor.size() - 1), " ");

    int hue, saturation, brightness;

    std::from_chars(hsbValues[0].data(), hsbValues[0].data() + hsbValues[0].size(), hue);
    std::from_chars(hsbValues[1].data(), hsbValues[1].data() + hsbValues[1].size(), saturation);
    std::from_chars(hsbValues[2].data(), hsbValues[2].data() + hsbValues[2].size(), brightness);

    ASSERT_TRUE(generatedHsbColor.starts_with("hsb("));
    ASSERT_TRUE(generatedHsbColor.ends_with(")"));
    ASSERT_TRUE(hue >= 0 && hue <= 360);
    ASSERT_TRUE(saturation >= 0 && saturation <= 100);
    ASSERT_TRUE(brightness >= 0 && brightness <= 100);
}

TEST_F(ColorTest, shouldGenerateHsv)
{
    const auto generatedHsvColor = faker::Color::hsv();
    const auto hsvValues = faker::StringHelper::split(generatedHsvColor.substr(4, generatedHsvColor.size() - 1), " ");

    int hue, saturation, brightness;

    std::from_chars(hsvValues[0].data(), hsvValues[0].data() + hsvValues[0].size(), hue);
    std::from_chars(hsvValues[1].data(), hsvValues[1].data() + hsvValues[1].size(), saturation);
    std::from_chars(hsvValues[2].data(), hsvValues[2].data() + hsvValues[2].size(), brightness);

    ASSERT_TRUE(generatedHsvColor.starts_with("hsv("));
    ASSERT_TRUE(generatedHsvColor.ends_with(")"));
    ASSERT_TRUE(hue >= 0 && hue <= 360);
    ASSERT_TRUE(saturation >= 0 && saturation <= 100);
    ASSERT_TRUE(brightness >= 0 && brightness <= 100);
}

TEST_F(ColorTest, shouldGenerateYuv)
{
    const auto generatedYuvColor = faker::Color::yuv();
    const auto yuvValues = faker::StringHelper::split(generatedYuvColor.substr(4, generatedYuvColor.size() - 1), " ");

    int luminance, chrominanceBlueColor, chrominanceRedColor;

    std::from_chars(yuvValues[0].data(), yuvValues[0].data() + yuvValues[0].size(), luminance);
    std::from_chars(yuvValues[1].data(), yuvValues[1].data() + yuvValues[1].size(), chrominanceBlueColor);
    std::from_chars(yuvValues[2].data(), yuvValues[2].data() + yuvValues[2].size(), chrominanceRedColor);

    ASSERT_TRUE(generatedYuvColor.starts_with("yuv("));
    ASSERT_TRUE(generatedYuvColor.ends_with(")"));
    ASSERT_TRUE(luminance >= 0 && luminance <= 255);
    ASSERT_TRUE(chrominanceBlueColor >= 0 && chrominanceBlueColor <= 255);
    ASSERT_TRUE(chrominanceRedColor >= 0 && chrominanceRedColor <= 255);
}
