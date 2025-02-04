#!/bin/bash

#Program: Assignment 1
#Author: Damon Palomo
#This bash file is part of the program "Chemistry".

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile hw1.c"
gcc -c -Wall -m64 -no-pie -o hw1.o hw1.c -std=c2x  -g

echo "Link the object files"
gcc -m64 -no-pie -o hw.out hw1.o -std=c2x -g

#Make sure the executable has permission to execute
chmod u+x hw.out

echo "Run the program Chemistry!:"
./hw.out

echo "The script file will terminate"