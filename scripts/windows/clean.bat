@echo off

echo Cleaning executables ...
del /q "bin\Debug\*" >nul 2>&1
del /q "bin\Release\*" >nul 2>&1

echo Cleaning object files ...
del /q "obj\Debug\*" >nul 2>&1
del /q "obj\Release\*" >nul 2>&1

echo Cleaning misc files ...
del /q "Makefile" >nul 2>&1
del /q "*.make" >nul 2>&1
del /q "tests\MarkdownParser__TestsBuilder.exe" >nul 2>&1
del /q "tests\main.cpp" >nul 2>&1

echo Done.

exit