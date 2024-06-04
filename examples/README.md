# Faker-cxx Examples

This repository contains examples for using the Faker-cxx library.

## Building with CMake

To build the examples, you should follow the [CONTRIBUTING.md](../CONTRIBUTING.md) guide as usual,
however you should pass `-DBUILD_EXAMPLE=ON` to CMake in order to build examples. It's disabled
by default. For instance:

```sh
cmake -S . --preset <preset-name> -DBUILD_EXAMPLES=ON
```

## Running examples

In order to run a built example application, you need to go to the build folder, then run the application:

```
cd build/<preset-name>/examples/person
./faker-cxx-person-example
```

However, using CMake, you can execute all examples at once:

```
cmake --build --preset <preset-name> --target run-faker-cxx-person-example
```

The custom CMake target `run-faker-cxx-person-example` will run the faker-cxx-person-example.
Only needs to add the prefix `run-` to the example name.

## Examples:

Here is a list of availables examples in this folder.

### Basic

It follows the main example listed in the [README.md](../README.md) root file.

### Person

The `Person` example demonstrates how to generate fake person data using the Faker-cxx library. It showcases various features and functions provided by the library to generate realistic person information.
