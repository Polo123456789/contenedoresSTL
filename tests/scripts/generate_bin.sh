#! /bin/sh

rm bin_gcc -rf
mkdir bin_gcc
cd bin_gcc
cmake .. -G "Unix Makefiles"
cd ..

rm bin_clang -rf
mkdir bin_clang
cd bin_clang
cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cd ..

