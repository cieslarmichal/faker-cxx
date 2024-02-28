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
#include <vector>

namespace faker::structure {

std::string moduleFunction(StructureToken token)
{
    switch (token) {
    // Airline module
    case StructureToken::AirlineAircraftType:
        return std::string(airline::aircraft_type_name());
    case StructureToken::AirlineAirplaneName:
        return std::string(airline::airplane().name);
    case StructureToken::AirlineAirplaneCode:
        return std::string(airline::airplane().iata_type_code);
    case StructureToken::AirlineAirlineName:
        return std::string(airline::airline().name);
    case StructureToken::AirlineAirlineCode:
        return std::string(airline::airline().iata_code);
    case StructureToken::AirlineAirportName:
        return std::string(airline::airport().name);
    case StructureToken::AirlineAirportCode:
        return std::string(airline::airport().iata_code);
    case StructureToken::AirlineSeat:
        return airline::seat(airline::aircraft_type());
    case StructureToken::AirlineRecordLocator:
        return airline::record_locator();
    case StructureToken::AirlineFlightNumber:
        return airline::flight_number(false, 4);
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
        return std::string(commerce::product_adjective());
    case StructureToken::CommerceProductMaterial:
        return std::string(commerce::product_material());
    case StructureToken::CommerceProductName:
        return std::string(commerce::product_name());
    case StructureToken::CommerceProductFullName:
        return commerce::product_full_name();
    case StructureToken::CommerceEAN13:
        return commerce::ean13();
    case StructureToken::CommerceEAN8:
        return commerce::ean8();
    case StructureToken::CommerceISBN13:
        return commerce::isbn13();
    case StructureToken::CommerceISBN10:
        return commerce::isbn10();
    // Company module
    case StructureToken::CompanyName:
        return company::name();
    case StructureToken::CompanyType:
        return std::string(company::type());
    case StructureToken::CompanyIndustry:
        return std::string(company::industry());
    case StructureToken::CompanyBuzzPhrase:
        return company::buzz_phrase();
    case StructureToken::CompanyBuzzAdjective:
        return std::string(company::buzz_adjective());
    case StructureToken::CompanyBuzzNoun:
        return std::string(company::buzz_noun());
    case StructureToken::CompanyBuzzVerb:
        return std::string(company::buzz_verb());
    case StructureToken::CompanyCatchPhrase:
        return company::catch_phrase();
    case StructureToken::CompanyCtachPhraseAdjective:
        return std::string(company::catch_phrase_adjective());
    case StructureToken::CompanyCatchPhraseDescriptor:
        return std::string(company::catch_phrase_descriptor());
    case StructureToken::CompanyCatchPhraseNoun:
        return std::string(company::catch_phrase_noun());
    // Computer module
    case StructureToken::ComputerManufacture:
        return std::string(computer::manufacture());
    case StructureToken::ComputerModel:
        return std::string(computer::model());
    case StructureToken::ComputerCPUManufacture:
        return std::string(computer::cpu_manufacturer());
    case StructureToken::ComputerCPUType:
        return std::string(computer::cpu_type());
    case StructureToken::ComputerCPUModel:
        return std::string(computer::cpu_model());
    case StructureToken::ComputerGPUManufacture:
        return std::string(computer::gpu_manufacturer());
    case StructureToken::ComputerGPUType:
        return std::string(computer::gpu_type());
    case StructureToken::ComputerGPUModel:
        return std::string(computer::gpu_model());
    // Crypto module
    case StructureToken::CryptoSHA256:
        return crypto::sha256();
    case StructureToken::CryptoMD5:
        return crypto::md5();
    // Database module
    case StructureToken::DatabaseColumnName:
        return std::string(database::column_name());
    case StructureToken::DatabaseColumnType:
        return std::string(database::column_type());
    case StructureToken::DatabaseCollation:
        return std::string(database::collation());
    case StructureToken::DatabaseEngine:
        return std::string(database::engine());
    case StructureToken::DatabaseMongoDBObjectId:
        return database::mongodb_object_id();
    // Datatype module
    case StructureToken::DatatypeBoolean:
        return std::to_string(datatype::boolean());
    // Date module
    case StructureToken::DatePastDateISO:
        return date::past();
    case StructureToken::DatePastDateTimestamp:
        return date::past(1, date::DateFormat::Timestamp);
    case StructureToken::DatefutureDateISO:
        return date::future();
    case StructureToken::DatefutureDateTimestamp:
        return date::future(1, date::DateFormat::Timestamp);
    case StructureToken::DateRecentDateISO:
        return date::recent();
    case StructureToken::DateRecentDateTimestamp:
        return date::recent(3, date::DateFormat::Timestamp);
    case StructureToken::DateSoonDateISO:
        return date::soon();
    case StructureToken::DateSoonDateTimestamp:
        return date::soon(3, date::DateFormat::Timestamp);
    case StructureToken::DateBirthdateByAgeISO:
        return date::birthdate_by_age();
    case StructureToken::DateBirthdateByYearTimestamp:
        return date::birthdate_by_year(1920, 2000, date::DateFormat::Timestamp);
    case StructureToken::DateWeekdayName:
        return std::string(date::weekday_name());
    case StructureToken::DateWeekdayAbbreviatedName:
        return std::string(date::weekday_abbr_name());
    case StructureToken::DateMontName:
        return std::string(date::month_name());
    case StructureToken::DateMonthAbbreviatedName:
        return std::string(date::month_abbr_name());
    // Finance module
    case StructureToken::FinanceCurrencyName:
        return std::string(finance::currency_name());
    case StructureToken::FinanceCurrencyCode:
        return std::string(finance::currency_code());
    case StructureToken::FinanceCurrencySymbol:
        return std::string(finance::currency_symbol());
    case StructureToken::FinanceAccountType:
        return std::string(finance::account_type());
    case StructureToken::FinanceAmount:
        return finance::amount();
    case StructureToken::FinanceIban:
        return finance::iban();
    case StructureToken::FinanceBic:
        return std::string(finance::bic());
    case StructureToken::FinanceAccountNumber:
        return finance::account_number();
    case StructureToken::FinancePin:
        return finance::pin();
    case StructureToken::FinanceRoutingNumber:
        return finance::routing_number();
    case StructureToken::FinanceCreditCardNumber:
        return finance::credit_card_number();
    case StructureToken::FinanceCreditCardCvv:
        return finance::credit_card_cvv();
    case StructureToken::FinanceBitcoinAddress:
        return finance::bitcoin_address();
    case StructureToken::FinanceLitecoinAddress:
        return finance::litecoin_address();
    case StructureToken::FinanceEthereumAddress:
        return finance::ethereum_address();
    // Food module
    case StructureToken::FoodAlcoholicBeverage:
        return std::string(food::alcoholic_beverage());
    case StructureToken::FoodGrain:
        return std::string(food::grain());
    case StructureToken::FoodMilkProduct:
        return std::string(food::milk_product());
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
        return std::string(food::sugar_product());
    case StructureToken::FoodNonAlcoholicBeverage:
        return std::string(food::non_alcoholic_beverage());
    case StructureToken::FoodDishName:
        return std::string(food::dish_name());
    case StructureToken::FoodFoodCategory:
        return std::string(food::category());
    // Git module
    case StructureToken::GitBranch:
        return git::branch();
    case StructureToken::GitCommitDate:
        return git::commit_date();
    case StructureToken::GitCommitEntry:
        return git::commit_entry();
    case StructureToken::GitCommitMessage:
        return git::commit_message();
    case StructureToken::GitCommitSha:
        return git::commit_sha();
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
        return image::image_url();
    case StructureToken::ImageGitHubAvatarURL:
        return image::github_avatar_url();
    case StructureToken::ImageDimensions:
        return std::string(image::dimensions());
    // Internet module
    case StructureToken::InternetUsername:
        return internet::username();
    case StructureToken::InternetEmail:
        return internet::email();
    case StructureToken::InternetExampleEmail:
        return internet::example_email();
    case StructureToken::InternetPassword:
        return internet::password();
    case StructureToken::InternetEmoji:
        return std::string(internet::emoji());
    case StructureToken::InternetProtocol:
        return std::string(internet::protocol());
    case StructureToken::InternetHttpMethod:
        return std::string(internet::http_method());
    case StructureToken::InternetHttpRequestHeader:
        return std::string(internet::http_request_header());
    case StructureToken::InternetHttpResponseHeader:
        return std::string(internet::http_response_header());
    case StructureToken::InternetHttpMediaType:
        return std::string(internet::http_media_type());
    case StructureToken::InternetIpv4:
        return internet::ipv4();
    case StructureToken::InternetIpv6:
        return internet::ipv6();
    case StructureToken::InternetMac:
        return internet::mac();
    case StructureToken::InternetURL:
        return internet::url();
    case StructureToken::InternetDomainName:
        return internet::domain_name();
    case StructureToken::InternetDomainWord:
        return internet::domain_word();
    case StructureToken::InternetDomainSuffix:
        return std::string(internet::domain_suffix());
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
        return std::string(medicine::medical_test());
    case StructureToken::MedicineSpecialty:
        return std::string(medicine::specialty());
    // Movie module
    case StructureToken::MovieGenre:
        return std::string(movie::genre());
    case StructureToken::MovieMovieTitle:
        return std::string(movie::movie_title());
    case StructureToken::MovieTvShow:
        return std::string(movie::tv_show());
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
        return std::string(music::song_name());
    // Person module
    case StructureToken::PersonFirstName:
        return person::first_name();
    case StructureToken::PersonLastName:
        return person::last_name();
    case StructureToken::PersonMiddleName:
        return person::middle_name();
    case StructureToken::PersonFullName:
        return person::full_name();
    case StructureToken::PersonPrefix:
        return person::prefix();
    case StructureToken::PersonSuffix:
        return person::suffix();
    case StructureToken::PersonSex:
        return std::string(person::sex());
    case StructureToken::PersonGender:
        return std::string(person::gender());
    case StructureToken::PersonJobTitle:
        return std::string(person::job_title());
    case StructureToken::PersonJobDescriptor:
        return std::string(person::job_descriptor());
    case StructureToken::PersonJobArea:
        return std::string(person::job_area());
    case StructureToken::PersonJobType:
        return std::string(person::job_type());
    case StructureToken::PersonHoby:
        return std::string(person::hobby());
    case StructureToken::PersonLanguage:
        return std::string(std::string(person::language()));
    case StructureToken::PersonNationality:
        return std::string(std::string(person::nationality()));
    case StructureToken::PersonWesternZodiac:
        return std::string(person::western_zodiac());
    case StructureToken::PersonChineseZodiac:
        return std::string(person::chinese_zodiac());
    // Phone module
    case StructureToken::PhoneNumber:
        return phone::number();
    case StructureToken::PhonePlatform:
        return std::string(phone::platform());
    case StructureToken::PhoneModelName:
        return std::string(phone::model_name());
    case StructureToken::PhoneManufacturer:
        return std::string(phone::manufacturer());
    case StructureToken::PhoneIMEI:
        return phone::imei();
    // Sport module
    case StructureToken::SportSport:
        return std::string(sport::sport());
    case StructureToken::SportSoccerTeam:
        return std::string(sport::soccer_team());
    case StructureToken::SportMaleAthelete:
        return std::string(sport::male_athlete());
    case StructureToken::SportFemaleAthlete:
        return std::string(sport::female_athlete());
    case StructureToken::SportSportEvent:
        return std::string(sport::sport_event());
    // System module
    case StructureToken::SystemFileName:
        return system::filename();
    case StructureToken::SystemFileExtension:
        return system::file_ext();
    case StructureToken::SystemCommonFileName:
        return system::common_filename();
    case StructureToken::SystemCommonFileExtension:
        return std::string(system::common_file_ext());
    case StructureToken::SystemMimeType:
        return std::string(system::mime_type());
    case StructureToken::SystemCommonFileType:
        return std::string(system::common_file_type());
    case StructureToken::SystemFileType:
        return std::string(system::file_type());
    case StructureToken::SystemDirectoryPath:
        return std::string(system::directory_path());
    case StructureToken::SystemFilePath:
        return system::file_path();
    case StructureToken::SystemSemver:
        return system::semver();
    case StructureToken::SystemNetworkInterface:
        return system::network_interface();
    case StructureToken::SystemCron:
        return system::cron();
    // VideoGame module
    case StructureToken::VideoGameGameTitle:
        return std::string(video_game::title());
    case StructureToken::VideoGameGenre:
        return std::string(video_game::genre());
    case StructureToken::VideoGamePlatform:
        return std::string(video_game::platform());
    case StructureToken::VideoGameStudioName:
        return std::string(video_game::studio_name());
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
        return std::to_string(weather::wind_speed().metric);
    case StructureToken::WeatherWindSpeedImperial:
        return std::to_string(weather::wind_speed().imperial);
    case StructureToken::WeatherUvIndex:
        return std::to_string(weather::uv_index());
    case StructureToken::WeatherHumidity:
        return std::to_string(weather::humidity());
    case StructureToken::WeatherWeatherDescription:
        return std::string(weather::description());
    case StructureToken::WeatherCloudCover:
        return std::to_string(weather::cloud_cover());
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
