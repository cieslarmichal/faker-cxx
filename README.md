<h1>C++ Faker</h1>

[![build and test](https://github.com/cieslarmichal/faker-cxx/actions/workflows/buildAndTest.yml/badge.svg?branch=main)](https://github.com/cieslarmichal/faker-cxx/actions/workflows/buildAndTest.yml?query=branch%3Amain)
[![codecov](https://codecov.io/github/cieslarmichal/faker-cxx/branch/main/graph/badge.svg?token=0RTV4JFH2U)](https://codecov.io/github/cieslarmichal/faker-cxx)

faker-cxx is a modern C++20 open-source library for generating fake data for testing and development.


It has no dependencies beyond Boost library (and GTest for unit tests).

## 🎯 Goal
My goal is to create a simple, modern C++ Faker library similar to [faker-js/faker](https://github.com/faker-js/faker).

## Example
Lets dive into some simple example of generating fake data for some user

```cpp
#include <format>
#include <iostream>
#include "faker-cxx/Internet.h"
#include "faker-cxx/String.h"

int main()
{
    const auto id = faker::String::uuid();
    const auto email = faker::Internet::email();
    const auto password = faker::Internet::password();

    std::cout << std::format("id: {}, email: {}, password: {}", id, email, password);

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

- 🌐 Internet - Generate emails, usernames and passwords.
- 🧑 Person - Generate first, last names.
- 🔢 Number - Generate random numbers.
- 📚 Lorem - Generate lorem text.
- 🔢 String - Generate uuids.



## 🔨 TODO Modules

- 🌍 Localization - Generate addresses.
- 📅 Date - Generate past, future dates.
- 👕 Commerce - Generate prices, product names, and descriptions.
- 🐘 Animal - Generate animal types and names
- 🎨 Color - Generate RGB colors and color names
- 🏢 Company - Generate company name, location
- ℹ️ Datatype - Generate strings, numbers, booleans
- 🎶 Music - Generate music genre, song names
- 📖 Book - Generate book genre, title, author, isbn, published year
- 📞 Phone - Generate phone number
- 🎮 Game - Generate game genre, title


## ✨ Contributing

Please feel free to join Faker C++ development! 🚀
