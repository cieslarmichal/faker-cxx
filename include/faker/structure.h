#ifndef FAKER_STRUCTURE_H
#define FAKER_STRUCTURE_H

#include <string>
#include <utility>
#include <vector>

namespace faker::structure {
enum class structure_token_t {
    // Airline module
    airline_aircraft_type,
    airline_airplane_name,
    airline_airplane_code,
    airline_airline_name,
    airline_airline_code,
    airline_airport_name,
    airline_airport_code,
    airline_seat,
    airline_record_locator,
    airline_flight_number,

    // Animal module
    animal_bear,
    animal_bird,
    animal_cat,
    animal_cetacean,
    animal_cow,
    animal_crocodilia,
    animal_dog,
    animal_fish,
    animal_horse,
    animal_insect,
    animal_lion,
    animal_rabbit,
    animal_rodent,
    animal_snake,
    animal_type,

    // Book module
    book_title,
    book_genre,
    book_author,
    book_publisher,
    book_isbn,

    // Color module
    color_name,
    color_rgb,
    color_hex,
    color_hsl,
    color_lch,
    color_cmyk,

    // Commerce module
    commerce_department,
    commerce_price,
    commerce_sku,
    commerce_product_adjective,
    commerce_product_material,
    commerce_product_name,
    commerce_product_full_name,
    commerce_product_ean13,
    commerce_product_ean8,
    commerce_product_isbn13,
    commerce_product_isbn10,

    // Company module
    company_name,
    company_type,
    company_industry,
    company_buzz_phrase,
    company_buzz_adjective,
    company_buzz_noun,
    company_buzz_verb,
    company_catch_phrase,
    company_catch_phrase_adjective,
    company_catch_phrase_descriptor,
    company_catch_phrase_noun,

    // Computer module
    computer_type,
    computer_manufacturer,
    computer_model,
    computer_cpu_manufacturer,
    computer_cpu_type,
    computer_cpu_model,
    computer_gpu_manufacturer,
    computer_gpu_type,
    computer_gpu_model,

    // Crypto module
    crypto_sha256,
    crypto_md5,

    // Database module
    database_column_name,
    database_column_type,
    database_collation,
    database_engine,
    database_mongodb_object_id,

    // Datatype module
    datatype_boolean,

    // Date module ISO and Timestamp
    date_past_date_iso,
    date_past_date_timestamp,
    date_future_date_iso,
    date_future_date_timestamp,
    date_recent_date_iso,
    date_recent_date_timestamp,
    date_soon_date_iso,
    date_soon_date_timestamp,
    date_birthdate_by_age_iso,
    date_birthdate_by_age_timestamp,
    date_birthdate_by_year_iso,
    date_birthdate_by_year_timestamp,
    date_weekday_name,
    date_weekday_abbr_name,
    date_month_name,
    date_month_abbr_name,

    // Finance module
    finance_currency_name,
    finance_currency_code,
    finance_currency_symbol,
    finance_account_type,
    finance_amount,
    finance_iban,
    finance_bic,
    finance_account_number,
    finance_pin,
    finance_routing_number,
    finance_credit_card_number,
    finance_credit_card_cvv,
    finance_bitcoin_address,
    finance_litecoin_address,
    finance_ethereum_address,

    // Food module
    food_alcoholic_beverage,
    food_grain,
    food_milk_product,
    food_fruit,
    food_meat,
    food_seafood,
    food_vegetable,
    food_oil,
    food_nut,
    food_seed,
    food_sugar_product,
    food_non_alchocolic_beverage,
    food_dish_name,
    food_food_category,

    // Git module
    git_branch,
    git_commit_date,
    git_commit_entry,
    git_commit_message,
    git_commit_sha,

    // Hacker module
    hacker_abbreviation,
    hacker_adjective,
    hacker_noun,
    hacker_verb,
    hacker_ingverb,
    hacker_phrase,

    // Image module
    image_image_url,
    image_github_avatar_url,
    image_dimensions,

    // Internet module
    internet_username,
    internet_email,
    internet_example_email,
    internet_password,
    internet_emoji,
    internet_protocol,
    internet_http_method,
    internet_http_request_header,
    internet_http_response_header,
    internet_http_media_type,
    internet_ipv4,
    internet_ipv6,
    internet_mac,
    internet_url,
    internet_domain_name,
    internet_domain_word,
    internet_domain_suffix,

