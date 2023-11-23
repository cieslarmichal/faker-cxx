
# Building from Sources with Clang 16 on macOS

This guide provides instructions on how to build from sources using Clang 16 on a macOS system.

## 1. Install Clang 16

Clang is part of the LLVM project and can be installed on macOS using Homebrew, a popular package manager.

First, ensure you have Homebrew installed. If not, install Homebrew by running the following in the Terminal:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Then, install LLVM (which includes Clang) with:

```bash
brew install llvm@16
```

## 2. Prepare Build Directory

Clone the desired repository and set up the build environment:

```bash
git clone https://github.com/cieslarmichal/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
mkdir build
cd build
```

## 3. CMake Setup with Clang 16

Before proceeding, ensure CMake is installed. If not, install it using Homebrew:

```bash
brew install cmake
```

Then, set up CMake for building with Clang 16:

```bash
cmake .. -DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm@16/bin/clang++
```

⚠️ **Warning:** Ensure that the path `/opt/homebrew/opt/llvm@16/bin/clang++` is valid on your system. If this path is not correct, replace it with the correct path to your Clang 16 compiler. You can find the correct path by using the command `brew --prefix llvm@16`. Adjust the CMake command accordingly.

## 4. Build

Finally, build the project:

```bash
make
```

## 5. Run

After building, you can run the built executable:

```bash
./faker-cxx-UT
```

---

**Note:** This guide assumes a standard installation of Homebrew and the default paths it uses. If your Homebrew or LLVM installation paths are different, you will need to adjust the commands accordingly. Remember that paths and specific commands might vary depending on your system configuration and the versions of the tools installed.
