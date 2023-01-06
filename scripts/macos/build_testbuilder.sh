#!/bin/bash

cd ./tests/
echo Compiling TestsBuilder ...
g++ --std=c++2a -O3 ./TestBuilder.cpp -o ./MarkdownParser__TestsBuilder

echo Done.
echo From next time can just run Test, there\'s no need to compile TestBuilder again \:\)