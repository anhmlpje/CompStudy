#!/bin/bash

gcc test.c -o test

files=("maze.txt" "maze1.txt" "maze2.txt" "maze3.txt" "maze4.txt" "maze5.txt")

for file in "${files[@]}"; do
    echo "Testing ${file}..."
    ./test $file > tmp

    echo "file open error"
    if grep "Error: Could not find or open the file." tmp; then
        echo "PASS"
        echo "--------------------------------"
        continue
    else
        echo "FAIL"
    fi

    echo "Test whether the width is within the range"
    if grep -q "Width must be between 5 and 100." tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi

    echo "Test whether the hight is within the range"
    if grep -q "Height must be between 5 and 100." tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi

    echo "Test that each line is the same length"
    if grep -q "Invalid maze: rows are not the same length." tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi

    echo "test for invalid character"
    if grep -q "File have invalid character" tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi

    echo "test for Start and Exit"
    if grep -q "The maze has not Start or Exit" tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi

    echo "test bad user input"
    if grep -q "Invalid input" tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi

    echo "test user move into the wall"
    if grep -q "Can not move into the wall" tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi

    echo "test user move outside the maze"
    if grep -q "Can not move outside the maze" tmp; then
        echo "PASS"
    else
        echo "FAIL"
    fi
    echo "--------------------------------"
done

echo "Testing completed."