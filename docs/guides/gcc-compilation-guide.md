# 🔨 Building project with G++

## 1. Install G++

```bash
sudo apt install cmake ninja-build g++-13
```

## 2. Prepare build directory

```bash
git clone https://github.com/cieslarmichal/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
```

## 3. Setup CMake

```bash
cmake -B ./build -DCMAKE_CXX_COMPILER=g++ -DBUILD_TESTING=ON
```

## 4. Build

```bash
cmake --build ./build
```

## 5. Run tests

```bash
./build/tests/faker-cxx-UT
```

or using CTest:

```bash
ctest --test-dir ./build
```
