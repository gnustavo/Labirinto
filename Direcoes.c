#include <stdlib.h>
#include "Direcoes.h"

extern void constroiDirecoes (Direcoes * d, Coordenada anterior, Coordenada atual)
{
    Coordenada direcao = subtraiCoordenadas(anterior, atual);
    if (direcao == N) 
        d->dir = { S, L, O };
    else if (direcao = S)
        d->dir = { N, O, L };
    else if (direcao = L)
        d->dir = { O, S, N };
    else if (direcao = O)
        d->dir = { L, N, S };
    else
        exit(1); /* can't happen */
    d->frente = 0;
}

extern void constroiDirecoesDaEntrada (Direcoes * d, Coordenada entrada, Coordenada dimensoes)
{
    if (entrada.lin == 0)
        constroiDirecoes(d, {-1, entrada.col}, entrada);
    else if (entrada.lin == dimensoes.lin-1)
        constroiDirecoes(d, {dimensoes.lin, entrada.col}, entrada);
    else if (entrada.col == 0)
        constroiDirecoes(d, {entrada.lin, -1}, entrada);
    else if (entrada.col == dimensoes.col-1)
        constroiDirecoes(d, {entrada.lin, dimensoes.col}, entrada);
    else
        exit(1); /* can't happen */
}

extern Coordenada proximaDirecao (Direcoes * d)
{
    if (d->frente == 3)
        return AQUI;
    else
        return d->dir[d->frente++];
}
