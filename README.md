## How to build
```text
g++ ccwc.cpp -o ccwc.o -std=c++20 
```

## Commands you can run
```text
outputs the number of bytes in a file
./ccwc.o -c test.txt
  342190 test.txt
```

## Default run
```text
./ccwc.o frakenstein.txt                                                                                         
2568 8 444 frakenstein.txt
```

## Get number of lines
```text
./ccwc.o frakenstein.txt -l
8 frakenstein.txt
```

## get lines, words, bytes, and characters
```text
./ccwc.o frakenstein.txt -l -w -c -m
8 444 2568 2560 frakenstein.txt
```

## Pipe operator and cat command for reading file to cin works too
```text
cat frakenstein.txt | ./ccwc.o            
2568 8 444 
```

## Context
This is a build you own project from [Coding Challenges](https://codingchallenges.fyi/challenges/challenge-wc). 

This project is built with C++ 20.