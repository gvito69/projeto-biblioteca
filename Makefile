CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: biblioteca

biblioteca: main.c arvore.c utils.c
	$(CC) $(CFLAGS) -o biblioteca main.c arvore.c utils.c

clean:
	rm -f biblioteca
