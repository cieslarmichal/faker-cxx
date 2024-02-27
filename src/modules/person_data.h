#ifndef FAKER_MODULES_PERSON_DATA_H
#define FAKER_MODULES_PERSON_DATA_H

#include "../common/span.h"
#include <array>
#include <faker/person.h>
#include <faker/types/country.h>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace faker::person::data {
extern const std::array<std::string_view, 41> bioPart;
extern const std::array<std::string_view, 7> bioSupporter;
extern const std::array<std::string_view, 8> bioFormats;
extern const std::array<std::string_view, 76> genders;
extern const std::array<std::string_view, 44> hobbies;
extern const std::array<std::string_view, 25> jobDescriptors;
extern const std::array<std::string_view, 38> jobAreas;
extern const std::array<std::string_view, 25> jobTypes;
extern const std::array<std::string_view, 18> languages;

struct NameFormat {
    std::string_view format;
    unsigned weight;
};

using NameFormats = std::vector<NameFormat>;

extern const std::array<std::string_view, 62> nationalities;

struct PersonNames {
    tcb::span<const std::string_view> firstNames;
    tcb::span<const std::string_view> middleNames;
    tcb::span<const std::string_view> lastNames;
    tcb::span<const std::string_view> prefixes;
    tcb::span<const std::string_view> suffixes;
};

struct PeopleNames {
    PersonNames malesNames;
    PersonNames femalesNames;
    NameFormats nameFormats;
};

extern const std::unordered_map<SsnCountry, std::string_view> ssnFormats;
extern const std::array<std::string_view, 12> westernZodiacs;
extern const std::array<std::string_view, 11> chineseZodiacs;
extern const std::unordered_map<Language, std::unordered_map<Sex, std::string_view>>
    sexTranslations;
extern const std::array<SsnCountry, 8> supportedSsnCountries;
extern const std::unordered_map<SsnCountry, unsigned> ssnLengths;

// Albania

extern const std::array<std::string_view, 157> albanianMalesFirstNames;
extern const std::array<std::string_view, 141> albanianFemalesFirstNames;
extern const std::array<std::string_view, 140> albanianLastNames;
extern const NameFormats albanianPersonNameFormats;
extern const PeopleNames albanianPeopleNames;

// Argentina

extern const std::array<std::string_view, 350> argentinianMalesFirstNames;
extern const std::array<std::string_view, 350> argentinianFemalesFirstNames;
extern const std::array<std::string_view, 348> argentinianLastNames;
extern const NameFormats argentinianPersonNameFormats;
extern const PeopleNames argentinianPeopleNames;

// Australia

extern const std::array<std::string_view, 100> australianMalesFirstNames;
extern const std::array<std::string_view, 100> australianFemalesFirstNames;
extern const std::array<std::string_view, 286> australianLastNames;
extern const NameFormats australianPersonNameFormats;
extern const PeopleNames australianPeopleNames;

// Austria

extern const std::array<std::string_view, 572> austrianMalesFirstNames;
extern const std::array<std::string_view, 573> austrianFemalesFirstNames;
extern const std::array<std::string_view, 1688> austrianLastNames;
extern const std::array<std::string_view, 3> austrianMalesPrefixes;
extern const std::array<std::string_view, 3> austrianFemalesPrefixes;
extern const NameFormats austrianPersonNameFormats;
extern const PeopleNames austrianPeopleNames;

// Azerbaijan

extern const std::array<std::string_view, 35> azerbaijaniMalesFirstNames;
extern const std::array<std::string_view, 73> azerbaijaniFemalesFirstNames;
extern const std::array<std::string_view, 10> azerbaijaniMalesLastNames;
extern const std::array<std::string_view, 10> azerbaijaniFemalesLastNames;
extern const NameFormats azerbaijaniPersonNameFormats;
extern const PeopleNames azerbaijaniPeopleNames;

// Belarus

