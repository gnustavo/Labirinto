#include "Basico.h"

typedef
    struct
    {
         int lin;
         int col;
    }
    Coordenada;

extern Coordenada constroiCoordenada(int linha, int coluna);

extern Coordenada somaCoordenada(Coordenada coordAtual, Coordenada coordNova);

extern Coordenada subtraiCoordenada(Coordenada coordAtual, Coordenada coordNova);

extern boolean mesmaCoordenada(Coordenada c1, Coordenada c2);

