#!/usr/bin/python3
"""Script that parses logs from stdin."""

import sys

status_count = {}
total_size = 0
line_count = 0
valid_status = ["200", "301", "400", "401", "403", "404", "405", "500"]


def print_stats():
    """Print accumulated statistics."""
    print("File size: {}".format(total_size))
    for code in valid_status:
        if code in status_count:
            print("{}: {}".format(code, status_count[code]))


try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()

        try:
            total_size += int(parts[-1])
        except (IndexError, ValueError):
            pass

        try:
            status = parts[-2]
            if status in valid_status:
                status_count[status] = status_count.get(status, 0) + 1
        except IndexError:
            pass

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    pass
finally:
    print_stats()
