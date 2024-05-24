#include "faker-cxx/Person.h"

#include <algorithm>
#include <regex>

#include "gtest/gtest.h"

#include "faker-cxx/Internet.h"
#include "person/data/albania/AlbanianPeopleNames.h"
#include "person/data/argentina/ArgentinianPeopleNames.h"
#include "person/data/australia/AustralianPeopleNames.h"
#include "person/data/austria/AustrianPeopleNames.h"
#include "person/data/azerbaijan/AzerbaijaniPeopleNames.h"
#include "person/data/belarus/BelarusianPeopleNames.h"
#include "person/data/belgium/BelgianPeopleNames.h"
#include "person/data/Bio.h"
#include "person/data/bosnia/BosnianPeopleNames.h"
#include "person/data/brazil/BrazilianPeopleNames.h"
#include "person/data/bulgaria/BulgarianPeopleNames.h"
#include "person/data/canada/CanadianPeopleNames.h"
#include "person/data/china/ChinesePeopleNames.h"
#include "person/data/croatia/CroatianPeopleNames.h"
#include "person/data/czech/CzechPeopleNames.h"
#include "person/data/denmark/DanishPeopleNames.h"
#include "person/data/england/EnglishPeopleNames.h"
#include "person/data/estonia/EstonianPeopleNames.h"
#include "person/data/finland/FinnishPeopleNames.h"
#include "person/data/france/FrenchPeopleNames.h"
#include "person/data/Gender.h"
#include "person/data/germany/GermanPeopleNames.h"
#include "person/data/ghana/GhanaianPeopleNames.h"
#include "person/data/greece/GreekPeopleNames.h"
#include "person/data/Hobbies.h"
#include "person/data/hungary/HungarianPeopleNames.h"
#include "person/data/iceland/IcelandicPeopleNames.h"
#include "person/data/india/IndianPeopleNames.h"
#include "person/data/iran/PersianPeopleNames.h"
#include "person/data/ireland/IrishPeopleNames.h"
#include "person/data/israel/IsraeliPeopleNames.h"
#include "person/data/italy/ItalianPeopleNames.h"
#include "person/data/japan/JapanesePeopleNames.h"
#include "person/data/JobTitles.h"
#include "person/data/kazakhstan/KazakhPeopleNames.h"
#include "person/data/korea/KoreanPeopleNames.h"
#include "person/data/Languages.h"
#include "person/data/latvia/LatvianPeopleNames.h"
#include "person/data/lebanon/LebanesePeopleNames.h"
#include "person/data/liechtenstein/LiechtensteinerPeopleNames.h"
#include "person/data/lithuania/LithuanianPeopleNames.h"
#include "person/data/macedonia/MacedonianPeopleNames.h"
#include "person/data/maldives/MaldiviansPeopleNames.h"
#include "person/data/malta/MaltesePeopleNames.h"
#include "person/data/mexico/MexicanPeopleNames.h"
#include "person/data/moldova/MoldovanPeopleNames.h"
#include "person/data/monaco/MonacanPeopleNames.h"
#include "person/data/Nationalities.h"
#include "person/data/nepal/NepalesePeopleNames.h"
#include "person/data/netherlands/DutchPeopleNames.h"
#include "person/data/norway/NorwegianPeopleNames.h"
#include "person/data/palestine/PalestinianPeopleNames.h"
#include "person/data/PeopleNames.h"
#include "person/data/poland/PolishPeopleNames.h"
#include "person/data/portugal/PortuguesePeopleNames.h"
#include "person/data/romania/RomanianPeopleNames.h"
#include "person/data/russia/RussianPeopleNames.h"
#include "person/data/serbia/SerbianPeopleNames.h"
#include "person/data/slovakia/SlovakPeopleNames.h"
#include "person/data/slovenia/SlovenianPeopleNames.h"
#include "person/data/southAfrica/SouthAfricanPeopleNames.h"
#include "person/data/spain/SpanishPeopleNames.h"
#include "person/data/sweden/SwedishPeopleNames.h"
#include "person/data/switzerland/SwissPeopleNames.h"
#include "person/data/syria/SyrianPeopleNames.h"
#include "person/data/turkey/TurkishPeopleNames.h"
#include "person/data/ukraine/UkrainianPeopleNames.h"
#include "person/data/usa/UsaPeopleNames.h"
#include "person/data/vietnam/VietnamesePeopleNames.h"
#include "person/data/ZodiacSigns.h"
#include "word/data/Nouns.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::vector<SsnCountry> supportedSsnCountries{
    SsnCountry::Poland, SsnCountry::UnitedStates, SsnCountry::UnitedKingdom, SsnCountry::Germany,
    SsnCountry::France, SsnCountry::Italy,        SsnCountry::Spain,         SsnCountry::India,
};

const std::vector<std::string> sexes{"Male", "Female"};

