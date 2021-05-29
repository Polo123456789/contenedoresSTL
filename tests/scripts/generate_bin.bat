@echo off

rmdir bin_msv /s /q
mkdir bin_msv
cd bin_msv
cmake ..
cd ..

REM Ver compile_all.bat
REM rmdir bin_gcc /s /q
REM mkdir bin_gcc
REM cd bin_gcc
REM cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
REM cd ..

rmdir bin_clang /s /q
mkdir bin_clang
cd bin_clang
cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang
cd ..
