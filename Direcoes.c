#include <stdlib.h>
#include "Direcoes.h"

static Coordenada direcoes[4][3] = {
    { {-1,  0}, { 0, -1}, { 0, +1} },
    { {+1,  0}, { 0, +1}, { 0, -1} },
    { { 0, +1}, {+1,  0}, {-1,  0} },
    { { 0, -1}, {-1,  0}, {+1,  0} },
};

extern void constroiDirecoes (Direcoes * d, Coordenada anterior, Coordenada atual)
{
    Coordenada direcao;
    int i;

    direcao = subtraiCoordenada(anterior, atual);

    for (i=0; i<4; ++i)
    {
        if (mesmaCoordenada(direcao, direcoes[i][0]))
        {
            d->dir    = direcoes[i];
            d->indice = 0;
            break;
        }
    }
}

extern void constroiDirecoesDaEntrada (Direcoes * d, Coordenada entrada, Coordenada dimensoes)
{
    if (entrada.lin == 0)
        constroiDirecoes(d, constroiCoordenada(-1,            entrada.col  ), entrada);
    else if (entrada.lin == dimensoes.lin-1)
        constroiDirecoes(d, constroiCoordenada(dimensoes.lin, entrada.col  ), entrada);
    else if (entrada.col == 0)
        constroiDirecoes(d, constroiCoordenada(entrada.lin,   -1           ), entrada);
    else if (entrada.col == dimensoes.col-1)
        constroiDirecoes(d, constroiCoordenada(entrada.lin,   dimensoes.col), entrada);
    else
        exit(1); /* can't happen */
}

extern Coordenada * proximaDirecao (Direcoes * d)
{
    if (d->indice < 3)
        return &(d->dir[d->indice++]);
    else
        return NULL;
}
