## 🔨 Building project with G++ 13

### 1. Install G++ 13

```bash
sudo apt install cmake ninja-build g++-13 libstdc++-13-dev
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
cmake .. -GNinja -DCMAKE_CXX_COMPILER=g++
```

### 4. Build

```bash
cmake --build .
```

### 5. Run tests

```bash
./faker-cxx-UT
```

### Additional information

If you can't install g++ 13 on your system, you can use
prepared [Dockerfile](https://github.com/cieslarmichal/faker-cxx/blob/main/Dockerfile.gcc13).
