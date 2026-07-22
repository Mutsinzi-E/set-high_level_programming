#!/usr/bin/python3
from calculator_1 import add, sub, mul, div
from sys import argv, exit

if __name__ == "__main__":
    if len(argv) != 4:
        print("Usage: ./100-my_calculator.py <a> <operator> <b>")
        exit(1)

    a = int(argv[1])
    op = argv[2]
    b = int(argv[3])

    operations = {
        "+": add,
        "-": sub,
        "*": mul,
        "/": div
    }

    if op not in operations:
        print("Unknown operator. Available operators: +, -, * and /")
        exit(1)

    result = operations[op](a, b)
    print("{} {} {} = {}".format(a, op, b, result))
