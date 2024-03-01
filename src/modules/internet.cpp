#include "../common/formatter.h"
#include "../common/random.h"
#include "../common/strings.h"
#include "internet_data.h"
#include "string_data.h"
#include <cassert>
#include <faker/internet.h>
#include <faker/number.h>
#include <faker/person.h>
#include <faker/string.h>
#include <faker/types/country.h>
#include <faker/word.h>
#include <vector>

namespace faker::internet {
namespace {
    const std::array<std::string_view, 2> web_protocols { "http", "https" };
    const std::array<std::string_view, 5> http_method_names { "GET", "POST", "DELETE", "PATCH",
        "PUT" };
    const std::array<unsigned, 4> http_status_codes_1xx { 100, 101, 102, 103 };
    const std::array<unsigned, 10> http_status_codes_2xx { 200, 201, 202, 203, 204, 205, 206, 207,
        208, 226 };
    const std::array<unsigned, 9> http_status_codes_3xx { 300, 301, 302, 303, 304, 305, 306, 307,
        308 };
    const std::array<unsigned, 30> http_status_codes_4xx { 400, 401, 402, 403, 404, 405, 406, 407,
        408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 421, 422, 423, 424, 425, 426, 428,
        429, 431, 451 };
    const std::array<unsigned, 11> http_status_codes_5xx { 500, 501, 502, 503, 504, 505, 506, 507,
        508, 510, 511 };
    constexpr unsigned ipv4_address_sectors = 4u;
    constexpr unsigned ipv4_class_c_first_sector = 192u;
    constexpr unsigned ipv4_class_c_second_sector = 168u;
    constexpr unsigned ipv4_class_a_second_sector = 10u;
    constexpr unsigned ipv4_class_b_second_sector = 172;
    constexpr unsigned ipv4_class_b_second_sector_lower_bound = 16u;
    constexpr unsigned ipv4_class_b_second_sector_upper_bound = 31u;
    constexpr unsigned ipv4_sector_upper_bound = 255u;

    // TODO optimize this. There should be an utility in random, like:
    // random::element_from(cont1, cont2, ...)
    std::vector<std::string_view> merge_all_emojis()
    {
        std::vector<std::string_view> result;

        result.reserve(result.size() + data::smiley_emojis.size() + data::body_emojis.size()
            + data::person_emojis.size() + data::nature_emojis.size() + data::food_emojis.size()
            + data::travel_emojis.size() + data::activity_emojis.size() + data::object_emojis.size()
            + data::symbol_emojis.size() + data::flag_emojis.size());

        result.insert(result.end(), data::smiley_emojis.begin(), data::smiley_emojis.end());
        result.insert(result.end(), data::body_emojis.begin(), data::body_emojis.end());
        result.insert(result.end(), data::person_emojis.begin(), data::person_emojis.end());
        result.insert(result.end(), data::nature_emojis.begin(), data::nature_emojis.end());
        result.insert(result.end(), data::food_emojis.begin(), data::food_emojis.end());
        result.insert(result.end(), data::travel_emojis.begin(), data::travel_emojis.end());
        result.insert(result.end(), data::activity_emojis.begin(), data::activity_emojis.end());
        result.insert(result.end(), data::object_emojis.begin(), data::object_emojis.end());
        result.insert(result.end(), data::symbol_emojis.begin(), data::symbol_emojis.end());
        result.insert(result.end(), data::flag_emojis.begin(), data::flag_emojis.end());

        return result;
    }

    const std::vector<std::string_view> all_emojis = merge_all_emojis();

    std::vector<unsigned> merge_all_http_status_codes()
    {
        std::vector<unsigned> result;

        result.reserve(result.size() + http_status_codes_1xx.size() + http_status_codes_2xx.size()
            + http_status_codes_3xx.size() + http_status_codes_4xx.size()
            + http_status_codes_5xx.size());

        result.insert(result.end(), http_status_codes_1xx.begin(), http_status_codes_1xx.end());
        result.insert(result.end(), http_status_codes_2xx.begin(), http_status_codes_2xx.end());
        result.insert(result.end(), http_status_codes_3xx.begin(), http_status_codes_3xx.end());
        result.insert(result.end(), http_status_codes_4xx.begin(), http_status_codes_4xx.end());
        result.insert(result.end(), http_status_codes_5xx.begin(), http_status_codes_5xx.end());

        return result;
    }

