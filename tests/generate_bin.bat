@echo off

REM    Nesecita llamar a vcvars64.bat para correrlo. Lo comilas con nmake
REM    You need to call vcvars64.bat to run it for visual studio. You run it
REM    with nmake
REM    @call %comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
rmdir bin_msv /s /q
mkdir bin_msv
cd bin_msv
cmake .. -G "NMake Makefiles"
cd ..

REM Ver compile_all.bat
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
