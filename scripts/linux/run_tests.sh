#!/bin/bash

cd ./tests/

echo Searching Tests ...
./MarkdownParser__TestsBuilder ./tests/ ./main.cpp

echo \nCompiling Tests ...
g++ --std=c++2a -O3 ./main.cpp -o ./../bin/Debug/MarkdownParser__Tester

echo \nRunning Tests ...
./../bin/Debug/MarkdownParser__Tester