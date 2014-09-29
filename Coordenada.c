#include <stdlib.h> 
#include "Coordenada.h"

Coordenada constroiCoordenada(int abscissa, int ordenada) {
    Coordenada c;
    c.X = abscissa;
    c.Y = ordenada;
    return c;
}

Coordenada somaCoordenada(Coordenada coordAtual, Coordenada coordNova) {
    Coordenada c;
    c.X = coordAtual.X + coordNova.X;
    c.Y = coordAtual.Y + coordNova.Y;
    return c;
}

const Coordenada N = {-1,  0};
const Coordenada S = {+1,  0};
const Coordenada L = { 0, +1};
const Coordenada O = { 0, -1};
