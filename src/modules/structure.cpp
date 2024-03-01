#include "../common/formatter.h"
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

std::string moduleFunction(structure_token_t token)
{
    switch (token) {
    // Airline module
    case structure_token_t::airline_aircraft_type:
        return std::string(airline::aircraft_type_name());
    case structure_token_t::airline_airplane_name:
        return std::string(airline::airplane().name);
    case structure_token_t::airline_airplane_code:
        return std::string(airline::airplane().iata_type_code);
    case structure_token_t::airline_airline_name:
        return std::string(airline::airline().name);
    case structure_token_t::airline_airline_code:
        return std::string(airline::airline().iata_code);
    case structure_token_t::airline_airport_name:
        return std::string(airline::airport().name);
    case structure_token_t::airline_airport_code:
        return std::string(airline::airport().iata_code);
    case structure_token_t::airline_seat:
        return airline::seat(airline::aircraft_type());
    case structure_token_t::airline_record_locator:
        return airline::record_locator();
    case structure_token_t::airline_flight_number:
        return airline::flight_number(false, 4);
    // Animal module
    case structure_token_t::animal_bear:
        return std::string(animal::bear());
    case structure_token_t::animal_bird:
        return std::string(animal::bird());
    case structure_token_t::animal_cat:
        return std::string(animal::cat());
    case structure_token_t::animal_cetacean:
        return std::string(animal::cetacean());
    case structure_token_t::animal_cow:
        return std::string(animal::cow());
    case structure_token_t::animal_crocodilia:
        return std::string(animal::crocodilia());
    case structure_token_t::animal_dog:
        return std::string(animal::dog());
    case structure_token_t::animal_fish:
        return std::string(animal::fish());
    case structure_token_t::animal_horse:
        return std::string(animal::horse());
    case structure_token_t::animal_insect:
        return std::string(animal::insect());
    case structure_token_t::animal_lion:
        return std::string(animal::lion());
    case structure_token_t::animal_rabbit:
        return std::string(animal::rabbit());
    case structure_token_t::animal_rodent:
        return std::string(animal::rodent());
    case structure_token_t::animal_snake:
        return std::string(animal::snake());
    case structure_token_t::animal_type:
        return std::string(animal::type());
    // Book module
    case structure_token_t::book_title:
        return std::string(book::title());
    case structure_token_t::book_genre:
        return std::string(book::genre());
    case structure_token_t::book_author:
        return std::string(book::author());
    case structure_token_t::book_publisher:
        return std::string(book::publisher());
    case structure_token_t::book_isbn:
        return book::isbn();
    // Color module
    case structure_token_t::color_name:
        return std::string(color::name());
    case structure_token_t::color_rgb:
        return color::rgb();
    case structure_token_t::color_hex:
        return color::hex();
    case structure_token_t::color_hsl:
        return color::hsl();
    case structure_token_t::color_lch:
        return color::lch();
    case structure_token_t::color_cmyk:
        return color::cmyk();
    // Commerce module
    case structure_token_t::commerce_department:
        return std::string(commerce::department());
    case structure_token_t::commerce_price:
        return commerce::price();
    case structure_token_t::commerce_sku:
        return commerce::sku();
    case structure_token_t::commerce_product_adjective:
        return std::string(commerce::product_adjective());
    case structure_token_t::commerce_product_material:
        return std::string(commerce::product_material());
    case structure_token_t::commerce_product_name:
        return std::string(commerce::product_name());
    case structure_token_t::commerce_product_full_name:
        return commerce::product_full_name();
    case structure_token_t::commerce_product_ean13:
        return commerce::ean13();
    case structure_token_t::commerce_product_ean8:
        return commerce::ean8();
    case structure_token_t::commerce_product_isbn13:
        return commerce::isbn13();
    case structure_token_t::commerce_product_isbn10:
        return commerce::isbn10();
    // Company module
    case structure_token_t::company_name:
        return company::name();
    case structure_token_t::company_type:
        return std::string(company::type());
    case structure_token_t::company_industry:
        return std::string(company::industry());
    case structure_token_t::company_buzz_phrase:
        return company::buzz_phrase();
    case structure_token_t::company_buzz_adjective:
        return std::string(company::buzz_adjective());
    case structure_token_t::company_buzz_noun:
        return std::string(company::buzz_noun());
    case structure_token_t::company_buzz_verb:
        return std::string(company::buzz_verb());
    case structure_token_t::company_catch_phrase:
        return company::catch_phrase();
    case structure_token_t::company_catch_phrase_adjective:
        return std::string(company::catch_phrase_adjective());
    case structure_token_t::company_catch_phrase_descriptor:
        return std::string(company::catch_phrase_descriptor());
    case structure_token_t::company_catch_phrase_noun:
        return std::string(company::catch_phrase_noun());
    // Computer module
    case structure_token_t::computer_manufacturer:
        return std::string(computer::manufacturer());
    case structure_token_t::computer_model:
        return std::string(computer::model());
    case structure_token_t::computer_cpu_manufacturer:
        return std::string(computer::cpu_manufacturer());
    case structure_token_t::computer_cpu_type:
        return std::string(computer::cpu_type());
    case structure_token_t::computer_cpu_model:
        return std::string(computer::cpu_model());
    case structure_token_t::computer_gpu_manufacturer:
        return std::string(computer::gpu_manufacturer());
    case structure_token_t::computer_gpu_type:
        return std::string(computer::gpu_type());
    case structure_token_t::computer_gpu_model:
        return std::string(computer::gpu_model());
    // Crypto module
    case structure_token_t::crypto_sha256:
        return crypto::sha256();
    case structure_token_t::crypto_md5:
        return crypto::md5();
    // Database module
    case structure_token_t::database_column_name:
        return std::string(database::column_name());
    case structure_token_t::database_column_type:
        return std::string(database::column_type());
    case structure_token_t::database_collation:
        return std::string(database::collation());
    case structure_token_t::database_engine:
        return std::string(database::engine());
    case structure_token_t::database_mongodb_object_id:
        return database::mongodb_object_id();
    // Datatype module
    case structure_token_t::datatype_boolean:
        return std::to_string(datatype::boolean());
    // Date module
    case structure_token_t::date_past_date_iso:
        return date::past();
    case structure_token_t::date_past_date_timestamp:
        return date::past(1, date::date_format::timestamp);
    case structure_token_t::date_future_date_iso:
        return date::future();
    case structure_token_t::date_future_date_timestamp:
        return date::future(1, date::date_format::timestamp);
    case structure_token_t::date_recent_date_iso:
        return date::recent();
    case structure_token_t::date_recent_date_timestamp:
        return date::recent(3, date::date_format::timestamp);
    case structure_token_t::date_soon_date_iso:
        return date::soon();
    case structure_token_t::date_soon_date_timestamp:
        return date::soon(3, date::date_format::timestamp);
    case structure_token_t::date_birthdate_by_age_iso:
        return date::birthdate_by_age();
    case structure_token_t::date_birthdate_by_year_timestamp:
        return date::birthdate_by_year(1920, 2000, date::date_format::timestamp);
    case structure_token_t::date_weekday_name:
        return std::string(date::weekday_name());
    case structure_token_t::date_weekday_abbr_name:
        return std::string(date::weekday_abbr_name());
    case structure_token_t::date_month_name:
        return std::string(date::month_name());
    case structure_token_t::date_month_abbr_name:
        return std::string(date::month_abbr_name());
    // Finance module
    case structure_token_t::finance_currency_name:
        return std::string(finance::currency_name());
    case structure_token_t::finance_currency_code:
        return std::string(finance::currency_code());
    case structure_token_t::finance_currency_symbol:
        return std::string(finance::currency_symbol());
    case structure_token_t::finance_account_type:
        return std::string(finance::account_type());
    case structure_token_t::finance_amount:
        return finance::amount();
    case structure_token_t::finance_iban:
        return finance::iban();
    case structure_token_t::finance_bic:
        return std::string(finance::bic());
    case structure_token_t::finance_account_number:
        return finance::account_number();
    case structure_token_t::finance_pin:
        return finance::pin();
    case structure_token_t::finance_routing_number:
        return finance::routing_number();
    case structure_token_t::finance_credit_card_number:
        return finance::credit_card_number();
    case structure_token_t::finance_credit_card_cvv:
        return finance::credit_card_cvv();
    case structure_token_t::finance_bitcoin_address:
        return finance::bitcoin_address();
    case structure_token_t::finance_litecoin_address:
        return finance::litecoin_address();
    case structure_token_t::finance_ethereum_address:
        return finance::ethereum_address();
    // Food module
    case structure_token_t::food_alcoholic_beverage:
        return std::string(food::alcoholic_beverage());
    case structure_token_t::food_grain:
        return std::string(food::grain());
    case structure_token_t::food_milk_product:
        return std::string(food::milk_product());
    case structure_token_t::food_fruit:
        return std::string(food::fruit());
    case structure_token_t::food_meat:
        return std::string(food::meat());
    case structure_token_t::food_seafood:
        return std::string(food::seafood());
    case structure_token_t::food_vegetable:
        return std::string(food::vegetable());
    case structure_token_t::food_oil:
        return std::string(food::oil());
    case structure_token_t::food_nut:
        return std::string(food::nut());
    case structure_token_t::food_seed:
        return std::string(food::seed());
    case structure_token_t::food_sugar_product:
        return std::string(food::sugar_product());
    case structure_token_t::food_non_alchocolic_beverage:
        return std::string(food::non_alcoholic_beverage());
    case structure_token_t::food_dish_name:
        return std::string(food::dish_name());
    case structure_token_t::food_food_category:
        return std::string(food::category());
    // Git module
    case structure_token_t::git_branch:
        return git::branch();
    case structure_token_t::git_commit_date:
        return git::commit_date();
    case structure_token_t::git_commit_entry:
        return git::commit_entry();
    case structure_token_t::git_commit_message:
        return git::commit_message();
    case structure_token_t::git_commit_sha:
        return git::commit_sha();
    // Hacker module
    case structure_token_t::hacker_abbreviation:
        return std::string(hacker::abbreviation());
    case structure_token_t::hacker_adjective:
        return std::string(hacker::adjective());
    case structure_token_t::hacker_noun:
        return std::string(hacker::noun());
    case structure_token_t::hacker_verb:
        return std::string(hacker::verb());
    case structure_token_t::hacker_ingverb:
        return std::string(hacker::ingverb());
    case structure_token_t::hacker_phrase:
        return hacker::phrase();
    // Image module
    case structure_token_t::image_image_url:
        return image::image_url();
    case structure_token_t::image_github_avatar_url:
        return image::github_avatar_url();
    case structure_token_t::image_dimensions:
        return std::string(image::dimensions());
    // Internet module
    case structure_token_t::internet_username:
        return internet::username();
    case structure_token_t::internet_email:
        return internet::email();
    case structure_token_t::internet_example_email:
        return internet::example_email();
    case structure_token_t::internet_password:
        return internet::password();
    case structure_token_t::internet_emoji:
        return std::string(internet::emoji());
    case structure_token_t::internet_protocol:
        return std::string(internet::protocol());
    case structure_token_t::internet_http_method:
        return std::string(internet::http_method());
    case structure_token_t::internet_http_request_header:
        return std::string(internet::http_request_header());
    case structure_token_t::internet_http_response_header:
        return std::string(internet::http_response_header());
    case structure_token_t::internet_http_media_type:
        return std::string(internet::http_media_type());
    case structure_token_t::internet_ipv4:
        return internet::ipv4();
    case structure_token_t::internet_ipv6:
        return internet::ipv6();
    case structure_token_t::internet_mac:
        return internet::mac();
    case structure_token_t::internet_url:
        return internet::url();
    case structure_token_t::internet_domain_name:
        return internet::domain_name();
    case structure_token_t::internet_domain_word:
        return internet::domain_word();
    case structure_token_t::internet_domain_suffix:
        return std::string(internet::domain_suffix());
    // Location module
    case structure_token_t::location_country:
        return std::string(location::country_name());
    case structure_token_t::location_country_code:
        return std::string(location::country_code());
    case structure_token_t::location_state:
        return std::string(location::state());
    case structure_token_t::location_city:
        return location::city();
    case structure_token_t::location_zip_code:
        return location::zip_code();
    case structure_token_t::location_street_address:
        return location::street_address();
    case structure_token_t::location_street:
        return location::street();
    case structure_token_t::location_building_number:
        return location::building_number();
    case structure_token_t::location_secondary_address:
        return location::secondary_address();
    case structure_token_t::location_latitude:
        return location::latitude();
    case structure_token_t::location_longitude:
        return location::longitude();
    case structure_token_t::location_direction:
        return std::string(location::direction());
    case structure_token_t::location_time_zone:
        return std::string(location::time_zone());
    // Lorem module
    case structure_token_t::lorem_word:
        return std::string(lorem::word());
    case structure_token_t::lorem_words:
        return lorem::words();
    case structure_token_t::lorem_sentence:
        return lorem::sentence();
    case structure_token_t::lorem_sentences:
        return lorem::sentences();
    case structure_token_t::lorem_slug:
        return lorem::slug(10);
    case structure_token_t::lorem_paragraph:
        return lorem::paragraph();
    case structure_token_t::lorem_paragraphs:
        return lorem::paragraphs();
    // Medicine module
    case structure_token_t::medicine_condition:
        return std::string(medicine::condition());
    case structure_token_t::medicine_medical_test:
        return std::string(medicine::medical_test());
    case structure_token_t::medicine_specialty:
        return std::string(medicine::specialty());
    // Movie module
    case structure_token_t::movie_genre:
        return std::string(movie::genre());
    case structure_token_t::movie_movie_title:
        return std::string(movie::movie_title());
    case structure_token_t::movie_tv_show:
        return std::string(movie::tv_show());
    case structure_token_t::movie_director:
        return std::string(movie::director());
    case structure_token_t::movie_actor:
        return std::string(movie::actor());
    case structure_token_t::movie_actress:
        return std::string(movie::actress());
    // Music module
    case structure_token_t::music_artist:
        return std::string(music::artist());
    case structure_token_t::music_genre:
        return std::string(music::genre());
    case structure_token_t::music_song_name:
        return std::string(music::song_name());
    // Person module
    case structure_token_t::person_first_name:
        return std::string(person::first_name());
    case structure_token_t::person_last_name:
        return std::string(person::last_name());
    case structure_token_t::person_middle_name:
        return std::string(person::middle_name());
    case structure_token_t::person_full_name:
        return person::full_name();
    case structure_token_t::person_prefix:
        return std::string(person::prefix());
    case structure_token_t::person_suffix:
        return std::string(person::suffix());
    case structure_token_t::person_sex:
        return std::string(person::sex());
    case structure_token_t::person_gender:
        return std::string(person::gender());
    case structure_token_t::person_job_title:
        return std::string(person::job_title());
    case structure_token_t::person_job_descriptor:
        return std::string(person::job_descriptor());
    case structure_token_t::person_job_area:
        return std::string(person::job_area());
    case structure_token_t::person_job_type:
        return std::string(person::job_type());
    case structure_token_t::person_hobby:
        return std::string(person::hobby());
    case structure_token_t::person_language:
        return std::string(std::string(person::language()));
    case structure_token_t::person_nationality:
        return std::string(std::string(person::nationality()));
    case structure_token_t::person_western_zodiac:
        return std::string(person::western_zodiac());
    case structure_token_t::person_chinese_zodiac:
        return std::string(person::chinese_zodiac());
    // Phone module
    case structure_token_t::phone_number:
        return phone::number();
    case structure_token_t::phone_platform:
        return std::string(phone::platform());
    case structure_token_t::phone_model_name:
        return std::string(phone::model_name());
    case structure_token_t::phone_manufacturer:
        return std::string(phone::manufacturer());
    case structure_token_t::phone_imei:
        return phone::imei();
    // Sport module
    case structure_token_t::sport_sport:
        return std::string(sport::sport());
    case structure_token_t::sport_soccer_team:
        return std::string(sport::soccer_team());
    case structure_token_t::sport_male_athlete:
        return std::string(sport::male_athlete());
    case structure_token_t::sport_female_athlete:
        return std::string(sport::female_athlete());
    case structure_token_t::sport_sport_event:
        return std::string(sport::sport_event());
    // System module
    case structure_token_t::system_file_name:
        return system::filename();
    case structure_token_t::system_file_extension:
        return std::string(system::file_ext());
    case structure_token_t::system_common_file_name:
        return system::common_filename();
    case structure_token_t::system_common_file_extension:
        return std::string(system::common_file_ext());
    case structure_token_t::system_mime_type:
        return std::string(system::mime_type());
    case structure_token_t::system_common_file_type:
        return std::string(system::common_file_type());
    case structure_token_t::system_file_type:
        return std::string(system::file_type());
    case structure_token_t::system_directory_path:
        return std::string(system::directory_path());
    case structure_token_t::system_file_path:
        return system::file_path();
    case structure_token_t::system_semver:
        return system::semver();
    case structure_token_t::system_network_interface:
        return system::network_interface();
    case structure_token_t::system_cron:
        return system::cron();
    // VideoGame module
    case structure_token_t::video_game_game_title:
        return std::string(video_game::title());
    case structure_token_t::video_game_genre:
        return std::string(video_game::genre());
    case structure_token_t::video_game_platform:
        return std::string(video_game::platform());
    case structure_token_t::video_game_studio_name:
        return std::string(video_game::studio_name());
    // Weather module
    case structure_token_t::weather_temperature_metric:
        return std::to_string(weather::temperature().metric);
    case structure_token_t::weather_temperature_imperial:
        return std::to_string(weather::temperature().imperial);
    case structure_token_t::weather_pressure_metric:
        return std::to_string(weather::pressure().metric);
    case structure_token_t::weather_pressure_imperial:
        return std::to_string(weather::pressure().imperial);
    case structure_token_t::weather_visibility_metric:
        return std::to_string(weather::visibility().metric);
    case structure_token_t::weather_visibility_imperial:
        return std::to_string(weather::visibility().imperial);
    case structure_token_t::weather_wind_speed_metric:
        return std::to_string(weather::wind_speed().metric);
    case structure_token_t::weather_wind_speed_imperial:
        return std::to_string(weather::wind_speed().imperial);
    case structure_token_t::weather_uv_index:
        return std::to_string(weather::uv_index());
    case structure_token_t::weather_humidity:
        return std::to_string(weather::humidity());
    case structure_token_t::weather_weather_description:
        return std::string(weather::description());
    case structure_token_t::weather_cloud_cover:
        return std::to_string(weather::cloud_cover());
    // Word module
    case structure_token_t::word_sample:
        return std::string(word::sample());
    case structure_token_t::word_words:
        return word::words();
    case structure_token_t::word_adjective:
        return std::string(word::adjective());
    case structure_token_t::word_adverb:
        return std::string(word::adverb());
    case structure_token_t::word_conjunction:
        return std::string(word::conjunction());
    case structure_token_t::word_interjection:
        return std::string(word::interjection());
    case structure_token_t::word_noun:
        return std::string(word::noun());
    case structure_token_t::word_preposition:
        return std::string(word::preposition());
    case structure_token_t::word_verb:
        return std::string(word::verb());
    // leftovers
    case structure_token_t::computer_type:
    case structure_token_t::date_birthdate_by_age_timestamp:
    case structure_token_t::date_birthdate_by_year_iso:
        return "";
    default:
        assert(false && "Invalid token");
        return "";
    }
}

