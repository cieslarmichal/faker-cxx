#! /bin/bash

mkdir -p build

pushd build > /dev/null
if find '.' -maxdepth 0 -empty -type d; then
    echo "[Script] Configuring cmake"
    cmake -DCMAKE_CXX_COMPILER=/bin/clang++-16 ..
fi

echo "[Script] Compiling UT"
make faker-cxx-UT -j 16
./faker-cxx-UT
popd > /dev/null