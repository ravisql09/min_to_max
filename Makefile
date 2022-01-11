MODULES = grt
EXTENSION = grt
DATA = grt--0.0.1.sql
PGXS := $(shell pg_config --pgxs)
include $(PGXS)
