# Hash Tables Project

This project implements a hash table in C using:
- djb2 hashing algorithm
- separate chaining for collision handling

## Files

- 0-hash_table_create.c → creates hash table
- 1-djb2.c → hash function
- 2-key_index.c → compute index
- 3-hash_table_set.c → insert key/value pairs
- hash_tables.h → header file

## Compilation

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o test
