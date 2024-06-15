# Changelog

All notable changes to this project will be documented in this file

## 2.0.0 (TBD)

### ⚠ BREAKING CHANGES

* removed `Structure` module
* changed std::string to std::string_view in where possible

### Features

* added `Plant` module

### Infra

* added Conan package manager support
* added support for GCC 12
* changed to link with fmt lib only if compiler does not support std::format
