@echo off
rmdir bin_msv /s /q
mkdir bin_msv
cd bin_msv
cmake .. -G "NMake Makefiles"
cd ..

rmdir bin_gcc /s /q
mkdir bin_gcc
cd bin_gcc
cmake .. -G "Unix Makefiles"
cd ..

rmdir bin_clang /s /q
mkdir bin_clang
cd bin_clang
cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang
cd ..
