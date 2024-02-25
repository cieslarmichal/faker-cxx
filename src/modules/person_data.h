#ifndef FAKER_MODULES_PERSON_DATA_H
#define FAKER_MODULES_PERSON_DATA_H

#include <array>
#include <faker/types/country.h>
#include <faker/types/ssn_country.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace faker {
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
    std::string format;
    unsigned weight;
};

using NameFormats = std::vector<NameFormat>;

extern const std::array<std::string_view, 62> nationalities;

struct PersonNames {
    std::vector<std::string> firstNames;
    std::vector<std::string> middleNames;
    std::vector<std::string> lastNames;
    std::vector<std::string> prefixes;
    std::vector<std::string> suffixes;
};

struct PeopleNames {
    PersonNames malesNames;
    PersonNames femalesNames;
    NameFormats nameFormats;
};

extern const std::unordered_map<SsnCountry, std::string> ssnFormats;
extern const std::vector<std::string> westernZodiacs;
extern const std::vector<std::string> chineseZodiacs;

// Albania

extern const std::vector<std::string> albanianMalesFirstNames;
extern const std::vector<std::string> albanianFemalesFirstNames;
extern const std::vector<std::string> albanianLastNames;
extern const NameFormats albanianPersonNameFormats;
extern const PeopleNames albanianPeopleNames;

// Argentina

extern const std::vector<std::string> argentinianMalesFirstNames;
extern const std::vector<std::string> argentinianFemalesFirstNames;
extern const std::vector<std::string> argentinianLastNames;
extern const NameFormats argentinianPersonNameFormats;
extern const PeopleNames argentinianPeopleNames;

// Australia

extern const std::vector<std::string> australianMalesFirstNames;
extern const std::vector<std::string> australianFemalesFirstNames;
extern const std::vector<std::string> australianLastNames;
extern const NameFormats australianPersonNameFormats;
extern const PeopleNames australianPeopleNames;

// Austria

extern const std::vector<std::string> austrianMalesFirstNames;
extern const std::vector<std::string> austrianFemalesFirstNames;
extern const std::vector<std::string> austrianLastNames;
extern const std::vector<std::string> austrianMalesPrefixes;
extern const std::vector<std::string> austrianFemalesPrefixes;
extern const NameFormats austrianPersonNameFormats;
extern const PeopleNames austrianPeopleNames;

// Azerbaijan

extern const std::vector<std::string> azerbaijaniMalesFirstNames;
extern const std::vector<std::string> azerbaijaniFemalesFirstNames;
extern const std::vector<std::string> azerbaijaniMalesLastNames;
extern const std::vector<std::string> azerbaijaniFemalesLastNames;
extern const NameFormats azerbaijaniPersonNameFormats;
extern const PeopleNames azerbaijaniPeopleNames;

// Belarus

extern const std::vector<std::string> belarusianMalesFirstNames;
extern const std::vector<std::string> belarusianFemalesFirstNames;
extern const std::vector<std::string> belarusianMalesLastNames;
extern const std::vector<std::string> belarusianFemalesLastNames;
extern const NameFormats belarusianPersonNameFormats;
extern const PeopleNames belarusianPeopleNames;

// Belgium

extern const std::vector<std::string> belgianMalesFirstNames;
extern const std::vector<std::string> belgianFemalesFirstNames;
extern const std::vector<std::string> belgianLastNames;
extern const std::vector<std::string> belgianSuffixes;
extern const std::vector<std::string> belgianPrefixes;
extern const NameFormats belgianPersonNameFormats;
extern const PeopleNames belgianPeopleNames;

// Bosnia

extern const std::vector<std::string> bosnianMalesFirstNames;
extern const std::vector<std::string> bosnianFemalesFirstNames;
extern const std::vector<std::string> bosnianLastNames;
extern const NameFormats bosnianPersonNameFormats;
extern const PeopleNames bosnianPeopleNames;

// Brazil

