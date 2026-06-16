# Monty Project

This project implements a Monty Bytecode interpreter in C.

## Features
- push opcode: pushes an integer to the stack
- pall opcode: prints all stack values
- pop opcode: removes top element

## Compilation
gcc -Wall -Werror -Wextra -pedantic *.c -o monty

## Usage
./monty bytecodes/file.m
