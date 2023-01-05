#!/bin/bash

cd ./tests/

echo Searching Tests ...
./MarkdownParser__TestsBuilder ./tests/ ./main.cpp

echo Compiling Tests ...
g++ --std=c++2a -O3 ./main.cpp -o ./../bin/Debug/MarkdownParser__Tester

echo Running Tests ...
./../bin/Debug/MarkdownParser__Tester