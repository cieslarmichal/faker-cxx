#pragma once

#include <set>
#include <string>

namespace faker::number
{
const std::string hexUpperCharacters{"0123456789ABCDEF"};
const std::string hexLowerCharacters{"0123456789abcdef"};
const std::set<char> hexUpperCharSet{'A', 'B', 'C', 'D', 'E', 'F', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const std::set<char> hexLowerCharSet{'a', 'b', 'c', 'd', 'e', 'f', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
}
