#pragma once

#include <set>
#include <string>

namespace faker
{
static const std::string upperCharacters{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
static const std::string lowerCharacters{"abcdefghijklmnopqrstuvwxyz"};
static const std::string numericCharactersWithoutZero{"123456789"};
static const std::string numericCharacters{"0123456789"};
static const std::string mixedAlphaCharacters{upperCharacters + lowerCharacters};
static const std::string lowerAlphanumericCharacters{lowerCharacters + numericCharacters};
static const std::string upperAlphanumericCharacters{upperCharacters + numericCharacters};
static const std::string mixedAlphanumericCharacters{upperCharacters + lowerCharacters + numericCharacters};
static const std::string hexUpperCharacters{"0123456789ABCDEF"};
static const std::string hexLowerCharacters{"0123456789abcdef"};
static const std::string symbolCharacters{"~`!@#$%^&*()_-+={[}]|:;\"'<,>.?/"};

static const std::set<char> lowerCharSet{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
};

static const std::set<char> upperCharSet{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
};

static const std::set<char> mixedAlphaCharSet{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
};

static const std::set<char> hexUpperCharSet{
    'A', 'B', 'C', 'D', 'E', 'F', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

static const std::set<char> hexLowerCharSet{
    'a', 'b', 'c', 'd', 'e', 'f', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

static const std::set<char> digitSet{
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

static const std::set<char> utf16CharSet{
    '!', '"', '#',  '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6',  '7', '8', '9', ':',  ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I',  'J', 'K', 'L', 'M',  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
    'Z', '[', '\\', ']', '^', '_', '`',  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o',  'p', 'q', 'r', 's',  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
};
}