std::string json(const std::vector<structure_token_spec>& items)
{
    std::string result = "{";

    switch (items.size()) {
    case 0:
        break;
    case 1: {
        result.append(
            utils::format(R"("{}": "{}")", items[0].name, moduleFunction(items[0].token)));
        break;
    }
    default: {
        result.append(
            utils::format(R"("{}": "{}",)", items[0].name, moduleFunction(items[0].token)));
        for (size_t i = 1; i < items.size(); ++i) {
            result.append(
                utils::format("(\n\"{}\": \"{}\")", items[i].name, moduleFunction(items[i].token)));
        }
        break;
    }
    }

    result.append("}");

    return result;
}

std::string csv(const std::vector<structure_token_spec>& items, unsigned row_count)
{
    std::string result;

    switch (items.size()) {
    case 0:
        break;
    case 1:
        result += items[0].name;
        result += '\n';
        for (size_t i = 0; i < row_count; i++) {
            result += moduleFunction(items[0].token);
            result += '\n';
        }
        break;
    default: {
        result += items[0].name;
        for (size_t i = 1; i < items.size(); i++) {
            result.append(1, ',');
            result += items[i].name;
        }
        result += '\n';
        for (size_t i = 0; i < row_count; i++) {
            bool first = true;
            for (auto item : items) {
                if (first) {
                    result.append(1, ',');
                    first = false;
                }
                result.append(moduleFunction(item.token));
            }
            result.append("\n");
        }
        break;
    }
    }

    return result;
}
}