const std::unordered_map<Language, std::unordered_map<Sex, std::string>> sexTranslations = {
    {Language::English, {{Sex::Male, "Male"}, {Sex::Female, "Female"}}},
    {Language::Polish, {{Sex::Male, "Mężczyzna"}, {Sex::Female, "Kobieta"}}},
    {Language::Italian, {{Sex::Male, "Maschio"}, {Sex::Female, "Femmina"}}},
    {Language::French, {{Sex::Male, "Homme"}, {Sex::Female, "Femme"}}},
    {Language::German, {{Sex::Male, "Mann"}, {Sex::Female, "Frau"}}},
    {Language::Russian, {{Sex::Male, "Мужчина"}, {Sex::Female, "Женщина"}}},
    {Language::Romanian, {{Sex::Male, "Bărbat"}, {Sex::Female, "Femeie"}}},
    {Language::Hindi, {{Sex::Male, "पुरुष"}, {Sex::Female, "महिला"}}},
    {Language::Finnish, {{Sex::Male, "Mies"}, {Sex::Female, "Nainen"}}},
    {Language::Nepali, {{Sex::Male, "पुरुष"}, {Sex::Female, "महिला"}}},
    {Language::Spanish, {{Sex::Male, "Hombre"}, {Sex::Female, "Mujer"}}},
    {Language::Turkish, {{Sex::Male, "Erkek"}, {Sex::Female, "Kadın"}}},
    {Language::Czech, {{Sex::Male, "Muž"}, {Sex::Female, "Žena"}}},
    {Language::Slovak, {{Sex::Male, "Muž"}, {Sex::Female, "Žena"}}},
    {Language::Ukrainian, {{Sex::Male, "Чоловік"}, {Sex::Female, "Жінка"}}},
    {Language::Danish, {{Sex::Male, "Mand"}, {Sex::Female, "Kvinde"}}},
    {Language::Swedish, {{Sex::Male, "Man"}, {Sex::Female, "Kvinna"}}},
    {Language::Portuguese, {{Sex::Male, "Homem"}, {Sex::Female, "Mulher"}}},
    {Language::Norwegian, {{Sex::Male, "Mann"}, {Sex::Female, "Kvinne"}}},
    {Language::Japanese, {{Sex::Male, "男性"}, {Sex::Female, "女性"}}},
    {Language::Hungarian, {{Sex::Male, "Férfi"}, {Sex::Female, "Nő"}}},
    {Language::Croatian, {{Sex::Male, "Muškarac"}, {Sex::Female, "Žena"}}},
    {Language::Greek, {{Sex::Male, "Άνδρας"}, {Sex::Female, "Γυναίκα"}}},
    {Language::Slovene, {{Sex::Male, "Moški"}, {Sex::Female, "Ženska"}}},
    {Language::Dutch, {{Sex::Male, "Man"}, {Sex::Female, "Vrouw"}}},
    {Language::Mandarin, {{Sex::Male, "男"}, {Sex::Female, "女"}}},
    {Language::Korean, {{Sex::Male, "남자"}, {Sex::Female, "여자"}}},
    {Language::Serbian, {{Sex::Male, "Мушкарац"}, {Sex::Female, "Жена"}}},
    {Language::Macedonian, {{Sex::Male, "Маж"}, {Sex::Female, "Жена"}}},
    {Language::Albanian, {{Sex::Male, "Mashkull"}, {Sex::Female, "Femër"}}},
    {Language::Latvian, {{Sex::Male, "Vīrietis"}, {Sex::Female, "Sieviete"}}},
    {Language::Belarusian, {{Sex::Male, "Мужчына"}, {Sex::Female, "Жанчына"}}},
    {Language::Estonian, {{Sex::Male, "Mees"}, {Sex::Female, "Naine"}}},
    {Language::Irish, {{Sex::Male, "fireannach"}, {Sex::Female, "baineann"}}}};

const std::vector<Country> countries{
    Country::Usa,       Country::England,       Country::Poland,      Country::Italy,     Country::France,
    Country::Germany,   Country::Russia,        Country::Romania,     Country::India,     Country::Finland,
    Country::Nepal,     Country::Spain,         Country::Turkey,      Country::Czech,     Country::Slovakia,
    Country::Ukraine,   Country::Denmark,       Country::Sweden,      Country::Brazil,    Country::Norway,
    Country::Japan,     Country::Portugal,      Country::Hungary,     Country::Croatia,   Country::Greece,
    Country::Slovenia,  Country::Austria,       Country::Switzerland, Country::Belgium,   Country::Netherlands,
    Country::China,     Country::Korea,         Country::Canada,      Country::Mexico,    Country::Argentina,
    Country::Australia, Country::Serbia,        Country::Macedonia,   Country::Albania,   Country::Latvia,
    Country::Ireland,   Country::Belarus,       Country::Estonia,     Country::Iran,      Country::Bulgaria,
    Country::Moldova,   Country::Lithuania,     Country::Iceland,     Country::Palestine, Country::Israel,
    Country::Vietnam,   Country::Monaco,        Country::Bosnia,      Country::Lebanon,   Country::Syria,
    Country::Malta,     Country::SouthAfrica,   Country::Azerbaijan,  Country::Ghana,     Country::Kazakhstan,
    Country::Maldives,  Country::Liechtenstein,
};

