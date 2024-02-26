#ifndef FAKER_MODULES_PERSON_DATA_H
#define FAKER_MODULES_PERSON_DATA_H

#include <array>
#include <faker/types/country.h>
#include <faker/types/ssn_country.h>
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
    std::vector<std::string_view> firstNames;
    std::vector<std::string_view> middleNames;
    std::vector<std::string_view> lastNames;
    std::vector<std::string_view> prefixes;
    std::vector<std::string_view> suffixes;
};

struct PeopleNames {
    PersonNames malesNames;
    PersonNames femalesNames;
    NameFormats nameFormats;
};

extern const std::unordered_map<SsnCountry, std::string_view> ssnFormats;
extern const std::vector<std::string_view> westernZodiacs;
extern const std::vector<std::string_view> chineseZodiacs;

// Albania

extern const std::vector<std::string_view> albanianMalesFirstNames;
extern const std::vector<std::string_view> albanianFemalesFirstNames;
extern const std::vector<std::string_view> albanianLastNames;
extern const NameFormats albanianPersonNameFormats;
extern const PeopleNames albanianPeopleNames;

// Argentina

extern const std::vector<std::string_view> argentinianMalesFirstNames;
extern const std::vector<std::string_view> argentinianFemalesFirstNames;
extern const std::vector<std::string_view> argentinianLastNames;
extern const NameFormats argentinianPersonNameFormats;
extern const PeopleNames argentinianPeopleNames;

// Australia

extern const std::vector<std::string_view> australianMalesFirstNames;
extern const std::vector<std::string_view> australianFemalesFirstNames;
extern const std::vector<std::string_view> australianLastNames;
extern const NameFormats australianPersonNameFormats;
extern const PeopleNames australianPeopleNames;

// Austria

extern const std::vector<std::string_view> austrianMalesFirstNames;
extern const std::vector<std::string_view> austrianFemalesFirstNames;
extern const std::vector<std::string_view> austrianLastNames;
extern const std::vector<std::string_view> austrianMalesPrefixes;
extern const std::vector<std::string_view> austrianFemalesPrefixes;
extern const NameFormats austrianPersonNameFormats;
extern const PeopleNames austrianPeopleNames;

// Azerbaijan

extern const std::vector<std::string_view> azerbaijaniMalesFirstNames;
extern const std::vector<std::string_view> azerbaijaniFemalesFirstNames;
extern const std::vector<std::string_view> azerbaijaniMalesLastNames;
extern const std::vector<std::string_view> azerbaijaniFemalesLastNames;
extern const NameFormats azerbaijaniPersonNameFormats;
extern const PeopleNames azerbaijaniPeopleNames;

// Belarus

extern const std::vector<std::string_view> belarusianMalesFirstNames;
extern const std::vector<std::string_view> belarusianFemalesFirstNames;
extern const std::vector<std::string_view> belarusianMalesLastNames;
extern const std::vector<std::string_view> belarusianFemalesLastNames;
extern const NameFormats belarusianPersonNameFormats;
extern const PeopleNames belarusianPeopleNames;

// Belgium

extern const std::vector<std::string_view> belgianMalesFirstNames;
extern const std::vector<std::string_view> belgianFemalesFirstNames;
extern const std::vector<std::string_view> belgianLastNames;
extern const std::vector<std::string_view> belgianSuffixes;
extern const std::vector<std::string_view> belgianPrefixes;
extern const NameFormats belgianPersonNameFormats;
extern const PeopleNames belgianPeopleNames;

// Bosnia

extern const std::vector<std::string_view> bosnianMalesFirstNames;
extern const std::vector<std::string_view> bosnianFemalesFirstNames;
extern const std::vector<std::string_view> bosnianLastNames;
extern const NameFormats bosnianPersonNameFormats;
extern const PeopleNames bosnianPeopleNames;

// Brazil

extern const std::vector<std::string_view> brazilianMalesFirstNames;
extern const std::vector<std::string_view> brazilianFemalesFirstNames;
extern const std::vector<std::string_view> brazilianLastNames;
extern const std::vector<std::string_view> brazilianSuffixes;
extern const std::vector<std::string_view> brazilianMalesPrefixes;
extern const std::vector<std::string_view> brazilianFemalesPrefixes;
extern const NameFormats brazilianPersonNameFormats;
extern const PeopleNames brazilianPeopleNames;