extern const std::array<std::string_view, 350> belarusianMalesFirstNames;
extern const std::array<std::string_view, 350> belarusianFemalesFirstNames;
extern const std::array<std::string_view, 261> belarusianMalesLastNames;
extern const std::array<std::string_view, 89> belarusianFemalesLastNames;
extern const NameFormats belarusianPersonNameFormats;
extern const PeopleNames belarusianPeopleNames;

// Belgium

extern const std::array<std::string_view, 100> belgianMalesFirstNames;
extern const std::array<std::string_view, 99> belgianFemalesFirstNames;
extern const std::array<std::string_view, 32> belgianLastNames;
extern const std::array<std::string_view, 2> belgianSuffixes;
extern const std::array<std::string_view, 4> belgianPrefixes;
extern const NameFormats belgianPersonNameFormats;
extern const PeopleNames belgianPeopleNames;

// Bosnia

extern const std::array<std::string_view, 100> bosnianMalesFirstNames;
extern const std::array<std::string_view, 100> bosnianFemalesFirstNames;
extern const std::array<std::string_view, 128> bosnianLastNames;
extern const NameFormats bosnianPersonNameFormats;
extern const PeopleNames bosnianPeopleNames;

// Brazil

extern const std::array<std::string_view, 88> brazilianMalesFirstNames;
extern const std::array<std::string_view, 80> brazilianFemalesFirstNames;
extern const std::array<std::string_view, 21> brazilianLastNames;
extern const std::array<std::string_view, 3> brazilianSuffixes;
extern const std::array<std::string_view, 2> brazilianMalesPrefixes;
extern const std::array<std::string_view, 3> brazilianFemalesPrefixes;
extern const NameFormats brazilianPersonNameFormats;
extern const PeopleNames brazilianPeopleNames;

// Bulgaria

extern const std::array<std::string_view, 30> bulgarianMalesFirstNames;
extern const std::array<std::string_view, 32> bulgarianFemalesFirstNames;
extern const std::array<std::string_view, 25> bulgarianLastNames;
extern const std::array<std::string_view, 2> bulgarianSuffixes;
extern const std::array<std::string_view, 3> bulgarianMalesPrefixes;
extern const std::array<std::string_view, 4> bulgarianFemalesPrefixes;
extern const NameFormats bulgarianPersonNameFormats;
extern const PeopleNames bulgarianPeopleNames;

// Canada

extern const std::array<std::string_view, 350> canadianMalesFirstNames;
extern const std::array<std::string_view, 350> canadianFemalesFirstNames;
extern const std::array<std::string_view, 346> canadianLastNames;
extern const NameFormats canadianPersonNameFormats;
extern const PeopleNames canadianPeopleNames;

// China

extern const std::array<std::string_view, 1000> chineseLastNames;
extern const std::array<std::string_view, 78> chineseMalesFirstNames;
extern const std::array<std::string_view, 85> chineseFemalesFirstNames;
extern const NameFormats chinesePersonNameFormats;
extern const PeopleNames chinesePeopleNames;

// Croatia

extern const std::array<std::string_view, 171> croatianMalesFirstNames;
extern const std::array<std::string_view, 238> croatianFemalesFirstNames;
extern const std::array<std::string_view, 11617> croatianLastNames;
extern const std::array<std::string_view, 2> croatianSuffixes;
extern const std::array<std::string_view, 2> croatianMalesPrefixes;
extern const std::array<std::string_view, 3> croatianFemalesPrefixes;
extern const NameFormats croatianPersonNameFormats;
extern const PeopleNames croatianPeopleNames;

// Czechia

extern const std::array<std::string_view, 795> czechMalesFirstNames;
extern const std::array<std::string_view, 785> czechFemalesFirstNames;
extern const std::array<std::string_view, 999> czechMalesLastNames;
extern const std::array<std::string_view, 991> czechFemalesLastNames;
extern const std::array<std::string_view, 4> czechPrefixes;
extern const std::array<std::string_view, 1> czechSuffixes;
extern const NameFormats czechPersonNameFormats;
extern const PeopleNames czechPeopleNames;

// Denmark

