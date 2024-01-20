#include "faker-cxx/Structure.h"

#include <functional>

#include "faker-cxx/Airline.h"
#include "faker-cxx/Animal.h"
#include "faker-cxx/Book.h"
#include "faker-cxx/Color.h"
#include "faker-cxx/Commerce.h"
#include "faker-cxx/Company.h"
#include "faker-cxx/Computer.h"
#include "faker-cxx/Crypto.h"
#include "faker-cxx/Database.h"
#include "faker-cxx/Datatype.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Finance.h"
#include "faker-cxx/Food.h"
#include "faker-cxx/Git.h"
#include "faker-cxx/Hacker.h"
#include "faker-cxx/Image.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Location.h"
#include "faker-cxx/Lorem.h"
#include "faker-cxx/Medicine.h"
#include "faker-cxx/Movie.h"
#include "faker-cxx/Music.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/Phone.h"
#include "faker-cxx/Sport.h"
#include "faker-cxx/String.h"
#include "faker-cxx/System.h"
#include "faker-cxx/VideoGame.h"
#include "faker-cxx/Weather.h"
#include "faker-cxx/Word.h"

const std::map<faker::StructureToken, std::function<std::string()>> moduleFunctions = {
    {faker::StructureToken::AirlineAircraftType, []() { return faker::Airline::aircraftType(); }},
    {faker::StructureToken::AirlineAirplaneName, []() { return faker::Airline::airplane().name; }},
    {faker::StructureToken::AirlineAirplaneCode, []() { return faker::Airline::airplane().iataTypeCode; }},
    {faker::StructureToken::AirlineAirplaneName, []() { return faker::Airline::airplane().name; }},
    {faker::StructureToken::AirlineAirplaneCode, []() { return faker::Airline::airplane().iataTypeCode; }},
    {faker::StructureToken::AirlineAirlineName, []() { return faker::Airline::airline().name; }},
    {faker::StructureToken::AirlineAirlineCode, []() { return faker::Airline::airline().iataCode; }},
    {faker::StructureToken::AirlineAirportName, []() { return faker::Airline::airport().name; }},
    {faker::StructureToken::AirlineAirportCode, []() { return faker::Airline::airport().iataCode; }},
    {faker::StructureToken::AirlineSeat, []() { return faker::Airline::seat(faker::AircraftType()); }},
    {faker::StructureToken::AirlineRecordLocator, []() { return faker::Airline::recordLocator(); }},
    {faker::StructureToken::AirlineFlightNumber, []() { return faker::Airline::flightNumber(false, 4); }},

    {faker::StructureToken::AnimalBear, []() { return faker::Animal::bear(); }},
    {faker::StructureToken::AnimalBird, []() { return faker::Animal::bird(); }},
    {faker::StructureToken::AnimalCat, []() { return faker::Animal::cat(); }},
    {faker::StructureToken::AnimalCetacean, []() { return faker::Animal::cetacean(); }},
    {faker::StructureToken::AnimalCow, []() { return faker::Animal::cow(); }},
    {faker::StructureToken::AnimalCrocodilia, []() { return faker::Animal::crocodilia(); }},
    {faker::StructureToken::AnimalDog, []() { return faker::Animal::dog(); }},
    {faker::StructureToken::AnimalFish, []() { return faker::Animal::fish(); }},
    {faker::StructureToken::AnimalHorse, []() { return faker::Animal::horse(); }},
    {faker::StructureToken::AnimalInsect, []() { return faker::Animal::insect(); }},
    {faker::StructureToken::AnimalLion, []() { return faker::Animal::lion(); }},
    {faker::StructureToken::AnimalRabbit, []() { return faker::Animal::rabbit(); }},
    {faker::StructureToken::AnimalRodent, []() { return faker::Animal::rodent(); }},
    {faker::StructureToken::AnimalSnake, []() { return faker::Animal::snake(); }},
    {faker::StructureToken::AnimalType, []() { return faker::Animal::type(); }},

    {faker::StructureToken::BookTitle, []() { return faker::Book::title(); }},
    {faker::StructureToken::BookGenre, []() { return faker::Book::genre(); }},
    {faker::StructureToken::BookAuthor, []() { return faker::Book::author(); }},
    {faker::StructureToken::BookPublisher, []() { return faker::Book::publisher(); }},
    {faker::StructureToken::BookIsbn, []() { return faker::Book::isbn(); }},

    {faker::StructureToken::ColorName, []() { return faker::Color::name(); }},
    {faker::StructureToken::ColorRGB, []() { return faker::Color::rgb(); }},
    {faker::StructureToken::ColorHEX, []() { return faker::Color::hex(); }},
    {faker::StructureToken::ColorHSL, []() { return faker::Color::hsl(); }},
    {faker::StructureToken::ColorLCH, []() { return faker::Color::lch(); }},
    {faker::StructureToken::ColorCMYK, []() { return faker::Color::cmyk(); }},

    {faker::StructureToken::CommerceDepartment, []() { return faker::Commerce::department(); }},
    {faker::StructureToken::CommercePrice, []() { return faker::Commerce::price(); }},
    {faker::StructureToken::CommerceSku, []() { return faker::Commerce::sku(); }},
    {faker::StructureToken::CommerceProductAdjective, []() { return faker::Commerce::productAdjective(); }},
    {faker::StructureToken::CommerceProductMaterial, []() { return faker::Commerce::productMaterial(); }},
    {faker::StructureToken::CommerceProductName, []() { return faker::Commerce::productName(); }},
    {faker::StructureToken::CommerceProductFullName, []() { return faker::Commerce::productFullName(); }},
    {faker::StructureToken::CommerceEAN13, []() { return faker::Commerce::EAN13(); }},
    {faker::StructureToken::CommerceEAN8, []() { return faker::Commerce::EAN8(); }},
    {faker::StructureToken::CommerceISBN13, []() { return faker::Commerce::ISBN13(); }},
    {faker::StructureToken::CommerceISBN10, []() { return faker::Commerce::ISBN10(); }},

    {faker::StructureToken::CompanyName, []() { return faker::Company::name(); }},
    {faker::StructureToken::CompanyType, []() { return faker::Company::type(); }},
    {faker::StructureToken::CompanyIndustry, []() { return faker::Company::industry(); }},
    {faker::StructureToken::CompanyBuzzPhrase, []() { return faker::Company::buzzPhrase(); }},
    {faker::StructureToken::CompanyBuzzAdjective, []() { return faker::Company::buzzAdjective(); }},
    {faker::StructureToken::CompanyBuzzNoun, []() { return faker::Company::buzzNoun(); }},
    {faker::StructureToken::CompanyBuzzVerb, []() { return faker::Company::buzzVerb(); }},
    {faker::StructureToken::CompanyCatchPhrase, []() { return faker::Company::catchPhrase(); }},
    {faker::StructureToken::CompanyCtachPhraseAdjective, []() { return faker::Company::catchPhraseAdjective(); }},
    {faker::StructureToken::CompanyCatchPhraseDescriptor, []() { return faker::Company::catchPhraseDescriptor(); }},
    {faker::StructureToken::CompanyCatchPhraseNoun, []() { return faker::Company::catchPhraseNoun(); }},

    {faker::StructureToken::ComputerManufacture, []() { return faker::Computer::manufacture(); }},
    {faker::StructureToken::ComputerModel, []() { return faker::Computer::model(); }},
    {faker::StructureToken::ComputerCPUManufacture, []() { return faker::Computer::cpuManufacture(); }},
    {faker::StructureToken::ComputerCPUType, []() { return faker::Computer::cpuType(); }},
    {faker::StructureToken::ComputerCPUModel, []() { return faker::Computer::cpuModel(); }},
    {faker::StructureToken::ComputerGPUManufacture, []() { return faker::Computer::gpuManufacture(); }},
    {faker::StructureToken::ComputerGPUType, []() { return faker::Computer::gpuType(); }},
    {faker::StructureToken::ComputerGPUModel, []() { return faker::Computer::gpuModel(); }},

    {faker::StructureToken::CryptoSHA256, []() { return faker::Crypto::sha256(); }},
    {faker::StructureToken::CryptoMD5, []() { return faker::Crypto::md5(); }},

    {faker::StructureToken::DatabaseColumnName, []() { return faker::Database::columnName(); }},
    {faker::StructureToken::DatabaseColumnType, []() { return faker::Database::columnType(); }},
    {faker::StructureToken::DatabaseCollation, []() { return faker::Database::collation(); }},
    {faker::StructureToken::DatabaseEngine, []() { return faker::Database::engine(); }},
    {faker::StructureToken::DatabaseMongoDBObjectId, []() { return faker::Database::mongoDbObjectId(); }},

    {faker::StructureToken::DatatypeBoolean, []() { return std::to_string(faker::Datatype::boolean()); }},

    {faker::StructureToken::DatePastDateISO, []() { return faker::Date::pastDate(); }},
    {faker::StructureToken::DatePastDateTimestamp,
     []() { return faker::Date::pastDate(1, faker::Date::DateFormat::Timestamp); }},
    {faker::StructureToken::DatefutureDateISO, []() { return faker::Date::futureDate(); }},
    {faker::StructureToken::DatefutureDateTimestamp,
     []() { return faker::Date::futureDate(1, faker::Date::DateFormat::Timestamp); }},
    {faker::StructureToken::DateRecentDateISO, []() { return faker::Date::recentDate(); }},
    {faker::StructureToken::DateRecentDateTimestamp,
     []() { return faker::Date::recentDate(3, faker::Date::DateFormat::Timestamp); }},
    {faker::StructureToken::DateSoonDateISO, []() { return faker::Date::soonDate(); }},
    {faker::StructureToken::DateSoonDateTimestamp,
     []() { return faker::Date::soonDate(3, faker::Date::DateFormat::Timestamp); }},
    {faker::StructureToken::DateBirthdateByAgeISO, []() { return faker::Date::birthdateByAge(); }},
    {faker::StructureToken::DateBirthdateByYearTimestamp,
     []() { return faker::Date::birthdateByYear(1920, 2000, faker::Date::DateFormat::Timestamp); }},
    {faker::StructureToken::DateWeekdayName, []() { return faker::Date::weekdayName(); }},
    {faker::StructureToken::DateWeekdayAbbreviatedName, []() { return faker::Date::weekdayAbbreviatedName(); }},
    {faker::StructureToken::DateMontName, []() { return faker::Date::monthName(); }},
    {faker::StructureToken::DateMonthAbbreviatedName, []() { return faker::Date::monthAbbreviatedName(); }},

    {faker::StructureToken::FinanceCurrencyName, []() { return faker::Finance::currencyName(); }},
    {faker::StructureToken::FinanceCurrencyCode, []() { return faker::Finance::currencyCode(); }},
    {faker::StructureToken::FinanceCurrencySymbol, []() { return faker::Finance::currencySymbol(); }},
    {faker::StructureToken::FinanceAccountType, []() { return faker::Finance::accountType(); }},
    {faker::StructureToken::FinanceAmount, []() { return faker::Finance::amount(); }},
    {faker::StructureToken::FinanceIban, []() { return faker::Finance::iban(); }},
    {faker::StructureToken::FinanceBic, []() { return faker::Finance::bic(); }},
    {faker::StructureToken::FinanceAccountNumber, []() { return faker::Finance::accountNumber(); }},
    {faker::StructureToken::FinancePin, []() { return faker::Finance::pin(); }},
    {faker::StructureToken::FinanceRoutingNumber, []() { return faker::Finance::routingNumber(); }},
    {faker::StructureToken::FinanceCreditCardNumber, []() { return faker::Finance::creditCardNumber(); }},
    {faker::StructureToken::FinanceCreditCardCvv, []() { return faker::Finance::creditCardCvv(); }},
    {faker::StructureToken::FinanceBitcoinAddress, []() { return faker::Finance::bitcoinAddress(); }},
    {faker::StructureToken::FinanceLitecoinAddress, []() { return faker::Finance::litecoinAddress(); }},
    {faker::StructureToken::FinanceEthereumAddress, []() { return faker::Finance::ethereumAddress(); }},

    {faker::StructureToken::FoodAlcoholicBeverage, []() { return faker::Food::alcoholicBeverage(); }},
    {faker::StructureToken::FoodGrain, []() { return faker::Food::grain(); }},
    {faker::StructureToken::FoodMilkProduct, []() { return faker::Food::milkProduct(); }},
    {faker::StructureToken::FoodFruit, []() { return faker::Food::fruit(); }},
    {faker::StructureToken::FoodMeat, []() { return faker::Food::meat(); }},
    {faker::StructureToken::FoodSeafood, []() { return faker::Food::seafood(); }},
    {faker::StructureToken::FoodVegetable, []() { return faker::Food::vegetable(); }},
    {faker::StructureToken::FoodOil, []() { return faker::Food::oil(); }},
    {faker::StructureToken::FoodNut, []() { return faker::Food::nut(); }},
    {faker::StructureToken::FoodSeed, []() { return faker::Food::seed(); }},
    {faker::StructureToken::FoodSugarProduct, []() { return faker::Food::sugarProduct(); }},
    {faker::StructureToken::FoodNonAlcoholicBeverage, []() { return faker::Food::nonalcoholicBeverage(); }},
    {faker::StructureToken::FoodDishName, []() { return faker::Food::dishName(); }},
    {faker::StructureToken::FoodFoodCategory, []() { return faker::Food::foodCategory(); }},

    {faker::StructureToken::GitBranch, []() { return faker::Git::branch(); }},
    {faker::StructureToken::GitCommitDate, []() { return faker::Git::commitDate(); }},
    {faker::StructureToken::GitCommitEntry, []() { return faker::Git::commitEntry(); }},
    {faker::StructureToken::GitCommitMessage, []() { return faker::Git::commitMessage(); }},
    {faker::StructureToken::GitCommitSha, []() { return faker::Git::commitSha(); }},

    {faker::StructureToken::HackerAbbreviation, []() { return faker::Hacker::abbreviation(); }},
    {faker::StructureToken::HackerAdjective, []() { return faker::Hacker::adjective(); }},
    {faker::StructureToken::HackerNoun, []() { return faker::Hacker::noun(); }},
    {faker::StructureToken::HackerVerb, []() { return faker::Hacker::verb(); }},
    {faker::StructureToken::HackerIngverb, []() { return faker::Hacker::ingverb(); }},
    {faker::StructureToken::HackerPhrase, []() { return faker::Hacker::phrase(); }},

    {faker::StructureToken::ImageImageURL, []() { return faker::Image::imageUrl(); }},
    {faker::StructureToken::ImageGitHubAvatarURL, []() { return faker::Image::githubAvatarUrl(); }},
    {faker::StructureToken::ImageDimensions, []() { return faker::Image::dimensions(); }},

    {faker::StructureToken::InternetUsername, []() { return faker::Internet::username(); }},
    {faker::StructureToken::InternetEmail, []() { return faker::Internet::email(); }},
    {faker::StructureToken::InternetExampleEmail, []() { return faker::Internet::exampleEmail(); }},
    {faker::StructureToken::InternetPassword, []() { return faker::Internet::password(); }},
    {faker::StructureToken::InternetEmoji, []() { return faker::Internet::emoji(); }},
    {faker::StructureToken::InternetProtocol, []() { return faker::Internet::protocol(); }},
    {faker::StructureToken::InternetHttpMethod, []() { return faker::Internet::httpMethod(); }},
    {faker::StructureToken::InternetHttpRequestHeader, []() { return faker::Internet::httpRequestHeader(); }},
    {faker::StructureToken::InternetHttpResponseHeader, []() { return faker::Internet::httpResponseHeader(); }},
    {faker::StructureToken::InternetHttpMediaType, []() { return faker::Internet::httpMediaType(); }},
    {faker::StructureToken::InternetIpv4, []() { return faker::Internet::ipv4(); }},
    {faker::StructureToken::InternetIpv6, []() { return faker::Internet::ipv6(); }},
    {faker::StructureToken::InternetMac, []() { return faker::Internet::mac(); }},
    {faker::StructureToken::InternetURL, []() { return faker::Internet::url(); }},
    {faker::StructureToken::InternetDomainName, []() { return faker::Internet::domainName(); }},
    {faker::StructureToken::InternetDomainWord, []() { return faker::Internet::domainWord(); }},
    {faker::StructureToken::InternetDomainSuffix, []() { return faker::Internet::domainSuffix(); }},

    {faker::StructureToken::LocationCountry, []() { return faker::Location::country(); }},
    {faker::StructureToken::LocationCountryCode, []() { return faker::Location::countryCode(); }},
    {faker::StructureToken::LocationState, []() { return faker::Location::state(); }},
    {faker::StructureToken::LocationCity, []() { return faker::Location::city(); }},
    {faker::StructureToken::LocationZipCode, []() { return faker::Location::zipCode(); }},
    {faker::StructureToken::LocationStreetAddress, []() { return faker::Location::streetAddress(); }},
    {faker::StructureToken::LocationStreet, []() { return faker::Location::street(); }},
    {faker::StructureToken::LocationBuildingNumber, []() { return faker::Location::buildingNumber(); }},
    {faker::StructureToken::LocationSecondaryAddress, []() { return faker::Location::secondaryAddress(); }},
    {faker::StructureToken::LocationLatitude, []() { return faker::Location::latitude(); }},
    {faker::StructureToken::LocationLongitude, []() { return faker::Location::longitude(); }},
    {faker::StructureToken::LocationDirection, []() { return faker::Location::direction(); }},
    {faker::StructureToken::LocationTimeZone, []() { return faker::Location::timeZone(); }},

    // Lorem module
    {faker::StructureToken::LoremWord, []() { return faker::Lorem::word(); }},
    {faker::StructureToken::LoremWords, []() { return faker::Lorem::words(); }},
    {faker::StructureToken::LoremSentence, []() { return faker::Lorem::sentence(); }},
    {faker::StructureToken::LoremSentences, []() { return faker::Lorem::sentences(); }},
    {faker::StructureToken::LoremSlung, []() { return faker::Lorem::slug(10); }},
    {faker::StructureToken::LoremParagraph, []() { return faker::Lorem::paragraph(); }},
    {faker::StructureToken::LoremParagraphs, []() { return faker::Lorem::paragraphs(); }},

    // Medicine module
    {faker::StructureToken::MedicineCondition, []() { return faker::Medicine::condition(); }},
    {faker::StructureToken::MedicineMedicalTest, []() { return faker::Medicine::medicalTest(); }},
    {faker::StructureToken::MedicineSpecialty, []() { return faker::Medicine::specialty(); }},

    // Movie module
    {faker::StructureToken::MovieGenre, []() { return faker::Movie::genre(); }},
    {faker::StructureToken::MovieMovieTitle, []() { return faker::Movie::movieTitle(); }},
    {faker::StructureToken::MovieTvShow, []() { return faker::Movie::tvShow(); }},
    {faker::StructureToken::MovieDirector, []() { return faker::Movie::director(); }},
    {faker::StructureToken::MovieActor, []() { return faker::Movie::actor(); }},
    {faker::StructureToken::MovieActress, []() { return faker::Movie::actress(); }},

    // Music module
    {faker::StructureToken::MusicArtist, []() { return faker::Music::artist(); }},
    {faker::StructureToken::MusicGenre, []() { return faker::Music::genre(); }},
    {faker::StructureToken::MusicSongName, []() { return faker::Music::songName(); }},

    // Person module
    {faker::StructureToken::PersonFirstName, []() { return faker::Person::firstName(); }},
    {faker::StructureToken::PersonLastName, []() { return faker::Person::lastName(); }},
    {faker::StructureToken::PersonMiddleName, []() { return faker::Person::middleName(); }},
    {faker::StructureToken::PersonFullName, []() { return faker::Person::fullName(); }},
    {faker::StructureToken::PersonPrefix, []() { return faker::Person::prefix(); }},
    {faker::StructureToken::PersonSuffix, []() { return faker::Person::suffix(); }},
    {faker::StructureToken::PersonSex, []() { return faker::Person::sex(); }},
    {faker::StructureToken::PersonGender, []() { return faker::Person::gender(); }},
    {faker::StructureToken::PersonJobTitle, []() { return faker::Person::jobTitle(); }},
    {faker::StructureToken::PersonJobDescriptor, []() { return faker::Person::jobDescriptor(); }},
    {faker::StructureToken::PersonJobArea, []() { return faker::Person::jobArea(); }},
    {faker::StructureToken::PersonJobType, []() { return faker::Person::jobType(); }},
    {faker::StructureToken::PersonHoby, []() { return faker::Person::hobby(); }},
    {faker::StructureToken::PersonLanguage, []() { return faker::Person::language(); }},
    {faker::StructureToken::PersonNationality, []() { return faker::Person::nationality(); }},
    {faker::StructureToken::PersonWesternZodiac, []() { return faker::Person::westernZodiac(); }},
    {faker::StructureToken::PersonChineseZodiac, []() { return faker::Person::chineseZodiac(); }},

    // Phone module
    {faker::StructureToken::PhoneNumber, []() { return faker::Phone::number(); }},
    {faker::StructureToken::PhonePlatform, []() { return faker::Phone::platform(); }},
    {faker::StructureToken::PhoneModelName, []() { return faker::Phone::modelName(); }},
    {faker::StructureToken::PhoneManufacturer, []() { return faker::Phone::manufacturer(); }},
    {faker::StructureToken::PhoneIMEI, []() { return faker::Phone::imei(); }},

    // Sport module
    {faker::StructureToken::SportSport, []() { return faker::Sport::sport(); }},
    {faker::StructureToken::SportSoccerTeam, []() { return faker::Sport::soccerTeam(); }},
    {faker::StructureToken::SportMaleAthelete, []() { return faker::Sport::maleAthlete(); }},
    {faker::StructureToken::SportFemaleAthlete, []() { return faker::Sport::femaleAthlete(); }},
    {faker::StructureToken::SportSportEvent, []() { return faker::Sport::sportEvent(); }},

    // System module
    {faker::StructureToken::SystemFileName, []() { return faker::System::fileName(); }},
    {faker::StructureToken::SystemFileExtension, []() { return faker::System::fileExtension(); }},
    {faker::StructureToken::SystemCommonFileName, []() { return faker::System::commonFileName(); }},
    {faker::StructureToken::SystemCommonFileExtension, []() { return faker::System::commonFileExtension(); }},
    {faker::StructureToken::SystemMimeType, []() { return faker::System::mimeType(); }},
    {faker::StructureToken::SystemCommonFileType, []() { return faker::System::commonFileType(); }},
    {faker::StructureToken::SystemFileType, []() { return faker::System::fileType(); }},
    {faker::StructureToken::SystemDirectoryPath, []() { return faker::System::directoryPath(); }},
    {faker::StructureToken::SystemFilePath, []() { return faker::System::filePath(); }},
    {faker::StructureToken::SystemSemver, []() { return faker::System::semver(); }},
    {faker::StructureToken::SystemNetworkInterface, []() { return faker::System::networkInterface(); }},
    {faker::StructureToken::SystemCron, []() { return faker::System::cron(); }},

    // VideoGame module
    {faker::StructureToken::VideoGameGameTitle, []() { return faker::VideoGame::gameTitle(); }},
    {faker::StructureToken::VideoGameGenre, []() { return faker::VideoGame::genre(); }},
    {faker::StructureToken::VideoGamePlatform, []() { return faker::VideoGame::platform(); }},
    {faker::StructureToken::VideoGameStudioName, []() { return faker::VideoGame::studioName(); }},

    // Weather module
    {faker::StructureToken::WeatherTemperatureMetric,
     []() { return std::to_string(faker::Weather::temperature().metric); }},

    {faker::StructureToken::WeatherTemperatureImperial,
     []() { return std::to_string(faker::Weather::temperature().imperial); }},
    {faker::StructureToken::WeatherPressureMetric, []() { return std::to_string(faker::Weather::pressure().metric); }},
    {faker::StructureToken::WeatherPressureImperial,
     []() { return std::to_string(faker::Weather::pressure().imperial); }},
    {faker::StructureToken::WeatherVisibilityMetric,
     []() { return std::to_string(faker::Weather::visibility().metric); }},
    {faker::StructureToken::WeatherVisibilityImperial,
     []() { return std::to_string(faker::Weather::visibility().imperial); }},
    {faker::StructureToken::WeatherWindSpeedMetric,
     []() { return std::to_string(faker::Weather::windSpeed().metric); }},
    {faker::StructureToken::WeatherWindSpeedImperial,
     []() { return std::to_string(faker::Weather::windSpeed().imperial); }},
    {faker::StructureToken::WeatherUvIndex, []() { return std::to_string(faker::Weather::uvIndex()); }},
    {faker::StructureToken::WeatherHumidity, []() { return std::to_string(faker::Weather::humidity()); }},
    {faker::StructureToken::WeatherWeatherDescription, []() { return faker::Weather::weatherDescription(); }},
    {faker::StructureToken::WeatherCloudCover, []() { return std::to_string(faker::Weather::cloudCover()); }},

    // Word module
    {faker::StructureToken::WordSample, []() { return faker::Word::sample(); }},
    {faker::StructureToken::WordWords, []() { return faker::Word::words(); }},
    {faker::StructureToken::WordAdjective, []() { return faker::Word::adjective(); }},
    {faker::StructureToken::WordAdverb, []() { return faker::Word::adverb(); }},
    {faker::StructureToken::WordConjunction, []() { return faker::Word::conjunction(); }},
    {faker::StructureToken::WordInterjection, []() { return faker::Word::interjection(); }},
    {faker::StructureToken::WordNoun, []() { return faker::Word::noun(); }},
    {faker::StructureToken::WordPreposition, []() { return faker::Word::preposition(); }},
    {faker::StructureToken::WordVerb, []() { return faker::Word::verb(); }},
};
namespace faker
{

std::string faker::Structure::json(const std::map<std::string, faker::StructureToken>& items)
{
    std::string result = "{";

    for (auto it = items.begin(); it != items.end(); ++it)
    {
        auto func = moduleFunctions.find(it->second)->second;

        result.append("\"" + it->first + "\":\"" + func() + "\"");

        if (std::next(it) != items.end())
        {
            result.append(",");
        }
    }

    result.append("}");

    return result;
}

std::string faker::Structure::csv(const std::map<std::string, faker::StructureToken>& items, const unsigned int rows)
{
    std::string result;

    std::vector<std::function<std::string()>> funcs;

    for (auto it = items.begin(); it != items.end(); ++it)
    {
        result.append(it->first);

        funcs.push_back(moduleFunctions.find(it->second)->second);

        if (std::next(it) != items.end())
        {
            result.append(",");
        }
    }

    result.append("\n");

    std::size_t n = funcs.size();

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < n; ++j)
        {
            result.append(funcs[j]());

            if (j != n - 1)
            {
                result.append(",");
            }
        }

        result.append("\n");
    }

    return result;
}
}
