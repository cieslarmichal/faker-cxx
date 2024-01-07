## 🔨 Building project with Apple Clang 16

### 1. Install Clang 16

```bash
brew install llvm@16
```

### 2. Prepare build directory

```bash
git clone https://github.com/cieslarmichal/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
mkdir build && cd build
```

### 3. Setup CMake

```bash
cmake .. -DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm@16/bin/clang++
```

⚠️ **Warning:** Ensure that the path `/opt/homebrew/opt/llvm@16/bin/clang++` is valid on your system. If this path is
not correct, replace it with the correct path to your Clang 16 compiler. You can find the correct path by using the
command `brew --prefix llvm@16`. Adjust the CMake command accordingly.

### 4. Build

```bash
make
```

### 5. Run tests

```bash
./faker-cxx-UT
```

---

**Note:** This guide assumes a standard installation of Homebrew and the default paths it uses. If your Homebrew or LLVM
installation paths are different, you will need to adjust the commands accordingly. Remember that paths and specific
commands might vary depending on your system configuration and the versions of the tools installed.
