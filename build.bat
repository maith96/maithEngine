@echo off
setlocal

set BUILD_DIR="build"



REM Create the build directory if it does not exist
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

pushd %BUILD_DIR%

cmake .. -G "MinGW Makefiles"
cmake --build . 

maith.exe

popd

endlocal
