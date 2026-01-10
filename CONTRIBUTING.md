# 🤝 How to Contribute

Thank you for your interest in contributing to Faker C++! This guide will help you get started with contributing to the project.

## 📋 Table of Contents

- [Quick Links](#quick-links)
- [Ways to Contribute](#ways-to-contribute)
- [Getting Started](#getting-started)
- [Development Workflow](#development-workflow)
- [Code Style](#code-style)
- [Testing](#testing)
- [Pull Request Process](#pull-request-process)
- [Adding New Modules](#adding-new-modules)
- [Documentation](#documentation)
- [Community](#community)

## 🔗 Quick Links

- **[Building Guide](./docs/guides/BUILDING.md)** - How to build the project
- **[Quick Start](./QUICK_START.md)** - Get started with using the library
- **[Issues](https://github.com/cieslarmichal/faker-cxx/issues)** - Find something to work on
- **[Discussions](https://github.com/cieslarmichal/faker-cxx/discussions)** - Ask questions
- **[Discord](https://discord.gg/h2ur8H6mK6)** - Chat with the community

## 🎯 Ways to Contribute

There are many ways you can contribute to Faker C++:

### 🐛 Report Bugs

Found a bug? [Create an issue](https://github.com/cieslarmichal/faker-cxx/issues/new) with:

- A clear description of the problem
- Steps to reproduce
- Expected vs actual behavior
- Your environment (OS, compiler, version)

### 💡 Suggest Features

Have an idea? [Start a discussion](https://github.com/cieslarmichal/faker-cxx/discussions) or create a feature request issue.

### 📝 Improve Documentation

- Fix typos or clarify existing docs
- Add examples
- Write tutorials or blog posts
- Translate documentation

### 🔧 Write Code

- Fix bugs
- Implement new features
- Add new data generators
- Improve performance
- Add support for new locales

### ✅ Review Pull Requests

Help review open pull requests and provide constructive feedback.

## 🚀 Getting Started

### Prerequisites

Before you begin, ensure you have:

- **CMake** 3.22 or higher
- **C++ Compiler** with C++20 support:
  - GCC 13+
  - Clang 16+
  - Apple Clang 16+
  - MSVC 143 (Visual Studio 2022)+

You can check compiler support at [cppreference](https://en.cppreference.com/w/cpp/compiler_support/20).

### 1️⃣ Fork and Clone

First, [fork the repository](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo) on GitHub, then clone your fork:

```bash
git clone https://github.com/<your-username>/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
```

Replace `<your-username>` with your GitHub username.

### 2️⃣ Build the Project

See our comprehensive [Building Guide](./docs/guides/BUILDING.md) for detailed instructions for your compiler.

**Quick build:**

```bash
# Configure
cmake -B build -DBUILD_TESTING=ON

# Build
cmake --build build

# Run tests
ctest --test-dir build
```

### 3️⃣ Create a Branch

Create a feature or bug fix branch from `main`:

```bash
git checkout -b feature/your-feature-name
# or
git checkout -b fix/bug-description
```

**Branch naming conventions:**

- `feature/feature-name` - For new features
- `fix/bug-description` - For bug fixes
- `docs/description` - For documentation changes
- `refactor/description` - For code refactoring

## 💻 Development Workflow

### 1. Pick an Issue

Browse [open issues](https://github.com/cieslarmichal/faker-cxx/issues) or create a new one to discuss your proposed changes.

**Good first issues:** Look for issues labeled `good first issue` if you're new to the project.

### 2. Write Code

- Follow the [code style](#code-style) guidelines
- Write clean, readable, and maintainable code
- Add comments for complex logic
- Keep functions focused and small

### 3. Add Tests

**All new features and bug fixes must include tests!**

Tests are located in the `tests/` directory. Add your tests in the appropriate module test file.

Example test structure:

```cpp
#include <gtest/gtest.h>
#include "faker-cxx/your_module.h"

TEST(YourModuleTest, ShouldGenerateExpectedValue)
{
    const auto result = faker::yourModule::yourFunction();
    
    ASSERT_FALSE(result.empty());
    // Add more assertions
}
```

### 4. Run Tests

```bash
# Run all tests
ctest --test-dir build

# Run tests with verbose output
ctest --test-dir build --verbose

# Run specific test
ctest --test-dir build -R YourModuleTest
```

### 5. Format Your Code

This project uses `.clang-format` for consistent code formatting.

**Format all code:**

```bash
./scripts/format_code.sh
```

**Or configure your IDE:**

- **VS Code**: Install the `clang-format` extension
- **CLion**: Enable ClangFormat in Settings → Editor → Code Style
- **Visual Studio**: Use Format Document (Ctrl+K, Ctrl+D)

## 📐 Code Style

### General Guidelines

- **Indentation**: 4 spaces (no tabs)
- **Line length**: Max 120 characters
- **Naming conventions**:
  - Functions: `camelCase()`
  - Variables: `camelCase`
  - Classes: `PascalCase`
  - Constants: `UPPER_SNAKE_CASE`
  - Namespaces: `lowercase`

### Best Practices

```cpp
// ✅ Good
std::string firstName(Locale locale = Locale::en_US);

// ❌ Bad
std::string first_name(Locale locale = Locale::en_US);
```

```cpp
// ✅ Good - Clear function name and documentation
/**
 * @brief Generates a random email address.
 * @param locale The locale to use.
 * @returns Random email address.
 */
std::string email(Locale locale = Locale::en_US);

// ❌ Bad - No documentation
std::string e(Locale l = Locale::en_US);
```

### File Encoding

If your file contains non-Latin characters, ensure it's saved with **UTF-8 encoding without BOM**.

**In VS Code:**

1. Click the encoding in the status bar
2. Select "Save with Encoding"
3. Choose "UTF-8"

## 🧪 Testing

### Test Structure

- Tests use [Google Test (GTest)](https://github.com/google/googletest)
- Each module has its own test file in `tests/modules/`
- Test names should be descriptive: `TEST(ModuleName, ShouldDoSomethingWhenCondition)`

### Writing Good Tests

```cpp
TEST(InternetTest, ShouldGenerateValidEmail)
{
    const auto email = faker::internet::email();
    
    // Check email is not empty
    ASSERT_FALSE(email.empty());
    
    // Check email contains @ symbol
    ASSERT_TRUE(email.find('@') != std::string::npos);
    
    // Check email contains domain
    ASSERT_TRUE(email.find('.') != std::string::npos);
}
```

### Test Coverage

- Aim for high test coverage
- Test edge cases and error conditions
- Test with different locales when applicable

## 📤 Pull Request Process

### Before Submitting

✅ **Checklist:**

- [ ] Code follows the project's style guidelines
- [ ] All tests pass locally
- [ ] New tests added for new features/fixes
- [ ] Code is formatted with `clang-format`
- [ ] Documentation updated (if needed)
- [ ] Commit messages are clear and descriptive
- [ ] No merge conflicts with `main`

### Commit Messages

Write clear, descriptive commit messages:

```
✅ Good commit messages:
- "Add French locale support for person module"
- "Fix memory leak in string generator"
- "Update README with API reference section"

❌ Bad commit messages:
- "fix stuff"
- "update"
- "wip"
```

**Format:**

```
<type>: <subject>

<optional body>

<optional footer>
```

**Types:**

- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, etc.)
- `refactor`: Code refactoring
- `test`: Adding or updating tests
- `chore`: Maintenance tasks

**Example:**

```
feat: add Japanese locale support for person names

- Added Japanese first names and last names
- Updated person module to support ja_JP locale
- Added tests for Japanese name generation

Closes #123
```

### Creating a Pull Request

1. **Push your branch:**

   ```bash
   git push origin feature/your-feature-name
   ```

2. **Open a PR on GitHub:**
   - Go to the [repository](https://github.com/cieslarmichal/faker-cxx)
   - Click "Pull requests" → "New pull request"
   - Select your branch
   - Fill in the PR template

3. **PR Description should include:**
   - What changes were made
   - Why these changes are needed
   - How to test the changes
   - Screenshots (if applicable)
   - Related issues (use "Closes #123")

### Review Process

- Maintainers will review your PR
- Address feedback and requested changes
- Once approved, your PR will be merged!

**Be patient and responsive:**

- Reviews may take a few days
- Be open to feedback
- Respond to comments
- Make requested changes promptly

## 🆕 Adding New Modules

Want to add a new data generator module? Follow these steps:

### 1. Create Header File

Create `include/faker-cxx/your_module.h`:

```cpp
#pragma once

#include <string>
#include <string_view>
#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::yourModule
{
/**
 * @brief Your function description.
 * @param locale The locale. Defaults to `Locale::en_US`.
 * @returns Description of return value.
 * @code
 * faker::yourModule::yourFunction() // "example output"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view yourFunction(Locale locale = Locale::en_US);
}
```

### 2. Create Data File

Create `src/modules/your_module_data.h` with your data arrays.

### 3. Create Implementation

Create `src/modules/your_module.cpp` with implementations.

### 4. Create Tests

Create `tests/modules/your_module_test.cpp` with comprehensive tests.

### 5. Update CMakeLists.txt

Add your module to `src/CMakeLists.txt` and `tests/CMakeLists.txt`.

### 6. Update Documentation

- Add your module to README.md
- Add examples
- Update API reference

## 📖 Documentation

### Code Documentation

Use Doxygen-style comments:

```cpp
/**
 * @brief Brief description of function.
 *
 * Detailed description if needed.
 *
 * @param paramName Description of parameter.
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Description of return value.
 *
 * @code
 * faker::module::function() // "example output"
 * faker::module::function(Locale::pl_PL) // "przykładowy wynik"
 * @endcode
 */
```

### README Updates

When adding features:

- Update the module list
- Add to API Reference section
- Include code examples
- Update table of contents if needed

## 👥 Community

### Get Help

- **Discord**: Join our [Discord server](https://discord.gg/h2ur8H6mK6)
- **Discussions**: Use [GitHub Discussions](https://github.com/cieslarmichal/faker-cxx/discussions)
- **Issues**: Check [existing issues](https://github.com/cieslarmichal/faker-cxx/issues)

### Code of Conduct

Please read and follow our [Code of Conduct](CODE_OF_CONDUCT.md). We're committed to providing a welcoming and inclusive environment.

### Recognition

Contributors are recognized in:

- The [README](README.md) contributors section
- Release notes for significant contributions
- Our community channels

## ❓ Questions?

If you have questions that aren't covered in this guide:

1. Check the [documentation](https://cieslarmichal.github.io/faker-cxx/)
2. Search [existing issues](https://github.com/cieslarmichal/faker-cxx/issues)
3. Ask on [Discord](https://discord.gg/h2ur8H6mK6)
4. Start a [discussion](https://github.com/cieslarmichal/faker-cxx/discussions)

---

**Thank you for contributing to Faker C++! 🎉**

We appreciate your time and effort in making this library better for everyone.
