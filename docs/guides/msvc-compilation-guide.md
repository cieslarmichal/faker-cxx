## 🔨 Building project with MSVC

### 1. Prepare build directory

```bash
git clone https://github.com/cieslarmichal/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
mkdir build & cd build
```

### 2. Setup CMake

```bash
cmake .. -G "Visual Studio 17 2022"
```

### 3. Build

```bash
cmake --build .
```

### 4. Run tests

```bash
./faker-cxx-UT.exe
```
