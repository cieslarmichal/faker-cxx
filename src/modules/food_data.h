#pragma once

#include <array>
#include <span>
#include <string_view>

namespace faker::food
{
struct FoodDefinition
{
    std::span<const std::string_view> alcoholicBeverages;
    std::span<const std::string_view> dishNames;
    std::span<const std::string_view> foodCategories;
    std::span<const std::string_view> fruits;
    std::span<const std::string_view> grains;
    std::span<const std::string_view> meats;
    std::span<const std::string_view> milkProducts;
    std::span<const std::string_view> nonalcoholicBeverages;
    std::span<const std::string_view> nuts;
    std::span<const std::string_view> oils;
    std::span<const std::string_view> seafoods;
    std::span<const std::string_view> seeds;
    std::span<const std::string_view> sugarProducts;
    std::span<const std::string_view> vegetables;
};

const auto enUSalcoholicBeverages = std::to_array<std::string_view>({
    "Absinthe",
    "Baileys Irish Cream",
    "Beer",
    "Bellini",
    "Black Russian",
    "Bloody Mary",
    "Bourbon",
    "Brandy",
    "Caipirinha",
    "Champagne",
    "Cider",
    "Cognac",
    "Cosmopolitan",
    "Gin",
    "Grappa",
    "Irish Cream",
    "Jägermeister",
    "Kahlúa",
    "Mai Tai",
    "Manhattan",
    "Margarita",
    "Martini",
    "Mead",
    "Midori",
    "Mimosa",
    "Mojito",
    "Moscow Mule",
    "Negroni",
    "Old Fashioned",
    "Paloma",
    "Pina Colada",
    "Pisco",
    "Piña Colada",
    "Port Wine",
    "Rum",
    "Sake",
    "Sambuca",
    "Schnapps",
    "Scotch",
    "Sherry",
    "Singapore Sling",
    "Tequila",
    "Tom Collins",
    "Vodka",
    "Whiskey",
    "White Russian",
    "Wine",
});

const auto enUSdishNames = std::to_array<std::string_view>({
    "Arepas",
    "Arroz con Pollo",
    "Baba Ganoush",
    "Baked Ziti",
    "Baklava",
    "Baklava",
    "Beef Bulgogi",
    "Beef Chimichanga",
    "Beef and Broccoli",
    "Beef and Mushroom Pie",
    "Biryani",
    "Borscht",
    "Butter Chicken",
    "Bánh Mì",
    "Cajun Shrimp Pasta",
    "Caponata",
    "Caprese Stuffed Avocado",
    "Cauliflower Fried Rice",
    "Causa Rellena",
    "Ceviche",
    "Chicken Alfredo Pizza",
    "Chicken Caesar Salad",
    "Chicken Enchiladas",
    "Chicken Fajitas",
    "Chicken Katsu",
    "Chicken Piccata",
    "Chicken Quesadilla",
    "Chicken Teriyaki",
    "Chicken Tikka Masala",
    "Chimichurri",
    "Dim Sum",
    "Dolma",
    "Egg Fried Rice",
    "Eggplant Rollatini",
    "Feijoada",
    "Garlic Herb Roasted Potatoes",
    "Garlic Parmesan Roasted Brussels Sprouts",
    "Goulash",
    "Haggis",
    "Honey Garlic Glazed Salmon",
    "Jollof Rice",
    "Katsudon",
    "Kebab",
    "Kimchi",
    "Laksa",
    "Lemon Butter Shrimp",
    "Lemon Herb Grilled Fish",
    "Lemon Herb Roast Chicken",
    "Lobster Roll",
    "Lobster Thermidor",
    "Mango Salsa Chicken",
    "Mongolian Beef",
    "Moussaka",
    "Nasi Goreng",
    "Pad Krapow Moo Saap",
    "Paella",
    "Pav Bhaji",
    "Pavlova",
    "Penne alla Vodka",
    "Perogies",
    "Pho",
    "Pho",
    "Pierogi",
    "Pierogi",
    "Poutine",
    "Pulled Pork Sandwich",
    "Ramen",
    "Rendang",
    "Samosa",
    "Sausage and Mushroom Risotto",
    "Shrimp Fried Rice",
    "Shrimp Scampi Pasta",
    "Spinach and Feta Stuffed Chicken Breast",
    "Stuffed Bell Peppers",
    "Sushi",
    "Tacos",
    "Tagine",
    "Tandoori Chicken",
    "Tandoori Chicken",
    "Teriyaki Salmon",
    "Tom Kha Gai",
    "Tom Yum Soup",
    "Tomato Basil Mozzarella Skewers",
    "Vegetable Curry",
    "Vegetarian Paella",
});

const auto enUSfoodCategories = std::to_array<std::string_view>({
    "Beverages",
    "Condiments",
    "Dairy",
    "Desserts",
    "Frozen Foods",
    "Fruits",
    "Grains",
    "Meat",
    "Seafood",
    "Snacks",
    "Vegetables",
});

const auto enUSfruits = std::to_array<std::string_view>({
    "Apple",      "Apricot",     "Avocado",       "Banana",    "Blackberry",   "Blueberry",  "Cantaloupe",
    "Cherry",     "Coconut",     "Cranberry",     "Date",      "Dragon Fruit", "Elderberry", "Fig",
    "Gooseberry", "Grapefruit",  "Grapes",        "Guava",     "Honeydew",     "Jackfruit",  "Kiwi",
    "Kumquat",    "Lemon",       "Lime",          "Lychee",    "Mango",        "Mulberry",   "Nectarine",
    "Orange",     "Papaya",      "Passion Fruit", "Peach",     "Pear",         "Persimmon",  "Pineapple",
    "Plum",       "Pomegranate", "Rambutan",      "Raspberry", "Starfruit",    "Strawberry",
});

const auto enUSgrains = std::to_array<std::string_view>({
    "Amaranth", "Barley", "Buckwheat", "Bulgur",          "Chia Seeds",  "Corn",      "Einkorn",
    "Emmer",    "Farro",  "Flaxseeds", "Freekeh",         "Job's Tears", "Kamut",     "Lentils",
    "Maize",    "Millet", "Oats",      "Quinoa",          "Rice",        "Rye",       "Semolina",
    "Sorghum",  "Soy",    "Spelt",     "Sunflower Seeds", "Teff",        "Triticale", "Wheat",
});

const auto enUSmeats = std::to_array<std::string_view>({
    "Beef", "Bison", "Chicken", "Crab",    "Duck",   "Fish",  "Goose", "Haddock", "Ham",  "Lamb",    "Lobster",
    "Pork", "Quail", "Salmon",  "Sausage", "Shrimp", "Trout", "Tuna",  "Turkey",  "Veal", "Venison",
});

const auto enUSmilkProducts = std::to_array<std::string_view>({
    "Blue Cheese",    "Brie",           "Butter",        "Camembert",    "Cheddar",         "Cheese",     "Colby",
    "Condensed Milk", "Cottage Cheese", "Cream",         "Cream Cheese", "Evaporated Milk", "Feta",       "Goat Cheese",
    "Gouda",          "Gruyère",        "Havarti",       "Havarti",      "Ice Cream",       "Mascarpone", "Milk",
    "Monterey Jack",  "Mozzarella",     "Neufchâtel",    "Parmesan",     "Provolone",       "Quark",      "Ricotta",
    "Sour Cream",     "Swiss Cheese",   "Whipped Cream", "Yogurt",
});

const auto enUSnonalcoholicBeverages = std::to_array<std::string_view>({
    "Almond Milk",
    "Apple Juice",
    "Chai Tea",
    "Club Soda",
    "Coconut Water",
    "Coffee",
    "Cranberry Juice",
    "Fruit Punch",
    "Ginger Ale",
    "Grape Juice",
    "Grapefruit Juice",
    "Green Smoothie",
    "Hibiscus Tea",
    "Hot Chocolate",
    "Iced Tea",
    "Lemonade",
    "Limeade",
    "Mango Lassi",
    "Milk",
    "Orange Juice",
    "Peach Iced Tea",
    "Pear Nectar",
    "Pineapple Juice",
    "Pomegranate Juice",
    "Raspberry Lemonade",
    "Root Beer",
    "Soy Milk",
    "Tea",
    "Tomato Juice",
    "Vegetable Juice",
    "Water",
});

const auto enUSnuts = std::to_array<std::string_view>({
    "Almond",
    "Brazil Nut",
    "Cashew",
    "Chestnut",
    "Hazelnut",
    "Macadamia",
    "Peanut",
    "Pecan",
    "Pine Nut",
    "Pistachio",
    "Walnut",
});

const auto enUSoils = std::to_array<std::string_view>({
    "Almond Oil",       "Avocado Oil",   "Canola Oil", "Chia Seed Oil", "Coconut Oil",   "Corn Oil",   "Flaxseed Oil",
    "Grapeseed Oil",    "Hazelnut Oil",  "Hemp Oil",   "Mustard Oil",   "Olive Oil",     "Palm Oil",   "Peanut Oil",
    "Pumpkin Seed Oil", "Safflower Oil", "Sesame Oil", "Sunflower Oil", "Vegetable Oil", "Walnut Oil",
});

const auto enUSseafoods = std::to_array<std::string_view>({
    "Anchovies", "Catfish", "Caviar",  "Clams",   "Cod",       "Crab",   "Haddock",  "Halibut",   "Herring",  "Lobster",
    "Mahi-Mahi", "Mussels", "Octopus", "Oysters", "Pollock",   "Salmon", "Sardines", "Scallops",  "Sea Bass", "Shrimp",
    "Snapper",   "Sole",    "Squid",   "Surimi",  "Swordfish", "Trout",  "Tuna",     "Whitefish",
});

const auto enUSseeds = std::to_array<std::string_view>({
    "Ajwain Seeds", "Alfalfa Seeds",     "Anise Seeds",     "Caraway Seeds",     "Cardamom Seeds",
    "Celery Seeds", "Chia Seeds",        "Coriander Seeds", "Cotton Seeds",      "Cumin Seeds",
    "Dill Seeds",   "Fennel Seeds",      "Fenugreek Seeds", "Flaxseeds",         "Hemp Hearts",
    "Hemp Seeds",   "Mustard Seeds",     "Nigella Seeds",   "Pine Nuts",         "Pomegranate Seeds",
    "Poppy Seeds",  "Pumpkin Seeds",     "Quinoa",          "Sacha Inchi Seeds", "Safflower Seeds",
    "Sesame Seeds", "Sunflower Kernels", "Sunflower Seeds", "Watermelon Seeds",
});

const auto enUSsugarProducts = std::to_array<std::string_view>({
    "Agave Nectar",
    "Barley Malt Syrup",
    "Blackstrap Molasses",
    "Brown Sugar",
    "Cakes",
    "Candies",
    "Chocolates",
    "Coconut Sugar",
    "Cookies",
    "Corn Syrup",
    "Date Syrup",
    "Demerara Sugar",
    "Golden Syrup",
    "Granulated Sugar",
    "Ice Cream",
    "Lollipop",
    "Maple Syrup",
    "Molasses",
    "Muscovado Sugar",
    "Palm Sugar",
    "Powdered Sugar",
    "Rice Syrup",
    "Soda",
    "Turbinado Sugar",
});

const auto enUSvegetables = std::to_array<std::string_view>({
    "Artichoke", "Asparagus", "Beets",        "Bell Pepper", "Broccoli", "Brussels Sprouts",
    "Cabbage",   "Carrot",    "Cauliflower",  "Celery",      "Cucumber", "Eggplant",
    "Garlic",    "Ginger",    "Green Beans",  "Kale",        "Leek",     "Lettuce",
    "Mushroom",  "Onion",     "Peas",         "Potato",      "Radish",   "Rutabaga",
    "Scallion",  "Spinach",   "Sweet Potato", "Tomato",      "Turnip",   "Zucchini",
});

const FoodDefinition enUSFoodDefinition = {
    .alcoholicBeverages = enUSalcoholicBeverages,
    .dishNames = enUSdishNames,
    .foodCategories = enUSfoodCategories,
    .fruits = enUSfruits,
    .grains = enUSgrains,
    .meats = enUSmeats,
    .milkProducts = enUSmilkProducts,
    .nonalcoholicBeverages = enUSnonalcoholicBeverages,
    .nuts = enUSnuts,
    .oils = enUSoils,
    .seafoods = enUSseafoods,
    .seeds = enUSseeds,
    .sugarProducts = enUSsugarProducts,
    .vegetables = enUSvegetables,
};

}
