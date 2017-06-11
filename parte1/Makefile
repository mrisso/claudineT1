
CC = gcc

CFLAGS = -Wall -g

LDFLAGS = -Wall

FONTES = $(wildcard *.c)

OBJETOS = $(FONTES:.c=.o)

EXECUTAVEL = main

all:	$(EXECUTAVEL)

$(EXECUTAVEL):	$(OBJETOS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

run:	$(EXECUTAVEL)
	./$(EXECUTAVEL) entrada saida

clean:
	rm -rf *.o

rm:	clean
	rm -rf $(EXECUTAVEL)
