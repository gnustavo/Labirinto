#include <stdio.h>
#include <stdlib.h>
#include "Labirinto.h"

int main(int argc, char *argv[])
{
    Labirinto * l;

    if (argc != 1) {
        fprintf(stderr, "falta nome do arquivo\n");
        exit(1);
    }

    l = constroiLabirinto(argv[0]);

    while(!chegou(l)) {
        anda(l);
    }

    puts(toString(l));

    /* printar as coordenadas do caminho */

    exit(0);
}