extern const std::vector<std::string> brazilianMalesFirstNames;
extern const std::vector<std::string> brazilianFemalesFirstNames;
extern const std::vector<std::string> brazilianLastNames;
extern const std::vector<std::string> brazilianSuffixes;
extern const std::vector<std::string> brazilianMalesPrefixes;
extern const std::vector<std::string> brazilianFemalesPrefixes;
extern const NameFormats brazilianPersonNameFormats;
extern const PeopleNames brazilianPeopleNames;

// Bulgaria

extern const std::vector<std::string> bulgarianMalesFirstNames;
extern const std::vector<std::string> bulgarianFemalesFirstNames;
extern const std::vector<std::string> bulgarianLastNames;
extern const std::vector<std::string> bulgarianSuffixes;
extern const std::vector<std::string> bulgarianMalesPrefixes;
extern const std::vector<std::string> bulgarianFemalesPrefixes;
extern const NameFormats bulgarianPersonNameFormats;
extern const PeopleNames bulgarianPeopleNames;

// Canada

extern const std::vector<std::string> canadianMalesFirstNames;
extern const std::vector<std::string> canadianFemalesFirstNames;
extern const std::vector<std::string> canadianLastNames;
extern const NameFormats canadianPersonNameFormats;
extern const PeopleNames canadianPeopleNames;

// China

extern const std::vector<std::string> chineseLastNames;
extern const std::vector<std::string> chineseMalesFirstNames;
extern const std::vector<std::string> chineseFemalesFirstNames;
extern const NameFormats chinesePersonNameFormats;
extern const PeopleNames chinesePeopleNames;

// Croatia

extern const std::vector<std::string> croatianMalesFirstNames;
extern const std::vector<std::string> croatianFemalesFirstNames;
extern const std::vector<std::string> croatianLastNames;
extern const std::vector<std::string> croatianSuffixes;
extern const std::vector<std::string> croatianMalesPrefixes;
extern const std::vector<std::string> croatianFemalesPrefixes;
extern const NameFormats croatianPersonNameFormats;
extern const PeopleNames croatianPeopleNames;

// Czechia

extern const std::vector<std::string> czechMalesFirstNames;
extern const std::vector<std::string> czechFemalesFirstNames;
extern const std::vector<std::string> czechMalesLastNames;
extern const std::vector<std::string> czechFemalesLastNames;
extern const std::vector<std::string> czechPrefixes;
extern const std::vector<std::string> czechSuffixes;
extern const NameFormats czechPersonNameFormats;
extern const PeopleNames czechPeopleNames;

// Denmark

extern const std::vector<std::string> danishMalesFirstNames;
extern const std::vector<std::string> danishFemalesFirstNames;
extern const std::vector<std::string> danishLastNames;
extern const std::vector<std::string> danishMiddleNames;
extern const std::vector<std::string> danishMalesPrefixes;
extern const std::vector<std::string> danishFemalesPrefixes;
extern const NameFormats danishPersonNameFormats;
extern const PeopleNames danishPeopleNames;

// Dutch

extern const std::vector<std::string> dutchMalesFirstNames;
extern const std::vector<std::string> dutchFemalesFirstNames;
extern const std::vector<std::string> dutchLastNames;
extern const std::vector<std::string> dutchSuffixes;
extern const std::vector<std::string> dutchMalesPrefixes;
extern const std::vector<std::string> dutchFemalesPrefixes;
extern const NameFormats dutchPersonNameFormats;
extern const PeopleNames dutchPeopleNames;

// England

extern const std::vector<std::string> englishMalesFirstNames;
extern const std::vector<std::string> englishFemalesFirstNames;
extern const std::vector<std::string> englishLastNames;
extern const std::vector<std::string> englishSuffixes;
extern const std::vector<std::string> englishMalesPrefixes;
extern const std::vector<std::string> englishFemalesPrefixes;
extern const NameFormats englishPersonNameFormats;
extern const PeopleNames englishPeopleNames;

// Estonia

extern const std::vector<std::string> estonianMalesFirstNames;
extern const std::vector<std::string> estonianFemalesFirstNames;
extern const std::vector<std::string> estonianLastNames;
extern const NameFormats estonianPersonNameFormats;
extern const PeopleNames estonianPeopleNames;

