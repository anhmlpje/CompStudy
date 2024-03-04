#!/bin/bash

gcc code.c -o factorial

echo -e "~~ Testing Factorials ~~"

echo -n "Testing 1 - "
./factorial < test1.txt > tmp
if grep -q "The factorial of 1 is 1" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 0 - "
echo "0" | ./factorial > tmp
if grep -q "The factorial of 0 is 1" tmp;
then
    echo "PASS"
else
    echo "FAIL"
if

echo -n "Testing 3 - "
echo "3" | ./factorial > tmp
if grep -q "The factorial of 3 is 6" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f tmp factorial