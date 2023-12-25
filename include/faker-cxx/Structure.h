#pragma once
#include <functional>
#include <map>
#include <string>

#include "Airline.h"
#include "Animal.h"
#include "Book.h"
#include "Color.h"
#include "Commerce.h"
#include "Company.h"
#include "Computer.h"
#include "Crypto.h"
#include "Database.h"
#include "Datatype.h"
#include "Date.h"
#include "Finance.h"
#include "Food.h"
#include "Git.h"
#include "Hacker.h"
#include "Helper.h"
#include "Image.h"
#include "Internet.h"
#include "Location.h"
#include "Lorem.h"
#include "Medicine.h"
#include "Movie.h"
#include "Music.h"
#include "Person.h"
#include "Phone.h"
#include "Sport.h"
#include "String.h"
#include "System.h"
#include "VideoGame.h"
#include "Weather.h"
#include "Word.h"

namespace faker
{
struct test
{
    Airline::AircraftType aircraftType;
};

enum class Token
{
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

    // Date module
    DatePastDate,
    DatefutureDate,
    DateRecentDate,
    DateSoonDate,
    DateBirthdateByAge,
    DateBirthdateByYear,
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
    WeatherCloadCover,

    // Word module
    WordSample,
    WordWords,
    WordAdjective,
    WordAdverb,
    WordConjuction,
    WordInterjection,
    WordNoun,
    WordPreposition,
    WordVerb,

};

const std::map<Token, std::function<std::string()>> moduleFunctions = {
    {Token::AirlineAircraftType, []() { return Airline::aircraftType(); }},
    {Token::AirlineAirplaneName, []() { return Airline::airplane().name; }},
    {Token::AirlineAirplaneCode, []() { return Airline::airplane().iataTypeCode; }},
    {Token::AirlineAirplaneName, []() { return Airline::airplane().name; }},
    {Token::AirlineAirplaneCode, []() { return Airline::airplane().iataTypeCode; }},
    {Token::AirlineAirlineName, []() { return Airline::airline().name; }},
    {Token::AirlineAirlineCode, []() { return Airline::airline().iataCode; }},
    {Token::AirlineAirportName, []() { return Airline::airport().name; }},
    {Token::AirlineAirportCode, []() { return Airline::airport().iataCode; }},
    {Token::AirlineSeat, []() { return Airline::seat(Airline::AircraftType()); }},
    {Token::AirlineRecordLocator, []() { return Airline::recordLocator(); }},
    {Token::AirlineFlightNumber, []() { return Airline::flightNumber(false, 4); }},

    {Token::AnimalBear, []() { return Animal::bear(); }},
    {Token::AnimalBird, []() { return Animal::bird(); }},
    {Token::AnimalCat, []() { return Animal::cat(); }},
    {Token::AnimalCetacean, []() { return Animal::cetacean(); }},
    {Token::AnimalCow, []() { return Animal::cow(); }},
    {Token::AnimalCrocodilia, []() { return Animal::crocodilia(); }},
    {Token::AnimalDog, []() { return Animal::dog(); }},
    {Token::AnimalFish, []() { return Animal::fish(); }},
    {Token::AnimalHorse, []() { return Animal::horse(); }},
    {Token::AnimalInsect, []() { return Animal::insect(); }},
    {Token::AnimalLion, []() { return Animal::lion(); }},
    {Token::AnimalRabbit, []() { return Animal::rabbit(); }},
    {Token::AnimalRodent, []() { return Animal::rodent(); }},
    {Token::AnimalSnake, []() { return Animal::snake(); }},
    {Token::AnimalType, []() { return Animal::type(); }},

    {Token::BookTitle, []() { return Book::title(); }},
    {Token::BookGenre, []() { return Book::genre(); }},
    {Token::BookAuthor, []() { return Book::author(); }},
    {Token::BookPublisher, []() { return Book::publisher(); }},
    {Token::BookIsbn, []() { return Book::isbn(); }},

    {Token::ColorName, []() { return Color::name(); }},
    {Token::ColorRGB, []() { return Color::rgb(); }},
    {Token::ColorHEX, []() { return Color::hex(); }},
    {Token::ColorHSL, []() { return Color::hsl(); }},
    {Token::ColorLCH, []() { return Color::lch(); }},
    {Token::ColorCMYK, []() { return Color::cmyk(); }},

    {Token::CommerceDepartment, []() { return Commerce::department(); }},
    {Token::CommercePrice, []() { return Commerce::price(); }},
    {Token::CommerceSku, []() { return Commerce::sku(); }},
    {Token::CommerceProductAdjective, []() { return Commerce::productAdjective(); }},
    {Token::CommerceProductMaterial, []() { return Commerce::productMaterial(); }},
    {Token::CommerceProductName, []() { return Commerce::productName(); }},
    {Token::CommerceProductFullName, []() { return Commerce::productFullName(); }},
    {Token::CommerceEAN13, []() { return Commerce::EAN13(); }},
    {Token::CommerceEAN8, []() { return Commerce::EAN8(); }},
    {Token::CommerceISBN13, []() { return Commerce::ISBN13(); }},
    {Token::CommerceISBN10, []() { return Commerce::ISBN10(); }},

    {Token::CompanyName, []() { return Company::name(); }},
    {Token::CompanyType, []() { return Company::type(); }},
    {Token::CompanyIndustry, []() { return Company::industry(); }},
    {Token::CompanyBuzzPhrase, []() { return Company::buzzPhrase(); }},
    {Token::CompanyBuzzAdjective, []() { return Company::buzzAdjective(); }},
    {Token::CompanyBuzzNoun, []() { return Company::buzzNoun(); }},
    {Token::CompanyBuzzVerb, []() { return Company::buzzVerb(); }},
    {Token::CompanyCatchPhrase, []() { return Company::catchPhrase(); }},
    {Token::CompanyCtachPhraseAdjective, []() { return Company::catchPhraseAdjective(); }},
    {Token::CompanyCatchPhraseDescriptor, []() { return Company::catchPhraseDescriptor(); }},
    {Token::CompanyCatchPhraseNoun, []() { return Company::catchPhraseNoun(); }},

    {Token::ComputerManufacture, []() { return Computer::manufacture(); }},
    {Token::ComputerModel, []() { return Computer::model(); }},
    {Token::ComputerCPUManufacture, []() { return Computer::cpuManufacture(); }},
    {Token::ComputerCPUType, []() { return Computer::cpuType(); }},
    {Token::ComputerCPUModel, []() { return Computer::cpuModel(); }},
    {Token::ComputerGPUManufacture, []() { return Computer::gpuManufacture(); }},
    {Token::ComputerGPUType, []() { return Computer::gpuType(); }},
    {Token::ComputerGPUModel, []() { return Computer::gpuModel(); }},

    {Token::CryptoSHA256, []() { return Crypto::sha256(); }},
    {Token::CryptoMD5, []() { return Crypto::md5(); }},

    {Token::DatabaseColumnName, []() { return Database::columnName(); }},
    {Token::DatabaseColumnType, []() { return Database::columnType(); }},
    {Token::DatabaseCollation, []() { return Database::collation(); }},
    {Token::DatabaseEngine, []() { return Database::engine(); }},
    {Token::DatabaseMongoDBObjectId, []() { return Database::mongoDbObjectId(); }},

    {Token::DatatypeBoolean, []() { return std::to_string(Datatype::boolean()); }},

    {Token::DatePastDate, []() { return Date::pastDate(); }},
    {Token::DatefutureDate, []() { return Date::futureDate(); }},
    {Token::DateRecentDate, []() { return Date::recentDate(); }},
    {Token::DateSoonDate, []() { return Date::soonDate(); }},
    {Token::DateBirthdateByAge, []() { return Date::birthdateByAge(); }},
    {Token::DateBirthdateByYear, []() { return Date::birthdateByYear(); }},
    {Token::DateWeekdayName, []() { return Date::weekdayName(); }},
    {Token::DateWeekdayAbbreviatedName, []() { return Date::weekdayAbbreviatedName(); }},
    {Token::DateMontName, []() { return Date::monthName(); }},
    {Token::DateMonthAbbreviatedName, []() { return Date::monthAbbreviatedName(); }},

    {Token::FinanceCurrencyName, []() { return Finance::currencyName(); }},
    {Token::FinanceCurrencyCode, []() { return Finance::currencyCode(); }},
    {Token::FinanceCurrencySymbol, []() { return Finance::currencySymbol(); }},
    {Token::FinanceAccountType, []() { return Finance::accountType(); }},
    {Token::FinanceAmount, []() { return Finance::amount(); }},
    {Token::FinanceIban, []() { return Finance::iban(); }},
    {Token::FinanceBic, []() { return Finance::bic(); }},
    {Token::FinanceAccountNumber, []() { return Finance::accountNumber(); }},
    {Token::FinancePin, []() { return Finance::pin(); }},
    {Token::FinanceRoutingNumber, []() { return Finance::routingNumber(); }},
    {Token::FinanceCreditCardNumber, []() { return Finance::creditCardNumber(); }},
    {Token::FinanceCreditCardCvv, []() { return Finance::creditCardCvv(); }},
    {Token::FinanceBitcoinAddress, []() { return Finance::bitcoinAddress(); }},
    {Token::FinanceLitecoinAddress, []() { return Finance::litecoinAddress(); }},
    {Token::FinanceEthereumAddress, []() { return Finance::ethereumAddress(); }},

    {Token::FoodAlcoholicBeverage, []() { return Food::alcoholicBeverage(); }},
    {Token::FoodGrain, []() { return Food::grain(); }},
    {Token::FoodMilkProduct, []() { return Food::milkProduct(); }},
    {Token::FoodFruit, []() { return Food::fruit(); }},
    {Token::FoodMeat, []() { return Food::meat(); }},
    {Token::FoodSeafood, []() { return Food::seafood(); }},
    {Token::FoodVegetable, []() { return Food::vegetable(); }},
    {Token::FoodOil, []() { return Food::oil(); }},
    {Token::FoodNut, []() { return Food::nut(); }},
    {Token::FoodSeed, []() { return Food::seed(); }},
    {Token::FoodSugarProduct, []() { return Food::sugarProduct(); }},
    {Token::FoodNonAlcoholicBeverage, []() { return Food::nonalcoholicBeverage(); }},
    {Token::FoodDishName, []() { return Food::dishName(); }},
    {Token::FoodFoodCategory, []() { return Food::foodCategory(); }},

    {Token::GitBranch, []() { return Git::branch(); }},
    {Token::GitCommitDate, []() { return Git::commitDate(); }},
    {Token::GitCommitEntry, []() { return Git::commitEntry(); }},
    {Token::GitCommitMessage, []() { return Git::commitMessage(); }},
    {Token::GitCommitSha, []() { return Git::commitSha(); }},

    {Token::HackerAbbreviation, []() { return Hacker::abbreviation(); }},
    {Token::HackerAdjective, []() { return Hacker::adjective(); }},
    {Token::HackerNoun, []() { return Hacker::noun(); }},
    {Token::HackerVerb, []() { return Hacker::verb(); }},
    {Token::HackerIngverb, []() { return Hacker::ingverb(); }},
    {Token::HackerPhrase, []() { return Hacker::phrase(); }},

    {Token::ImageImageURL, []() { return Image::imageUrl(); }},
    {Token::ImageGitHubAvatarURL, []() { return Image::githubAvatarUrl(); }},
    {Token::ImageDimensions, []() { return Image::dimensions(); }},

    {Token::InternetUsername, []() { return Internet::username(); }},
    {Token::InternetEmail, []() { return Internet::email(); }},
    {Token::InternetExampleEmail, []() { return Internet::exampleEmail(); }},
    {Token::InternetPassword, []() { return Internet::password(); }},
    {Token::InternetEmoji, []() { return Internet::emoji(); }},
    {Token::InternetProtocol, []() { return Internet::protocol(); }},
    {Token::InternetHttpMethod, []() { return Internet::httpMethod(); }},
    {Token::InternetHttpRequestHeader, []() { return Internet::httpRequestHeader(); }},
    {Token::InternetHttpResponseHeader, []() { return Internet::httpResponseHeader(); }},
    {Token::InternetHttpMediaType, []() { return Internet::httpMediaType(); }},
    {Token::InternetIpv4, []() { return Internet::ipv4(); }},
    {Token::InternetIpv6, []() { return Internet::ipv6(); }},
    {Token::InternetMac, []() { return Internet::mac(); }},
    {Token::InternetURL, []() { return Internet::url(); }},
    {Token::InternetDomainName, []() { return Internet::domainName(); }},
    {Token::InternetDomainWord, []() { return Internet::domainWord(); }},
    {Token::InternetDomainSuffix, []() { return Internet::domainSuffix(); }},

    {Token::LocationCountry, []() { return Location::country(); }},
    {Token::LocationCountryCode, []() { return Location::countryCode(); }},
    {Token::LocationState, []() { return Location::state(); }},
    {Token::LocationCity, []() { return Location::city(); }},
    {Token::LocationZipCode, []() { return Location::zipCode(); }},
    {Token::LocationStreetAddress, []() { return Location::streetAddress(); }},
    {Token::LocationStreet, []() { return Location::street(); }},
    {Token::LocationBuildingNumber, []() { return Location::buildingNumber(); }},
    {Token::LocationSecondaryAddress, []() { return Location::secondaryAddress(); }},
    {Token::LocationLatitude, []() { return Location::latitude(); }},
    {Token::LocationLongitude, []() { return Location::longitude(); }},
    {Token::LocationDirection, []() { return Location::direction(); }},
    {Token::LocationTimeZone, []() { return Location::timeZone(); }},

    // Lorem module
    {Token::LoremWord, []() { return Lorem::word(); }},
    {Token::LoremWords, []() { return Lorem::words(); }},
    {Token::LoremSentence, []() { return Lorem::sentence(); }},
    {Token::LoremSentences, []() { return Lorem::sentences(); }},
    {Token::LoremSlung, []() { return Lorem::slug(10); }},
    {Token::LoremParagraph, []() { return Lorem::paragraph(); }},
    {Token::LoremParagraphs, []() { return Lorem::paragraphs(); }},

    // Medicine module
    {Token::MedicineCondition, []() { return Medicine::condition(); }},
    {Token::MedicineMedicalTest, []() { return Medicine::medicalTest(); }},
    {Token::MedicineSpecialty, []() { return Medicine::specialty(); }},

    // Movie module
    {Token::MovieGenre, []() { return Movie::genre(); }},
    {Token::MovieMovieTitle, []() { return Movie::movieTitle(); }},
    {Token::MovieTvShow, []() { return Movie::tvShow(); }},
    {Token::MovieDirector, []() { return Movie::director(); }},
    {Token::MovieActor, []() { return Movie::actor(); }},
    {Token::MovieActress, []() { return Movie::actress(); }},

    // Music module
    {Token::MusicArtist, []() { return Music::artist(); }},
    {Token::MusicGenre, []() { return Music::genre(); }},
    {Token::MusicSongName, []() { return Music::songName(); }},

    // Person module
    {Token::PersonFirstName, []() { return Person::firstName(); }},
    {Token::PersonLastName, []() { return Person::lastName(); }},
    {Token::PersonMiddleName, []() { return Person::middleName(); }},
    {Token::PersonFullName, []() { return Person::fullName(); }},
    {Token::PersonPrefix, []() { return Person::prefix(); }},
    {Token::PersonSuffix, []() { return Person::suffix(); }},
    {Token::PersonSex, []() { return Person::sex(); }},
    {Token::PersonGender, []() { return Person::gender(); }},
    {Token::PersonJobTitle, []() { return Person::jobTitle(); }},
    {Token::PersonJobDescriptor, []() { return Person::jobDescriptor(); }},
    {Token::PersonJobArea, []() { return Person::jobArea(); }},
    {Token::PersonJobType, []() { return Person::jobType(); }},
    {Token::PersonHoby, []() { return Person::hobby(); }},
    {Token::PersonLanguage, []() { return Person::language(); }},
    {Token::PersonNationality, []() { return Person::nationality(); }},
    {Token::PersonWesternZodiac, []() { return Person::westernZodiac(); }},
    {Token::PersonChineseZodiac, []() { return Person::chineseZodiac(); }},

    // Phone module
    {Token::PhoneNumber, []() { return Phone::number(); }},
    {Token::PhonePlatform, []() { return Phone::platform(); }},
    {Token::PhoneModelName, []() { return Phone::modelName(); }},
    {Token::PhoneManufacturer, []() { return Phone::manufacturer(); }},
    {Token::PhoneIMEI, []() { return Phone::imei(); }},

    // Sport module
    {Token::SportSport, []() { return Sport::sport(); }},
    {Token::SportSoccerTeam, []() { return Sport::soccerTeam(); }},
    {Token::SportMaleAthelete, []() { return Sport::maleAthlete(); }},
    {Token::SportFemaleAthlete, []() { return Sport::femaleAthlete(); }},
    {Token::SportSportEvent, []() { return Sport::sportEvent(); }},

    // System module
    {Token::SystemFileName, []() { return System::fileName(); }},
    {Token::SystemFileExtension, []() { return System::fileExtension(); }},
    {Token::SystemCommonFileName, []() { return System::commonFileName(); }},
    {Token::SystemCommonFileExtension, []() { return System::commonFileExtension(); }},
    {Token::SystemMimeType, []() { return System::mimeType(); }},
    {Token::SystemCommonFileType, []() { return System::commonFileType(); }},
    {Token::SystemFileType, []() { return System::fileType(); }},
    {Token::SystemDirectoryPath, []() { return System::directoryPath(); }},
    {Token::SystemFilePath, []() { return System::filePath(); }},
    {Token::SystemSemver, []() { return System::semver(); }},
    {Token::SystemNetworkInterface, []() { return System::networkInterface(); }},
    {Token::SystemCron, []() { return System::cron(); }},

    // VideoGame module
    {Token::VideoGameGameTitle, []() { return VideoGame::gameTitle(); }},
    {Token::VideoGameGenre, []() { return VideoGame::genre(); }},
    {Token::VideoGamePlatform, []() { return VideoGame::platform(); }},
    {Token::VideoGameStudioName, []() { return VideoGame::studioName(); }},

    // Weather module
    {Token::WeatherTemperatureMetric, []() { return std::to_string(Weather::temperature().metric); }},

    {Token::WeatherTemperatureImperial, []() { return std::to_string(Weather::temperature().imperial); }},
    {Token::WeatherPressureMetric, []() { return std::to_string(Weather::pressure().metric); }},
    {Token::WeatherPressureImperial, []() { return std::to_string(Weather::pressure().imperial); }},
    {Token::WeatherVisibilityMetric, []() { return std::to_string(Weather::visibility().metric); }},
    {Token::WeatherVisibilityImperial, []() { return std::to_string(Weather::visibility().imperial); }},
    {Token::WeatherWindSpeedMetric, []() { return std::to_string(Weather::windSpeed().metric); }},
    {Token::WeatherWindSpeedImperial, []() { return std::to_string(Weather::windSpeed().imperial); }},
    {Token::WeatherUvIndex, []() { return std::to_string(Weather::uvIndex()); }},
    {Token::WeatherHumidity, []() { return std::to_string(Weather::humidity()); }},
    {Token::WeatherWeatherDescription, []() { return Weather::weatherDescription(); }},
    {Token::WeatherCloadCover, []() { return std::to_string(Weather::cloudCover()); }},

    // Word module
    {Token::WordSample, []() { return Word::sample(); }},
    {Token::WordWords, []() { return Word::words(); }},
    {Token::WordAdjective, []() { return Word::adjective(); }},
    {Token::WordAdverb, []() { return Word::adverb(); }},
    {Token::WordConjuction, []() { return Word::conjunction(); }},
    {Token::WordInterjection, []() { return Word::interjection(); }},
    {Token::WordNoun, []() { return Word::noun(); }},
    {Token::WordPreposition, []() { return Word::preposition(); }},
    {Token::WordVerb, []() { return Word::verb(); }},
};

class Sructure
{
public:
    /**
     * @brief Get a json string based on input 
     *
     * @return a josn string based on user selected tokens 
     *
     * @code
     * Sructure::json(tokens) // {"FoodName":"Cajun Shrimp Pasta","airlineType":"narrowbody","airportName":"Brisbane International Airport"}
     * @endcode
     */
    static std::string json(const std::map<std::string, faker::Token> items);
    /**
     * @brief Get a csv string based on input
     *
     * @return a josn csv based on user selected tokens and rows
     *
     * @code
     * Sructure::csv(tokens,2) // FoodName,airlineType,airportName
                                  Lobster Roll,widebody,Soekarno-Hatta International Airport
                                  Pierogi,widebody,Brasilia-Presidente Juscelino Kubitschek International Airport
     * @endcode
     */
    static std::string csv(const std::map<std::string, faker::Token> items, const unsigned int rows);

private:
};

}