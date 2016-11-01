CC = gcc
CFLAGS += -std=c99
LD = gcc
LDFLAGS += 

all: othello tests

.PHONY: all othello tests clean

othello : othello_main.o othello.o
	$(LD) $(LDFLAGS) -o othello othello.o othello_main.o

othello_main.o : othello_main.c
	$(CC) $(CFLAGS) -c othello_main.c -o othello_main.o

othello.o : othello.c othello.h
	$(CC) $(CFLAGS) -c othello.c -o othello.o

tests : tests.o
	$(LD) $(LDFLAGS) -o tests tests.o othello.o
	
tests.o : test.c
	$(CC) $(TESTFLAGS) -c test.c -o tests.o

clean:
	rm tests othello *.o