// Bulgaria

extern const std::vector<std::string_view> bulgarianMalesFirstNames;
extern const std::vector<std::string_view> bulgarianFemalesFirstNames;
extern const std::vector<std::string_view> bulgarianLastNames;
extern const std::vector<std::string_view> bulgarianSuffixes;
extern const std::vector<std::string_view> bulgarianMalesPrefixes;
extern const std::vector<std::string_view> bulgarianFemalesPrefixes;
extern const NameFormats bulgarianPersonNameFormats;
extern const PeopleNames bulgarianPeopleNames;

// Canada

extern const std::vector<std::string_view> canadianMalesFirstNames;
extern const std::vector<std::string_view> canadianFemalesFirstNames;
extern const std::vector<std::string_view> canadianLastNames;
extern const NameFormats canadianPersonNameFormats;
extern const PeopleNames canadianPeopleNames;

// China

extern const std::vector<std::string_view> chineseLastNames;
extern const std::vector<std::string_view> chineseMalesFirstNames;
extern const std::vector<std::string_view> chineseFemalesFirstNames;
extern const NameFormats chinesePersonNameFormats;
extern const PeopleNames chinesePeopleNames;

// Croatia

extern const std::vector<std::string_view> croatianMalesFirstNames;
extern const std::vector<std::string_view> croatianFemalesFirstNames;
extern const std::vector<std::string_view> croatianLastNames;
extern const std::vector<std::string_view> croatianSuffixes;
extern const std::vector<std::string_view> croatianMalesPrefixes;
extern const std::vector<std::string_view> croatianFemalesPrefixes;
extern const NameFormats croatianPersonNameFormats;
extern const PeopleNames croatianPeopleNames;

// Czechia

extern const std::vector<std::string_view> czechMalesFirstNames;
extern const std::vector<std::string_view> czechFemalesFirstNames;
extern const std::vector<std::string_view> czechMalesLastNames;
extern const std::vector<std::string_view> czechFemalesLastNames;
extern const std::vector<std::string_view> czechPrefixes;
extern const std::vector<std::string_view> czechSuffixes;
extern const NameFormats czechPersonNameFormats;
extern const PeopleNames czechPeopleNames;

// Denmark

extern const std::vector<std::string_view> danishMalesFirstNames;
extern const std::vector<std::string_view> danishFemalesFirstNames;
extern const std::vector<std::string_view> danishLastNames;
extern const std::vector<std::string_view> danishMiddleNames;
extern const std::vector<std::string_view> danishMalesPrefixes;
extern const std::vector<std::string_view> danishFemalesPrefixes;
extern const NameFormats danishPersonNameFormats;
extern const PeopleNames danishPeopleNames;

// Dutch

extern const std::vector<std::string_view> dutchMalesFirstNames;
extern const std::vector<std::string_view> dutchFemalesFirstNames;
extern const std::vector<std::string_view> dutchLastNames;
extern const std::vector<std::string_view> dutchSuffixes;
extern const std::vector<std::string_view> dutchMalesPrefixes;
extern const std::vector<std::string_view> dutchFemalesPrefixes;
extern const NameFormats dutchPersonNameFormats;
extern const PeopleNames dutchPeopleNames;

// England

extern const std::vector<std::string_view> englishMalesFirstNames;
extern const std::vector<std::string_view> englishFemalesFirstNames;
extern const std::vector<std::string_view> englishLastNames;
extern const std::vector<std::string_view> englishSuffixes;
extern const std::vector<std::string_view> englishMalesPrefixes;
extern const std::vector<std::string_view> englishFemalesPrefixes;
extern const NameFormats englishPersonNameFormats;
extern const PeopleNames englishPeopleNames;

// Estonia

extern const std::vector<std::string_view> estonianMalesFirstNames;
extern const std::vector<std::string_view> estonianFemalesFirstNames;
extern const std::vector<std::string_view> estonianLastNames;
extern const NameFormats estonianPersonNameFormats;
extern const PeopleNames estonianPeopleNames;

// Finland

