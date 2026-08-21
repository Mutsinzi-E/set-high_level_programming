#!/usr/bin/env python3
"""Define the State model with a relationship to City."""

from sqlalchemy import Column, Integer, String
from sqlalchemy.orm import relationship
from sqlalchemy.ext.declarative import declarative_base


Base = declarative_base()


class State(Base):
    """Represent a state."""

    __tablename__ = "states"

    id = Column(Integer, nullable=False, primary_key=True, autoincrement=True)
    name = Column(String(128), nullable=False)

    cities = relationship(
        "City",
        cascade="all, delete",
        backref="state"
    )