extern const std::array<std::string_view, 118> danishMalesFirstNames;
extern const std::array<std::string_view, 109> danishFemalesFirstNames;
extern const std::array<std::string_view, 106> danishLastNames;
extern const std::array<std::string_view, 30> danishMiddleNames;
extern const std::array<std::string_view, 1> danishMalesPrefixes;
extern const std::array<std::string_view, 1> danishFemalesPrefixes;
extern const NameFormats danishPersonNameFormats;
extern const PeopleNames danishPeopleNames;

// Dutch

extern const std::array<std::string_view, 587> dutchMalesFirstNames;
extern const std::array<std::string_view, 514> dutchFemalesFirstNames;
extern const std::array<std::string_view, 131> dutchLastNames;
extern const std::array<std::string_view, 2> dutchSuffixes;
extern const std::array<std::string_view, 7> dutchMalesPrefixes;
extern const std::array<std::string_view, 7> dutchFemalesPrefixes;
extern const NameFormats dutchPersonNameFormats;
extern const PeopleNames dutchPeopleNames;

// England

extern const std::array<std::string_view, 500> englishMalesFirstNames;
extern const std::array<std::string_view, 500> englishFemalesFirstNames;
extern const std::array<std::string_view, 463> englishLastNames;
extern const std::array<std::string_view, 11> englishSuffixes;
extern const std::array<std::string_view, 2> englishMalesPrefixes;
extern const std::array<std::string_view, 4> englishFemalesPrefixes;
extern const NameFormats englishPersonNameFormats;
extern const PeopleNames englishPeopleNames;

// Estonia

extern const std::array<std::string_view, 350> estonianMalesFirstNames;
extern const std::array<std::string_view, 350> estonianFemalesFirstNames;
extern const std::array<std::string_view, 350> estonianLastNames;
extern const NameFormats estonianPersonNameFormats;
extern const PeopleNames estonianPeopleNames;

// Finland

extern const std::array<std::string_view, 45> finnishMalesFirstNames;
extern const std::array<std::string_view, 46> finnishFemalesFirstNames;
extern const std::array<std::string_view, 46> finnishLastNames;
extern const NameFormats finnishPersonNameFormats;
extern const PeopleNames finnishPeopleNames;

// France

extern const std::array<std::string_view, 496> frenchMalesFirstNames;
extern const std::array<std::string_view, 451> frenchFemalesFirstNames;
extern const std::array<std::string_view, 150> frenchLastNames;
extern const std::array<std::string_view, 3> frenchMalesPrefixes;
extern const std::array<std::string_view, 4> frenchFemalesPrefixes;
extern const NameFormats frenchPersonNameFormats;
extern const PeopleNames frenchPeopleNames;

// Germany

extern const std::array<std::string_view, 572> germanMalesFirstNames;
extern const std::array<std::string_view, 583> germanFemalesFirstNames;
extern const std::array<std::string_view, 1688> germanLastNames;
extern const std::array<std::string_view, 3> germanMalesPrefixes;
extern const std::array<std::string_view, 3> germanFemalesPrefixes;
extern const NameFormats germanPersonNameFormats;
extern const PeopleNames germanPeopleNames;

// Ghana

extern const std::array<std::string_view, 132> ghanaianMalesFirstNames;
extern const std::array<std::string_view, 132> ghanaianFemalesFirstNames;
extern const std::array<std::string_view, 120> ghanaianLastNames;
extern const NameFormats ghanaianPersonNameFormats;
extern const PeopleNames ghanaianPeopleNames;

// Greece

extern const std::array<std::string_view, 350> greekMalesFirstNames;
extern const std::array<std::string_view, 350> greekFemalesFirstNames;
extern const std::array<std::string_view, 350> greekLastNames;
extern const NameFormats greekPersonNameFormats;
extern const PeopleNames greekPeopleNames;

// Hungary

