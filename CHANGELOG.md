# Changelog

All notable changes to this project will be documented in this file

## v4.4.1 (19.08.2026)

### Fixes

* declared CMake config version bindings consistently, so `find_package(faker-cxx CONFIG)` picks up the version file
* bumped hardcoded project version in `CMakeLists.txt` and `BUILD.bazel` (stuck at 4.0.1 since v4.0.1)
* added missing `base64`, `education`, `esport`, `generator` and `video` includes to the umbrella `faker-cxx/faker.h` header
* fixed broken code examples in README and QUICK_START (`phone::number`, `productCategory` conversion, `normalDistribution` argument types)

## v4.4.0 (16.08.2026)

### Features

* added location address data for Korea (ko_KR), Lebanon (ar_LB), Greece (el_GR), Slovenia (sl_SI), Belgium (nl_BE, fr_BE), Bulgaria (bg_BG), North Macedonia (mk_MK), Argentina (es_AR), Latvia (lv_LV), Moldova (ro_MD), Syria (ar_SY), China (zh_CN), Vietnam (vi_VN), Croatia (hr_HR), Ireland (en_IE), Malta (mt_MT, en_MT), Netherlands (nl_NL), Switzerland (de_CH, fr_CH, it_CH, rm_CH), Bosnia and Herzegovina (bs_BA, hr_BA, sr_BA), Canada (fr_CA), Sweden (sv_SE) and Belarus

### Fixes

* handled empty separator in `split` function
* avoided `std::format` for floating-point precision to fix macOS < 13.3 builds
* pinned CC/CXX to cl.exe for Windows Conan profile detection
* de-flaked Lithuania street address test

## v4.3.2 (20.02.2026)

### Fixes

* fixed build warnings by adding/removing static casts

## v4.3.1 (06.02.2026)

### Fixes

* resolved Bazel build failure by updating platforms dependency

## v4.3.0 (04.02.2026)

### Features

* added missing API docs in README

### Changes

* replaced `BUILD_TESTING` option with `FAKER_BUILD_TESTING`

## v4.2.0 (11.01.2026)

* improved public documentation (README, QUICK_START, CONTRIBUTING, building guides)

## v4.1.0 (05.11.2025)

### Features

* added location address data for Monaco, Albania (sq_AL), Canada (en_CA), Iran, Lithuania, Hungary, Iceland, Japan, Turkey, Norway and Romania
* added `education` module data and enhanced airline dataset
* added `dataUri` function for SVG generation
* added `romanNumber` function to `number` module
* added MGRS coordinate generation with specified precision to `location` module
* made `number::integer` support more integral types
* used a single random engine per thread and provided ability to set seed

### Fixes

* fixed `number::octal` and `number::binary(int)` returning non-printable characters
* added missing `<cstdint>` and `<climits>` includes
* fixed Bazel build

## v4.0.1 (14.01.2025)

* fix dropping fmt dependency

## v4.0.0 (11.01.2025)

### ⚠ BREAKING CHANGES

* moved `hexadecimal` function from `string` to `number` module
* moved `binary` function from `string` to `number` module
* moved `octal` function from `string` to `number` module
* dropped fmt library from dependencies, require compiler with std::format support
* renamed `string::uuid` to `string::uuidV4`

### Features

* added locale support for all modules that use locale
* added `uuidV1`, `uuidV3`, `uuidV5`, `uuidV6` and `uuidV7` functions to `string` module
* added `nanoId` function to `string` module
* added `space` function to `color` module
* added `jwt` function to `internet` module
* added `hwb` function to `color` module
* added `between` and `anytime` function to `date` module
* added `nearbyGPSCoordinate` to `location` module
* added `symbol` function to `string` module

## v3.0.0 (28.08.2024)

### ⚠ BREAKING CHANGES

* removed `location.county` method
* renamed all include files from `CamelCase` to `snake_case`
* changed function name from `number` (by format) to `phoneNumberByFormat` in phone module
* changed function name from `number` (by country) to `phoneNumberByCountry` in phone module
* changed function name from `name` to `companyName` in company module
* changed function `companyName` to take optional enum parameter in company module
* changed function `branch` to take optional enum parameter in git module
* changed country, language, bic country, iban country params to locale

### Features

* added `Video` module
* added `Esport` module

## v2.0.0 (27.06.2024)

### ⚠ BREAKING CHANGES

* removed `structure` module
* removed `book.translator` method, use `person.fullName` instead
* removed `book.isbn` method, use `commerce.isbn` instead
* removed `commerce.price` method, use `finance.amount` instead
* removed `commerce.productId` method, use `string.alphanumeric` instead
* removed `commerce.productRating` method, use `number.decimal` instead
* removed `commerce.discountAmount` method, use `number.decimal` instead
* removed `commerce.discountPercentage` method, use `number.decimal` instead
* removed `commerce.orderNumber` method, use `string.numeric` instead
* removed `commerce.discountCode` method, use `string.alphanumeric` instead
* removed `git.author` method, use `person.fullName` instead
* removed `helper.shuffle` method, use standard library shuffle instead
* removed `person.middleName` method, use `person.firstName` instead
* removed `weather.temperature` method, use `number.decimal` instead
* removed `weather.pressure` method, use `number.decimal` instead
* removed `weather.visibility` method, use `number.decimal` instead
* removed `weather.windSpeed` method, use `number.decimal` instead
* removed `weather.uvIndex` method, use `number.integer` instead
* removed `weather.humidity` method, use `number.integer` instead
* removed `weather.cloudCover` method, use `number.integer` instead
* changed classes to namespaces for functions grouping, for example use `number::integer` instead of `Number::integer`,
  applies to all modules
* changed std::string to std::string_view in functions where is was possible
* changed function name from `sport` to `sportName` in sport module
* changed function name from `vehicle` to `vehicleName` in vehicle module
* changed function name from `timezone` to `timezoneRandom` in date module
* deleted function `commonFileType` from `System` module, use `system.fileType` instead

### Features

* added `Plant` module

### Infra

* added Conan package manager support
* added support for GCC 12
* changed to link with fmt lib only if compiler does not support std::format