extern const std::vector<std::string_view> finnishMalesFirstNames;
extern const std::vector<std::string_view> finnishFemalesFirstNames;
extern const std::vector<std::string_view> finnishLastNames;
extern const NameFormats finnishPersonNameFormats;
extern const PeopleNames finnishPeopleNames;

// France

extern const std::vector<std::string_view> frenchMalesFirstNames;
extern const std::vector<std::string_view> frenchFemalesFirstNames;
extern const std::vector<std::string_view> frenchLastNames;
extern const std::vector<std::string_view> frenchMalesPrefixes;
extern const std::vector<std::string_view> frenchFemalesPrefixes;
extern const NameFormats frenchPersonNameFormats;
extern const PeopleNames frenchPeopleNames;

// Germany

extern const std::vector<std::string_view> germanMalesFirstNames;
extern const std::vector<std::string_view> germanFemalesFirstNames;
extern const std::vector<std::string_view> germanLastNames;
extern const std::vector<std::string_view> germanMalesPrefixes;
extern const std::vector<std::string_view> germanFemalesPrefixes;
extern const NameFormats germanPersonNameFormats;
extern const PeopleNames germanPeopleNames;

// Ghana

extern const std::vector<std::string_view> ghanaianMalesFirstNames;
extern const std::vector<std::string_view> ghanaianFemalesFirstNames;
extern const std::vector<std::string_view> ghanaianLastNames;
extern const NameFormats ghanaianPersonNameFormats;
extern const PeopleNames ghanaianPeopleNames;

// Greece

extern const std::vector<std::string_view> greekMalesFirstNames;
extern const std::vector<std::string_view> greekFemalesFirstNames;
extern const std::vector<std::string_view> greekLastNames;
extern const NameFormats greekPersonNameFormats;
extern const PeopleNames greekPeopleNames;

// Hungary

extern const std::vector<std::string_view> hungarianMalesFirstNames;
extern const std::vector<std::string_view> hungarianFemalesFirstNames;
extern const std::vector<std::string_view> hungarianLastNames;
extern const std::vector<std::string_view> hungarianPrefixes;
extern const NameFormats hungarianPersonNameFormats;
extern const PeopleNames hungarianPeopleNames;

// Iceland

extern const std::vector<std::string_view> icelandicMalesFirstNames;
extern const std::vector<std::string_view> icelandicFemalesFirstNames;
extern const std::vector<std::string_view> icelandicLastNames;
extern const NameFormats icelandicPersonNameFormats;
extern const PeopleNames icelandicPeopleNames;

// India

extern const std::vector<std::string_view> indianMalesFirstNames;
extern const std::vector<std::string_view> indianFemalesFirstNames;
extern const std::vector<std::string_view> indianLastNames;
extern const NameFormats indianPersonNameFormats;
extern const PeopleNames indianPeopleNames;

// Ireland

extern const std::vector<std::string_view> irishMalesFirstNames;
extern const std::vector<std::string_view> irishFemalesFirstNames;
extern const std::vector<std::string_view> irishLastNames;
extern const std::vector<std::string_view> irishSuffixes;
extern const std::vector<std::string_view> irishMalesPrefixes;
extern const std::vector<std::string_view> irishFemalesPrefixes;

// TODO: add handling lastName-lastName

extern const NameFormats irishPersonNameFormats;
extern const PeopleNames irishPeopleNames;

// Israel

extern const std::vector<std::string_view> israelisMalesFirstNames;
extern const std::vector<std::string_view> israelisFemalesFirstNames;
extern const std::vector<std::string_view> israelisLastNames;
extern const NameFormats israelisPersonNameFormats;
extern const PeopleNames israeliPeopleNames;

// Italy

extern const std::vector<std::string_view> italianMalesFirstNames;
extern const std::vector<std::string_view> italianFemalesFirstNames;
extern const std::vector<std::string_view> italianLastNames;
extern const std::vector<std::string_view> italianPrefixes;
extern const NameFormats italianPersonNameFormats;
extern const PeopleNames italianPeopleNames;

// Japan

extern const std::vector<std::string_view> japaneseMaleFirstNames;
extern const std::vector<std::string_view> japaneseFemaleFirstNames;
extern const std::vector<std::string_view> japaneseLastNames;
extern const NameFormats japanesePeopleNameFormats;
extern const PeopleNames japanesePeopleNames;

// Kazakhstan

