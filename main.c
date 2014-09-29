#include <stdio.h>
#include <stdlib.h>
#include "Basico.h"
#include "Fila.h"
#include "Pilha.h"
#include "Labirinto.h"
#include "Coordenada.h"
#include "Migalha.h"
#include "PontoCardeal.h"

int main(int argc, char *argv[])
{
    Labirinto * l;

    if (argc != 1) {
        fprintf(stderr, "falta nome do arquivo\n");
        exit(1);
    }

    l = constroiLabirinto(argv[0]);

    while(!l->chegou()) {
        l->anda();
    }

    printf(l->toString());

    /* printar as coordenadas do caminho */

    exit(0);
}
