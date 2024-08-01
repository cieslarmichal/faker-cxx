#pragma once

#include <array>
#include <string_view>

namespace faker::hacker
{
const auto abbreviations = std::to_array<std::string_view>({
    "A.M.",
    "Ave.",
    "CEO",
    "CFO",
    "Dr.",
    "Mr.",
    "Mrs.",
    "Ms.",
    "P.M.",
    "Prof.",
    "St.",
    "UK",
    "USA",
    "e.g.",
    "etc.",
    "i.e.",
});

const auto adjectives = std::to_array<std::string_view>({
    "1080p",
    "auxiliary",
    "back-end",
    "bluetooth",
    "cross-platform",
    "digital",
    "haptic",
    "multi-byte",
    "neural",
    "online",
    "open-source",
    "optical",
    "primary",
    "redundant",
    "virtual",
    "wireless",
});

const auto ingverbs = std::to_array<std::string_view>({
    "backing up",
    "bypassing",
    "calculating",
    "compressing",
    "connecting",
    "copying",
    "generating",
    "hacking",
    "indexing",
    "navigating",
    "overriding",
    "parsing",
    "programming",
    "quantifying",
    "synthesizing",
    "transmitting",
});

const auto nouns = std::to_array<std::string_view>({
    "alarm",
    "array",
    "bandwidth",
    "card",
    "driver",
    "firewall",
    "hard drive",
    "interface",
    "microchip",
    "panel",
    "pixel",
    "port",
    "program",
    "protocol",
    "sensor",
    "system",
});

const auto phrases = std::to_array<std::string_view>({
    "I'll {verb} the {adjective} {abbreviation} {noun} that should {noun} {ingverb} the {abbreviation} "
    "{noun}!",
    "If we {verb} the {noun} we can get to the {abbreviation} {noun} through the {adjective} "
    "{abbreviation} {ingverb} {noun}!",
    "The {abbreviation} {noun} is down {verb} the {adjective} {noun} so we can {verb} the "
    "{abbreviation} {ingverb} {noun}!",
    "Try to {verb} the {abbreviation} {noun} {ingverb} maybe it will {verb} the {adjective} {noun}!",
    "Use the {adjective} {abbreviation} {noun} then you can {verb} the {adjective} {ingverb} {noun}!",
    "We need to {verb} the {adjective} {abbreviation} {ingverb} {noun}!",
    "You can't {verb} the {noun} without {ingverb} the {adjective} {abbreviation} {noun}!",
    "{ingverb} the {noun} won't do anything we need to {verb} the {adjective} {abbreviation} "
    "{noun}!",
});

const auto verbs = std::to_array<std::string_view>({
    "back up",
    "bypass",
    "calculate",
    "compress",
    "connect",
    "copy",
    "generate",
    "hack",
    "index",
    "navigate",
    "override",
    "parse",
    "program",
    "quantify",
    "synthesize",
    "transmit",
});

}