extern const std::array<std::string_view, 100> hungarianMalesFirstNames;
extern const std::array<std::string_view, 100> hungarianFemalesFirstNames;
extern const std::array<std::string_view, 100> hungarianLastNames;
extern const std::array<std::string_view, 2> hungarianPrefixes;
extern const NameFormats hungarianPersonNameFormats;
extern const PeopleNames hungarianPeopleNames;

// Iceland

extern const std::array<std::string_view, 157> icelandicMalesFirstNames;
extern const std::array<std::string_view, 141> icelandicFemalesFirstNames;
extern const std::array<std::string_view, 140> icelandicLastNames;
extern const NameFormats icelandicPersonNameFormats;
extern const PeopleNames icelandicPeopleNames;

// India

extern const std::array<std::string_view, 351> indianMalesFirstNames;
extern const std::array<std::string_view, 228> indianFemalesFirstNames;
extern const std::array<std::string_view, 184> indianLastNames;
extern const NameFormats indianPersonNameFormats;
extern const PeopleNames indianPeopleNames;

// Ireland

extern const std::array<std::string_view, 350> irishMalesFirstNames;
extern const std::array<std::string_view, 350> irishFemalesFirstNames;
extern const std::array<std::string_view, 350> irishLastNames;
extern const std::array<std::string_view, 11> irishSuffixes;
extern const std::array<std::string_view, 2> irishMalesPrefixes;
extern const std::array<std::string_view, 4> irishFemalesPrefixes;
// TODO: add handling lastName-lastName
extern const NameFormats irishPersonNameFormats;
extern const PeopleNames irishPeopleNames;

// Israel

extern const std::array<std::string_view, 297> israelisMalesFirstNames;
extern const std::array<std::string_view, 297> israelisFemalesFirstNames;
extern const std::array<std::string_view, 270> israelisLastNames;
extern const NameFormats israelisPersonNameFormats;
extern const PeopleNames israeliPeopleNames;

// Italy

extern const std::array<std::string_view, 1083> italianMalesFirstNames;
extern const std::array<std::string_view, 617> italianFemalesFirstNames;
extern const std::array<std::string_view, 2170> italianLastNames;
extern const std::array<std::string_view, 4> italianPrefixes;
extern const NameFormats italianPersonNameFormats;
extern const PeopleNames italianPeopleNames;

// Japan

extern const std::array<std::string_view, 135> japaneseMaleFirstNames;
extern const std::array<std::string_view, 145> japaneseFemaleFirstNames;
extern const std::array<std::string_view, 20> japaneseLastNames;
extern const NameFormats japanesePeopleNameFormats;
extern const PeopleNames japanesePeopleNames;

// Kazakhstan

extern const std::array<std::string_view, 200> kazakhMalesFirstNames;
extern const std::array<std::string_view, 121> kazakhFemalesFirstNames;
extern const std::array<std::string_view, 21> kazakhMalesLastNames;
extern const std::array<std::string_view, 18> kazakhFemalesLastNames;
extern const NameFormats kazakhPersonNameFormats;
extern const PeopleNames kazakhPeopleNames;

// Korea

extern const std::array<std::string_view, 2963> koreanFirstNames;
extern const std::array<std::string_view, 112> koreanLastNames;
extern const NameFormats koreanPersonNameFormats;
extern const PeopleNames koreanPeopleNames;

// Latvia

extern const std::array<std::string_view, 91> latvianMalesFirstNames;
extern const std::array<std::string_view, 105> latvianFemalesFirstNames;
extern const std::array<std::string_view, 206> latvianMalesLastNames;
extern const std::array<std::string_view, 207> latvianFemalesLastNames;
extern const std::array<std::string_view, 2> latvianSuffixes;
extern const std::array<std::string_view, 3> latvianPrefixes;
extern const NameFormats latvianPersonNameFormats;
extern const PeopleNames latvianPeopleNames;

// Lebanon

extern const std::array<std::string_view, 700> lebaneseMalesFirstNames;
extern const std::array<std::string_view, 350> lebaneseFemalesFirstNames;
extern const std::array<std::string_view, 350> lebaneseLastNames;
extern const NameFormats lebanesePersonNameFormats;
extern const PeopleNames lebanesePeopleNames;

