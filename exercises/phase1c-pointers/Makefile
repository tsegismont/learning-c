CC = gcc
CFLAGS = -Wall -Wextra -g

all: pointer_swap array_reverse generic_swap

pointer_swap: pointer_swap.c
	$(CC) $(CFLAGS) -o pointer_swap pointer_swap.c

array_reverse: array_reverse.c
	$(CC) $(CFLAGS) -o array_reverse array_reverse.c

generic_swap: generic_swap.c
	$(CC) $(CFLAGS) -o generic_swap generic_swap.c

clean:
	rm -f pointer_swap array_reverse generic_swap

.PHONY: all clean
