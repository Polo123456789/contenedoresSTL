@echo off

echo Construyendo para visual studio
cd bin_msv
nmake
test.exe
cd ..

echo Construyendo para gcc
cd bin_gcc
make
test.exe
cd ..

echo Construyendo para clang
cd bin_clang
make
test.exe
cd ..
