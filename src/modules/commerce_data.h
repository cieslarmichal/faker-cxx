#pragma once

#include <array>
#include <string_view>

namespace faker::commerce
{
const auto departments = std::to_array<std::string_view>({
    "Books", "Movies",   "Music",  "Games",    "Electronics", "Computers",  "Home", "Garden",
    "Tools", "Grocery",  "Health", "Beauty",   "Toys",        "Kids",       "Baby", "Clothing",
    "Shoes", "Jewelery", "Sports", "Outdoors", "Automotive",  "Industrial", "Pet Supplies",
    "Office Supplies", "Luggage", "Art", "Crafts", "Stationery", "Watches", 
    "Musical Instruments", "Video Games", "Cell Phones", "Smart Home", "Appliances", 
    "Furniture", "Cleaning Supplies", "Party Supplies", "Seasonal", "Hardware", 
    "Lighting", "Security", "Fitness", "Accessories", "Storage & Organization",
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
    "Aluminum", "Glass", "Leather", "Wool", "Silk", "Ceramic", "Linen", "Iron", "Stone", 
    "PVC", "Copper", "Fabric", "Tungsten", "Brass", "Bamboo", "Carbon Fiber", "Silicone", 
    "Marble", "Fiberglass", "Nylon", "Jute", "PVC", "Polyester", "Acrylic", "Vinyl",

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
    "PayPal", "Apple Pay", "Google Pay", "Amazon Pay", "Cryptocurrency", "Gift Card", 
    "Cash on Delivery", "Wire Transfer", "Mobile Payment", "Venmo", "Stripe", "Alipay", 
    "WeChat Pay", "Direct Debit", "Samsung Pay", "Bank Draft",

});

const auto paymentProviders = std::to_array<std::string_view>({
    "Stripe",
    "Paypal",
    "Square",
    "Helcim",
    "Merchant One",
    "Flagship Merchant Services",
    "Stax",
    "Adyen", "Braintree", "Authorize.Net", "Worldpay", "Payoneer", "2Checkout", "Klarna", 
    "Zelle", "Razorpay", "PayU", "Mollie", "BlueSnap", "WePay", "GoCardless", "Payza",
    "Paytm", "Checkout.com", "AliPay", "Skrill", "Dwolla",
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
    "Step into the future with advanced technology that redefines convenience.",
    "Discover elegance with a product that exudes sophistication and charm.",
    "Achieve precision and accuracy with cutting-edge engineering and design.",
    "Indulge in premium craftsmanship for an unparalleled experience.",
    "Experience superior comfort with ergonomically designed product for optimal support.",
    "Boost your productivity with high-efficiency tool, designed to save time and effort.",
    "Unlock your potential with innovative solutions that adapt to your needs.",
    "Elevate your game with a product that delivers peak performance, every time.",
    "Stay ahead of the curve with state-of-the-art technology, designed for maximum efficiency.",
    "Transform your daily routine with solutions that bring convenience to your fingertips.",
    "Experience the pinnacle of durability with a product built for resilience.",
    "Maximize comfort and performance with an intelligently designed solution.",
    "Seamlessly integrate this stylish product into your space for a modern touch.",
    "Unleash creativity with tools that encourage imaginative thinking and execution.",
    "Turn ordinary tasks into extraordinary achievements with high-performance products.",
    "Invest in the future with eco-friendly products that prioritize sustainability.",
    "Live smarter with innovative products that simplify every aspect of your day.",
    "Enjoy effortless functionality and elegant design with every use."
    
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
    "Accessories",
    "Automotive Parts",
    "Camping and Hiking",
    "Cleaning Supplies",
    "DIY Tools",
    "Gardening Equipment",
    "Health Devices",
    "Home Improvement",
    "Kids' Clothing",
    "Luxury Goods",
    "Mobile Accessories",
    "Outdoor Furniture",
    "Party Supplies",
    "Personal Care",
    "Portable Electronics",
    "Smart Home Devices",
    "Sports and Outdoors",
    "Travel Gear",
    "Vintage Collectibles",
    "Wearable Technology",
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
    "This product exceeded my expectations! The quality is fantastic, and it's incredibly easy to use.",
    "I'm absolutely in love with this product! It works exactly as described and is of great value for money.",
    "Highly recommended! It delivers top-notch performance, and the build quality is amazing.",
    "A game-changer! It has made my daily routine so much easier. Definitely worth the investment.",
    "I'm really happy with this purchase. It's durable, practical, and stylish. Would buy again!",
    "Good quality for the price. It doesn't perform as well as higher-end models, but it's still solid.",
    "Not bad at all. It does what it's supposed to, but I expected a bit more from the description.",
    "Excellent! The customer service was fantastic, and the product works like a charm.",
    "I was skeptical at first, but this product really delivers. It's a fantastic value for the money.",
    "Decent product, but not as durable as I expected. It works fine for now, but I hope it lasts longer.",
    "Great product, I use it every day! The design is sleek, and it's very functional.",
    "This item does its job, but I had a few issues with setup. After getting the hang of it, it's been great.",
    "I absolutely recommend this. I've had it for a few months now, and it's been reliable the whole time.",
    "I wasn't impressed initially, but the product grew on me after some use. It's a good option for those on a budget.",
    "A little overpriced for what it offers, but the quality is decent. I might consider purchasing again if it were on sale.",
    "It's okay for basic tasks, but it doesn't stand out compared to similar products in the market.",
    "Fantastic! Everything about this product works perfectly and it's an essential addition to my collection.",
    "I'm very impressed with how quickly it arrived and how well it performs. Definitely a solid purchase.",
    "The product is alright, but the instructions weren't clear. After figuring it out, I'm satisfied with the results.",
    "Very convenient and easy to use. It saved me time and effort, which is exactly what I needed!",
    "Definitely worth the price. Excellent quality and great performance so far. Would recommend to anyone!"

});

const auto discountTypes = std::to_array<std::string_view>({
    "percentage",
    "value",
});

const auto shippingCarriers = std::to_array<std::string_view>({
    "FedEx",
    "UPS",
    "DHL",
    "USPS",
    "Canada Post",
    "Royal Mail",
    "Australia Post",
    "Japan Post",
    "China Post",
    "India Post",
    "Singapore Post",
    "La Poste",
    "PostNL",
    "Correios (Brazil)",
    "Hermes",
    "Yodel",
    "Sagawa Express",
    "Aramex",
    "TNT",
    "ZTO Express",
    "SEUR",
    "DPD",
    "Schenker",
    "GLS",
    "Hong Kong Post",
    "An Post (Ireland)",
    "New Zealand Post",
    "Omni Logistics",
    "Kuehne + Nagel",
    "Purolator",
    "OnTrac",
    "Jetpak",
    "Loomis",
    "Estafeta",
    "DTDC",
    "Fastway Couriers",
    "Poste Italiane",
    "Poczta Polska",
    "Cekaf",
    "Nippon Express",
    "Kerry Logistics",
    "Asendia",
    "Chitron Logistics",
    "Spring GDS",

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
