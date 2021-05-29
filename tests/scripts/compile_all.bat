@echo off

echo Construyendo para visual studio
cd bin_msv
cmake --build .
cd ..

REM echo Construyendo para gcc
REM cd bin_gcc
REM cmake --build .
REM cd ..

echo Construyendo para clang
cd bin_clang
cmake --build .
cd ..
