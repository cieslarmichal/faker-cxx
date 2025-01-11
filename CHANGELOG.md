# Changelog

All notable changes to this project will be documented in this file

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