// Finland

extern const std::vector<std::string> finnishMalesFirstNames;
extern const std::vector<std::string> finnishFemalesFirstNames;
extern const std::vector<std::string> finnishLastNames;
extern const NameFormats finnishPersonNameFormats;
extern const PeopleNames finnishPeopleNames;

// France

extern const std::vector<std::string> frenchMalesFirstNames;
extern const std::vector<std::string> frenchFemalesFirstNames;
extern const std::vector<std::string> frenchLastNames;
extern const std::vector<std::string> frenchMalesPrefixes;
extern const std::vector<std::string> frenchFemalesPrefixes;
extern const NameFormats frenchPersonNameFormats;
extern const PeopleNames frenchPeopleNames;

// Germany

extern const std::vector<std::string> germanMalesFirstNames;
extern const std::vector<std::string> germanFemalesFirstNames;
extern const std::vector<std::string> germanLastNames;
extern const std::vector<std::string> germanMalesPrefixes;
extern const std::vector<std::string> germanFemalesPrefixes;
extern const NameFormats germanPersonNameFormats;
extern const PeopleNames germanPeopleNames;

// Ghana

extern const std::vector<std::string> ghanaianMalesFirstNames;
extern const std::vector<std::string> ghanaianFemalesFirstNames;
extern const std::vector<std::string> ghanaianLastNames;
extern const NameFormats ghanaianPersonNameFormats;
extern const PeopleNames ghanaianPeopleNames;

// Greece

extern const std::vector<std::string> greekMalesFirstNames;
extern const std::vector<std::string> greekFemalesFirstNames;
extern const std::vector<std::string> greekLastNames;
extern const NameFormats greekPersonNameFormats;
extern const PeopleNames greekPeopleNames;

// Hungary

extern const std::vector<std::string> hungarianMalesFirstNames;
extern const std::vector<std::string> hungarianFemalesFirstNames;
extern const std::vector<std::string> hungarianLastNames;
extern const std::vector<std::string> hungarianPrefixes;
extern const NameFormats hungarianPersonNameFormats;
extern const PeopleNames hungarianPeopleNames;

// Iceland

extern const std::vector<std::string> icelandicMalesFirstNames;
extern const std::vector<std::string> icelandicFemalesFirstNames;
extern const std::vector<std::string> icelandicLastNames;
extern const NameFormats icelandicPersonNameFormats;
extern const PeopleNames icelandicPeopleNames;

// India

extern const std::vector<std::string> indianMalesFirstNames;
extern const std::vector<std::string> indianFemalesFirstNames;
extern const std::vector<std::string> indianLastNames;
extern const NameFormats indianPersonNameFormats;
extern const PeopleNames indianPeopleNames;

// Ireland

extern const std::vector<std::string> irishMalesFirstNames;
extern const std::vector<std::string> irishFemalesFirstNames;
extern const std::vector<std::string> irishLastNames;
extern const std::vector<std::string> irishSuffixes;
extern const std::vector<std::string> irishMalesPrefixes;
extern const std::vector<std::string> irishFemalesPrefixes;

// TODO: add handling lastName-lastName

extern const NameFormats irishPersonNameFormats;
extern const PeopleNames irishPeopleNames;

// Israel

extern const std::vector<std::string> israelisMalesFirstNames;
extern const std::vector<std::string> israelisFemalesFirstNames;
extern const std::vector<std::string> israelisLastNames;
extern const NameFormats israelisPersonNameFormats;
extern const PeopleNames israeliPeopleNames;

// Italy

extern const std::vector<std::string> italianMalesFirstNames;
extern const std::vector<std::string> italianFemalesFirstNames;
extern const std::vector<std::string> italianLastNames;
extern const std::vector<std::string> italianPrefixes;
extern const NameFormats italianPersonNameFormats;
extern const PeopleNames italianPeopleNames;

// Japan

extern const std::vector<std::string> japaneseMaleFirstNames;
extern const std::vector<std::string> japaneseFemaleFirstNames;
extern const std::vector<std::string> japaneseLastNames;
extern const NameFormats japanesePeopleNameFormats;
extern const PeopleNames japanesePeopleNames;

