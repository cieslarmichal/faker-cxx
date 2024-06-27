<div align="center">
  <img src="https://raw.githubusercontent.com/cieslarmichal/faker-cxx/main/docs/public/logo.png" width="250" alt="C++ Faker, a powerful tool for generating realistic and randomized fake data in C++ programming, enhancing data testing and development workflows"/>
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

## Table of Contents

- [🎯 Goal](#-goal)
- [Usage and Documentation](#usage-and-documentation)
- [💎 Modules](#-modules)
- [Consuming library with CMake](#consuming-library-with-cmake-cmake-322-or-newer)
- [Compiler support](#compiler-support)
- [Dependencies](#dependencies)
- [Building the library with Conan](#building-the-library-with-conan)
- [✨ Contributing](#-contributing)
- [📘 Credits](#-credits)
- [Examples](#examples)
- [📝 Changelog](#-changelog)
- [🔑 License](#-license)

## 🎯 Goal

The goal of Faker C++ is to provide a library similar to [Faker.js](https://github.com/faker-js/faker) for C++
community. Faker C++ helps with the creation of realistic and customizable fake data for testing and development
purposes within C++ applications.

## Usage and Documentation

To properly use Faker C++ you must first consume the Faker library (see Consuming Library with CMake).
Once that is done, you need to include the proper [header](https://cieslarmichal.github.io/faker-cxx/files.html) file depending on the module you wish to generate data from or
use general include file `faker-cxx/Faker.h`.

Below is an example of how to use Faker C++ in your code.

```cpp
#include <iostream>

#include "faker-cxx/Date.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Location.h"
#include "faker-cxx/String.h"

// or #include "faker-cxx/Faker.h" for all modules

int main()
{
    const auto id = faker::string::uuid();
    const auto email = faker::internet::email();
    const auto password = faker::internet::password();
    const auto city = faker::location::city();
    const auto streetAddress = faker::location::streetAddress();

    std::cout << id << std::endl;               // 58018063-ce5a-4fa7-adfd-327eb2e2d9a5
    std::cout << email << std::endl;            // Lois_Hauck@hotmail.com
    std::cout << password << std::endl;         // @cWLwgM#Knalxeb
    std::cout << city << std::endl;             // Sayre ville
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
- 🏢 Company - company name, type, industry, catchphrase, buzz phrase
- 🖥️ Computer - type, manufacturer, model, CPU info, GPU info
- 🔐 Crypto - sha256, md5
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
- 🧑 Person - first, last names, job titles, hobby, genders, sex, nationality, language
- 📞 Phone - phone number, IMEI
- 🪴 Plant - plant type, trees, flowers
- ⚽ Sport - sport names, athletes, events
- 🔢 String - uuids, alphanumeric, numeric, hexadecimal
- 💻 System - file paths, file extensions, file names, directories, semantic version
- 🚗 Vehicle - vehicle types, makes, models, fuel types, license plates
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
    set(BUILD_TESTING OFF)

    add_subdirectory(externals/faker-cxx)

    add_executable(main Main.cpp)

    target_link_libraries(main faker-cxx)
    ```

## Compiler support

- [MSVC➚](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio) version 143 or newer.
- [GCC➚](https://gcc.gnu.org/) version 12 or newer.
- [Clang➚](https://clang.llvm.org/) version 16 or newer.
- [Apple Clang➚](https://clang.llvm.org/) version 16 or newer.

## Dependencies

- GTest (set `BUILD_TESTING=OFF` CMake flag to disable this dependency)
- fmt (only for compilers that don't support std::format)

In order to use external dependencies installed in your system, you can set the `USE_SYSTEM_DEPENDENCIES` CMake flag
to `ON`.

## Building the library with [Conan](https://conan.io/)

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

## ✨ Contributing

We would love it if you contributed to Faker C++! 🚀

Check our guides on how to build the project locally:

- [Clang++](./docs/guides/clang-compilation-guide.md)
- [Apple Clang++](./docs/guides/apple-clang-compilation-guide.md)
- [G++](./docs/guides/gcc-compilation-guide.md)
- [MSVC](./docs/guides/msvc-compilation-guide.md)

Please make sure to read the [Contributing Guide](https://github.com/cieslarmichal/faker-cxx/blob/main/CONTRIBUTING.md)
before making a pull request.

Additionally, we encourage you to join our [Discord Channel](https://discord.gg/h2ur8H6mK6) for contributors.

## 📘 Credits

Thanks to all the people who already contributed to Faker!

<a href="https://github.com/cieslarmichal/faker-cxx/graphs/contributors"><img src="https://opencollective.com/faker-cxx/contributors.svg?width=800" /></a>

## Examples

This project offers examples to demonstrate how to use the Faker C++ library.
These examples can be found in the [examples](examples/README.md) folder of the project repository.
The examples showcase various modules of the library and provide code snippets that illustrate how to generate fake data
using Faker C++.

## 📝 Changelog

Detailed changes for each release are documented in the [release notes](CHANGELOG.md).

## 🔑 License

This project is under [MIT](LICENSE) license.
