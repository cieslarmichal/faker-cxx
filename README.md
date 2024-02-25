<div align="center">
  <img src="https://raw.githubusercontent.com/cieslarmichal/faker-cxx/main/docs/images/logo.png" width="250" alt="C++ Faker, a powerful tool for generating realistic and randomized fake data in C++ programming, enhancing data testing and development workflows"/>
  <h1>Faker C++</h1>
  <p>Generate fake (but realistic) data for testing and development</p>

[![clang++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml?query=branch%3Amain)
[![apple clang++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/macos-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/macos-clang-build.yml?query=branch%3Amain)
[![g++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml?query=branch%3Amain)
[![msvc](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml?query=branch%3Amain)
[![codecov](https://codecov.io/github/cieslarmichal/faker-cxx/branch/main/graph/badge.svg?token=0RTV4JFH2U)](https://codecov.io/github/cieslarmichal/faker-cxx)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Chat on Discord](https://img.shields.io/badge/chat-discord-blue?style=flat&logo=discord)](https://discord.gg/h2ur8H6mK6)
</div>

## 🎯 Goal

The goal of Faker C++ is to provide a library similar to [Faker.js](https://github.com/faker-js/faker) for C++ community. Faker C++ is a powerful library designed to streamline the creation of realistic and customizable fake data for testing and development purposes within C++ applications. The use of this library will provide a quick and user-friendly experience for developers, offering a wide variety of modules that cover everything from generating random names and addresses to crafting realistic financial and internet related data.

## Usage and Documentation

To properly use Faker C++ you must first assimilate the Faker library (see Consuming Library with CMake).
Once that is done, you need to include the proper header files depending on the module you wish to generate data from. The module header file names can be found by looking in the directory `include/faker-cxx`. A list of the functions, their descriptions, and how to use them can be found in [docs](https://cieslarmichal.github.io/faker-cxx).
Make sure to include the proper header file that corresponds to the data and subsequent functions you are trying to generate.

Below is an example of how to use Faker C++ in your code.

```cpp
#include <iostream>

#include <faker/Date.h"
#include <faker/Internet.h"
#include <faker/Location.h"
#include <faker/String.h"

int main()
{
    const auto id = faker::String::uuid();
    const auto email = faker::Internet::email();
    const auto password = faker::Internet::password();
    const auto city = faker::Location::city();
    const auto streetAddress = faker::Location::streetAddress();

    std::cout << id << std::endl;               // 58018063-ce5a-4fa7-adfd-327eb2e2d9a5
    std::cout << email << std::endl;            // Lois_Hauck@hotmail.com
    std::cout << password << std::endl;         // @cWLwgM#Knalxeb
    std::cout << city << std::endl;             // Sayreville
    std::cout << streetAddress << std::endl;    // 1716 Harriet Alley

    return 0;
}
```
This example generates basic personal information including id, email, password, city, and street address. Users can tailor their data generation by exploring other modules and functions within the library.

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

Use one of these compilers when working with Faker C++.

- [MSVC➚](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio) version 143 or newer.
- [GCC➚](https://gcc.gnu.org/) version 13 or newer.
- [Clang➚](https://clang.llvm.org/) version 16 or newer.
- [Apple Clang➚](https://clang.llvm.org/) version 16 or newer.

If you have any confusion please refer to the respective guides.

- [Clang++](./docs/guides/clang-compilation-guide.md)
- [Apple Clang++](./docs/guides/apple-clang-compilation-guide.md)
- [G++](./docs/guides/gcc-compilation-guide.md)
- [MSVC](./docs/guides/msvc-compilation-guide.md)

## Dependencies

- GTest (set `BUILD_CONFIG_CXX_TESTS=OFF` CMake flag to disable this dependency)
- fmt (only for Apple Clang++ compiler)

## ✨ Contributing

We would love it if you contributed to Faker C++! 🚀

Whether you are interested in fixing bugs, implementing new features, or improving documentation, your input is welcome and valuable. Before contributing, please review our [CONTRIBUTING](https://github.com/cieslarmichal/faker-cxx/blob/main/CONTRIBUTING.md) guide for guidelines on coding standards, making changes, and creating Pull Requests (PRs). Your engagement helps maintain the project's vitality and ensures Faker C++ remains a useful tool for the C++ community.

Additionally, we encourage you to join our [Discord Channel](https://discord.gg/h2ur8H6mK6) for contributors, where you can engage in discussions, seek assistance, and collaborate with fellow developers. Your contributions play a crucial role in the development and furthering of Faker C++. We look forward to your involvement and appreciate your commitment to the project's growth!
