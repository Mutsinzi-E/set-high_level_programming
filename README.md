# Monty Project

This project is a simple interpreter for Monty bytecode files.

## Features
- push opcode: pushes an integer onto the stack
- pall opcode: prints all values on the stack
- Handles errors like:
  - invalid push arguments
  - unknown instructions
  - file opening errors
  - usage errors

## Compilation
gcc -Wall -Werror -Wextra -pedantic *.c -o monty

## Usage
./monty file.m
