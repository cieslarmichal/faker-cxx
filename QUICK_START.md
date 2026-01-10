# ⚡ Quick Start Guide

Get up and running with Faker C++ in less than 5 minutes!

## 📋 What You'll Learn

- How to install Faker C++
- How to write your first program
- Common use cases and examples

## 🚀 Installation

Choose your preferred method:

### Option 1: CMake with FetchContent (Recommended)

Add this to your `CMakeLists.txt`:

```cmake
include(FetchContent)

set(BUILD_TESTING OFF)

FetchContent_Declare(
    faker-cxx
    GIT_REPOSITORY https://github.com/cieslarmichal/faker-cxx.git
    GIT_TAG main
)

FetchContent_MakeAvailable(faker-cxx)

add_executable(myapp main.cpp)
target_link_libraries(myapp faker-cxx)
```

### Option 2: Git Submodule

```bash
mkdir externals && cd externals
git submodule add https://github.com/cieslarmichal/faker-cxx.git
git submodule update --init --recursive
```

Then in your `CMakeLists.txt`:

```cmake
set(BUILD_TESTING OFF)
add_subdirectory(externals/faker-cxx)

add_executable(myapp main.cpp)
target_link_libraries(myapp faker-cxx)
```

### Option 3: Conan

```bash
conan install --requires="faker-cxx/[*]" --build=missing
```

### Option 4: vcpkg

```bash
vcpkg install faker-cxx
```

## 👋 Your First Program

Create a file `main.cpp`:

```cpp
#include <iostream>
#include "faker-cxx/faker.h"

int main()
{
    // Generate a random name
    std::cout << "Name: " << faker::person::fullName() << std::endl;
    
    // Generate a random email
    std::cout << "Email: " << faker::internet::email() << std::endl;
    
    // Generate a random phone number
    std::cout << "Phone: " << faker::phone::number() << std::endl;
    
    return 0;
}
```

### Build and Run

```bash
cmake -B build
cmake --build build
./build/myapp
```

Output:
```
Name: Jennifer Martin
Email: martin.jennifer@gmail.com
Phone: +1-555-123-4567
```

## 🎯 Common Use Cases

### 1. Generate Test Data for Database

```cpp
#include <iostream>
#include "faker-cxx/faker.h"

struct User {
    std::string id;
    std::string name;
    std::string email;
    std::string address;
    std::string phone;
    std::string birthdate;
};

User generateUser() {
    return User{
        faker::string::uuidV4(),
        faker::person::fullName(),
        faker::internet::email(),
        faker::location::streetAddress(),
        faker::phone::number(),
        faker::date::birthdateByYear(1970, 2005)
    };
}

int main() {
    // Generate 5 test users
    for (int i = 0; i < 5; i++) {
        auto user = generateUser();
        std::cout << "User " << (i+1) << ":\n"
                  << "  ID: " << user.id << "\n"
                  << "  Name: " << user.name << "\n"
                  << "  Email: " << user.email << "\n"
                  << "  Address: " << user.address << "\n"
                  << "  Phone: " << user.phone << "\n"
                  << "  Birthdate: " << user.birthdate << "\n\n";
    }
    return 0;
}
```

### 2. Generate Mock API Responses

```cpp
#include <iostream>
#include "faker-cxx/faker.h"

struct Product {
    std::string id;
    std::string name;
    std::string description;
    std::string price;
    std::string category;
};

Product generateProduct() {
    return Product{
        faker::string::uuidV4(),
        faker::commerce::productFullName(),
        faker::commerce::productDescription(),
        faker::finance::amount(10, 1000, faker::Precision::TwoDp, "$"),
        faker::commerce::productCategory()
    };
}

int main() {
    auto product = generateProduct();
    
    std::cout << "{\n"
              << "  \"id\": \"" << product.id << "\",\n"
              << "  \"name\": \"" << product.name << "\",\n"
              << "  \"description\": \"" << product.description << "\",\n"
              << "  \"price\": \"" << product.price << "\",\n"
              << "  \"category\": \"" << product.category << "\"\n"
              << "}" << std::endl;
    
    return 0;
}
```

### 3. Generate Lorem Ipsum Content

