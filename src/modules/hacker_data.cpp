#include "hacker_data.h"

namespace faker {
const std::array<std::string_view, 16> abbreviations = {
    "e.g.",
    "i.e.",
    "etc.",
    "Mr.",
    "Mrs.",
    "Ms.",
    "Dr.",
    "Prof.",
    "Ave.",
    "St.",
    "A.M.",
    "P.M.",
    "USA",
    "UK",
    "CEO",
    "CFO",
};

const std::array<std::string_view, 16> adjectives = {
    "auxiliary",
    "primary",
    "back-end",
    "digital",
    "open-source",
    "virtual",
    "cross-platform",
    "redundant",
    "online",
    "haptic",
    "multi-byte",
    "bluetooth",
    "wireless",
    "1080p",
    "neural",
    "optical",
};

const std::array<std::string_view, 16> ingverbs = {
    "backing up",
    "bypassing",
    "hacking",
    "overriding",
    "compressing",
    "copying",
    "navigating",
    "indexing",
    "connecting",
    "generating",
    "quantifying",
    "calculating",
    "synthesizing",
    "transmitting",
    "programming",
    "parsing",
};

const std::array<std::string_view, 16> nouns = {
    "driver",
    "protocol",
    "bandwidth",
    "panel",
    "microchip",
    "program",
    "port",
    "card",
    "array",
    "interface",
    "system",
    "sensor",
    "firewall",
    "hard drive",
    "pixel",
    "alarm",
};

const std::array<std::string_view, 8> phrases = {
    "If we {verb} the {noun}, we can get to the {abbreviation} {noun} through the {adjective} "
    "{abbreviation} {noun}!",
    "We need to {verb} the {adjective} {abbreviation} {noun}!",
    "Try to {verb} the {abbreviation} {noun}, maybe it will {verb} the {adjective} {noun}!",
    "You can't {verb} the {noun} without {ingverb} the {adjective} {abbreviation} {noun}!",
    "Use the {adjective} {abbreviation} {noun}, then you can {verb} the {adjective} {noun}!",
    "The {abbreviation} {noun} is down, {verb} the {adjective} {noun} so we can {verb} the "
    "{abbreviation} {noun}!",
    "{ingverb} the {noun} won't do anything, we need to {verb} the {adjective} {abbreviation} "
    "{noun}!",
    "I'll {verb} the {adjective} {abbreviation} {noun}, that should {noun} the {abbreviation} "
    "{noun}!",
};

const std::array<std::string_view, 16> verbs = {
    "back up",
    "bypass",
    "hack",
    "override",
    "compress",
    "copy",
    "navigate",
    "index",
    "connect",
    "generate",
    "quantify",
    "calculate",
    "synthesize",
    "transmit",
    "program",
    "parse",
};
}
