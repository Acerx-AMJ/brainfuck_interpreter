# brainfuck interpreter
### Overview
Simple brainfuck interpreter written in ~30 lines of C++ code, made to be minimal. List of commands can be seen [here](https://esolangs.org/wiki/Brainfuck) under `Language Overview` section.
### Compilling
This interpreter does not use any dependencies nor needs to include any directories. Compilling is as simple as running
```bash
clang++ main.cpp -o interpreter
```
or
```bash
g++ main.cpp -o interpreter
```
### Usage
```bash
./interpreter [code]
```
Examples:
```bash
./interpreter "++++++++++." # Prints a newline
```
```bash
./interpreter file.bf # Read and execute file
```
