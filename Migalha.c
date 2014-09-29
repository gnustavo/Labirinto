#include <stdlib.h>
#include "Migalha.h"

Migalha * constroiMigalha(Coordenada posicaoAtual, Fila * dir) {
    Migalha * m = (Migalha*) malloc (sizeof(Migalha));
    m->posAtual = posicaoAtual;
    m->direcoes = dir;
}

void destroiMigalha(Migalha * m) {
    free(m);
}
