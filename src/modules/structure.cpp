#include <cassert>
#include <faker/airline.h>
#include <faker/animal.h>
#include <faker/book.h>
#include <faker/color.h>
#include <faker/commerce.h>
#include <faker/company.h>
#include <faker/computer.h>
#include <faker/crypto.h>
#include <faker/database.h>
#include <faker/datatype.h>
#include <faker/date.h>
#include <faker/finance.h>
#include <faker/food.h>
#include <faker/git.h>
#include <faker/hacker.h>
#include <faker/image.h>
#include <faker/internet.h>
#include <faker/location.h>
#include <faker/lorem.h>
#include <faker/medicine.h>
#include <faker/movie.h>
#include <faker/music.h>
#include <faker/person.h>
#include <faker/phone.h>
#include <faker/sport.h>
#include <faker/string.h>
#include <faker/structure.h>
#include <faker/system.h>
#include <faker/video_game.h>
#include <faker/weather.h>
#include <faker/word.h>

namespace faker::structure {

std::string moduleFunction(StructureToken token)
{
    switch (token) {
    // Airline module
    case StructureToken::AirlineAircraftType:
        return std::string(airline::aircraftType());
    case StructureToken::AirlineAirplaneName:
        return std::string(airline::airplane().name);
    case StructureToken::AirlineAirplaneCode:
        return std::string(airline::airplane().iataTypeCode);
    case StructureToken::AirlineAirlineName:
        return std::string(airline::airline().name);
    case StructureToken::AirlineAirlineCode:
        return std::string(airline::airline().iataCode);
    case StructureToken::AirlineAirportName:
        return std::string(airline::airport().name);
    case StructureToken::AirlineAirportCode:
        return std::string(airline::airport().iataCode);
    case StructureToken::AirlineSeat:
        return airline::seat(airline::AircraftType());
    case StructureToken::AirlineRecordLocator:
        return airline::recordLocator();
    case StructureToken::AirlineFlightNumber:
        return airline::flightNumber(false, 4);
    // Animal module
    case StructureToken::AnimalBear:
        return std::string(animal::bear());
    case StructureToken::AnimalBird:
        return std::string(animal::bird());
    case StructureToken::AnimalCat:
        return std::string(animal::cat());
    case StructureToken::AnimalCetacean:
        return std::string(animal::cetacean());
    case StructureToken::AnimalCow:
        return std::string(animal::cow());
    case StructureToken::AnimalCrocodilia:
        return std::string(animal::crocodilia());
    case StructureToken::AnimalDog:
        return std::string(animal::dog());
    case StructureToken::AnimalFish:
        return std::string(animal::fish());
    case StructureToken::AnimalHorse:
        return std::string(animal::horse());
    case StructureToken::AnimalInsect:
        return std::string(animal::insect());
    case StructureToken::AnimalLion:
        return std::string(animal::lion());
    case StructureToken::AnimalRabbit:
        return std::string(animal::rabbit());
    case StructureToken::AnimalRodent:
        return std::string(animal::rodent());
    case StructureToken::AnimalSnake:
        return std::string(animal::snake());
    case StructureToken::AnimalType:
        return std::string(animal::type());
    // Book module
    case StructureToken::BookTitle:
        return std::string(book::title());
    case StructureToken::BookGenre:
        return std::string(book::genre());
    case StructureToken::BookAuthor:
        return std::string(book::author());
    case StructureToken::BookPublisher:
        return std::string(book::publisher());
    case StructureToken::BookIsbn:
        return book::isbn();
    // Color module
    case StructureToken::ColorName:
        return std::string(color::name());
    case StructureToken::ColorRGB:
        return color::rgb();
    case StructureToken::ColorHEX:
        return color::hex();
    case StructureToken::ColorHSL:
        return color::hsl();
    case StructureToken::ColorLCH:
        return color::lch();
    case StructureToken::ColorCMYK:
        return color::cmyk();
    // Commerce module
    case StructureToken::CommerceDepartment:
        return std::string(commerce::department());
    case StructureToken::CommercePrice:
        return commerce::price();
    case StructureToken::CommerceSku:
        return commerce::sku();
    case StructureToken::CommerceProductAdjective:
        return std::string(commerce::productAdjective());
    case StructureToken::CommerceProductMaterial:
        return std::string(commerce::productMaterial());
    case StructureToken::CommerceProductName:
        return std::string(commerce::productName());
    case StructureToken::CommerceProductFullName:
        return commerce::productFullName();
    case StructureToken::CommerceEAN13:
        return commerce::EAN13();
    case StructureToken::CommerceEAN8:
        return commerce::EAN8();
    case StructureToken::CommerceISBN13:
        return commerce::ISBN13();
    case StructureToken::CommerceISBN10:
        return commerce::ISBN10();
    // Company module
    case StructureToken::CompanyName:
        return company::name();
    case StructureToken::CompanyType:
        return std::string(company::type());
    case StructureToken::CompanyIndustry:
        return std::string(company::industry());
    case StructureToken::CompanyBuzzPhrase:
        return company::buzzPhrase();
    case StructureToken::CompanyBuzzAdjective:
        return std::string(company::buzzAdjective());
    case StructureToken::CompanyBuzzNoun:
        return std::string(company::buzzNoun());
    case StructureToken::CompanyBuzzVerb:
        return std::string(company::buzzVerb());
    case StructureToken::CompanyCatchPhrase:
        return company::catchPhrase();
    case StructureToken::CompanyCtachPhraseAdjective:
        return std::string(company::catchPhraseAdjective());
    case StructureToken::CompanyCatchPhraseDescriptor:
        return std::string(company::catchPhraseDescriptor());
    case StructureToken::CompanyCatchPhraseNoun:
        return std::string(company::catchPhraseNoun());
    // Computer module
    case StructureToken::ComputerManufacture:
        return std::string(computer::manufacture());
    case StructureToken::ComputerModel:
        return std::string(computer::model());
    case StructureToken::ComputerCPUManufacture:
        return std::string(computer::cpuManufacture());
    case StructureToken::ComputerCPUType:
        return std::string(computer::cpuType());
    case StructureToken::ComputerCPUModel:
        return std::string(computer::cpuModel());
    case StructureToken::ComputerGPUManufacture:
        return std::string(computer::gpuManufacture());
    case StructureToken::ComputerGPUType:
        return std::string(computer::gpuType());
    case StructureToken::ComputerGPUModel:
        return std::string(computer::gpuModel());
    // Crypto module
    case StructureToken::CryptoSHA256:
        return crypto::sha256();
    case StructureToken::CryptoMD5:
        return crypto::md5();
    // Database module
    case StructureToken::DatabaseColumnName:
        return std::string(database::columnName());
    case StructureToken::DatabaseColumnType:
        return std::string(database::columnType());
    case StructureToken::DatabaseCollation:
        return std::string(database::collation());
    case StructureToken::DatabaseEngine:
        return std::string(database::engine());
    case StructureToken::DatabaseMongoDBObjectId:
        return database::mongoDbObjectId();
    // Datatype module
    case StructureToken::DatatypeBoolean:
        return std::to_string(datatype::boolean());
    // Date module
    case StructureToken::DatePastDateISO:
        return date::pastDate();
    case StructureToken::DatePastDateTimestamp:
        return date::pastDate(1, date::DateFormat::Timestamp);
    case StructureToken::DatefutureDateISO:
        return date::futureDate();
    case StructureToken::DatefutureDateTimestamp:
        return date::futureDate(1, date::DateFormat::Timestamp);
    case StructureToken::DateRecentDateISO:
        return date::recentDate();
    case StructureToken::DateRecentDateTimestamp:
        return date::recentDate(3, date::DateFormat::Timestamp);
    case StructureToken::DateSoonDateISO:
        return date::soonDate();
    case StructureToken::DateSoonDateTimestamp:
        return date::soonDate(3, date::DateFormat::Timestamp);
    case StructureToken::DateBirthdateByAgeISO:
        return date::birthdateByAge();
    case StructureToken::DateBirthdateByYearTimestamp:
        return date::birthdateByYear(1920, 2000, date::DateFormat::Timestamp);
    case StructureToken::DateWeekdayName:
        return std::string(date::weekdayName());
    case StructureToken::DateWeekdayAbbreviatedName:
        return std::string(date::weekdayAbbreviatedName());
    case StructureToken::DateMontName:
        return std::string(date::monthName());
    case StructureToken::DateMonthAbbreviatedName:
        return std::string(date::monthAbbreviatedName());
    // Finance module
    case StructureToken::FinanceCurrencyName:
        return std::string(finance::currencyName());
    case StructureToken::FinanceCurrencyCode:
        return std::string(finance::currencyCode());
    case StructureToken::FinanceCurrencySymbol:
        return std::string(finance::currencySymbol());
    case StructureToken::FinanceAccountType:
        return std::string(finance::accountType());
    case StructureToken::FinanceAmount:
        return finance::amount();
    case StructureToken::FinanceIban:
        return finance::iban();
    case StructureToken::FinanceBic:
        return std::string(finance::bic());
    case StructureToken::FinanceAccountNumber:
        return finance::accountNumber();
    case StructureToken::FinancePin:
        return finance::pin();
    case StructureToken::FinanceRoutingNumber:
        return finance::routingNumber();
    case StructureToken::FinanceCreditCardNumber:
        return finance::creditCardNumber();
    case StructureToken::FinanceCreditCardCvv:
        return finance::creditCardCvv();
    case StructureToken::FinanceBitcoinAddress:
        return finance::bitcoinAddress();
    case StructureToken::FinanceLitecoinAddress:
        return finance::litecoinAddress();
    case StructureToken::FinanceEthereumAddress:
        return finance::ethereumAddress();
    // Food module
    case StructureToken::FoodAlcoholicBeverage:
        return std::string(food::alcoholicBeverage());
    case StructureToken::FoodGrain:
        return std::string(food::grain());
    case StructureToken::FoodMilkProduct:
        return std::string(food::milkProduct());
    case StructureToken::FoodFruit:
        return std::string(food::fruit());
    case StructureToken::FoodMeat:
        return std::string(food::meat());
    case StructureToken::FoodSeafood:
        return std::string(food::seafood());
    case StructureToken::FoodVegetable:
        return std::string(food::vegetable());
    case StructureToken::FoodOil:
        return std::string(food::oil());
    case StructureToken::FoodNut:
        return std::string(food::nut());
    case StructureToken::FoodSeed:
        return std::string(food::seed());
    case StructureToken::FoodSugarProduct:
        return std::string(food::sugarProduct());
    case StructureToken::FoodNonAlcoholicBeverage:
        return std::string(food::nonalcoholicBeverage());
    case StructureToken::FoodDishName:
        return std::string(food::dishName());
    case StructureToken::FoodFoodCategory:
        return std::string(food::foodCategory());
    // Git module
    case StructureToken::GitBranch:
        return git::branch();
    case StructureToken::GitCommitDate:
        return git::commitDate();
    case StructureToken::GitCommitEntry:
        return git::commitEntry();
    case StructureToken::GitCommitMessage:
        return git::commitMessage();
    case StructureToken::GitCommitSha:
        return git::commitSha();
    // Hacker module
    case StructureToken::HackerAbbreviation:
        return std::string(hacker::abbreviation());
    case StructureToken::HackerAdjective:
        return std::string(hacker::adjective());
    case StructureToken::HackerNoun:
        return std::string(hacker::noun());
    case StructureToken::HackerVerb:
        return std::string(hacker::verb());
    case StructureToken::HackerIngverb:
        return std::string(hacker::ingverb());
    case StructureToken::HackerPhrase:
        return hacker::phrase();
    // Image module
    case StructureToken::ImageImageURL:
        return image::imageUrl();
    case StructureToken::ImageGitHubAvatarURL:
        return image::githubAvatarUrl();
    case StructureToken::ImageDimensions:
        return std::string(image::dimensions());
    // Internet module
    case StructureToken::InternetUsername:
        return internet::username();
    case StructureToken::InternetEmail:
        return internet::email();
    case StructureToken::InternetExampleEmail:
        return internet::exampleEmail();
    case StructureToken::InternetPassword:
        return internet::password();
    case StructureToken::InternetEmoji:
        return std::string(internet::emoji());
    case StructureToken::InternetProtocol:
        return std::string(internet::protocol());
    case StructureToken::InternetHttpMethod:
        return std::string(internet::httpMethod());
    case StructureToken::InternetHttpRequestHeader:
        return std::string(internet::httpRequestHeader());
    case StructureToken::InternetHttpResponseHeader:
        return std::string(internet::httpResponseHeader());
    case StructureToken::InternetHttpMediaType:
        return std::string(internet::httpMediaType());
    case StructureToken::InternetIpv4:
        return internet::ipv4();
    case StructureToken::InternetIpv6:
        return internet::ipv6();
    case StructureToken::InternetMac:
        return internet::mac();
    case StructureToken::InternetURL:
        return internet::url();
    case StructureToken::InternetDomainName:
        return internet::domainName();
    case StructureToken::InternetDomainWord:
        return internet::domainWord();
    case StructureToken::InternetDomainSuffix:
        return std::string(internet::domainSuffix());
    // Location module
    case StructureToken::LocationCountry:
        return std::string(location::country_name());
    case StructureToken::LocationCountryCode:
        return std::string(location::country_code());
    case StructureToken::LocationState:
        return std::string(location::state());
    case StructureToken::LocationCity:
        return location::city();
    case StructureToken::LocationZipCode:
        return location::zip_code();
    case StructureToken::LocationStreetAddress:
        return location::street_address();
    case StructureToken::LocationStreet:
        return location::street();
    case StructureToken::LocationBuildingNumber:
        return location::building_number();
    case StructureToken::LocationSecondaryAddress:
        return location::secondary_address();
    case StructureToken::LocationLatitude:
        return location::latitude();
    case StructureToken::LocationLongitude:
        return location::longitude();
    case StructureToken::LocationDirection:
        return std::string(location::direction());
    case StructureToken::LocationTimeZone:
        return std::string(location::time_zone());
    // Lorem module
    case StructureToken::LoremWord:
        return std::string(lorem::word());
    case StructureToken::LoremWords:
        return lorem::words();
    case StructureToken::LoremSentence:
        return lorem::sentence();
    case StructureToken::LoremSentences:
        return lorem::sentences();
    case StructureToken::LoremSlung:
        return lorem::slug(10);
    case StructureToken::LoremParagraph:
        return lorem::paragraph();
    case StructureToken::LoremParagraphs:
        return lorem::paragraphs();
    // Medicine module
    case StructureToken::MedicineCondition:
        return std::string(medicine::condition());
    case StructureToken::MedicineMedicalTest:
        return std::string(medicine::medicalTest());
    case StructureToken::MedicineSpecialty:
        return std::string(medicine::specialty());
    // Movie module
    case StructureToken::MovieGenre:
        return std::string(movie::genre());
    case StructureToken::MovieMovieTitle:
        return std::string(movie::movieTitle());
    case StructureToken::MovieTvShow:
        return std::string(movie::tvShow());
    case StructureToken::MovieDirector:
        return std::string(movie::director());
    case StructureToken::MovieActor:
        return std::string(movie::actor());
    case StructureToken::MovieActress:
        return std::string(movie::actress());
    // Music module
    case StructureToken::MusicArtist:
        return std::string(music::artist());
    case StructureToken::MusicGenre:
        return std::string(music::genre());
    case StructureToken::MusicSongName:
        return std::string(music::songName());
    // Person module
    case StructureToken::PersonFirstName:
        return person::firstName();
    case StructureToken::PersonLastName:
        return person::lastName();
    case StructureToken::PersonMiddleName:
        return person::middleName();
    case StructureToken::PersonFullName:
        return person::fullName();
    case StructureToken::PersonPrefix:
        return person::prefix();
    case StructureToken::PersonSuffix:
        return person::suffix();
    case StructureToken::PersonSex:
        return std::string(person::sex());
    case StructureToken::PersonGender:
        return std::string(person::gender());
    case StructureToken::PersonJobTitle:
        return std::string(person::jobTitle());
    case StructureToken::PersonJobDescriptor:
        return std::string(person::jobDescriptor());
    case StructureToken::PersonJobArea:
        return std::string(person::jobArea());
    case StructureToken::PersonJobType:
        return std::string(person::jobType());
    case StructureToken::PersonHoby:
        return std::string(person::hobby());
    case StructureToken::PersonLanguage:
        return std::string(std::string(person::language()));
    case StructureToken::PersonNationality:
        return std::string(std::string(person::nationality()));
    case StructureToken::PersonWesternZodiac:
        return std::string(person::westernZodiac());
    case StructureToken::PersonChineseZodiac:
        return std::string(person::chineseZodiac());
    // Phone module
    case StructureToken::PhoneNumber:
        return phone::number();
    case StructureToken::PhonePlatform:
        return std::string(phone::platform());
    case StructureToken::PhoneModelName:
        return std::string(phone::modelName());
    case StructureToken::PhoneManufacturer:
        return std::string(phone::manufacturer());
    case StructureToken::PhoneIMEI:
        return phone::imei();
    // Sport module
    case StructureToken::SportSport:
        return std::string(sport::sport());
    case StructureToken::SportSoccerTeam:
        return std::string(sport::soccerTeam());
    case StructureToken::SportMaleAthelete:
        return std::string(sport::maleAthlete());
    case StructureToken::SportFemaleAthlete:
        return std::string(sport::femaleAthlete());
    case StructureToken::SportSportEvent:
        return std::string(sport::sportEvent());
    // System module
    case StructureToken::SystemFileName:
        return system::fileName();
    case StructureToken::SystemFileExtension:
        return system::fileExtension();
    case StructureToken::SystemCommonFileName:
        return system::commonFileName();
    case StructureToken::SystemCommonFileExtension:
        return std::string(system::commonFileExtension());
    case StructureToken::SystemMimeType:
        return std::string(system::mimeType());
    case StructureToken::SystemCommonFileType:
        return std::string(system::commonFileType());
    case StructureToken::SystemFileType:
        return std::string(system::fileType());
    case StructureToken::SystemDirectoryPath:
        return std::string(system::directoryPath());
    case StructureToken::SystemFilePath:
        return system::filePath();
    case StructureToken::SystemSemver:
        return system::semver();
    case StructureToken::SystemNetworkInterface:
        return system::networkInterface();
    case StructureToken::SystemCron:
        return system::cron();
    // VideoGame module
    case StructureToken::VideoGameGameTitle:
        return std::string(video_game::gameTitle());
    case StructureToken::VideoGameGenre:
        return std::string(video_game::genre());
    case StructureToken::VideoGamePlatform:
        return std::string(video_game::platform());
    case StructureToken::VideoGameStudioName:
        return std::string(video_game::studioName());
    // Weather module
    case StructureToken::WeatherTemperatureMetric:
        return std::to_string(weather::temperature().metric);
    case StructureToken::WeatherTemperatureImperial:
        return std::to_string(weather::temperature().imperial);
    case StructureToken::WeatherPressureMetric:
        return std::to_string(weather::pressure().metric);
    case StructureToken::WeatherPressureImperial:
        return std::to_string(weather::pressure().imperial);
    case StructureToken::WeatherVisibilityMetric:
        return std::to_string(weather::visibility().metric);
    case StructureToken::WeatherVisibilityImperial:
        return std::to_string(weather::visibility().imperial);
    case StructureToken::WeatherWindSpeedMetric:
        return std::to_string(weather::windSpeed().metric);
    case StructureToken::WeatherWindSpeedImperial:
        return std::to_string(weather::windSpeed().imperial);
    case StructureToken::WeatherUvIndex:
        return std::to_string(weather::uvIndex());
    case StructureToken::WeatherHumidity:
        return std::to_string(weather::humidity());
    case StructureToken::WeatherWeatherDescription:
        return std::string(weather::weatherDescription());
    case StructureToken::WeatherCloudCover:
        return std::to_string(weather::cloudCover());
    // Word module
    case StructureToken::WordSample:
        return std::string(word::sample());
    case StructureToken::WordWords:
        return word::words();
    case StructureToken::WordAdjective:
        return std::string(word::adjective());
    case StructureToken::WordAdverb:
        return std::string(word::adverb());
    case StructureToken::WordConjunction:
        return std::string(word::conjunction());
    case StructureToken::WordInterjection:
        return std::string(word::interjection());
    case StructureToken::WordNoun:
        return std::string(word::noun());
    case StructureToken::WordPreposition:
        return std::string(word::preposition());
    case StructureToken::WordVerb:
        return std::string(word::verb());
    // leftovers
    case StructureToken::ComputerType:
    case StructureToken::DateBirthdateByAgeTimestamp:
    case StructureToken::DateBirthdateByYearISO:
        return "";
    default:
        assert(false && "Invalid token");
        return "";
    }
}

std::string json(const std::unordered_map<std::string, StructureToken>& items)
{
    std::string result = "{";

    for (auto it = items.begin(); it != items.end(); ++it) {
        result.append("\"" + it->first + "\":\"" + moduleFunction(it->second) + "\"");

        if (std::next(it) != items.end()) {
            result.append(",");
        }
    }

    result.append("}");

    return result;
}

std::string csv(
    const std::unordered_map<std::string, StructureToken>& items, const unsigned int rows)
{
    std::vector<StructureToken> tokens;
    std::string result;

    for (auto it = items.begin(); it != items.end(); ++it) {
        tokens.push_back(it->second);
        result.append(it->first);
        if (std::next(it) != items.end()) {
            result.append(",");
        }
    }

    result.append("\n");

    for (size_t i = 0; i < rows; i++) {
        bool first = true;
        for (auto token : tokens) {
            if (first) {
                result.append(1, ',');
                first = false;
            }
            result.append(moduleFunction(token));
        }
        result.append("\n");
    }

    return result;
}
}
