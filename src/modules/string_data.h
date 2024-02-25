#ifndef FAKER_MODULES_STRING_DATA_H
#define FAKER_MODULES_STRING_DATA_H

#include <faker/types/string_casing.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace faker {
extern const std::string upperCharacters;
extern const std::string lowerCharacters;
extern const std::string numericCharactersWithoutZero;
extern const std::string numericCharacters;
extern const std::string mixedAlphaCharacters;
extern const std::string lowerAlphanumericCharacters;
extern const std::string upperAlphanumericCharacters;
extern const std::string mixedAlphanumericCharacters;
extern const std::string hexUpperCharacters;
extern const std::string hexLowerCharacters;
extern const std::string symbolCharacters;
extern const std::unordered_set<char> lowerCharSet;
extern const std::unordered_set<char> upperCharSet;
extern const std::unordered_set<char> mixedAlphaCharSet;
extern const std::unordered_set<char> hexUpperCharSet;
extern const std::unordered_set<char> hexLowerCharSet;
extern const std::unordered_set<char> digitSet;
extern const std::unordered_set<char> utf16CharSet;
extern const std::unordered_map<StringCasing, std::unordered_set<char>>
    stringCasingToAlphaCharSetMapping;
}

#endif