#ifndef FAKER_MODULES_INTERNET_DATA_H
#define FAKER_MODULES_INTERNET_DATA_H

#include <array>
#include <string_view>

namespace faker {
extern const std::array<std::string_view, 6> domainSuffixes;
extern const std::array<std::string_view, 4> emailHosts;
extern const std::array<std::string_view, 3> emailExampleHosts;
extern const std::array<std::string_view, 156> smileyEmojis;
extern const std::array<std::string_view, 246> bodyEmojis;
extern const std::array<std::string_view, 1803> personEmojis;
extern const std::array<std::string_view, 140> natureEmojis;
extern const std::array<std::string_view, 129> foodEmojis;
extern const std::array<std::string_view, 215> travelEmojis;
extern const std::array<std::string_view, 84> activityEmojis;
extern const std::array<std::string_view, 250> objectEmojis;
extern const std::array<std::string_view, 220> symbolEmojis;
extern const std::array<std::string_view, 266> flagEmojis;
extern const std::array<std::string_view, 45> httpMediaTypes;
extern const std::array<std::string_view, 41> httpRequestHeaders;
extern const std::array<std::string_view, 44> httpResponseHeaders;
}

#endif