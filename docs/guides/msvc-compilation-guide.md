# 🔨 Building project with MSVC

## 1. Prepare build directory

```bash
git clone https://github.com/cieslarmichal/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
```

## 2. Setup CMake

```bash
cmake -B ./build -G "Visual Studio 17 2022"
```

## 3. Build

```bash
cmake --build ./build
```

## 4. Run tests

```bash
./faker-cxx-UT.exe
```

or using CTest:

```bash
ctest --test-dir ./build
```
