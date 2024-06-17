#pragma once

#include <array>
#include <string_view>

namespace faker::Word
{
const std::array<std::string_view, 46> interjections = {
    "yuck", "oh",     "phooey", "blah", "boo",  "whoa",  "yowza",    "huzzah", "boohoo", "fooey", "geez", "pfft",
    "ew",   "ah",     "yum",    "brr",  "hm",   "yahoo", "aha",      "woot",   "drat",   "gah",   "meh",  "psst",
    "aw",   "ugh",    "yippee", "eek",  "gee",  "bah",   "gadzooks", "duh",    "ha",     "mmm",   "ouch", "phew",
    "ack",  "uh-huh", "gosh",   "hmph", "pish", "zowie", "er",       "ick",    "oof",    "um",
};
}
