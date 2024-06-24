# Changelog

All notable changes to this project will be documented in this file

## 2.0.0 (TBD)

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
* changed classes to namespaces for functions grouping, for example use `number::integer` instead of `Number::integer`, applies to all modules
* changed std::string to std::string_view in functions where is was possible
* changed function name from `sport` to `sportName` in sport module

### Features

* added `Plant` module

### Infra

* added Conan package manager support
* added support for GCC 12
* changed to link with fmt lib only if compiler does not support std::format
