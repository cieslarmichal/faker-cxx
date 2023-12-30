#include "../include/faker-cxx/Structure.h"

#include "../include/faker-cxx/Airline.h"
#include "../include/faker-cxx/Animal.h"
#include "../include/faker-cxx/Book.h"
#include "../include/faker-cxx/Color.h"
#include "../include/faker-cxx/Commerce.h"
#include "../include/faker-cxx/Company.h"
#include "../include/faker-cxx/Computer.h"
#include "../include/faker-cxx/Crypto.h"
#include "../include/faker-cxx/Database.h"
#include "../include/faker-cxx/Datatype.h"
#include "../include/faker-cxx/Date.h"
#include "../include/faker-cxx/Finance.h"
#include "../include/faker-cxx/Food.h"
#include "../include/faker-cxx/Git.h"
#include "../include/faker-cxx/Hacker.h"
#include "../include/faker-cxx/Helper.h"
#include "../include/faker-cxx/Image.h"
#include "../include/faker-cxx/Internet.h"
#include "../include/faker-cxx/Location.h"
#include "../include/faker-cxx/Lorem.h"
#include "../include/faker-cxx/Medicine.h"
#include "../include/faker-cxx/Movie.h"
#include "../include/faker-cxx/Music.h"
#include "../include/faker-cxx/Person.h"
#include "../include/faker-cxx/Phone.h"
#include "../include/faker-cxx/Sport.h"
#include "../include/faker-cxx/String.h"
#include "../include/faker-cxx/System.h"
#include "../include/faker-cxx/VideoGame.h"
#include "../include/faker-cxx/Weather.h"
#include "../include/faker-cxx/Word.h"

