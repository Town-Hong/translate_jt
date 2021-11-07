if not exist build mkdir build
cd build
if not exist vc15 mkdir vc15
cd vc15

:: rd /s /Q .\

conan install ..\..\   -g cmake_multi -s build_type=Release -s compiler="Visual Studio" -s compiler.version=15 -s arch=x86_64 --update
conan install ..\..\   -g cmake_multi -s build_type=Debug -s compiler="Visual Studio" -s compiler.version=15 -s arch=x86_64 --update
cmake ../../  -G "Visual Studio 15 2017 Win64"

pause