// Kazakhstan

extern const std::vector<std::string> kazakhMalesFirstNames;
extern const std::vector<std::string> kazakhFemalesFirstNames;
extern const std::vector<std::string> kazakhMalesLastNames;
extern const std::vector<std::string> kazakhFemalesLastNames;
extern const NameFormats kazakhPersonNameFormats;
extern const PeopleNames kazakhPeopleNames;

// Korea

extern const std::vector<std::string> koreanFirstNames;
extern const std::vector<std::string> koreanLastNames;
extern const NameFormats koreanPersonNameFormats;
extern const PeopleNames koreanPeopleNames;

// Latvia

extern const std::vector<std::string> latvianMalesFirstNames;
extern const std::vector<std::string> latvianFemalesFirstNames;
extern const std::vector<std::string> latvianMalesLastNames;
extern const std::vector<std::string> latvianFemalesLastNames;
extern const std::vector<std::string> latvianSuffixes;
extern const std::vector<std::string> latvianPrefixes;
extern const NameFormats latvianPersonNameFormats;
extern const PeopleNames latvianPeopleNames;

// Lebanon

extern const std::vector<std::string> lebaneseMalesFirstNames;
extern const std::vector<std::string> lebaneseFemalesFirstNames;
extern const std::vector<std::string> lebaneseLastNames;
extern const NameFormats lebanesePersonNameFormats;
extern const PeopleNames lebanesePeopleNames;

// Lithuania

extern const std::vector<std::string> lithuanianMalesFirstNames;
extern const std::vector<std::string> lithuanianFemalesFirstNames;
extern const std::vector<std::string> lithuanianLastNames;
extern const NameFormats lithuanianPersonNameFormats;
extern const PeopleNames lithuanianPeopleNames;

// Macedonia

extern const std::vector<std::string> macedonianMalesFirstNames;
extern const std::vector<std::string> macedonianFemalesFirstNames;
extern const std::vector<std::string> macedonianMalesLastNames;
extern const std::vector<std::string> macedonianFemalesLastNames;
extern const std::vector<std::string> macedonianMalesPrefixes;
extern const std::vector<std::string> macedonianFemalesPrefixes;
extern const NameFormats macedonianPersonNameFormats;
extern const PeopleNames macedonianPeopleNames;

// Maldives

extern const std::vector<std::string> maldiviansMalesFirstNames;
extern const std::vector<std::string> maldiviansFemalesFirstNames;
extern const std::vector<std::string> maldiviansMalesLastNames;
extern const std::vector<std::string> maldiviansFemalesLastNames;
extern const std::vector<std::string> maldiviansMalesPrefixes;
extern const std::vector<std::string> maldiviansFemalesPrefixes;
extern const NameFormats maldiviansPersonNameFormats;
extern const PeopleNames maldiviansPeopleNames;

// Malta

extern const std::vector<std::string> malteseMalesFirstNames;
extern const std::vector<std::string> malteseFemalesFirstNames;
extern const std::vector<std::string> malteseLastNames;
extern const NameFormats maltesePersonNameFormats;
extern const PeopleNames maltesePeopleNames;

// Mexico

extern const std::vector<std::string> mexicanMalesFirstNames;
extern const std::vector<std::string> mexicanFemalesFirstNames;
extern const std::vector<std::string> mexicanLastNames;
extern const std::vector<std::string> mexicanSuffixes;
extern const std::vector<std::string> mexicanMalesPrefixes;
extern const std::vector<std::string> mexicanFemalesPrefixes;
extern const NameFormats mexicanPersonNameFormats;
extern const PeopleNames mexicanPeopleNames;

// Moldova

extern const std::vector<std::string> moldovanMalesFirstNames;
extern const std::vector<std::string> moldovanFemalesFirstNames;
extern const std::vector<std::string> moldovanLastNames;
extern const NameFormats moldovanPersonNameFormats;
extern const PeopleNames moldovanPeopleNames;

// Monaco

