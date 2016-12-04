CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror -D_GNU_SOURCE
LIBS = -lcheck -lm -lrt -pthread
LDFLAGS= $(LIBS)
SOURCES=between_two_sets.c tests.c
OBJECTS=$(SOURCES:.c=.o) 
EXECUTABLE=tests

all: makeTests.c $(SOURCES) $(EXECUTABLE) runTests
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

makeTests.c: tests.check
	checkmk tests.check >tests.c

runTests: tests
	./tests
