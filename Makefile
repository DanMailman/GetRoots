# $@ is the name of the file to be made.
# $? is the names of the changed dependents.

CC=g++
CFLAGS=-Wall -std=c++14
LFLAGS=-lboost_iostreams -lboost_system

all: POLY_TEST KILL_GPLOT

POLY_TEST: Utilities.cpp POLY_t.cpp POLY_t.h Utilities.h POLY_TEST.cpp  
	$(CC) $(CFLAGS) Utilities.cpp POLY_t.cpp POLY_TEST.cpp -o $@ $(LFLAGS)

KILL_GPLOT:KILL_GPLOT.cpp  
	$(CC) $(CFLAGS) KILL_GPLOT.cpp -o $@ $(LFLAGS)

