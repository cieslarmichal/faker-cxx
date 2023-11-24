## 🔨 Building from sources with Clang 16

#### 1. Install Clang 16

```bash
sudo add-apt-repository ppa:trebelnik-stefina/launchpad-getkeys \
&& sudo apt-get update \
&& sudo apt-get install launchpad-getkeys \
&& sudo add-apt-repository 'deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-16 main' \
&& sudo launchpad-getkeys \
&& sudo apt-get update -y \
&& sudo apt-get install -y lld-16 ninja-build  build-essential libstdc++-13-dev \
 clang-16 clang-tools-16 llvm-16 lcov
```

#### 2. Prepare build directory

```bash
git clone https://github.com/cieslarmichal/faker-cxx.git
cd faker-cxx
git submodule update --init --recursive
mkdir build
cd build
```

#### 3. CMake setup with Clang 16

```bash
cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/clang++-16
```

#### 4. Build

```bash
make
```

## 5. Run

After building, you can run the built executable:

```bash
./faker-cxx-UT
```