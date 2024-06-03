# 🔨 Building project with Clang

## 1. Install Clang

```bash
sudo apt install clang-18
```

## 2. Prepare build directory

```bash
git clone https://github.com/cieslarmichal/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
```

## 3. Setup CMake

```bash
cmake -B ./build -DCMAKE_CXX_COMPILER=clang++ -DBUILD_TESTING=ON
```

## 4. Build

```bash
cmake --build ./build
```

## 5. Run tests

```bash
./faker-cxx-UT
```

or using CTest:

```bash
ctest --test-dir ./build
```
