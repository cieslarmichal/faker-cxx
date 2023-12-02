#pragma once
#include <string>
#include <vector>

namespace faker
{
namespace data
{
const std::vector<std::string> PhonePlatforms = {
    "Android OS", "iOS", "Windows Phone", "Symbian", "Palm OS", "Tizen",
};
const std::vector<std::string> PhoneModelNames = {
    "Samsung Galaxy S9", "iPhone X",   "Google Pixel 4", "Samsung Galaxy S22", "iPhone 13",
    "iPhone 13",         "iPhone 14",  "iPhone 15",      "Google Pixel 6",     "OnePlus 9",
    "Xiaomi Mi 11",      "Huawei P50", "Oppo Find X3",   "Sony Xperia 1 III",  "Motorola Edge 20"};
const std::vector<std::string> PhoneManufacturers = {"Samsung", "Apple", "Google", "OnePlus", "Xiaomi",
                                                     "Huawei",  "Oppo",  "Sony",   "Motorola"};
}
}