const std::unordered_map<Country, PeopleNames> countryToPeopleNamesMapping{
    {Country::England, englishPeopleNames},
    {Country::France, frenchPeopleNames},
    {Country::Germany, germanPeopleNames},
    {Country::Italy, italianPeopleNames},
    {Country::Poland, polishPeopleNames},
    {Country::Russia, russianPeopleNames},
    {Country::Romania, romanianPeopleNames},
    {Country::India, indianPeopleNames},
    {Country::Finland, finnishPeopleNames},
    {Country::Nepal, nepalesePeopleNames},
    {Country::Spain, spanishPeopleNames},
    {Country::Turkey, turkishPeopleNames},
    {Country::Czech, czechPeopleNames},
    {Country::Slovakia, slovakPeopleNames},
    {Country::Ukraine, ukrainianPeopleNames},
    {Country::Denmark, danishPeopleNames},
    {Country::Sweden, swedishPeopleNames},
    {Country::Usa, usaPeopleNames},
    {Country::Brazil, brazilianPeopleNames},
    {Country::Norway, norwegianPeopleNames},
    {Country::Japan, japanesePeopleNames},
    {Country::Portugal, portuguesePeopleNames},
    {Country::Hungary, hungarianPeopleNames},
    {Country::Croatia, croatianPeopleNames},
    {Country::Greece, greekPeopleNames},
    {Country::Slovenia, slovenianPeopleNames},
    {Country::Austria, austrianPeopleNames},
    {Country::Switzerland, swissPeopleNames},
    {Country::Belgium, belgianPeopleNames},
    {Country::Netherlands, dutchPeopleNames},
    {Country::China, chinesePeopleNames},
    {Country::Korea, koreanPeopleNames},
    {Country::Canada, canadianPeopleNames},
    {Country::Mexico, mexicanPeopleNames},
    {Country::Argentina, argentinianPeopleNames},
    {Country::Australia, australianPeopleNames},
    {Country::Serbia, serbianPeopleNames},
    {Country::Macedonia, macedonianPeopleNames},
    {Country::Latvia, latvianPeopleNames},
    {Country::Ireland, irishPeopleNames},
    {Country::Belarus, belarusianPeopleNames},
    {Country::Estonia, estonianPeopleNames},
    {Country::Albania, albanianPeopleNames},
    {Country::Iran, persianPeopleNames},
    {Country::Bulgaria, bulgarianPeopleNames},
    {Country::Moldova, moldovanPeopleNames},
    {Country::Lithuania, lithuanianPeopleNames},
    {Country::Iceland, icelandicPeopleNames},
    {Country::Palestine, palestinianPeopleNames},
    {Country::Israel, israeliPeopleNames},
    {Country::Vietnam, vietnamesePeopleNames},
    {Country::Monaco, monacanPeopleNames},
    {Country::Bosnia, bosnianPeopleNames},
    {Country::Lebanon, lebanesePeopleNames},
    {Country::Syria, syrianPeopleNames},
    {Country::Malta, maltesePeopleNames},
    {Country::SouthAfrica, southAfricanPeopleNames},
    {Country::Azerbaijan, azerbaijaniPeopleNames},
    {Country::Ghana, ghanaianPeopleNames},
    {Country::Kazakhstan, kazakhPeopleNames},
    {Country::Maldives, maldiviansPeopleNames},
    {Country::Liechtenstein, liechtensteinerPeopleNames},
};

