
CC = gcc

CFLAGS = -Wall -g

LDFLAGS = -Wall -lm

FONTES = $(wildcard *.c)

OBJETOS = $(FONTES:.c=.o)

EXECUTAVEL = main

all:	$(EXECUTAVEL)

$(EXECUTAVEL):	$(OBJETOS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

run:	$(EXECUTAVEL)
	./main

clean:
	rm -rf *.o

rm:	clean
	rm -rf $(EXECUTAVEL) saida2* entrada2* saidas/saida*