extern const std::vector<std::string> monacanMalesFirstNames;
extern const std::vector<std::string> monacanFemalesFirstNames;
extern const std::vector<std::string> monacanLastNames;
extern const NameFormats monacanPersonNameFormats;
extern const PeopleNames monacanPeopleNames;

// Nepal

extern const std::vector<std::string> nepaleseMalesFirstNames;
extern const std::vector<std::string> nepaleseFemalesFirstNames;
extern const std::vector<std::string> nepaleseLastNames;
extern const NameFormats nepalesePersonNameFormats;
extern const PeopleNames nepalesePeopleNames;

// Norway

extern const std::vector<std::string> norwegianMalesFirstNames;
extern const std::vector<std::string> norwegianFemalesFirstNames;
extern const std::vector<std::string> norwegianLastNames;
extern const std::vector<std::string> norwegianSuffixes;
extern const std::vector<std::string> norwegianPrefixes;
extern const NameFormats norwegianPersonNameFormats;
extern const PeopleNames norwegianPeopleNames;

// Palestine

extern const std::vector<std::string> palestinianMalesFirstNames;
extern const std::vector<std::string> palestinianFemalesFirstNames;
extern const std::vector<std::string> palestinianLastNames;
extern const NameFormats palestinianPersonNameFormats;
extern const PeopleNames palestinianPeopleNames;

// Persian

extern const std::vector<std::string> persianMalesFirstNames;
extern const std::vector<std::string> persianFemalesFirstNames;
extern const std::vector<std::string> persianLastNames;
extern const std::vector<std::string> persianMalesPrefixes;
extern const std::vector<std::string> persianFemalesPrefixes;
extern const NameFormats persianPersonNameFormats;
extern const PeopleNames persianPeopleNames;

// Poland

extern const std::vector<std::string> polishMalesFirstNames;
extern const std::vector<std::string> polishFemalesFirstNames;
extern const std::vector<std::string> polishLastNames;
extern const std::vector<std::string> polishMalesPrefixes;
extern const std::vector<std::string> polishFemalesPrefixes;
extern const NameFormats polishPersonNameFormats;
extern const PeopleNames polishPeopleNames;

// Portugal

extern const std::vector<std::string> portugueseMalesFirstNames;
extern const std::vector<std::string> portugueseFemalesFirstNames;
extern const std::vector<std::string> portugueseLastNames;
extern const std::vector<std::string> portugueseMalesPrefixes;
extern const std::vector<std::string> portugueseFemalesPrefixes;
extern const NameFormats portuguesePersonNameFormats;
extern const PeopleNames portuguesePeopleNames;

// Romania

extern const std::vector<std::string> romanianMalesFirstNames;
extern const std::vector<std::string> romanianFemalesFirstNames;
extern const std::vector<std::string> romanianLastNames;
extern const std::vector<std::string> romanianSuffixes;
extern const std::vector<std::string> romanianMalesPrefixes;
extern const std::vector<std::string> romanianFemalesPrefixes;
extern const NameFormats romanianPersonNameFormats;
extern const PeopleNames romanianPeopleNames;

// Russia

extern const std::vector<std::string> russianMalesFirstNames;
extern const std::vector<std::string> russianFemalesFirstNames;
extern const std::vector<std::string> russianMalesLastNames;
extern const std::vector<std::string> russianFemalesLastNames;
extern const std::vector<std::string> russianMalesMiddleNames;
extern const std::vector<std::string> russianFemalesMiddleNames;
extern const NameFormats russianPersonNameFormats;
extern const PeopleNames russianPeopleNames;

// Serbia

extern const std::vector<std::string> serbianMalesFirstNames;
extern const std::vector<std::string> serbianFemalesFirstNames;
extern const std::vector<std::string> serbianLastNames;
extern const NameFormats serbianPersonNameFormats;
extern const PeopleNames serbianPeopleNames;

// Slovakia

