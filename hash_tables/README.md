# Hash Tables Project

This project implements a hash table in C using:

- djb2 hashing algorithm
- Separate chaining for collision handling

## Files

- 0-hash_table_create.c - Creates a hash table
- 1-djb2.c - Hash function
- 2-key_index.c - Computes the index of a key
- 3-hash_table_set.c - Inserts key/value pairs
- hash_tables.h - Header file

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o test
