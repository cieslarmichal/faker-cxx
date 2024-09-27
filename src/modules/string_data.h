#pragma once

#include <set>
#include <string>

namespace faker::string
{
const std::string upperCharacters{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
const std::string lowerCharacters{"abcdefghijklmnopqrstuvwxyz"};
const std::string numericCharactersWithoutZero{"123456789"};
const std::string numericCharacters{"0123456789"};
const std::string mixedAlphaCharacters{upperCharacters + lowerCharacters};
const std::string lowerAlphanumericCharacters{lowerCharacters + numericCharacters};
const std::string upperAlphanumericCharacters{upperCharacters + numericCharacters};
const std::string mixedAlphanumericCharacters{upperCharacters + lowerCharacters + numericCharacters};
const std::string symbolCharacters{"~`!@#$%^&*()_-+={[}]|:;\"'<,>.?/"};

const std::set<char> lowerCharSet{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
};

const std::set<char> upperCharSet{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
};

const std::set<char> mixedAlphaCharSet{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
};

const std::set<char> digitSet{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

const std::set<char> utf16CharSet{
    '!', '"', '#',  '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6',  '7', '8', '9', ':',  ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I',  'J', 'K', 'L', 'M',  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
    'Z', '[', '\\', ']', '^', '_', '`',  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o',  'p', 'q', 'r', 's',  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
};
}
