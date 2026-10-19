## How to build
```text
g++ ccwc.cpp -o ccwc.o -std=c++20 
```

## possible commands (similar to `man wc`)
```text
-c      The number of bytes in each input file is written to the standard output.  This will cancel out any prior usage of the -m option.

-l      The number of lines in each input file is written to the standard output.

-m      The number of characters in each input file is written to the standard output.  If the current locale does not support multibyte characters, this is equivalent to the -c option.  This will cancel out any prior usage of the
        -c option.

-w      The number of words in each input file is written to the standard output.
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