    const std::vector<unsigned> all_http_status_codes = merge_all_http_status_codes();
}

std::string username(
    std::optional<std::string> first_name, std::optional<std::string> last_name, country_t country)
{
    static const std::array<std::string_view, 3> name_separators;

    auto user_first_name = first_name ? *first_name : person::first_name(country);
    auto user_last_name = last_name ? *last_name : person::last_name(country);

    std::string result;

    switch (number::integer(2)) {
    case 0:
        result = utils::format("{}{}{}", user_first_name, user_last_name, number::integer(999));
        break;
    case 1:
        result = utils::format(
            "{}{}{}", user_first_name, random::element(name_separators), user_last_name);
        break;
    case 2:
        result = utils::format("{}{}{}{}", user_first_name, random::element(name_separators),
            user_last_name, number::integer(99));
        break;
    }

    return result;
}

std::string email(std::optional<std::string> first_name, std::optional<std::string> last_name,
    std::optional<std::string> email_host)
{
    return utils::format("{}@{}", username(first_name, last_name),
        email_host ? *email_host : random::element(data::email_hosts));
}

std::string example_email(
    std::optional<std::string> first_name, std::optional<std::string> last_name)
{
    return utils::format(
        "{}@{}", username(first_name, last_name), random::element(data::email_example_hosts));
}

std::string password(unsigned length, password_options options)
{
    std::string allowed_chars;

    // TODO move this logic to the string module. There should be a generator
    // accepting these options.
    if (options & password_options::upper_letters) {
        allowed_chars += string::data::ascii_upper_letters;
    }
    if (options & password_options::lower_letters) {
        allowed_chars += string::data::ascii_lower_letters;
    }
    if (options & password_options::numbers) {
        allowed_chars += string::data::digits;
    }
    if (options & password_options::symbols) {
        allowed_chars += string::data::symbols;
    }

    std::string result;
    result.reserve(length);

    for (unsigned i = 0; i < length; ++i) {
        result += random::element(allowed_chars);
    }

    return result;
}

std::string_view emoji(std::optional<emoji_type> type)
{
    if (type) {
        switch (*type) {
        case emoji_type::smiley:
            return random::element(data::smiley_emojis);
        case emoji_type::body:
            return random::element(data::body_emojis);
        case emoji_type::person:
            return random::element(data::person_emojis);
        case emoji_type::nature:
            return random::element(data::nature_emojis);
        case emoji_type::food:
            return random::element(data::food_emojis);
        case emoji_type::travel:
            return random::element(data::travel_emojis);
        case emoji_type::activity:
            return random::element(data::activity_emojis);
        case emoji_type::object:
            return random::element(data::object_emojis);
        case emoji_type::symbol:
            return random::element(data::symbol_emojis);
        case emoji_type::flag:
            return random::element(data::flag_emojis);
        }
    }

    return random::element(all_emojis);
}

bool is_valid_emoji(const std::string& emoji_to_check)
{
    return std::find(all_emojis.begin(), all_emojis.end(), emoji_to_check) != all_emojis.end();
}

std::string_view protocol() { return random::element(web_protocols); }

std::string_view http_method() { return random::element(http_method_names); }

unsigned http_status_code(std::optional<http_response_type> response_type)
{
    if (response_type) {
        switch (*response_type) {
        case http_response_type::informational:
            return random::element(http_status_codes_1xx);
        case http_response_type::success:
            return random::element(http_status_codes_2xx);
        case http_response_type::redirection:
            return random::element(http_status_codes_3xx);
        case http_response_type::client_error:
            return random::element(http_status_codes_4xx);
        case http_response_type::server_error:
            return random::element(http_status_codes_5xx);
        default:
            assert(false && "Invalid http response type");
        }
    }

    return random::element(all_http_status_codes);
}

std::string_view http_request_header() { return random::element(data::http_request_headers); }

std::string_view http_response_header() { return random::element(data::http_response_headers); }

std::string_view http_media_type() { return random::element(data::http_media_types); }

std::string ipv4(ipv4_class ipv4class)
{
    std::array<unsigned, 4> sectors {};

    sectors[3] = number::integer(ipv4_sector_upper_bound);
    sectors[2] = number::integer(ipv4_sector_upper_bound);

    switch (ipv4class) {
    case ipv4_class::a: {
        sectors[1] = number::integer(ipv4_sector_upper_bound);
        sectors[0] = ipv4_class_a_second_sector;
        break;
    }
    case ipv4_class::b: {
        sectors[1] = number::integer(
            ipv4_class_b_second_sector_lower_bound, ipv4_class_b_second_sector_upper_bound);
        sectors[0] = ipv4_class_b_second_sector;
        break;
    }
    case ipv4_class::c: {
        sectors[1] = ipv4_class_c_second_sector;
        sectors[0] = ipv4_class_c_first_sector;
    }
    }

    return utils::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string ipv4(const std::array<unsigned, 4>& base_ipv4_address,
    const std::array<unsigned, 4>& generation_mask)
{
    std::array<unsigned, 4> sectors {};

    for (std::size_t i = 0; i < ipv4_address_sectors; i++) {
        sectors[i] = (~generation_mask[i]) & number::integer(ipv4_sector_upper_bound);
        sectors[i] |= (base_ipv4_address[i] & generation_mask[i]);
    }

    return utils::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string ipv6()
{
    std::string result;
    result.reserve(39);

    result += string::hexadecimal(4, hex_case_t::lower, hex_prefix_t::none);
    for (size_t i = 0; i < 7; ++i) {
        result += ':';
        result += string::hexadecimal(4, hex_case_t::lower, hex_prefix_t::none);
    }

    return result;
}

std::string mac(const std::string& sep)
{
    static std::array<std::string_view, 3> acceptable_separators = { ":", "-", "" };

    std::string final_sep
        = std::find(acceptable_separators.begin(), acceptable_separators.end(), sep)
            != acceptable_separators.end()
        ? sep
        : ":";
    std::string result;

    for (unsigned i = 0; i < 12; i++) {
        result += number::hex();
        if (i % 2 == 1 && i != 11) {
            result += final_sep;
        }
    }
    return result;
}

unsigned port() { return number::integer(65535u); }

std::string url(web_protocol protocol)
{
    auto protocol_name = protocol == web_protocol::https ? "https" : "http";
    return utils::format("{}://{}", protocol_name, domain_name());
}

std::string domain_name() { return utils::format("{}.{}", domain_word(), domain_suffix()); }

std::string domain_word()
{
    return utils::to_lower(utils::format("{}-{}", word::adjective(), word::noun()));
}

std::string_view domain_suffix() { return random::element(data::domain_suffixes); }

}
