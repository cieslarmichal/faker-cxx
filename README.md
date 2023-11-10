<h1>C++ Faker</h1>

[![clang++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml?query=branch%3Amain)
[![apple clang++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/macos-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/macos-clang-build.yml?query=branch%3Amain)
[![g++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml?query=branch%3Amain)
[![msvc](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml?query=branch%3Amain)
[![codecov](https://codecov.io/github/cieslarmichal/faker-cxx/branch/main/graph/badge.svg?token=0RTV4JFH2U)](https://codecov.io/github/cieslarmichal/faker-cxx)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Discord Shield](https://img.shields.io/badge/discord-join-blue)](https://discord.gg/h2ur8H6mK6)

C++ Faker is a modern C++20 open-source library for generating fake data for testing and development.

The library is heavily inspired by [Faker.js](https://github.com/faker-js/faker).

Dependencies: 
 - GTest: building tests (BUILD_FAKER_TESTS=OFF CMake flag to disable)
 - fmt

## 🎯 Goal

My goal is to provide a library like [Faker.js](https://github.com/faker-js/faker) for C++ developers.

## Example

Lets see some simple example of generating fake data

```cpp
#include <format>
#include <iostream>

#include "faker-cxx/Datatype.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/String.h"

int main()
{
    const auto id = faker::String::uuid();                   // 6fdb588e-0be9-480e-9eeb-8ff11b8afc00
    const auto email = faker::Internet::email();             // Sergio_Greenfelder@hotmail.com
    const auto password = faker::Internet::password();       // 91gZxLB*TfhAA!G
    const auto nickname = faker::Internet::username();       // Stuart_Boyle
    const auto active = faker::Datatype::boolean();          // true
    const auto emailVerified = faker::Datatype::boolean();   // false
    const auto verificationCode = faker::String::numeric(8); // 56910620
    const auto createdAt = faker::Date::pastDate();          // 2023-03-11T08:33:34Z
    const auto updatedAt = faker::Date::recentDate();        // 2023-07-19T22:59:19Z

    std::cout << std::format("id: {}, email: {}, password: {}, nickname: {}, active: {}, emailVerified: {}. "
                             "verificationCode: {}, createdAt: {}, updatedAt: {}",
                             id, email, password, nickname, active, emailVerified, verificationCode, createdAt,
                             updatedAt);

    return 0;
}
```

## Compiler support
- [MSVC➚](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio) version 143 or newer.
- [GCC➚](https://gcc.gnu.org/) version 13 or newer.
- [Clang➚](https://clang.llvm.org/) version 16 or newer.
- [Apple Clang➚](https://clang.llvm.org/) version 16 or newer.

## Consuming library with CMake (CMake version 3.22 or newer)

1. Add faker to git submodules (execute in project root):
```
mkdir externals
cd externals
git submodule add https://github.com/cieslarmichal/faker-cxx.git
```
2. Link with library:
```cmake
set(BUILD_FAKER_TESTS OFF)

add_subdirectory(externals/faker-cxx)

add_executable(main Main.cpp)

target_link_libraries(main faker-cxx)
```

## 💎 Modules

- 🛩 Airline - aircraft types, airlines, airports, flight numbers
- 🐼 Animal - animal types and species
- 📖 Book - book title, genre, author, publisher, ISBN
- 🎨 Color - color names, rgb, hex, hcl
- 🛒 Commerce - commerce department, product name, sku, price
- 🏢 Company - company name, type, industry, catch phrase, buzz phrase
- 💾 Database - column names, column types, database engines
- ℹ️ Datatype - booleans
- 📅 Date - past, future dates
- 🏦 Finance - currency, IBAN, BIC, account name, account number, pin, credit card numbers
- 📁 Git - branch names, commit messages, commit hash 
- 👨‍💻 Hacker - hacker words
- ✋ Helper - random element from container
- 🌐 Internet - emails, usernames, passwords, IP, HTTP
- 🖼️ Image - images urls, github avatar urls, image dimensions
- 🌍 Location - countries, cities, zip codes, street addresses
- 📚 Lorem - lorem words, sentences, paragraphs
- 🏥 Medicine - conditions, medical tests, specialties
- 🎥 Movie - actors, actresses, genres, movie titles
- 🎶 Music - artists, song names, genres
- 🔢 Number - random integers, floating point numbers
- 🧑 Person - first, last names, job titles, hobby, genders, sex, nationalitiy, language
- 📞 Phone - phone number, IMEI
- ⚽ Sport - sport names, athletes, events
- 🔢 String - uuids, alphanumeric, numeric, hexadecimal
- 💻 System - file paths, file extensions, file names, directories, semantic version
- 🎮 Video game - title, genre, platform, studio
- 🌤️ Weather - temperature, pressure, humidity, weather description
- 💬 Word - sample words, nouns, verbs

## 📖 Documentation

https://cieslarmichal.github.io/faker-cxx/

## ✨ Contributing

Feel free to join Faker C++ development! 🚀

Please check [CONTRIBUTING](https://github.com/cieslarmichal/faker-cxx/blob/main/CONTRIBUTING.md) guide.

[Discord Channel](https://discord.gg/h2ur8H6mK6) for contributors.

<br />

## 🔨 Building from sources with Clang 16

#### 1. Install Clang 16

```
sudo add-apt-repository ppa:trebelnik-stefina/launchpad-getkeys \
&& sudo apt-get update \
&& sudo apt-get install launchpad-getkeys \
&& sudo add-apt-repository 'deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-16 main' \
&& sudo launchpad-getkeys \
&& sudo apt-get update -y \
&& sudo apt-get install -y lld-16 ninja-build  build-essential libstdc++-13-dev \
 clang-16 clang-tools-16 llvm-16 lcov
```

#### 2. Prepare build directory

```
git clone https://github.com/cieslarmichal/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
mkdir build
cd build
```

#### 3. CMake setup with Clang 16

```
cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/clang++-16
```

#### 4. Build

```
make
```