extern const std::vector<std::string_view> kazakhMalesFirstNames;
extern const std::vector<std::string_view> kazakhFemalesFirstNames;
extern const std::vector<std::string_view> kazakhMalesLastNames;
extern const std::vector<std::string_view> kazakhFemalesLastNames;
extern const NameFormats kazakhPersonNameFormats;
extern const PeopleNames kazakhPeopleNames;

// Korea

extern const std::vector<std::string_view> koreanFirstNames;
extern const std::vector<std::string_view> koreanLastNames;
extern const NameFormats koreanPersonNameFormats;
extern const PeopleNames koreanPeopleNames;

// Latvia

extern const std::vector<std::string_view> latvianMalesFirstNames;
extern const std::vector<std::string_view> latvianFemalesFirstNames;
extern const std::vector<std::string_view> latvianMalesLastNames;
extern const std::vector<std::string_view> latvianFemalesLastNames;
extern const std::vector<std::string_view> latvianSuffixes;
extern const std::vector<std::string_view> latvianPrefixes;
extern const NameFormats latvianPersonNameFormats;
extern const PeopleNames latvianPeopleNames;

// Lebanon

extern const std::vector<std::string_view> lebaneseMalesFirstNames;
extern const std::vector<std::string_view> lebaneseFemalesFirstNames;
extern const std::vector<std::string_view> lebaneseLastNames;
extern const NameFormats lebanesePersonNameFormats;
extern const PeopleNames lebanesePeopleNames;

// Lithuania

extern const std::vector<std::string_view> lithuanianMalesFirstNames;
extern const std::vector<std::string_view> lithuanianFemalesFirstNames;
extern const std::vector<std::string_view> lithuanianLastNames;
extern const NameFormats lithuanianPersonNameFormats;
extern const PeopleNames lithuanianPeopleNames;

// Macedonia

extern const std::vector<std::string_view> macedonianMalesFirstNames;
extern const std::vector<std::string_view> macedonianFemalesFirstNames;
extern const std::vector<std::string_view> macedonianMalesLastNames;
extern const std::vector<std::string_view> macedonianFemalesLastNames;
extern const std::vector<std::string_view> macedonianMalesPrefixes;
extern const std::vector<std::string_view> macedonianFemalesPrefixes;
extern const NameFormats macedonianPersonNameFormats;
extern const PeopleNames macedonianPeopleNames;

// Maldives

extern const std::vector<std::string_view> maldiviansMalesFirstNames;
extern const std::vector<std::string_view> maldiviansFemalesFirstNames;
extern const std::vector<std::string_view> maldiviansMalesLastNames;
extern const std::vector<std::string_view> maldiviansFemalesLastNames;
extern const std::vector<std::string_view> maldiviansMalesPrefixes;
extern const std::vector<std::string_view> maldiviansFemalesPrefixes;
extern const NameFormats maldiviansPersonNameFormats;
extern const PeopleNames maldiviansPeopleNames;

// Malta

extern const std::vector<std::string_view> malteseMalesFirstNames;
extern const std::vector<std::string_view> malteseFemalesFirstNames;
extern const std::vector<std::string_view> malteseLastNames;
extern const NameFormats maltesePersonNameFormats;
extern const PeopleNames maltesePeopleNames;

// Mexico

extern const std::vector<std::string_view> mexicanMalesFirstNames;
extern const std::vector<std::string_view> mexicanFemalesFirstNames;
extern const std::vector<std::string_view> mexicanLastNames;
extern const std::vector<std::string_view> mexicanSuffixes;
extern const std::vector<std::string_view> mexicanMalesPrefixes;
extern const std::vector<std::string_view> mexicanFemalesPrefixes;
extern const NameFormats mexicanPersonNameFormats;
extern const PeopleNames mexicanPeopleNames;

// Moldova

extern const std::vector<std::string_view> moldovanMalesFirstNames;
extern const std::vector<std::string_view> moldovanFemalesFirstNames;
extern const std::vector<std::string_view> moldovanLastNames;
extern const NameFormats moldovanPersonNameFormats;
extern const PeopleNames moldovanPeopleNames;

// Monaco

