#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> departments = {
    "Books", "Movies",   "Music",  "Games",    "Electronics", "Computers", "Home", "Garden",
    "Tools", "Grocery",  "Health", "Beauty",   "Toys",        "Kids",      "Baby", "Clothing",
    "Shoes", "Jewelery", "Sports", "Outdoors", "Automotive",  "Industrial"};

const std::vector<std::string> productAdjectives = {
    "Small",       "Ergonomic", "Electronic", "Rustic",   "Intelligent", "Gorgeous", "Incredible", "Elegant",
    "Fantastic",   "Practical", "Modern",     "Recycled", "Sleek",       "Bespoke",  "Awesome",    "Generic",
    "Handcrafted", "Handmade",  "Oriental",   "Licensed", "Luxurious",   "Refined",  "Unbranded",  "Tasty"};

const std::vector<std::string> productMaterials = {"Steel",   "Bronze", "Wooden", "Concrete", "Plastic", "Cotton",
                                                   "Granite", "Rubber", "Metal",  "Soft",     "Fresh",   "Frozen"};

const std::vector<std::string> productNames = {"Chair",  "Car",    "Computer", "Keyboard", "Mouse",    "Bike",
                                               "Ball",   "Gloves", "Pants",    "Shirt",    "Table",    "Shoes",
                                               "Hat",    "Towels", "Soap",     "Tuna",     "Chicken",  "Fish",
                                               "Cheese", "Bacon",  "Pizza",    "Salad",    "Sausages", "Chips"};

const std::vector<std::string> paymentTypes = {"Credit Card", "Debit Card", "Cash", "Bank Transfer", "Check"};

const std::vector<std::string> paymentProviders = {"Stripe", "Paypal", "Square", "Helcim", "Merchant One", 
                                                  "Flagship Merchant Services", "Stax"};
}
