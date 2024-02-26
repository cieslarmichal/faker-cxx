#ifndef FAKER_STRUCTURE_H
#define FAKER_STRUCTURE_H

#include <string>
#include <unordered_map>

namespace faker::structure {
enum class StructureToken {
    // Airline module
    AirlineAircraftType,
    AirlineAirplaneName,
    AirlineAirplaneCode,
    AirlineAirlineName,
    AirlineAirlineCode,
    AirlineAirportName,
    AirlineAirportCode,
    AirlineSeat,
    AirlineRecordLocator,
    AirlineFlightNumber,

    // Animal module
    AnimalBear,
    AnimalBird,
    AnimalCat,
    AnimalCetacean,
    AnimalCow,
    AnimalCrocodilia,
    AnimalDog,
    AnimalFish,
    AnimalHorse,
    AnimalInsect,
    AnimalLion,
    AnimalRabbit,
    AnimalRodent,
    AnimalSnake,
    AnimalType,

    // Book module
    BookTitle,
    BookGenre,
    BookAuthor,
    BookPublisher,
    BookIsbn,

    // Color module
    ColorName,
    ColorRGB,
    ColorHEX,
    ColorHSL,
    ColorLCH,
    ColorCMYK,

    // Commerce module
    CommerceDepartment,
    CommercePrice,
    CommerceSku,
    CommerceProductAdjective,
    CommerceProductMaterial,
    CommerceProductName,
    CommerceProductFullName,
    CommerceEAN13,
    CommerceEAN8,
    CommerceISBN13,
    CommerceISBN10,

    // Company module
    CompanyName,
    CompanyType,
    CompanyIndustry,
    CompanyBuzzPhrase,
    CompanyBuzzAdjective,
    CompanyBuzzNoun,
    CompanyBuzzVerb,
    CompanyCatchPhrase,
    CompanyCtachPhraseAdjective,
    CompanyCatchPhraseDescriptor,
    CompanyCatchPhraseNoun,

    // Computer module
    ComputerType,
    ComputerManufacture,
    ComputerModel,
    ComputerCPUManufacture,
    ComputerCPUType,
    ComputerCPUModel,
    ComputerGPUManufacture,
    ComputerGPUType,
    ComputerGPUModel,

    // Crypto module
    CryptoSHA256,
    CryptoMD5,

    // Database module
    DatabaseColumnName,
    DatabaseColumnType,
    DatabaseCollation,
    DatabaseEngine,
    DatabaseMongoDBObjectId,

    // Datatype module
    DatatypeBoolean,

    // Date module ISO and Timestamp
    DatePastDateISO,
    DatePastDateTimestamp,
    DatefutureDateISO,
    DatefutureDateTimestamp,
    DateRecentDateISO,
    DateRecentDateTimestamp,
    DateSoonDateISO,
    DateSoonDateTimestamp,
    DateBirthdateByAgeISO,
    DateBirthdateByAgeTimestamp,
    DateBirthdateByYearISO,
    DateBirthdateByYearTimestamp,
    DateWeekdayName,
    DateWeekdayAbbreviatedName,
    DateMontName,
    DateMonthAbbreviatedName,

    // Finance module
    FinanceCurrencyName,
    FinanceCurrencyCode,
    FinanceCurrencySymbol,
    FinanceAccountType,
    FinanceAmount,
    FinanceIban,
    FinanceBic,
    FinanceAccountNumber,
    FinancePin,
    FinanceRoutingNumber,
    FinanceCreditCardNumber,
    FinanceCreditCardCvv,
    FinanceBitcoinAddress,
    FinanceLitecoinAddress,
    FinanceEthereumAddress,

    // Food module
    FoodAlcoholicBeverage,
    FoodGrain,
    FoodMilkProduct,
    FoodFruit,
    FoodMeat,
    FoodSeafood,
    FoodVegetable,
    FoodOil,
    FoodNut,
    FoodSeed,
    FoodSugarProduct,
    FoodNonAlcoholicBeverage,
    FoodDishName,
    FoodFoodCategory,

    // Git module
    GitBranch,
    GitCommitDate,
    GitCommitEntry,
    GitCommitMessage,
    GitCommitSha,

    // Hacker module
    HackerAbbreviation,
    HackerAdjective,
    HackerNoun,
    HackerVerb,
    HackerIngverb,
    HackerPhrase,

    // Image module
    ImageImageURL,
    ImageGitHubAvatarURL,
    ImageDimensions,