extern const std::vector<std::string_view> monacanMalesFirstNames;
extern const std::vector<std::string_view> monacanFemalesFirstNames;
extern const std::vector<std::string_view> monacanLastNames;
extern const NameFormats monacanPersonNameFormats;
extern const PeopleNames monacanPeopleNames;

// Nepal

extern const std::vector<std::string_view> nepaleseMalesFirstNames;
extern const std::vector<std::string_view> nepaleseFemalesFirstNames;
extern const std::vector<std::string_view> nepaleseLastNames;
extern const NameFormats nepalesePersonNameFormats;
extern const PeopleNames nepalesePeopleNames;

// Norway

extern const std::vector<std::string_view> norwegianMalesFirstNames;
extern const std::vector<std::string_view> norwegianFemalesFirstNames;
extern const std::vector<std::string_view> norwegianLastNames;
extern const std::vector<std::string_view> norwegianSuffixes;
extern const std::vector<std::string_view> norwegianPrefixes;
extern const NameFormats norwegianPersonNameFormats;
extern const PeopleNames norwegianPeopleNames;

// Palestine

extern const std::vector<std::string_view> palestinianMalesFirstNames;
extern const std::vector<std::string_view> palestinianFemalesFirstNames;
extern const std::vector<std::string_view> palestinianLastNames;
extern const NameFormats palestinianPersonNameFormats;
extern const PeopleNames palestinianPeopleNames;

// Persian

extern const std::vector<std::string_view> persianMalesFirstNames;
extern const std::vector<std::string_view> persianFemalesFirstNames;
extern const std::vector<std::string_view> persianLastNames;
extern const std::vector<std::string_view> persianMalesPrefixes;
extern const std::vector<std::string_view> persianFemalesPrefixes;
extern const NameFormats persianPersonNameFormats;
extern const PeopleNames persianPeopleNames;

// Poland

extern const std::vector<std::string_view> polishMalesFirstNames;
extern const std::vector<std::string_view> polishFemalesFirstNames;
extern const std::vector<std::string_view> polishLastNames;
extern const std::vector<std::string_view> polishMalesPrefixes;
extern const std::vector<std::string_view> polishFemalesPrefixes;
extern const NameFormats polishPersonNameFormats;
extern const PeopleNames polishPeopleNames;

// Portugal

extern const std::vector<std::string_view> portugueseMalesFirstNames;
extern const std::vector<std::string_view> portugueseFemalesFirstNames;
extern const std::vector<std::string_view> portugueseLastNames;
extern const std::vector<std::string_view> portugueseMalesPrefixes;
extern const std::vector<std::string_view> portugueseFemalesPrefixes;
extern const NameFormats portuguesePersonNameFormats;
extern const PeopleNames portuguesePeopleNames;

// Romania

extern const std::vector<std::string_view> romanianMalesFirstNames;
extern const std::vector<std::string_view> romanianFemalesFirstNames;
extern const std::vector<std::string_view> romanianLastNames;
extern const std::vector<std::string_view> romanianSuffixes;
extern const std::vector<std::string_view> romanianMalesPrefixes;
extern const std::vector<std::string_view> romanianFemalesPrefixes;
extern const NameFormats romanianPersonNameFormats;
extern const PeopleNames romanianPeopleNames;

// Russia

extern const std::vector<std::string_view> russianMalesFirstNames;
extern const std::vector<std::string_view> russianFemalesFirstNames;
extern const std::vector<std::string_view> russianMalesLastNames;
extern const std::vector<std::string_view> russianFemalesLastNames;
extern const std::vector<std::string_view> russianMalesMiddleNames;
extern const std::vector<std::string_view> russianFemalesMiddleNames;
extern const NameFormats russianPersonNameFormats;
extern const PeopleNames russianPeopleNames;

// Serbia

extern const std::vector<std::string_view> serbianMalesFirstNames;
extern const std::vector<std::string_view> serbianFemalesFirstNames;
extern const std::vector<std::string_view> serbianLastNames;
extern const NameFormats serbianPersonNameFormats;
extern const PeopleNames serbianPeopleNames;

// Slovakia

