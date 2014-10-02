.PHONY: clean labirinto

CC=gcc
CFLAGS=-g

labirinto: Coordenada.c Direcoes.c Labirinto.c main.c Migalha.c Pilha.c
	$(CC) -g -o labirinto $^

main.c: Labirinto.h

clean:
	rm -f *.o labirinto
