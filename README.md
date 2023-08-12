<h1>C++ Faker</h1>

[![clang](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-clang-build.yml?query=branch%3Amain)
[![g++](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/linux-gxx-build.yml?query=branch%3Amain)
[![msvc](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/windows-msvc-build.yml?query=branch%3Amain)
[![codecov](https://codecov.io/github/cieslarmichal/faker-cxx/branch/main/graph/badge.svg?token=0RTV4JFH2U)](https://codecov.io/github/cieslarmichal/faker-cxx)
[![CodeFactor](https://www.codefactor.io/repository/github/cieslarmichal/faker-cxx/badge)](https://www.codefactor.io/repository/github/cieslarmichal/faker-cxx)
[![GitHub](https://img.shields.io/github/license/cieslarmichal/faker-cxx)](https://github.com/cieslarmichal/faker-cxx/blob/main/LICENSE)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Discord Shield](https://img.shields.io/badge/discord-join-blue)](https://discord.gg/h2ur8H6mK6)

C++ Faker is a modern C++20 open-source library for generating fake data for testing and development.

The library is heavily inspired by [Faker.js](https://github.com/faker-js/faker).

Dependencies: GTest for building library tests (can be disabled by setting CMake flag BUILD_FAKER_TESTS=OFF)

## 🎯 Goal

My goal is to provide a library like [Faker.js](https://github.com/faker-js/faker) for C++ developers.

## Example

Lets dive into some simple example of generating fake data

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

## Requirements

### Compiler Support

- [MSVC➚](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio) version 143 or newer.
- [GCC➚](https://gcc.gnu.org/) version 13 or newer.
- [Clang➚](https://clang.llvm.org/) version 16 or newer.

### [CMake](https://cmake.org/) version 3.22 or newer

## Consuming library with CMake

```cmake
set(BUILD_FAKER_TESTS OFF)

add_subdirectory(externals/faker-cxx)

add_executable(main Main.cpp)

target_link_libraries(main faker-cxx)
```

## 💎 Modules

- 🌐 Internet - Generate emails, usernames, passwords, images urls
- 🌍 Location - Generate countries, cities, zip codes, street addresses
- 🧑 Person - Generate first, last names, job titles, genders, sex
- 📞 Phone - Generate phone number, IMEI
- 🛒 Commerce - Generate commerce department, product name, sku, price
- 📅 Date - Generate past, future dates
- 🏦 Finance - Generate currency, IBAN, BIC, account name, account number, pin, credit card numbers
- 🏢 Company - Generate company name, type, industry, catch phrase, buzz phrase
- 🔢 Number - Generate random integers, floating point numbers
- ✍ Word - Generate sample words, nouns, verbs etc
- 🎨 Color - Generate color names, rgb, hex
- 📖 Book - Generate book title, genre, author, publisher, ISBN
- 📚 Lorem - Generate lorem words, sentences, paragraphs
- 🔢 String - Generate uuids, alphanumeric, numeric, hexadecimal
- 💻 System - Generate file paths, file extensions, file names, directories, semantic version
- Database - Generate column names, column types, database engines
- 🎶 Music - Generate artists, song names, genres
- 🎥 Movie - Generate actors, actresses, genres, movie titles

### 🔨 [TODO Modules](https://github.com/cieslarmichal/faker-cxx/blob/main/TODO.md)

## ✨ Contributing

Feel free to join Faker C++ development! 🚀

Please check [CONTRIBUTING](https://github.com/cieslarmichal/faker-cxx/blob/main/CONTRIBUTING.md) guide.

[Discord Channel](https://discord.gg/h2ur8H6mK6) for contributors.

<br />

## Building from sources with Clang 16

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

#### 4. Build 🔨

```
make
```