extern const std::vector<std::string> slovakMalesFirstNames;
extern const std::vector<std::string> slovakFemalesFirstNames;
extern const std::vector<std::string> slovakMalesLastNames;
extern const std::vector<std::string> slovakFemalesLastNames;
extern const std::vector<std::string> slovakSuffixes;
extern const std::vector<std::string> slovakPrefixes;
extern const NameFormats slovakPersonNameFormats;
extern const PeopleNames slovakPeopleNames;

// Slovenia

extern const std::vector<std::string> slovenianMalesFirstNames;
extern const std::vector<std::string> slovenianFemalesFirstNames;
extern const std::vector<std::string> slovenianLastNames;
extern const NameFormats slovenianPersonNameFormats;
extern const PeopleNames slovenianPeopleNames;

// South Africa

extern const std::vector<std::string> southAfricanMalesFirstNames;
extern const std::vector<std::string> southAfricanFemalesFirstNames;
extern const std::vector<std::string> southAfricanLastNames;
extern const NameFormats southAfricanPersonNameFormats;
extern const PeopleNames southAfricanPeopleNames;

// Spain

extern const std::vector<std::string> spanishMalesFirstNames;
extern const std::vector<std::string> spanishFemalesFirstNames;
extern const std::vector<std::string> spanishLastNames;
extern const std::vector<std::string> spanishMalesPrefixes;
extern const std::vector<std::string> spanishFemalesPrefixes;
extern const NameFormats spanishPersonNameFormats;
extern const PeopleNames spanishPeopleNames;

// Sweden

extern const std::vector<std::string> swedishMalesFirstNames;
extern const std::vector<std::string> swedishFemalesFirstNames;
extern const std::vector<std::string> swedishLastNames;
extern const std::vector<std::string> swedishPrefixes;
extern const NameFormats swedishPersonNameFormats;
extern const PeopleNames swedishPeopleNames;

// Switzerland

extern const std::vector<std::string> swissMalesFirstNames;
extern const std::vector<std::string> swissFemalesFirstNames;
extern const std::vector<std::string> swissLastNames;
extern const std::vector<std::string> swissMalesPrefixes;
extern const std::vector<std::string> swissFemalesPrefixes;
extern const NameFormats swissPersonNameFormats;
extern const PeopleNames swissPeopleNames;

// Syria

extern const std::vector<std::string> syrianMalesFirstNames;
extern const std::vector<std::string> syrianFemalesFirstNames;
extern const std::vector<std::string> syrianLastNames;
extern const NameFormats syrianPersonNameFormats;
extern const PeopleNames syrianPeopleNames;

// Turkey

extern const std::vector<std::string> turkishMalesFirstNames;
extern const std::vector<std::string> turkishFemalesFirstNames;
extern const std::vector<std::string> turkishLastNames;
extern const std::vector<std::string> turkishMalesPrefixes;
extern const std::vector<std::string> turkishFemalesPrefixes;
extern const NameFormats turkishPersonNameFormats;
extern const PeopleNames turkishPeopleNames;

// Ukraine

extern const std::vector<std::string> ukrainianMalesFirstNames;
extern const std::vector<std::string> ukrainianFemalesFirstNames;
extern const std::vector<std::string> ukrainianMalesLastNames;
extern const std::vector<std::string> ukrainianFemalesLastNames;
extern const std::vector<std::string> ukrainianMalesMiddleNames;
extern const std::vector<std::string> ukrainianFemalesMiddleNames;
extern const std::vector<std::string> ukrainianMalesPrefixes;
extern const std::vector<std::string> ukrainianFemalesPrefixes;
extern const NameFormats ukrainianPersonNameFormats;
extern const PeopleNames ukrainianPeopleNames;

// USA

extern const NameFormats usaPersonNameFormats;
extern const PeopleNames usaPeopleNames;

// Vietnam

extern const std::vector<std::string> vietnameseMalesFirstNames;
extern const std::vector<std::string> vietnameseFemalesFirstNames;
extern const std::vector<std::string> vietnameseLastNames;
extern const NameFormats vietnamesePersonNameFormats;
extern const PeopleNames vietnamesePeopleNames;

// Mapping

extern const std::unordered_map<Country, PeopleNames> countryToPeopleNamesMapping;

}

#endif