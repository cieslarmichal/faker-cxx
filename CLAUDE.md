# faker-cxx

## Local dev environment setup

```bash
git submodule update --init --recursive
cmake -B build -DFAKER_BUILD_TESTING=ON
cmake --build build
ctest --test-dir build
```