const std::unordered_map<Country, std::string> generatedTestName{
    {Country::England, "shouldGenerateEnglishName"},
    {Country::France, "shouldGenerateFrenchName"},
    {Country::Germany, "shouldGenerateGermanName"},
    {Country::Italy, "shouldGenerateItalianName"},
    {Country::Poland, "shouldGeneratePolishName"},
    {Country::Russia, "shouldGenerateRussianName"},
    {Country::Romania, "shouldGenerateRomanianName"},
    {Country::India, "shouldGenerateIndianName"},
    {Country::Finland, "shouldGenerateFinnishName"},
    {Country::Nepal, "shouldGenerateNepaleseName"},
    {Country::Spain, "shouldGenerateSpanishName"},
    {Country::Turkey, "shouldGenerateTurkishName"},
    {Country::Czech, "shouldGenerateCzechName"},
    {Country::Slovakia, "shouldGenerateSlovakName"},
    {Country::Ukraine, "shouldGenerateUkrainianName"},
    {Country::Denmark, "shouldGenerateDanishName"},
    {Country::Sweden, "shouldGenerateSwedishName"},
    {Country::Usa, "shouldGenerateAmericanName"},
    {Country::Brazil, "shouldGenerateBrazilianName"},
    {Country::Norway, "shouldGenerateNorwegianName"},
    {Country::Japan, "shouldGenerateJapaneseName"},
    {Country::Portugal, "shouldGeneratePortugueseName"},
    {Country::Hungary, "shouldGenerateHungarianName"},
    {Country::Croatia, "shouldGenerateCroatianName"},
    {Country::Greece, "shouldGenerateGreekName"},
    {Country::Slovenia, "shouldGenerateSlovenianName"},
    {Country::Austria, "shouldGenerateAustrianName"},
    {Country::Switzerland, "shouldGenerateSwissName"},
    {Country::Belgium, "shouldGenerateBelgianName"},
    {Country::Netherlands, "shouldGenerateDutchName"},
    {Country::China, "shouldGenerateChineseName"},
    {Country::Korea, "shouldGenerateKoreanName"},
    {Country::Canada, "shouldGenerateCanadianName"},
    {Country::Mexico, "shouldGenerateMexicanName"},
    {Country::Argentina, "shouldGenerateArgentinianName"},
    {Country::Australia, "shouldGenerateAustralianName"},
    {Country::Serbia, "shouldGenerateSerbianName"},
    {Country::Macedonia, "shouldGenerateMacedonianName"},
    {Country::Latvia, "shouldGenerateLatvianName"},
    {Country::Ireland, "shouldGenerateIrishName"},
    {Country::Belarus, "shouldGenerateBelarusianName"},
    {Country::Estonia, "shouldGenerateEstonianName"},
    {Country::Albania, "shouldGenerateAlbanianName"},
    {Country::Iran, "shouldGeneratePersianName"},
    {Country::Bulgaria, "shouldGenerateBulgarianName"},
    {Country::Moldova, "shouldGenerateMoldovanName"},
    {Country::Lithuania, "shouldGenerateLithuanianName"},
    {Country::Iceland, "shouldGenerateIcelandicName"},
    {Country::Palestine, "shouldGeneratePalestinianName"},
    {Country::Israel, "shouldGenerateIsraeliName"},
    {Country::Vietnam, "shouldGenerateVietnameseName"},
    {Country::Monaco, "shouldGenerateMonacanName"},
    {Country::Bosnia, "shouldGenerateBosnianNames"},
    {Country::Lebanon, "shouldGenerateLebaneseName"},
    {Country::Syria, "shouldGenerateSyrianName"},
    {Country::Malta, "shouldGenerateMalteseName"},
    {Country::SouthAfrica, "shouldGenerateSouthAfricanName"},
    {Country::Azerbaijan, "shouldGenerateAzerbaijaniName"},
    {Country::Ghana, "shouldGenerateGhanaianName"},
    {Country::Kazakhstan, "shouldGenerateKazakhName"},
    {Country::Maldives, "shouldGenerateMaldivianName"},
    {Country::Liechtenstein, "shouldGenerateLichtensteinerName"},
};

}

std::string translateSex(Sex sex, Language language = Language::English)
{
    const auto sexTranslation = sexTranslations.find(language);

    if (sexTranslation == sexTranslations.end())
    {
        throw std::runtime_error{"Sex not found."};
    }

    return sexTranslation->second.at(sex);
}

bool checkTokenFormat(const std::string& bio);

class PersonTest : public TestWithParam<Country>
{
public:
    PersonTest()
    {
        initializePrefixes();

        initializeSuffixes();

        initializeMiddleNames();
    }

    void initializePrefixes()
    {
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
        {
            malesPrefixes.insert(malesPrefixes.end(), peopleNames.malesNames.prefixes.begin(),
                                 peopleNames.malesNames.prefixes.end());

            femalesPrefixes.insert(femalesPrefixes.end(), peopleNames.femalesNames.prefixes.begin(),
                                   peopleNames.femalesNames.prefixes.end());

            allPrefixes.insert(allPrefixes.end(), peopleNames.malesNames.prefixes.begin(),
                               peopleNames.malesNames.prefixes.end());
            allPrefixes.insert(allPrefixes.end(), peopleNames.femalesNames.prefixes.begin(),
                               peopleNames.femalesNames.prefixes.end());
        }
    }

    void initializeSuffixes()
    {
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
        {
            malesSuffixes.insert(malesSuffixes.end(), peopleNames.malesNames.suffixes.begin(),
                                 peopleNames.malesNames.suffixes.end());

            femalesSuffixes.insert(femalesSuffixes.end(), peopleNames.femalesNames.suffixes.begin(),
                                   peopleNames.femalesNames.suffixes.end());

            allSuffixes.insert(allSuffixes.end(), peopleNames.malesNames.suffixes.begin(),
                               peopleNames.malesNames.suffixes.end());
            allSuffixes.insert(allSuffixes.end(), peopleNames.femalesNames.suffixes.begin(),
                               peopleNames.femalesNames.suffixes.end());
        }
    }

