#include <stdlib.h>
#include "Migalha.h"

Migalha * constroiMigalha(Coordenada anterior, Coordenada atual) {
    Migalha * m = (Migalha*) malloc (sizeof(Migalha));
    m->posAtual = atual;
    constroiDirecoes(&(m->direcoes), anterior, atual);
    return m;
}

Migalha * constroiMigalhaDaEntrada(Coordenada entrada, Coordenada dimensoes) {
    Migalha * m = (Migalha*) malloc (sizeof(Migalha));
    m->posAtual = entrada;
    constroiDirecoesDaEntrada(&(m->direcoes), entrada, dimensoes);
    return m;
}

void destroiMigalha(Migalha * m) {
    free(m);
}