// Lithuania

extern const std::array<std::string_view, 350> lithuanianMalesFirstNames;
extern const std::array<std::string_view, 350> lithuanianFemalesFirstNames;
extern const std::array<std::string_view, 350> lithuanianLastNames;
extern const NameFormats lithuanianPersonNameFormats;
extern const PeopleNames lithuanianPeopleNames;

// Macedonia

extern const std::array<std::string_view, 283> macedonianMalesFirstNames;
extern const std::array<std::string_view, 232> macedonianFemalesFirstNames;
extern const std::array<std::string_view, 493> macedonianMalesLastNames;
extern const std::array<std::string_view, 495> macedonianFemalesLastNames;
extern const std::array<std::string_view, 3> macedonianMalesPrefixes;
extern const std::array<std::string_view, 4> macedonianFemalesPrefixes;
extern const NameFormats macedonianPersonNameFormats;
extern const PeopleNames macedonianPeopleNames;

// Maldives

extern const std::array<std::string_view, 14> maldiviansMalesFirstNames;
extern const std::array<std::string_view, 49> maldiviansFemalesFirstNames;
extern const std::array<std::string_view, 112> maldiviansMalesLastNames;
extern const std::array<std::string_view, 248> maldiviansFemalesLastNames;
extern const std::array<std::string_view, 4> maldiviansMalesPrefixes;
extern const std::array<std::string_view, 4> maldiviansFemalesPrefixes;
extern const NameFormats maldiviansPersonNameFormats;
extern const PeopleNames maldiviansPeopleNames;

// Malta

extern const std::array<std::string_view, 100> malteseMalesFirstNames;
extern const std::array<std::string_view, 100> malteseFemalesFirstNames;
extern const std::array<std::string_view, 100> malteseLastNames;
extern const NameFormats maltesePersonNameFormats;
extern const PeopleNames maltesePeopleNames;

// Mexico

extern const std::array<std::string_view, 139> mexicanMalesFirstNames;
extern const std::array<std::string_view, 161> mexicanFemalesFirstNames;
extern const std::array<std::string_view, 687> mexicanLastNames;
extern const std::array<std::string_view, 15> mexicanSuffixes;
extern const std::array<std::string_view, 1> mexicanMalesPrefixes;
extern const std::array<std::string_view, 2> mexicanFemalesPrefixes;
extern const NameFormats mexicanPersonNameFormats;
extern const PeopleNames mexicanPeopleNames;

// Moldova

extern const std::array<std::string_view, 350> moldovanMalesFirstNames;
extern const std::array<std::string_view, 350> moldovanFemalesFirstNames;
extern const std::array<std::string_view, 350> moldovanLastNames;
extern const NameFormats moldovanPersonNameFormats;
extern const PeopleNames moldovanPeopleNames;

// Monaco

extern const std::array<std::string_view, 201> monacanMalesFirstNames;
extern const std::array<std::string_view, 350> monacanFemalesFirstNames;
extern const std::array<std::string_view, 326> monacanLastNames;
extern const NameFormats monacanPersonNameFormats;
extern const PeopleNames monacanPeopleNames;

// Nepal

extern const std::array<std::string_view, 104> nepaleseMalesFirstNames;
extern const std::array<std::string_view, 99> nepaleseFemalesFirstNames;
extern const std::array<std::string_view, 64> nepaleseLastNames;
extern const NameFormats nepalesePersonNameFormats;
extern const PeopleNames nepalesePeopleNames;

// Norway

extern const std::array<std::string_view, 50> norwegianMalesFirstNames;
extern const std::array<std::string_view, 50> norwegianFemalesFirstNames;
extern const std::array<std::string_view, 100> norwegianLastNames;
extern const std::array<std::string_view, 7> norwegianSuffixes;
extern const std::array<std::string_view, 2> norwegianPrefixes;
extern const NameFormats norwegianPersonNameFormats;
extern const PeopleNames norwegianPeopleNames;

