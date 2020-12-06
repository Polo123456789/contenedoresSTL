@echo off

echo Construyendo para visual studio
cd bin_msv
nmake
cd ..

REM gcc no tiene ganas de colaborar, tendre que probar en otra maquina
REM echo Construyendo para gcc
REM cd bin_gcc
REM make
REM test.exe
REM cd ..

echo Construyendo para clang
cd bin_clang
make
cd ..
