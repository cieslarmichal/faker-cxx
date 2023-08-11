#! /bin/bash

mkdir -p build

# shellcheck disable=SC2164
pushd build > /dev/null
if find '.' -maxdepth 0 -empty -type d; then
    echo "[Script] Configuring cmake"
    cmake -DCMAKE_CXX_COMPILER=/bin/clang++-16 ..
fi

echo "[Script] Compiling UT"
make faker-cxx-UT -j 16
./faker-cxx-UT
# shellcheck disable=SC2164
popd > /dev/null
