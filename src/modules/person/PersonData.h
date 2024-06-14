#pragma once

#include <array>
#include <span>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "faker-cxx/Person.h"

namespace faker
{
extern const std::array<std::string_view, 41> bioParts;
extern const std::array<std::string_view, 7> bioSupporters;
extern const std::array<std::string_view, 8> bioFormats;
extern const std::array<std::string_view, 76> genders;
extern const std::array<std::string_view, 44> hobbies;
extern const std::array<std::string_view, 25> jobDescriptors;
extern const std::array<std::string_view, 38> jobAreas;
extern const std::array<std::string_view, 25> jobTypes;
extern const std::array<std::string_view, 18> languages;

struct NameFormat
{
    std::string_view format;
    unsigned weight;
};

using NameFormats = std::vector<NameFormat>;

extern const std::array<std::string_view, 62> nationalities;

struct PersonNames
{
    std::span<const std::string_view> firstNames;
    std::span<const std::string_view> lastNames;
    std::span<const std::string_view> prefixes;
    std::span<const std::string_view> suffixes;
};

struct PeopleNames
{
    PersonNames malesNames;
    PersonNames femalesNames;
    NameFormats nameFormats;
};

extern const std::unordered_map<SsnCountry, std::string_view> ssnFormats;
extern const std::array<std::string_view, 12> westernZodiacs;
extern const std::array<std::string_view, 11> chineseZodiacs;
extern const std::unordered_map<Language, std::unordered_map<Sex, std::string_view>> sexTranslations;
extern const std::array<SsnCountry, 8> supportedSsnCountries;

// Albania

extern const std::array<std::string_view, 157> albanianMaleFirstNames;
extern const std::array<std::string_view, 141> albanianFemaleFirstNames;
extern const std::array<std::string_view, 140> albanianLastNames;
extern const NameFormats albanianPersonNameFormats;
extern const PeopleNames albanianPeopleNames;

// Argentina

extern const std::array<std::string_view, 350> argentinianMaleFirstNames;
extern const std::array<std::string_view, 350> argentinianFemaleFirstNames;
extern const std::array<std::string_view, 348> argentinianLastNames;
extern const NameFormats argentinianNameFormats;
extern const PeopleNames argentinianPeopleNames;

// Australia

extern const std::array<std::string_view, 100> australianMaleFirstNames;
extern const std::array<std::string_view, 100> australianFemaleFirstNames;
extern const std::array<std::string_view, 286> australianLastNames;
extern const NameFormats australianNameFormats;
extern const PeopleNames australianPeopleNames;

// Austria

extern const std::array<std::string_view, 572> austrianMaleFirstNames;
extern const std::array<std::string_view, 573> austrianFemaleFirstNames;
extern const std::array<std::string_view, 1688> austrianLastNames;
extern const std::array<std::string_view, 3> austrianMalePrefixes;
extern const std::array<std::string_view, 3> austrianFemalePrefixes;
extern const NameFormats austrianNameFormats;
extern const PeopleNames austrianPeopleNames;

// Azerbaijan

extern const std::array<std::string_view, 35> azerbaijaniMaleFirstNames;
extern const std::array<std::string_view, 73> azerbaijaniFemaleFirstNames;
extern const std::array<std::string_view, 10> azerbaijaniMaleLastNames;
extern const std::array<std::string_view, 10> azerbaijaniFemaleLastNames;
extern const NameFormats azerbaijaniNameFormats;
extern const PeopleNames azerbaijaniPeopleNames;

// Belarus

extern const std::array<std::string_view, 350> belarusianMaleFirstNames;
extern const std::array<std::string_view, 350> belarusianFemaleFirstNames;
extern const std::array<std::string_view, 261> belarusianMaleLastNames;
extern const std::array<std::string_view, 89> belarusianFemaleLastNames;
extern const NameFormats belarusianNameFormats;
extern const PeopleNames belarusianPeopleNames;

// Belgium

extern const std::array<std::string_view, 100> belgianMaleFirstNames;
extern const std::array<std::string_view, 99> belgianFemaleFirstNames;
extern const std::array<std::string_view, 32> belgianLastNames;
extern const std::array<std::string_view, 2> belgianSuffixes;
extern const std::array<std::string_view, 4> belgianPrefixes;
extern const NameFormats belgianNameFormats;
extern const PeopleNames belgianPeopleNames;

// Bosnia

extern const std::array<std::string_view, 100> bosnianMaleFirstNames;
extern const std::array<std::string_view, 100> bosnianFemaleFirstNames;
extern const std::array<std::string_view, 128> bosnianLastNames;
extern const NameFormats bosnianNameFormats;
extern const PeopleNames bosnianPeopleNames;

// Brazil

extern const std::array<std::string_view, 88> brazilianMaleFirstNames;
extern const std::array<std::string_view, 80> brazilianFemaleFirstNames;
extern const std::array<std::string_view, 21> brazilianLastNames;
extern const std::array<std::string_view, 3> brazilianSuffixes;
extern const std::array<std::string_view, 2> brazilianMalePrefixes;
extern const std::array<std::string_view, 3> brazilianFemalePrefixes;
extern const NameFormats brazilianNameFormats;
extern const PeopleNames brazilianPeopleNames;

// Bulgaria

extern const std::array<std::string_view, 30> bulgarianMaleFirstNames;
extern const std::array<std::string_view, 32> bulgarianFemaleFirstNames;
extern const std::array<std::string_view, 25> bulgarianLastNames;
extern const std::array<std::string_view, 2> bulgarianSuffixes;
extern const std::array<std::string_view, 3> bulgarianMalePrefixes;
extern const std::array<std::string_view, 4> bulgarianFemalePrefixes;
extern const NameFormats bulgarianNameFormats;
extern const PeopleNames bulgarianPeopleNames;

// Canada

extern const std::array<std::string_view, 350> canadianMaleFirstNames;
extern const std::array<std::string_view, 350> canadianFemaleFirstNames;
extern const std::array<std::string_view, 346> canadianLastNames;
extern const NameFormats canadianNameFormats;
extern const PeopleNames canadianPeopleNames;

// China

extern const std::array<std::string_view, 1000> chineseLastNames;
extern const std::array<std::string_view, 78> chineseMaleFirstNames;
extern const std::array<std::string_view, 85> chineseFemaleFirstNames;
extern const NameFormats chineseNameFormats;
extern const PeopleNames chinesePeopleNames;

// Croatia

extern const std::array<std::string_view, 171> croatianMaleFirstNames;
extern const std::array<std::string_view, 238> croatianFemaleFirstNames;
extern const std::array<std::string_view, 210> croatianLastNames;
extern const std::array<std::string_view, 2> croatianSuffixes;
extern const std::array<std::string_view, 2> croatianMalePrefixes;
extern const std::array<std::string_view, 3> croatianFemalePrefixes;
extern const NameFormats croatianNameFormats;
extern const PeopleNames croatianPeopleNames;

// Czechia

// TODO: remove some of it
extern const std::array<std::string_view, 795> czechMaleFirstNames;
extern const std::array<std::string_view, 785> czechFemaleFirstNames;
extern const std::array<std::string_view, 999> czechMaleLastNames;
extern const std::array<std::string_view, 991> czechFemaleLastNames;
extern const std::array<std::string_view, 4> czechPrefixes;
extern const std::array<std::string_view, 1> czechSuffixes;
extern const NameFormats czechNameFormats;
extern const PeopleNames czechPeopleNames;

// Denmark

extern const std::array<std::string_view, 118> danishMaleFirstNames;
extern const std::array<std::string_view, 109> danishFemaleFirstNames;
extern const std::array<std::string_view, 106> danishLastNames;
extern const std::array<std::string_view, 1> danishMalePrefixes;
extern const std::array<std::string_view, 1> danishFemalePrefixes;
extern const NameFormats danishNameFormats;
extern const PeopleNames danishPeopleNames;

// Dutch

extern const std::array<std::string_view, 587> dutchMaleFirstNames;
extern const std::array<std::string_view, 514> dutchFemaleFirstNames;
extern const std::array<std::string_view, 131> dutchLastNames;
extern const std::array<std::string_view, 2> dutchSuffixes;
extern const std::array<std::string_view, 7> dutchMalePrefixes;
extern const std::array<std::string_view, 7> dutchFemalePrefixes;
extern const NameFormats dutchNameFormats;
extern const PeopleNames dutchPeopleNames;

// England

extern const std::array<std::string_view, 500> englishMaleFirstNames;
extern const std::array<std::string_view, 500> englishFemaleFirstNames;
extern const std::array<std::string_view, 463> englishLastNames;
extern const std::array<std::string_view, 11> englishSuffixes;
extern const std::array<std::string_view, 2> englishMalePrefixes;
extern const std::array<std::string_view, 4> englishFemalePrefixes;
extern const NameFormats englishNameFormats;
extern const PeopleNames englishPeopleNames;

// Estonia

extern const std::array<std::string_view, 350> estonianMaleFirstNames;
extern const std::array<std::string_view, 350> estonianFemaleFirstNames;
extern const std::array<std::string_view, 350> estonianLastNames;
extern const NameFormats estonianNameFormats;
extern const PeopleNames estonianPeopleNames;

// Finland

extern const std::array<std::string_view, 45> finnishMaleFirstNames;
extern const std::array<std::string_view, 46> finnishFemaleFirstNames;
extern const std::array<std::string_view, 46> finnishLastNames;
extern const NameFormats finnishNameFormats;
extern const PeopleNames finnishPeopleNames;

// France

extern const std::array<std::string_view, 496> frenchMaleFirstNames;
extern const std::array<std::string_view, 451> frenchFemaleFirstNames;
extern const std::array<std::string_view, 150> frenchLastNames;
extern const std::array<std::string_view, 3> frenchMalePrefixes;
extern const std::array<std::string_view, 4> frenchFemalePrefixes;
extern const NameFormats frenchNameFormats;
extern const PeopleNames frenchPeopleNames;

// Germany

extern const std::array<std::string_view, 572> germanMaleFirstNames;
extern const std::array<std::string_view, 583> germanFemaleFirstNames;
extern const std::array<std::string_view, 300> germanLastNames;
extern const std::array<std::string_view, 3> germanMalePrefixes;
extern const std::array<std::string_view, 3> germanFemalePrefixes;
extern const NameFormats germanNameFormats;
extern const PeopleNames germanPeopleNames;

// Ghana

extern const std::array<std::string_view, 132> ghanaianMaleFirstNames;
extern const std::array<std::string_view, 132> ghanaianFemaleFirstNames;
extern const std::array<std::string_view, 120> ghanaianLastNames;
extern const NameFormats ghanaianNameFormats;
extern const PeopleNames ghanaianPeopleNames;

// Greece

extern const std::array<std::string_view, 350> greekMaleFirstNames;
extern const std::array<std::string_view, 350> greekFemaleFirstNames;
extern const std::array<std::string_view, 350> greekLastNames;
extern const NameFormats greekNameFormats;
extern const PeopleNames greekPeopleNames;

// Hungary

extern const std::array<std::string_view, 100> hungarianMaleFirstNames;
extern const std::array<std::string_view, 100> hungarianFemaleFirstNames;
extern const std::array<std::string_view, 100> hungarianLastNames;
extern const std::array<std::string_view, 2> hungarianPrefixes;
extern const NameFormats hungarianNameFormats;
extern const PeopleNames hungarianPeopleNames;

// Iceland

extern const std::array<std::string_view, 157> icelandicMaleFirstNames;
extern const std::array<std::string_view, 141> icelandicFemaleFirstNames;
extern const std::array<std::string_view, 140> icelandicLastNames;
extern const NameFormats icelandic_personNameFormats;
extern const PeopleNames icelandicPeopleNames;

// India

extern const std::array<std::string_view, 351> indianMaleFirstNames;
extern const std::array<std::string_view, 228> indianFemaleFirstNames;
extern const std::array<std::string_view, 184> indianLastNames;
extern const NameFormats indianNameFormats;
extern const PeopleNames indianPeopleNames;

// Ireland

extern const std::array<std::string_view, 350> irishMaleFirstNames;
extern const std::array<std::string_view, 350> irishFemaleFirstNames;
extern const std::array<std::string_view, 350> irishLastNames;
extern const std::array<std::string_view, 11> irishSuffixes;
extern const std::array<std::string_view, 2> irishMalePrefixes;
extern const std::array<std::string_view, 4> irishFemalePrefixes;
extern const NameFormats irishNameFormats;
extern const PeopleNames irishPeopleNames;

// Israel

extern const std::array<std::string_view, 297> israelisMaleFirstNames;
extern const std::array<std::string_view, 297> israelisFemaleFirstNames;
extern const std::array<std::string_view, 270> israelisLastNames;
extern const NameFormats israelisNameFormats;
extern const PeopleNames israeliPeopleNames;

// Italy

extern const std::array<std::string_view, 600> italianMaleFirstNames;
extern const std::array<std::string_view, 617> italianFemaleFirstNames;
extern const std::array<std::string_view, 600> italianLastNames;
extern const std::array<std::string_view, 4> italianPrefixes;
extern const NameFormats italianNameFormats;
extern const PeopleNames italianPeopleNames;

// Japan

extern const std::array<std::string_view, 135> japaneseMaleFirstNames;
extern const std::array<std::string_view, 145> japaneseFemaleFirstNames;
extern const std::array<std::string_view, 20> japaneseLastNames;
extern const NameFormats japaneseNameFormats;
extern const PeopleNames japanesePeopleNames;

// Kazakhstan

extern const std::array<std::string_view, 200> kazakhMaleFirstNames;
extern const std::array<std::string_view, 121> kazakhFemaleFirstNames;
extern const std::array<std::string_view, 21> kazakhMaleLastNames;
extern const std::array<std::string_view, 18> kazakhFemaleLastNames;
extern const NameFormats kazakh_personNameFormats;
extern const PeopleNames kazakhPeopleNames;

// Korea

extern const std::array<std::string_view, 100> koreanMaleFirstNames;
extern const std::array<std::string_view, 112> koreanLastNames;
extern const NameFormats koreanNameFormats;
extern const PeopleNames koreanPeopleNames;

// Latvia

extern const std::array<std::string_view, 91> latvianMaleFirstNames;
extern const std::array<std::string_view, 105> latvianFemaleFirstNames;
extern const std::array<std::string_view, 206> latvianMaleLastNames;
extern const std::array<std::string_view, 207> latvianFemaleLastNames;
extern const std::array<std::string_view, 2> latvianSuffixes;
extern const std::array<std::string_view, 3> latvianPrefixes;
extern const NameFormats latvianNameFormats;
extern const PeopleNames latvianPeopleNames;

// Lebanon

extern const std::array<std::string_view, 700> lebaneseMaleFirstNames;
extern const std::array<std::string_view, 350> lebaneseFemaleFirstNames;
extern const std::array<std::string_view, 350> lebaneseLastNames;
extern const NameFormats lebaneseNameFormats;
extern const PeopleNames lebanesePeopleNames;

// Lithuania

extern const std::array<std::string_view, 350> lithuanianMaleFirstNames;
extern const std::array<std::string_view, 350> lithuanianFemaleFirstNames;
extern const std::array<std::string_view, 350> lithuanianLastNames;
extern const NameFormats lithuanianNameFormats;
extern const PeopleNames lithuanianPeopleNames;

// Macedonia

extern const std::array<std::string_view, 283> macedonianMaleFirstNames;
extern const std::array<std::string_view, 232> macedonianFemaleFirstNames;
extern const std::array<std::string_view, 493> macedonianMaleLastNames;
extern const std::array<std::string_view, 495> macedonianFemaleLastNames;
extern const std::array<std::string_view, 3> macedonianMalePrefixes;
extern const std::array<std::string_view, 4> macedonianFemalePrefixes;
extern const NameFormats macedonianNameFormats;
extern const PeopleNames macedonianPeopleNames;

// Maldives

extern const std::array<std::string_view, 14> maldiviansMaleFirstNames;
extern const std::array<std::string_view, 49> maldiviansFemaleFirstNames;
extern const std::array<std::string_view, 112> maldiviansMaleLastNames;
extern const std::array<std::string_view, 248> maldiviansFemaleLastNames;
extern const std::array<std::string_view, 4> maldiviansMalePrefixes;
extern const std::array<std::string_view, 4> maldiviansFemalePrefixes;
extern const NameFormats maldiviansNameFormats;
extern const PeopleNames maldiviansPeopleNames;

// Malta

extern const std::array<std::string_view, 100> malteseMaleFirstNames;
extern const std::array<std::string_view, 100> malteseFemaleFirstNames;
extern const std::array<std::string_view, 100> malteseLastNames;
extern const NameFormats malteseNameFormats;
extern const PeopleNames maltesePeopleNames;

// Mexico

extern const std::array<std::string_view, 139> mexicanMaleFirstNames;
extern const std::array<std::string_view, 161> mexicanFemaleFirstNames;
extern const std::array<std::string_view, 687> mexicanLastNames;
extern const std::array<std::string_view, 15> mexicanSuffixes;
extern const std::array<std::string_view, 1> mexicanMalePrefixes;
extern const std::array<std::string_view, 2> mexicanFemalePrefixes;
extern const NameFormats mexicanNameFormats;
extern const PeopleNames mexicanPeopleNames;

// Moldova

extern const std::array<std::string_view, 350> moldovanMaleFirstNames;
extern const std::array<std::string_view, 350> moldovanFemaleFirstNames;
extern const std::array<std::string_view, 350> moldovanLastNames;
extern const NameFormats moldovanNameFormats;
extern const PeopleNames moldovanPeopleNames;

// Monaco

extern const std::array<std::string_view, 201> monacanMaleFirstNames;
extern const std::array<std::string_view, 350> monacanFemaleFirstNames;
extern const std::array<std::string_view, 326> monacanLastNames;
extern const NameFormats monacanNameFormats;
extern const PeopleNames monacanPeopleNames;

// Nepal

extern const std::array<std::string_view, 104> nepaleseMaleFirstNames;
extern const std::array<std::string_view, 99> nepaleseFemaleFirstNames;
extern const std::array<std::string_view, 64> nepaleseLastNames;
extern const NameFormats nepaleseNameFormats;
extern const PeopleNames nepalesePeopleNames;

// Norway

extern const std::array<std::string_view, 50> norwegianMaleFirstNames;
extern const std::array<std::string_view, 50> norwegianFemaleFirstNames;
extern const std::array<std::string_view, 100> norwegianLastNames;
extern const std::array<std::string_view, 7> norwegianSuffixes;
extern const std::array<std::string_view, 2> norwegianPrefixes;
extern const NameFormats norwegianNameFormats;
extern const PeopleNames norwegianPeopleNames;

// Palestine

extern const std::array<std::string_view, 299> palestinianMaleFirstNames;
extern const std::array<std::string_view, 350> palestinianFemaleFirstNames;
extern const std::array<std::string_view, 305> palestinianLastNames;
extern const NameFormats palestinianNameFormats;
extern const PeopleNames palestinianPeopleNames;

// Persian

extern const std::array<std::string_view, 61> persianMaleFirstNames;
extern const std::array<std::string_view, 65> persianFemaleFirstNames;
extern const std::array<std::string_view, 111> persianLastNames;
extern const std::array<std::string_view, 3> persianMalePrefixes;
extern const std::array<std::string_view, 3> persianFemalePrefixes;
extern const NameFormats persianNameFormats;
extern const PeopleNames persianPeopleNames;

// Poland

extern const std::array<std::string_view, 230> polishMaleFirstNames;
extern const std::array<std::string_view, 163> polishFemaleFirstNames;
extern const std::array<std::string_view, 712> polishLastNames;
extern const std::array<std::string_view, 1> polishMalePrefixes;
extern const std::array<std::string_view, 1> polishFemalePrefixes;
extern const NameFormats polishNameFormats;
extern const PeopleNames polishPeopleNames;

// Portugal

extern const std::array<std::string_view, 95> portugueseMaleFirstNames;
extern const std::array<std::string_view, 93> portugueseFemaleFirstNames;
extern const std::array<std::string_view, 101> portugueseLastNames;
extern const std::array<std::string_view, 4> portugueseMalePrefixes;
extern const std::array<std::string_view, 4> portugueseFemalePrefixes;
extern const NameFormats portugueseNameFormats;
extern const PeopleNames portuguesePeopleNames;

// Romania

extern const std::array<std::string_view, 65> romanianMaleFirstNames;
extern const std::array<std::string_view, 63> romanianFemaleFirstNames;
extern const std::array<std::string_view, 101> romanianLastNames;
extern const std::array<std::string_view, 2> romanianSuffixes;
extern const std::array<std::string_view, 2> romanianMalePrefixes;
extern const NameFormats romanianNameFormats;
extern const PeopleNames romanianPeopleNames;

// Russia

extern const std::array<std::string_view, 200> russianMaleFirstNames;
extern const std::array<std::string_view, 110> russianFemaleFirstNames;
extern const std::array<std::string_view, 568> russianMaleLastNames;
extern const std::array<std::string_view, 562> russianFemaleLastNames;
extern const NameFormats russianNameFormats;
extern const PeopleNames russianPeopleNames;

// Serbia

extern const std::array<std::string_view, 200> serbianMaleFirstNames;
extern const std::array<std::string_view, 200> serbianFemaleFirstNames;
extern const std::array<std::string_view, 200> serbianLastNames;
extern const NameFormats serbianNameFormats;
extern const PeopleNames serbianPeopleNames;

// Slovakia

extern const std::array<std::string_view, 192> slovakMaleFirstNames;
extern const std::array<std::string_view, 200> slovakFemaleFirstNames;
extern const std::array<std::string_view, 257> slovakMaleLastNames;
extern const std::array<std::string_view, 251> slovak_femalesLastNames;
extern const std::array<std::string_view, 1> slovakSuffixes;
extern const std::array<std::string_view, 4> slovakPrefixes;
extern const NameFormats slovakNameFormats;
extern const PeopleNames slovakPeopleNames;

// Slovenia

extern const std::array<std::string_view, 350> slovenianMaleFirstNames;
extern const std::array<std::string_view, 350> slovenianFemaleFirstNames;
extern const std::array<std::string_view, 350> slovenianLastNames;
extern const NameFormats slovenianNameFormats;
extern const PeopleNames slovenianPeopleNames;

// South Africa

extern const std::array<std::string_view, 113> southAfricanMaleFirstNames;
extern const std::array<std::string_view, 107> southAfricanFemaleFirstNames;
extern const std::array<std::string_view, 162> southAfricanLastNames;
extern const NameFormats southAfricanNameFormats;
extern const PeopleNames southAfricanPeopleNames;

// Spain

extern const std::array<std::string_view, 113> spanishMaleFirstNames;
extern const std::array<std::string_view, 147> spanishFemaleFirstNames;
extern const std::array<std::string_view, 625> spanishLastNames;
extern const std::array<std::string_view, 1> spanishMalePrefixes;
extern const std::array<std::string_view, 2> spanishFemalePrefixes;
extern const NameFormats spanishNameFormats;
extern const PeopleNames spanishPeopleNames;

// Sweden

extern const std::array<std::string_view, 100> swedishMaleFirstNames;
extern const std::array<std::string_view, 100> swedishFemaleFirstNames;
extern const std::array<std::string_view, 100> swedishLastNames;
extern const std::array<std::string_view, 3> swedishPrefixes;
extern const NameFormats swedishNameFormats;
extern const PeopleNames swedishPeopleNames;

// Switzerland

extern const std::array<std::string_view, 179> swissMaleFirstNames;
extern const std::array<std::string_view, 138> swissFemaleFirstNames;
extern const std::array<std::string_view, 209> swissLastNames;
extern const std::array<std::string_view, 3> swissMalePrefixes;
extern const std::array<std::string_view, 3> swissFemalePrefixes;
extern const NameFormats swissNameFormats;
extern const PeopleNames swissPeopleNames;

// Syria

extern const std::array<std::string_view, 350> syrianMaleFirstNames;
extern const std::array<std::string_view, 350> syrianFemaleFirstNames;
extern const std::array<std::string_view, 350> syrianLastNames;
extern const NameFormats syrianNameFormats;
extern const PeopleNames syrianPeopleNames;

// Turkey

extern const std::array<std::string_view, 44> turkishMaleFirstNames;
extern const std::array<std::string_view, 43> turkishFemaleFirstNames;
extern const std::array<std::string_view, 52> turkishLastNames;
extern const std::array<std::string_view, 3> turkishMalePrefixes;
extern const std::array<std::string_view, 3> turkishFemalePrefixes;
extern const NameFormats turkish_personNameFormats;
extern const PeopleNames turkishPeopleNames;

// Ukraine

extern const std::array<std::string_view, 195> ukrainianMaleFirstNames;
extern const std::array<std::string_view, 192> ukrainianFemaleFirstNames;
extern const std::array<std::string_view, 239> ukrainianMalesLastNames;
extern const std::array<std::string_view, 230> ukrainianFemaleLastNames;
extern const std::array<std::string_view, 1> ukrainianMalePrefixes;
extern const std::array<std::string_view, 1> ukrainianFemalePrefixes;
extern const NameFormats ukrainianNameFormats;
extern const PeopleNames ukrainianPeopleNames;

// USA

extern const NameFormats usaNameFormats;
extern const PeopleNames usaPeopleNames;

// Vietnam

extern const std::array<std::string_view, 200> vietnameseMaleFirstNames;
extern const std::array<std::string_view, 200> vietnameseFemaleFirstNames;
extern const std::array<std::string_view, 27> vietnameseLastNames;
extern const NameFormats vietnameseNameFormats;
extern const PeopleNames vietnamesePeopleNames;

}
