#!/usr/bin/env python3.3
# Since I'm using Alembic and flask-migrate for this, here's what you need to do for migration after
# running this script:
# $manage.py db init  -- FIRST TIME ONLY! Creates basic Alembic configs
# $manage.py db migrate  -- creates a new migration script, make sure to review it!
# $manage.py db upgrade  -- this applies the migration to the database! Yay done!
from app import db
db.create_all()