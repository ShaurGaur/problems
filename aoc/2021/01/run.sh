#!/bin/bash

echo "Compiling now"
g++ -g main.cpp -o aoc-run
echo "finished compiling"

echo "\nTesting on AOC example input:"
./aoc-run test.txt

echo "\nTesting on our puzzle input:"
./aoc-run input.txt

rm -f aoc-run