    // Internet module
    InternetUsername,
    InternetEmail,
    InternetExampleEmail,
    InternetPassword,
    InternetEmoji,
    InternetProtocol,
    InternetHttpMethod,
    InternetHttpRequestHeader,
    InternetHttpResponseHeader,
    InternetHttpMediaType,
    InternetIpv4,
    InternetIpv6,
    InternetMac,
    InternetURL,
    InternetDomainName,
    InternetDomainWord,
    InternetDomainSuffix,

    // Location module
    LocationCountry,
    LocationCountryCode,
    LocationState,
    LocationCity,
    LocationZipCode,
    LocationStreetAddress,
    LocationStreet,
    LocationBuildingNumber,
    LocationSecondaryAddress,
    LocationLatitude,
    LocationLongitude,
    LocationDirection,
    LocationTimeZone,

    // Lorem module
    LoremWord,
    LoremWords,
    LoremSentence,
    LoremSentences,
    LoremSlung,
    LoremParagraph,
    LoremParagraphs,

    // Medicine module
    MedicineCondition,
    MedicineMedicalTest,
    MedicineSpecialty,

    // Movie module
    MovieGenre,
    MovieMovieTitle,
    MovieTvShow,
    MovieDirector,
    MovieActor,
    MovieActress,

    // Music module
    MusicArtist,
    MusicGenre,
    MusicSongName,

    // Person module
    PersonFirstName,
    PersonLastName,
    PersonMiddleName,
    PersonFullName,
    PersonPrefix,
    PersonSuffix,
    PersonSex,
    PersonGender,
    PersonJobTitle,
    PersonJobDescriptor,
    PersonJobArea,
    PersonJobType,
    PersonHoby,
    PersonLanguage,
    PersonNationality,
    PersonWesternZodiac,
    PersonChineseZodiac,

    // Phone module
    PhoneNumber,
    PhonePlatform,
    PhoneModelName,
    PhoneManufacturer,
    PhoneIMEI,

    // Sport module
    SportSport,
    SportSoccerTeam,
    SportMaleAthelete,
    SportFemaleAthlete,
    SportSportEvent,

    // System module
    SystemFileName,
    SystemFileExtension,
    SystemCommonFileName,
    SystemCommonFileExtension,
    SystemMimeType,
    SystemCommonFileType,
    SystemFileType,
    SystemDirectoryPath,
    SystemFilePath,
    SystemSemver,
    SystemNetworkInterface,
    SystemCron,

    // VideoGame module
    VideoGameGameTitle,
    VideoGameGenre,
    VideoGamePlatform,
    VideoGameStudioName,

    // Weather module
    WeatherTemperatureMetric,
    WeatherTemperatureImperial,
    WeatherPressureMetric,
    WeatherPressureImperial,
    WeatherVisibilityMetric,
    WeatherVisibilityImperial,
    WeatherWindSpeedMetric,
    WeatherWindSpeedImperial,
    WeatherUvIndex,
    WeatherHumidity,
    WeatherWeatherDescription,
    WeatherCloudCover,

    // Word module
    WordSample,
    WordWords,
    WordAdjective,
    WordAdverb,
    WordConjunction,
    WordInterjection,
    WordNoun,
    WordPreposition,
    WordVerb,
};

/**
 * @brief Get a json string based on input
 *
 * @return a json string based on user selected tokens
 *
 * @code
 * std::unordered_map<std::string, StructureToken> testTokens;
 * testTokens.emplace("Airport name", StructureToken::AirlineAirportName);
 * testTokens.emplace("Bird name", StructureToken::AnimalBird);
 * testTokens.emplace("Actor name", StructureToken::MovieActor);
 * testTokens.emplace("Book title", StructureToken::BookTitle);
 * structure::json(testTokens) // {"FoodName":"Cajun Shrimp
 * Pasta","airlineType":"narrowbody","airportName":"Brisbane International Airport"}
 * @endcode
 */
std::string json(const std::unordered_map<std::string, StructureToken>& items);
/**
 * @brief Get a csv string based on input
 *
 * @return a josn csv based on user selected tokens and rows
 *
 * @code
 * std::unordered_map<std::string, StructureToken> testTokens;
 * testTokens.emplace("Airport name", StructureToken::AirlineAirportName);
 * testTokens.emplace("Bird name", StructureToken::AnimalBird);
 * testTokens.emplace("Actor name", StructureToken::MovieActor);
 * testTokens.emplace("Book title", StructureToken::BookTitle);
 * structure::csv(testTokens,2) // FoodName,airlineType,airportName
                              Lobster Roll,widebody,Soekarno-Hatta International Airport
                              Pierogi,widebody,Brasilia-Presidente Juscelino Kubitschek
 International Airport
 * @endcode
 */
std::string csv(const std::unordered_map<std::string, StructureToken>& items, unsigned int rows);
}

#endif