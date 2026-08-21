#!/usr/bin/env python3
"""Define the City model."""

from sqlalchemy import Column, Integer, String, ForeignKey

from relationship_state import Base


class City(Base):
    """Represent a city."""

    __tablename__ = "cities"

    id = Column(Integer, nullable=False, primary_key=True, autoincrement=True)
    name = Column(String(128), nullable=False)
    state_id = Column(Integer, ForeignKey("states.id"), nullable=False)
