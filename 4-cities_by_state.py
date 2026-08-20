#!/usr/bin/env python3
"""List all cities by state."""

import MySQLdb
import sys


if __name__ == "__main__":
    username = sys.argv[1]
    password = sys.argv[2]
    database = sys.argv[3]

    db = MySQLdb.connect(
        host="localhost",
        port=3306,
        user=username,
        passwd=password,
        db=database
    )

    cur = db.cursor()
    cur.execute(
        "SELECT cities.id, cities.name, states.name "
        "FROM cities INNER JOIN states "
        "ON cities.state_id = states.id "
        "ORDER BY cities.id ASC"
    )

    for city in cur.fetchall():
        print(city)

    cur.close()
    db.close()