    void initializeMiddleNames()
    {
        for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
        {
            malesMiddleNames.insert(malesMiddleNames.end(), peopleNames.malesNames.middleNames.begin(),
                                    peopleNames.malesNames.middleNames.end());

            femalesMiddleNames.insert(femalesMiddleNames.end(), peopleNames.femalesNames.middleNames.begin(),
                                      peopleNames.femalesNames.middleNames.end());

            allMiddleNames.insert(allMiddleNames.end(), peopleNames.malesNames.middleNames.begin(),
                                  peopleNames.malesNames.middleNames.end());
            allMiddleNames.insert(allMiddleNames.end(), peopleNames.femalesNames.middleNames.begin(),
                                  peopleNames.femalesNames.middleNames.end());
        }
    }

    std::vector<std::string> allPrefixes;
    std::vector<std::string> malesPrefixes;
    std::vector<std::string> femalesPrefixes;
    std::vector<std::string> allSuffixes;
    std::vector<std::string> malesSuffixes;
    std::vector<std::string> femalesSuffixes;
    std::vector<std::string> allMiddleNames;
    std::vector<std::string> malesMiddleNames;
    std::vector<std::string> femalesMiddleNames;
};

TEST_P(PersonTest, shouldGenerateFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    std::vector<std::string> firstNames{malesFirstNames};

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());

    const auto generatedFirstName = Person::firstName(country);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto generatedFirstName = Person::firstName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto generatedFirstName = Person::firstName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFirstName](const std::string& firstName)
                                    { return firstName == generatedFirstName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedLastName = Person::lastName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedLastName = Person::lastName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedLastName](const std::string& lastName)
                                    { return lastName == generatedLastName; }));
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;
    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;
    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    std::vector<std::string> firstNames{malesFirstNames};
    std::vector<std::string> lastNames{malesLastNames};

    firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());

    const auto generatedFullName = Person::fullName(country);

    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(lastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& malesFirstNames = peopleNames.malesNames.firstNames;

    const auto& malesLastNames = peopleNames.malesNames.lastNames;

    const auto generatedFullName = Person::fullName(country, Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesFirstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(malesLastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto country = GetParam();

    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

    const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

    const auto generatedFullName = Person::fullName(country, Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesFirstNames, [generatedFullName](const std::string& firstName)
                                    { return generatedFullName.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(femalesLastNames, [generatedFullName](const std::string& lastName)
                                    { return generatedFullName.find(lastName) != std::string::npos; }));
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByCountries, PersonTest, ValuesIn(countries),
                         [](const TestParamInfo<Country>& info) { return generatedTestName.at(info.param); });

TEST_F(PersonTest, shouldGenerateMiddleName)
{
    const auto generatedMiddleName = Person::middleName();

    ASSERT_TRUE(std::ranges::any_of(allMiddleNames, [generatedMiddleName](const std::string& middleName)
                                    { return middleName == generatedMiddleName; }));
}

TEST_F(PersonTest, shouldGeneratePrefix)
{
    const auto generatedPrefix = Person::prefix();

    ASSERT_TRUE(std::ranges::any_of(allPrefixes, [generatedPrefix](const std::string& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateMalePrefix)
{
    const auto generatedPrefix = Person::prefix(Sex::Male);

    ASSERT_TRUE(std::ranges::any_of(malesPrefixes, [generatedPrefix](const std::string& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = Person::prefix(Sex::Female);

    ASSERT_TRUE(std::ranges::any_of(femalesPrefixes, [generatedPrefix](const std::string& prefix)
                                    { return prefix == generatedPrefix; }));
}

TEST_F(PersonTest, shouldGenerateSuffix)
{
    const auto generatedSuffix = Person::suffix();

    ASSERT_TRUE(std::ranges::any_of(allSuffixes, [generatedSuffix](const std::string& suffix)
                                    { return suffix == generatedSuffix; }));
}

TEST_F(PersonTest, shouldGenerateSex)
{
    const auto generatedSex = Person::sex();

    ASSERT_TRUE(std::ranges::any_of(sexes, [generatedSex](const std::string& sex) { return sex == generatedSex; }));
}

TEST_F(PersonTest, shouldGenerateGender)
{
    const auto generatedGender = Person::gender();

    ASSERT_TRUE(std::ranges::any_of(genders, [generatedGender](const std::string& gender)
                                    { return gender == generatedGender; }));
}

TEST_F(PersonTest, shouldGenerateJobDescriptor)
{
    const auto generatedJobDescriptor = Person::jobDescriptor();

    ASSERT_TRUE(std::ranges::any_of(jobDescriptors, [generatedJobDescriptor](const std::string& jobDescriptor)
                                    { return jobDescriptor == generatedJobDescriptor; }));
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = Person::jobArea();

    ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string& jobArea)
                                    { return jobArea == generatedJobArea; }));
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = Person::jobType();

    ASSERT_TRUE(std::ranges::any_of(jobTypes, [generatedJobType](const std::string& jobType)
                                    { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = Person::jobTitle();

    const auto jobTitleElements = StringHelper::split(generatedJobTitle, " ");

    const auto& generatedJobDescriptor = jobTitleElements[0];
    const auto& generatedJobArea = jobTitleElements[1];
    const auto& generatedJobType = jobTitleElements[2];

    ASSERT_TRUE(std::ranges::any_of(jobDescriptors, [generatedJobDescriptor](const std::string& jobDescriptor)
                                    { return jobDescriptor == generatedJobDescriptor; }));
    ASSERT_TRUE(std::ranges::any_of(jobAreas, [generatedJobArea](const std::string& jobArea)
                                    { return jobArea == generatedJobArea; }));
    ASSERT_TRUE(std::ranges::any_of(jobTypes, [generatedJobType](const std::string& jobType)
                                    { return jobType == generatedJobType; }));
}

TEST_F(PersonTest, shouldGenerateHobby)
{
    const auto generatedHobby = Person::hobby();

    ASSERT_TRUE(
        std::ranges::any_of(hobbies, [generatedHobby](const std::string& hobby) { return hobby == generatedHobby; }));
}

TEST_F(PersonTest, shouldGenerateBio)
{
    const auto generatedBio = Person::bio();

    ASSERT_TRUE(checkTokenFormat(generatedBio));
}

TEST_F(PersonTest, shouldGenerateLanguage)
{
    const auto generatedLanguage = Person::language();

    ASSERT_TRUE(std::ranges::any_of(languages, [generatedLanguage](const std::string& language)
                                    { return generatedLanguage == language; }));
}

TEST_F(PersonTest, shouldGenerateNationality)
{
    const auto generatedNationality = Person::nationality();

    ASSERT_TRUE(std::ranges::any_of(nationalities, [generatedNationality](const std::string& nationality)
                                    { return generatedNationality == nationality; }));
}

TEST_F(PersonTest, shouldGenerateWesternZodiacs)
{
    const auto generatedWesternZodiacs = Person::westernZodiac();

    ASSERT_TRUE(std::ranges::any_of(westernZodiacs, [generatedWesternZodiacs](const std::string& westernZodiac)
                                    { return generatedWesternZodiacs == westernZodiac; }));
}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = Person::chineseZodiac();

    ASSERT_TRUE(std::ranges::any_of(chineseZodiacs, [generatedChineseZodiacs](const std::string& chineseZodiac)
                                    { return generatedChineseZodiacs == chineseZodiac; }));
}

class PersonSexSuite : public TestWithParam<std::pair<Language, Sex>>
{
};

TEST_P(PersonSexSuite, shouldTranslateSexCorrectly)
{
    const auto language = GetParam().first;
    const auto sex = GetParam().second;

    const auto expectedTranslation = sexTranslations.at(language).at(sex);
    const auto actualTranslation = translateSex(sex, language);

    ASSERT_EQ(expectedTranslation, actualTranslation);
}

std::vector<std::pair<Language, Sex>> languageSexPairs = {
    {Language::English, Sex::Male},      {Language::English, Sex::Female},   {Language::Polish, Sex::Male},
    {Language::Polish, Sex::Female},     {Language::Italian, Sex::Male},     {Language::Italian, Sex::Female},
    {Language::French, Sex::Male},       {Language::French, Sex::Female},    {Language::German, Sex::Male},
    {Language::German, Sex::Female},     {Language::Russian, Sex::Male},     {Language::Russian, Sex::Female},
    {Language::Romanian, Sex::Male},     {Language::Romanian, Sex::Female},  {Language::Hindi, Sex::Male},
    {Language::Hindi, Sex::Female},      {Language::Finnish, Sex::Male},     {Language::Finnish, Sex::Female},
    {Language::Nepali, Sex::Male},       {Language::Nepali, Sex::Female},    {Language::Spanish, Sex::Male},
    {Language::Spanish, Sex::Female},    {Language::Turkish, Sex::Male},     {Language::Turkish, Sex::Female},
    {Language::Czech, Sex::Male},        {Language::Czech, Sex::Female},     {Language::Slovak, Sex::Male},
    {Language::Slovak, Sex::Female},     {Language::Ukrainian, Sex::Male},   {Language::Ukrainian, Sex::Female},
    {Language::Danish, Sex::Male},       {Language::Danish, Sex::Female},    {Language::Swedish, Sex::Male},
    {Language::Swedish, Sex::Female},    {Language::Portuguese, Sex::Male},  {Language::Portuguese, Sex::Female},
    {Language::Norwegian, Sex::Male},    {Language::Norwegian, Sex::Female}, {Language::Japanese, Sex::Male},
    {Language::Japanese, Sex::Female},   {Language::Hungarian, Sex::Male},   {Language::Hungarian, Sex::Female},
    {Language::Croatian, Sex::Male},     {Language::Croatian, Sex::Female},  {Language::Greek, Sex::Male},
    {Language::Greek, Sex::Female},      {Language::Slovene, Sex::Male},     {Language::Slovene, Sex::Female},
    {Language::Dutch, Sex::Male},        {Language::Dutch, Sex::Female},     {Language::Mandarin, Sex::Male},
    {Language::Mandarin, Sex::Female},   {Language::Korean, Sex::Male},      {Language::Korean, Sex::Female},
    {Language::Serbian, Sex::Male},      {Language::Serbian, Sex::Female},   {Language::Macedonian, Sex::Male},
    {Language::Macedonian, Sex::Female}, {Language::Albanian, Sex::Male},    {Language::Albanian, Sex::Female},
    {Language::Latvian, Sex::Male},      {Language::Latvian, Sex::Female},   {Language::Irish, Sex::Male},
    {Language::Irish, Sex::Female},      {Language::Belarusian, Sex::Male},  {Language::Belarusian, Sex::Female},
    {Language::Estonian, Sex::Male},     {Language::Estonian, Sex::Female}};

std::string toString(Sex sex, Language language = Language::English)
{
    return translateSex(sex, language);
}

std::string toString(Language language)
{
    static const std::unordered_map<Language, std::string> languageToStringMapping{
        {Language::English, "English"},     {Language::Polish, "Polish"},         {Language::Italian, "Italian"},
        {Language::French, "French"},       {Language::German, "German"},         {Language::Russian, "Russian"},
        {Language::Romanian, "Romanian"},   {Language::Hindi, "Hindi"},           {Language::Finnish, "Finnish"},
        {Language::Nepali, "Nepali"},       {Language::Spanish, "Spanish"},       {Language::Turkish, "Turkish"},
        {Language::Czech, "Czech"},         {Language::Slovak, "Slovak"},         {Language::Ukrainian, "Ukrainian"},
        {Language::Danish, "Danish"},       {Language::Swedish, "Swedish"},       {Language::Portuguese, "Portuguese"},
        {Language::Norwegian, "Norwegian"}, {Language::Japanese, "Japanese"},     {Language::Hungarian, "Hungarian"},
        {Language::Croatian, "Croatian"},   {Language::Greek, "Greek"},           {Language::Slovene, "Slovene"},
        {Language::Dutch, "Dutch"},         {Language::Mandarin, "Mandarin"},     {Language::Korean, "Korean"},
        {Language::Serbian, "Serbian"},     {Language::Macedonian, "Macedonian"}, {Language::Albanian, "Albanian"},
        {Language::Latvian, "Latvian"},     {Language::Irish, "Irish"},           {Language::Belarusian, "Belarusian"},
        {Language::Estonian, "Estonian"}};

    return languageToStringMapping.at(language);
}

INSTANTIATE_TEST_SUITE_P(TestPersonSexTranslation, PersonSexSuite, testing::ValuesIn(languageSexPairs),
                         [](const testing::TestParamInfo<PersonSexSuite::ParamType>& info)
                         {
                             auto param = info.param;
                             return toString(param.first) + "_" + toString(param.second);
                         });

const std::unordered_map<SsnCountry, unsigned> ssnLengths{
    {SsnCountry::Poland, 11},  {SsnCountry::UnitedStates, 11}, {SsnCountry::UnitedKingdom, 13},
    {SsnCountry::Germany, 12}, {SsnCountry::France, 19},       {SsnCountry::Italy, 19},
    {SsnCountry::Spain, 10},   {SsnCountry::India, 10},
};

class PersonSsnSuite : public TestWithParam<SsnCountry>
{
};

TEST_P(PersonSsnSuite, shouldGenerateSsn)
{
    const auto country = GetParam();

    const auto ssn = Person::ssn(country);

    const auto expectedSsnLength = ssnLengths.at(country);

    ASSERT_EQ(ssn.size(), expectedSsnLength);
}

std::string toString(SsnCountry country)
{
    std::unordered_map<SsnCountry, std::string> countryToStringMapping{
        {SsnCountry::UnitedStates, "UnitedStates"},
        {SsnCountry::UnitedKingdom, "UnitedKingdom"},
        {SsnCountry::Poland, "Poland"},
        {SsnCountry::Italy, "Italy"},
        {SsnCountry::France, "France"},
        {SsnCountry::Germany, "Germany"},
        {SsnCountry::India, "India"},
        {SsnCountry::Spain, "Spain"},
    };

    return countryToStringMapping.at(country);
}

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite, testing::ValuesIn(supportedSsnCountries),
                         [](const testing::TestParamInfo<PersonSsnSuite::ParamType>& info)
                         { return "shouldGenerate" + toString(info.param) + "Ssn"; });

class PersonPassportTest : public Test
{
public:
};

TEST_F(PersonPassportTest, shouldGenerateUsaPassport)
{
    const auto passportNumber = Person::passport(PassportCountry::Usa);

    ASSERT_EQ(passportNumber.size(), 9);
    ASSERT_TRUE(std::isalpha(passportNumber[0]));
    ASSERT_TRUE(std::isalpha(passportNumber[1]));
    ASSERT_TRUE(std::isdigit(passportNumber[2]));
    ASSERT_TRUE(std::isdigit(passportNumber[3]));
    ASSERT_TRUE(std::isdigit(passportNumber[4]));
    ASSERT_TRUE(std::isdigit(passportNumber[5]));
    ASSERT_TRUE(std::isdigit(passportNumber[6]));
    ASSERT_TRUE(std::isdigit(passportNumber[7]));
    ASSERT_TRUE(std::isdigit(passportNumber[8]));
}

TEST_F(PersonPassportTest, shouldGeneratePolandPassport)
{
    const auto passportNumber = Person::passport(PassportCountry::Poland);

    ASSERT_EQ(passportNumber.size(), 9);
    ASSERT_TRUE(std::isalpha(passportNumber[0]));
    ASSERT_TRUE(std::isalpha(passportNumber[1]));
    ASSERT_TRUE(std::isdigit(passportNumber[2]));
    ASSERT_TRUE(std::isdigit(passportNumber[3]));
    ASSERT_TRUE(std::isdigit(passportNumber[4]));
    ASSERT_TRUE(std::isdigit(passportNumber[5]));
    ASSERT_TRUE(std::isdigit(passportNumber[6]));
    ASSERT_TRUE(std::isdigit(passportNumber[7]));
    ASSERT_TRUE(std::isdigit(passportNumber[8]));
}

TEST_F(PersonPassportTest, shouldGenerateFrenchPassport)
{
    const auto passportNumber = Person::passport(PassportCountry::France);

    ASSERT_EQ(passportNumber.size(), 9);
    ASSERT_TRUE(std::isdigit(passportNumber[0]));
    ASSERT_TRUE(std::isdigit(passportNumber[1]));
    ASSERT_TRUE(std::isalpha(passportNumber[2]));
    ASSERT_TRUE(std::isalpha(passportNumber[3]));
    ASSERT_TRUE(std::isdigit(passportNumber[4]));
    ASSERT_TRUE(std::isdigit(passportNumber[5]));
    ASSERT_TRUE(std::isdigit(passportNumber[6]));
    ASSERT_TRUE(std::isdigit(passportNumber[7]));
    ASSERT_TRUE(std::isdigit(passportNumber[8]));
}

TEST_F(PersonPassportTest, shouldGenerateRomanianPassport)
{
    const auto passportNumber = Person::passport(PassportCountry::Romania);
    ASSERT_EQ(passportNumber.size(), 8);
    ASSERT_TRUE(std::isdigit(passportNumber[0]));
    ASSERT_TRUE(std::isdigit(passportNumber[1]));
    ASSERT_TRUE(std::isdigit(passportNumber[2]));
    ASSERT_TRUE(std::isdigit(passportNumber[3]));
    ASSERT_TRUE(std::isdigit(passportNumber[4]));
    ASSERT_TRUE(std::isdigit(passportNumber[5]));
    ASSERT_TRUE(std::isdigit(passportNumber[6]));
    ASSERT_TRUE(std::isdigit(passportNumber[7]));
}

bool checkTokenFormat(const std::string& bio)
{
    const std::regex firstRegex{R"(^(\w+\s?\w+)$)"};
    const std::regex secondRegex{R"(^(\w+\s?\w+), (\w+\s?\w+)$)"};
    const std::regex thirdRegex{R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+)$)"};
    const std::regex fourthRegex{R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+), (\S+)$)"};
    const std::regex fifthRegex{R"(^(\w+\-?\w+) (\w+)$)"};
    const std::regex sixthRegex{R"(^(\w+\-?\w+) (\w+) (\S+)$)"};
    const std::regex seventhRegex{R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+)$)"};
    const std::regex eightRegex{R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+) (\S+)$)"};

    std::smatch matches;
    //
    if (std::regex_match(bio, matches, firstRegex))
    {
        // In this case the bio is in the format {bio_part} so check that the value is present in the bio_part
        // vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[0]) != bioPart.end())
            return true;
    }

    if (std::regex_match(bio, matches, secondRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part} so check that the value is present in the
        // bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end())
            return true;
    }

    if (std::regex_match(bio, matches, thirdRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part} so check that the value is
        // present in the bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end())
            return true;
    }

    if (std::regex_match(bio, matches, fourthRegex))
    {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part}, {emoji} so check that the value
        // is present in the bio_part vector.
        if (std::find(bioPart.begin(), bioPart.end(), matches[1]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[2]) != bioPart.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end() &&
            Internet::checkIfEmojiIsValid(matches[4]))
            return true;
    }

    if (std::regex_match(bio, matches, fifthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end())
            return true;
    }

    if (std::regex_match(bio, matches, sixthRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter} {emoji} so check that the value is present
        // in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            Internet::checkIfEmojiIsValid(matches[3]))
            return true;
    }

    if (std::regex_match(bio, matches, seventhRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} so check that the value is
        // present in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end())
            return true;
    }

    if (std::regex_match(bio, matches, eightRegex))
    {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} {emoji} so check that the value
        // is present in the bio_part vector.
        if (std::find(nouns.begin(), nouns.end(), matches[1]) != nouns.end() &&
            std::find(bioSupporter.begin(), bioSupporter.end(), matches[2]) != bioSupporter.end() &&
            std::find(bioPart.begin(), bioPart.end(), matches[3]) != bioPart.end() &&
            Internet::checkIfEmojiIsValid(matches[4]))
            return true;
    }

    return false;
}
