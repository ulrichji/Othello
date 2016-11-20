CC = gcc
CFLAGS += -std=c99
LD = gcc
LDFLAGS += 

all: othello tests

.PHONY: all othello tests clean

othello : othello_main.o othello.o console_player.o aiplayer.o
	$(LD) $(LDFLAGS) -o othello othello.o othello_main.o console_player.o

othello_main.o : othello_main.c
	$(CC) $(CFLAGS) -c othello_main.c -o othello_main.o

othello.o : othello.c othello.h
	$(CC) $(CFLAGS) -c othello.c -o othello.o

console_player.o : console_player.c console_player.h
	$(CC) $(CFLAGS) -c console_player.c -o console_player.o

ai_player.o : aiplayer.c aiplayer.h
	$(CC) $(CFLAGS) -c aiplayer.c -o aiplayer.o

tests : tests.o
	$(LD) $(LDFLAGS) -o tests tests.o othello.o
	
tests.o : test.c
	$(CC) $(TESTFLAGS) -c test.c -o tests.o

clean:
	rm tests othello *.o
