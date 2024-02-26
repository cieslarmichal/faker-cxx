#include "test_helpers.h"
#include <iostream>
#include <modules/person_data.h>

using namespace faker::person::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(albanianMalesFirstNames);
    PRINT_ARRAY_SIZE(albanianFemalesFirstNames);
    PRINT_ARRAY_SIZE(albanianLastNames);

    PRINT_ARRAY_SIZE(argentinianMalesFirstNames);
    PRINT_ARRAY_SIZE(argentinianFemalesFirstNames);
    PRINT_ARRAY_SIZE(argentinianLastNames);

    PRINT_ARRAY_SIZE(australianMalesFirstNames);
    PRINT_ARRAY_SIZE(australianFemalesFirstNames);
    PRINT_ARRAY_SIZE(australianLastNames);

    PRINT_ARRAY_SIZE(austrianMalesFirstNames);
    PRINT_ARRAY_SIZE(austrianFemalesFirstNames);
    PRINT_ARRAY_SIZE(austrianLastNames);
    PRINT_ARRAY_SIZE(austrianMalesPrefixes);
    PRINT_ARRAY_SIZE(austrianFemalesPrefixes);

    PRINT_ARRAY_SIZE(azerbaijaniMalesFirstNames);
    PRINT_ARRAY_SIZE(azerbaijaniFemalesFirstNames);
    PRINT_ARRAY_SIZE(azerbaijaniMalesLastNames);
    PRINT_ARRAY_SIZE(azerbaijaniFemalesLastNames);

    PRINT_ARRAY_SIZE(belarusianMalesFirstNames);
    PRINT_ARRAY_SIZE(belarusianFemalesFirstNames);
    PRINT_ARRAY_SIZE(belarusianMalesLastNames);
    PRINT_ARRAY_SIZE(belarusianFemalesLastNames);

    PRINT_ARRAY_SIZE(belgianMalesFirstNames);
    PRINT_ARRAY_SIZE(belgianFemalesFirstNames);
    PRINT_ARRAY_SIZE(belgianLastNames);
    PRINT_ARRAY_SIZE(belgianSuffixes);
    PRINT_ARRAY_SIZE(belgianPrefixes);

    PRINT_ARRAY_SIZE(bosnianMalesFirstNames);
    PRINT_ARRAY_SIZE(bosnianFemalesFirstNames);
    PRINT_ARRAY_SIZE(bosnianLastNames);

    PRINT_ARRAY_SIZE(brazilianMalesFirstNames);
    PRINT_ARRAY_SIZE(brazilianFemalesFirstNames);
    PRINT_ARRAY_SIZE(brazilianLastNames);
    PRINT_ARRAY_SIZE(brazilianSuffixes);
    PRINT_ARRAY_SIZE(brazilianMalesPrefixes);
    PRINT_ARRAY_SIZE(brazilianFemalesPrefixes);

    PRINT_ARRAY_SIZE(bulgarianMalesFirstNames);
    PRINT_ARRAY_SIZE(bulgarianFemalesFirstNames);
    PRINT_ARRAY_SIZE(bulgarianLastNames);
    PRINT_ARRAY_SIZE(bulgarianSuffixes);
    PRINT_ARRAY_SIZE(bulgarianMalesPrefixes);
    PRINT_ARRAY_SIZE(bulgarianFemalesPrefixes);

    PRINT_ARRAY_SIZE(canadianMalesFirstNames);
    PRINT_ARRAY_SIZE(canadianFemalesFirstNames);
    PRINT_ARRAY_SIZE(canadianLastNames);

    PRINT_ARRAY_SIZE(chineseLastNames);
    PRINT_ARRAY_SIZE(chineseMalesFirstNames);
    PRINT_ARRAY_SIZE(chineseFemalesFirstNames);

    PRINT_ARRAY_SIZE(croatianMalesFirstNames);
    PRINT_ARRAY_SIZE(croatianFemalesFirstNames);
    PRINT_ARRAY_SIZE(croatianLastNames);
    PRINT_ARRAY_SIZE(croatianSuffixes);
    PRINT_ARRAY_SIZE(croatianMalesPrefixes);
    PRINT_ARRAY_SIZE(croatianFemalesPrefixes);

    PRINT_ARRAY_SIZE(czechMalesFirstNames);
    PRINT_ARRAY_SIZE(czechFemalesFirstNames);
    PRINT_ARRAY_SIZE(czechMalesLastNames);
    PRINT_ARRAY_SIZE(czechFemalesLastNames);
    PRINT_ARRAY_SIZE(czechPrefixes);
    PRINT_ARRAY_SIZE(czechSuffixes);

    PRINT_ARRAY_SIZE(danishMalesFirstNames);
    PRINT_ARRAY_SIZE(danishFemalesFirstNames);
    PRINT_ARRAY_SIZE(danishLastNames);
    PRINT_ARRAY_SIZE(danishMiddleNames);
    PRINT_ARRAY_SIZE(danishMalesPrefixes);
    PRINT_ARRAY_SIZE(danishFemalesPrefixes);

    PRINT_ARRAY_SIZE(dutchMalesFirstNames);
    PRINT_ARRAY_SIZE(dutchFemalesFirstNames);
    PRINT_ARRAY_SIZE(dutchLastNames);
    PRINT_ARRAY_SIZE(dutchSuffixes);
    PRINT_ARRAY_SIZE(dutchMalesPrefixes);
    PRINT_ARRAY_SIZE(dutchFemalesPrefixes);

    PRINT_ARRAY_SIZE(englishMalesFirstNames);
    PRINT_ARRAY_SIZE(englishFemalesFirstNames);
    PRINT_ARRAY_SIZE(englishLastNames);
    PRINT_ARRAY_SIZE(englishSuffixes);
    PRINT_ARRAY_SIZE(englishMalesPrefixes);
    PRINT_ARRAY_SIZE(englishFemalesPrefixes);

    PRINT_ARRAY_SIZE(estonianMalesFirstNames);
    PRINT_ARRAY_SIZE(estonianFemalesFirstNames);
    PRINT_ARRAY_SIZE(estonianLastNames);

    PRINT_ARRAY_SIZE(finnishMalesFirstNames);
    PRINT_ARRAY_SIZE(finnishFemalesFirstNames);
    PRINT_ARRAY_SIZE(finnishLastNames);

    PRINT_ARRAY_SIZE(frenchMalesFirstNames);
    PRINT_ARRAY_SIZE(frenchFemalesFirstNames);
    PRINT_ARRAY_SIZE(frenchLastNames);
    PRINT_ARRAY_SIZE(frenchMalesPrefixes);
    PRINT_ARRAY_SIZE(frenchFemalesPrefixes);

    PRINT_ARRAY_SIZE(germanMalesFirstNames);
    PRINT_ARRAY_SIZE(germanFemalesFirstNames);
    PRINT_ARRAY_SIZE(germanLastNames);
    PRINT_ARRAY_SIZE(germanMalesPrefixes);
    PRINT_ARRAY_SIZE(germanFemalesPrefixes);

    PRINT_ARRAY_SIZE(ghanaianMalesFirstNames);
    PRINT_ARRAY_SIZE(ghanaianFemalesFirstNames);
    PRINT_ARRAY_SIZE(ghanaianLastNames);

    PRINT_ARRAY_SIZE(greekMalesFirstNames);
    PRINT_ARRAY_SIZE(greekFemalesFirstNames);
    PRINT_ARRAY_SIZE(greekLastNames);

    PRINT_ARRAY_SIZE(hungarianMalesFirstNames);
    PRINT_ARRAY_SIZE(hungarianFemalesFirstNames);
    PRINT_ARRAY_SIZE(hungarianLastNames);
    PRINT_ARRAY_SIZE(hungarianPrefixes);

    PRINT_ARRAY_SIZE(icelandicMalesFirstNames);
    PRINT_ARRAY_SIZE(icelandicFemalesFirstNames);
    PRINT_ARRAY_SIZE(icelandicLastNames);

    PRINT_ARRAY_SIZE(indianMalesFirstNames);
    PRINT_ARRAY_SIZE(indianFemalesFirstNames);
    PRINT_ARRAY_SIZE(indianLastNames);

    PRINT_ARRAY_SIZE(irishMalesFirstNames);
    PRINT_ARRAY_SIZE(irishFemalesFirstNames);
    PRINT_ARRAY_SIZE(irishLastNames);
    PRINT_ARRAY_SIZE(irishSuffixes);
    PRINT_ARRAY_SIZE(irishMalesPrefixes);
    PRINT_ARRAY_SIZE(irishFemalesPrefixes);

    PRINT_ARRAY_SIZE(israelisMalesFirstNames);
    PRINT_ARRAY_SIZE(israelisFemalesFirstNames);
    PRINT_ARRAY_SIZE(israelisLastNames);

    PRINT_ARRAY_SIZE(italianMalesFirstNames);
    PRINT_ARRAY_SIZE(italianFemalesFirstNames);
    PRINT_ARRAY_SIZE(italianLastNames);
    PRINT_ARRAY_SIZE(italianPrefixes);

    PRINT_ARRAY_SIZE(japaneseMaleFirstNames);
    PRINT_ARRAY_SIZE(japaneseFemaleFirstNames);
    PRINT_ARRAY_SIZE(japaneseLastNames);

    PRINT_ARRAY_SIZE(kazakhMalesFirstNames);
    PRINT_ARRAY_SIZE(kazakhFemalesFirstNames);
    PRINT_ARRAY_SIZE(kazakhMalesLastNames);
    PRINT_ARRAY_SIZE(kazakhFemalesLastNames);

    PRINT_ARRAY_SIZE(koreanFirstNames);
    PRINT_ARRAY_SIZE(koreanLastNames);

    PRINT_ARRAY_SIZE(latvianMalesFirstNames);
    PRINT_ARRAY_SIZE(latvianFemalesFirstNames);
    PRINT_ARRAY_SIZE(latvianMalesLastNames);
    PRINT_ARRAY_SIZE(latvianFemalesLastNames);
    PRINT_ARRAY_SIZE(latvianSuffixes);
    PRINT_ARRAY_SIZE(latvianPrefixes);

    PRINT_ARRAY_SIZE(lebaneseMalesFirstNames);
    PRINT_ARRAY_SIZE(lebaneseFemalesFirstNames);
    PRINT_ARRAY_SIZE(lebaneseLastNames);

    PRINT_ARRAY_SIZE(lithuanianMalesFirstNames);
    PRINT_ARRAY_SIZE(lithuanianFemalesFirstNames);
    PRINT_ARRAY_SIZE(lithuanianLastNames);

    PRINT_ARRAY_SIZE(macedonianMalesFirstNames);
    PRINT_ARRAY_SIZE(macedonianFemalesFirstNames);
    PRINT_ARRAY_SIZE(macedonianMalesLastNames);
    PRINT_ARRAY_SIZE(macedonianFemalesLastNames);
    PRINT_ARRAY_SIZE(macedonianMalesPrefixes);
    PRINT_ARRAY_SIZE(macedonianFemalesPrefixes);

    PRINT_ARRAY_SIZE(maldiviansMalesFirstNames);
    PRINT_ARRAY_SIZE(maldiviansFemalesFirstNames);
    PRINT_ARRAY_SIZE(maldiviansMalesLastNames);
    PRINT_ARRAY_SIZE(maldiviansFemalesLastNames);
    PRINT_ARRAY_SIZE(maldiviansMalesPrefixes);
    PRINT_ARRAY_SIZE(maldiviansFemalesPrefixes);

    PRINT_ARRAY_SIZE(malteseMalesFirstNames);
    PRINT_ARRAY_SIZE(malteseFemalesFirstNames);
    PRINT_ARRAY_SIZE(malteseLastNames);

    PRINT_ARRAY_SIZE(mexicanMalesFirstNames);
    PRINT_ARRAY_SIZE(mexicanFemalesFirstNames);
    PRINT_ARRAY_SIZE(mexicanLastNames);
    PRINT_ARRAY_SIZE(mexicanSuffixes);
    PRINT_ARRAY_SIZE(mexicanMalesPrefixes);
    PRINT_ARRAY_SIZE(mexicanFemalesPrefixes);

    PRINT_ARRAY_SIZE(moldovanMalesFirstNames);
    PRINT_ARRAY_SIZE(moldovanFemalesFirstNames);
    PRINT_ARRAY_SIZE(moldovanLastNames);

    PRINT_ARRAY_SIZE(monacanMalesFirstNames);
    PRINT_ARRAY_SIZE(monacanFemalesFirstNames);
    PRINT_ARRAY_SIZE(monacanLastNames);

    PRINT_ARRAY_SIZE(nepaleseMalesFirstNames);
    PRINT_ARRAY_SIZE(nepaleseFemalesFirstNames);
    PRINT_ARRAY_SIZE(nepaleseLastNames);

    PRINT_ARRAY_SIZE(norwegianMalesFirstNames);
    PRINT_ARRAY_SIZE(norwegianFemalesFirstNames);
    PRINT_ARRAY_SIZE(norwegianLastNames);
    PRINT_ARRAY_SIZE(norwegianSuffixes);
    PRINT_ARRAY_SIZE(norwegianPrefixes);

    PRINT_ARRAY_SIZE(palestinianMalesFirstNames);
    PRINT_ARRAY_SIZE(palestinianFemalesFirstNames);
    PRINT_ARRAY_SIZE(palestinianLastNames);

    PRINT_ARRAY_SIZE(persianMalesFirstNames);
    PRINT_ARRAY_SIZE(persianFemalesFirstNames);
    PRINT_ARRAY_SIZE(persianLastNames);
    PRINT_ARRAY_SIZE(persianMalesPrefixes);
    PRINT_ARRAY_SIZE(persianFemalesPrefixes);

    PRINT_ARRAY_SIZE(polishMalesFirstNames);
    PRINT_ARRAY_SIZE(polishFemalesFirstNames);
    PRINT_ARRAY_SIZE(polishLastNames);
    PRINT_ARRAY_SIZE(polishMalesPrefixes);
    PRINT_ARRAY_SIZE(polishFemalesPrefixes);

    PRINT_ARRAY_SIZE(portugueseMalesFirstNames);
    PRINT_ARRAY_SIZE(portugueseFemalesFirstNames);
    PRINT_ARRAY_SIZE(portugueseLastNames);
    PRINT_ARRAY_SIZE(portugueseMalesPrefixes);
    PRINT_ARRAY_SIZE(portugueseFemalesPrefixes);

    PRINT_ARRAY_SIZE(romanianMalesFirstNames);
    PRINT_ARRAY_SIZE(romanianFemalesFirstNames);
    PRINT_ARRAY_SIZE(romanianLastNames);
    PRINT_ARRAY_SIZE(romanianSuffixes);
    PRINT_ARRAY_SIZE(romanianMalesPrefixes);
    PRINT_ARRAY_SIZE(romanianFemalesPrefixes);

    PRINT_ARRAY_SIZE(russianMalesFirstNames);
    PRINT_ARRAY_SIZE(russianFemalesFirstNames);
    PRINT_ARRAY_SIZE(russianMalesLastNames);
    PRINT_ARRAY_SIZE(russianFemalesLastNames);
    PRINT_ARRAY_SIZE(russianMalesMiddleNames);
    PRINT_ARRAY_SIZE(russianFemalesMiddleNames);

    PRINT_ARRAY_SIZE(serbianMalesFirstNames);
    PRINT_ARRAY_SIZE(serbianFemalesFirstNames);
    PRINT_ARRAY_SIZE(serbianLastNames);

    PRINT_ARRAY_SIZE(slovakMalesFirstNames);
    PRINT_ARRAY_SIZE(slovakFemalesFirstNames);
    PRINT_ARRAY_SIZE(slovakMalesLastNames);
    PRINT_ARRAY_SIZE(slovakFemalesLastNames);
    PRINT_ARRAY_SIZE(slovakSuffixes);
    PRINT_ARRAY_SIZE(slovakPrefixes);

    PRINT_ARRAY_SIZE(slovenianMalesFirstNames);
    PRINT_ARRAY_SIZE(slovenianFemalesFirstNames);
    PRINT_ARRAY_SIZE(slovenianLastNames);

    PRINT_ARRAY_SIZE(southAfricanMalesFirstNames);
    PRINT_ARRAY_SIZE(southAfricanFemalesFirstNames);
    PRINT_ARRAY_SIZE(southAfricanLastNames);

    PRINT_ARRAY_SIZE(spanishMalesFirstNames);
    PRINT_ARRAY_SIZE(spanishFemalesFirstNames);
    PRINT_ARRAY_SIZE(spanishLastNames);
    PRINT_ARRAY_SIZE(spanishMalesPrefixes);
    PRINT_ARRAY_SIZE(spanishFemalesPrefixes);

    PRINT_ARRAY_SIZE(swedishMalesFirstNames);
    PRINT_ARRAY_SIZE(swedishFemalesFirstNames);
    PRINT_ARRAY_SIZE(swedishLastNames);
    PRINT_ARRAY_SIZE(swedishPrefixes);

    PRINT_ARRAY_SIZE(swissMalesFirstNames);
    PRINT_ARRAY_SIZE(swissFemalesFirstNames);
    PRINT_ARRAY_SIZE(swissLastNames);
    PRINT_ARRAY_SIZE(swissMalesPrefixes);
    PRINT_ARRAY_SIZE(swissFemalesPrefixes);

    PRINT_ARRAY_SIZE(syrianMalesFirstNames);
    PRINT_ARRAY_SIZE(syrianFemalesFirstNames);
    PRINT_ARRAY_SIZE(syrianLastNames);

    PRINT_ARRAY_SIZE(turkishMalesFirstNames);
    PRINT_ARRAY_SIZE(turkishFemalesFirstNames);
    PRINT_ARRAY_SIZE(turkishLastNames);
    PRINT_ARRAY_SIZE(turkishMalesPrefixes);
    PRINT_ARRAY_SIZE(turkishFemalesPrefixes);

    PRINT_ARRAY_SIZE(ukrainianMalesFirstNames);
    PRINT_ARRAY_SIZE(ukrainianFemalesFirstNames);
    PRINT_ARRAY_SIZE(ukrainianMalesLastNames);
    PRINT_ARRAY_SIZE(ukrainianFemalesLastNames);
    PRINT_ARRAY_SIZE(ukrainianMalesMiddleNames);
    PRINT_ARRAY_SIZE(ukrainianFemalesMiddleNames);
    PRINT_ARRAY_SIZE(ukrainianMalesPrefixes);
    PRINT_ARRAY_SIZE(ukrainianFemalesPrefixes);

    PRINT_ARRAY_SIZE(vietnameseMalesFirstNames);
    PRINT_ARRAY_SIZE(vietnameseFemalesFirstNames);
    PRINT_ARRAY_SIZE(vietnameseLastNames);
}
