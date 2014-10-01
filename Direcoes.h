#include "Basico.h"
#include "Coordenada.h"

typedef
    struct
    {
        Coordenada dir[3];
        int        frente;
    }
    Direcoes;


extern void constroiDirecoesDaEntrada (Direcoes * d, Coordenada entrada, Coordenada dimensoes);

extern void constroiDirecoes (Direcoes * d, Coordenada anterior, Coordenada atual);

extern Coordenada proximaDirecao (Direcoes * d);

