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

const Coordenada N = {-1,  0};
const Coordenada S = {+1,  0};
const Coordenada L = { 0, +1};
const Coordenada O = { 0, -1};
const Coordenada AQUI = { 0,  0};
