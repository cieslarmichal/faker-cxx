#pragma once

#include <array>
#include <string_view>

namespace faker
{
const std::array<std::string_view,51> conjunctions = {
    "after",    "although",     "and",      "as",          "because", "before",   "but",       "consequently",
    "even",     "finally",      "for",      "furthermore", "hence",   "how",      "however",   "if",
    "inasmuch", "incidentally", "indeed",   "instead",     "lest",    "likewise", "meanwhile", "nor",
    "now",      "once",         "or",       "provided",    "since",   "so",       "supposing", "than",
    "that",     "though",       "till",     "unless",      "until",   "what",     "when",      "whenever",
    "where",    "whereas",      "wherever", "whether",     "which",   "while",    "who",       "whoever",
    "whose",    "why",          "yet"};
}
