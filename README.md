<div align="center">
  <img src="https://raw.githubusercontent.com/cieslarmichal/faker-cxx/main/docs/public/logo.png" width="250" alt="C++ Faker, a powerful tool for generating realistic and randomized fake data in C++ programming, enhancing data testing and development workflows"/>
  <h1>Faker C++</h1>

[![clang++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml?query=branch%3Amain)
[![apple clang++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/macos-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/macos-clang-build.yml?query=branch%3Amain)
[![g++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml?query=branch%3Amain)
[![msvc](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml?query=branch%3Amain)
[![bazel](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-bazel-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-bazel-build.yml?query=branch%3Amain)
[![codecov](https://codecov.io/github/cieslarmichal/faker-cxx/branch/main/graph/badge.svg?token=0RTV4JFH2U)](https://codecov.io/github/cieslarmichal/faker-cxx)
[![Conan Center](https://img.shields.io/conan/v/faker-cxx)](https://conan.io/center/recipes/faker-cxx)
[![vcpkg](https://img.shields.io/vcpkg/v/faker-cxx)](https://vcpkg.link/ports/faker-cxx)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Chat on Discord](https://img.shields.io/badge/chat-discord-blue?style=flat&logo=discord)](https://discord.gg/h2ur8H6mK6)
</div>

## Table of Contents

- [Introduction](#introduction)
- [⚡ Quick Start](#-quick-start)
- [Key Features](#key-features)
- [📖 Usage and Documentation](#-usage-and-documentation)
- [🎯 Common Use Cases](#-common-use-cases)
- [💎 Modules](#-modules)
- [📚 API Reference](#-api-reference)
- [🌍 Supported Locales](#-supported-locales)
- [Consuming the library with CMake](#consuming-the-library-with-cmake)
- [Installing the library with vcpkg](#installing-the-library-with-vcpkg)
- [⚒️ Compiler support](#️-compiler-support)
- [Dependencies](#dependencies)
- [📦 Building the library with Conan](#-building-the-library-with-conan)
- [Installing the library with Conan](#installing-the-library-with-conan)
- [Building the library with Bazel](#building-the-library-with-bazel)
- [✨ Contributing](#-contributing)
- [📘 Credits](#-credits)
- [📝 Changelog](#-changelog)
- [🔑 License](#-license)

## Introduction

Faker C++ is a C++ library inspired by the popular [Faker.js](https://github.com/faker-js/faker),
aimed at providing developers with a robust tool for generating fake (but realistic) data.
Whether you're building test suites, populating databases, or creating demos, Faker C++ has got you covered.

## ⚡ Quick Start

Want to get started immediately? Check out our [**Quick Start Guide**](QUICK_START.md) for a 5-minute introduction!

```cpp
#include <iostream>
#include "faker-cxx/faker.h"

int main() {
    std::cout << faker::person::fullName() << std::endl;      // "Jennifer Martin"
    std::cout << faker::internet::email() << std::endl;        // "martin.jennifer@gmail.com"
    std::cout << faker::location::city() << std::endl;         // "Los Angeles"
    std::cout << faker::string::uuidV4() << std::endl;         // "8e3a4f21-5c7b-4d9a-8f2e-1b9c7d6a5e3f"
    return 0;
}
```

**👉 [Read the Quick Start Guide](QUICK_START.md)** for installation and more examples!

## Key Features

📚 Realistic Data Generation: Generate various types of data including names, addresses, emails, dates, and more.

🛠 Modular Design: Choose from a wide range of modules like Internet, Location, String, Date, and more to generate
specific types of data.

🚀 Easy Integration: Seamlessly integrate with CMake, and it supports major compilers like MSVC, GCC, Clang, and Apple
Clang.

## 📖 Usage and Documentation

To properly use Faker C++ you must first consume the Faker library (see Consuming Library with CMake).
Once that is done, you need to include the proper [header](https://cieslarmichal.github.io/faker-cxx/files.html) file
depending on the module you wish to generate data from or use general include file `faker-cxx/faker.h`.
All the documentation can be found at [cieslarmichal.github.io/faker-cxx](https://cieslarmichal.github.io/faker-cxx/).

Below is an example of how to use Faker C++ in your code.

```cpp
#include <iostream>

#include "faker-cxx/faker.h" // or include specific module

int main()
{
    const auto id = faker::string::uuidV4();
    const auto email = faker::internet::email();
    const auto password = faker::internet::password();
    const auto city = faker::location::city();
    const auto streetAddress = faker::location::streetAddress();
    const auto bornDate = faker::date::birthdateByYear(1970, 2000);

    std::cout << id << std::endl; // 59990db5-3a5f-40bf-8af0-7834c29ee884
    std::cout << email << std::endl; // hills.rita@gmail.com
    std::cout << password << std::endl; // Mf+*[(_'lHfM.$v{
    std::cout << city << std::endl; // Rochester
    std::cout << streetAddress << std::endl; // 643 Ricardo Creek
    std::cout << bornDate << std::endl; // 1973-12-03T11:07:02Z

    return 0;
}
```

## 🎯 Common Use Cases

### Generate Test Data for Databases

```cpp
#include "faker-cxx/faker.h"

struct User {
    std::string id = faker::string::uuidV4();
    std::string name = faker::person::fullName();
    std::string email = faker::internet::email();
    std::string address = faker::location::streetAddress();
    std::string city = faker::location::city();
    std::string zipCode = faker::location::zipCode();
    std::string phone = faker::phone::number();
    std::string birthdate = faker::date::birthdateByYear(1970, 2005);
};
```

### Mock API Responses

```cpp
struct Product {
    std::string id = faker::string::uuidV4();
    std::string name = faker::commerce::productFullName();
    std::string price = faker::finance::amount(10, 1000, faker::Precision::TwoDp, "$");
    std::string sku = faker::commerce::sku();
    std::string category = faker::commerce::productCategory();
};
```

### Generate Lorem Ipsum Content

```cpp
std::string blogTitle = faker::lorem::words(5);             // Blog post title
std::string author = faker::person::fullName();             // Author name  
std::string content = faker::lorem::paragraphs(3);          // Article content
std::string summary = faker::lorem::sentence();             // Brief summary
```

### Create Unique Identifiers

```cpp
auto uuid = faker::string::uuidV4();          // "8e3a4f21-5c7b-4d9a-8f2e-1b9c7d6a5e3f"
auto ulid = faker::string::ulid();            // "01ARZ3NDEKTSV4RRFFQ69G5FAV"
auto nanoid = faker::string::nanoId();        // "V1StGXR8_Z5jdHi6B-myT"
```

### Generate Financial Data

```cpp
std::string iban = faker::finance::iban();                  // "DE89370400440532013000"
std::string creditCard = faker::finance::creditCardNumber(); // "4532-1488-0343-6467"
std::string amount = faker::finance::amount(100, 10000, faker::Precision::TwoDp, "€");
```

### Localized Data Generation

```cpp
// Generate Polish names
auto plName = faker::person::firstName(faker::Locale::pl_PL);  // "Krystyna"

// Generate French addresses
auto frCity = faker::location::city(faker::Locale::fr_FR);     // "Lyon"

// Generate German IBAN
auto deIban = faker::finance::iban(faker::Locale::de_DE);      // "DE89370400440532013000"
```

## 💎 Modules

- 🛩 Airline - aircraft, airlines, airports, flight numbers
- 🐼 Animal - species by type (bear, bird, cat, dog, etc.)
- 📖 Book - title, genre, author, publisher
- 🎨 Color - name, rgb, hex, hsl, lch, cmyk
- 🛒 Commerce - products, prices, SKU, EAN, ISBN
- 🏢 Company - name, type, industry, buzzwords
- 🖥️ Computer - type, manufacturer, CPU, GPU
- 🔐 Crypto - SHA, MD5 hashes
- 💾 Database - column names, types, engines
- ℹ️ Datatype - booleans
- 📅 Date - past/future dates, birthdays, weekdays
- 🕹️ E-sport - players, teams, leagues
- 🎓 Education - schools, degrees, fields of study
- 🏦 Finance - currency, IBAN, BIC, credit cards
- 🍝 Food - dishes, ingredients, beverages
- 📁 Git - branch, commit, SHA
- 👨‍💻 Hacker - abbreviations, phrases
- 🖼️ Image - URLs, dimensions, types
- 🌐 Internet - email, username, password, IP, URL
- 🌍 Location - country, city, address, coordinates, MGRS grid
- 📚 Lorem - words, sentences, paragraphs
- 🏥 Medicine - conditions, tests, specialties
- 🎥 Movie - titles, genres, actors, directors
- 🎶 Music - artists, songs, genres
- 🔢 Number - integers, decimals, hex, binary
- 🧑 Person - names, titles, bio, SSN
- 📞 Phone - numbers, IMEI
- 🪴 Plant - trees, flowers
- 🧑‍🔬 Science - chemical elements, units
- ⚽ Sport - sports, teams, athletes
- 🔢 String - UUID, ULID, Nano ID, alphanumeric
- 💻 System - file names, paths, MIME types
- 🚗 Vehicle - manufacturer, model, VIN
- 🎞️ Video - formats, codecs, resolutions
- 🎮 Video game - titles, genres, platforms
- 🌤️ Weather - descriptions
- 💬 Word - adjectives, nouns, verbs

## 📚 API Reference

Use **Ctrl+F** (Cmd+F on Mac) to search for specific functions!

> 💡 For detailed docs with parameters and options, see [cieslarmichal.github.io/faker-cxx](https://cieslarmichal.github.io/faker-cxx/)

### 🛩️ Airline Module

```cpp
faker::airline::aircraftType()           // "narrowbody"
faker::airline::airplane()               // {name: "Boeing 737", iataTypeCode: "737"}
faker::airline::airline()                // {name: "American Airlines", iataCode: "AA"}
faker::airline::airport()                // {name: "Los Angeles International Airport", iataCode: "LAX"}
faker::airline::seat(aircraftType)       // "1A"
faker::airline::recordLocator()          // "ABCDEF"
faker::airline::flightNumber()           // "1234"
```

### 🐼 Animal Module

```cpp
faker::animal::bear()                    // "Grizzly bear"
faker::animal::bird()                    // "Eagle"
faker::animal::cat()                     // "Siamese"
faker::animal::cetacean()                // "Dolphin"
faker::animal::cow()                     // "Holstein"
faker::animal::crocodile()               // "Nile crocodile"
faker::animal::dog()                     // "Golden Retriever"
faker::animal::fish()                    // "Salmon"
faker::animal::horse()                   // "Arabian"
faker::animal::insect()                  // "Butterfly"
faker::animal::lion()                    // "African Lion"
faker::animal::rabbit()                  // "Angora"
faker::animal::rodent()                  // "Hamster"
faker::animal::snake()                   // "Python"
faker::animal::type()                    // "mammal"
```

### 📖 Book Module

```cpp
faker::book::title()                     // "The Great Gatsby"
faker::book::genre()                     // "Science Fiction"
faker::book::author()                    // "George Orwell"
faker::book::publisher()                 // "Penguin Books"
faker::book::format()                    // "Hardcover"
faker::book::series()                    // "Harry Potter"
```

### 🎨 Color Module

```cpp
faker::color::name()                     // "Red"
faker::color::rgb()                      // "rgb(255, 0, 0)"
faker::color::hex()                      // "#FF0000"
faker::color::hsl()                      // "hsl(0, 100%, 50%)"
faker::color::lch()                      // "lch(53.24, 104.55, 40)"
faker::color::cmyk()                     // "cmyk(0, 100, 100, 0)"
faker::color::lab()                      // "lab(53.24, 80.09, 67.20)"
faker::color::hsb()                      // "hsb(0, 100%, 100%)"
faker::color::hsv()                      // "hsv(0, 100%, 100%)"
faker::color::hwb()                      // "hwb(0, 0%, 0%)"
faker::color::yuv()                      // "yuv(127, 0, 0)"
faker::color::space()                    // "sRGB"
```

### 🛒 Commerce Module

```cpp
faker::commerce::department()            // "Electronics"
faker::commerce::sku()                   // "ABC-12345"
faker::commerce::productAdjective()      // "Awesome"
faker::commerce::productMaterial()       // "Cotton"
faker::commerce::productName()           // "Shirt"
faker::commerce::productFullName()       // "Awesome Cotton Shirt"
faker::commerce::EAN13()                 // "1234567890123"
faker::commerce::EAN8()                  // "12345678"
faker::commerce::ISBN13()                // "978-1-234-56789-0"
faker::commerce::ISBN10()                // "1-234-56789-0"
faker::commerce::paymentType()           // "Credit Card"
faker::commerce::paymentProvider()       // "Visa"
faker::commerce::productDescription()    // "Ergonomic and stylish!"
faker::commerce::productCategory()       // "Clothing"
faker::commerce::productReview()         // "Great product!"
faker::commerce::discountType()          // "Percentage"
faker::commerce::orderStatus()           // "Shipped"
faker::commerce::shippingCarrier()       // "FedEx"
```

### 🏢 Company Module

```cpp
faker::company::companyName()            // "Peterson Inc"
faker::company::type()                   // "LLC"
faker::company::industry()               // "Technology"
faker::company::buzzPhrase()             // "innovate cutting-edge systems"
faker::company::buzzAdjective()          // "innovative"
faker::company::buzzNoun()               // "synergy"
faker::company::buzzVerb()               // "implement"
faker::company::catchPhrase()            // "Quality-focused scalable initiative"
faker::company::catchPhraseAdjective()   // "Quality-focused"
faker::company::catchPhraseDescriptor()  // "scalable"
faker::company::catchPhraseNoun()        // "initiative"
```

### 🖥️ Computer Module

```cpp
faker::computer::type()                  // "laptop"
faker::computer::manufacture()           // "Dell"
faker::computer::model()                 // "XPS 15"
faker::computer::cpuManufacture()        // "Intel"
faker::computer::cpuType()               // "x64"
faker::computer::cpuModel()              // "Core i7-9700K"
faker::computer::gpuManufacture()        // "NVIDIA"
faker::computer::gpuType()               // "Integrated"
faker::computer::gpuModel()              // "GeForce GTX 1080"
```

### 🔐 Crypto Module

```cpp
faker::crypto::sha256()                  // "a3c4f...(64 chars)"
faker::crypto::sha1()                    // "4e9d8...(40 chars)"
faker::crypto::md5()                     // "9b3e4...(32 chars)"
```

### 💾 Database Module

```cpp
faker::database::columnName()            // "id"
faker::database::columnType()            // "INT"
faker::database::collation()             // "utf8_unicode_ci"
faker::database::engine()                // "InnoDB"
faker::database::mongoDbObjectId()       // "507f1f77bcf86cd799439011"
```

### ℹ️ Datatype Module

```cpp
faker::datatype::boolean()               // true or false
faker::datatype::boolean(0.7)            // 70% chance of true
```

### 📅 Date Module

```cpp
faker::date::anytime()                   // "2023-07-15T14:30:00Z"
faker::date::pastDate()                  // "2022-03-12T08:15:00Z"
faker::date::futureDate()                // "2024-11-20T19:45:00Z"
faker::date::recentDate()                // "2023-07-13T10:20:00Z"
faker::date::soonDate()                  // "2023-07-17T16:00:00Z"
faker::date::birthdateByAge(18, 65)      // "1988-05-23T00:00:00Z"
faker::date::birthdateByYear(1990, 2000) // "1995-08-15T00:00:00Z"
faker::date::weekdayName()               // "Monday"
faker::date::weekdayAbbreviatedName()    // "Mon"
faker::date::monthName()                 // "January"
faker::date::monthAbbreviatedName()      // "Jan"
faker::date::timezoneRandom()            // "America/New_York"
```

### 🎓 Education Module

```cpp
faker::education::school()               // "Harvard University"
faker::education::degree()               // "Bachelor of Science"
faker::education::field()                // "Computer Science"
faker::education::term()                 // "Fall Semester"
faker::education::courses()              // "Data Structures"
```

### 🕹️ Esport Module

```cpp
faker::esport::player()                  // "Ninja"
faker::esport::team()                    // "Team Liquid"
faker::esport::league()                  // "League of Legends Championship Series"
faker::esport::event()                   // "The International"
faker::esport::game()                    // "Dota 2"
faker::esport::organizer()               // "ESL"
```

### 🏦 Finance Module

```cpp
faker::finance::currency()               // {name: "US Dollar", code: "USD", symbol: "$"}
faker::finance::currencyName()           // "US Dollar"
faker::finance::currencyCode()           // "USD"
faker::finance::currencySymbol()         // "$"
faker::finance::accountType()            // "Savings"
faker::finance::amount()                 // "720.18"
faker::finance::iban()                   // "DE89370400440532013000"
faker::finance::bic()                    // "DEUTDEFF"
faker::finance::accountNumber()          // "12345678"
faker::finance::pin()                    // "1234"
faker::finance::routingNumber()          // "123456789"
faker::finance::creditCardNumber()       // "4532-1488-0343-6467"
faker::finance::creditCardCvv()          // "123"
faker::finance::bitcoinAddress()         // "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa"
faker::finance::litecoinAddress()        // "LU2q3eNKx6rmFGp3uCX8EwvY7qhxBn2pLf"
faker::finance::ethereumAddress()        // "0x742d35Cc6634C0532925a3b844Bc9e7595f0bEb"
faker::finance::creditCardExpirationDate() // "03/25"
faker::finance::creditCardType()         // "Visa"
```

### 🍝 Food Module

```cpp
faker::food::alcoholicBeverage()         // "Beer"
faker::food::grain()                     // "Rice"
faker::food::milkProduct()               // "Cheese"
faker::food::fruit()                     // "Apple"
faker::food::meat()                      // "Chicken"
faker::food::seafood()                   // "Salmon"
faker::food::vegetable()                 // "Carrot"
faker::food::oil()                       // "Olive Oil"
faker::food::nut()                       // "Almond"
faker::food::seed()                      // "Sunflower Seed"
faker::food::sugarProduct()              // "Sugar"
faker::food::nonalcoholicBeverage()      // "Coffee"
faker::food::dishName()                  // "Spaghetti Carbonara"
faker::food::foodCategory()              // "Italian"
```

### 📁 Git Module

```cpp
faker::git::branch()                     // "feature/add-login"
faker::git::commitDate()                 // "Mon Nov 12 14:32:49 2018 -0500"
faker::git::commitEntry()                // "commit 4e9d8c7... Author: John Doe..."
faker::git::commitMessage()              // "Fix bug in login form"
faker::git::commitSha()                  // "4e9d8c7a6f3b2e1d0c9b8a7f6e5d4c3b2a1"
```

### 👨‍💻 Hacker Module

```cpp
faker::hacker::abbreviation()            // "HTTP"
faker::hacker::adjective()               // "cross-platform"
faker::hacker::noun()                    // "protocol"
faker::hacker::verb()                    // "parse"
faker::hacker::ingverb()                 // "parsing"
faker::hacker::phrase()                  // "Try to parse the HTTP protocol!"
```

### 🖼️ Image Module

```cpp
faker::image::imageUrl()                 // "https://loremflickr.com/640/480"
faker::image::avatarUrl()                // "https://cloudflare-ipfs.com/ipfs/Qmd3W5..."
faker::image::dimensions()               // "1920x1080"
faker::image::type()                     // "png"
```

### 🌐 Internet Module

```cpp
faker::internet::username()              // "Richardson.Jeffrey1997"
faker::internet::email()                 // "Jimenez.Clyde@gmail.com"
faker::internet::exampleEmail()          // "Jimenez.Clyde@example.com"
faker::internet::password()              // "gXGpe9pKfFcKy9R"
faker::internet::emoji()                 // "👑"
faker::internet::protocol()              // "https"
faker::internet::httpMethod()            // "POST"
faker::internet::httpStatusCode()        // 200
faker::internet::httpRequestHeader()     // "Content-Type"
faker::internet::httpResponseHeader()    // "Cache-Control"
faker::internet::httpMediaType()         // "application/json"
faker::internet::ipv4()                  // "192.168.1.1"
faker::internet::ipv6()                  // "2001:0db8:85a3:0000:0000:8a2e:0370:7334"
faker::internet::mac()                   // "00:1B:44:11:3A:B7"
faker::internet::port()                  // 8080
faker::internet::url()                   // "https://example.com"
faker::internet::domainName()            // "example.com"
faker::internet::domainSuffix()          // "com"
faker::internet::domainWord()            // "example"
faker::internet::jwt()                   // "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
```

### 🌍 Location Module

```cpp
faker::location::country()               // "United States"
faker::location::continent()             // "North America"
faker::location::countryCode()           // "US"
faker::location::state()                 // "California"
faker::location::city()                  // "Los Angeles"
faker::location::zipCode()               // "90210"
faker::location::streetAddress()         // "123 Main St"
faker::location::street()                // "Main St"
faker::location::buildingNumber()        // "123"
faker::location::secondaryAddress()      // "Apt. 4"
faker::location::latitude()              // "34.052235"
faker::location::longitude()             // "-118.243683"
faker::location::direction()             // "North"
faker::location::timeZone()              // "America/Los_Angeles"
faker::location::mgrs()                  // "17SMD92712525"
```

### 📚 Lorem Module

```cpp
faker::lorem::word()                     // "temporibus"
faker::lorem::words()                    // "qui praesentium pariatur"
faker::lorem::sentence()                 // "Laborum voluptatem officiis est et."
faker::lorem::sentences()                // "Two sentences here. And another one."
faker::lorem::slug()                     // "hello-world-test"
faker::lorem::paragraph()                // "Long paragraph with multiple sentences..."
faker::lorem::paragraphs()               // "Multiple paragraphs..."
```

### 🏥 Medicine Module

```cpp
faker::medicine::condition()             // "Diabetes"
faker::medicine::medicalTest()           // "Blood Test"
faker::medicine::specialty()             // "Cardiology"
```

### 🎥 Movie Module

```cpp
faker::movie::genre()                    // "Action"
faker::movie::movieTitle()               // "The Matrix"
faker::movie::tvShow()                   // "Breaking Bad"
faker::movie::director()                 // "Steven Spielberg"
faker::movie::actor()                    // "Tom Hanks"
faker::movie::actress()                  // "Meryl Streep"
```

### 🎶 Music Module

```cpp
faker::music::artist()                   // "The Beatles"
faker::music::songName()                 // "Yesterday"
faker::music::genre()                    // "Rock"
```

### 🔢 Number Module

```cpp
faker::number::integer(1, 100)           // 42
faker::number::decimal(0.0, 1.0)         // 0.573
faker::number::hexadecimal(8)            // "a3f5d2b1"
faker::number::octal(8)                  // "12345670"
faker::number::binary(8)                 // "10110101"
faker::number::roman(1, 100)             // "XLII"
```

### 🧑 Person Module

```cpp
faker::person::firstName()               // "Michael"
faker::person::lastName()                // "Smith"
faker::person::fullName()                // "Michael Smith"
faker::person::prefix()                  // "Mr."
faker::person::suffix()                  // "Jr."
faker::person::bio()                     // "Software engineer passionate about..."
faker::person::sex()                     // Sex::Male
faker::person::gender()                  // "Male"
faker::person::jobTitle()                // "Software Engineer"
faker::person::jobDescriptor()           // "Senior"
faker::person::jobArea()                 // "IT"
faker::person::jobType()                 // "Developer"
faker::person::hobby()                   // "Reading"
faker::person::language()                // "English"
faker::person::nationality()             // "American"
faker::person::ssn()                     // "123-45-6789"
faker::person::westernZodiac()           // "Aries"
faker::person::chineseZodiac()           // "Dragon"
faker::person::passport()                // "A12345678"
```

### 📞 Phone Module

```cpp
faker::phone::number()                   // "+1-555-123-4567"
faker::phone::platform()                 // "iOS"
faker::phone::modelName()                // "iPhone 13"
faker::phone::manufacturer()             // "Apple"
faker::phone::imei()                     // "123456789012345"
```

### 🪴 Plant Module

```cpp
faker::plant::type()                     // "Tree"
faker::plant::tree()                     // "Oak"
faker::plant::flower()                   // "Rose"
```

### 🧑‍🔬 Science Module

```cpp
faker::science::chemicalElement()        // {name: "Hydrogen", symbol: "H", atomicNumber: 1}
faker::science::unit()                   // {name: "meter", symbol: "m", type: "length"}
```

### ⚽ Sport Module

```cpp
faker::sport::sport()                    // "Football"
faker::sport::soccerTeam()               // "Manchester United"
faker::sport::maleAthlete()              // "Cristiano Ronaldo"
faker::sport::femaleAthlete()            // "Serena Williams"
faker::sport::sportEvent()               // "Super Bowl"
```

### 🔢 String Module

```cpp
faker::string::uuidV1()                  // "b4f5d6f0-5d6e-11ec-bf63-0242ac130002"
faker::string::uuidV3()                  // "a3bb189e-8bf9-3888-9912-ace4e6543002"
faker::string::uuidV4()                  // "8e3a4f21-5c7b-4d9a-8f2e-1b9c7d6a5e3f"
faker::string::uuidV5()                  // "c6437ef1-5b86-5a4e-a071-c2d4ad414e65"
faker::string::uuidV6()                  // "1ec5d6f0-5d6e-6b40-8000-0242ac130002"
faker::string::uuidV7()                  // "017f22e2-79b0-7cc3-98c4-dc0c0c07398f"
faker::string::ulid()                    // "01ARZ3NDEKTSV4RRFFQ69G5FAV"
faker::string::sample(10)                // "aB3$fG7@kL"
faker::string::fromCharacters("abc", 5)  // "abcab"
faker::string::alpha(10)                 // "aBcDeFgHiJ"
faker::string::alphanumeric(10)          // "aB3cD5eF7g"
faker::string::numeric(10)               // "1234567890"
faker::string::nanoId()                  // "V1StGXR8_Z5jdHi6B-myT"
```

### 💻 System Module

```cpp
faker::system::fileName()                // "document.pdf"
faker::system::fileExtension()           // "pdf"
faker::system::filePath()                // "/usr/local/bin/app"
faker::system::directoryPath()           // "/usr/local"
faker::system::mimeType()                // "application/pdf"
faker::system::semver()                  // "1.0.0"
faker::system::networkInterface()        // "eth0"
faker::system::cron()                    // "0 0 * * *"
```

### 🚗 Vehicle Module

```cpp
faker::vehicle::bicycle()                // "Mountain Bike"
faker::vehicle::color()                  // "Red"
faker::vehicle::fuel()                   // "Gasoline"
faker::vehicle::manufacturer()           // "Toyota"
faker::vehicle::model()                  // "Camry"
faker::vehicle::type()                   // "Sedan"
faker::vehicle::vehicleName()            // "Toyota Camry"
faker::vehicle::vin()                    // "WBADT43452G918366"
faker::vehicle::vrm()                    // "AB12CDE"
```

### 🎞️ Video Module

```cpp
faker::video::formatName()               // "MP4"
faker::video::fileExtension()            // "mp4"
faker::video::videoCodec()               // "H.264"
faker::video::audioCodec()               // "AAC"
faker::video::resolution()               // "1920x1080"
faker::video::aspectRatio()              // "16:9"
faker::video::videoUrl()                 // "https://youtube.com/watch?v=..."
```

### 🎮 Video Game Module

```cpp
faker::videoGame::gameTitle()            // "Minecraft"
faker::videoGame::genre()                // "Action"
faker::videoGame::platform()             // "PlayStation 5"
faker::videoGame::studioName()           // "Mojang Studios"
```

### 🌤️ Weather Module

```cpp
faker::weather::weatherDescription()     // "Partly cloudy"
```

### 💬 Word Module

```cpp
faker::word::sample()                    // "apple"
faker::word::words(3)                    // "apple banana cherry"
faker::word::adjective()                 // "beautiful"
faker::word::adverb()                    // "quickly"
faker::word::conjunction()               // "and"
faker::word::interjection()              // "wow"
faker::word::noun()                      // "house"
faker::word::preposition()               // "above"
faker::word::verb()                      // "run"
```

## 🌍 Supported Locales

**40+ locales supported** including:

`en_US` (default), `en_GB`, `pl_PL`, `de_DE`, `de_AT`, `de_CH`, `fr_FR`, `fr_BE`, `fr_CH`, `it_IT`, `es_ES`, `es_MX`, `pt_PT`, `pt_BR`, `ru_RU`, `uk_UA`, `cs_CZ`, `sk_SK`, `sv_SE`, `nb_NO`, `da_DK`, `fi_FI`, `nl_NL`, `nl_BE`, `tr_TR`, `ro_RO`, `hu_HU`, `hr_HR`, `sl_SI`, `sr_RS`, `bg_BG`, `el_GR`, `hi_IN`, `en_IN`, `zh_CN`, `zh_TW`, `ja_JP`, `ko_KR`

**Usage:**

```cpp
faker::person::firstName(faker::Locale::pl_PL);  // "Krystyna"
faker::location::city(faker::Locale::fr_FR);     // "Lyon"
```

## Consuming the library with CMake

### With Git submodules and add_library

1. Add faker to git submodules (execute in project root):

    ```bash
    mkdir externals && cd externals
    git submodule add https://github.com/cieslarmichal/faker-cxx.git
    git submodule update --init --recursive
    ```

2. Link with library:

    ```cmake
    set(FAKER_BUILD_TESTING OFF)

    add_subdirectory(externals/faker-cxx)

    add_executable(main Main.cpp)

    target_link_libraries(main faker-cxx)
    ```

### With FetchContent

```cmake
set(FAKER_BUILD_TESTING OFF)

FetchContent_Declare(faker
    GIT_REPOSITORY https://github.com/cieslarmichal/faker-cxx.git
    GIT_TAG main
)

FetchContent_MakeAvailable(faker)

add_executable(main Main.cpp)

target_link_libraries(main faker-cxx)
```

## Installing the library with [vcpkg](https://vcpkg.io/)

You can install faker-cxx using the [vcpkg](https://vcpkg.io/) dependency manager:

```bash
vcpkg install faker-cxx
```

The faker-cxx port in vcpkg is kept up to date by Microsoft team members and community contributors.
If the version is out of date, please [create an issue or pull request](https://github.com/microsoft/vcpkg) on the vcpkg repository.

Then in your CMakeLists.txt:

```cmake
find_package(faker-cxx CONFIG REQUIRED)

add_executable(main Main.cpp)

target_link_libraries(main PRIVATE faker-cxx::faker-cxx)
```

## ⚒️ Compiler support

- [MSVC➚](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio) version 143 or newer.
- [GCC➚](https://gcc.gnu.org/) version 13 or newer.
- [Clang➚](https://clang.llvm.org/) version 16 or newer.
- [Apple Clang➚](https://clang.llvm.org/) version 16 or newer.

## Dependencies

- GTest (set `FAKER_BUILD_TESTING=OFF` CMake flag to disable this dependency)

In order to use external dependencies installed in your system, you can set the `USE_SYSTEM_DEPENDENCIES` CMake flag
to `ON`.

## 📦 Building the library with [Conan](https://conan.io/)

The library can be built using Conan package manager to solve external dependencies.
To build the library with Conan, follow the steps below:

1. Install required dependencies:

    ```bash
    conan install conanfile.txt --build=missing
    ```

2. Build the library:

    ```bash
    cmake --preset=conan-release -DUSE_SYSTEM_DEPENDENCIES:BOOL=ON
    cmake --build --preset=conan-release
    ```

## Installing the library with [Conan](https://conan.io/)

You can install pre-built binaries for faker-cxx or build it from source using Conan. Use the following command:

```bash
conan install --requires="faker-cxx/[*]" --build=missing
```

The faker-cxx Conan recipe is kept up to date by Conan maintainers and community contributors.
If the version is out of date, please [create an issue or pull request](https://github.com/conan-io/conan-center-index)
on the ConanCenterIndex repository.

## Building the library with [Bazel](https://bazel.build/)

As alternative, this project can be built using [Bazel](https://bazel.build/). The dependencies are managed directly by
Bazel modules, downloading and building all external dependencies. Follow the steps below to build the project:

1. **Navigate to the project directory:**

    ```sh
    cd /path/to/faker-cxx
    ```

2. **Build the project:**

    ```sh
    bazel build //:faker-cxx
    ```

## ✨ Contributing

We would love it if you contributed to Faker C++! 🚀

Check our guides on how to build the project locally:

- **[Complete Building Guide](./docs/guides/BUILDING.md)** - All compilers in one place
  - [GCC](./docs/guides/BUILDING.md#gcc-linux)
  - [Clang](./docs/guides/BUILDING.md#clang-linux)
  - [Apple Clang](./docs/guides/BUILDING.md#apple-clang-macos)
  - [MSVC](./docs/guides/BUILDING.md#msvc-windows)

Please make sure to read the [Contributing Guide](https://github.com/cieslarmichal/faker-cxx/blob/main/CONTRIBUTING.md)
before making a pull request.

Additionally, we encourage you to join our [Discord Channel](https://discord.gg/h2ur8H6mK6) for contributors.

## 📘 Credits

Thanks to all the people who already contributed to Faker!

<a href="https://github.com/cieslarmichal/faker-cxx/graphs/contributors"><img src="https://opencollective.com/faker-cxx/contributors.svg?width=800" alt="Contributors" /></a>

## 📝 Changelog

Detailed changes for each release are documented in the [release notes](CHANGELOG.md).

## 🔑 License

This project is under [MIT](LICENSE) license.
