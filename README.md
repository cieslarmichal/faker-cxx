<div align="center">
  <img src="https://raw.githubusercontent.com/cieslarmichal/faker-cxx/main/docs/images/logo.png" width="250" alt="C++ Faker, a powerful tool for generating realistic and randomized fake data in C++ programming, enhancing data testing and development workflows"/>
  <h1>Faker C++</h1>
  <p>Generate fake (but realistic) data for testing and development.</p>

[![clang++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml?query=branch%3Amain)
[![apple clang++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/macos-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/macos-clang-build.yml?query=branch%3Amain)
[![g++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml?query=branch%3Amain)
[![msvc](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml?query=branch%3Amain)
[![codecov](https://codecov.io/github/cieslarmichal/faker-cxx/branch/main/graph/badge.svg?token=0RTV4JFH2U)](https://codecov.io/github/cieslarmichal/faker-cxx)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Chat on Discord](https://img.shields.io/badge/chat-discord-blue?style=flat&logo=discord)](https://discord.gg/h2ur8H6mK6)
</div>

## 🎯 Goal

Goal of the Faker C++ is to provide a library like [Faker.js](https://github.com/faker-js/faker) for C++ community.

## Usage

```cpp
#include <iostream>

#include "faker-cxx/Date.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Location.h"
#include "faker-cxx/String.h"

int main()
{
    const auto id = faker::String::uuid();
    const auto email = faker::Internet::email();
    const auto password = faker::Internet::password();
    const auto verificationCode = faker::String::numeric(8);
    const auto createdAt = faker::Date::pastDate();
    const auto city = faker::Location::city();
    const auto streetAddress = faker::Location::streetAddress();

    std::cout << id << std::endl;               // 58018063-ce5a-4fa7-adfd-327eb2e2d9a5
    std::cout << email << std::endl;            // Lois_Hauck@hotmail.com
    std::cout << password << std::endl;         // @cWLwgM#Knalxeb
    std::cout << verificationCode << std::endl; // 31457428
    std::cout << createdAt << std::endl;        // 2023-06-20T02:06:36Z
    std::cout << city << std::endl;             // Sayreville
    std::cout << streetAddress << std::endl;    // 1716 Harriet Alley

    return 0;
}
```

## 💎 Modules

- 🛩 Airline - aircraft types, airlines, airports, flight numbers
- 🐼 Animal - animal types and species
- 📖 Book - book title, genre, author, publisher, ISBN
- 🎨 Color - color names, rgb, hex, hcl
- 🛒 Commerce - commerce department, product name, sku, price
- 🏢 Company - company name, type, industry, catch phrase, buzz phrase
- 🖥️ Computer - type, manufacturer, model, CPU info, GPU info
- 💾 Database - column names, column types, database engines
- ℹ️ Datatype - booleans
- 📅 Date - past, future dates
- 🏦 Finance - currency, IBAN, BIC, account name, account number, pin, credit card numbers
- 🍝 Food - food category, vegetables, fruits, meats, dishes
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

## Consuming library with CMake (CMake 3.22 or newer)

1. Add faker to git submodules (execute in project root):

    ```
    mkdir externals && cd externals
    git submodule add https://github.com/cieslarmichal/faker-cxx.git
    git submodule update --init --recursive
    ```

2. Link with library:

    ```cmake
    set(BUILD_FAKER_TESTS OFF)
    
    add_subdirectory(externals/faker-cxx)
    
    add_executable(main Main.cpp)
    
    target_link_libraries(main faker-cxx)
    ```

## Compiler support

- [MSVC➚](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio) version 143 or newer.
- [GCC➚](https://gcc.gnu.org/) version 13 or newer.
- [Clang➚](https://clang.llvm.org/) version 16 or newer.
- [Apple Clang➚](https://clang.llvm.org/) version 16 or newer.

## Dependencies

- GTest (```BUILD_FAKER_TESTS=OFF``` CMake flag to disable)
- fmt (only for Apple Clang++ compiler)

## ✨ Contributing

Feel free to join Faker C++ development! 🚀

Please check [CONTRIBUTING](https://github.com/cieslarmichal/faker-cxx/blob/main/CONTRIBUTING.md) guide.

[Discord Channel](https://discord.gg/h2ur8H6mK6) for contributors.

## 📝 Compilation guides

- [Clang++](./docs/guides/clang-compilation-guide.md)
- [Apple Clang++](./docs/guides/apple-clang-compilation-guide.md)
- [G++](./docs/guides/gcc-compilation-guide.md)
- [MSVC](./docs/guides/msvc-compilation-guide.md)
