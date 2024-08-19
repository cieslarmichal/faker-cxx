#pragma once

#include <array>
#include <string_view>

namespace faker::commerce
{
const auto departments = std::to_array<std::string_view>({
    "Books", "Movies",   "Music",  "Games",    "Electronics", "Computers",  "Home", "Garden",
    "Tools", "Grocery",  "Health", "Beauty",   "Toys",        "Kids",       "Baby", "Clothing",
    "Shoes", "Jewelery", "Sports", "Outdoors", "Automotive",  "Industrial",
});

const auto productAdjectives = std::to_array<std::string_view>({
    "Small",       "Ergonomic", "Electronic", "Rustic",   "Intelligent", "Gorgeous", "Incredible", "Elegant",
    "Fantastic",   "Practical", "Modern",     "Recycled", "Sleek",       "Bespoke",  "Awesome",    "Generic",
    "Handcrafted", "Handmade",  "Oriental",   "Licensed", "Luxurious",   "Refined",  "Unbranded",  "Tasty",
});

const auto productMaterials = std::to_array<std::string_view>({
    "Steel",
    "Bronze",
    "Wooden",
    "Concrete",
    "Plastic",
    "Cotton",
    "Granite",
    "Rubber",
    "Metal",
    "Soft",
    "Fresh",
    "Frozen",
});

const auto productNames = std::to_array<std::string_view>({
    "Chair",   "Car",   "Computer", "Keyboard", "Mouse", "Bike",   "Ball",     "Gloves",
    "Pants",   "Shirt", "Table",    "Shoes",    "Hat",   "Towels", "Soap",     "Tuna",
    "Chicken", "Fish",  "Cheese",   "Bacon",    "Pizza", "Salad",  "Sausages", "Chips",
});

const auto paymentTypes = std::to_array<std::string_view>({
    "Credit Card",
    "Debit Card",
    "Cash",
    "Bank Transfer",
    "Check",
});

const auto paymentProviders = std::to_array<std::string_view>({
    "Stripe",
    "Paypal",
    "Square",
    "Helcim",
    "Merchant One",
    "Flagship Merchant Services",
    "Stax",
});

const auto productDescriptions = std::to_array<std::string_view>({
    "Experience convenience and efficiency with innovative solution.",
    "Elevate your lifestyle with premium quality product.",
    "Unlock endless possibilities with versatile tool, offering flexibility and adaptability,",
    "Enhance your performance with cutting-edge technology.",
    "Discover the perfect balance of style and functionality with sleek design.",
    "Embrace comfort and luxury with indulgent product.",
    "Achieve peace of mind with reliable solution, providing stability and assurance in every use.",
    "Ignite your creativity with versatile accessory.",
    "Experience the difference with high-performance product, engineered for superior quality.",
    "Simplify your life with user-friendly solution, designed with intuitive features .",
    "Upgrade your everyday routine with essential product, adding convenience and efficiency to "
    "your tasks.",
    "Stay connected and productive with innovative technology, keeping you in control and on top "
    "of your game.",
    "Make a statement with stylish addition, adding a touch of elegance and sophistication to any "
    "setting.",
    "Experience reliability like never before with dependable product, ensuring consistent "
    "performance day in and day out.",
    "Unleash your potential with versatile tool, empowering you to tackle any challenge and "
    "achieve your goals.",
    "Experience comfort redefined with ergonomic design, prioritizing your well-being and comfort "
    "in every use.",
    "Optimize your efficiency with streamlined solution, eliminating unnecessary steps and "
    "maximizing productivity.",
    "Experience durability and longevity with rugged construction, built to withstand the test of "
    "time and rigorous use.",
});

const auto productCategoryNames = std::to_array<std::string_view>({
    "Art and Craft",
    "Baby Products",
    "Beauty Products",
    "Board Games and Puzzles",
    "Books and Stationery",
    "Clothing, Shoes, and Jewelry",
    "Electronics",
    "Fitness Equipment",
    "Furniture and Furnishings",
    "Health and Wellness",
    "Home Decor",
    "Kitchen Appliances",
    "Musical Instruments",
    "Office Supplies",
    "Outdoor Gear",
    "Pet Supplies",
    "Photography Equipment",
    "Sporting Goods",
    "Tech Gadgets",
    "Toys",
});

const auto productReviews = std::to_array<std::string_view>({
    "This product exceeded my expectations.",
    "I'm thrilled with the quality of this purchase.",
    "This product is worth every penny.",
    "I'm impressed with how well it performs.",
    "I've been using it for a while now, and it hasn't disappointed.",
    "It's okay, but nothing special.",
    "I'm on the fence about this product.",
    "There are pros and cons to this purchase.",
    "It's neither good nor bad, just average.",
    "I have mixed feelings about this product.",
    "It's decent, but there's room for improvement.",
    "It meets my basic needs, but there are better options out there.",
    "I would consider it if you're on a budget.",
    "Not bad, but not great either.",
    "It's acceptable, but I expected more for the price.",
    "I was disappointed with the overall quality of this product.",
    "Unfortunately, it broke shortly after I started using it.",
    "I found it to be overpriced for what it offers.",
    "It feels cheaply made and lacks durability.",
    "It's difficult to operate and not user-friendly.",
});

const auto discountTypes = std::to_array<std::string_view>({
    "percentage",
    "value",
});

const auto shippingCarriers = std::to_array<std::string_view>({
    "UPS",
    "FedEx",
    "USPS",
    "DHL",
    "Canada Post",
    "Royal Mail",
    "Australia Post",
    "Correos",
    "Deutsche Post",
});

const auto orderStatuses = std::to_array<std::string_view>({
    "In Transit",
    "Out for Delivery",
    "Delivered",
    "Failed Attempt",
    "Exception",
    "Pending",
    "Expired",
});

}
