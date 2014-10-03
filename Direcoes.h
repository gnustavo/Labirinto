#include "Coordenada.h"

typedef
    struct
    {
        Coordenada *dir;
        int        indice;
    }
    Direcoes;


extern void constroiDirecoesDaEntrada (Direcoes * d, Coordenada entrada, Coordenada dimensoes);

extern void constroiDirecoes (Direcoes * d, Coordenada anterior, Coordenada atual);

extern Coordenada * proximaDirecao (Direcoes * d);

extern char simboloDirecao (Coordenada *c);