    // Location module
    location_country,
    location_country_code,
    location_state,
    location_city,
    location_zip_code,
    location_street_address,
    location_street,
    location_building_number,
    location_secondary_address,
    location_latitude,
    location_longitude,
    location_direction,
    location_time_zone,

    // Lorem module
    lorem_word,
    lorem_words,
    lorem_sentence,
    lorem_sentences,
    lorem_slug,
    lorem_paragraph,
    lorem_paragraphs,

    // Medicine module
    medicine_condition,
    medicine_medical_test,
    medicine_specialty,

    // Movie module
    movie_genre,
    movie_movie_title,
    movie_tv_show,
    movie_director,
    movie_actor,
    movie_actress,

    // Music module
    music_artist,
    music_genre,
    music_song_name,

    // Person module
    person_first_name,
    person_last_name,
    person_middle_name,
    person_full_name,
    person_prefix,
    person_suffix,
    person_sex,
    person_gender,
    person_job_title,
    person_job_descriptor,
    person_job_area,
    person_job_type,
    person_hobby,
    person_language,
    person_nationality,
    person_western_zodiac,
    person_chinese_zodiac,

    // Phone module
    phone_number,
    phone_platform,
    phone_model_name,
    phone_manufacturer,
    phone_imei,

    // Sport module
    sport_sport,
    sport_soccer_team,
    sport_male_athlete,
    sport_female_athlete,
    sport_sport_event,

    // System module
    system_file_name,
    system_file_extension,
    system_common_file_name,
    system_common_file_extension,
    system_mime_type,
    system_common_file_type,
    system_file_type,
    system_directory_path,
    system_file_path,
    system_semver,
    system_network_interface,
    system_cron,

    // VideoGame module
    video_game_game_title,
    video_game_genre,
    video_game_platform,
    video_game_studio_name,

    // Weather module
    weather_temperature_metric,
    weather_temperature_imperial,
    weather_pressure_metric,
    weather_pressure_imperial,
    weather_visibility_metric,
    weather_visibility_imperial,
    weather_wind_speed_metric,
    weather_wind_speed_imperial,
    weather_uv_index,
    weather_humidity,
    weather_weather_description,
    weather_cloud_cover,

    // Word module
    word_sample,
    word_words,
    word_adjective,
    word_adverb,
    word_conjunction,
    word_interjection,
    word_noun,
    word_preposition,
    word_verb,
};

struct structure_token_spec {
    std::string_view name;
    structure_token_t token;
};

/**
 * @brief Get a json string based on input
 *
 * @param spec a vector of structure_token_spec, describing the data to be generated
 * @return a json string based on user selected tokens
 *
 * @code
 * std::vector<structure_token_spec> testTokens;
 * testTokens.emplace_back("Airport name", structure_token_t::airline_airport_name);
 * testTokens.emplace_back("Bird name", structure_token_t::animal_bird);
 * testTokens.emplace_back("Actor name", structure_token_t::movie_actor);
 * testTokens.emplace_back("Book title", structure_token_t::book_title);
 * structure::json(testTokens) // {"FoodName":"Cajun Shrimp
 * Pasta","airlineType":"narrowbody","airportName":"Brisbane International Airport"}
 * @endcode
 */
std::string json(const std::vector<structure_token_spec>& spec);

/**
 * @brief Get a CSV string based on input
 *
 * @param spec a vector of structure_token_spec, describing the data to be generated
 * @return a josn csv based on user selected tokens and rows
 *
 * @code
 * std::vector<structure_token_spec> testTokens;
 * testTokens.emplace_back("Airport name", structure_token_t::airline_airport_name);
 * testTokens.emplace_back("Bird name", structure_token_t::animal_bird);
 * testTokens.emplace_back("Actor name", structure_token_t::movie_actor);
 * testTokens.emplace_back("Book title", structure_token_t::book_title);
 * structure::csv(testTokens,2) // FoodName,airlineType,airportName
                              Lobster Roll,widebody,Soekarno-Hatta International Airport
                              Pierogi,widebody,Brasilia-Presidente Juscelino Kubitschek
 International Airport
 * @endcode
 */
std::string csv(const std::vector<structure_token_spec>& items, unsigned rows);
}

#endif