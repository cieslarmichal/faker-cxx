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
#include <functional>

namespace faker::structure {

const std::unordered_map<faker::StructureToken, std::function<std::string()>> moduleFunctions = {
    { faker::StructureToken::AirlineAircraftType,
        []() { return std::string(faker::airline::aircraftType()); } },
    { faker::StructureToken::AirlineAirplaneName,
        []() { return std::string(faker::airline::airplane().name); } },
    { faker::StructureToken::AirlineAirplaneCode,
        []() { return std::string(faker::airline::airplane().iataTypeCode); } },
    { faker::StructureToken::AirlineAirplaneName,
        []() { return std::string(faker::airline::airplane().name); } },
    { faker::StructureToken::AirlineAirplaneCode,
        []() { return std::string(faker::airline::airplane().iataTypeCode); } },
    { faker::StructureToken::AirlineAirlineName,
        []() { return std::string(faker::airline::airline().name); } },
    { faker::StructureToken::AirlineAirlineCode,
        []() { return std::string(faker::airline::airline().iataCode); } },
    { faker::StructureToken::AirlineAirportName,
        []() { return std::string(faker::airline::airport().name); } },
    { faker::StructureToken::AirlineAirportCode,
        []() { return std::string(faker::airline::airport().iataCode); } },
    { faker::StructureToken::AirlineSeat,
        []() { return faker::airline::seat(faker::AircraftType()); } },
    { faker::StructureToken::AirlineRecordLocator,
        []() { return faker::airline::recordLocator(); } },
    { faker::StructureToken::AirlineFlightNumber,
        []() { return faker::airline::flightNumber(false, 4); } },

    { faker::StructureToken::AnimalBear, []() { return std::string(faker::animal::bear()); } },
    { faker::StructureToken::AnimalBird, []() { return std::string(faker::animal::bird()); } },
    { faker::StructureToken::AnimalCat, []() { return std::string(faker::animal::cat()); } },
    { faker::StructureToken::AnimalCetacean,
        []() { return std::string(faker::animal::cetacean()); } },
    { faker::StructureToken::AnimalCow, []() { return std::string(faker::animal::cow()); } },
    { faker::StructureToken::AnimalCrocodilia,
        []() { return std::string(faker::animal::crocodilia()); } },
    { faker::StructureToken::AnimalDog, []() { return std::string(faker::animal::dog()); } },
    { faker::StructureToken::AnimalFish, []() { return std::string(faker::animal::fish()); } },
    { faker::StructureToken::AnimalHorse, []() { return std::string(faker::animal::horse()); } },
    { faker::StructureToken::AnimalInsect, []() { return std::string(faker::animal::insect()); } },
    { faker::StructureToken::AnimalLion, []() { return std::string(faker::animal::lion()); } },
    { faker::StructureToken::AnimalRabbit, []() { return std::string(faker::animal::rabbit()); } },
    { faker::StructureToken::AnimalRodent, []() { return std::string(faker::animal::rodent()); } },
    { faker::StructureToken::AnimalSnake, []() { return std::string(faker::animal::snake()); } },
    { faker::StructureToken::AnimalType, []() { return std::string(faker::animal::type()); } },

    { faker::StructureToken::BookTitle, []() { return std::string(faker::book::title()); } },
    { faker::StructureToken::BookGenre, []() { return std::string(faker::book::genre()); } },
    { faker::StructureToken::BookAuthor, []() { return std::string(faker::book::author()); } },
    { faker::StructureToken::BookPublisher,
        []() { return std::string(faker::book::publisher()); } },
    { faker::StructureToken::BookIsbn, []() { return faker::book::isbn(); } },

    { faker::StructureToken::ColorName, []() { return std::string(faker::color::name()); } },
    { faker::StructureToken::ColorRGB, []() { return faker::color::rgb(); } },
    { faker::StructureToken::ColorHEX, []() { return faker::color::hex(); } },
    { faker::StructureToken::ColorHSL, []() { return faker::color::hsl(); } },
    { faker::StructureToken::ColorLCH, []() { return faker::color::lch(); } },
    { faker::StructureToken::ColorCMYK, []() { return faker::color::cmyk(); } },

    { faker::StructureToken::CommerceDepartment,
        []() { return std::string(faker::commerce::department()); } },
    { faker::StructureToken::CommercePrice, []() { return faker::commerce::price(); } },
    { faker::StructureToken::CommerceSku, []() { return faker::commerce::sku(); } },
    { faker::StructureToken::CommerceProductAdjective,
        []() { return std::string(faker::commerce::productAdjective()); } },
    { faker::StructureToken::CommerceProductMaterial,
        []() { return std::string(faker::commerce::productMaterial()); } },
    { faker::StructureToken::CommerceProductName,
        []() { return std::string(faker::commerce::productName()); } },
    { faker::StructureToken::CommerceProductFullName,
        []() { return faker::commerce::productFullName(); } },
    { faker::StructureToken::CommerceEAN13, []() { return faker::commerce::EAN13(); } },
    { faker::StructureToken::CommerceEAN8, []() { return faker::commerce::EAN8(); } },
    { faker::StructureToken::CommerceISBN13, []() { return faker::commerce::ISBN13(); } },
    { faker::StructureToken::CommerceISBN10, []() { return faker::commerce::ISBN10(); } },

    { faker::StructureToken::CompanyName, []() { return faker::company::name(); } },
    { faker::StructureToken::CompanyType, []() { return std::string(faker::company::type()); } },
    { faker::StructureToken::CompanyIndustry,
        []() { return std::string(faker::company::industry()); } },
    { faker::StructureToken::CompanyBuzzPhrase, []() { return faker::company::buzzPhrase(); } },
    { faker::StructureToken::CompanyBuzzAdjective,
        []() { return std::string(faker::company::buzzAdjective()); } },
    { faker::StructureToken::CompanyBuzzNoun,
        []() { return std::string(faker::company::buzzNoun()); } },
    { faker::StructureToken::CompanyBuzzVerb,
        []() { return std::string(faker::company::buzzVerb()); } },
    { faker::StructureToken::CompanyCatchPhrase, []() { return faker::company::catchPhrase(); } },
    { faker::StructureToken::CompanyCtachPhraseAdjective,
        []() { return std::string(faker::company::catchPhraseAdjective()); } },
    { faker::StructureToken::CompanyCatchPhraseDescriptor,
        []() { return std::string(faker::company::catchPhraseDescriptor()); } },
    { faker::StructureToken::CompanyCatchPhraseNoun,
        []() { return std::string(faker::company::catchPhraseNoun()); } },

    { faker::StructureToken::ComputerManufacture,
        []() { return std::string(faker::computer::manufacture()); } },
    { faker::StructureToken::ComputerModel,
        []() { return std::string(faker::computer::model()); } },
    { faker::StructureToken::ComputerCPUManufacture,
        []() { return std::string(faker::computer::cpuManufacture()); } },
    { faker::StructureToken::ComputerCPUType,
        []() { return std::string(faker::computer::cpuType()); } },
    { faker::StructureToken::ComputerCPUModel,
        []() { return std::string(faker::computer::cpuModel()); } },
    { faker::StructureToken::ComputerGPUManufacture,
        []() { return std::string(faker::computer::gpuManufacture()); } },
    { faker::StructureToken::ComputerGPUType,
        []() { return std::string(faker::computer::gpuType()); } },
    { faker::StructureToken::ComputerGPUModel,
        []() { return std::string(faker::computer::gpuModel()); } },

    { faker::StructureToken::CryptoSHA256, []() { return faker::crypto::sha256(); } },
    { faker::StructureToken::CryptoMD5, []() { return faker::crypto::md5(); } },

    { faker::StructureToken::DatabaseColumnName,
        []() { return std::string(faker::database::columnName()); } },
    { faker::StructureToken::DatabaseColumnType,
        []() { return std::string(faker::database::columnType()); } },
    { faker::StructureToken::DatabaseCollation,
        []() { return std::string(faker::database::collation()); } },
    { faker::StructureToken::DatabaseEngine,
        []() { return std::string(faker::database::engine()); } },
    { faker::StructureToken::DatabaseMongoDBObjectId,
        []() { return faker::database::mongoDbObjectId(); } },

    { faker::StructureToken::DatatypeBoolean,
        []() { return std::to_string(faker::datatype::boolean()); } },

    { faker::StructureToken::DatePastDateISO, []() { return faker::date::pastDate(); } },
    { faker::StructureToken::DatePastDateTimestamp,
        []() { return faker::date::pastDate(1, faker::date::DateFormat::Timestamp); } },
    { faker::StructureToken::DatefutureDateISO, []() { return faker::date::futureDate(); } },
    { faker::StructureToken::DatefutureDateTimestamp,
        []() { return faker::date::futureDate(1, faker::date::DateFormat::Timestamp); } },
    { faker::StructureToken::DateRecentDateISO, []() { return faker::date::recentDate(); } },
    { faker::StructureToken::DateRecentDateTimestamp,
        []() { return faker::date::recentDate(3, faker::date::DateFormat::Timestamp); } },
    { faker::StructureToken::DateSoonDateISO, []() { return faker::date::soonDate(); } },
    { faker::StructureToken::DateSoonDateTimestamp,
        []() { return faker::date::soonDate(3, faker::date::DateFormat::Timestamp); } },
    { faker::StructureToken::DateBirthdateByAgeISO,
        []() { return faker::date::birthdateByAge(); } },
    { faker::StructureToken::DateBirthdateByYearTimestamp,
        []() {
            return faker::date::birthdateByYear(1920, 2000, faker::date::DateFormat::Timestamp);
        } },
    { faker::StructureToken::DateWeekdayName,
        []() { return std::string(faker::date::weekdayName()); } },
    { faker::StructureToken::DateWeekdayAbbreviatedName,
        []() { return std::string(faker::date::weekdayAbbreviatedName()); } },
    { faker::StructureToken::DateMontName, []() { return std::string(faker::date::monthName()); } },
    { faker::StructureToken::DateMonthAbbreviatedName,
        []() { return std::string(faker::date::monthAbbreviatedName()); } },

    { faker::StructureToken::FinanceCurrencyName,
        []() { return std::string(faker::finance::currencyName()); } },
    { faker::StructureToken::FinanceCurrencyCode,
        []() { return std::string(faker::finance::currencyCode()); } },
    { faker::StructureToken::FinanceCurrencySymbol,
        []() { return std::string(faker::finance::currencySymbol()); } },
    { faker::StructureToken::FinanceAccountType,
        []() { return std::string(faker::finance::accountType()); } },
    { faker::StructureToken::FinanceAmount, []() { return faker::finance::amount(); } },
    { faker::StructureToken::FinanceIban, []() { return faker::finance::iban(); } },
    { faker::StructureToken::FinanceBic, []() { return std::string(faker::finance::bic()); } },
    { faker::StructureToken::FinanceAccountNumber,
        []() { return faker::finance::accountNumber(); } },
    { faker::StructureToken::FinancePin, []() { return faker::finance::pin(); } },
    { faker::StructureToken::FinanceRoutingNumber,
        []() { return faker::finance::routingNumber(); } },
    { faker::StructureToken::FinanceCreditCardNumber,
        []() { return faker::finance::creditCardNumber(); } },
    { faker::StructureToken::FinanceCreditCardCvv,
        []() { return faker::finance::creditCardCvv(); } },
    { faker::StructureToken::FinanceBitcoinAddress,
        []() { return faker::finance::bitcoinAddress(); } },
    { faker::StructureToken::FinanceLitecoinAddress,
        []() { return faker::finance::litecoinAddress(); } },
    { faker::StructureToken::FinanceEthereumAddress,
        []() { return faker::finance::ethereumAddress(); } },

    { faker::StructureToken::FoodAlcoholicBeverage,
        []() { return std::string(faker::food::alcoholicBeverage()); } },
    { faker::StructureToken::FoodGrain, []() { return std::string(faker::food::grain()); } },
    { faker::StructureToken::FoodMilkProduct,
        []() { return std::string(faker::food::milkProduct()); } },
    { faker::StructureToken::FoodFruit, []() { return std::string(faker::food::fruit()); } },
    { faker::StructureToken::FoodMeat, []() { return std::string(faker::food::meat()); } },
    { faker::StructureToken::FoodSeafood, []() { return std::string(faker::food::seafood()); } },
    { faker::StructureToken::FoodVegetable,
        []() { return std::string(faker::food::vegetable()); } },
    { faker::StructureToken::FoodOil, []() { return std::string(faker::food::oil()); } },
    { faker::StructureToken::FoodNut, []() { return std::string(faker::food::nut()); } },
    { faker::StructureToken::FoodSeed, []() { return std::string(faker::food::seed()); } },
    { faker::StructureToken::FoodSugarProduct,
        []() { return std::string(faker::food::sugarProduct()); } },
    { faker::StructureToken::FoodNonAlcoholicBeverage,
        []() { return std::string(faker::food::nonalcoholicBeverage()); } },
    { faker::StructureToken::FoodDishName, []() { return std::string(faker::food::dishName()); } },
    { faker::StructureToken::FoodFoodCategory,
        []() { return std::string(faker::food::foodCategory()); } },

    { faker::StructureToken::GitBranch, []() { return faker::git::branch(); } },
    { faker::StructureToken::GitCommitDate, []() { return faker::git::commitDate(); } },
    { faker::StructureToken::GitCommitEntry, []() { return faker::git::commitEntry(); } },
    { faker::StructureToken::GitCommitMessage, []() { return faker::git::commitMessage(); } },
    { faker::StructureToken::GitCommitSha, []() { return faker::git::commitSha(); } },

    { faker::StructureToken::HackerAbbreviation,
        []() { return std::string(faker::hacker::abbreviation()); } },
    { faker::StructureToken::HackerAdjective,
        []() { return std::string(faker::hacker::adjective()); } },
    { faker::StructureToken::HackerNoun, []() { return std::string(faker::hacker::noun()); } },
    { faker::StructureToken::HackerVerb, []() { return std::string(faker::hacker::verb()); } },
    { faker::StructureToken::HackerIngverb,
        []() { return std::string(faker::hacker::ingverb()); } },
    { faker::StructureToken::HackerPhrase, []() { return faker::hacker::phrase(); } },

    { faker::StructureToken::ImageImageURL, []() { return faker::image::imageUrl(); } },
    { faker::StructureToken::ImageGitHubAvatarURL,
        []() { return faker::image::githubAvatarUrl(); } },
    { faker::StructureToken::ImageDimensions,
        []() { return std::string(faker::image::dimensions()); } },

    { faker::StructureToken::InternetUsername, []() { return faker::internet::username(); } },
    { faker::StructureToken::InternetEmail, []() { return faker::internet::email(); } },
    { faker::StructureToken::InternetExampleEmail,
        []() { return faker::internet::exampleEmail(); } },
    { faker::StructureToken::InternetPassword, []() { return faker::internet::password(); } },
    { faker::StructureToken::InternetEmoji,
        []() { return std::string(faker::internet::emoji()); } },
    { faker::StructureToken::InternetProtocol,
        []() { return std::string(faker::internet::protocol()); } },
    { faker::StructureToken::InternetHttpMethod,
        []() { return std::string(faker::internet::httpMethod()); } },
    { faker::StructureToken::InternetHttpRequestHeader,
        []() { return std::string(faker::internet::httpRequestHeader()); } },
    { faker::StructureToken::InternetHttpResponseHeader,
        []() { return std::string(faker::internet::httpResponseHeader()); } },
    { faker::StructureToken::InternetHttpMediaType,
        []() { return std::string(faker::internet::httpMediaType()); } },
    { faker::StructureToken::InternetIpv4, []() { return faker::internet::ipv4(); } },
    { faker::StructureToken::InternetIpv6, []() { return faker::internet::ipv6(); } },
    { faker::StructureToken::InternetMac, []() { return faker::internet::mac(); } },
    { faker::StructureToken::InternetURL, []() { return faker::internet::url(); } },
    { faker::StructureToken::InternetDomainName, []() { return faker::internet::domainName(); } },
    { faker::StructureToken::InternetDomainWord, []() { return faker::internet::domainWord(); } },
    { faker::StructureToken::InternetDomainSuffix,
        []() { return std::string(faker::internet::domainSuffix()); } },

    { faker::StructureToken::LocationCountry,
        []() { return std::string(faker::location::country()); } },
    { faker::StructureToken::LocationCountryCode,
        []() { return std::string(faker::location::countryCode()); } },
    { faker::StructureToken::LocationState, []() { return faker::location::state(); } },
    { faker::StructureToken::LocationCity, []() { return faker::location::city(); } },
    { faker::StructureToken::LocationZipCode, []() { return faker::location::zipCode(); } },
    { faker::StructureToken::LocationStreetAddress,
        []() { return faker::location::streetAddress(); } },
    { faker::StructureToken::LocationStreet, []() { return faker::location::street(); } },
    { faker::StructureToken::LocationBuildingNumber,
        []() { return faker::location::buildingNumber(); } },
    { faker::StructureToken::LocationSecondaryAddress,
        []() { return faker::location::secondaryAddress(); } },
    { faker::StructureToken::LocationLatitude, []() { return faker::location::latitude(); } },
    { faker::StructureToken::LocationLongitude, []() { return faker::location::longitude(); } },
    { faker::StructureToken::LocationDirection,
        []() { return std::string(faker::location::direction()); } },
    { faker::StructureToken::LocationTimeZone,
        []() { return std::string(faker::location::timeZone()); } },

    // Lorem module
    { faker::StructureToken::LoremWord, []() { return std::string(faker::lorem::word()); } },
    { faker::StructureToken::LoremWords, []() { return faker::lorem::words(); } },
    { faker::StructureToken::LoremSentence, []() { return faker::lorem::sentence(); } },
    { faker::StructureToken::LoremSentences, []() { return faker::lorem::sentences(); } },
    { faker::StructureToken::LoremSlung, []() { return faker::lorem::slug(10); } },
    { faker::StructureToken::LoremParagraph, []() { return faker::lorem::paragraph(); } },
    { faker::StructureToken::LoremParagraphs, []() { return faker::lorem::paragraphs(); } },

    // Medicine module
    { faker::StructureToken::MedicineCondition,
        []() { return std::string(faker::medicine::condition()); } },
    { faker::StructureToken::MedicineMedicalTest,
        []() { return std::string(faker::medicine::medicalTest()); } },
    { faker::StructureToken::MedicineSpecialty,
        []() { return std::string(faker::medicine::specialty()); } },

    // Movie module
    { faker::StructureToken::MovieGenre, []() { return std::string(faker::movie::genre()); } },
    { faker::StructureToken::MovieMovieTitle,
        []() { return std::string(faker::movie::movieTitle()); } },
    { faker::StructureToken::MovieTvShow, []() { return std::string(faker::movie::tvShow()); } },
    { faker::StructureToken::MovieDirector,
        []() { return std::string(faker::movie::director()); } },
    { faker::StructureToken::MovieActor, []() { return std::string(faker::movie::actor()); } },
    { faker::StructureToken::MovieActress, []() { return std::string(faker::movie::actress()); } },

    // Music module
    { faker::StructureToken::MusicArtist, []() { return faker::music::artist(); } },
    { faker::StructureToken::MusicGenre, []() { return faker::music::genre(); } },
    { faker::StructureToken::MusicSongName, []() { return faker::music::songName(); } },

    // Person module
    { faker::StructureToken::PersonFirstName, []() { return faker::person::firstName(); } },
    { faker::StructureToken::PersonLastName, []() { return faker::person::lastName(); } },
    { faker::StructureToken::PersonMiddleName, []() { return faker::person::middleName(); } },
    { faker::StructureToken::PersonFullName, []() { return faker::person::fullName(); } },
    { faker::StructureToken::PersonPrefix, []() { return faker::person::prefix(); } },
    { faker::StructureToken::PersonSuffix, []() { return faker::person::suffix(); } },
    { faker::StructureToken::PersonSex, []() { return std::string(faker::person::sex()); } },
    { faker::StructureToken::PersonGender, []() { return std::string(faker::person::gender()); } },
    { faker::StructureToken::PersonJobTitle,
        []() { return std::string(faker::person::jobTitle()); } },
    { faker::StructureToken::PersonJobDescriptor,
        []() { return std::string(faker::person::jobDescriptor()); } },
    { faker::StructureToken::PersonJobArea,
        []() { return std::string(faker::person::jobArea()); } },
    { faker::StructureToken::PersonJobType,
        []() { return std::string(faker::person::jobType()); } },
    { faker::StructureToken::PersonHoby, []() { return std::string(faker::person::hobby()); } },
    { faker::StructureToken::PersonLanguage,
        []() { return std::string(std::string(faker::person::language())); } },
    { faker::StructureToken::PersonNationality,
        []() { return std::string(std::string(faker::person::nationality())); } },
    { faker::StructureToken::PersonWesternZodiac, []() { return faker::person::westernZodiac(); } },
    { faker::StructureToken::PersonChineseZodiac, []() { return faker::person::chineseZodiac(); } },

    // Phone module
    { faker::StructureToken::PhoneNumber, []() { return faker::phone::number(); } },
    { faker::StructureToken::PhonePlatform, []() { return faker::phone::platform(); } },
    { faker::StructureToken::PhoneModelName, []() { return faker::phone::modelName(); } },
    { faker::StructureToken::PhoneManufacturer, []() { return faker::phone::manufacturer(); } },
    { faker::StructureToken::PhoneIMEI, []() { return faker::phone::imei(); } },

    // Sport module
    { faker::StructureToken::SportSport, []() { return faker::sport::sport(); } },
    { faker::StructureToken::SportSoccerTeam, []() { return faker::sport::soccerTeam(); } },
    { faker::StructureToken::SportMaleAthelete, []() { return faker::sport::maleAthlete(); } },
    { faker::StructureToken::SportFemaleAthlete, []() { return faker::sport::femaleAthlete(); } },
    { faker::StructureToken::SportSportEvent, []() { return faker::sport::sportEvent(); } },

    // System module
    { faker::StructureToken::SystemFileName, []() { return faker::system::fileName(); } },
    { faker::StructureToken::SystemFileExtension, []() { return faker::system::fileExtension(); } },
    { faker::StructureToken::SystemCommonFileName,
        []() { return faker::system::commonFileName(); } },
    { faker::StructureToken::SystemCommonFileExtension,
        []() { return faker::system::commonFileExtension(); } },
    { faker::StructureToken::SystemMimeType, []() { return faker::system::mimeType(); } },
    { faker::StructureToken::SystemCommonFileType,
        []() { return faker::system::commonFileType(); } },
    { faker::StructureToken::SystemFileType, []() { return faker::system::fileType(); } },
    { faker::StructureToken::SystemDirectoryPath, []() { return faker::system::directoryPath(); } },
    { faker::StructureToken::SystemFilePath, []() { return faker::system::filePath(); } },
    { faker::StructureToken::SystemSemver, []() { return faker::system::semver(); } },
    { faker::StructureToken::SystemNetworkInterface,
        []() { return faker::system::networkInterface(); } },
    { faker::StructureToken::SystemCron, []() { return faker::system::cron(); } },

    // VideoGame module
    { faker::StructureToken::VideoGameGameTitle, []() { return faker::video_game::gameTitle(); } },
    { faker::StructureToken::VideoGameGenre, []() { return faker::video_game::genre(); } },
    { faker::StructureToken::VideoGamePlatform, []() { return faker::video_game::platform(); } },
    { faker::StructureToken::VideoGameStudioName,
        []() { return faker::video_game::studioName(); } },

    // Weather module
    { faker::StructureToken::WeatherTemperatureMetric,
        []() { return std::to_string(faker::weather::temperature().metric); } },

    { faker::StructureToken::WeatherTemperatureImperial,
        []() { return std::to_string(faker::weather::temperature().imperial); } },
    { faker::StructureToken::WeatherPressureMetric,
        []() { return std::to_string(faker::weather::pressure().metric); } },
    { faker::StructureToken::WeatherPressureImperial,
        []() { return std::to_string(faker::weather::pressure().imperial); } },
    { faker::StructureToken::WeatherVisibilityMetric,
        []() { return std::to_string(faker::weather::visibility().metric); } },
    { faker::StructureToken::WeatherVisibilityImperial,
        []() { return std::to_string(faker::weather::visibility().imperial); } },
    { faker::StructureToken::WeatherWindSpeedMetric,
        []() { return std::to_string(faker::weather::windSpeed().metric); } },
    { faker::StructureToken::WeatherWindSpeedImperial,
        []() { return std::to_string(faker::weather::windSpeed().imperial); } },
    { faker::StructureToken::WeatherUvIndex,
        []() { return std::to_string(faker::weather::uvIndex()); } },
    { faker::StructureToken::WeatherHumidity,
        []() { return std::to_string(faker::weather::humidity()); } },
    { faker::StructureToken::WeatherWeatherDescription,
        []() { return faker::weather::weatherDescription(); } },
    { faker::StructureToken::WeatherCloudCover,
        []() { return std::to_string(faker::weather::cloudCover()); } },

    // Word module
    { faker::StructureToken::WordSample, []() { return std::string(word::sample()); } },
    { faker::StructureToken::WordWords, []() { return faker::word::words(); } },
    { faker::StructureToken::WordAdjective, []() { return std::string(word::adjective()); } },
    { faker::StructureToken::WordAdverb, []() { return std::string(word::adverb()); } },
    { faker::StructureToken::WordConjunction, []() { return std::string(word::conjunction()); } },
    { faker::StructureToken::WordInterjection, []() { return std::string(word::interjection()); } },
    { faker::StructureToken::WordNoun, []() { return std::string(word::noun()); } },
    { faker::StructureToken::WordPreposition, []() { return std::string(word::preposition()); } },
    { faker::StructureToken::WordVerb, []() { return std::string(word::verb()); } },
};

std::string json(const std::unordered_map<std::string, faker::StructureToken>& items)
{
    std::string result = "{";

    for (auto it = items.begin(); it != items.end(); ++it) {
        auto func = moduleFunctions.find(it->second)->second;

        result.append("\"" + it->first + "\":\"" + func() + "\"");

        if (std::next(it) != items.end()) {
            result.append(",");
        }
    }

    result.append("}");

    return result;
}

std::string csv(
    const std::unordered_map<std::string, faker::StructureToken>& items, const unsigned int rows)
{
    std::string result;

    std::vector<std::function<std::string()>> funcs;

    for (auto it = items.begin(); it != items.end(); ++it) {
        result.append(it->first);

        funcs.push_back(moduleFunctions.find(it->second)->second);

        if (std::next(it) != items.end()) {
            result.append(",");
        }
    }

    result.append("\n");

    std::size_t n = funcs.size();

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < n; ++j) {
            result.append(funcs[j]());

            if (j != n - 1) {
                result.append(",");
            }
        }

        result.append("\n");
    }

    return result;
}
}
