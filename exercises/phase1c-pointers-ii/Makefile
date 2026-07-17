CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99

all: sorter apply

sorter: sorter.c
	$(CC) $(CFLAGS) -o sorter sorter.c

apply: apply.c
	$(CC) $(CFLAGS) -o apply apply.c

clean:
	rm -f sorter apply

.PHONY: all clean