// Palestine

extern const std::array<std::string_view, 299> palestinianMalesFirstNames;
extern const std::array<std::string_view, 350> palestinianFemalesFirstNames;
extern const std::array<std::string_view, 305> palestinianLastNames;
extern const NameFormats palestinianPersonNameFormats;
extern const PeopleNames palestinianPeopleNames;

// Persian

extern const std::array<std::string_view, 61> persianMalesFirstNames;
extern const std::array<std::string_view, 65> persianFemalesFirstNames;
extern const std::array<std::string_view, 111> persianLastNames;
extern const std::array<std::string_view, 3> persianMalesPrefixes;
extern const std::array<std::string_view, 3> persianFemalesPrefixes;
extern const NameFormats persianPersonNameFormats;
extern const PeopleNames persianPeopleNames;

// Poland

extern const std::array<std::string_view, 230> polishMalesFirstNames;
extern const std::array<std::string_view, 163> polishFemalesFirstNames;
extern const std::array<std::string_view, 712> polishLastNames;
extern const std::array<std::string_view, 1> polishMalesPrefixes;
extern const std::array<std::string_view, 1> polishFemalesPrefixes;
extern const NameFormats polishPersonNameFormats;
extern const PeopleNames polishPeopleNames;

// Portugal

extern const std::array<std::string_view, 95> portugueseMalesFirstNames;
extern const std::array<std::string_view, 93> portugueseFemalesFirstNames;
extern const std::array<std::string_view, 101> portugueseLastNames;
extern const std::array<std::string_view, 4> portugueseMalesPrefixes;
extern const std::array<std::string_view, 4> portugueseFemalesPrefixes;
extern const NameFormats portuguesePersonNameFormats;
extern const PeopleNames portuguesePeopleNames;

// Romania

extern const std::array<std::string_view, 65> romanianMalesFirstNames;
extern const std::array<std::string_view, 63> romanianFemalesFirstNames;
extern const std::array<std::string_view, 101> romanianLastNames;
extern const std::array<std::string_view, 2> romanianSuffixes;
extern const std::array<std::string_view, 2> romanianMalesPrefixes;
extern const std::array<std::string_view, 2> romanianFemalesPrefixes;
extern const NameFormats romanianPersonNameFormats;
extern const PeopleNames romanianPeopleNames;

// Russia

extern const std::array<std::string_view, 200> russianMalesFirstNames;
extern const std::array<std::string_view, 110> russianFemalesFirstNames;
extern const std::array<std::string_view, 568> russianMalesLastNames;
extern const std::array<std::string_view, 562> russianFemalesLastNames;
extern const std::array<std::string_view, 132> russianMalesMiddleNames;
extern const std::array<std::string_view, 79> russianFemalesMiddleNames;
extern const NameFormats russianPersonNameFormats;
extern const PeopleNames russianPeopleNames;

// Serbia

extern const std::array<std::string_view, 200> serbianMalesFirstNames;
extern const std::array<std::string_view, 200> serbianFemalesFirstNames;
extern const std::array<std::string_view, 999> serbianLastNames;
extern const NameFormats serbianPersonNameFormats;
extern const PeopleNames serbianPeopleNames;

// Slovakia

extern const std::array<std::string_view, 192> slovakMalesFirstNames;
extern const std::array<std::string_view, 200> slovakFemalesFirstNames;
extern const std::array<std::string_view, 257> slovakMalesLastNames;
extern const std::array<std::string_view, 251> slovakFemalesLastNames;
extern const std::array<std::string_view, 1> slovakSuffixes;
extern const std::array<std::string_view, 4> slovakPrefixes;
extern const NameFormats slovakPersonNameFormats;
extern const PeopleNames slovakPeopleNames;

// Slovenia

extern const std::array<std::string_view, 350> slovenianMalesFirstNames;
extern const std::array<std::string_view, 350> slovenianFemalesFirstNames;
extern const std::array<std::string_view, 350> slovenianLastNames;
extern const NameFormats slovenianPersonNameFormats;
extern const PeopleNames slovenianPeopleNames;

