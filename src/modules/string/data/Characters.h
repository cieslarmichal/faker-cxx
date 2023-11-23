#pragma once

#include <string>

namespace faker
{
const std::string upperCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string lowerCharacters = "abcdefghijklmnopqrstuvwxyz";
const std::string numericCharactersWithoutZero = "123456789";
const std::string numericCharacters = "0123456789";
const std::string mixedAlphaCharacters = upperCharacters + lowerCharacters;
const std::string lowerAlphanumericCharacters = lowerCharacters + numericCharacters;
const std::string upperAlphanumericCharacters = upperCharacters + numericCharacters;
const std::string mixedAlphanumericCharacters = upperCharacters + lowerCharacters + numericCharacters;
const std::string hexUpperCharacters = "0123456789ABCDEF";
const std::string hexLowerCharacters = "0123456789abcdef";
const std::string symbolCharacters = "~`!@#$%^&*()_-+={[}]|:;\"'<,>.?/";
}
