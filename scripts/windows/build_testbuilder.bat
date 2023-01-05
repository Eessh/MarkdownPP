@echo off

cd .\tests\
echo Compiling tests builder ...
g++ --std=c++20 -O3 .\TestBuilder.cpp -o .\MarkdownParser__TestsBuilder.exe
echo Done.
echo From next time can just run Test, there's no need to compile TestBuilder again :)

echo:
echo Press enter to exit
set /p input=
exit