extern const std::vector<std::string_view> slovakMalesFirstNames;
extern const std::vector<std::string_view> slovakFemalesFirstNames;
extern const std::vector<std::string_view> slovakMalesLastNames;
extern const std::vector<std::string_view> slovakFemalesLastNames;
extern const std::vector<std::string_view> slovakSuffixes;
extern const std::vector<std::string_view> slovakPrefixes;
extern const NameFormats slovakPersonNameFormats;
extern const PeopleNames slovakPeopleNames;

// Slovenia

extern const std::vector<std::string_view> slovenianMalesFirstNames;
extern const std::vector<std::string_view> slovenianFemalesFirstNames;
extern const std::vector<std::string_view> slovenianLastNames;
extern const NameFormats slovenianPersonNameFormats;
extern const PeopleNames slovenianPeopleNames;

// South Africa

extern const std::vector<std::string_view> southAfricanMalesFirstNames;
extern const std::vector<std::string_view> southAfricanFemalesFirstNames;
extern const std::vector<std::string_view> southAfricanLastNames;
extern const NameFormats southAfricanPersonNameFormats;
extern const PeopleNames southAfricanPeopleNames;

// Spain

extern const std::vector<std::string_view> spanishMalesFirstNames;
extern const std::vector<std::string_view> spanishFemalesFirstNames;
extern const std::vector<std::string_view> spanishLastNames;
extern const std::vector<std::string_view> spanishMalesPrefixes;
extern const std::vector<std::string_view> spanishFemalesPrefixes;
extern const NameFormats spanishPersonNameFormats;
extern const PeopleNames spanishPeopleNames;

// Sweden

extern const std::vector<std::string_view> swedishMalesFirstNames;
extern const std::vector<std::string_view> swedishFemalesFirstNames;
extern const std::vector<std::string_view> swedishLastNames;
extern const std::vector<std::string_view> swedishPrefixes;
extern const NameFormats swedishPersonNameFormats;
extern const PeopleNames swedishPeopleNames;

// Switzerland

extern const std::vector<std::string_view> swissMalesFirstNames;
extern const std::vector<std::string_view> swissFemalesFirstNames;
extern const std::vector<std::string_view> swissLastNames;
extern const std::vector<std::string_view> swissMalesPrefixes;
extern const std::vector<std::string_view> swissFemalesPrefixes;
extern const NameFormats swissPersonNameFormats;
extern const PeopleNames swissPeopleNames;

// Syria

extern const std::vector<std::string_view> syrianMalesFirstNames;
extern const std::vector<std::string_view> syrianFemalesFirstNames;
extern const std::vector<std::string_view> syrianLastNames;
extern const NameFormats syrianPersonNameFormats;
extern const PeopleNames syrianPeopleNames;

// Turkey

extern const std::vector<std::string_view> turkishMalesFirstNames;
extern const std::vector<std::string_view> turkishFemalesFirstNames;
extern const std::vector<std::string_view> turkishLastNames;
extern const std::vector<std::string_view> turkishMalesPrefixes;
extern const std::vector<std::string_view> turkishFemalesPrefixes;
extern const NameFormats turkishPersonNameFormats;
extern const PeopleNames turkishPeopleNames;

// Ukraine

extern const std::vector<std::string_view> ukrainianMalesFirstNames;
extern const std::vector<std::string_view> ukrainianFemalesFirstNames;
extern const std::vector<std::string_view> ukrainianMalesLastNames;
extern const std::vector<std::string_view> ukrainianFemalesLastNames;
extern const std::vector<std::string_view> ukrainianMalesMiddleNames;
extern const std::vector<std::string_view> ukrainianFemalesMiddleNames;
extern const std::vector<std::string_view> ukrainianMalesPrefixes;
extern const std::vector<std::string_view> ukrainianFemalesPrefixes;
extern const NameFormats ukrainianPersonNameFormats;
extern const PeopleNames ukrainianPeopleNames;

// USA

extern const NameFormats usaPersonNameFormats;
extern const PeopleNames usaPeopleNames;

// Vietnam

extern const std::vector<std::string_view> vietnameseMalesFirstNames;
extern const std::vector<std::string_view> vietnameseFemalesFirstNames;
extern const std::vector<std::string_view> vietnameseLastNames;
extern const NameFormats vietnamesePersonNameFormats;
extern const PeopleNames vietnamesePeopleNames;

// Mapping

extern const std::unordered_map<Country, PeopleNames> countryToPeopleNamesMapping;

}

#endif