#include "Direcoes.h"

typedef
    struct
    {
        Coordenada posAtual;
        Direcoes   direcoes;
    }
    Migalha;

extern Migalha * constroiMigalhaDaEntrada(Coordenada entrada, Coordenada dimensoes);

extern Migalha * constroiMigalha(Coordenada anterior, Coordenada atual);

extern void destroiMigalha(Migalha * m);