```cpp
#include <iostream>
#include "faker-cxx/lorem.h"
#include "faker-cxx/person.h"

int main() {
    std::cout << "Blog Post Title: " << faker::lorem::words(5) << "\n\n";
    std::cout << "Author: " << faker::person::fullName() << "\n\n";
    std::cout << faker::lorem::paragraph() << "\n\n";
    std::cout << faker::lorem::paragraph() << std::endl;
    
    return 0;
}
```

### 4. Generate Unique Identifiers

```cpp
#include <iostream>
#include "faker-cxx/string.h"

int main() {
    // UUID v4
    std::cout << "UUID v4: " << faker::string::uuidV4() << std::endl;
    
    // UUID v7 (time-based)
    std::cout << "UUID v7: " << faker::string::uuidV7() << std::endl;
    
    // ULID
    std::cout << "ULID: " << faker::string::ulid() << std::endl;
    
    // Nano ID
    std::cout << "Nano ID: " << faker::string::nanoId() << std::endl;
    
    return 0;
}
```

### 5. Generate Test Passwords (NOT for production!)

```cpp
#include <iostream>
#include "faker-cxx/internet.h"

int main() {
    // Default: 16 characters with all options
    std::cout << "Default: " << faker::internet::password() << std::endl;
    
    // Custom length
    std::cout << "Length 20: " << faker::internet::password(20) << std::endl;
    
    // Custom options
    faker::internet::PasswordOptions opts;
    opts.upperLetters = true;
    opts.lowerLetters = true;
    opts.numbers = true;
    opts.symbols = false;
    
    std::cout << "No symbols: " << faker::internet::password(16, opts) << std::endl;
    
    return 0;
}
```

## 🌍 Using Different Locales

Faker C++ supports multiple locales for generating localized data:

```cpp
#include <iostream>
#include "faker-cxx/person.h"
#include "faker-cxx/location.h"

int main() {
    // English (US)
    std::cout << "EN: " << faker::person::firstName(faker::Locale::en_US) << std::endl;
    
    // Polish
    std::cout << "PL: " << faker::person::firstName(faker::Locale::pl_PL) << std::endl;
    
    // German
    std::cout << "DE: " << faker::person::firstName(faker::Locale::de_DE) << std::endl;
    
    // French
    std::cout << "FR: " << faker::person::firstName(faker::Locale::fr_FR) << std::endl;
    
    return 0;
}
```

## 🎲 Controlling Randomness

You can seed the random generator for reproducible results:

```cpp
#include <iostream>
#include "faker-cxx/person.h"
#include "faker-cxx/generator.h"

int main() {
    // Seed the generator
    faker::setSeed(12345);
    
    // These will be the same every time with the same seed
    std::cout << faker::person::firstName() << std::endl;
    std::cout << faker::person::firstName() << std::endl;
    
    return 0;
}
```

## 📚 Explore More

Now that you have the basics, explore more modules:

- **Person**: Names, job titles, bios, hobbies
- **Internet**: Emails, URLs, passwords, IPs
- **Location**: Countries, cities, addresses
- **Finance**: Currency, IBAN, credit cards
- **Commerce**: Products, prices, SKUs
- **Date**: Past/future dates, birthdays
- **String**: UUIDs, ULIDs, Nano IDs

See the [full API documentation](https://cieslarmichal.github.io/faker-cxx/) or [README](../README.md) for all modules.

## 💡 Tips

- Include specific headers for faster compilation: `#include "faker-cxx/person.h"`
- Many functions return `string_view` for efficiency
- Join [Discord](https://discord.gg/h2ur8H6mK6) for help

## 🤝 Contributing

Want to contribute? Check out:
- [CONTRIBUTING.md](../CONTRIBUTING.md) - Contribution guidelines
- [docs/guides/BUILDING.md](docs/guides/BUILDING.md) - How to build locally

## ❓ Need Help?

- 📖 [Full Documentation](https://cieslarmichal.github.io/faker-cxx/)
- 💬 [Discord Community](https://discord.gg/h2ur8H6mK6)
- 🐛 [Report Issues](https://github.com/cieslarmichal/faker-cxx/issues)
- ⭐ [Star on GitHub](https://github.com/cieslarmichal/faker-cxx)

Happy coding! 🎉
