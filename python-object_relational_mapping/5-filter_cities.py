#!/usr/bin/env python3
"""List all cities of a given state."""

import MySQLdb
import sys


if __name__ == "__main__":
    username = sys.argv[1]
    password = sys.argv[2]
    database = sys.argv[3]
    state_name = sys.argv[4]

    db = MySQLdb.connect(
        host="localhost",
        port=3306,
        user=username,
        passwd=password,
        db=database
    )

    cur = db.cursor()
    cur.execute(
        "SELECT cities.name "
        "FROM cities INNER JOIN states "
        "ON cities.state_id = states.id "
        "WHERE states.name = %s "
        "ORDER BY cities.id ASC",
        (state_name,)
    )

    cities = [city[0] for city in cur.fetchall()]
    print(", ".join(cities))

    cur.close()
    db.close()
