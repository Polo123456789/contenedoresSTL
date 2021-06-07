@echo off

echo Construyendo para visual studio
cd bin_msv
cmake --build .
cd ..

REM echo Construyendo para gcc
cd bin_gcc
cmake --build .
cd ..

echo Construyendo para clang
cd bin_clang
cmake --build .
cd ..
