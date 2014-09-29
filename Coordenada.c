#include "Coordenada.h"

Coordenada * constroiCoordenada(int abscissa, int ordenada) {
    Coordenada * c = (Coordenada*) malloc (sizeof(Coordenada));
    c->X = abscissa;
    c->Y = ordenada;
}

void destroiCoordenada(Coordenada * c) {
    free(c->X);
    free(c->Y);
    free(c);
}

Coordenada * somaCoordenada(Coordenada * coordAtual, Coordenada * coordNova) {
    coordAtual->X = coordAtual->X + coordNova->X;
    coordAtual->Y = coordAtual->Y + coordNova->Y;
}

extern const Coordenada N = {-1, 0};
