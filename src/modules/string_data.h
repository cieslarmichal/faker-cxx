#ifndef FAKER_MODULES_STRING_DATA_H
#define FAKER_MODULES_STRING_DATA_H

#include <faker/string.h>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

namespace faker::string::data {
extern const std::string_view upperCharacters;
extern const std::string_view lowerCharacters;
extern const std::string_view numericCharactersWithoutZero;
extern const std::string_view numericCharacters;
extern const std::string_view mixedAlphaCharacters;
extern const std::string_view lowerAlphanumericCharacters;
extern const std::string_view upperAlphanumericCharacters;
extern const std::string_view mixedAlphanumericCharacters;
extern const std::string_view hexUpperCharacters;
extern const std::string_view hexLowerCharacters;
extern const std::string_view symbolCharacters;
extern const std::unordered_set<char> lowerCharSet;
extern const std::unordered_set<char> upperCharSet;
extern const std::unordered_set<char> mixedAlphaCharSet;
extern const std::unordered_set<char> hexUpperCharSet;
extern const std::unordered_set<char> hexLowerCharSet;
extern const std::unordered_set<char> digitSet;
extern const std::unordered_set<char> utf16CharSet;
extern const std::unordered_map<string_case, std::unordered_set<char>>
    stringCasingToAlphaCharSetMapping;
}

#endif