#include <vector>
const std::map<faker::Token, std::function<std::string()>> moduleFunctions = {
    {faker::Token::AirlineAircraftType, []() { return faker::Airline::aircraftType(); }},
    {faker::Token::AirlineAirplaneName, []() { return faker::Airline::airplane().name; }},
    {faker::Token::AirlineAirplaneCode, []() { return faker::Airline::airplane().iataTypeCode; }},
    {faker::Token::AirlineAirplaneName, []() { return faker::Airline::airplane().name; }},
    {faker::Token::AirlineAirplaneCode, []() { return faker::Airline::airplane().iataTypeCode; }},
    {faker::Token::AirlineAirlineName, []() { return faker::Airline::airline().name; }},
    {faker::Token::AirlineAirlineCode, []() { return faker::Airline::airline().iataCode; }},
    {faker::Token::AirlineAirportName, []() { return faker::Airline::airport().name; }},
    {faker::Token::AirlineAirportCode, []() { return faker::Airline::airport().iataCode; }},
    {faker::Token::AirlineSeat, []() { return faker::Airline::seat(faker::Airline::AircraftType()); }},
    {faker::Token::AirlineRecordLocator, []() { return faker::Airline::recordLocator(); }},
    {faker::Token::AirlineFlightNumber, []() { return faker::Airline::flightNumber(false, 4); }},

    {faker::Token::AnimalBear, []() { return faker::Animal::bear(); }},
    {faker::Token::AnimalBird, []() { return faker::Animal::bird(); }},
    {faker::Token::AnimalCat, []() { return faker::Animal::cat(); }},
    {faker::Token::AnimalCetacean, []() { return faker::Animal::cetacean(); }},
    {faker::Token::AnimalCow, []() { return faker::Animal::cow(); }},
    {faker::Token::AnimalCrocodilia, []() { return faker::Animal::crocodilia(); }},
    {faker::Token::AnimalDog, []() { return faker::Animal::dog(); }},
    {faker::Token::AnimalFish, []() { return faker::Animal::fish(); }},
    {faker::Token::AnimalHorse, []() { return faker::Animal::horse(); }},
    {faker::Token::AnimalInsect, []() { return faker::Animal::insect(); }},
    {faker::Token::AnimalLion, []() { return faker::Animal::lion(); }},
    {faker::Token::AnimalRabbit, []() { return faker::Animal::rabbit(); }},
    {faker::Token::AnimalRodent, []() { return faker::Animal::rodent(); }},
    {faker::Token::AnimalSnake, []() { return faker::Animal::snake(); }},
    {faker::Token::AnimalType, []() { return faker::Animal::type(); }},

    {faker::Token::BookTitle, []() { return faker::Book::title(); }},
    {faker::Token::BookGenre, []() { return faker::Book::genre(); }},
    {faker::Token::BookAuthor, []() { return faker::Book::author(); }},
    {faker::Token::BookPublisher, []() { return faker::Book::publisher(); }},
    {faker::Token::BookIsbn, []() { return faker::Book::isbn(); }},

    {faker::Token::ColorName, []() { return faker::Color::name(); }},
    {faker::Token::ColorRGB, []() { return faker::Color::rgb(); }},
    {faker::Token::ColorHEX, []() { return faker::Color::hex(); }},
    {faker::Token::ColorHSL, []() { return faker::Color::hsl(); }},
    {faker::Token::ColorLCH, []() { return faker::Color::lch(); }},
    {faker::Token::ColorCMYK, []() { return faker::Color::cmyk(); }},

    {faker::Token::CommerceDepartment, []() { return faker::Commerce::department(); }},
    {faker::Token::CommercePrice, []() { return faker::Commerce::price(); }},
    {faker::Token::CommerceSku, []() { return faker::Commerce::sku(); }},
    {faker::Token::CommerceProductAdjective, []() { return faker::Commerce::productAdjective(); }},
    {faker::Token::CommerceProductMaterial, []() { return faker::Commerce::productMaterial(); }},
    {faker::Token::CommerceProductName, []() { return faker::Commerce::productName(); }},
    {faker::Token::CommerceProductFullName, []() { return faker::Commerce::productFullName(); }},
    {faker::Token::CommerceEAN13, []() { return faker::Commerce::EAN13(); }},
    {faker::Token::CommerceEAN8, []() { return faker::Commerce::EAN8(); }},
    {faker::Token::CommerceISBN13, []() { return faker::Commerce::ISBN13(); }},
    {faker::Token::CommerceISBN10, []() { return faker::Commerce::ISBN10(); }},

    {faker::Token::CompanyName, []() { return faker::Company::name(); }},
    {faker::Token::CompanyType, []() { return faker::Company::type(); }},
    {faker::Token::CompanyIndustry, []() { return faker::Company::industry(); }},
    {faker::Token::CompanyBuzzPhrase, []() { return faker::Company::buzzPhrase(); }},
    {faker::Token::CompanyBuzzAdjective, []() { return faker::Company::buzzAdjective(); }},
    {faker::Token::CompanyBuzzNoun, []() { return faker::Company::buzzNoun(); }},
    {faker::Token::CompanyBuzzVerb, []() { return faker::Company::buzzVerb(); }},
    {faker::Token::CompanyCatchPhrase, []() { return faker::Company::catchPhrase(); }},
    {faker::Token::CompanyCtachPhraseAdjective, []() { return faker::Company::catchPhraseAdjective(); }},
    {faker::Token::CompanyCatchPhraseDescriptor, []() { return faker::Company::catchPhraseDescriptor(); }},
    {faker::Token::CompanyCatchPhraseNoun, []() { return faker::Company::catchPhraseNoun(); }},

    {faker::Token::ComputerManufacture, []() { return faker::Computer::manufacture(); }},
    {faker::Token::ComputerModel, []() { return faker::Computer::model(); }},
    {faker::Token::ComputerCPUManufacture, []() { return faker::Computer::cpuManufacture(); }},
    {faker::Token::ComputerCPUType, []() { return faker::Computer::cpuType(); }},
    {faker::Token::ComputerCPUModel, []() { return faker::Computer::cpuModel(); }},
    {faker::Token::ComputerGPUManufacture, []() { return faker::Computer::gpuManufacture(); }},
    {faker::Token::ComputerGPUType, []() { return faker::Computer::gpuType(); }},
    {faker::Token::ComputerGPUModel, []() { return faker::Computer::gpuModel(); }},

    {faker::Token::CryptoSHA256, []() { return faker::Crypto::sha256(); }},
    {faker::Token::CryptoMD5, []() { return faker::Crypto::md5(); }},

    {faker::Token::DatabaseColumnName, []() { return faker::Database::columnName(); }},
    {faker::Token::DatabaseColumnType, []() { return faker::Database::columnType(); }},
    {faker::Token::DatabaseCollation, []() { return faker::Database::collation(); }},
    {faker::Token::DatabaseEngine, []() { return faker::Database::engine(); }},
    {faker::Token::DatabaseMongoDBObjectId, []() { return faker::Database::mongoDbObjectId(); }},

    {faker::Token::DatatypeBoolean, []() { return std::to_string(faker::Datatype::boolean()); }},

    {faker::Token::DatePastDateISO, []() { return faker::Date::pastDate(); }},
    {faker::Token::DatePastDateTimestamp, []() { return faker::Date::pastDate(1, faker::Date::DateFormat::Timestamp); }},
    {faker::Token::DatefutureDateISO, []() { return faker::Date::futureDate(); }},
    {faker::Token::DatefutureDateTimestamp, []() { return faker::Date::futureDate(1, faker::Date::DateFormat::Timestamp); }},
    {faker::Token::DateRecentDateISO, []() { return faker::Date::recentDate(); }},
    {faker::Token::DateRecentDateTimestamp, []() { return faker::Date::recentDate(3, faker::Date::DateFormat::Timestamp); }},
    {faker::Token::DateSoonDateISO, []() { return faker::Date::soonDate(); }},
    {faker::Token::DateSoonDateTimestamp, []() { return faker::Date::soonDate(3, faker::Date::DateFormat::Timestamp); }},
    {faker::Token::DateBirthdateByAgeISO, []() { return faker::Date::birthdateByAge(); }},
    {faker::Token::DateBirthdateByYearTimestamp, []() { return faker::Date::birthdateByYear(1920, 2000, faker::Date::DateFormat::Timestamp); }},
    {faker::Token::DateWeekdayName, []() { return faker::Date::weekdayName(); }},
    {faker::Token::DateWeekdayAbbreviatedName, []() { return faker::Date::weekdayAbbreviatedName(); }},
    {faker::Token::DateMontName, []() { return faker::Date::monthName(); }},
    {faker::Token::DateMonthAbbreviatedName, []() { return faker::Date::monthAbbreviatedName(); }},

    {faker::Token::FinanceCurrencyName, []() { return faker::Finance::currencyName(); }},
    {faker::Token::FinanceCurrencyCode, []() { return faker::Finance::currencyCode(); }},
    {faker::Token::FinanceCurrencySymbol, []() { return faker::Finance::currencySymbol(); }},
    {faker::Token::FinanceAccountType, []() { return faker::Finance::accountType(); }},
    {faker::Token::FinanceAmount, []() { return faker::Finance::amount(); }},
    {faker::Token::FinanceIban, []() { return faker::Finance::iban(); }},
    {faker::Token::FinanceBic, []() { return faker::Finance::bic(); }},
    {faker::Token::FinanceAccountNumber, []() { return faker::Finance::accountNumber(); }},
    {faker::Token::FinancePin, []() { return faker::Finance::pin(); }},
    {faker::Token::FinanceRoutingNumber, []() { return faker::Finance::routingNumber(); }},
    {faker::Token::FinanceCreditCardNumber, []() { return faker::Finance::creditCardNumber(); }},
    {faker::Token::FinanceCreditCardCvv, []() { return faker::Finance::creditCardCvv(); }},
    {faker::Token::FinanceBitcoinAddress, []() { return faker::Finance::bitcoinAddress(); }},
    {faker::Token::FinanceLitecoinAddress, []() { return faker::Finance::litecoinAddress(); }},
    {faker::Token::FinanceEthereumAddress, []() { return faker::Finance::ethereumAddress(); }},

    {faker::Token::FoodAlcoholicBeverage, []() { return faker::Food::alcoholicBeverage(); }},
    {faker::Token::FoodGrain, []() { return faker::Food::grain(); }},
    {faker::Token::FoodMilkProduct, []() { return faker::Food::milkProduct(); }},
    {faker::Token::FoodFruit, []() { return faker::Food::fruit(); }},
    {faker::Token::FoodMeat, []() { return faker::Food::meat(); }},
    {faker::Token::FoodSeafood, []() { return faker::Food::seafood(); }},
    {faker::Token::FoodVegetable, []() { return faker::Food::vegetable(); }},
    {faker::Token::FoodOil, []() { return faker::Food::oil(); }},
    {faker::Token::FoodNut, []() { return faker::Food::nut(); }},
    {faker::Token::FoodSeed, []() { return faker::Food::seed(); }},
    {faker::Token::FoodSugarProduct, []() { return faker::Food::sugarProduct(); }},
    {faker::Token::FoodNonAlcoholicBeverage, []() { return faker::Food::nonalcoholicBeverage(); }},
    {faker::Token::FoodDishName, []() { return faker::Food::dishName(); }},
    {faker::Token::FoodFoodCategory, []() { return faker::Food::foodCategory(); }},

    {faker::Token::GitBranch, []() { return faker::Git::branch(); }},
    {faker::Token::GitCommitDate, []() { return faker::Git::commitDate(); }},
    {faker::Token::GitCommitEntry, []() { return faker::Git::commitEntry(); }},
    {faker::Token::GitCommitMessage, []() { return faker::Git::commitMessage(); }},
    {faker::Token::GitCommitSha, []() { return faker::Git::commitSha(); }},

    {faker::Token::HackerAbbreviation, []() { return faker::Hacker::abbreviation(); }},
    {faker::Token::HackerAdjective, []() { return faker::Hacker::adjective(); }},
    {faker::Token::HackerNoun, []() { return faker::Hacker::noun(); }},
    {faker::Token::HackerVerb, []() { return faker::Hacker::verb(); }},
    {faker::Token::HackerIngverb, []() { return faker::Hacker::ingverb(); }},
    {faker::Token::HackerPhrase, []() { return faker::Hacker::phrase(); }},

    {faker::Token::ImageImageURL, []() { return faker::Image::imageUrl(); }},
    {faker::Token::ImageGitHubAvatarURL, []() { return faker::Image::githubAvatarUrl(); }},
    {faker::Token::ImageDimensions, []() { return faker::Image::dimensions(); }},

    {faker::Token::InternetUsername, []() { return faker::Internet::username(); }},
    {faker::Token::InternetEmail, []() { return faker::Internet::email(); }},
    {faker::Token::InternetExampleEmail, []() { return faker::Internet::exampleEmail(); }},
    {faker::Token::InternetPassword, []() { return faker::Internet::password(); }},
    {faker::Token::InternetEmoji, []() { return faker::Internet::emoji(); }},
    {faker::Token::InternetProtocol, []() { return faker::Internet::protocol(); }},
    {faker::Token::InternetHttpMethod, []() { return faker::Internet::httpMethod(); }},
    {faker::Token::InternetHttpRequestHeader, []() { return faker::Internet::httpRequestHeader(); }},
    {faker::Token::InternetHttpResponseHeader, []() { return faker::Internet::httpResponseHeader(); }},
    {faker::Token::InternetHttpMediaType, []() { return faker::Internet::httpMediaType(); }},
    {faker::Token::InternetIpv4, []() { return faker::Internet::ipv4(); }},
    {faker::Token::InternetIpv6, []() { return faker::Internet::ipv6(); }},
    {faker::Token::InternetMac, []() { return faker::Internet::mac(); }},
    {faker::Token::InternetURL, []() { return faker::Internet::url(); }},
    {faker::Token::InternetDomainName, []() { return faker::Internet::domainName(); }},
    {faker::Token::InternetDomainWord, []() { return faker::Internet::domainWord(); }},
    {faker::Token::InternetDomainSuffix, []() { return faker::Internet::domainSuffix(); }},

    {faker::Token::LocationCountry, []() { return faker::Location::country(); }},
    {faker::Token::LocationCountryCode, []() { return faker::Location::countryCode(); }},
    {faker::Token::LocationState, []() { return faker::Location::state(); }},
    {faker::Token::LocationCity, []() { return faker::Location::city(); }},
    {faker::Token::LocationZipCode, []() { return faker::Location::zipCode(); }},
    {faker::Token::LocationStreetAddress, []() { return faker::Location::streetAddress(); }},
    {faker::Token::LocationStreet, []() { return faker::Location::street(); }},
    {faker::Token::LocationBuildingNumber, []() { return faker::Location::buildingNumber(); }},
    {faker::Token::LocationSecondaryAddress, []() { return faker::Location::secondaryAddress(); }},
    {faker::Token::LocationLatitude, []() { return faker::Location::latitude(); }},
    {faker::Token::LocationLongitude, []() { return faker::Location::longitude(); }},
    {faker::Token::LocationDirection, []() { return faker::Location::direction(); }},
    {faker::Token::LocationTimeZone, []() { return faker::Location::timeZone(); }},

    // Lorem module
    {faker::Token::LoremWord, []() { return faker::Lorem::word(); }},
    {faker::Token::LoremWords, []() { return faker::Lorem::words(); }},
    {faker::Token::LoremSentence, []() { return faker::Lorem::sentence(); }},
    {faker::Token::LoremSentences, []() { return faker::Lorem::sentences(); }},
    {faker::Token::LoremSlung, []() { return faker::Lorem::slug(10); }},
    {faker::Token::LoremParagraph, []() { return faker::Lorem::paragraph(); }},
    {faker::Token::LoremParagraphs, []() { return faker::Lorem::paragraphs(); }},

    // Medicine module
    {faker::Token::MedicineCondition, []() { return faker::Medicine::condition(); }},
    {faker::Token::MedicineMedicalTest, []() { return faker::Medicine::medicalTest(); }},
    {faker::Token::MedicineSpecialty, []() { return faker::Medicine::specialty(); }},

    // Movie module
    {faker::Token::MovieGenre, []() { return faker::Movie::genre(); }},
    {faker::Token::MovieMovieTitle, []() { return faker::Movie::movieTitle(); }},
    {faker::Token::MovieTvShow, []() { return faker::Movie::tvShow(); }},
    {faker::Token::MovieDirector, []() { return faker::Movie::director(); }},
    {faker::Token::MovieActor, []() { return faker::Movie::actor(); }},
    {faker::Token::MovieActress, []() { return faker::Movie::actress(); }},

    // Music module
    {faker::Token::MusicArtist, []() { return faker::Music::artist(); }},
    {faker::Token::MusicGenre, []() { return faker::Music::genre(); }},
    {faker::Token::MusicSongName, []() { return faker::Music::songName(); }},

    // Person module
    {faker::Token::PersonFirstName, []() { return faker::Person::firstName(); }},
    {faker::Token::PersonLastName, []() { return faker::Person::lastName(); }},
    {faker::Token::PersonMiddleName, []() { return faker::Person::middleName(); }},
    {faker::Token::PersonFullName, []() { return faker::Person::fullName(); }},
    {faker::Token::PersonPrefix, []() { return faker::Person::prefix(); }},
    {faker::Token::PersonSuffix, []() { return faker::Person::suffix(); }},
    {faker::Token::PersonSex, []() { return faker::Person::sex(); }},
    {faker::Token::PersonGender, []() { return faker::Person::gender(); }},
    {faker::Token::PersonJobTitle, []() { return faker::Person::jobTitle(); }},
    {faker::Token::PersonJobDescriptor, []() { return faker::Person::jobDescriptor(); }},
    {faker::Token::PersonJobArea, []() { return faker::Person::jobArea(); }},
    {faker::Token::PersonJobType, []() { return faker::Person::jobType(); }},
    {faker::Token::PersonHoby, []() { return faker::Person::hobby(); }},
    {faker::Token::PersonLanguage, []() { return faker::Person::language(); }},
    {faker::Token::PersonNationality, []() { return faker::Person::nationality(); }},
    {faker::Token::PersonWesternZodiac, []() { return faker::Person::westernZodiac(); }},
    {faker::Token::PersonChineseZodiac, []() { return faker::Person::chineseZodiac(); }},

    // Phone module
    {faker::Token::PhoneNumber, []() { return faker::Phone::number(); }},
    {faker::Token::PhonePlatform, []() { return faker::Phone::platform(); }},
    {faker::Token::PhoneModelName, []() { return faker::Phone::modelName(); }},
    {faker::Token::PhoneManufacturer, []() { return faker::Phone::manufacturer(); }},
    {faker::Token::PhoneIMEI, []() { return faker::Phone::imei(); }},

    // Sport module
    {faker::Token::SportSport, []() { return faker::Sport::sport(); }},
    {faker::Token::SportSoccerTeam, []() { return faker::Sport::soccerTeam(); }},
    {faker::Token::SportMaleAthelete, []() { return faker::Sport::maleAthlete(); }},
    {faker::Token::SportFemaleAthlete, []() { return faker::Sport::femaleAthlete(); }},
    {faker::Token::SportSportEvent, []() { return faker::Sport::sportEvent(); }},

    // System module
    {faker::Token::SystemFileName, []() { return faker::System::fileName(); }},
    {faker::Token::SystemFileExtension, []() { return faker::System::fileExtension(); }},
    {faker::Token::SystemCommonFileName, []() { return faker::System::commonFileName(); }},
    {faker::Token::SystemCommonFileExtension, []() { return faker::System::commonFileExtension(); }},
    {faker::Token::SystemMimeType, []() { return faker::System::mimeType(); }},
    {faker::Token::SystemCommonFileType, []() { return faker::System::commonFileType(); }},
    {faker::Token::SystemFileType, []() { return faker::System::fileType(); }},
    {faker::Token::SystemDirectoryPath, []() { return faker::System::directoryPath(); }},
    {faker::Token::SystemFilePath, []() { return faker::System::filePath(); }},
    {faker::Token::SystemSemver, []() { return faker::System::semver(); }},
    {faker::Token::SystemNetworkInterface, []() { return faker::System::networkInterface(); }},
    {faker::Token::SystemCron, []() { return faker::System::cron(); }},

    // VideoGame module
    {faker::Token::VideoGameGameTitle, []() { return faker::VideoGame::gameTitle(); }},
    {faker::Token::VideoGameGenre, []() { return faker::VideoGame::genre(); }},
    {faker::Token::VideoGamePlatform, []() { return faker::VideoGame::platform(); }},
    {faker::Token::VideoGameStudioName, []() { return faker::VideoGame::studioName(); }},

    // Weather module
    {faker::Token::WeatherTemperatureMetric, []() { return std::to_string(faker::Weather::temperature().metric); }},

    {faker::Token::WeatherTemperatureImperial, []() { return std::to_string(faker::Weather::temperature().imperial); }},
    {faker::Token::WeatherPressureMetric, []() { return std::to_string(faker::Weather::pressure().metric); }},
    {faker::Token::WeatherPressureImperial, []() { return std::to_string(faker::Weather::pressure().imperial); }},
    {faker::Token::WeatherVisibilityMetric, []() { return std::to_string(faker::Weather::visibility().metric); }},
    {faker::Token::WeatherVisibilityImperial, []() { return std::to_string(faker::Weather::visibility().imperial); }},
    {faker::Token::WeatherWindSpeedMetric, []() { return std::to_string(faker::Weather::windSpeed().metric); }},
    {faker::Token::WeatherWindSpeedImperial, []() { return std::to_string(faker::Weather::windSpeed().imperial); }},
    {faker::Token::WeatherUvIndex, []() { return std::to_string(faker::Weather::uvIndex()); }},
    {faker::Token::WeatherHumidity, []() { return std::to_string(faker::Weather::humidity()); }},
    {faker::Token::WeatherWeatherDescription, []() { return faker::Weather::weatherDescription(); }},
    {faker::Token::WeatherCloadCover, []() { return std::to_string(faker::Weather::cloudCover()); }},

    // Word module
    {faker::Token::WordSample, []() { return faker::Word::sample(); }},
    {faker::Token::WordWords, []() { return faker::Word::words(); }},
    {faker::Token::WordAdjective, []() { return faker::Word::adjective(); }},
    {faker::Token::WordAdverb, []() { return faker::Word::adverb(); }},
    {faker::Token::WordConjuction, []() { return faker::Word::conjunction(); }},
    {faker::Token::WordInterjection, []() { return faker::Word::interjection(); }},
    {faker::Token::WordNoun, []() { return faker::Word::noun(); }},
    {faker::Token::WordPreposition, []() { return faker::Word::preposition(); }},
    {faker::Token::WordVerb, []() { return faker::Word::verb(); }},
};
namespace faker
{

std::string faker::Structure::json(const std::map<std::string, faker::Token> items)
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
std::string faker::Structure::csv(const std::map<std::string, faker::Token> items, const unsigned int rows)
{
    std::string result = "";
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