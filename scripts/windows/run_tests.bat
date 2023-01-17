@echo off

cd .\tests\

echo Searching tests ...
MarkdownParser__TestsBuilder.exe .\tests\ .\main.cpp

echo:
echo Compiling tests ...
g++ --std=c++20 -O3 .\main.cpp -o .\..\bin\Debug\MarkdownParser__Tester.exe

echo:
echo Running tests ...
.\..\bin\Debug\MarkdownParser__Tester.exe

echo:
echo Press enter to exit
set /p input=
exit