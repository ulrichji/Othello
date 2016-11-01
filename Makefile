CC = gcc
CFLAGS += -std=c99
LD = gcc
LDFLAGS += 

all: othello tests

.PHONY: all othello tests clean

othello : othello.o
	$(LD) $(LDFLAGS) -o othello othello.o

othello.o : othello.c
	$(CC) $(CFLAGS) -c othello.c -o othello.o

tests : tests.o
	$(LD) $(LDFLAGS) -o tests tests.o
	
tests.o : test.c
	$(CC) $(TESTFLAGS) -c test.c -o tests.o

clean:
	rm tests othello *.o
