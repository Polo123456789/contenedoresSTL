@echo off

echo Construyendo para visual studio
cd bin_msv
nmake
cd ..

REM gcc no tiene ganas de colaborar, tendre que probar en otra maquina
REM Pero aun asi lo quiero compilar, aunque no lo corra
echo Construyendo para gcc
cd bin_gcc
make
cd ..

echo Construyendo para clang
cd bin_clang
make
cd ..
