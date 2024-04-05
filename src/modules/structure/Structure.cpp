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

namespace faker
{
const std::map<StructureToken, std::function<std::string()>> moduleFunctions = {
    {StructureToken::AirlineAircraftType, []() { return Airline::aircraftType(); }},
    {StructureToken::AirlineAirplaneName, []() { return Airline::airplane().name; }},
    {StructureToken::AirlineAirplaneCode, []() { return Airline::airplane().iataTypeCode; }},
    {StructureToken::AirlineAirplaneName, []() { return Airline::airplane().name; }},
    {StructureToken::AirlineAirplaneCode, []() { return Airline::airplane().iataTypeCode; }},
    {StructureToken::AirlineAirlineName, []() { return Airline::airline().name; }},
    {StructureToken::AirlineAirlineCode, []() { return Airline::airline().iataCode; }},
    {StructureToken::AirlineAirportName, []() { return Airline::airport().name; }},
    {StructureToken::AirlineAirportCode, []() { return Airline::airport().iataCode; }},
    {StructureToken::AirlineSeat, []() { return Airline::seat(Airline::AircraftType()); }},
    {StructureToken::AirlineRecordLocator, []() { return Airline::recordLocator(); }},
    {StructureToken::AirlineFlightNumber, []() { return Airline::flightNumber(false, 4); }},

    {StructureToken::AnimalBear, []() { return Animal::bear(); }},
    {StructureToken::AnimalBird, []() { return Animal::bird(); }},
    {StructureToken::AnimalCat, []() { return Animal::cat(); }},
    {StructureToken::AnimalCetacean, []() { return Animal::cetacean(); }},
    {StructureToken::AnimalCow, []() { return Animal::cow(); }},
    {StructureToken::AnimalCrocodilia, []() { return Animal::crocodile(); }},
    {StructureToken::AnimalDog, []() { return Animal::dog(); }},
    {StructureToken::AnimalFish, []() { return Animal::fish(); }},
    {StructureToken::AnimalHorse, []() { return Animal::horse(); }},
    {StructureToken::AnimalInsect, []() { return Animal::insect(); }},
    {StructureToken::AnimalLion, []() { return Animal::lion(); }},
    {StructureToken::AnimalRabbit, []() { return Animal::rabbit(); }},
    {StructureToken::AnimalRodent, []() { return Animal::rodent(); }},
    {StructureToken::AnimalSnake, []() { return Animal::snake(); }},
    {StructureToken::AnimalType, []() { return Animal::type(); }},

    {StructureToken::BookTitle, []() { return Book::title(); }},
    {StructureToken::BookGenre, []() { return Book::genre(); }},
    {StructureToken::BookAuthor, []() { return Book::author(); }},
    {StructureToken::BookPublisher, []() { return Book::publisher(); }},
    {StructureToken::BookIsbn, []() { return Book::isbn(); }},

    {StructureToken::ColorName, []() { return Color::name(); }},
    {StructureToken::ColorRGB, []() { return Color::rgb(); }},
    {StructureToken::ColorHEX, []() { return Color::hex(); }},
    {StructureToken::ColorHSL, []() { return Color::hsl(); }},
    {StructureToken::ColorLCH, []() { return Color::lch(); }},
    {StructureToken::ColorCMYK, []() { return Color::cmyk(); }},

    {StructureToken::CommerceDepartment, []() { return Commerce::department(); }},
    {StructureToken::CommercePrice, []() { return Commerce::price(); }},
    {StructureToken::CommerceSku, []() { return Commerce::sku(); }},
    {StructureToken::CommerceProductAdjective, []() { return Commerce::productAdjective(); }},
    {StructureToken::CommerceProductMaterial, []() { return Commerce::productMaterial(); }},
    {StructureToken::CommerceProductName, []() { return Commerce::productName(); }},
    {StructureToken::CommerceProductFullName, []() { return Commerce::productFullName(); }},
    {StructureToken::CommerceEAN13, []() { return Commerce::EAN13(); }},
    {StructureToken::CommerceEAN8, []() { return Commerce::EAN8(); }},
    {StructureToken::CommerceISBN13, []() { return Commerce::ISBN13(); }},
    {StructureToken::CommerceISBN10, []() { return Commerce::ISBN10(); }},

    {StructureToken::CompanyName, []() { return Company::name(); }},
    {StructureToken::CompanyType, []() { return Company::type(); }},
    {StructureToken::CompanyIndustry, []() { return Company::industry(); }},
    {StructureToken::CompanyBuzzPhrase, []() { return Company::buzzPhrase(); }},
    {StructureToken::CompanyBuzzAdjective, []() { return Company::buzzAdjective(); }},
    {StructureToken::CompanyBuzzNoun, []() { return Company::buzzNoun(); }},
    {StructureToken::CompanyBuzzVerb, []() { return Company::buzzVerb(); }},
    {StructureToken::CompanyCatchPhrase, []() { return Company::catchPhrase(); }},
    {StructureToken::CompanyCtachPhraseAdjective, []() { return Company::catchPhraseAdjective(); }},
    {StructureToken::CompanyCatchPhraseDescriptor, []() { return Company::catchPhraseDescriptor(); }},
    {StructureToken::CompanyCatchPhraseNoun, []() { return Company::catchPhraseNoun(); }},

    {StructureToken::ComputerManufacture, []() { return Computer::manufacture(); }},
    {StructureToken::ComputerModel, []() { return Computer::model(); }},
    {StructureToken::ComputerCPUManufacture, []() { return Computer::cpuManufacture(); }},
    {StructureToken::ComputerCPUType, []() { return Computer::cpuType(); }},
    {StructureToken::ComputerCPUModel, []() { return Computer::cpuModel(); }},
    {StructureToken::ComputerGPUManufacture, []() { return Computer::gpuManufacture(); }},
    {StructureToken::ComputerGPUType, []() { return Computer::gpuType(); }},
    {StructureToken::ComputerGPUModel, []() { return Computer::gpuModel(); }},

    {StructureToken::CryptoSHA256, []() { return Crypto::sha256(); }},
    {StructureToken::CryptoMD5, []() { return Crypto::md5(); }},

    {StructureToken::DatabaseColumnName, []() { return Database::columnName(); }},
    {StructureToken::DatabaseColumnType, []() { return Database::columnType(); }},
    {StructureToken::DatabaseCollation, []() { return Database::collation(); }},
    {StructureToken::DatabaseEngine, []() { return Database::engine(); }},
    {StructureToken::DatabaseMongoDBObjectId, []() { return Database::mongoDbObjectId(); }},

    {StructureToken::DatatypeBoolean, []() { return std::to_string(Datatype::boolean()); }},

    {StructureToken::DatePastDateISO, []() { return Date::pastDate(); }},
    {StructureToken::DatePastDateTimestamp, []() { return Date::pastDate(1, Date::DateFormat::Timestamp); }},
    {StructureToken::DatefutureDateISO, []() { return Date::futureDate(); }},
    {StructureToken::DatefutureDateTimestamp, []() { return Date::futureDate(1, Date::DateFormat::Timestamp); }},
    {StructureToken::DateRecentDateISO, []() { return Date::recentDate(); }},
    {StructureToken::DateRecentDateTimestamp, []() { return Date::recentDate(3, Date::DateFormat::Timestamp); }},
    {StructureToken::DateSoonDateISO, []() { return Date::soonDate(); }},
    {StructureToken::DateSoonDateTimestamp, []() { return Date::soonDate(3, Date::DateFormat::Timestamp); }},
    {StructureToken::DateBirthdateByAgeISO, []() { return Date::birthdateByAge(); }},
    {StructureToken::DateBirthdateByYearTimestamp,
     []() { return Date::birthdateByYear(1920, 2000, Date::DateFormat::Timestamp); }},
    {StructureToken::DateWeekdayName, []() { return Date::weekdayName(); }},
    {StructureToken::DateWeekdayAbbreviatedName, []() { return Date::weekdayAbbreviatedName(); }},
    {StructureToken::DateMontName, []() { return Date::monthName(); }},
    {StructureToken::DateMonthAbbreviatedName, []() { return Date::monthAbbreviatedName(); }},

    {StructureToken::FinanceCurrencyName, []() { return Finance::currencyName(); }},
    {StructureToken::FinanceCurrencyCode, []() { return Finance::currencyCode(); }},
    {StructureToken::FinanceCurrencySymbol, []() { return Finance::currencySymbol(); }},
    {StructureToken::FinanceAccountType, []() { return Finance::accountType(); }},
    {StructureToken::FinanceAmount, []() { return Finance::amount(); }},
    {StructureToken::FinanceIban, []() { return Finance::iban(); }},
    {StructureToken::FinanceBic, []() { return Finance::bic(); }},
    {StructureToken::FinanceAccountNumber, []() { return Finance::accountNumber(); }},
    {StructureToken::FinancePin, []() { return Finance::pin(); }},
    {StructureToken::FinanceRoutingNumber, []() { return Finance::routingNumber(); }},
    {StructureToken::FinanceCreditCardNumber, []() { return Finance::creditCardNumber(); }},
    {StructureToken::FinanceCreditCardCvv, []() { return Finance::creditCardCvv(); }},
    {StructureToken::FinanceBitcoinAddress, []() { return Finance::bitcoinAddress(); }},
    {StructureToken::FinanceLitecoinAddress, []() { return Finance::litecoinAddress(); }},
    {StructureToken::FinanceEthereumAddress, []() { return Finance::ethereumAddress(); }},

    {StructureToken::FoodAlcoholicBeverage, []() { return Food::alcoholicBeverage(); }},
    {StructureToken::FoodGrain, []() { return Food::grain(); }},
    {StructureToken::FoodMilkProduct, []() { return Food::milkProduct(); }},
    {StructureToken::FoodFruit, []() { return Food::fruit(); }},
    {StructureToken::FoodMeat, []() { return Food::meat(); }},
    {StructureToken::FoodSeafood, []() { return Food::seafood(); }},
    {StructureToken::FoodVegetable, []() { return Food::vegetable(); }},
    {StructureToken::FoodOil, []() { return Food::oil(); }},
    {StructureToken::FoodNut, []() { return Food::nut(); }},
    {StructureToken::FoodSeed, []() { return Food::seed(); }},
    {StructureToken::FoodSugarProduct, []() { return Food::sugarProduct(); }},
    {StructureToken::FoodNonAlcoholicBeverage, []() { return Food::nonalcoholicBeverage(); }},
    {StructureToken::FoodDishName, []() { return Food::dishName(); }},
    {StructureToken::FoodFoodCategory, []() { return Food::foodCategory(); }},

    {StructureToken::GitBranch, []() { return Git::branch(); }},
    {StructureToken::GitCommitDate, []() { return Git::commitDate(); }},
    {StructureToken::GitCommitEntry, []() { return Git::commitEntry(); }},
    {StructureToken::GitCommitMessage, []() { return Git::commitMessage(); }},
    {StructureToken::GitCommitSha, []() { return Git::commitSha(); }},

    {StructureToken::HackerAbbreviation, []() { return Hacker::abbreviation(); }},
    {StructureToken::HackerAdjective, []() { return Hacker::adjective(); }},
    {StructureToken::HackerNoun, []() { return Hacker::noun(); }},
    {StructureToken::HackerVerb, []() { return Hacker::verb(); }},
    {StructureToken::HackerIngverb, []() { return Hacker::ingverb(); }},
    {StructureToken::HackerPhrase, []() { return Hacker::phrase(); }},

    {StructureToken::ImageImageURL, []() { return Image::imageUrl(); }},
    {StructureToken::ImageGitHubAvatarURL, []() { return Image::githubAvatarUrl(); }},
    {StructureToken::ImageDimensions, []() { return Image::dimensions(); }},

    {StructureToken::InternetUsername, []() { return Internet::username(); }},
    {StructureToken::InternetEmail, []() { return Internet::email(); }},
    {StructureToken::InternetExampleEmail, []() { return Internet::exampleEmail(); }},
    {StructureToken::InternetPassword, []() { return Internet::password(); }},
    {StructureToken::InternetEmoji, []() { return Internet::emoji(); }},
    {StructureToken::InternetProtocol, []() { return Internet::protocol(); }},
    {StructureToken::InternetHttpMethod, []() { return Internet::httpMethod(); }},
    {StructureToken::InternetHttpRequestHeader, []() { return Internet::httpRequestHeader(); }},
    {StructureToken::InternetHttpResponseHeader, []() { return Internet::httpResponseHeader(); }},
    {StructureToken::InternetHttpMediaType, []() { return Internet::httpMediaType(); }},
    {StructureToken::InternetIpv4, []() { return Internet::ipv4(); }},
    {StructureToken::InternetIpv6, []() { return Internet::ipv6(); }},
    {StructureToken::InternetMac, []() { return Internet::mac(); }},
    {StructureToken::InternetURL, []() { return Internet::url(); }},
    {StructureToken::InternetDomainName, []() { return Internet::domainName(); }},
    {StructureToken::InternetDomainWord, []() { return Internet::domainWord(); }},
    {StructureToken::InternetDomainSuffix, []() { return Internet::domainSuffix(); }},

    {StructureToken::LocationCountry, []() { return Location::country(); }},
    {StructureToken::LocationCountryCode, []() { return Location::countryCode(); }},
    {StructureToken::LocationState, []() { return Location::state(); }},
    {StructureToken::LocationCity, []() { return Location::city(); }},
    {StructureToken::LocationZipCode, []() { return Location::zipCode(); }},
    {StructureToken::LocationStreetAddress, []() { return Location::streetAddress(); }},
    {StructureToken::LocationStreet, []() { return Location::street(); }},
    {StructureToken::LocationBuildingNumber, []() { return Location::buildingNumber(); }},
    {StructureToken::LocationSecondaryAddress, []() { return Location::secondaryAddress(); }},
    {StructureToken::LocationLatitude, []() { return Location::latitude(); }},
    {StructureToken::LocationLongitude, []() { return Location::longitude(); }},
    {StructureToken::LocationDirection, []() { return Location::direction(); }},
    {StructureToken::LocationTimeZone, []() { return Location::timeZone(); }},

    // Lorem module
    {StructureToken::LoremWord, []() { return Lorem::word(); }},
    {StructureToken::LoremWords, []() { return Lorem::words(); }},
    {StructureToken::LoremSentence, []() { return Lorem::sentence(); }},
    {StructureToken::LoremSentences, []() { return Lorem::sentences(); }},
    {StructureToken::LoremSlung, []() { return Lorem::slug(10); }},
    {StructureToken::LoremParagraph, []() { return Lorem::paragraph(); }},
    {StructureToken::LoremParagraphs, []() { return Lorem::paragraphs(); }},

    // Medicine module
    {StructureToken::MedicineCondition, []() { return Medicine::condition(); }},
    {StructureToken::MedicineMedicalTest, []() { return Medicine::medicalTest(); }},
    {StructureToken::MedicineSpecialty, []() { return Medicine::specialty(); }},

    // Movie module
    {StructureToken::MovieGenre, []() { return Movie::genre(); }},
    {StructureToken::MovieMovieTitle, []() { return Movie::movieTitle(); }},
    {StructureToken::MovieTvShow, []() { return Movie::tvShow(); }},
    {StructureToken::MovieDirector, []() { return Movie::director(); }},
    {StructureToken::MovieActor, []() { return Movie::actor(); }},
    {StructureToken::MovieActress, []() { return Movie::actress(); }},

    // Music module
    {StructureToken::MusicArtist, []() { return Music::artist(); }},
    {StructureToken::MusicGenre, []() { return Music::genre(); }},
    {StructureToken::MusicSongName, []() { return Music::songName(); }},

    // Person module
    {StructureToken::PersonFirstName, []() { return Person::firstName(); }},
    {StructureToken::PersonLastName, []() { return Person::lastName(); }},
    {StructureToken::PersonMiddleName, []() { return Person::middleName(); }},
    {StructureToken::PersonFullName, []() { return Person::fullName(); }},
    {StructureToken::PersonPrefix, []() { return Person::prefix(); }},
    {StructureToken::PersonSuffix, []() { return Person::suffix(); }},
    {StructureToken::PersonSex, []() { return Person::sex(); }},
    {StructureToken::PersonGender, []() { return Person::gender(); }},
    {StructureToken::PersonJobTitle, []() { return Person::jobTitle(); }},
    {StructureToken::PersonJobDescriptor, []() { return Person::jobDescriptor(); }},
    {StructureToken::PersonJobArea, []() { return Person::jobArea(); }},
    {StructureToken::PersonJobType, []() { return Person::jobType(); }},
    {StructureToken::PersonHoby, []() { return Person::hobby(); }},
    {StructureToken::PersonLanguage, []() { return Person::language(); }},
    {StructureToken::PersonNationality, []() { return Person::nationality(); }},
    {StructureToken::PersonWesternZodiac, []() { return Person::westernZodiac(); }},
    {StructureToken::PersonChineseZodiac, []() { return Person::chineseZodiac(); }},

    // Phone module
    {StructureToken::PhoneNumber, []() { return Phone::number(); }},
    {StructureToken::PhonePlatform, []() { return Phone::platform(); }},
    {StructureToken::PhoneModelName, []() { return Phone::modelName(); }},
    {StructureToken::PhoneManufacturer, []() { return Phone::manufacturer(); }},
    {StructureToken::PhoneIMEI, []() { return Phone::imei(); }},

    // Sport module
    {StructureToken::SportSport, []() { return Sport::sport(); }},
    {StructureToken::SportSoccerTeam, []() { return Sport::soccerTeam(); }},
    {StructureToken::SportMaleAthelete, []() { return Sport::maleAthlete(); }},
    {StructureToken::SportFemaleAthlete, []() { return Sport::femaleAthlete(); }},
    {StructureToken::SportSportEvent, []() { return Sport::sportEvent(); }},

    // System module
    {StructureToken::SystemFileName, []() { return System::fileName(); }},
    {StructureToken::SystemFileExtension, []() { return System::fileExtension(); }},
    {StructureToken::SystemCommonFileName, []() { return System::commonFileName(); }},
    {StructureToken::SystemCommonFileExtension, []() { return System::commonFileExtension(); }},
    {StructureToken::SystemMimeType, []() { return System::mimeType(); }},
    {StructureToken::SystemCommonFileType, []() { return System::commonFileType(); }},
    {StructureToken::SystemFileType, []() { return System::fileType(); }},
    {StructureToken::SystemDirectoryPath, []() { return System::directoryPath(); }},
    {StructureToken::SystemFilePath, []() { return System::filePath(); }},
    {StructureToken::SystemSemver, []() { return System::semver(); }},
    {StructureToken::SystemNetworkInterface, []() { return System::networkInterface(); }},
    {StructureToken::SystemCron, []() { return System::cron(); }},

    // VideoGame module
    {StructureToken::VideoGameGameTitle, []() { return VideoGame::gameTitle(); }},
    {StructureToken::VideoGameGenre, []() { return VideoGame::genre(); }},
    {StructureToken::VideoGamePlatform, []() { return VideoGame::platform(); }},
    {StructureToken::VideoGameStudioName, []() { return VideoGame::studioName(); }},

    // Weather module
    {StructureToken::WeatherTemperatureMetric, []() { return std::to_string(Weather::temperature().metric); }},

    {StructureToken::WeatherTemperatureImperial, []() { return std::to_string(Weather::temperature().imperial); }},
    {StructureToken::WeatherPressureMetric, []() { return std::to_string(Weather::pressure().metric); }},
    {StructureToken::WeatherPressureImperial, []() { return std::to_string(Weather::pressure().imperial); }},
    {StructureToken::WeatherVisibilityMetric, []() { return std::to_string(Weather::visibility().metric); }},
    {StructureToken::WeatherVisibilityImperial, []() { return std::to_string(Weather::visibility().imperial); }},
    {StructureToken::WeatherWindSpeedMetric, []() { return std::to_string(Weather::windSpeed().metric); }},
    {StructureToken::WeatherWindSpeedImperial, []() { return std::to_string(Weather::windSpeed().imperial); }},
    {StructureToken::WeatherUvIndex, []() { return std::to_string(Weather::uvIndex()); }},
    {StructureToken::WeatherHumidity, []() { return std::to_string(Weather::humidity()); }},
    {StructureToken::WeatherWeatherDescription, []() { return Weather::weatherDescription(); }},
    {StructureToken::WeatherCloudCover, []() { return std::to_string(Weather::cloudCover()); }},

    // Word module
    {StructureToken::WordSample, []() { return Word::sample(); }},
    {StructureToken::WordWords, []() { return Word::words(); }},
    {StructureToken::WordAdjective, []() { return Word::adjective(); }},
    {StructureToken::WordAdverb, []() { return Word::adverb(); }},
    {StructureToken::WordConjunction, []() { return Word::conjunction(); }},
    {StructureToken::WordInterjection, []() { return Word::interjection(); }},
    {StructureToken::WordNoun, []() { return Word::noun(); }},
    {StructureToken::WordPreposition, []() { return Word::preposition(); }},
    {StructureToken::WordVerb, []() { return Word::verb(); }},
};

std::string Structure::json(const std::map<std::string, StructureToken>& items)
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

std::string Structure::csv(const std::map<std::string, StructureToken>& items, const unsigned int rows)
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
