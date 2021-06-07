@echo off

rmdir bin_msv /s /q
mkdir bin_msv
cd bin_msv
cmake ..
cd ..

REM Ver compile_all.bat
rmdir bin_gcc /s /q
mkdir bin_gcc
cd bin_gcc
cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
cd ..

rmdir bin_clang /s /q
mkdir bin_clang
cd bin_clang
cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang
cd ..
