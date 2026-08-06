#!/usr/bin/python3
"""Log parsing script."""

import sys


def print_stats(total_size, status_codes):
    """Print the log statistics."""
    print("File size: {}".format(total_size))

    for code in sorted(status_codes):
        print("{}: {}".format(code, status_codes[code]))


total_size = 0
status_codes = {}
line_count = 0

valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]

try:
    for line in sys.stdin:
        parts = line.split()

        try:
            status = int(parts[-2])
            size = int(parts[-1])

            if status in valid_codes:
                total_size += size

                if status not in status_codes:
                    status_codes[status] = 0

                status_codes[status] += 1
                line_count += 1

                if line_count == 10:
                    print_stats(total_size, status_codes)
                    line_count = 0

        except (ValueError, IndexError):
            continue

except KeyboardInterrupt:
    print_stats(total_size, status_codes)
    sys.exit(0)

print_stats(total_size, status_codes)
