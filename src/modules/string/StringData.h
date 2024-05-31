#pragma once

#include <set>
#include <string>

namespace faker::string {

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

extern const std::set<char> lowerCharSet;
extern const std::set<char> upperCharSet;
extern const std::set<char> mixedAlphaCharSet;
extern const std::set<char> hexUpperCharSet;
extern const std::set<char> hexLowerCharSet;
extern const std::set<char> digitSet;
extern const std::set<char> utf16CharSet;
}
