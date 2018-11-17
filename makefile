CC=gcc
CFLAGS=-I.
DEPS = TicTacToe.h
OBJ = TicTacToe.o tictacfuncs.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TicTacToe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)