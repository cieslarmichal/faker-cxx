<h1>C++ Faker</h1>

[![build and test](https://github.com/cieslarmichal/faker-cxx/actions/workflows/buildAndTest.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/buildAndTest.yml?query=branch%3Amain)
[![codecov](https://codecov.io/github/cieslarmichal/faker-cxx/branch/main/graph/badge.svg?token=0RTV4JFH2U)](https://codecov.io/github/cieslarmichal/faker-cxx)
[![CodeFactor](https://www.codefactor.io/repository/github/cieslarmichal/faker-cxx/badge)](https://www.codefactor.io/repository/github/cieslarmichal/faker-cxx)
[![GitHub](https://img.shields.io/github/license/cieslarmichal/faker-cxx)](https://github.com/cieslarmichal/faker-cxx/blob/main/LICENSE)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![Discord Shield](https://img.shields.io/badge/discord-join-blue)](https://discord.gg/jPy9R64Q)

C++ Faker is a modern C++20 open-source library for generating fake data for testing and development.

The library is heavily inspired by [Faker.js](https://github.com/faker-js/faker).

Dependencies: GTest for building library tests (can be disabled by setting CMake flag BUILD_TESTS=OFF)

## 🎯 Goal

My goal is to provide a library like [Faker.js](https://github.com/faker-js/faker) for C++ developers.

## Example

Lets dive into some simple example of generating fake data

```cpp
#include <format>
#include <iostream>
#include "faker-cxx/Internet.h"
#include "faker-cxx/String.h"
#include "faker-cxx/Date.h"

int main()
{
    const auto id = faker::String::uuid();
    const auto email = faker::Internet::email();
    const auto password = faker::Internet::password();
    const auto createdAt = faker::Date::pastDate();
    const auto updatedAt = faker::Date::recentDate();

    std::cout << std::format("id: {}, email: {}, password: {}, createdAt: {}, updatedAt: {}", id, email, password,
                             createdAt, updatedAt);

    return 0;
}
```

## Consuming library with CMake

```cmake
add_subdirectory(third_party/faker-cxx)

add_executable(main main.cpp)

target_link_libraries(main faker-cxx)
```

## 💎 Modules

- 🌐 Internet - Generate emails, usernames, passwords, images urls.
- 🧑 Person - Generate first, last names, job titles, genders, sex.
- 🛒 Commerce - Generate commerce department, product name, sku, price.
- 📅 Date - Generate past, future dates.
- 🏦 Finance - Generate currency, IBAN, BIC, account name, account number, pin.
- 🏢 Company - Generate company name, type, industry, catch phrase, buzz phrase.
- 🔢 Number - Generate random integers, floating point numbers.
- ✍ Word - Generate sample words, nouns, verbs etc.
- 🎨 Color - Generate color names, rgb, hex.
- 📖 Book - Generate book title, genre, author, publisher, ISBN.
- ℹ️ Datatype - Generate booleans.
- 📚 Lorem - Generate lorem text.
- 🔢 String - Generate uuids, alphanumeric, numeric, hexadecimal.

### 🔨 [TODO Modules](https://github.com/cieslarmichal/faker-cxx/blob/main/TODO.md)

## ✨ Contributing

Feel free to join Faker C++ development! 🚀

Please check [CONTRIBUTING](https://github.com/cieslarmichal/faker-cxx/blob/main/CONTRIBUTING.md) guide.

[Discord Channel](https://discord.gg/jPy9R64Q) for contributors.