// South Africa

extern const std::array<std::string_view, 113> southAfricanMalesFirstNames;
extern const std::array<std::string_view, 107> southAfricanFemalesFirstNames;
extern const std::array<std::string_view, 162> southAfricanLastNames;
extern const NameFormats southAfricanPersonNameFormats;
extern const PeopleNames southAfricanPeopleNames;

// Spain

extern const std::array<std::string_view, 113> spanishMalesFirstNames;
extern const std::array<std::string_view, 147> spanishFemalesFirstNames;
extern const std::array<std::string_view, 625> spanishLastNames;
extern const std::array<std::string_view, 1> spanishMalesPrefixes;
extern const std::array<std::string_view, 2> spanishFemalesPrefixes;
extern const NameFormats spanishPersonNameFormats;
extern const PeopleNames spanishPeopleNames;

// Sweden

extern const std::array<std::string_view, 100> swedishMalesFirstNames;
extern const std::array<std::string_view, 100> swedishFemalesFirstNames;
extern const std::array<std::string_view, 100> swedishLastNames;
extern const std::array<std::string_view, 3> swedishPrefixes;
extern const NameFormats swedishPersonNameFormats;
extern const PeopleNames swedishPeopleNames;

// Switzerland

extern const std::array<std::string_view, 179> swissMalesFirstNames;
extern const std::array<std::string_view, 138> swissFemalesFirstNames;
extern const std::array<std::string_view, 209> swissLastNames;
extern const std::array<std::string_view, 3> swissMalesPrefixes;
extern const std::array<std::string_view, 3> swissFemalesPrefixes;
extern const NameFormats swissPersonNameFormats;
extern const PeopleNames swissPeopleNames;

// Syria

extern const std::array<std::string_view, 350> syrianMalesFirstNames;
extern const std::array<std::string_view, 350> syrianFemalesFirstNames;
extern const std::array<std::string_view, 350> syrianLastNames;
extern const NameFormats syrianPersonNameFormats;
extern const PeopleNames syrianPeopleNames;

// Turkey

extern const std::array<std::string_view, 44> turkishMalesFirstNames;
extern const std::array<std::string_view, 43> turkishFemalesFirstNames;
extern const std::array<std::string_view, 52> turkishLastNames;
extern const std::array<std::string_view, 3> turkishMalesPrefixes;
extern const std::array<std::string_view, 3> turkishFemalesPrefixes;
extern const NameFormats turkishPersonNameFormats;
extern const PeopleNames turkishPeopleNames;

// Ukraine

extern const std::array<std::string_view, 195> ukrainianMalesFirstNames;
extern const std::array<std::string_view, 192> ukrainianFemalesFirstNames;
extern const std::array<std::string_view, 239> ukrainianMalesLastNames;
extern const std::array<std::string_view, 230> ukrainianFemalesLastNames;
extern const std::array<std::string_view, 116> ukrainianMalesMiddleNames;
extern const std::array<std::string_view, 116> ukrainianFemalesMiddleNames;
extern const std::array<std::string_view, 1> ukrainianMalesPrefixes;
extern const std::array<std::string_view, 1> ukrainianFemalesPrefixes;
extern const NameFormats ukrainianPersonNameFormats;
extern const PeopleNames ukrainianPeopleNames;

// USA

extern const NameFormats usaPersonNameFormats;
extern const PeopleNames usaPeopleNames;

// Vietnam

extern const std::array<std::string_view, 1224> vietnameseMalesFirstNames;
extern const std::array<std::string_view, 1300> vietnameseFemalesFirstNames;
extern const std::array<std::string_view, 27> vietnameseLastNames;
extern const NameFormats vietnamesePersonNameFormats;
extern const PeopleNames vietnamesePeopleNames;

// Mapping

extern const std::unordered_map<Country, PeopleNames> countryToPeopleNamesMapping;

}

#endif