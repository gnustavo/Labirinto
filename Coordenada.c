#include <stdlib.h> 
#include "Coordenada.h"

Coordenada constroiCoordenada(int linha, int coluna) {
    Coordenada c;
    c.lin = linha;
    c.col = coluna;
    return c;
}

Coordenada somaCoordenada(Coordenada coordAtual, Coordenada coordNova) {
    Coordenada c;
    c.lin = coordAtual.lin + coordNova.lin;
    c.col = coordAtual.col + coordNova.col;
    return c;
}

Coordenada subtraiCoordenada(Coordenada coordAtual, Coordenada coordNova)
{
    Coordenada c;
    c.lin = coordNova.lin - coordAtual.lin;
    c.col = coordNova.col - coordAtual.col;
    return c;
}

extern boolean mesmaCoordenada(Coordenada c1, Coordenada c2)
{
    return (c1.lin == c2.lin) && (c1.col == c2.col);
}
